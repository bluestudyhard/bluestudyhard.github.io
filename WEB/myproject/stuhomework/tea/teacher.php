<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
    <link rel="stylesheet" href="../style/template.css"/>
    <link rel="stylesheet" href="../style/stu.css"/>
    <!--    <link rel="stylesheet" href="../style/serach.css" />-->
    <link rel="stylesheet" href="../style/text.css"/>
    <link rel="stylesheet" href="https://cdn.staticfile.org/font-awesome/4.7.0/css/font-awesome.css">
    <script>
        function doDel(number1) {
            if (confirm("真的要删掉吗？")) {
                window.location = '../mysql/add.php?action=del&uid=' + number1;
            }
        }
    </script>
    <script type="text/javascript" src="https://wow.techbrood.com/libs/jquery/jquery-2.1.1.min.js"></script>
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
        <a href='teacheradd.php' class="add" class="fa fa-plus-square-o">&#xf196 </a>
    </div>
    <div class="content">
        <div class="left-side">
            <div class="leftbody">
                <div class="left-logo">
                    <img src="../img/bluesheep.jpg">
                    <div class="author">cover by blue and stupidsheep</div>
                </div>
                <div class="leftbuttons">
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
                    <label class="left-button">
                            <span>
                                <a href="stuscore.php"> 成绩管理</a>
                                <input type="radio" name="option" value="score"/>
                            </span>
                    </label>
                </div>
            </div>
        </div>
        <div class="right-side">
            <div class="nav-search-box">
                <div class="nav-search">
                    <form action="stuserach.php" method="post">
                        <div class="search-box">
                            <input class="search-txt" type='text' id='inp' name="ser"/>
                            <input class="search-btn" type='submit' id='btn' value='&#xf002'/>
                        </div>
                    </form>
                </div>
            </div>

            <form action="stuEdit.php?action=stu" method="post" class="stu-form">
                <table>
                    <thead>
                    <th>序号</th>
                    <th>学号</th>
                    <th>姓名</th>
                    <th>性别</th>
                    <th>专业名</th>
                    <th>出生日期</th>
                    <th>总学分</th>
                    <th>修改信息</th>
                    </thead>
                    <tbody>
                    <?php
                    include "../mysql/database.php";
                    $sql = new SQL();
                    $str = 'select * from stuinfo';
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
                            echo "<td><a href='javascript:edit()' class='edit'>修改  </a><a href='javascript:doDel({$row['number']})')>  删除</a></td></tr>";
                        }
                        echo '</tbody></table>';
                    }
                    printTable($sql->arr, $sql->head);
                    ?>
            </form>
            <script src="../style/index.js"></script>
        </div>
    </div>
    <div class="footer" style="text-align: center;">
        <span></span>
    </div>

</body>

</html>