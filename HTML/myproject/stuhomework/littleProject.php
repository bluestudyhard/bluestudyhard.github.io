<?php
session_start();//当下边有include时
//include("mysql/sql.sql");
$passord = $checked = $uid = "";


if (isset($_POST["username"])) {
    $username = trim($_POST["username"]);
    $password = trim($_POST["password"]);
    $email    = trim($_POST["email"]);
    if (isset($_POST['checked']))
        $checked = trim($_POST['checked']);

    $sql = new SQL();
    $str = "select `username`, `password`, `power` from `users` where `username` = '$username'";
    $sql->Run($str);
    if (!empty($sql->arr)) {
        $user = $sql->arr[0];//将二维数组的第一个赋值给user
        // print_r($user);
        if ($user['password'] === $password) {
            $_SESSION = [
                'username' => $username,
                'logged'   => true,
                'power'    => $user['power']
            ];

            if ($checked === 'on')
                setcookie('username', $username, time() + 3600 * 24 * 365);
            else
                setcookie('username', $username);

            if ($_SESSION['power'] == 'private') {
                header('location:login.html');
            } else {
                header('location:littleProject.php');
            }
        }
    }
    echo "<script>alert('密码或账号错误')</script>";
    header("Refresh:0");
}
?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edg e">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Form Validator</title>
    <link rel="stylesheet" href="style/login.css">
</head>

<body>
<div class="index">
    <div class="login-box">
        <div class="left-picture">
            <div class="pic-header">
                学生成绩管理系统
            </div>
        </div>
        <div class="formm">
            <div class="header"><span>用户登录</span></div>
            <div class="login-input">
                <form method="post">
                    <label>
                        <div class="name">Username</div>
                        <input class="input" type="text" name="username" placeholder="Enter username">
                    </label>
                    <label>
                        <div class="name">Email</div>
                        <input class="input" type="email" name="email" placeholder="Enter email"/>
                    </label>
                    <label>
                        <div class="name">Password</div>
                        <input class="input" type="password" name="password" placeholder="Enter password" id="input">
                    </label>
                    <label>
                        <div class="checkbox">
                            <input class="checkbox" type="checkbox" name="checked" title="记住我"/>
                            <span class="remember">不是本地电脑不要勾选</span>
                        </div>
                    </label>
                    <div class="btn">
                        <button type="submit" class="submit">Submit</button>
                    </div>
                </form>
            </div>
        </div>
        <div class="footer">
            <span>Copyright 2022 Stupid Sheep&&Blue Studyhard, All Rights Reserved.</span>
            <span>联系邮箱：stupidsheep5268@qq.com</span>

        </div>
    </div>
    <script>
        const form = document.querySelector('form');


        function check() {


            return true;
        }

        form.onsubmit = () => {
            if (check()) {
                form.action = 'littleProject.php';
                form.submit();
            }
            return false;
        }
    </script>
</div>

</body>

</html>