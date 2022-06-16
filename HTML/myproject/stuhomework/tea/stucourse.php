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
    <link rel="stylesheet" href="../style/stu.css"/>
    <script>
        function doDel(number1) {
            if (confirm("真的要删掉吗？")) {
                window.location = 'mysql/add.php?action=del&uid=' + number1;
            }
        }
    </script>
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
              <a href="teacher.php"> 学生管理</a>
              <input type="radio" name="option" value="score"/>
            </span>
                </label>
                <label class="left-button">
            <span>
              <a href="stucourse.php"> 课程管理</a>
              <input type="radio" name="option" value="score"/>
            </span>
                </label>
            </div>
        </div>
        <a href='teacheradd.php'>增加 </a>
        <div class="right-side">
            <?php
            echo '<table>
          <thead>
          <th>序号</th>
            <th>课程号</th>
            <th>课程名</th>
            <th>学期</th>
            <th>学时</th>
            <th>学分</th>
            <th>修改信息</th>
          </thead>
          <tbody>';

            $str = 'select * from stukc';
            $sql->Run($str);

            function printTable($arr, $head): void
            {
                $i = 1;
                foreach ($arr as $row) {
                    echo "<tr><td>{$i}</td>";
                    $i++;
                    foreach ($head as $col) {
                        echo "<td id='{$col}'>{$row[$col]}</td>";
                    }
                    echo "<td><a href='javascript:edit()' class='edit'>修改  </a><a href='javascript:doDel({$row['courseNum']})')>  删除</a></td></tr>";
                }
                echo '</tbody></table>';
            }

            printTable($sql->arr, $sql->head);
            ?>
            <script src="../style/index.js"></script>
        </div>
    </div>
    <div class="footer" style="text-align: center;">
        <span></span>
    </div>
</body>

</html>