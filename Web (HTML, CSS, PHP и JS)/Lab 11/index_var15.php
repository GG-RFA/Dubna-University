<!doctype html>
<html>
<head>
<meta charset="utf-8">
<title>Задание 11</title>
<link rel="stylesheet" href="style_var15.css" type="text/css">
<script>
// определяем тип запроса
var XMLHttpRequestObject=false;
if (window.XMLHttpRequest) 
	XMLHttpRequestObject=new XMLHttpRequest(); 
else if ( window.ActiveXObject ) {
	XMLHttpRequestObject=new ActiveXObject("Microsoft.XMLHTTP");}

// Вставка кусков текста в HTML документ
// ВНИМАНИЕ!!! ЭТА ФУНКЦИЯ НЕ СОВПАДАЕТ ПОЛНОСТЬЮ С ФУНКЦИЕЙ ИЗ ЗАДАНИЯ № 4 !!!
function getDate(txt,callback){
	XMLHttpRequestObject.open("POST", "ajax_var15.php",true);
	XMLHttpRequestObject.send(txt);
	if ( XMLHttpRequestObject ) {
		XMLHttpRequestObject.onreadystatechange= function() {
			if ( XMLHttpRequestObject.readyState==4 && XMLHttpRequestObject.status==200 ) {
				callback(XMLHttpRequestObject.response);
			} 
		}
	}
}

// Создание таблицы
function f1(op) { 
	Ok.setAttribute('value', op);
	if (op == 'update') {    // Только в этом случае передаём дополнительные данные !!!
		food_name_Old.setAttribute('name', 'food_name_Old');
		product_name_Old.setAttribute('name', 'product_name_Old');
		measure_Old.setAttribute('name', 'measure_Old');
		amount_Old.setAttribute('name', 'amount_Old');
	}	
	getDate("jjj",
		(txt)=>{document.innerHTML=txt;} // создание таблицы
	)
}
</script>
</head>
<body>
<table id='tbl' cellspacing='0' cellpadding='8' border='1'>
	<caption>Рецепты блюд</caption>
	<tbody style='text-align:center'>	 
	<tr><th>Название блюда</th><th>Наименование продукта</th><th>Единицы измерения</th><th>Количество</th></tr>
	<?php require_once 'ajax_var15.php';?>
	</tbody>
</table>
<br>
<form id="form1" method="POST">
	<input type="hidden" id="food_name_Old">
	<input type="hidden" id="product_name_Old">
	<input type="hidden" id="measure_Old">
	<input type="hidden" id="amount_Old">
	<input type="hidden" id="Ok" name="Ok">
	<table cellspacing="0" cellpadding="4" border="0">
		<tr>
			<th class="stR"><label for="food_name">Название блюда</label></th>
			<td><input id="food_name" name="food_name" size=18 maxlength=18 placeholder="Введите название блюда" required></td>
		</tr>
		<tr>
			
		<th class="stR"><label for="product_name">Наименование продукта</label></th>
			<td>
                        <select name="product_name" id="product_name">
                        <option value="Мидии">Мидии</option>
                        <option value="Лук">Лук</option>
                        <option value="Сыр">Сыр</option>
                        <option value="Яйцо куриное">Яйцо куриное</option>
                        <option value="Кальмары">Кальмары</option>
                        </select>
            </td>
            
		</tr>
		<tr>
		<th class="stR">Единицы измерения</th>
			<td><input type="radio" id="measure0" name="measure" value="Г" checked>
				<label for="measure0">Граммы</label>
				<input type="radio" id="measure1" name="measure" value="Ш">
				<label for="measure1">Штуки</label>
			</td>
		</tr>
		<tr>
		<th class="stR"><label for="amount">Количество</label></th>
		<td><input type="number" id="amount" name="amount" size=4 maxlength=4 placeholder="9999" required></td>
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
			document.getElementById("measure_Old").value=d[2].innerHTML;
			if (d[2].innerHTML=="Г")
				document.getElementById("measure0").checked=true;
			else
				document.getElementById("measure1").checked=true;
			document.getElementById("amount").value=d[3].innerHTML;
			document.getElementById("amount_Old").value=d[3].innerHTML;
			return;
		}
	}
	rowCount=-1;
});
</script>
</body>
</html>