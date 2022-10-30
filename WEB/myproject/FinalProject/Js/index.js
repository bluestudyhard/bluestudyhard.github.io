//              ---个人信息内的刷新按钮
let refresh = false;

function change() {
    location.reload();
    refresh = true;
}

//              ---成绩表的切换
let box1 = false;
let box2 = false;

//              ---课程与成绩表的切换
function showBox1() {
    let box = document.querySelector(".score-box");
    if (box2 === true) {
        document.querySelector(".classroom-box").classList.toggle("hidBox");
        box2 = false;
    }
    let yes = box.classList.toggle("showBox");
    box1 = !yes;
}

//              ---课程表的切换
function showBox2() {
    let box = document.querySelector(".classroom-box");
    if (box1 === false) {
        document.querySelector(".score-box").classList.toggle("showBox");
        box1 = true;
    }
    let yes = box.classList.toggle("hidBox");
    box2 = !yes;
}

//              ---个人信息显示
document.querySelector(".author").addEventListener("click", function () {
    document.querySelector(".shadow_before").classList.toggle("shadow");
    document.querySelector(".person_info").classList.toggle("showinfo");
})
document.querySelector(".info_return").addEventListener("click", function () {
    document.querySelector(".shadow_before").classList.toggle("shadow");
    document.querySelector(".person_info").classList.toggle("showinfo");

})


//              ---修改个人信息-->两个button
document.querySelector(".change").addEventListener("click", function () {
    let arr = document.querySelectorAll(".per_info span span");
    let btn1 = document.querySelector(".change");
    btn1.classList.toggle("showChange");
    let btn2 = document.querySelector(".set");
    btn2.classList.toggle("showSet");
    let name_arr = ['class', 'name', 'number', 'born', 'sex', 'project'];
    for (let i = 0; i < arr.length; ++i) {
        let input = document.createElement("input");
        input.setAttribute("type", "text");
        input.setAttribute("class", "editt");
        input.setAttribute("name", name_arr[i]);
        input.value = arr[i].innerHTML;
        arr[i].innerHTML = "";
        arr[i].appendChild(input);
        if (i === 2)
            input.setAttribute("readonly", "readonly");

    }
})