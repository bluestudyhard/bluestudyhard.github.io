[toc]

## js 基础

### 输出 执行语句从上到下

输出数据：

- 使用 `window.alert()` 弹出警告框。刷新一次网页就弹一次
- 使用 `document.write()` 方法将内容写到 HTML 文档中。
- 使用 `innerHTML` 写入到 HTML 元素。
- 使用 `console.log()` 写入到浏览器的控制台。

### 数据类型

- number — 可以是浮点数，也可以是整数，
- bigint — 用于任意长度的整数，
- string — 字符串类型，
  字符串中包含变量的方法 用反引号 `${}`
  ```js {.line-numbers}
  let n = 233;
  let Str = ` 反引号 ${n} `;
  console.log(Str);
  ```
- boolean — 逻辑值：true/false，
- null — 具有单个值 null 的类型，表示“空”或“不存在”，
- undefined — 具有单个值 undefined 的类型，表示“未分配（未定义）”，
- **object 和 symbol**

```js {.line-numbers}
let length = 16; // Number 通过数字字面量赋值
let points = x \* 10; // Number 通过表达式字面量赋值
let lastName = "Johnson"; // String 通过字符串字面量赋值
let cars = ["Saab", "Volvo", "BMW"]; // Array 通过数组字面量赋值
let person = {firstName:"John", lastName:"Doe"}; // Object 通过对象字面量赋值
```

JSON

### js 引用

- js 可以引用外部 script 标签，外部标签内部不可修改，一般放在网页设计底部以便加载完网页加载
- 也可以在标签里通过属性引入，不过不方便维护
  ```html {.line-numbers}
  <button onclick="alert('点一下捏一下wyt的脸');">点我</button>
  ```

### 作用域

### 箭头函数

使用箭头函数的目的就是为了方便省事，尤其是对于简单的单行行为来说。
除了方便以外，它还有很多有用的特性

- **初级**
  创建函数有一个简单的方式用箭头函数来创建

```js {.line-numbers}
let func = (a1, a2) => expression;
/*等价于*/
let func = function (a1, a2) {
  return expression;
};
/*实例*/
let sum = (a, b) => a + b;
```

- **几种用法**

- 如果只有一个参数，还可以直接省略圆括号

  ```js {.line-numbers}
  let double = (n) => n * 2;
  ```

- 也可以像函数表达式一样使用

  ```js {.line-numbers}
  let age = () => console.log("aaa");
  ```

- 多行的箭头函数
  有时我们需要更复杂一点的函数，比如带有多行的表达式或语句。在这种情况下，我们可以使用花括号将它们括起来。主要区别在于，用花括号括起来之后，需要包含 return 才能返回值（就像常规函数一样）。

```js {.line-numbers}
let sum = (a, b) => {
  let result = a + b;
  return result;
};
/*无参数*/
let point = () => {
  if (1) console.log("111");
  else console.log("000");
};
```

**高级使用**
JavaScript 充满了我们需要编写在其他地方执行的小函数的情况。
例如：

- arr.forEach(func) —— forEach 对每个数组元素都执行 func。
- setTimeout(func) —— func 由内建调度器执行。

**箭头函数没有“this”**
比如

```js {.line-numbers}
let group = {
  students: ["blue", "fish", "sheep"],
  school: "hzxy",
  show() {
    this.students.forEach((student) =>
      console.log(this.school + ":" + student)
    );
  },
};
group.show();
```

如果我们使用正常的函数，则会出现错误：

```js {.line-numbers}
this.students.forEach((function(student){
      console.log(this.school + ":" + student)
    });
```

因为在这里 this 没有指向谁，所以是默认的 undefined

### 运算符

比较重要的**"+"** 运算符
**+string 可以实现字符串转数字**
string + int = "string";
例

```js {.line-numbers}
console.log("2333" + 4); // 23334
let s = prompt("123", "1");
console.log(typeof +s); //number
```

### 循环

- 全局作用域，局部作用域，块级作用域

