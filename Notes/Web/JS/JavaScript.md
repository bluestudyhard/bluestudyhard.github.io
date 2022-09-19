## 基本语句

### 输出 执行语句从上到下

输出数据：

- 使用 `window.alert()` 弹出警告框。刷新一次网页就弹一次
- 使用 `document.write()` 方法将内容写到 HTML 文档中。
- 使用 `innerHTML` 写入到 HTML 元素。
- 使用 `console.log()` 写入到浏览器的控制台。

## 数据类型

```js {.line-numbers}
let length = 16; // Number 通过数字字面量赋值
let points = x \* 10; // Number 通过表达式字面量赋值
let lastName = "Johnson"; // String 通过字符串字面量赋值
let cars = ["Saab", "Volvo", "BMW"]; // Array 通过数组字面量赋值
let person = {firstName:"John", lastName:"Doe"}; // Object 通过对象字面量赋值
```

## js 引用

- js 可以引用外部 script 标签，外部标签内部不可修改，一般放在网页设计底部以便加载完网页加载
- 也可以在标签里通过属性引入，不过不方便维护
  ```html {.line-numbers}
  <button onclick="alert('点一下捏一下wyt的脸');">点我</button>
  ```
