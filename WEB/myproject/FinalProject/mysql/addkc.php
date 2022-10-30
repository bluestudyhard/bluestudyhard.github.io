<?php
include "database.php";

$sql = new SQL();
if (isset($_GET['action'])) {
    switch ($_GET['action']) {
        case "add";
            $coursenum = $_POST['courseNum'];
            $coursename = $_POST['courseName'];
            $term = $_POST['term'];
            $studyhour = $_POST['studyhour'];
            $point = $_POST['point'];
            $str_add = "insert into stukc values ('{$coursenum}','{$coursename}','{$term}','{$studyhour}','{$point}')";
            if ($str_add > 0) {
                $sql->Run($str_add);
                echo "<script>alert('添加成功');window.location = '../tea/stucourse.php'</script>";
            } else {
                echo "<script>alert('添加失败');window.history.back();</script>";
            }
            break;
        case "del";
            $SID = $_GET['uid'];
            $str_del = "delete from stukc where courseNum = '$SID' ";
            $sql->Run($str_del);
            echo "<script>alert('删除成功');window.location = '../tea/stucourse.php';</script>";
            break;
        case "del1";
            $SID = $_GET['uid'];
            $str_del = "delete from stuxskc where courseNum = '$SID' ";
            $sql->Run($str_del);
            echo "<script>alert('删除成功');window.location = '../tea/stuscore.php';</script>";
            break;
    }
}