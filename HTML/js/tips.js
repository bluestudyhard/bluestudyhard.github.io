//获取 div 元素的宽度，包含内边距（padding）和边框（border）.offsetWidth
//
let movemouse = document.querySelector(".movemouse");
let moveimg = document.querySelector(".movemouse img");
movemouse.onclick = function (event) {
  let field = this.getBoundingClientRect();
  console.log(field.top); //52
  console.log(field.left); //281
  console.log(event.clientX);

  console.log(moveimg.clientWidth + " " + moveimg.clientHeight);
  console.log(movemouse.clientLeft);
  let left =
    event.clientX - field.left - movemouse.clientLeft - moveimg.clientWidth / 2;
  let top =
    event.clientY - field.top - movemouse.clientTop - moveimg.clientHeight / 2;

  moveimg.style.left = left + "px";
  moveimg.style.top = top + "px";
};
//movemouse.onclick = ""; 移除click事件

let changebuttonli = document.querySelector(".change-list ul");
let buttons = document.querySelectorAll(".change-list button");

changebuttonli.onclick = function (ele) {
  if (ele.target.className != "bbt") {
    return;
  } else {
    let li = ele.target.closest("li");
    li.remove();
  }
};
