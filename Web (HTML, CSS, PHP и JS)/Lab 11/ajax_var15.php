<?php
require_once 'login_var15.php';
$conn = new mysqli($server, $user, $password, $dbname);
if ($conn->connect_error)
	echo "<p>Невозможно подключиться к серверу или открыть БД: $conn->connect_error </p>\n";
else {
	$Ok        = $_POST['Ok']; 
	$food_name = $_POST['food_name'];
	$product_name = $_POST['product_name'];
	$measure  = $_POST['measure'];
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
			$product_name_Old  = $_POST['product_name_Old'];
			$measure_Old       = $_POST['measure_Old'];
			$amount_Old        = $_POST['amount_Old '];
			
			$query= "UPDATE `Рецепты блюд` ".
					"SET `Название блюда`='$food_name', `Наименование продукта`='$product_name', `Единицы измерения`='$measure' , `Количество`='$amount' ".
					"WHERE `Название блюда`='$food_name_Old' AND `Наименование продукта`='$product_name_Old'";
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
		$txt='';
		while ($row=$result->fetch_array(MYSQLI_NUM)) {
			$txt.='<tr><td>'.$row[0].'</td><td>'.$row[1].'</td><td>'.$row[2].'</td><td>'.$row[3].'</td></tr>';
		}
		echo $txt;
		$result->close();
	}
	$conn->close();
}
?>
