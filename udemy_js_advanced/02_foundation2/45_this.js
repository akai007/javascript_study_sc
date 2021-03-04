// 'use strict' // than this will be undefined
console.log(this); // It is Window in browser

function a() {
  console.log(this); // It is Window in browser
}
a()