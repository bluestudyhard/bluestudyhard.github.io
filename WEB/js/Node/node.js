const express = require("express");

const app = express();

app.get("/", (request, response) => {
  response.send("hello");
  console.log(request);
});

app.listen(8000, () => {
  console.log("服务已启动，8000 端口监听中");
});
