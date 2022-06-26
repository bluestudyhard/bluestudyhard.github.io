<?php

include "../mysql/database.php";
$sql = new SQL();

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <link rel="stylesheet" href="../style/template.css"/>
    <link rel="stylesheet" href="../style/teacheradd.css"/>
    <title>mysql</title>
</head>

<body>
<div class="app">
    <div class="header">
        <div class="container">
            <div>欢</div>
            <div>迎</div>
            <div>来</div>
            <div>到</div>
            <div>学</div>
            <div>生</div>
            <div>管</div>
            <div>理</div>
            <div>系</div>
            <div>统</div>
        </div>
    </div>
    <div class="content">

        <div class="left-side">
            <div class="leftbody">
                <label class="left-button">
            <span>
                <a href="teacheradd.php"> 学生信息添加</a>
                <input type="radio" name="option" value="score"/>
            </span>
                </label>
                <label class="left-button">
                        <span>
                                <a href="courseadd.php"> 课程信息添加</a>
                                <input type="radio" name="option" value="score"/>
                        </span>
                </label>
                <label class="left-button">
                        <span>
                                <a href="teacher.php"> 返回主页</a>
                                <input type="radio" name="option" value="score"/>
                        </span>
                </label>
            </div>
        </div>

        <div class="right-side">
            <form action="../mysql/add.php?action=add2" method="post">
                <div class="addlabel">员工号
                    <input type="text" name="eid">
                <div class="addlabel">员工姓名
                    <input type="text" name="ename">
                </div>
                <div class="addlabel">员工年龄
                    <input type="text" name="age">
                </div>
                <div class="addlabel">员工薪资
                    <input type="text" name="salary">
                <div class="addlabel">
                    <input type="submit" value="上传数据">
                </div>
            </form>
        </div>
</body>

</html>