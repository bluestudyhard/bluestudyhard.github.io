## node js 简介

### node.js 项目结构。

## express 框架

- **Express 是一个基于 Node 平台的 Web 应用开发框架，它提供了一系列的强大特性，帮助你创建各种 Web 应用。**
- express
- 提供了简洁的路由定义方式
  对获取 http 请求参数进行了简化处理
  对模板引擎支持程度高，方便渲染动态 HTML 页面
  拥有中间件机制有效控制 HTTP 请求
  拥有大量第三方中间件对功能进行扩展
- Express 下载方法
  npm install express

### 用 express 框架搭建一个简单的服务器

- get 的第一个参数是 url "/" 是默认的根目录 如 `192.168.01.1 ` "/aj" 就是`192.168.01.1/aj`
- 第二个参数(request,response);

```js {.line-numbers}
// 引入express框架
const express = require("express");
// 创建网站服务器。
const app = express();
// 中间件接收 GET 和 POST 请求
app.get("/", (request, response) => {
    //设置响应头 设置允许跨域
  response.setHeader("Access-Control-Allow-Origin", "*");
  response.send("hello ajax");
});
app.post("/", (req, res) => {
  res.send("helo POST");
});
app.listen(8080，()={
    //设置响应头 设置允许跨域
  response.setHeader("Access-Control-Allow-Origin", "*");
    console.log("http://localhost:8080");
    console.log("服务启动成功");
});//监听
```
