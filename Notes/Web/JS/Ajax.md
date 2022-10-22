## 原生 ajax

### ajax 简介

Ajax(Asynchronous JavaScript and XML)是异步 JavaScript 和 XML

ajax 被设计出来的根本目的就是为了实现不刷新整个网页的情况下实现浏览器局部的交互。
举个例子，我们向服务器发送一个简单的请求，哪怕是更新一个局部的内容，都会使得整个网页刷新。

### XHR

**XHR 的基本实用操作**
const httpRequest = new XMLHttpRequest();
常用方法
**open()(String method,String url,boolean asynch,String username,String password)**

- **open()：该方法创建 http 请求**
  第一个参数是指定提交方式(post、get)
  第二个参数是指定要提交的地址是哪
  第三个参数是指定是异步还是同步(true 表示异步，false 表示同步)
  第四和第五参数在 http 认证的时候会用到。是可选的
- **send(content) 发送请求给服务器**
  如果是 get 方式，并不需要填写参数，或填写 null
  如果是 post 方式，把要提交的参数写上去

- **setRequestHeader(String header,String value)
  setRequestHeader(String header,String value)：设置消息头（使用 post 方式才会使用到，get 方法并不需要调用该方法）**
  getAllResponseHeaders() 获取所有的响应头
  getResponseHeader(String header) 获取响应头
  setRequestHeader()设置响应头
- **onreadystatechange：请求状态改变的事件触发器（readyState 变化时会调用此方法），一般用于指定回调函数**
  **readyState：请求状态 readyState 一改变，回调函数被调用，它有 5 个状态**
  0：未初始化
  1：open 方法成功调用以后
  2：服务器已经应答客户端的请求
  3：交互中。Http 头信息已经接收，响应数据尚未接收。
  4：完成。数据接收完成
- **status 服务器的响应码 如 404 200-300 303 500 等** 表示各种状态。200-300 表示响应成功 404 表示服务器文件获取失败。
- **responseText：服务器返回的文本内容**
- **responseXML：服务器返回的兼容 DOM 的 XML 内容**
- **statusText：服务器返回状态码的文本信息**

**编写一个简单的 ajax 代码**

```js {.line-numbers}
<html>
  <button>111</button>
  <div></div>
</html>;

const xhr = XMLHttpRequest(); // 获取xhr对象

xhr.open("GET", "localhost:8000/aj");

xhr.send();

xhr.onreadystatechange = () => {
  // 表示数据接受完成
  if (xhr.readyState === 4) {
    if (xhr.status >= 200 && xhr.status < 300) {
      let btn = document.querySelector("button");
      btn.onclic = () => {
        div.innerHTML = xhr.response;
      };
    }
  }
};
```

## Axio

### promise
