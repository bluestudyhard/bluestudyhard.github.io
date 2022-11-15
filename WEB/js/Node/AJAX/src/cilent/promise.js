// promise 是一个对象
//有三个状态 pending（待定）
// fulfilled（已执行）
// rejected（已拒绝）

/**
 * 然后 resolve 和 rejected 可以让 状态进入fufilled 和 rejected。
 */

/**
 *
 */
const promise = new Promise((resolve, reject) => {
  // setTimeout(() => {
  //   resolve("已执行回调");
  // }, 3000);
  let n = 1;
  let response = "如果resolve"; // 只能执行一次resolve
  n++;
  resolve(response + n); // 执行完成就调用resolve
  let refuese = "被reject了";
  reject(refuese);
});

// then对象表示，再调用一次promise then就是一个新的promise。可以利用then不断的链式调用promise

console.log(promise);
let p = promise.then();
console.log(p); // 还是一个promise 实例

// 每一次then调用相当于是在使用一个新的promise对象，自带executor函数，这个函数有两个参数，resolve reject 将由我们自己来定义resolve 和reject的内容。
// 只能调用一次resolve 和 reject
/**
 * promise 类内自带两个构造器 state 和 result state表示是完成了还是被拒绝了，然后result就返回成功的value和失败的error信息
 */
promise.then((res) => console.log("生成一个猪"));
promise.then((res, rej) => {
  console.log("养猪");
});
// 我们可以预先设置好我们要的promise成功返回的值，然后再用then调用就好了。
// promise.then((res, rej) => {
//   console.log(res);
// });
// let err = new Promise((res, rej) => {
//   let rejected = "拒绝链接";

//   setTimeout(() => {
//     rej(new Error(rejected));
//   }, 1000);
// });
//promise.catch(null, (error) => alert(error));
// 每一个then里面的参数，都可以各自作为一个函数使用。
// err.then(
//   (result) => alert(result),
//   (error) => alert(error)
// );
// promise 链式调用 为了解决回调地狱问题,其实和递归一样
// 传递给new promise的

// new Promise(function (resolve, rej) {
//   setTimeout(() => resolve(1), 1000);
// })
//   .then((result) => {
//     console.log(result); //1
//     return result * 2;
//   })
//   .then((result) => {
//     console.log(result); //2
//     return result * 2;
//   })
//   .then((result) => {
//     console.log(result); //4
//     return result * 2;
//   })
//   .then((res) => {
//     alert(res);
//   });

// fetch(url,methods) 函数包括url和操作方法
// fetch的基本用法，基于promise then 获取了以后就一直then then获取响应信息

// fetch(
//   "https://api.github.com/repos/javascript-tutorial/en.javascript.info/commits"
// )
//   .then((response) => response.json())
//   .then((res) => {
//     console.log(res);
//   });

// arrayBuffer
let imgurl =
  "https://yandex.com/images/search?text=k%20on&family=yes&pos=2&img_url=http%3A%2F%2Fkonachan.net%2Fsample%2Fe0f58695d569b4a450048ae472bf68e0%2FKonachan.com%2520-%252052755%2520sample.jpg&rpt=simage&lr=109371";
const headers = "Access-Control-Allow-Origin";
/**
 * fetch 通过async 封装一个函数
 */
async function getData() {
  try {
    let res = await fetch(imgurl, {
      mode: "cors",
      
    });
    console.log(res);
    console.log(res.json());
    console.log(res.arrayBuffer);
    console.log(res.blob);
  } catch (err) {
    console.log(err);
  }
}
getData();