## 对象

### 对象的创建

- js 的对象，可以理解为 map，字典这样的东西，里面可以套函数，键值，也可以套对象

```js {.line-numbers}
/*套对象，套key*/
let Object = {
  key: "键值",
  myfunction: function name(params) {},
};
/*对象里的对象*/
let coverObj = {
  objj: { myname: 1, myage: 19 },
};
console.log(coverObj.objj.myage);
```

### 对象方法 this

**this 的值指的就是当前对象也就是.前面的对象** 即调用这个方法的对象
比如

```js {.line-numbers}
let user = {
  name: "John",
  age: 30,
  sayHi() {
    // "this" 指的是“当前的对象”
    alert(this.name);
  }
kk.onclick = function(){
  this.xxx = xx;//this指的是kk
}
```

在 JavaScript 中，this 关键字与其他大多数编程语言中的不同。JavaScript 中的 this 可以用于任何函数，即使它不是对象的方法。
在调用不同的对象时，他有着不同的"this"的值
**在没有对象时，this==undefined**

```js {.line-numbers}
function aaa() {
  console.log(this); //undefined
}
```

### 遍历对象方法

- **for in**
  一般都是用 for in 方法，for of 可以遍历对象但是没那么方便
  **value 指的是对象的键 key** obj[key] = value;

```js {.line-numbers}
let obj = { name: "blue", age: 18 };
for (let value in obj) {
  console.log(value); //name age
  console.log(obj[value]); // blue 18
}
```

- **for..of**

```js {.line-numbers}
let obj = { name: "blue", age: 18 };
for (let value of Object.values(value)) {
  console.log(value);
}
```

### 内置对象

#### 数组

- **array.push()** 数组末尾添加一个或者多个元素 数组长度+1
- **Array.pop();** 删除最后一个
- **Array.shift();** 删除第一个
- unshift 数组开头加一个，相当于 pushfont 完成后返回的是新数组的长度
- sort(), reverse() 属于是懂得都懂了 但是 sort 原型只能实现个位数
- **sort 实现自定义排序**
  arry.sort(function (a, b) {
  return a - b; //升序
  });

- indexof() latindexof()

**遍历数组方法**
**forEach();**
array.forEach((currentValue,index,arr),thisValue)
**currentValue 必选，一般用 elm，element。当前元素**
index 当前元素的下标
arr 当前元素的所属的数组对象
**常用箭头函数调用内部的 function**
例

```js {.line-numbers}
let array1 = [1, 2, 3, 4, 5];
array1.forEach(function (elem) {
  console.log(elem); //1 2 3 4 5
});
// 和下面这个是等价的
array1.forEach((elem) => {
  console.log(elem); //1 2 3 4 5
});
```

**forEach 带其他参数**

```js {.line-numbers}
let array2 = [array1, array1];
array2.forEach((elm, index, arr) => console.log(elm, index, arr));
// [1,2,3,4,5] 0 [Array(5),Array(5)] 指的是数组套数组里的那个数组
array1.forEach((elm, index, arr) => console.log(elm, index, arr)); // 1 0 [1,2,3,4,5]
```

**利用 foreach 和 for..in 遍历数组里的对象**

```js {.line-numbers}
let array3 = [
  { name: "blue", age: "18" },
  { name: "fish", age: "18" },
  { name: "sheep", age: "18" },
];
array3.forEach(elm=>for (value in elm) {
   {
      console.log(value);
  }
})
```

#### String

#### Date

#### Math

## DOM

### 概述

- DOM 全称文档对象模型，是一个标准编程接口（api） 利用 DOM 可以改变网页的样式，内容，结构

### DOM 树

### DOM 节点类

DOM 节点的层次结构如下图
![img](./imgg/domnode.png)

