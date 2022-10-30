<?php
session_start();
include("Data/database.php");

$username    = "";
$per_arr     = [];
$class_arr   = [];
$final_score = [];
$for_search1 = [];
$for_search2 = [];
$define_sex  = ['女', '男']; //数据0.1的判断
$tot_time    = 0;
$tot_point   = 0;
$avg_score   = 0;
$flag1       = false;
$flag2       = false;
if (!isset($_SESSION['username'])) {

    $username             = trim($_POST["username"]);
    $_SESSION['username'] = $username;
} else
    $username = $_SESSION['username'];
$sql1   = new SQL();
$gramma = "select `class`,`number`,`name`,`sex`,`project`,`born`,`totalnumber` from `stuinfo` where '$username' = `number`";
$sql1->Run($gramma); //select完后存储的是二维数组，但二维数组只有一个索引
if (!empty($sql1->arr)) {
    $i = 0;
    foreach ($sql1->arr[0] as $value) {
        $per_arr[$i++] = $value;
    }
}
$sql2    = new SQL();
$gramma2 = "select `courseNum`, `score` from `stuxskc` where '$username' = `number`";
$sql2->Run($gramma2);
$num = 0;
//print_r($sql2->arr);
//echo $num . "<br>";
$score_arr = [];
$sql3      = new SQL();;
$key  = 0;
$key2 = 0;
foreach ($sql2->arr as $value) {
    $number = $value['courseNum'];
    //    echo $number . "<br>";


    $gramma3 = "select `courseNum`, `courseName`, `term`, `studyhour`, `point` from stukc where '$number' = `courseNum`";
    $sql3->Run($gramma3);
    if (!empty($sql3->arr)) {
        foreach ($sql3->arr as $value2) {
            $score_arr[$key]          = $value2;
            $score_arr[$key]["score"] = $sql2->arr[$key]["score"];

            $final_score[$score_arr[$key]["courseNum"]] = $score_arr[$key]["score"]; //获得关于成绩和科目的关联数组，要用直接调用该科目名称的键
            //          ---nothing


            $avg_score += $score_arr[$key]["score"];
            $tot_point += $score_arr[$key]["point"];
            $tot_time  += $score_arr[$key]["studyhour"];
            $key++;
        }
    }
    if (!empty($_POST['search1'])) {
        $search = $_POST['search1'];
        $flag1  = true;
        $sql5   = new SQL();
        $str    = "select `courseNum`, `courseName`, `term`, `studyhour`, `point` from stukc where `courseNum` = '$number' and(`courseName` like '%$search%' or `term` like '%$search%' or `studyhour` like '%$search%' or `point` like '%$search%')";
        $sql5->Run($str);
        foreach ($sql5->arr as $value3) {
            $for_search1[$key2]          = $value3;
            $for_search1[$key2]['score'] = $final_score[$for_search1[$key2]['courseNum']];
        }
    }
    $key2++;
}
$avg_score /= count($score_arr);
$sql4      = new SQL();
$gramma4   = "select `courseNum`, `courseName`, `term`, `studyhour`,`point` from stukc";
$sql4->Run($gramma4);
if (!empty($sql4->arr)) {
    $key = 0;
    foreach ($sql4->arr as $value) {
        $class_arr[$key++] = $value;
    }
}
$flag_btn2 = false;
if (!empty($_POST['search2'])) {
    $flag_btn2 = true;
    $search    = $_POST['search2'];
    $flag2     = true;
    $sql6      = new SQL();
    $str       = "select `courseNum`, `courseName`, `term`, `studyhour`, `point` from stukc where `courseNum` like '%$search%' or`courseName` like '%$search%' or `term` like '%$search%' or `studyhour` like '%$search%' or `point` like '%$search%'";
    $sql6->Run($str);
    //    print_r($sql6->arr);
    $key3 = 0;
    foreach ($sql6->arr as $value3) {
        $for_search2[$key3++] = $value3;
    }
    //    print_r($for_search2);

} else
    $flag2 = false;
if ($flag_btn2 === true) {
    echo "<script>
    window.onload = function()
    {
        document.querySelector('.classroom').click();
    }
</script>";
}
?>


<!doctype html>
<html lang="zh">

<head>
    <meta charset="utf-8">
    <link rel="icon" sizes="32X32" href="img/sheep.jpg">
    <link rel="stylesheet" href="css/index.css">
    <link rel="stylesheet" href="https://cdn.staticfile.org/font-awesome/4.7.0/css/font-awesome.css">
    <title>学生界面</title>
</head>

<body>
<div class="shadow_before"></div>
<div class="left-box">
    <button type="button" class="score" onclick="showBox1()">学生成绩</button>
    <button type="button" class="classroom" onclick="showBox2()">课程安排</button>
