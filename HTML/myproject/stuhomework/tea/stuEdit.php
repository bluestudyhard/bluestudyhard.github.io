<?php

include "../mysql/database.php";
$sql = new SQL();
if (isset($_POST)) {
    switch ($_GET['action']) {
        case "stu";
            //print_r($_POST);
            $stuid = $_POST['number'];
            foreach ($_POST as $key => $value) {
                $str = "call update_stuinfo('{$stuid}', '{$key}', '{$value}')";
                $sql->Run($str);
            }
            header("location:teacher.php");
            break;
        case "course";
            $courseID = $_POST['courseNum'];
            foreach ($_POST as $key => $value)// foreach 特性，key是获取数组键值，也就是表头，value就是里面的结果，foreach本身就可以把表的元素拆分成一个个
            {
                $str = "call update_course('{$courseID}','{$key}','{$value}')";
                $sql->Run($str);
                header("location:stucourse.php");

            }
            break;
        case "search";
            $info = $_POST['ser'];
            print_r($info);
            break;
    }

}
