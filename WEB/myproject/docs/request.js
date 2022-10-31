let url = "https://fanyi-api.baidu.com/api/trans/vip/translate?";
const xhr = new XMLHttpRequest();
const appid = "20221028001422420";
const key = "bsyZYm3NFJLCQWjPwsKE";
let salt = new Date().getTime();
let btn = document.querySelector(".result-btn");
let result = document.querySelector(".result-content");
let textarea = document.querySelector("textarea");
let from = "en";
let to = "zh";
// Unicode汉字范围 19968-40869
textarea.onkeydown = (e) => {
  let code = e.key; // 识别按键的名称 回车是Enter

  if (code === "Enter") {
    let contents = $("#srctext").val(); //用了jquery
    //console.log(contents.charCodeAt(0));
    if (contents.charCodeAt(0) >= 19968 && contents.charCodeAt(0) <= 40869) {
      from = "zh";
      to = "en";
    }
    let str = appid + contents + salt + key;
    let sign = MD5(str);
    let issending = false;
    let url = `https://fanyi-api.baidu.com/api/trans/vip/translate?q=${encodeURIComponent(
      contents
    )}&from=${from}&to=${to}&appid=${appid}&salt=${salt}&sign=${sign}&callback=callback`;
    // 用jsonp的方法向api请求
    result.innerHTML = "";
    let script = document.createElement("script");
    script.src = url;
    console.log(script);
    document.body.append(script);
    issending = true;
    script.remove();
    // console.log(contents);
  }
};

btn.onclick = function () {
  let contents = $("#srctext").val(); //用了jquery
  console.log(contents.charCodeAt(0));
  if (contents.charCodeAt(0) >= 19968 && contents.charCodeAt(0) <= 40869) {
    from = "zh";
    to = "en";
  }
  let str = appid + contents + salt + key;
  let sign = MD5(str);
  let issending = false;
  let url = `https://fanyi-api.baidu.com/api/trans/vip/translate?q=${encodeURIComponent(
    contents
  )}&from=${from}&to=${to}&appid=${appid}&salt=${salt}&sign=${sign}&callback=callback`;
  // 用jsonp的方法向api请求
  result.innerHTML = "";
  let script = document.createElement("script");
  script.src = url;
  console.log(script);
  document.body.append(script);
  issending = true;
  script.remove();
  // console.log(contents);
};
function callback(data) {
  data.trans_result.forEach((element) => {
    result.innerHTML += element.dst;
  });
}