</div>
<div class="header">学生成绩管理系统(学生端)</div>
<div class="setting">
    <div class="setting-btn"><i class="fa fa-gear" style="font-size:40px;"></i></div>
    <div class="list">
        <div>
            <button class="author">个人信息</button>
        </div>
        <div class="logout"><a href="login.php">安全退出</a></div>
    </div>
</div>
<div class="person_info showinfo">
    <button class="info_return"><i class="fa fa-close" style="font-size:20px;"></i></button>
    <div class="info_header">
        学生个人信息
    </div>
    <!--    onsubmit="return false;"看情况-->
    <form action="update_stu.php" method="post" target="here">
        <div class="per_info" style="position:relative;">
            <span class="one_info">系别:计算机科学与工程学院</span><span class="two_info">班级:<span><?php echo $per_arr[0] ?></span></span>
        </div>
        <div class="per_info" style="position:relative;">
            <span class="one_info">名字:<span><?php echo $per_arr[2] ?></span></span>
            <span class="two_info">学号:<span><?php echo $per_arr[1] ?></span></span>
        </div>
        <div class="per_info" style="position:relative;">
            <span class="one_info">生日:<span><?php echo $per_arr[5] ?></span></span>
            <span class="two_info">性别:<span><?php echo $per_arr[3] ?></span></span>
        </div>
        <div class="per_info" style="position:relative;">
            <span class="one_info">专业:<span><?php echo $per_arr[4] ?></span></span>
            <span class="two_info">总学分:<?php echo $per_arr[6] ?></span>
        </div>
        <button type="submit" class="set showSet btn button" onclick="change()">保存</button>
    </form>
    <button class="change btn button">修改</button>
    <button class="reflesh button" onclick="change()">刷新</button>
</div>
<div class="score-box showBox">
    <div>
        <div class="table-header">成绩明细</div>
    </div>
    <div class="search1 ">
        <form style="display:block;" action="index.php" method="post" class="form1">
            <input class="search-bar" type="text" name="search1" placeholder="Search"/>
            <div class="tubiao">
                <button type="submit" class="submit1"><i class="fa fa-search" style="font-size:30px;"></i></button>
            </div>
        </form>
    </div>
    <div class="score_info">
        <div class="tot_time">总学时: <?php echo $tot_time ?></div>
        <div class="tot_GPA">总学分: <?php echo $tot_point ?></div>
        <div class="avg_score">平均成绩:<?php echo sprintf("%01.2f", $avg_score) ?></div>
        <div class="print">打印时间:<?php echo date("Y-m-d"); ?></div>
    </div>
    <table class="score-table">
        <thead>
        <th>课程名</th>
        <th>学期</th>
        <th>学时</th>
        <th>获得学分</th>
        <th>成绩</th>
        </thead>
        <tbody>
        <?php
        //        echo "score表数:" . count($score_arr);
        if ($flag1 === false) {
            foreach ($score_arr as $value1) {
                $flag3 = false;
                echo "<tr>";
                foreach ($value1 as $value2) {
                    if ($flag3 === false) {
                        $flag3 = true;
                        continue;
                    }
                    echo "<td>";
                    echo $value2;
                    echo "</td>";
                }
                echo "</tr>";
            }
        } else {
            $key6 = 0;
            $num  = "";
            //            print_r($for_search1);
            foreach ($for_search1 as $value) {
                $flag3 = false;
                echo "<tr>";
                foreach ($value as $value2) {
                    if ($flag3 === false) {
                        $flag3 = true;
                        continue;
                    }
                    echo "<td>";
                    echo $value2;
                    echo "</td>";
                }
            }
        }
        ?>
        </tbody>
    </table>
    <div class="footer">
        <div>第 1 页 &nbsp;&nbsp;&nbsp; 共 1 页</div>
    </div>
</div>
<div class="classroom-box hidBox">
    <div class="class_header">
        课程安排表
    </div>
    <div class="search2 ">
        <form style="display:block;" action="index.php" method="post" class="form2">
            <input class="search-bar" type="text" name="search2" placeholder="Search"/>
            <div class="tubiao">
                <button type="submit" class="submit2"><i class="fa fa-search" style="font-size:30px;"></i></button>
            </div>
        </form>
    </div>
    <table class="room-table">
        <thead>
        <th>编号</th>
        <th>课程名</th>
        <th>学期</th>
        <th>学时</th>
        <th>学分</th>
        </thead>
        <tbody>
        <?php
        if ($flag2 === false) {
            foreach ($class_arr as $value) {
                echo "<tr>";
                foreach ($value as $value2) {
                    echo "<td>";
                    echo $value2;
                    echo "</td>";
                }

                echo "</tr>";
            }
        } else {
            foreach ($for_search2 as $value) {
                echo "<tr>";
                foreach ($value as $value2) {
                    echo "<td>";
                    echo $value2;
                    echo "</td>";
                }
                echo "</tr>";
            }
        }


        ?>
        </tbody>
    </table>
</div>
<iframe id="here" name="here"></iframe>
</body>
<script src="Js/index.js"></script>

</html>