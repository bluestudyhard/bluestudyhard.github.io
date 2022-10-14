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
  circle_li[i].style.backgroundPosition = "0-" + index + "px"; //没逗号的
}
/*
仿网购网站的输入框，失去焦点和获取焦点的一些变化
 */
let focus = document.querySelector(".missfoucus input");
let f_value = focus.value;
focus.onfocus = function () {
  if (this.value === f_value) {
    focus.value = "";
    focus.style.color = "#111";
  }
};
focus.onblur = function () {
  if (focus.value === "")
    (focus.value = f_value), (focus.style.color = "#3333");
  else return;
};

/*修改样式  */
let texxt = document.querySelector(".texxt");
texxt.onclick = function () {
  this.className = "texxt change";
};

/*密码输入框，文字警示实例 */
let changefoucus = document.querySelector(".changefoucus input");
let changefoucus_text = document.querySelector(".changefoucus span");
changefoucus.onblur = function () {
  let len = changefoucus.value.length;
  if (len < 6 || len > 12) changefoucus_text.className = "changefoucusAf";
  else changefoucus_text.className = "changefoucusbf";
};

/*
 排他思想实例 
  
*/
let buttons = document.querySelectorAll(".changefoucus button");
for (let i = 0; i < buttons.length; i++) {
  buttons[i].onclick = function () {
    for (let i = 0; i < buttons.length; i++) {
      buttons[i].style.backgroundColor = ""; //每一个循环首先清空颜色
    }
    buttons[i].style.backgroundColor = "pink";
  };
}

//全选框
let firstcheck = document.querySelector(".firstcheck");
let chooseall = document.querySelectorAll(".changetable input");
console.log(chooseall);
flag = 0;
firstcheck.onclick = function () {
  if (flag == 0) {
    for (let i = 0; i < chooseall.length; i++) {
      chooseall[i].checked = true;
    }
    flag = 1;
  } else {
    for (let i = 0; i < chooseall.length; i++) {
      chooseall[i].checked = false;
    }
    flag = 0;
  }
};

/*节点操作
 */
//nodeType 元素节点 1，文本节点3 document对象 9 nodeType 用于获取节点类型
// nodeName tagName 可以用来读取dom节点
// Node.data 获取文本节点的内容
// hidden 设置为true时 = display:none;
let elm = document.body;
console.log(elm.nodeType); //1
console.log(elm.firstChild); //是在其中的#text文本
console.log(elm.firstChild.nodeType); //3
console.log(elm.firstChild.data); //1

let gg = document.getElementsByTagName("tr");
console.log(gg);

let div = document.querySelector("#first div");
div.innerHTML = "wytsigiblue";

/**
 获取自定义属性
 getAttribute()
 setAttribute("属性","值")
 removeAttribute()
 */
let div1 = document.querySelector("div");
console.log(div1.getAttribute("id")); //first
div1.setAttribute("class", "111");
console.log(div1); //class 变成了111
console.log(div1.dataset); // index: "2"time: "3"[[Prototype]]: DOMStringMap
console.log(div1.dataset.time); //3
console.log(div1.dataset.moneyStatic);
// Tab 切换栏
let TabUl = document.querySelectorAll(".tabtop li");
let TabSpan = document.querySelectorAll(".content");
for (let i = 0; i < TabUl.length; i++) {
  let index = TabUl[i].getAttribute("index");
  TabUl[i].onclick = function () {
    for (let i = 0; i < TabUl.length; i++) {
      TabSpan[i].style.display = "none";
    }
    TabSpan[index].style.display = "block";
  };
}

/**
 
节点操作
parentNode 离元素节点最近的父级节点即亲爹
childNodes 所有儿子包括文本节点
children 只返回子元素节点 其余节点不返回 只读属性
firstchild 第一个子节点 包括文本节点
lastchild 最后一个子节点 包括文本节点
firstElementChild 第一个元素节点
lastElementChild 最后一个元素节点 IE9以上支持
最好还是用下标访问吧 不用考虑兼容性 children[0];
nextElementSibling 下一个元素节点
previousElementSibling 上一个元素节点
nextSibling 下一个节点
previousSibling 上一个节点
 */
let first = document.querySelector("#first");
console.log(h1.parentNode); //body

console.log(btn.parentNode); // <div id="first">
// const Nodes = document.body.childNodes; 可以用这种方式来获取整个html文件的所有元素
// for (let i = 0; i < Nodes.length; i++) {
//   console.log(Nodes[i]);
// }
console.log(first.childNodes); //17个子元素,包括文本节点 可以用for循环遍历
console.log(first.children); // 8个子元素不包括文本节点

console.log(first.children[0]); //一样可以直接访问 一般都这样来访问节点元素

console.log(first.firstChild, first.lastChild); //这样获得的是包括文本的第一个节点，所以一般得到的是#text

console.log(first.firstElementChild, first.lastElementChild);

console.log(first.nextElementSibling); //下一个元素节点
console.log(first.previousElementSibling); //上一个元素节点

let divv = document.createElement("div");

console.log(divv);

/**
 节点插入方法 
 .append()在node末尾插入节点或字符串
  .prepend() 开头插入节点或字符串
  before 前面插入
  after 后面
  replacewith 将node替换为给定节点或字符串
 */
let newnode = document.querySelector(".node");
let li = document.querySelector(".node li"); //第一个li
divv.className = "newnode";
divv.innerHTML = "append"; //这是一个新节点
newnode.append(divv); // 在这个节点的末尾插入

newnode.before("最前面插入字符串");
newnode.after("最后面插入字符串");
let li1 = document.createElement("li");
li1.innerHTML = "替换掉原本的li";
li.replaceWith(li1);
newnode.prepend("prepend"); // 在这个节点的开头插入

