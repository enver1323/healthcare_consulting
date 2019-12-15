-- MySQL dump 10.13  Distrib 5.7.28, for Linux (x86_64)
--
-- Host: localhost    Database: hcs
-- ------------------------------------------------------
-- Server version	5.7.28-0ubuntu0.18.04.4

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
-- Table structure for table `doctors`
--

DROP TABLE IF EXISTS `doctors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `doctors` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `work_name` varchar(255) DEFAULT NULL,
  `work_address` varchar(255) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `email` varchar(255) DEFAULT NULL,
  `phone` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=89 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `doctors`
--

LOCK TABLES `doctors` WRITE;
/*!40000 ALTER TABLE `doctors` DISABLE KEYS */;
INSERT INTO `doctors` VALUES (1,'﻿ЎЗБЕКИСТОН РЕСПУБЛИКАСИ СОҒЛИҚНИ САҚЛАШ ВАЗИРЛИГИ ','Шайхонтохур тумани, Навоий кўчаси, 12','А.К.Шадманов ','minzdrav@med.ru','241-16-91'),(2,'РЕСПУБЛИКА ТАШҚИ ИҚТИСОДИЙ ФАОЛИЯТИНИ МУВОФИҚЛАШТИРИШ  ДЕПАРТАМЕНТИ','Шайхонтохур тумани, Навоий кўчаси, 13','А.Қаюмов','','267-12-19'),(3,'\"РЕСПУБЛИКА  ССВ  \"\"РЕЗЕРВ\"\" БИРЛАШМАСИ\"','Мирзо Улуғбек тумани, Паркент кўчаси, 51','Х.Габидуллин','','267-47-03'),(4,'РЕСПУБЛИКА  ССВ  ХУСУСИЙЛАШТИРИШ ВА ПУЛЛИК ХИЗМАТНИ ТАШКИЛ ЭТИШ  БЎЛИМИ','Мирзо Улуғбек тумани, Паркент кўчаси, 51','','','268-34-95'),(5,'\"РЕСПУБЛИКА  ССВ \"\"САЛОМАТЛИК-3\"\"  ЛОЙИХАСИНИ АМАЛГА ОШИРИШ  БЮРОСИ\"','Мирзо Улуғбек тумани, Паркент кўчаси, 51','','','268-08-19'),(6,'РЕСПУБЛИКА  ССВ  ЖАМИЯТ САЛОМАТЛИГИ ВА СОҒЛИҚНИ САҚЛАШНИ ТАШКИЛ ҚИЛИШ ИЛМИЙ ТАДҚИҚОТ ИНСТИТУТИ ','Мирзо Улуғбек тумани, М.Улуғбек кўчаси, 38','З.Муталова','zulkhumor.mutalova@minzdrav.uz   alimdjan.madaliev@minzdrav.uz','267-62-44'),(7,'РЕСПУБЛИКА   ИХТИСОСЛАШТИРИЛГАН ПЕДИАТРИЯ ИЛМИЙ-АМАЛИЙ ТИББИЁТ МАРКАЗИ  ','Олмазор тумани, 2-Чимбой кўчаси, талант тор 3уй','Ахмедова Дилором Илхамовна','dilorom.ahmedova@minzdrav.uz','229-38-73'),(8,'РЕСПУБЛИКА  ИХТИСОСЛАШТИРИЛГАН АКУШЕРЛИК ВА ГИНЕКОЛОГИЯ  ИЛМИЙ-АМАЛИЙ ТИББИЁТ МАРКАЗИ','Мирзо Улуғбек тумани, М.Улуғбек кўчаси, 132-а','Мавлуда Хамзаевна Хайрутдинова','info@gynecology.uzsci.net','263-78-30'),(9,'РЕСПУБЛИКА ПЕРИНАТАЛ МАРКАЗИ ','Юнусобод тумани, Боғишамол кўчаси, 223','А.Любчич','','260-28-80'),(10,'РЕСПУБЛИКА АҲОЛИ РЕПРОДУКТИВ САЛОМАТЛИК МАРКАЗИ','Яшнаобод тумани, Тараққиёт кўчаси, 103','Л.Рахимова','rcrzn@minzdrav.uz','289-71-74'),(11,'\"РЕСПУБЛИКА  \"\"ОНА ВА БОЛА СКРИНИНГ\"\" МАРКАЗИ\"','Юнусобод тумани, Боғишамол 3-тор кўчаси, 5','М. К.Шарипова ','screening.uz@mail.ru','2602846'),(12,'РЕСПУБЛИКА ИХТИСОСЛАШТИРИЛГАН ЭНДОКРИНОЛОГИЯ ИЛМИЙ-АМАЛИЙ ТИББИЁТ МАРКАЗИ Ё Х Туракулов','Мирзо Улуғбек тумани, М.Улуғбек кўчаси, 56','А.В.Алимов ','endocrin@uzsci.net','262-27-02'),(13,'РЕСПУБЛИКА ИХТИСОСЛАШТИРИЛГАН КАРДИОЛОГИЯ ИЛМИЙ-АМАЛИЙ ТИББИЁТ МАРКАЗИ','Мирзо Улуғбек тумани, Осиё кўчаси, 4','Р.Д.Курбанов','cardio@sarkor.com  ,  cardiocenter@mail.ru','237-36-88'),(14,'\"РЕСПУБЛИКА ИХТИСОСЛАШТИРИЛГАН КЎЗ МИКРОХИРУРГИЯСИ МАРКАЗИ \"\"АЖ\"\"  \"','Учтепа тумани, Кичик халқа йўли, 14','А.Ф.Юсупов','eye-center@inbox.ru','217-49-34'),(15,'РЕСПУБЛИКА КЎЗ КАСАЛЛИКЛАРИ КЛИНИК ШИФОХОНАСИ  ','Олмазор тумани, Зиё кўчаси, 12','Икрамов Отабек Исакович','info@rkob.uz','227-14-42'),(16,'РЕСПУБЛИКАИХТИСОСЛАШТИРИЛГАН  НЕЙРОХИРУРГИЯ ИЛМИЙ -АМАЛИЙ ТИББИЁТ МАРКАЗИ','Мирзо Улуғбек тумани, Хумоюн мавзеси, 40','Кариев Гайрат Маратович гл.врач Д.Б.Миразимов','kariev@bcc.com.uz uzneurosurgery@qmail.com','264-96-30'),(17,'РЕСПУБЛИКА ШОШИЛИНЧ ТИББИЙ ЁРДАМ ИЛМИЙ МАРКАЗИ','Чилонзор тумани, Кичик халка (Фарход кўчаси),2','Абдухаким Муминович Ходжибаев','abduhakim.muminov@minzdrav.uz','279-34-57'),(18,'РЕСПУБЛИКА ИХТИСОСЛАШТИРИЛГАН ОНКОЛОГИЯ ВА РАДИОЛОГИЯ ИЛМИЙ-АМАЛИЙ ТИББИЁТ МАРКАЗИ','Шайхонтохур тумани Фаробий кўчаси, 383','Тилляшайхов Мирзаголиб Негматович','sarimbekn@list.ru','227-13-27'),(19,'Ш.А. АЛИМОВ номли  РЕСПУБЛИКА  ФТИЗИАТРИЯ ВА ПУЛЬМОНОЛОГИЯ ИЛМИЙ-АМАЛИЙ ТИББИЁТ МАРКАЗИ','Шайхонтохур тумани, Ш.Алимов кўчаси, 1','Парпиева Наргиза Нусратовна','nationaltbuz@mail.ru','278-04-70'),(20,'РЕСПУБЛИКА ДОТС (DOTS)  МАРКАЗИ (Силга қарши кураш дастури )','Шайхонтохур тумани, Ш.Алимов кўчаси, 1','Г.Узокова','avazbek.jalolov@mail.ru','278-07-30'),(21,'РЕСПУБЛИКА  ИЛМИЙ-ИХТИСОСЛАШГАН АЛЛЕРГОЛОГИЯ МАРКАЗИ','Олмазор тумани, Фаробий кўчаси, 2','Ш.Сагдуллаева','Shahnoza.Sagdullaeva@mail.ru','214-55-06'),(22,'РЕСПУБЛИКА  ИХТИСОСЛАШТИРИЛГАН УРОЛОГИЯ МАРКАЗИ','Олмазор тумани, Ходжаев кўчаси, 1-берк кўча, 1','Ш.Турсунов','f.akilov@minzdrav.uz','246-61-03'),(23,'РЕСПУБЛИКА НАРКОЛОГИЯ МАРКАЗИ ','Тошкент вилояти, Қибрай тумани, Солор шахарчаси, Ором кўчаси, 1','Буриходжаев Гулом Нумонович','www.narkosentr.uz','150-78-95'),(24,'РЕСПУБЛИКА УЛАТ КАРАНТИН ВА ЎТА ХАВФЛИ ЮҚУМЛИ КАСАЛЛИКЛАР МУХОФАЗАСИ  МАРКАЗИ','Шайхонтохур тумани, Эшон Бобохон кўчаси, 2','Директор Сайдалиев Сайдимурат Сайдиганиевич','m.madaminov@minzdrav.uz','246-36-84'),(25,'РЕСПУБЛИКА  ДСЭНМ - ДАВЛАТ САНИТАРИЯ-ЭПИДЕМИОЛОГИЯ НАЗОРАТИ МАРКАЗИ','Чилонзор тумани, Бунёдкор кўчаси, 46','Алматов Бахром Ибрагимович','bahrom.almatov@minzdrav.uz','276-59-28'),(26,'ЎЗБЕКИСТОН ХАВО ЙЎЛЛАРИ МАК ДСЭНМ - ДАВЛАТ САНИТАРИЯ-ЭПИДЕМИОЛОГИЯ НАЗОРАТИ МАРКАЗИ','Мирзо Улуғбек тумани, Авиасозлар шаҳарчаси,  25-а уй','Шоумаров Санат Бахрамович','','215-61-42'),(27,'РЕСПУБЛИКА  ДЕЗИНФЕКЦИЯ СТАНЦИЯСИ','Олмазор тумани,  Беруний кўчаси, 371 уй','Шухрат Абдурахманович Ботирходжаев','xasan 33001987@mail.ru','246-97-14'),(28,'РЕСПУБЛИКА   ОИТСга ҚАРШИ КУРАШ МАРКАЗИ','Чилонзор тумани, 16-мавзе, Фарход кўчаси, 12','Юлдашев Кахрамон Холдорович','n.atabekov@minzdrav.uz','276-95-23'),(29,'РЕСПУБЛИКА   БОЛАЛАР КАМ ИНВАЗИВ ВА ЭНДОСКОПИК ХИРУРГИЯ ИЛМИЙ-АМАЛИЙ МАРКАЗИ','\"Олмазор тумани, \"\"Фаробий\"\" кўчаси, 2 уй.  ТТА, 8 корпус, 3 этаж\"','Бобир Закирович Абдусаматов','centr.uzb@mail.ru','150-94-90'),(30,'АКАДЕМИК В. ВОХИДОВ номли РЕСПУБЛИКА ИХТИСОСЛАШТИРИЛГАН ЖАРРОХЛИК МАРКАЗИ ','Чилонзор тумани, Фарход кўчаси, 10','Назиров Феруз Гафурович','vakhidov@uzcsi.net','277-26-42'),(31,'РЕСПУБЛИКА   СПОРТ ЖАРОХАТ МАРКАЗИ  ','Яшнобод тумани, Тараққиёт кўчаси, 78 (Беруний -3 аренда)','Искандаров Темур Искандарович','sport-trauma.uz@mail.ru','249-58-45'),(32,'ТРАВМАТОЛОГИЯ ВА ОРТОПЕДИЯ ИЛМИЙ АМАЛИЙ ТИББИЁТ МАРКАЗИ','Яшнаобод тумани, Тараққиёт кўчаси, 78','Азизов М.Ж ','niito-tashkent@yandex.ru','233-10-30'),(33,'РЕСПУБЛИКА  БОЛАЛАР ОРТОПЕДИЯ МАРКАЗИ','Тошкент вилояти, Қибрай тумани, Солор шахарчаси, Олийгоҳ кўчаси, 8','Кадиров Ифтихор Муроджанович','eldor306@mail.ru','260-46-45'),(34,'РЕСПУБЛИКА БОЛАЛАР ТАЯНЧ-ХАРАКАТ ТИЗИМИ КАСАЛЛИКЛАРИ РЕАБИЛИТАЦИЯ МАРКАЗИ','Тошкент вилояти, Қибрай тумани, Солор шахарчаси, Бобур кўчаси, 4','Солижон Зарипович Бекчанов','www.zuzu. 2001.uz','71-260-63-30'),(35,'РЕСПУБЛИКА  ЭПИДЕМИОЛОГИЯ, МИКРОБИОЛОГИЯ ВА ЮҚУМЛИ КАСАЛЛИКЛАР КАСАЛЛИКЛАР ИЛМИЙ ТЕКШИРИШ ИНСТИТУТИ ва КЛИНИКАСИ','Учтепа тумани, Заковат кўчаси, 2','Нурмат Сатиниязович Атабеков','r.isamitdinova@minzdrav.uz','243-36-05'),(36,'\"РЕСПУБЛИКА \"\"ОДАМ МИКОЗЛАРИНИ ҚЎЗҒАТУВЧИ ЗАМБУРУҒ ТУРЛАРИ КОЛЛЕКЦИЯСИ МИКОЛОГИЯ ЛАБОРАТОРИЯСИ ВА МУЗЕЙИ\"\"\"','Учтепа тумани, Решетов  кўчаси, 2','С.Осипова','svetosip7@mail.ru','243-36-05'),(37,'БЎҒМА (ДИФТЕРИЯ) КАСАЛЛИГИГА БАКТЕРИОЛОГИК ДИАГНОЗ ҚЎЙИШ МАРКАЗИ','Мирзо Улуғбек тумани, Паркент кўчаси, 51 уй','','',''),(38,'РЕСПУБЛИКА  ВИРУСОЛОГИЯ ИЛМИЙ ТЕКШИРИШ ИНСТИТУТИ  ','Юнусобод тумани, Янгишахар кўчаси, 7-а','Мусабаев Эркин Исакович','virology.Institute@gmail.Com.','224-83-26'),(39,'РЕСПУБЛИКА   ИХТИСОСЛАШТИРИЛГАН ДЕРМАТОЛОГИЯ ВА ВЕНЕРОЛОГИЯ ИЛМИЙ-АМАЛИЙ ТИББИЁТ МАРКАЗИ','\"Олмазор тумани, \"\"Фаробий\"\" кўчаси, 2 уй\"','У.Собиров','niidiv@mail.ru','214-50-98'),(40,'РЕСПУБЛИКА   ТЕРИ-ТАНОСИЛ КЛИНИК КАСАЛХОНАСИ','Миробод тумани, Нукус кўчаси, 1 проезд, 14','О.Ибрагимов','rkvkb.@','299-99-79'),(41,'РЕСПУБЛИКА  ТЕРАПИЯ ВА ТИББИЙ РЕАБИЛИТАЦИЯ ИЛМИЙ-АМАЛИЙ ТИББИЁТ МАРКАЗИ','Юнусобод тумани, Хуршид кўчаси, 4','К.Муминов','Salohhud@mail.ru','234-55-00'),(42,'ЎСМИРЛАР ВА ЧАҚИРИЛУВЧИ ЁШЛАРГА ТИББИЙ ЁРДАМНИ ТАШКИЛ ЭТИШ РЕСПУБЛИКА  МАРКАЗИ ','Шайхонтохур тумани, Навоий кўчаси, 12','И.Уринбаев','ibragim.yrinboev@minzdrav.uz','241-54-40'),(43,'САНИТАРИЯ ГЕГИЕНА ВА КАСБ КАСАЛЛИКЛАР  ИЛМИЙ ТАДҚИҚОТ ИНСТИТУТИ ','Мирзо Улуғбек тумани, Олтинтепа кўчаси, 325','Усманов Равшан Жахонгирович','gigiena_niisgz@mail.ru','266-69-56'),(44,'ТОШКЕНТ РЕСПУБЛИКА ТИББИЁТ АКАДЕМИЯСИ  №1-сон КЛИНИКАСИ','Олмазор тумани, Ходжаев кўчаси, 2','Туйчиев Лазиз Нодирович','INFOQ1-klinikatma.uz','150-97-00'),(45,'ТОШКЕНТ РЕСПУБЛИКА ТИББИЁТ АКАДЕМИЯСИ  №2-сон КЛИНИКАСИ','\"Олмазор тумани, \"\"Фаробий\"\" кўчаси, 2 уй\"','Юлдашев Ёркин Каримович','2-kltashmedakad@mail.ru','150-95-00'),(46,'ТОШКЕНТ РЕСПУБЛИКА ТИББИЁТ АКАДЕМИЯСИ  №3-сон КЛИНИКАСИ','Яшнаобод тумани, Тараққиёт кўчаси, 103','Друстамова Дилором Маликовна','3-klinikatma.uz','289-43-43 289-43-44 (90)175-89-16'),(47,'РЕСПУБЛИКА  ПЕДИАТРИЯ ТИББИЁТ ИНСТИТУТИНИНГ  КЛИНИКАСИ  ','Юнусобод тумани, Боғишамол кўчаси, 223','Усманова Гулираъно Маллабаевна','tpmi@uzsci.net','262-96-62'),(48,'РЕСПУБЛИКА  1-сон  КЛИНИК ШИФОХОНАСИ','Миробод тумани, Содиқ Азимов кўчаси, 74','Хусанов Анвар Мирзаакбарович ','olimjan_rkb@mail.ru','233-42-32'),(49,'РЕСПУБЛИКА  2-сон  КЛИНИК ШИФОХОНАСИ','Мирзо Улуғбек тумани, Улуғбек шаҳарчаси, Булоқсой кўчаси, 1','З.Абдурахманова','rkbg.@minzdrav,uz,','289-21-63'),(50,'РЕСПУБЛИКА КУЗАТУВ КУЧАЙТИРИЛГАН РУХИЙ КАСАЛЛИКЛАР ШИФОХОНАСИ','Олмазор тумани, Чуқурсой кўчаси, 149','Усманов Улугбек Маратович, ','trkkrksh@minzdrav.uz','248-50-93'),(51,'РЕСПУБЛИКА  КЛИНИК РУХИЙ ШИФОХОНАСИ   ','Сергели тумани, Йўлдош дахаси, 4','С.Тиловов','Respsih@mail.ru','258-35-12'),(52,'У.К. ҚУРБОНОВ номли  РЕСПУБЛИКА  БОЛАЛАР РУХИЙ-АСАБ КАСАЛХОНАСИ','Мирзо Улуғбек тумани, Олмачи кўчаси, 1 ','Ш.Нурматова','rdpnb@mail.ru','267-73-50'),(53,'ВРАЧЛАР ВА ФАРМАЦЕВТЛАРНИ АТТЕСТАЦИЯДАН ЎТКАЗИШ ВА ЛИЦЕНЗИЯ БЕРИШ  РЕСПУБЛИКА  МАРКАЗИ ','Мирзо Улуғбек тумани, Паркент кўчаси, 51','А.Б.Яркулов','ahror.yrkulov@minzdrav.uz','267-15-23'),(54,'РЕСПУБЛИКА   ТИББИЙ ТАЪЛИМНИ РИВОЖЛАНТИРИШ МАРКАЗИ','Мирзо Улуғбек тумани, Паркент кўчаси, 51','Х.Абдуллаева','','268-17-14'),(55,'РЕСПУБЛИКА  ВРАЧЛАР МАЛАКАСИНИ ОШИРИШ ИНСТИТУТИ','Мирзо Улуғбек тумани, Паркент кўчаси, 51','Акилов Хабулла Атауллаевич ','info@tipme.uz','268-17-44'),(56,'ЎРТА ТИББИЁТ ВА ДОРИШУНОС ХОДИМЛАРИНИ МАЛАКАСИНИ ОШИРИШ ВА ИХТИСОСЛАШТИРИШ РЕСПУБЛИКА МАРКАЗИ ','Олмазор тумани, Каримов кўчаси, 45','','','214-51-23'),(57,'ТОШКЕНТ РЕСПУБЛИКА  ПЕДИАТРИЯ ТИББИЁТ ИНСТИТУТИ   ','Юнусобод тумани, Жаҳон Обидова кўчаси, 223','Ахмелова Дилором Илхамовна ','mail@tashpmi,uz','260-31-26'),(58,'ТОШКЕНТ  ТИББИЁТ АКАДЕМИЯСИ ','Олмазор тумани, Фаробий кўчаси, 3','Л.Туйчиев','tta2005@mail.ru','214-83-11'),(59,'ТОШКЕНТ ФАРМАЦЕВТИКА ИНСТИТУТИ   ','Миробод тумани, Афросиёб кўчаси, 45','А.Юнусходжаев','pharm,@bcc,com uz,','256-37-38'),(60,'РЕСПУБЛИКА  ГЕМАТОЛОГИЯ ВА ҚОН ҚУЙИШ ИЛМИЙ ТЕКШИРИШ ИНСТИТУТИ ','Чилонзор тумани, Бунёдкор кўчаси, 42','А.Каюмов','alonur.saidov@minzdrav.uz','278-79-35'),(61,'РЕСПУБЛИКА СУД-ТИББИЙ ЭКСПЕРТИЗА БОШ БЮРОСИ','Яккасарой тумани, Боғубўстон, 143','Искандаров Алишер Искандарович','javlonbek1974@yahoo.com','250-87-20'),(62,'РЕСПУБЛИКА ПАТОЛОГО-АНОТОМИК МАРКАЗИ  ','Олмазор тумани, Ф.Хаджаев кўчаси, 11','А.Искандаров','rpat-uz@mail.ru','214-50-11'),(63,'РЕСПУБЛИКА  ДОРИ ВОСИТАЛАРИ ЭКСПЕРТИЗАСИ ВА СТАНДАРТИЗАЦИЯСИ ДАВЛАТ МАРКАЗИ','Олмазор тумани, Усмонхўжаев кўчаси, Умаров тор кўчаси, 16','','habibulla.Jalilov@minzdrav.uz','244-48-23'),(64,'РЕСПУБЛИКА СТОМАТОЛОГИК ПОЛИКЛИНИКАСИ ','Чилонзор тумани, Нурхон кўчаси, 16-а','Файзуллаев Садулла Асадуллаевич ','fauzllaev7177@vfil,ru','277-45-94'),(65,'РЕСПУБЛИКА МАРКАЗИЙ КОНСУЛЬТАТИВ ДИАГНОСТИК ПОЛИКЛИНИКА','Яшнаобод тумани, Қорасув кўчаси, 25','Д.Саидова','gavkhar/abduraupova@minzdrav.uz','9463553'),(66,'РЕСПУБЛИКА  БОЛАЛАР СУЯК СИЛИ САНАТОРИЯСИ ,  Мирзо Улуғбек тумани  ','Мирзо Улуғбек тумани, Буюк ипак йўли кўчаси, 425','З.Хаджимухамедов','','264-25-26'),(67,'\"РЕСПУБЛИКА  БОЛАЛАР СИЛ КАСАЛЛИКЛАРИГА ҚАРШИ  \"\"ЧИМГАН\"\" САНАТОРИЯСИ\"','Тошкент вилояти, Бўстонлиқ тумани, Чимган қишлоғи','Н.Ниёзметов','Chimgan2014@mail.ru','742-23-134'),(68,'\"\"\"ПАРДА-ТУРСУН\"\" номли РЕСПУБЛИКА ФТИЗИАТРИЯ САНАТОРИЯСИ     \"','Наманган вилояти, Поп тумани, Парда-Турсун қишлоғи','Абдуллаев','tub,sanatoriya@mail,ru','943010757'),(69,'\"РЕСПУБЛИКА ФТИЗИАТРИЯ-ПУЛЬМОНОЛОГИЯ  \"\"ПАХАТАЛИККЎЛ\"\"  САНАТОРИЯСИ  \"','Наманган вилояти, Наманган шахар, Пахталиккул кўчаси, 1','','tahir.turdiev@minzdrav.uz','224-67-15   0369-2246420'),(70,'К.С. ЗОИРОВ номли ЎЗБЕКИСТОН СОҒЛИҚНИ САҚЛАШ  МУЗЕЙИ    ','Миробод тумани, Охунбобоев кўчаси, 30','Махсумова ','','233-40-53'),(71,'\"\"\"ЎЗБЕКИСТОНДА СОҒЛИҚНИ САҚЛАШ\"\" , \"\"ЗДРАВООХРАНЕНИЕ УЗБЕКИСТАНА\"\"  РЕСПУБЛИКА ГАЗЕТАСИ  ТАХРИРИЯТИ    \"','Миробод тумани, Охунбобоев кўчаси, 30','','info@ssgzt.uz','233-13-22'),(72,'\"\"\"СИХАТ-САЛОМАТЛИК\"\"  РЕСПУБЛИКА ЖУРНАЛИ ТАХРИРИЯТИ  \"','Мирзо Улуғбек тумани, Паркент кўчаси, 51 уй','','sihat@list.ru','268-17-54'),(73,'\"ЎЗБЕКИСТОН ТИББИЁТ ЖИРНАЛИ\"\", \"\"МЕДИЦИНСКИЙ ЖУРНАЛ УЗБЕКИСТАНА\"\"  РЕСПУБЛИКА ЖУРНАЛИ ТАХРИРИЯТИ\"','Яшнаобод тумани, Тараққиёт кўчаси, 103','','','289-44-58'),(74,'\"Республика  ихтисослаштирилган жаррохлик марказининг  \"\"ЎЗБЕКИСТОН ХИРУРГИЯСИ\"\"  ЖУРНАЛИ РЕДАКЦИЯСИ \"','Чилонзор тумани, Фарҳод кўчаси, 10','','','277-26-13'),(75,'\"РЕСПУБЛИКА СОҒЛИҚНИ САҚЛАШ ВАЗИРЛИГИнинг  \"\"ХАМШИРА\"\" журнал  тахририяти \"','Чилонзор тумани, 8-даха, Қатортол кўчаси, 60','Усмонхужаев А','','273-47-82'),(76,'РЕСПУБЛИКА   ДАВЛАТ ИЛМИЙ-ТИББИЁТ КУТУБХОНАСИ ДИРЕКЦИЯСИ','Миробод тумани, Истиқбол кўчаси, 30','Болкунова','','233-38-22'),(77,'РЕСПУБЛИКА  ССВнинг   АВТОХЎЖАЛИГИ             ','Миробод тумани, Сарикўл 3-тор кўчаси,  13','','','283-77-38'),(78,'\"\"\"НИХОЛ\"\" - ТАЖРИБА ЗАВОДИ\"','Олмазор тумани, Фаробий кўчаси, 383','Бабаджанов А','','246-24-25'),(79,'РЕСПУБЛИКА  ССВ - ТОШКЕНТ КИСЛОРОД ЗАВОДИ    ','Чилонзор тумани, Чилонзор кўчаси, 86 ','Алимов ','','960-69-86'),(80,'ТОШКЕНТ ДАВЛАТ СТОМАТОЛОГИЯ ИНСТИТУТ КЛИНИКАСИ               ','Яшнобод тумани, Тараққиёт кучаси-103-уй','Бахтиёр Файзуллаев','','289-48-92'),(81,'РЕСПУБЛИКА  НОГИРОНЛАРНИ РЕАБИЛИТАЦИЯ ҚИЛИШ ВА ПРОТЕЗЛАШ МИЛЛИЙ  МАРКАЗИ                                   ','Мирзо Улугбек тумани, Дархон-тепа кўчаси, 5-а','','zayni-bek@umail.uz','235-45-05'),(82,'РЕСПУБЛИКА  ХИРУРГИК АНГИОНЕВРОЛОГИЯ ИХТИСОСЛАШТИРИЛГАН МАРКАЗИ                      ','Олмазор тумани, Фаробий кўчаси, 2','Каримов Шовкат Ибрагимович','rasul-1981@mail.ru','1509514'),(83,'УРУШ ВА МЕҲНАТ ФАХРИЙЛАРИ УЧУН РЕСПУБЛИКА ПАНСИОНАТИ','','','',''),(84,'РЕСПУБЛИКА ҚОН КУЙИШ МАРКАЗИ','Яккасарой тумани Ш.Руставели кучаси 138 уй','Саидов Аълонур ','',''),(85,'\"ТОШКЕНТ ВИЛОЯТИ \"\"ТОВОҚСОЙ\"\" САНАТОРИЯСИ\"','','','',''),(86,'Ўзбекистон Республикаси Соғлиқни сақлаш вазирлиги Республика тибий ижтимоий экспертиза инспекцияси','Тошкент шаҳар Чилонзор тумани. Новза кўчаси 14 уй','Назарматов Умарали Эргашевич','inspeksiya-kadr@mail.uz','94-634-23-95'),(87,'\"\"\"Одам савдоси жабирдийдаларига ёрдам бериш  бўйича Республика реабилитация маркази\"','Чилозор-3-18','Қодиров Мурадин Холматович','odamsavdosi2008@mail,ru','71-277-65-83'),(88,'Тошкент шахар тез тиббий ёрдам станцияси','Тошкент ш. Ю.Обод тумани М-4, 17 а уй','Д.Т.Султанов','','');
/*!40000 ALTER TABLE `doctors` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hospitals`
--

DROP TABLE IF EXISTS `hospitals`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hospitals` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hospitals`
--

LOCK TABLES `hospitals` WRITE;
/*!40000 ALTER TABLE `hospitals` DISABLE KEYS */;
/*!40000 ALTER TABLE `hospitals` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `name` varchar(256) NOT NULL,
  `email` varchar(256) NOT NULL,
  `type` varchar(256) NOT NULL,
  `password` varchar(256) NOT NULL,
  PRIMARY KEY (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES ('TEST_NAME','email@mail.mail','type','d41d8cd98f00b204e9800998ecf8427e');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-12-15 13:50:57
