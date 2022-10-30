<?php

$studentID = $_POST['studentID'];
$studentname = $_POST['$studentname'];
$studentclass = $_POST['studentclass'];
$phone = $_POST['phone'];
echo '<p>确认添加学生信息:</p>';
echo '您添加的学生ID是' . $studentID;
echo '<br>';
echo '学生姓名是' . $studentname;
echo '<br>';
echo '班级为' . $studentclass;
echo '<br>';
echo '联系电话是 ' . $phone;
echo '<br>';
?>