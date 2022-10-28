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

// let xhr1 = new XMLHttpRequest();
// xhr1.open("POST", "http://localhost:8000/aj", true);

// let input1 = document.querySelector("input").value;
// let btn2 = document.querySelector(".btn2");
// let content = document.querySelector(".content");
// let input2 = document.querySelector(".secondinput");
// let btn3 = document.querySelector(".secondsubmit");
// //请求体
// // let rd = { name: "blue", sex: 1 };
// // xhr1.send(rd);
// xhr1.setRequestHeader("content-type", "application/x-www-form-urlencoded");
// xhr1.setRequestHeader("name", "blue");

// btn2.onclick = () => {
//   xhr1.onreadystatechange = function () {
//     if (xhr1.readyState === 4) {
//       if ((xhr1.status >= 200 && xhr1.status < 300) || xhr.status == 304) {
//         content.innerHTML = xhr1.response;
//         console.log(xhr1.response);
//       }
//     }
//   };
// };

let move = document.querySelector(".move");

move.addEventListener("click", () => {
  const xhr1 = new XMLHttpRequest();
  // open 和 send 一定要在响应函数的外面，然后要先open再send
  xhr1.open("POST", "http://localhost:8000/aj", true);
  xhr1.responseType = "json"; // 固定的接受json响应 但是指定了这个只能接受json
  //xhr1.setRequestHeader("content-type", "text/html; charset=utf-8");
  //xhr1.setRequestHeader("name", "blue");
  xhr1.send();
  xhr1.onreadystatechange = () => {
    if (xhr1.readyState === 4) {
      if (xhr1.status >= 200 && xhr1.status < 300) {
        move.innerHTML = xhr1.response.name;
      }
    }
  };
});

let btn2 = document.querySelector(".secondsubmit");
let secondinput = document.querySelector(".secondinput");
btn2.onclick = () => {
  let xhr = new XMLHttpRequest();
  xhr.open("GET", "http://localhost:8000/delay");
  // 设置响应延迟
  xhr.timeout = 2000;
  xhr.ontimeout = () => {
    alert("请求超时,请稍后重试");
  };
  // 网络异常回调
  xhr.onerror = () => {
    alert("你的网络出现了一些问题");
  };
  xhr.send();
  xhr.onreadystatechange = () => {
    if (xhr.readyState === 4) {
      if (xhr.status >= 200 && xhr.status < 300) {
        secondinput.value = xhr.response;
      }
    }
  };
};
