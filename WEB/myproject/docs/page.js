//https://cn.bing.com/search?q=ssss

let ser = document.querySelector(".serachbody");
let form = document.querySelector("form");
const body = document.querySelector("body");

function randomPage() {
  let count = Math.floor(Math.random() * 10) + 1;
  body.style.backgroundImage = `url(page/page${count}.png)`;
}
randomPage();
let date = new Date();
let hours = date.getHours();
if (hours >= 23 || hours <= 6) {
  body.style.backgroundImage = `url(page/page10.png)`;
} else if (hours >= 6 && hours <= 12) {
  body.style.backgroundImage = `url(page/page9.png)`;
}
console.log(hours);
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

/**
 * 切换图片
 */
const btnleft = document.querySelector(".button-left");
const btnright = document.querySelector(".button-right");

function changeImage() {
  let i = 0;
  btnright.onclick = () => {
    if (i == 10 || i > 10) i = 0;
    body.style.backgroundImage = `url(page/page${i}.png)`;
    i++;
  };
  btnleft.onclick = () => {
    if (i < 0) i = 10;
    body.style.backgroundImage = `url(page/page${i}.png)`;
    i--;
  };
}
changeImage();
// form.action = "https://cn.bing.com/search?q=" + ser.value;
// console.log(form.action);
//form.action = `https://www.baidu.com/s?wd=ss${ser.value}`;

let btnts = document.querySelector(".translate");
let translate = document.querySelector(".translatebox");
let isdisplay = false;
btnts.onclick = () => {
  if (!isdisplay) {
    translate.style.display = "none";
    isdisplay = true;
  } else {
    isdisplay = false;
    translate.style.display = "flex";
  }
};
