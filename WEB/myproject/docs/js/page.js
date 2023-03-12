//https://cn.bing.com/search?q=ssss

let ser = document.querySelector(".serachbody");
let form = document.querySelector("form");
const body = document.querySelector("body");
let count = Math.floor(Math.random() * 14) + 1;
function randomPage() {
  body.style.backgroundImage = `url(page/page${count}.webp)`;
}
randomPage();
let date = new Date();
let hours = date.getHours();
if (hours >= 23 || hours <= 6) {
  body.style.backgroundImage = `url(page/page${count}.webp)`;
} else if (hours >= 6 && hours <= 12) {
  body.style.backgroundImage = `url(page/page${count}.webp)`;
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
    if (i == 14 || i > 14) i = 0;
    body.style.backgroundImage = `url(page/page${i}.webp)`;
    i++;
    console.log(i);
  };
  btnleft.onclick = () => {
    if (i < 0) i = 14;
    body.style.backgroundImage = `url(page/page${i}.webp)`;
    i--;
  };
}
changeImage();
// form.action = "https://cn.bing.com/search?q=" + ser.value;
// console.log(form.action);
//form.action = `https://www.baidu.com/s?wd=ss${ser.value}`;

let btnts = document.querySelector(".translate");
let translate = document.querySelector(".translatebox");
let textareas = document.querySelectorAll("textarea");
console.log(textareas);
let isdisplay = false;
btnts.onclick = () => {
  if (!isdisplay) {
    textareas.forEach((e) => {
      e.innerHTML = "";
      e.style.width = "0px";
      e.style.height = "0px";
    });
    textareas[1].style.display = "none";
    isdisplay = true;
  } else {
    isdisplay = false;
    textareas.forEach((e) => {
      e.innerHTML = "";
      e.style.width = "400px";
      e.style.height = "400px";
    });
    textareas[1].style.display = "flex";
  }
};