newnode.insertAdjacentHTML("beforebegin", "<p>插入在节点前</p>");
newnode.insertAdjacentHTML("afterbegin", "<p>插入开头</p>");
newnode.insertAdjacentHTML("afterend", "<p>插入最后</p>");
newnode.insertAdjacentHTML("beforeend", "<p>插入结尾</p>");

let remoevenode = document.querySelectorAll(".node");

/**
 * 手动清空方法
 */
//newnode.remove();直接删除头节点就完事了
function clear(elem) {
  for (let i = 0; i < elem.length; i++) {
    elem[i].remove();
  }
}
// clear(remoevenode);

let outsidea = document.querySelectorAll(".node a");

outsidea.forEach((elm) => {
  let sa = elm.getAttribute("href");
  if (sa.includes("://")) elm.style.color = "orange";
});
// let sa = outsidea[i].getAttribute("href");

// if (sa.includes("://")) {
//   outsidea[i].style.color = "orange";
// }

let student = [
  { name: "blue", subject: "js", score: 100 },
  { name: "blue1", subject: "js1", score: 1010 },
  { name: "blue2", subject: "js2", score: 1002 },
];

let tablenode = document.querySelector(".nodetable tbody");

student.forEach((ele) => {
  const tr = document.createElement("tr");
  let td = "";
  for (const value of Object.values(ele)) {
    td += `<td>${value}</td>`;
  }
  tr.innerHTML = td;
  tablenode.appendChild(tr);
});

/**
 * 重写数组方法
 *
 */

let array1 = [1, 2, 3, 4, 5];
let array2 = [array1, array1]; //数组套数组
let array3 = [
  { name: "blue", age: "18" },
  { name: "fish", age: "18" },
  { name: "sheep", age: "18" },
];

array1.forEach((elm) => console.log(elm));

array1.forEach((elm, index, arr) => console.log(elm, index, arr));

array2.forEach((elm, index, arr) => console.log(elm, index, arr));

array3.forEach((elm) => {
  for (let value in elm) console.log(value + ":" + elm[value]);
});

array3.forEach((elm) => {
  for (let value of Object.values(elm)) console.log(value);
});

/**
 * 事件监听 目的是为了给一个事件分配多个处理程序
 * addEventListener(event, handler[, options]) 为事件分配处理程序
 * event 事件
 * handler 处理程序
 * options 
 * once：如果为 true，那么会在被触发后自动删除监听器。
capture：事件处理的阶段，我们稍后将在 冒泡和捕获 一章中介绍。由于历史原因，options 也可以是 false/true，它与 {capture: false/true} 相同。
passive：如果为 true，那么处理程序将不会调用 preventDefault()，我们稍后将在 浏览器默认行为 一章中介绍。

 * removeEventListener(event, handler[, options]) 移除处理程序 
 * 
 * 移除处理程序我们需要传入与分配的函数完全相同的函数
 * btnns[0].removeEventListener("click", () => alert("listen!")); 这样并不会移除处理程序
 * 一定要和传入分配的函数，内容都要一样的才行，所以如果要删除事件，建议先先好函数，不要用箭头函数
 */

let btnns = document.querySelectorAll(".listener button");

btnns[0].addEventListener("click", () => alert("listen!"));
// btnns[0].removeEventListener("click", () => alert("listen!"));
function handler() {
  alert("listenTwice");
}
btnns[0].addEventListener("click", handler); //会在第一个事件响应以后再次响应。
//btnns[0].removeEventListener("click", handler); //成功移除
btnns[0].onclick = () => alert("click event");
btnns[1].addEventListener("click", () => (btnns[1].style.display = "none"));

//有些事件无法通过 DOM 属性进行分配。只能使用 addEventListener。
// 例如，DOMContentLoaded 事件，该事件在文档加载完成并且 DOM 构建完成时触发。

/**
 * 事件对象
 * event.type 事件类型
 * event.currentTarget 处理事件的元素 相当于this
 * event.clientX,Y 返回鼠标指针的水平坐标(根据客户端区域，即当前窗口) 而且只在那个设置了事件的区域 比如说我设置了button，那我在button的不同区域点击，会返回不同的坐标
 */

//事件发生时，浏览器会创建一个event对象

btnns[2].onclick = function (event) {
  alert(event.type + " " + event.currentTarget); //  click [object HTMLButtonElement]
  alert(event.clientX + ":" + event.clientY); //相对点击位置一直在变
};

/**
 * 冒泡事件 捕获事件
 * event.stopPropagation()
 * 捕获路线 document -> html -> body -> father ->target
 */
const body = document.querySelector("body");
let father = document.querySelector(".father");
let son = document.querySelector(".son");
let taget = document.querySelector(".target");
/**
 * 冒泡
 * 阻止冒泡
 * event.stopImmediatePropagation()
 * event.stopPropagation() 停止向上移动
 */
son.addEventListener("click", function (ele) {
  alert("son");
  ele.stopPropagation(); //不会在继续冒泡
}); //点击son father 先弹出son 随后father也会弹出
father.addEventListener("click", () => alert("father"));

//body.addEventListener("click", () => alert("还会往上冒泡"));

/**
 * 捕获
 */

// son.addEventListener("click", function () {
//   alert("son", true); // capture:true;
// }); //点击son father 先弹出father 随后弹出son
// father.addEventListener("click", () => alert("father"), true);
//console.log(document.querySelectorAll("*"));
// document.querySelectorAll("*")获取的是所有的元素节点

// for (let ele of document.querySelectorAll("*")) {
//   ele.addEventListener(
//     "click",
//     () => console.log(`capture:${ele.tagName}`),
//     true
//   );
//   ele.addEventListener("click", () => console.log(`bubble:${ele.tagName}`));
// }
