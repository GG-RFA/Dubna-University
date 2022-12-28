<?php
// здесь начинаются проверки по regexp
if ($status != "select") {
    if ($dataPost->tab == "Члены_общества" || $dataPost->tab=="члены_общества" ) {
        if (!preg_match('/^[а-яё\s]++$/ui', $dataPost->data[0][1])) {
            $msg = '<div class="alert alert-danger" role="alert">В колонке "ФИО члена общества" должны быть только буквы русского алфавита!</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
      if ($dataPost->tab == "Мероприятия_общества" || $dataPost->tab=="мероприятия_общества") {
        if (!preg_match('/^[^A-z]+$/ui', $dataPost->data[0][2])) {
            $msg = '<div class="alert alert-danger" role="alert">В колонке "Мероприятия" не должно быть букв английского алфавита!</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
      if ($dataPost->tab == "Члены_общества" || $dataPost->tab=="члены_общества" ) {
        if (!preg_match('/^[^A-z]+$/ui', $dataPost->data[0][2])) {
            $msg = '<div class="alert alert-danger" role="alert">В колонке "Домашний адрес" не должно быть букв английского алфавита!</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
    if ($dataPost->tab == "Члены_общества" || $dataPost->tab=="члены_общества" ) {
        if (!preg_match('/^[0-9]{4}$/', $dataPost->data[0][0])) {
            $msg = '<div class="alert alert-danger" role="alert">В колонке "№ билета" должно быть 4 цифры!</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
    if ($dataPost->tab == "Мероприятия_общества" || $dataPost->tab=="мероприятия_общества" ) {
        if (!preg_match('/^[0-9]{3}$/', $dataPost->data[0][0])) {
            $msg = '<div class="alert alert-danger" role="alert">В колонке "№ порядковый" должно быть 3 цифры!</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
    if ($dataPost->tab == "Мероприятия_общества" || $dataPost->tab=="мероприятия_общества" ) {
        if (!preg_match('/^(19|20)[0-9]{2}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$/', $dataPost->data[0][1])) {
            $msg = '<div class="alert alert-danger" role="alert">В колонке "Дата проведения" неверно введена дата!</div>';
            array_push($rows, $msg);
            $flag = false;
        }
    }
}
?>