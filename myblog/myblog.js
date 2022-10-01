let buttons = document.querySelectorAll(".changeimg button ");
let body = document.querySelector("body");
console.log(buttons);
for (let i = 0; i < buttons.length; i++) {
  if (i == 0) {
    buttons[i].onclick = function () {
      body.style.backgroundImage = "url('myblog/imgg/mugi1.png')"; //相对于HTML的路径来说
    };
  } else if (i == 1) {
    buttons[i].onclick = function () {
      body.style.backgroundImage = "url('myblog/imgg/yuyi1.jpg')";
    };
  } else if (i == 2) {
    buttons[i].onclick = function () {
      body.style.backgroundImage = "url('myblog/imgg/miao1.jpg')";
    };
  } else if (i == 3) {
    buttons[i].onclick = function () {
      body.style.backgroundImage = "url('myblog/imgg/mio1.png')";
    };
  } else {
    buttons[i].onclick = function () {
      body.style.backgroundImage = "url('myblog/imgg/lizi2.png')";
    };
  }
}
