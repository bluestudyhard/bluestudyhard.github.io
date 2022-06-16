<?php

include "../mysql/database.php";
$sql = new SQL();
if (isset($_POST)) {
    //print_r($_POST);
    $stuid = $_POST['number'];
    foreach ($_POST as $key => $value) {
        $str = "call update_stuinfo('{$stuid}', '{$key}', '{$value}')";
//        echo $str, '<br>';
        $sql->Run($str);
    }
    header("location:teacher.php");
}
