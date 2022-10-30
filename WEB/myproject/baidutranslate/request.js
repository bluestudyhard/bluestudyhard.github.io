let url = "https://fanyi-api.baidu.com/api/trans/vip/translate?";
const xhr = new XMLHttpRequest();
const appid = "20221028001422420";
const key = "bsyZYm3NFJLCQWjPwsKE";
let salt = new Date().getTime();
let from = "en";
let to = "zh";
let btn = document.querySelector("button");
let result = document.querySelector(".result");
btn.onclick = function () {
  let contents = $("#srctext").val();
  let str = appid + contents + salt + key;
  let sign = MD5(str);
  let url = `https://fanyi-api.baidu.com/api/trans/vip/translate?q=${encodeURIComponent(
    contents
  )}&from=en&to=zh&appid=${appid}&salt=${salt}&sign=${sign}&callback=callback`;
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

  let script = document.createElement("script");
  script.src = url;
  console.log(script);
  document.body.append(script);
};
function callback(data) {
  alert(data.trans_result.dst);
}
// console.log(contents);
