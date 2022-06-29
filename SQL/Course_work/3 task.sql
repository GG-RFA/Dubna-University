DROP DATABASE TED_15_3;
CREATE DATABASE TED_15_3 CHARSET utf8mb4; USE TED_15_3;
/* -1- */
DROP TABLE IF EXISTS `Участие в мероприятии`; DROP TABLE IF EXISTS `Члены общества`;
DROP TABLE IF EXISTS `Мероприятия общества`;
/*Создаём таблицы */
CREATE TABLE `Мероприятия общества` (
`№ порядковый` INT NOT NULL,
`Дата проведения` DATE NOT NULL,
`Мероприятие` VARCHAR(120) NOT NULL,
`Стоимость` INT NOT NULL,
`Общее кол-во человек` INT NOT NULL, PRIMARY KEY(`№ порядковый`)
) ENGINE=InnoDB;
CREATE TABLE `Члены общества` (
`№ билета` INT NOT NULL,
`ФИО члена общества` VARCHAR(60) NOT NULL,
`Домашний адрес` VARCHAR(120) NOT NULL, PRIMARY KEY(`№ билета`)
) ENGINE=InnoDB;
CREATE TABLE `Участие в мероприятии` (
`№ порядковый` INT NOT NULL,
`№ билета` INT NOT NULL,
`Количество приглашенных человек` INT NOT NULL, PRIMARY KEY(`№ порядковый`,`№ билета`),
FOREIGN KEY(`№ порядковый`) REFERENCES `Мероприятия общества`(`№ порядковый`) ON DELETE RESTRICT ON UPDATE CASCADE,
FOREIGN KEY(`№ билета`) REFERENCES `Члены общества`(`№ билета`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB;
/* Заполняем данными */
INSERT INTO `Мероприятия общества`
(`№	порядковый`,`Дата	проведения`,`Мероприятие`,`Стоимость`,`Общее	кол-во человек`)
VALUES
(100, '2018.06.20', 'Рыбная ловля в Астрахани(1 неделя)', 19000,0),
(101, '2018.10.24', 'Соревнования по рыбной ловле в реке Оке(3 дня)', 3900,0), (102, '2019.03.02', 'Выезд на подледный лов на Белое озеро(3 дня)', 3100,0), (103, '2019.09.21', 'Рыбалка на Карелии', 12000,0);
INSERT INTO `Члены общества`
(`№ билета`, `ФИО члена общества`, `Домашний адрес`) VALUES
(1009,'Сидоров Сергей Михайлович','г.Котельники,ул.Новая,д.17,кв.123'), (1010,'Антонов Анатолий Федорович','г.Дзержинский,ул.Гарибальди,д.15,кв.89');
INSERT INTO `Участие в мероприятии`
(`№ порядковый`,`№ билета`,`Количество приглашенных человек`) VALUES
(100,1009,2),
(101,1009,3),
(102,1009,1),
(100,1010,3),
(102,1010,1);
/* -2- */
/* Создаём хранимые процедуры */
DROP FUNCTION IF EXISTS getSummary; DELIMITER $$
CREATE FUNCTION getSummary(num INT) RETURNS INT
DETERMINISTIC BEGIN
DECLARE SUMMARY INT DEFAULT 0;
SELECT SUM(`Количество приглашенных человек`) INTO SUMMARY
FROM `Участие в мероприятии`
WHERE `Участие в мероприятии`.`№ порядковый`=num; RETURN IFNULL(SUMMARY,0);
END $$ DELIMITER ;
select getSummary(100) as `Общее`;

/* -3- */ DELIMITER $$
CREATE PROCEDURE setSummary() BEGIN
UPDATE	`Мероприятия	общества`	SET	`Общее	кол-во	человек`=getSummary(`№ порядковый`);
END $$ DELIMITER ;
CALL setSummary();
SELECT * FROM `Мероприятия общества`;
/* -4- */
DROP PROCEDURE IF EXISTS setCursor;
DELIMITER $$
CREATE PROCEDURE `setCursor`() BEGIN
DECLARE NUM INT;
DECLARE SUMMARY,b INT DEFAULT 0;
DECLARE cursor1 CURSOR FOR SELECT `Участие в мероприятии`.`№ порядковый`, SUM(`Количество приглашенных человек`) FROM `Участие в мероприятии`
GROUP BY `Участие в мероприятии`.`№ порядковый`; DECLARE CONTINUE HANDLER FOR NOT FOUND SET b = 1;
UPDATE `Мероприятия общества` SET `Общее кол-во человек`=0; OPEN cursor1;
WHILE b=0 DO
FETCH cursor1 INTO num,SUMMARY;
UPDATE `Мероприятия общества` SET `Общее кол-во человек`=SUMMARY WHERE `№ порядковый`=NUM;
END WHILE;
CLOSE cursor1; END $$ DELIMITER ;
CALL setCursor();
SELECT * FROM `Мероприятия общества`;
/* Создаём триггеры */
/* -5- */ DELIMITER $$
CREATE TRIGGER `deleteD`
AFTER DELETE ON `Участие в мероприятии` FOR EACH ROW BEGIN
UPDATE	`Мероприятия	общества`	SET	`Общее	кол-во	человек`=getSummary(`№ порядковый`)
WHERE `№ порядковый`=OLD.`№ порядковый`; END $$
DELIMITER ;
/* -6- */ DELIMITER $$
CREATE TRIGGER `insertD`
AFTER INSERT ON `Участие в мероприятии` FOR EACH ROW BEGIN
UPDATE	`Мероприятия	общества`	SET	`Общее	кол-во	человек`=getSummary(`№ порядковый`)
WHERE `№ порядковый`=NEW.`№ порядковый`; END $$
DELIMITER ;
/* -7- */ DELIMITER $$
CREATE TRIGGER `updateD`
AFTER UPDATE ON `Участие в мероприятии` FOR EACH ROW BEGIN
IF OLD.`№ порядковый`!=NEW.`№ порядковый` THEN
UPDATE	`Мероприятия	общества`	SET	`Общее	кол-во	человек`=getSummary(`№ порядковый`)
WHERE `№ порядковый`= OLD.`№ порядковый`; END IF;
UPDATE	`Мероприятия	общества`	SET	`Общее	кол-во	человек`=getSummary(`№ порядковый`)
WHERE `№ порядковый`=NEW.`№ порядковый`; END $$
DELIMITER ;
/* Назначаем права доступа */
/* -8- */
DROP USER 'administrator'@'localhost'; DROP USER 'chairman'@'localhost'; DROP USER 'worker'@'localhost'; DROP USER 'visitor'@'localhost';

CREATE USER 'administrator'@'localhost' IDENTIFIED BY 'password'; CREATE USER 'chairman'@'localhost' IDENTIFIED BY 'password'; CREATE USER 'worker'@'localhost' IDENTIFIED BY 'password'; CREATE USER 'visitor'@'localhost';
/* -9- */
GRANT ALL PRIVILEGES ON `TED_15_3`.*
TO 'administrator'@'localhost';
REVOKE CREATE,DROP ON `TED_15_3`.*
FROM 'administrator'@'localhost';

FLUSH PRIVILEGES;
/* -10- */
GRANT ALL PRIVILEGES ON `TED_15_3`.*
TO 'chairman'@'localhost';
REVOKE CREATE, ALTER, DROP ON `TED_15_3`.*
FROM 'chairman'@'localhost';

FLUSH PRIVILEGES;
/* -11- */
GRANT INSERT,UPDATE, SELECT ON `TED_15_3`.`Мероприятия общества` TO 'worker'@'localhost';
REVOKE INSERT,SELECT(`Стоимость`) ON `TED_15_3`.`Мероприятия общества` FROM 'worker'@'localhost';
GRANT INSERT,UPDATE, SELECT ON `TED_15_3`.`Члены общества` TO 'worker'@'localhost';
GRANT UPDATE(`Количество приглашенных человек`) ON `TED_15_3`.`Участие в мероприятии`
TO 'worker'@'localhost';
GRANT INSERT, SELECT ON `TED_15_3`.`Участие в мероприятии` TO 'worker'@'localhost';

FLUSH PRIVILEGES;
/* -12- */
CREATE VIEW `Просмотр` AS
SELECT `Мероприятия общества`.`№ порядковый`,
`Мероприятия общества`.`Дата проведения`,
`Мероприятия общества`.`Мероприятие`,
`Мероприятия общества`.`Стоимость`,
`Члены общества`.`№ билета`,
`Члены общества`.`ФИО члена общества`,
`Участие в мероприятии`.`Количество приглашенных человек` FROM ((`Мероприятия общества`
RIGHT JOIN `Участие в мероприятии`
ON `Участие в мероприятии`.`№ порядковый`=`Мероприятия общества`.`№ порядковый`) INNER JOIN `Члены общества`
ON `Члены общества`.`№ билета`=`Участие в мероприятии`.`№ билета`);
/* -13- */
GRANT SELECT ON `TED_15_3`.`Просмотр` TO 'visitor'@'localhost';
FLUSH PRIVILEGES;