- EventTarget 是一切根的抽象类，作为一个基础让所有的节点都支持事件类
- Node 也是抽象类，然后他提供了树的核心功能
  parentNode,nextSibling 等
  children —— 仅那些作为元素节点的子代的节点。
  childNodes
  firstElementChild，lastElementChild —— 第一个和最后一个子元素。
  previousElementSibling，nextElementSibling —— 兄弟元素。
  parentElement —— 父元素。
- Document 被 HTMLDocument 继承，指的是整个 HTML 的整个文档，document 继承自这个类

- **Element 是 Dom 元素的基础类。**
  它提供了元素及导航 如**nextElementSibling,children,以及 getElementsByTagName,和 querySelector**

- 最后，HTMLElement —— 是所有 HTML 元素的基础类。我们大部分时候都会用到它。

它会被更具体的 HTML 元素继承：

HTMLInputElement —— input 元素的类，
HTMLBodyElement —— body 元素的类，
HTMLAnchorElement —— a 元素的类，

### 节点方法

- **parentNode** 离元素节点最近的父级节点即亲爹
- **childNodes** 所有儿子包括文本节点
- **children** 只返回子元素节点 其余节点不返回 只读属性
- **firstchild** 第一个子节点 包括文本节点
- **lastchild** 最后一个子节点 包括文本节点
- **firstElementChild** 第一个元素节点
- **lastElementChild** 最后一个元素节点 IE9 以上支持
- 最好还是用下标访问吧 不用考虑兼容性 children[0];
- **nextElementSibling** 下一个元素节点
- **previousElementSibling** 上一个元素节点
- **nextSibling** 下一个节点
- **previousSibling** 上一个节点

#### 创建方法

- **document.createElement(tag)** 创建一个新的元素节点
- **document.createTextNode(text)** 用给定的文本创建一个 文本节点：

#### 插入/删除/克隆方法

这些插入方法改变的只有 dom 元素而不是原本的 html 的内容

- **document.createElement(tag)**—— 用给定的标签创建一个元素节点，
- **document.createTextNode(value)** —— 创建一个文本节点（很少使用），
- **elem.cloneNode(deep)** —— 克隆元素，如果 deep==true 则与其后代一起克隆。

- **node.append**(...nodes or strings) —— 在 node 末尾 插入节点或字符串，
- **node.prepend**(...nodes or strings) —— 在 node 开头 插入节点或字符串，
- **node.before**(...nodes or strings) —— 在 node 前面 插入节点或字符串，
- **node.after**(...nodes or strings) —— 在 node 后面 插入节点或字符串，
- **node.replaceWith**(...nodes or strings) —— 将 node 替换为给定的节点或字符串。
- **node.remove()** 删除节点
  **所有插入方法都会自动从旧位置删除该节点。**
  elem.remove(); 删除头结点会直接全部删除
- **node.cloneNode** 克隆节点

- **旧の方法**

parent.appendChild(node)
parent.insertBefore(node, nextSibling)
parent.removeChild(node)
parent.replaceChild(newElem, node)

```js {.line-numbers}
<html>
  <ol class="node">
    <li>1</li>
    <li>2</li>
    <li>3</li>
  </ol>
</html>;

let newnode = document.querySelector(".node");
let li = document.querySelector(".node li"); //第一个li divv.className = "newnode";
divv.innerHTML = "append";
newnode.prepend("prepend"); // 在这个节点的开头插入
newnode.append(divv);
newnode.before("前面插入字符串");
newnode.after("后面插入字符串");
let li1 = document.createElement("li");
li1.innerHTML = "替换掉原本的li";
li.replaceWith(li1);

/*插入结果*/
前面插入字符串;
prepend;
替换掉原本的li;
2;
3;
append;
后面插入字符串;
```

- **insertAdjacentHTML("where",html)** 方法
  该方法的第一个参数是代码字（code word），指定相对于 elem 的插入位置。**必须为以下之一**：

- **"beforebegin"** —— 将 html 插入到 elem 之前，
- **"afterbegin"** —— 将 html 插入到 elem 开头，
- **"beforeend"** —— 将 html 插入到 elem 末尾，
- **"afterend"** —— 将 html 插入到 elem 之后。
  相对于 append before，该方法不会重叠，而是会在其之前/之后新增元素

