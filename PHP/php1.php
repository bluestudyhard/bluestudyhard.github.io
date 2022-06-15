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
<form action="php1.php?action=add" method="post">
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

//echo '<h2>ss </h2>>';
//
//const blue = "19";
//echo blue;
//
//
//$blll = '字符串';
//var_dump($blll);//打印并返回类型
//echo '<br>';
//print_r($blll);


$table = "<table border=1px ><th>姓名</th><th>学号</th><th>性别</th><th>专业名</th><th>学分</th><th>专业名</th><tr><td>蓝凯</td><td>2114100314</td><td>男</td><td>计算机</td><td>50</td><td>杨</td></tr><tr><td>蓝凯</td><td>2114100314</td><td>男</td><td>计算机</td><td>50</td><td>杨</td></tr><tr><td>蓝凯</td><td>2114100314</td><td>男</td><td>计算机</td><td>50</td><td>杨</td></tr>";
print_r($table);

if(isset($_POST))
{   $stuid = $_POST['studentID'];
    $stuname = $_POST['studentName'];
    $stuproject = $_POST['project'];
    $stusex = $_POST['sex'];
    $stuborn= $_POST['born'];
    print_r($_POST);
}
