<?php
include("Data/database.php");
$search = $_POST['search'];   //接收搜索框中的内容
$sql    = new SQL();
echo $search;
$str = "select `class`,`number`,`name` from `stuinfo` where `name` like '%{$search}%'";
$sql->Run($str);
print_r($sql->arr);
if (empty($sql->arr))
    echo "nope";
?>
<!DOCTYPE html>
<html lang="zh">
<head>
    <meta charset="UTF-8">
    <title>Insert title here</title>
    <style>
        table, th, td {
            border: 1px solid #000;
        }
    </style>
</head>
<body>
<form action="index.php" method="post">
    <input type="text" name="search" value="">
    <input type="submit" name="submit" value="搜索">
</form>
<table>
    <th colspan="5">学生查询系统</th>
    <tr>
        <td>序号</td>
        <td>姓名</td>
        <td>年龄</td>
        <td>专业</td>
        <td>班级</td>
    </tr>
</table>
</body>
</html>