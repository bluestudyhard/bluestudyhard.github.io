<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/Template.css">
    <link rel="stylesheet" href="css/css1.css">
    <link rel="stylesheet" href="css/myproject.css">
    <script type="text/javascript" src="js/js1.js"> </script>
    <title>myfirstweb</title>
</head>

</style>

<body style="text-align: center;">
    <div>
        <h1 id="H1">BlueShouldStudy</h1>
    </div>
    <form action="mysql/add.php?action=search" method="post">
        <input type="search" placeholder="Search" name="searchok" />
        <button type="submit" value="onserach" >
            <span class="fontawesome-search"></span>
        </button>
    </form>
    <form action="try.html" method="post">
        <input type="text" placeholder="Search" name="searchok" />
        <input type="submit" value="onserach" >
            <span class="fontawesome-search"></span>
    </form>
    <div>
        <p id="polist"><strong>导航页</strong></p>
        
        <div class="divolist">
            <ol id="olist">
                <li><a href="#">啦啦啦</a></li>
                <li><a href="#">这里是横向列表</a></li>
                <li><a href="#">温温是笨蛋</a></li>
                <li><a href="#">导航到温温</a></li>
                <li><a href="#">噜噜噜</a></li>
                <li><a href="#">对称</a></li>
                <li><a href="#">噜噜噜</a></li>
            </ol>
        </div>
        <button onclick="alert('点一下捏一下wyt的脸');">
            点我
        </button>
        <div id="first">
        </div>
        <div id="second">
            
        </div>
    </div>
    <script>
        console.log("hello word");
        //window.alert("my first js");
        document.getElementById("first").innerHTML = "改改";
        document.getElementById("second").innerHTML = "改改吗";
        document.write(5 * 6);
        console.log("lulululu");

        function rename(a, b) {
            return a * b;
        }
        var x;
        x = 5;
    </script>
</body>