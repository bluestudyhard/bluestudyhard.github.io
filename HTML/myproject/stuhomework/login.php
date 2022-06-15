<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <link rel="stylesheet" href="style/template.css"/>
    <link rel="stylesheet" href="style/login.css"/>
    <title>mysql</title>
</head>

<body>
<div class="header">aaa</div>
<form action="login.php" method="post">
    <div><input type="text" name="studentName" size="10/"/></div>
    <div>
        <input type="text" name="studentID" size="10/"/>
    </div>
    <div>
        <input type="submit" value="mis"/>
    </div>

</form>
</body>

</html>

<?php
include "mysql/database.php";
if (isset($_POST)) {
//    print_r($_POST);
//    $sql = new SQL();
//    $str = 'select * from stuinfo';
//    $sql->Run($str);
//    print_r($sql);//打印变量
//    echo $str;
}

$sql = new SQL();
$str = 'select * from stuinfo';
$sql->Run($str);//执行
$stuid = $_POST['studentID'];
$stuname = $_POST['studentName'];
$stuproject = $_POST['project'];
$stusex = $_POST['sex'];
$stuborn = $_POST['born'];
$str_add = "insert into stuinfo values (null,'{$stuid}','{$stuname}','{$stusex}','{$stuproject}','{$stuborn}','{$stuid}')";
//$sql->Run($str_add);
//print_r($sql->arr);//打印变量

foreach ($sql->head as $col)
    echo $col, '<br>';

echo '<table><thead><th>姓名</th><th>学号</th><th>性别</th><th>专业名</th><th>学分</th><th>专业名</th><th>修改信息</th></thead><tbody>';

function printTable($arr, $head): void
{
    foreach ($arr as $row) {

        echo '<tr>';
        foreach ($head as $col) {
            echo '<td>', $row[$col], '</td>';
        }
        echo '<td><a href="teacheradd.php">增加  <a href="teacheradd.php">修改  <a href="teacheradd.php">删除 </td>', '</tr>';
    }
    echo '</tbody></table>';
}

printTable($sql->arr, $sql->head);
?>