```js {.line-numbers}

最前面插入字符串
<p>插入在节点前</p>
<ol class="node">
  <p>插入开头</p>
  prepend
  <li>替换掉原本的li</li>
  <li>2</li>
  <li>3</li>
  <div class="newnode">append</div>
  <p>插入结尾</p>
  <p>插入最后</p>
</ol>
最后面插入字符串

newnode.insertAdjacentHTML("beforebegin", "<p>插入在节点前</p>");
newnode.insertAdjacentHTML("afterbegin", "<p>插入开头</p>");
newnode.insertAdjacentHTML("afterend", "<p>插入最后</p>");
newnode.insertAdjacentHTML("beforeend", "<p>插入结尾</p>");
```

### 选择器

- getElementById 根据 id 返回的是元素对象
- document.getElementsByTagName() 会搜索整个文件结构，包括根节点，然后会动态的改变，保持和 dom 树的一致，他是从第一个父节元素开始往下递归的在 DOM 树中搜索符合条件的元素
- document.getElementsByClassName 获取 class
- **其实 H5 以后选择器都用 querySelector 了** 前面的已经成为了时代の眼泪(bushi)
- querySelector 获取的是第一个元素。用法就是根据元素直接获取就行 比如 id 就#id class 就.class
  querySelector 还可以直接像 css 选择器那样获取元素。
  querySelectorAll 获取所有的同类元素
  ` let img4 = document.querySelector(".changstyle img");`

```js {.line-numbers}
let time = document.querySelector(".box");
console.log(time);
console.log(document.querySelector("#first"));
console.log(document.querySelector("ul")); //只会获取第一个ul
```

### 事件

#### 事件流

- 事件由 3 部分组成————事件源，事件类型，事件处理程序。事件三要素
- **操作事件三要素可以分为 1.获取事件源，2.绑定事件，3.添加事件处理程序**

一 . **事件源 事件触发的对象 以按钮为例**

```js {.line-numbers}
<button class="btn"></button>;
let btn = document.querySelector(".btn");
```

二 . **绑定事件**
通过添加事件类型来进行绑定

- ```js {.line-numbers}
  btn.onclick;
  ```

三 . **添加事件处理程序**

- ```js {.line-numbers}
  btn.onclick = function () {
    alert("change");
  };
  ```

#### 事件类型

常用事件类型

鼠标事件

- **onclick** 点击鼠标时触发此事件
- ondblclick 双击鼠标时触发此事件
- onmousedown 按下鼠标时触发此事件
- onmouseup 鼠标按下后又松开时触发此事件
- onmouseover 当鼠标移动到某个元素上方时触发此事件
- onmousemove 移动鼠标时触发此事件
- onmouseout 当鼠标离开某个元素范围时触发此事件
- onkeypress 当按下并松开键盘上的某个键时触发此事件
- onkeydown 当按下键盘上的某个按键时触发此事件
- onkeyup 当放开键盘上的某个按键时触发此事件

键盘事件

onkeydown 某个键盘按键被按下。
onkeypress 某个键盘按键被按下并松开。
onkeyup 某个键盘按键被松开。

表单事件

- **onfocus** 元素获取焦点时触发
- **onblur 元素失去焦点时触发**
  **比如说定位了一个文本框，你点击文本框就是 onfocus 有焦点，点击文本框外部就是失去焦点 onblur**
- onchange 该事件在表单元素的内容改变时触发
- onfocusin 元素即将获取焦点时触发
- onfocusout 元素即将失去焦点时触发
- oninput 元素获取用户输入时触发
- onreset 表单重置时触发
- onsearch 用户向搜索域输入文本时触发
- onselect 用户选取文本时触发
- onsubmit 表单提交时触发

#### 事件处理程序

一.函数处理

二.修改元素

