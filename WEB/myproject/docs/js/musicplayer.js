const pause = document.querySelector("#pause");
const audio = document.querySelector("audio");
let flag = false;
pause.onclick = () => {
  if (!flag) {
    pause.className = "iconfont1 icon-bofang";
    flag = true;
    audio.play();
  } else {
    pause.className = "iconfont icon-Playerpause";
    flag = false;
    audio.pause();
  }
};
