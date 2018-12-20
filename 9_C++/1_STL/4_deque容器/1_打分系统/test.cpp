/*************************************************************************
	> File Name: test.cpp
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月20日 星期六 15时45分26秒
 ************************************************************************/

#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;


//选手信息
class Player{
public:
    string mName;
    int mScore;
public:
    Player()
    {}
    Player(string name, int score) : mName(name), mScore(score)
    {
    }
};

void Create_Player(vector<Player>& v)
{
    //vector<Player> vPlist;
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        Player p;
        p.mName  = "选手_";
        p.mName += nameSeed[i];
        p.mScore = 0;

        v.push_back(p);        
    }
    return;
}

void printScore(int val)
{
    cout << val << " ";
}

void Set_Score(vector<Player> &v)
{
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
    {
        int score = 0;
        //当前的学生进行打分
        deque<int> dScore;
        for (int i = 0; i < 20; i++)
        {
            score = rand() % 41 + 60; 
            dScore.push_back(score);
        }
        
        sort(dScore.begin(), dScore.end());
        cout << it->mName << endl;
        for_each(dScore.begin(), dScore.end(), printScore);
        cout << endl;

        //去除最高法 去除最低分
        dScore.pop_front();
        dScore.pop_back();

        int totalScore = 0;
        for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++)
            totalScore += *(dit);

        //得到平均分
        it->mScore = totalScore / dScore.size();
        cout << "平均分 " << it->mScore << endl;
        cout << "------------------------------------" << endl;
    }
}


//排序规则
bool compare(Player& p1, Player& p2)
{
    return p1.mScore > p2.mScore;
}
//rank
void Print_Rank(vector<Player> &v)
{
   cout << "===================排名=========================" << endl;
    sort(v.begin(), v.end(), compare);

    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->mName << "分数为： " << it->mScore << endl;
    }
}

int main(int argc, char** argv)
{
    vector<Player> vPlist;
    Create_Player(vPlist);
    Set_Score(vPlist);
    Print_Rank(vPlist);
    return 0;
}
