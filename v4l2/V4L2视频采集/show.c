#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>   
#include <assert.h>   
  
#include <getopt.h>   
  
#include <fcntl.h>   
#include <unistd.h>   
#include <errno.h>   
#include <malloc.h>   
#include <sys/stat.h>   
#include <sys/types.h>   
#include <sys/time.h>   
#include <sys/mman.h>   
#include <sys/ioctl.h>   
  
#include <asm/types.h>   
  
#include <linux/videodev2.h>   
  
#define CLEAR(x) memset(&(x),0,sizeof(x))   
  
//定义一个缓存结构体   
struct buffer  
{  
  void* start;     //空指针   
  size_t length;   //长度大小   
};  
  
#define CAPTURE_FILE "test.yuyv"   
  
static char* dev_name = NULL;   //设备名   
static int fd = -1;              //文件序列   
static struct buffer* buffers = NULL;    //缓存对象   
static unsigned int n_buffers = 0;   //缓存数   
   
static void errno_exit(const char* s)   //错误输出      
{  
   fprintf(stderr,"%s error %d, %s\n",s,errno,strerror(errno));  
      exit(EXIT_FAILURE);  
}  
  
/*
static void process_image(const void* p, size_t length)   //处理获取图像 
{ 
   // fputc('!',stdout); 
 //fflush(stdout); 
 FILE *fp = fopen(CAPTURE_FILE, "a"); 
 
    if (fp<0)  
    { 
        printf("open frame data file failed\n"); 
        exit(EXIT_FAILURE); 
    } 
 fwrite(p,length, 1, fp); 
 perror("fwrite error"); 
 
 fclose(fp); 
    printf("Capture one frame saved in %s\n", CAPTURE_FILE); 
}
*/  
  
static void read_frame(FILE *fp)   //读取数据帧，用的都是mmap   
{  
   struct v4l2_buffer buf;  
   unsigned int i;  
   buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
   buf.memory = V4L2_MEMORY_MMAP;  
  
   if(-1 == ioctl(fd,VIDIOC_DQBUF,&buf))   //读取   
          errno_exit("VIDIOC_DQBUF");  
   
    fwrite(buffers[buf.index].start, buf.length, 1, fp);  //将数据写道fp中，这里的文件是"test.yuyv"   
  
   if(-1 == ioctl(fd,VIDIOC_QBUF,&buf))    //放回缓存   
       errno_exit("VIDIOC_QBUF");  
  
}  
  
static void mainloop(void)  
{  
    unsigned int count;  
 count = 100;  
 FILE *fp = fopen(CAPTURE_FILE, "w");  
  
    if (fp<0)   
    {  
        printf("open frame data file failed\n");  
        exit(EXIT_FAILURE);  
    }  
 while(count-- > 0)  
 {  
  
   read_frame(fp);    
 }  
 fclose(fp);  
    printf("Capture one frame saved in %s\n", CAPTURE_FILE);  
}  
  
static void stop_capturing(void)  //停止捕获帧   
{  
   enum v4l2_buf_type type;  
   type = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
  
   if(-1 == ioctl(fd,VIDIOC_STREAMOFF,&type))  //关闭视频流   
    errno_exit("VIDIOC_STREAMOFF");  
   printf("\nStreamOff success!\n");  
}  
  
static void start_capturing(void)   //开始捕获帧   
{  
   unsigned int i;  
   enum v4l2_buf_type type;  
  
   for(i = 0;i < n_buffers;i++)  
   {  
     struct v4l2_buffer buf;  
  CLEAR(buf);  
  
  buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
  buf.memory = V4L2_MEMORY_MMAP;  
  buf.index = i;  
  
  if(-1 == ioctl(fd,VIDIOC_QBUF,&buf))   //放入缓存   
   errno_exit("VIDIOC_QBUF");  
   }  
  
   type = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
  
   if(-1 == ioctl(fd,VIDIOC_STREAMON,&type))   //打开视频流   
      errno_exit("VIDIOC_STREAMON");  
   else printf("StreamOn success!\n");  
}  
  
