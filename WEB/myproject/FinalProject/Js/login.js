//              --- 联系方式
let email_btn = document.querySelector('.email');
email_btn.addEventListener("click", function () {
    let sec = document.querySelector(".email-content").classList.toggle('email-emerge');
    email_btn.textContent = (sec) ? "作者信息" : "收起";
    console.log("hellow");
});
//              --- 焦点测试是否有输入账号

let flag1 = false;
let flag2 = false;
let submitOff = document.querySelector(".submit1");
let input1 = document.querySelector('#username');
let user_tip = function () {
    input1.classList.add('invalid');
    input1.value = "请输入学号或教工号!";
}
input1.onblur = function () {
    if (input1.value === "") {
        flag1 = false;
        user_tip();
        if (!submitOff.hasAttribute("disabled"))
            submitOff.setAttribute("disabled", "disabled");
    } else {
        flag1 = true;
        if (flag1 && flag2 && submitOff.hasAttribute("disabled"))
            submitOff.removeAttribute("disabled");
    }
};
input1.onfocus = function () {
    if (this.classList.contains('invalid')) {
        this.classList.remove("invalid");
        input1.value = "";
    }
}
//          ---因为input2的type=password中数据无法显示，需要改为type=text
let input2 = document.querySelector('#password');
let psw_tip = function () {
    input2.classList.add('invalid');
    input2.value = "请输入密码!";
    input2.removeAttribute("type");
    input2.setAttribute("type", "text");
}

input2.onblur = function () {
    if (input2.value === "") {
        flag2 = false;
        psw_tip();
        if (!submitOff.hasAttribute('disabled'))
            submitOff.setAttribute("disabled", "disabled");
    } else {
        flag2 = true;
        if (flag1 && flag2 && submitOff.hasAttribute('disabled'))
            submitOff.removeAttribute('disabled');
    }

}
input2.onfocus = function () {
    if (this.classList.contains('invalid')) {
        this.classList.remove("invalid");
        input2.removeAttribute("type");
        input2.setAttribute("type", "password");
        input2.value = "";
    }
}

//              ---拦截有输入的密码，验证格式
let former = document.querySelector("form");
let user_check1 = false;
let psw_check1 = false;
let check = function () {
    let username = document.querySelector("#username").value;
    let password = document.querySelector("#password").value;
    // --- 方法一:密码在js处理，用于统一使用一个密码
    // const psw_check = (password === "blueSheep");
    // //因为调用了check时为已经输入了账号密码，所以需要一个全局变量让他能够传”密码正确“这个信息出去
    // psw_check1 = psw_check;
    if (password.length >= 8 && password.length <= 16) {
        let f1 = false, f2 = false;
        for (let i = 0; i < password.length; ++i) {
            if (password[i] >= 'a' && password[i] <= 'z' || password[i] >= 'A' && password[i] <= 'Z')
                f1 = true;
            if (password[i] >= '0' && password[i] <= '9')
                f2 = true;
        }
        if (f1 && f2)
            psw_check1 = true;
    }

    if (username.length === 10) {
        for (let i = 0; i < username.length; ++i) {
            if (username[i] < '0' || username[i] > '9') {
                user_check1 = false;
                return false;
            }
        }
        user_check1 = true;
        return psw_check1;
    } else if (username === "teacher") {
        user_check1 = true;
        return psw_check1;
    } else {
        user_check1 = false;
        return false;
    }

}
//          ---有输入，点击提交表单后对数据进行检查格式
document.querySelector(".submit1").addEventListener("click", function () {

    if (check() === true) {
        let form_check = document.querySelector("form").hasAttribute("onsubmit");
        if (form_check) {
            document.querySelector("form").removeAttribute("onsubmit");
        }
        former.action = 'login.php';
        former.onsubmit();
    } else {
        document.querySelector('form').setAttribute("onsubmit", "return false");
        let str1 = "";
        let str2 = "";
        if (user_check1 === false) {
            document.querySelector(".user_comment_user_sup").classList.add("showRed");
            document.querySelector(".user_comment_user").classList.add("showRed");
            str1 = "error: 账号输入格式错误";
            console.log("hello");
        } else {

            if (document.querySelector(".user_comment_user_sup").classList.contains("showRed")) {
                document.querySelector(".user_comment_user_sup").classList.remove("showRed");
                document.querySelector(".user_comment_user").classList.remove("showRed");
            }
        }

        if (psw_check1 === false) {
            document.querySelector(".user_comment_psw_sup").classList.add("showRed");
            document.querySelector(".user_comment_psw").classList.add("showRed");
            str2 = "error: 密码输入格式错误";
        } else {
            if (document.querySelector(".user_comment_psw_sup").classList.contains("showRed")) {
                document.querySelector(".user_comment_psw_sup").classList.remove("showRed");
                document.querySelector(".user_comment_psw").classList.remove("showRed");
            }

        }
        alert(str1 + "\n" + str2);
    }


})
//          ---在input中检测到按下回车，则点击submit按钮
document.querySelector("input").addEventListener("keydown", function (event) {
    if (event.key === "Enter") {
        document.querySelector(".submit1").click();
    }
})