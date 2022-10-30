let url = "https://fanyi-api.baidu.com/api/trans/vip/translate?";
const xhr = new XMLHttpRequest();
const appid = "20221028001422420";
const key = "bsyZYm3NFJLCQWjPwsKE";
let salt = new Date().getTime();
let btn = document.querySelector("button");
let result = document.querySelector(".result-content");
let from = "en";
let to = "zh";
// Unicode汉字范围 19968-40869
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
  console.log(url);
  //   xhr.open("GET", url);
  //   xhr.setRequestHeader("Access-Control-Allow-Origin", "*");
  //   xhr.send();

  //   xhr.onreadystatechange = () => {
  //     if (xhr.readyState === 4) {
  //       if (xhr.status >= 200 && xhr.status < 300) {
  //         let res = JSON.parse(xhr.responseText);
  //         console.log(res);
  //       }
  //     }
  //   };
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