static void uninit_device(void)   //释放存储空间   
{  
   unsigned int i;  
  
   for(i =0;i < n_buffers;i++)  
   {  
      if(-1 == munmap(buffers[i].start,buffers[i].length))  
    errno_exit("munmap");  
   }  
  
   free(buffers);  
}  
  
  
static void init_mmap(void)   //初始化读取方式   
{  
   struct v4l2_requestbuffers req;  
   CLEAR(req);  
  
   req.count = 2;  
   req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
   req.memory = V4L2_MEMORY_MMAP;  
  
   if(-1 == ioctl(fd,VIDIOC_REQBUFS,&req))   //分配内存   
   {  
      if(EINVAL == errno)  
   {  
     fprintf(stderr,"%s does not support memory mapping\n",dev_name);  
    exit(EXIT_FAILURE);  
   }  
   else  
    errno_exit("VIDIOC_REQBUFS");  
   }  
  
  
   buffers = calloc(req.count,sizeof(*buffers));   //分配缓存   
   if(!buffers)  
   {  
      fprintf(stderr,"Out of memory\n");  
    exit(EXIT_FAILURE);  
   }  
  
   for(n_buffers = 0;n_buffers < req.count;n_buffers++)  
   {  
       struct v4l2_buffer buf;  
    CLEAR(buf);  
  
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
    buf.memory = V4L2_MEMORY_MMAP;  
    buf.index = n_buffers;  
  
    if(-1 == ioctl(fd,VIDIOC_QUERYBUF,&buf))  
     errno_exit("VIDIOC_QUERYBUF");  
  
    buffers[n_buffers].length = buf.length;   //设置映射方式为mmap   
    buffers[n_buffers].start = mmap(NULL,buf.length,PROT_READ | PROT_WRITE,MAP_SHARED,fd,buf.m.offset);  
  
    if(MAP_FAILED == buffers[n_buffers].start)  
     errno_exit("mmap");  
   }  
}  
  
static void init_device(void)  //初始化设备   
{  
   struct v4l2_capability cap;  
   struct v4l2_format fmt;  
   unsigned int min;  
  
   if(-1 == ioctl(fd,VIDIOC_QUERYCAP,&cap))  
   {  
       if(EINVAL == errno)  
    {  
       fprintf(stderr,"%s is no V4L2 device\n",dev_name);  
    exit(EXIT_FAILURE);  
    }  
    else   
     errno_exit("VIDIOC_QUERYCAP");  
   }  
  
   if(!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE))  
   {  
        fprintf(stderr,"%s is no video  capture device\n",dev_name);  
          exit(EXIT_FAILURE);  
   }  
  
   if(!(cap.capabilities & V4L2_CAP_STREAMING))  
   {  
       fprintf(stderr,"%s does not support streaming i/o\n",dev_name);  
    exit(EXIT_FAILURE);  
   }  
//////////////////////////////////////////   
   CLEAR(fmt);       //设置帧格式   
   fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
   fmt.fmt.pix.width = 640;  
   fmt.fmt.pix.height = 480;  
   fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;  
   fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;  
  
   if(-1 == ioctl(fd,VIDIOC_S_FMT,&fmt))  
    errno_exit("VIDIOC_S_FMT");  
   printf("Set frame format successful!\n");  
   init_mmap();  
  
}  
  
static void close_device(void)   //关闭设备   
{  
   if(-1 == close(fd))  
    errno_exit("close");  
   fd = -1;  
   printf("Close the device successful!\n");  
}  
  
static void open_device(void)    //打开设备   
{  
   fd = open(dev_name,O_RDWR,0);  
   if(-1 ==fd)  
   {  
      fprintf(stderr,"Cannot open %s\n",dev_name);  
   exit(EXIT_FAILURE);  
   }  
   printf("Open the %s successful\n",dev_name);  
}  
  
int main(int argc,char* argv[])  
{  
   dev_name = "/dev/video0";  
  
   open_device();  
   init_device();  
   start_capturing();  
   mainloop();  
   stop_capturing();  
   uninit_device();  
   close_device();  
   exit(EXIT_SUCCESS);  
   return 0;  
}
