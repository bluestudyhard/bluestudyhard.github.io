<?php
include "database.php";

$sql = new SQL();
if (isset($_GET['action'])) {
    switch ($_GET['action']) {
        case "add";
            $stuid = $_POST['studentID'];
            $stuname = $_POST['studentName'];
            $stusex = $_POST['sex'];
            $stuproject = $_POST['project'];
            $stuborn = $_POST['born'];
            $stupoint = $_POST['point'];
            $coursenum = $_POST['courseNum'];
            $score = $_POST['score'];
            $str_add = "insert into stuinfo values ('{$stuid}','{$stuname}','{$stusex}','{$stuproject}','{$stuborn}','{$stupoint}')";
            $str_add1 = "insert into stuxskc value ('{$stuid}','{$coursenum}','{$score}')";
            if ($str_add > 0) {
                $sql->Run($str_add);
                $sql->Run($str_add1);
                echo "<script>alert('添加成功');window.location = '../tea/teacher.php'</script>";
            } else {
                echo "<script>alert('添加失败');window.history.back();</script>";
            }
            break;
        case "del";
            $SID = $_GET['uid'];
            $str_del = "delete from stuinfo where number = '$SID' ";
            $sql->Run($str_del);
            echo "<script>alert('删除成功');window.location = '../tea/teacher.php'</script>";
            break;
        case "del1";
            $SID = $_GET['uid'];
            $str_del = "delete from stuxskc  where courseNum = '$SID' ";
            $sql->Run($str_del);
            echo "<script>alert('删除成功');window.location = '../tea/stuscore.php'</script>";
            break;
    }
}