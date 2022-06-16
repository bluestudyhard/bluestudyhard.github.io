<?php

include "../mysql/database.php";
$sql = new SQL();

?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <link rel="stylesheet" href="../style/template.css" />
  <link rel="stylesheet" href="../style/stu.css" />
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
              <input type="radio" name="option" value="score" />
            </span>
          </label>
          <label class="left-button">
            <span>
              课程管理
              <input type="radio" name="option" value="score" />
            </span>
          </label>
        </div>
      </div>

      <div class="right-side">
        <form action="../mysql/add.php?action=add" method="post">
          <div>学号
            <input type="text" name="studentID" value="2333">
          </div>
          <div>姓名
            <input type="text" name="studentName">
          </div>
          <div>性别
            <input type="radio" name="sex" value="1" /> 男
            <input type="radio" name="sex" value="0" />女
          </div>
          <div>专业名
            <input type="text" name="project">
          </div>
          <div>出生日期
            <input type="text" name="born">
          </div>
          <div>总学分
            <input type="text" name="point">
          </div>
          <div>
            <input type="submit" value="提交">
          </div>
        </form>
      </div>
</body>

</html>