<?php
include("Data/database.php");
$sql = new SQL();
if (isset($_POST)) {
    $stuid = $_POST['number'];
    print_r($_POST);
    foreach ($_POST as $key => $value) {
        $str = "call update_stuinfo('{$stuid}','{$key}','{$value}')";
        $sql->Run($str);
    }
    print_r($sql->arr);
}
