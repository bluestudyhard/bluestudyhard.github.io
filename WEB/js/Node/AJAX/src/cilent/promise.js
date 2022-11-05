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
  setTimeout(() => {
    resolve("已执行回调");
  }, 3000);
});

promise.then(console.log("看不懂then"));
promise.then(console.log("看不懂then"));
console.dir(Promise);
