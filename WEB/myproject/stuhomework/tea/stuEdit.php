<?php

include "../mysql/database.php";
$sql = new SQL();
if (isset($_POST)) {
    switch ($_GET['action']) {
        case "stu";
            //print_r($_POST);
            $stuid = $_POST['oldID'];
            foreach ($_POST as $key => $value) {

                if ($key !== "number" && $stuid !== $_POST["number"]) {
                    $stuid = $_POST['number'];
                }
                $str = "call update_stuinfo('{$stuid}', '{$key}', '{$value}')";
                $sql->Run($str);
                //echo '<br>', $str;
            }
           header("location:teacher.php");
            break;
        case "course";
            $courseID = $_POST['oldID'];
            foreach ($_POST as $key => $value)// foreach 特性，key是获取数组键值，也就是表头，value就是里面的结果，foreach本身就可以把表的元素拆分成一个个
            {   if($key !=="courseNum" && $courseID !== $_POST['courseNum']){
                    $courseID = $_POST['courseNum'];
            }
                $str = "call update_course('{$courseID}','{$key}','{$value}')";
                $sql->Run($str);
                header("location:stucourse.php");
                echo'<br> ',$str;
            }
            break;
//        case "search";
//            $info = $_POST['ser'];
//            $str = "select * from stuinfo where name = '$info'";
//            $sql->Run($str);
//            function printTable($arr, $head): void
//            {
//                $i = 1;
//                foreach ($arr as $row) {
//                    echo "<tr><td>{$i}</td>";
//                    $i++;
//                    foreach ($head as $col)
//                    {
//                        echo "<td id='{$col}'>{$row[$col]}</td>";
//                    }
//                    echo "<td><a href='javascript:edit()' class='edit'>修改  </a><a href='javascript:doDel({$row['number']})')>  删除</a></td></tr>";
//                }
//                echo '</tbody></table>';
//            }
//            break;
    }
}
