<?php

include "mysql/database.php";
$sql = new SQL();

if (isset($_POST)) {
    $stuid = $_POST['studentID'];
    $stuname = $_POST['studentName'];
    $stusex = $_POST['sex'];
    $stuproject = $_POST['project'];
    $stuborn = $_POST['born'];
    $stupoint = $_POST['point'];
    $str_add = "insert into stuinfo values ('{$stuid}','{$stuname}','{$stusex}','{$stuproject}','{$stuborn}','{$stuid}')";
    $sql->Run($str_add);
}


?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <link rel="stylesheet" href="style/template.css"/>
    <link rel="stylesheet" href="style/stu.css"/>
    <title>mysql</title>
</head>

<body>
<div class="app">
    <div class="header">
        <div class="header-title">欢迎来到学生成绩管理系统</div>
    </div>
    <div class="content">
        <div class="left-side">
            <div class="leftbody">
                131
                <label class="left-button">
            <span>
              成绩管理
              <input type="radio" name="option" value="score"/>
            </span>
                </label>
                <label class="left-button">
            <span>
              课程管理
              <input type="radio" name="option" value="score"/>
            </span>
                </label>
            </div>
        </div>

        <div class="right-side">
            <?php
            echo '<table>
          <thead>
            <th>姓名</th>
            <th>学号</th>
            <th>性别</th>
            <th>专业名</th>
            <th>出生日期</th>
            <th>总学分</th>
            <th>修改信息</th>
          </thead>
          <tbody>';

            $str = 'select * from stuinfo';
            $sql->Run($str);
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

            <!-- <div class="change-form">
                <span>修改学生信息</span>
                <form action="student.php" method="post">
                    <input type="text">

                </form>
            </div> -->

        </div>
    </div>
    <div class="footer" style="text-align: center;">
        <span>cover by blue @3164752596@qq.com</span>
    </div>
</body>

</html>