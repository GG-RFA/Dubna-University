<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>Создание таблицы "Рецепты блюд"</title>
</head>
<body>
<?php
require_once 'login_var15.php';
$conn = new mysqli($server, $user, $password, $dbname);
if ($conn->connect_error)
	echo "<p>Невозможно подключиться к серверу или открыть БД:<br>\n".$conn->connect_error."</p>\n";
else {
	$query="DROP TABLE IF EXISTS `Рецепты блюд`";
	$result=$conn->query($query);
	if (!$result)
		echo "<p>Невозможно удалить таблицу \"Рецепты блюд\":<br>\n".$conn->error."</p>\n";
	else {
		$query="CREATE TABLE `Рецепты блюд`(".
			 "`Название блюда` VARCHAR(20) NOT NULL,".
			 "`Наименование продукта` VARCHAR(20) NOT NULL,".
			 "`Единицы измерения` VARCHAR(20) NOT NULL,".
			 "`Количество` INT NOT NULL,". 
			 "PRIMARY KEY(`Название блюда`, `Наименование продукта`)". 
			 ")";
		$result=$conn->query($query);
		if (!$result)
			echo "<p>Невозможно создать таблицу \"Рецепты блюд\":<br>\n".$conn->error."</p>\n";
		else
			echo "<p>Таблица \"Рецепты блюд\" создана</p>\n";
	}
	$conn->close();
}
?>
</body>
</html>
