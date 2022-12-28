<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Задание 9</title>
<link rel="stylesheet" href="style.css" type="text/css">
<script>

function f1(op) { 
	Ok.setAttribute('value', op);
	if (op == 'update') {    // Только в этом случае передавать дополнительные данные !!!
		food_name_Old.setAttribute('name', 'food_name_Old');
		product_name_Old.setAttribute('name', 'product_name_Old');
		measure_Old.setAttribute('name', 'measure_Old');
		amount_Old.setAttribute('name', 'amount_Old');
	}	
}
</script>
</head>
<body>
<?php
require_once 'login.php';
$conn = new mysqli($server, $user, $password, $dbname);
if ($conn->connect_error)
	echo "<p>Невозможно подключиться к серверу или открыть БД: $conn->connect_error </p>\n";
else {
	$Ok        = $_POST['Ok']; 
	$food_name = $_POST['food_name'];
	$product_name = $_POST['product_name'];
	$measure      = $_POST['measure'];
	$amount    = $_POST['amount'];

	switch ($Ok) {
		case 'insert':
			$query= "INSERT INTO `Рецепты блюд`(`Название блюда`, `Наименование продукта`, `Единицы измерения`, `Количество`) ".
					"values ('$food_name', '$product_name', '$measure', '$amount')";			
			$result=$conn->query($query);
			if (!$result)
				echo "<p>Невозможно добавить записи в таблицу \"Рецепты блюд\" $conn->error </p>\n";
			break;
		case 'update':
			$food_name_Old = $_POST['food_name_Old'];
	        $product_name_Old = $_POST['product_name_Old'];
	        $measure_Old      = $_POST['measure_Old'];
	        $amount_Old       = $_POST['amount_Old'];
			
			$query= "UPDATE `Рецепты блюд` ".
					"SET `Название блюда`='$food_name', `Наименование продукта`='$product_name', `Единицы измерения`='$measure' , `Количество`='$amount' ".
					"WHERE `Название блюда`='$food_name_Old' AND `Наименование продукта`='$product_name_Old' AND `Единицы измерения`='$measure_Old' AND `Количество`='$amount_Old'";
			$result=$conn->query($query);
			if (!$result)
				echo "<p>Невозможно обновить записи в таблицы \"Рецепты блюд\" $conn->error </p>\n";
			break;
		case 'delete':
			$query="DELETE FROM `Рецепты блюд` ".
				   "WHERE `Название блюда`= '$food_name' and `Наименование продукта`='$product_name' and `Единицы измерения`='$measure' and `Количество`='$amount'";	   
			$result=$conn->query($query);
			if (!$result)
				echo "<p>Невозможно удалить записи из таблицы \"Рецепты блюд\": $conn->error </p>\n";
	}

	$query="SELECT `Название блюда`, `Наименование продукта`, `Единицы измерения`, `Количество` FROM `Рецепты блюд`";
	$result=$conn->query($query);
	if (!$result)
		echo "<p>Невозможно просмотреть записи из таблицы \"Рецепты блюд\": $conn->error </p>\n";
	else {
		echo "<table id='tbl' cellspacing='0' cellpadding='8' border='1'>\n";
		echo "\t<caption>Рецепты блюд</caption>\n";
		echo "\t<tbody style='text-align:center'>\n";	 
		echo "\t\t<tr><th>Название блюда</th><th>Наименование продукта</th><th>Единицы измерения</th><th>Количество</th></tr>\n";
		while ($row=$result->fetch_array(MYSQLI_NUM)) {
			echo "\t\t<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td><td>$row[3]</td></tr>\n";
		}
		echo "\t</tbody>\n";
		echo "</table>\n";
		$result->close();
	}
	$conn->close();
}
?>
<br>
<form id="form1" method="post">
	<input type="hidden" id="food_name_Old">
	<input type="hidden" id="product_name_Old">
	<input type="hidden" id="measure_Old">
	<input type="hidden" id="amount_Old">
	<input type="hidden" id="Ok" name="Ok">
	<table cellspacing="0" cellpadding="4" border="0">
		<tr>
			<th class="stR"><label for="food_name">Название блюда</label></th>
			<td><input type="text" id="food_name" name="food_name" size=15 maxlength=18 placeholder="Жульен с мидиями" required></td>
		</tr>
		<tr>
			<th class="stR"><label for="product_name">Наименование продукта</label></th>
			<td><input type="text" id="product_name" name="product_name" size=15 maxlength=18 placeholder="Мидии" required></td>
		</tr>
		<tr>
			<th class="stR"><label for="measure">Единицы измерения</label></th>
			<td><input type="text" id="measure" name="measure" size=4 maxlength=6 required></td>
		</tr>
		<tr>
			<th class="stR"><label for="amount">Количество</label></th>
			<td><input type="number" id="amount" name="amount" size=6 min="1" max="999999999" pattern="\d[1-999999999]" required></td>
		</tr>
		<tr>
			<th class="stR"><input type="submit" value="Создать новую запись" onclick="f1('insert')"></th>
			<td><input type="submit" value="Изменить выбранную запись" onclick="f1('update')"></td>
		</tr>
		<tr>		
			<th class="stR"><input type="reset" value="Очистить поля формы"></th>
			<td><input type="submit" value="Удалить выбранную запись" onclick="f1('delete')"></td>
		</tr>	
	</table>
</form>
<script>
var rowCount; 									// номер выбранной строки таблицы
var tbl1=document.getElementById("tbl");
tbl1.addEventListener("click", (e)=>{			// Обработка события "e" - клик мышки на таблице
	let cell = e.target;						// Свойства
	let t = cell.parentElement;					// Где произошло 
	let r = t.parentElement.children;			// Выбираем массив строк
	for (rowCount = 1; rowCount < r.length; rowCount++) {
		if (r[rowCount] === t) {				// Идентичность объектов
			d=r[rowCount].getElementsByTagName("td");
			document.getElementById("food_name").value=d[0].innerHTML;
			document.getElementById("food_name_Old").value=d[0].innerHTML;
			document.getElementById("product_name").value=d[1].innerHTML;
			document.getElementById("product_name_Old").value=d[1].innerHTML;
			document.getElementById("measure").value=d[2].innerHTML;
			document.getElementById("measure_Old").value=d[2].innerHTML;
			document.getElementById("amount").value=d[3].innerHTML;
			document.getElementById("amount_Old").value=d[3].innerHTML;
		}
	}
	rowCount=-1;
});
</script>
</body>
</html>