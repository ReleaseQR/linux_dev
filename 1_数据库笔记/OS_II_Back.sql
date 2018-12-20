-- MySQL dump 10.13  Distrib 5.7.22, for Linux (x86_64)
--
-- Host: localhost    Database: OS_II
-- ------------------------------------------------------
-- Server version	5.7.22-0ubuntu18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Data_QR`
--

DROP TABLE IF EXISTS `Data_QR`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Data_QR` (
  `id` int(11) DEFAULT NULL,
  `data` varchar(200) DEFAULT NULL,
  `ip` varchar(40) DEFAULT NULL,
  `port` int(11) DEFAULT NULL,
  `cmd` varchar(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Data_QR`
--

LOCK TABLES `Data_QR` WRITE;
/*!40000 ALTER TABLE `Data_QR` DISABLE KEYS */;
INSERT INTO `Data_QR` VALUES (0,'this is null','127.0.0.0',8000,'AT');
/*!40000 ALTER TABLE `Data_QR` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `TestData`
--

DROP TABLE IF EXISTS `TestData`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `TestData` (
  `id` int(11) DEFAULT NULL,
  `information` varchar(200) DEFAULT NULL,
  `ip` varchar(40) DEFAULT NULL,
  `port` int(11) DEFAULT NULL,
  `userName` varchar(5) DEFAULT NULL,
  `time` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `TestData`
--

LOCK TABLES `TestData` WRITE;
/*!40000 ALTER TABLE `TestData` DISABLE KEYS */;
INSERT INTO `TestData` VALUES (0,'This Text Is For Testing','192.168.1.1',8080,NULL,NULL),(1,'This Is For Test...','127.0.0.0',8080,NULL,NULL),(3,'this is updata data','0.0.0.0',9090,'QR','1993-07-07');
/*!40000 ALTER TABLE `TestData` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-06-24 13:02:05
