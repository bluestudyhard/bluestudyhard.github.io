//https://cn.bing.com/search?q=ssss

let ser = document.querySelector(".serachbody");
let form = document.querySelector("form");
const body = document.querySelector("body");
ser.onfocus = () => {
  ser.className = "change-search";
  ser.style.transition = "all 1s";
  // body.style.backgroundSize = 150 + "%";
  body.className = "body-after";
};

ser.onblur = () => {
  ser.className = "serachbody";
  body.className = "body";
};

// form.action = "https://cn.bing.com/search?q=" + ser.value;
// console.log(form.action);
//form.action = `https://www.baidu.com/s?wd=ss${ser.value}`;
