USE `mydb`;

DELETE FROM Director;
DELETE FROM Studio;
DELETE FROM Employed;
DELETE FROM Movie;
DELETE FROM Scenography;
DELETE FROM Actor;
DELETE FROM Acting_job;
DELETE FROM Cover;
DELETE FROM Producing;
INSERT INTO Director VALUES
(765,'Nic','Pizzolatto','USA'),
(775,'Cary','Fukunaga','USA'),
(762,'Akira','Kurosawa','Japan'),
(768,'Ingmar','Bergman','Sweden'),
(777,'Sergio','Leone','Italy'),
(778,'Alejandro','Innaritu','Mexico'),
(761,'Edgar','Wright','UK'),
(779,'Denis','Villeneuve','Canada');
INSERT INTO Studio VALUES
(15,'Disney','San Fernando',1923),
(22,'Universal','San Fernando',1912),
(23,'Warner Bros','San Fernando',1923),
(13,'20th Century Fox','Hollywood',1935),
(18,'Columbia','Hollywood',1924);
INSERT INTO Employed VALUES
(765,500000,15),
(775,250000,15),
(762,2500000,22),
(768,350000,13),
(777,10000,18),
(778,150000,23),
(761,775000,23),
(779,400000,13);
INSERT INTO Movie VALUES
(32,'Galveston',3,'2018-2-12','2019-3-22',765),
(33,'Beasts of no Nation',2,'2012-4-21','2014-1-15',775),
(43,'Ran',67,'1984-2-12','1985-6-12',762),
(38,'Fanny and Alexander',32,'1981-2-12','1981-6-2',768),
(42,'The Good,the Bad and the Ugly',3,'1965-3-11','1966-3-22',777),
(51,'Babel',3,'2018-5-2','2019-12-1',778),
(36,'Baby Driver',3,'2017-2-1','2017-8-22',761),
(39,'Blade Runner 2049',3,'2016-2-12','2017-6-22',779);
INSERT INTO Scenography VALUES
(1,32,'Savanah,Georgia'),
(1,33,'Ghana'),
(1,43,'Aso, Kumamoto, Japan'),
(2,43,'Gotemba, Shizuoka, Japan'),
(3,43,'Kokonoe, Oita, Japan'),
(4,43,'Shonai, Yamagata, Japan'),
(5,43,'Toho Studios, Tokyo, Japan'),
(1,38,'Uppsala, Uppsala län, Sweden'),
(2,38,'Valvgatan, Uppsala, Uppsala Län, Sweden'),
(1,42,'Carazo, Burgos, Castilla y León, Spain'),
(2,42,'Cabo de Gata, Almería, Andalucía, Spain'),
(3,42,'Rome, Lazio, Italy'),
(4,42,' Burgos, Castilla y León, Spain '),
(1,51,' Ouarzazate, Morocco '),
(2,51,' Tecate, Baja California Norte, Mexico '),
(3,51,'Shinjuku,Tokyo,Japan'),
(1,36,'Atlanta,Georgia, USA'),
(2,36,'New Orleans, Lousiana, USA'),
(1,39,'Budapest, Hungary'),
(2,39,'Icelabd'),
(3,39,'Almeria, Andalucia, Spain'),
(4,39,'Nevada,USA');


INSERT INTO Actor VALUES
(1001,'Ryan','Gosling'),
(1002,'Ana','de Armas'),
(1003,'Harrison','Ford'),
(1004,'Ansel','Elgort'),
(1005,'Lily','James'),
(1006,'Kevin','Spacey'),
(1007,'Brad','Pitt'),
(1011,'Cate','Blanchett'),
(1013,'Clint','Eastwood'),
(1014,'Lee','van Cleef'),
(1020,'Bertil','Guve'),
(1021,'Pernilla','Allwin'),
(1025,'Akira','Terao'),
(1026,'Tatsuya','Nakadai'),
(1030,'Abraham','Attah'),
(1031,'Ricky','Adelayitor'),
(1035,'Ben','Foster'),
(1036,'Jeffrey','Grover'),
(1040,'Margot','Robbie'),
(1041,'Christopher','Plummer');
Insert into Acting_job VALUES
(32,1036,'Dr.Finelli', 300000),
(32,1035,'Roy', 200000),
(33,1030,'Agu',150000),
(33,1031,'Village Constable',122000),
(43,1025,'Taro Takatora Ichimonji',11000),
(43,1026,'Lord Hidetora Ichimonji',22000),
(38,1020,'Alexander Ekdahl',1300),
(38,1021,'Fanny Ekhdal',1000),
(42,1013,'Blondie',45000),
(42,1014,'Sentenza/Angel Eyes',60000),
(51,1007,'Richard',16000),
(51,1011,'Susan',17000),
(36,1005,'Debora',200000),
(36,1006,'Doc',150000),
(36,1004,'Baby',1000000),
(39,1001,'K',100000),
(39,1002,'Joi',750000),
(39,1003,'Rick Deckard',150000);

Insert into Cover VALUES
(1002,1040),
(1006,1041);
Insert into Producing VALUES
(32,15,500000),
(33,22,272000),
(43,23,33000),
(38,13,2300),
(42,18,105000),
(51,15,33000),
(36,22,1150000),
(39,23,1000000);
