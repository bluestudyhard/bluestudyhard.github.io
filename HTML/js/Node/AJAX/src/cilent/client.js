let btn = document.querySelector(".btn1");
let result = document.querySelector(".result");
//创建对象
const xhr = new XMLHttpRequest();
// 初始化，设置请求方法和url
xhr.open("GET", "http://localhost:8000/aj", true);

// 发送
xhr.send(); //GET不用内容
xhr.onreadystatechange = function () {
  if (xhr.readyState === 4) {
    if (xhr.status >= 200 && xhr.status < 300) {
      console.log(xhr.status); // 状态码
      console.log(xhr.statusText); //状态字符串
      console.log(xhr.getAllResponseHeaders()); //所有响应头
      console.log(xhr.response); //响应体
      btn.onclick = () => (result.innerHTML = xhr.response);
    }
  }
};

let xhr1 = new XMLHttpRequest();
xhr1.open("POST", "http://localhost:8000/aj", true);

let input1 = document.querySelector("input").value;
let btn2 = document.querySelector(".btn2");
let content = document.querySelector(".content");
//请求体
let requesthead = { name: "blue", sex: 1 };
xhr1.send(requesthead);
xhr1.onreadystatechange = function () {
  if (xhr.readyState === 4) {
    if ((xhr.status >= 200 && xhr.status < 300) || xhr.status == 304) {
      btn2.onclick = () => {
        content.innerHTML = xhr1.response;
        console.log(xhr1.response);
      };
    }
  }
};
