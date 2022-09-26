console.log(document.body);
//console.log(document.head);
// childNotes 获取所有的子节点
const Nodes = document.body.childNodes;
for (let i = 0; i < Nodes.length; i++) {
  //console.log(Nodes[i]);
}
// getElementById 返回的是元素对象
let ele = document.getElementById("first");
console.log("1.", ele);
console.log(typeof ele); //object
console.dir(ele); //#id   返回的是对象的属性 所有属性和属性值

//document.getElementsByTagName() 会搜索整个文件结构，包括根节点，然后会动态的改变，保持和dom树的一致，他是从第一个父节元素开始往下递归的在DOM树中搜索符合条件的元素
// 不可以直接用为定义的节点来使用这个函数  console.log(ul.getElementsByTagName("li"));//undefined
let lis = document.getElementsByTagName("ul"); //伪数组存储
console.log(lis); //HTMLCOlletion(2) [ul ul]
for (let i = 0; i < lis.length; i++) {
  console.log(lis[i]);
}
//document.getElementsByClassName 获取class
let getclass = document.getElementsByClassName("box");
console.log(getclass);

// 其实H5以后选择器都用 querySelector了 获取的是第一个元素。用法就是根据元素直接获取就行 比如id 就#id class就.class

let time = document.querySelector(".box");
console.log(time);
console.log(document.querySelector("#first"));
console.log(document.querySelector("ul")); //只会获取第一个ul

//事件源 事件触发的对象 在这里是按钮
let btn = document.querySelector(".btn");
//事件类型 如何触发，触发什么事件
// 事件处理程序 通过一个函数赋值的方式完成
btn.onclick = function () {
  alert("这是一个按钮");
};

let clm = document.querySelector(".clikcmove");
clm.innerHTML = "<strong>今天是个好日子</strong>"; //可以直接获取,改变html的元素,可加标签
//console.log(clm.innerHTML);
let ul = document.querySelector("ul");
console.log(ul.innerText); //会去掉html的标签

let btn1 = document.querySelector(".btn1");
let btn2 = document.querySelector(".btn2");
let img = document.querySelector(".img1");

btn1.onclick = function () {
  img.src = "../img/02.png";
};
btn2.onclick = function () {
  img.src = "../img/01.png";
};
/*自定义时间改变图片*/
let img2 = document.querySelector(".img2");
let date = new Date();
let hours = date.getHours();
let h1 = document.querySelector("h1");

function changeimg() {
  if (hours >= 6 && hours <= 12)
    (img2.src = "../img/01.png"), (h1.innerHTML = " GOOD MORNING MASTER ");
  else if (hours > 12 && hours <= 18)
    (img2.src = "../img/01.png"), (h1.innerHTML = " GOOD Afternoon KING ");
  else img2.src = "../img/back.png";
}
changeimg();

let btn3 = document.querySelector(".btn3");
let input = document.querySelector("input");
btn3.onclick = function () {
  input.value = "点击咯";
  this.disabled = true; //禁用点击，点击了一次以后就不能点击了
};

let img3 = document.querySelector(".img3");
let input1 = document.querySelector(".input1");
let flag = 0;
img3.onclick = function () {
  if (flag == 0) {
    img3.src = "../img/open.png";
    input1.type = "text";
    flag = 1;
  } else {
    img3.src = "../img/closed.png";
    input1.type = "password";
    flag = 0;
  }
};
/*
点击更改颜色
*/
let changecolour = document.querySelector(".changecolour");
changecolour.onclick = function () {
  if (flag == 0) {
    this.style.backgroundColor = "blue";
    this.style.width = "80px";
    this.style.height = "80px";
    flag = 1;
  } else {
    this.style.backgroundColor = "red";
    this.style.width = "100px";
    this.style.height = "100px";
    flag = 0;
  }
};

/*点击隐藏图片 */
let imgclose = document.querySelector(".changestyle i");
let img4 = document.querySelector(".changestyle img");
imgclose.onclick = function () {
  img4.style.display = "none";
};

let circle_li = document.querySelectorAll(".circle_imge li");
console.log(circle_li);

for (let i = 0; i < circle_li.length; i++) {
  let index = i * 44;
  circle_li[i].style.backgroundPosition = "0-"+index+"px";//没逗号的 
  
}
