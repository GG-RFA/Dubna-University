<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>Просмотр записей из таблицы "Рецепты блюд"</title>
<style>
	.left {text-align:left;}
</style>
</head>
<body>
<?php
require_once 'login_var15.php';
$conn = new mysqli($server, $user, $password, $dbname); //соединение с сервером
if ($conn->connect_error)
	echo "<p>Невозможно подключиться к серверу или открыть БД:<br>\n".$conn->connect_error."</p>\n";
else {
	$query="SELECT `Название блюда`, `Наименование продукта`, `Единицы измерения`,`Количество` FROM `Рецепты блюд`";
	$result=$conn->query($query);
	if (!$result)
		echo "<p>Невозможно просмотреть записи из таблицы \"Рецепты блюд\":<br>\n".$conn->error."</p>\n";
	else {
		echo "<table cellspacing=0 cellpadding=8 border=1>\n";
		echo "\t<caption>Рецепты блюд</caption>\n";
		echo "\t<tbody style='text-align:center'>\n";	 
		echo "\t\t<tr><th>Название блюда</th><th>Наименование продукта</th><th>Единицы измерения</th><th>Количество</th></tr>\n";
		while ($row=$result->fetch_array(MYSQLI_NUM)) {
			echo "\t\t<tr><td>$row[0]</td><td class='left'>$row[1]</td><td>$row[2]</td><td>$row[3]</td></tr>\n";
		}
		echo "\t</tbody>\n";
		echo "</table>\n";
		$result->close();
	}
	$conn->close();
}
?>
</body>
</html>


