<?php
session_start(); //需要使用session时
include("Data/database.php");
$password = $checked = $uid = $checked = "";


if (isset($_POST["username"])) {
    $username = trim($_POST["username"]);
    $password = trim($_POST["password"]);
    if (isset($_POST['checked']))
        $checked = trim($_POST['checked']);

    $sql = new SQL();
    $str = "select `username`, `password`, `power` from `users` where `username` = '$username'";
    $sql->Run($str);
    if (!empty($sql->arr)) {
        $users = $sql->arr[0]; //将二维数组的第一个赋值给user
        // print_r($user);
        $_SESSION['logged']   = false;
        $_SESSION['power']    = "";
        $_SESSION['username'] = "";
        if ($users['password'] === $password) {
            $_SESSION = [
                'username' => $username,
                'logged'   => true,
                'power'    => $users['power']
            ];
            if ($checked === 'on')
                setcookie('username', $username, time() + 3600 * 24 * 365);
            else
                setcookie('username', $username);
        }
    }
    if ($_SESSION['logged'] === true && $_SESSION['power'] === 'private') { //密码正确传将名字传到学生端
        echo <<<EOT
        <form action='index.php' class='formm' method='POST'>
            <input type='text' name='username' value='{$_SESSION["username"]}'/>
        </form>
        <script>
            document.querySelector('.formm').submit();
         </script>
        EOT;
    } else if ($_SESSION['logged'] === true && $_SESSION['power'] === 'public') {
        header("location:tea/teacher.php");
    }


    echo "<script>alert('密码或账号错误')</script>";
}
?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>学生成绩管理系统</title>
    <link rel="icon" sizes="32X32" href="img/projectLogo.ico">
    <link rel="stylesheet" href="css/login.css">
</head>

<body>
    <div class="index">
        <div class="logo"><img src="img/bluesheep.jpg" alt="logo" width="70" /></div>
        <div class="email-content email-emerge">
            <div class="email-header">作者信息</div>
            <div class="profile1">
                <img class="pic1" src="img/sheepPro.png" alt="sheep" title="Stupidsheep">
                <div class="infor">
                    <div class="major">班级:计算机类3班</div>
                    <div class="maker">姓名:陈洋浩</div>
                    <div class="id">学号:2114100306</div>
                    <div class="qqmail">邮箱:2983626014@qq.com</div>
                </div>
            </div>
            <div class="profile2">
                <img class="pic2" src="img/bluePro.png" alt="blue" title="BlueStudyHard">
                <!--            <div class="pic2"></div>-->
                <div class="infor">
                    <div class="major">班级:计算机类3班</div>
                    <div class="maker">姓名:蓝凯</div>
                    <div class="id">学号:2114100314</div>
                    <div class="qqmail">邮箱:3164752596@qq.com</div>
                </div>
            </div>
        </div>
        <div class="login-box">
            <div class="left-picture">
                <div class="pic-header">
                    <span>学生成绩</span>管理系统
                </div>

                <button class="email">作者信息</button>
            </div>
            <div class="formm">
                <div class="header"><span>用户登录</span></div>
                <div class="login-input">
                    <form method="post">
                        <label>
                            <div class="name">账号:</div>
                            <div></div>
                            <input class="input" type="text" name="username" placeholder="Enter username" id="username" autocomplete="off">
                        </label>
                        <div>
                            <sup class="user_comment_user_sup">*</sup>
                            <div class="user_comment_user">请输入正确的10位学号或教工号</div>
                        </div>
                        <label>
                            <div class="name">密码:</div>
                            <input class="input" type="password" name="password" placeholder="Enter password" id="password" autocomplete="off">
                        </label>
                        <div class="psw_comment">
                            <sup class="user_comment_psw_sup">*</sup>
                            <div class="user_comment_psw">请输入8-16位只包含有数字和字母密码</div>
                        </div>
                        <div class="checked">
                            <label>
                                <input type="checkbox" class="checkbox" name="checked">
                            </label>
                            <span class="remember">记住我</span>
                            <sup>*</sup>
                            <span>若不是本地电脑，不要勾选</span>
                        </div>
                        <div class="btn">
                            <button type="submit" class="submit1  ">提交</button>

                        </div>
                    </form>
                    <div class="formFooter">
                        <a href="https://www.bilibili.com" class="forget" target="_blank">忘记密码</a>
                        <div class="blank"></div>
                        <a href="https://www.bilibili.com" class="makesure" target="_blank">无法验证</a>
                    </div>
                </div>
            </div>
            <div class="footer">
                <span>Copyright 2022 Stupid Sheep&&Blue Studyhard, All Rights Reserved.</span>


            </div>
        </div>
    </div>

</body>
<script type="text/javascript" src="Js/login.js"></script>

</html>