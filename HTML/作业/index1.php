<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>制作第一个PHP网页</title>
  </head>
  <body>
<?php 
  echo "<h1>欢迎来到我的网站!<h1> <br>";

?>
<p>我是惠州学院计算机科学与工程学院3班蓝凯</p>
<hr>
<h2>当前系统时间为</h2>
<?php
  date_default_timezone_set("PRC");
  echo date("y-m-d h:i:s");
?>
  </body>