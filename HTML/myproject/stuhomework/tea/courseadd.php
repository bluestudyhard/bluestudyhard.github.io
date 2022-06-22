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
            </div>
        </div>

        <div class="right-side">
            <form action="../mysql/addkc.php?action=add" method="post">
                <div class="addlabel">课程号
                    <input type="text" name="courseNum">
                </div>
                <div class="addlabel">课程名
                    <input type="text" name="courseName">
                </div>
                <div class="addlabel">开课学期
                    <input type="text" name="term">
                </div>
                <div class="addlabel">学时
                    <input type="text" name="studyhour">
                </div>
                <div class="addlabel">所得学分
                    <input type="text" name="point">
                </div>
                <div class="addlabel">
                    <input type="submit" value="提交">
                </div>
            </form>
        </div>
</body>

</html>