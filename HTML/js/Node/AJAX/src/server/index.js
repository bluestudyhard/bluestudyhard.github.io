const express = require("express");

const app = express(); //express 对象

/**
 * 路由定义
 * app.get() 创建了一个回调函数
 * 第一个参数 请求根路径 若传 "/" url为 根目录 /xx 就是url的xxx
 * 第二个参数是一个函数 (request,response)
 */
app.get("/aj", (request, response) => {
  //设置响应头 设置允许跨域
  response.setHeader("Access-Control-Allow-Origin", "*");
  //设置响应体
  response.send("hello ajax");
});

app.post("/aj", (req, response) => {
  response.setHeader("Access-Control-Allow-Origin", "*");
  // 响应信息
  response.send("post ajax");
});

app.listen(8000, () => {
  console.log("http://localhost:8000/aj");
  console.log("服务已启动，8000 端口监听中");
});