- element.innerHTML
  可以直接获取,改变 html 的元素,可加标签。不能修改表单

  ```js {.line-numbers}
  let clm = document.querySelector(".clikcmove");
  clm.innerHTML = "<strong>今天是个好日子</strong>";
  ```

- src，href,id,alt,title
  直接更改 html 里的 src，href 等标签，然后更换里面的内容

  ```js {.line-numbers}
  let img = document.querySelector(".img1");
  img.src = "../img/02.png";
  ```

- type,value,checked,selected,disabled
  更改表单的方法
  type 更改 input 的类型，比如说，text 改成 password 等
  disable 使用后可以禁用点击

  ```js {.line-numbers}
  let btn3 = document.querySelector(".btn3");
  let input = document.querySelector("input");
  input1.type = "text";
  input1.type = "password";
  btn3.onclick = function () {
    input.value = "点击咯";
    this.disabled = true; //禁用点击，点击了一次以后就不能点击了
  };
  ```

- Element.style Element.className

  直接通过 js 来更改 style 的样式

  ```js {.line-numbers}
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
  ```

  可以用 className 直接改变元素的类名，改变这个是直接覆盖，如果需要保留原来的类名，要用 css 多项选择器

  ```js {.line-numbers}
  let texxt = document.querySelector(".texxt");
  texxt.onclick = function () {
    //this.className = "change";//覆盖了原来的.texxt
    this.className = "texxt change";
  };
  ```

- 不得不提的一个经常用到的算法思想，排他思想
  例 多个按钮，点击了一个值显示对应的内容和颜色

```js {.line-numbers}
let buttons = document.querySelectorAll(".changefoucus button");
for (let i = 0; i < buttons.length; i++) {
  buttons[i].onclick = function () {
    for (let i = 0; i < buttons.length; i++) {
      buttons[i].style.backgroundColor = ""; //每一个循环首先清空颜色
    }
    buttons[i].style.backgroundColor = "pink";
  };
}
```

### DOM 属性

- 特性（attribute）—— 写在 HTML 中的内容。
- 属性（property）—— DOM 对象中的内容。

我们也可以自定义 DOM 属性。
例如，让我们在 document.body 中创建一个新的属性：

```js {.line-numbers}
document.body.myData = {
  name: "Caesar",
  title: "Imperator",
};

alert(document.body.myData.title); // Imperator
```

- 我们也可以直接添加新的方法

```js {.line-numbers}
  document.body.newMethod = function(){
    console.log(this.tagName);
  }
  document.body.
```

#### H5 自定义特性(属性)

- 在 H5 之后可以在元素中添加自定义属性 格式为 data-xxx
  例如

```js {.line-numbers}
<div class="blue" data-index="1">
```

index 属性不是元素本身自带的 class 这样的属性，是我们人为定义的

- getAttribute()
  获取属性
  ```js {.line-numbers}
  div1.getAttribute("data-index");
  ```
- setAttribute("属性","值")
  设置自定义属性
- removeAttribute()
  删除自定义属性或者删除原本的属性
- dataset h5 新增方法
  可以获取整个自定义元素的键值，然后可以直接访问键值得到属性的值

  ```js {.line-numbers}
  <div id="first" class="" data-index="2" data-time="3" data-money-static="2">
  console.log(div1.dataset); //DOMStringMap index: "2", time: "3"
  console.log(div1.dataset.time); //3
  console.log(div1.dataset["time"]);
  ```

  如果要获取的值的名字是多个-命名的 如 data-index-time 这种 通过 dataset 获取需要采用驼峰命名法不需要再打 data 了

  ```js {.line-numbers}
  console.log(div1.dataset.moneyStatic); //2
  ```

**属性的类型**

一般来说 DOM 属性都是字符串类型的
有几个特例

- checked 属性是 bool 型的
- style 特性是字符串类型的 但是 style 属性是一个对象

```js {.line-numbers}
alert(div.style); // [object CSSStyleDeclaration]
alert(div.style.color); // red
```
