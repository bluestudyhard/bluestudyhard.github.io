const buttons = document.querySelectorAll(".changeimg button ");
const body = document.querySelector("body");
console.log(buttons);
/*
重构后
差点忘了 ``这玩意的用法
` ` 里面套字符串${elemt} 可以赋值字符串 然后用`` 也不用担心双引号单引号的转义问题
 */
let imglist = ["mugi1.png", "yuyi1.jpg", "miao1.jpg", "mio1.png", "lizi2.png"];
buttons.forEach((elm, index) => {
  elm.onclick = function () {
    body.style.backgroundImage = `url('imgg/${imglist[index]}'`;
  };
});
