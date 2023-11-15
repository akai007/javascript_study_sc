

function foo() {
  console.log(this.a);
}

console.log("// default binding");
var a = 2;

foo(); // 严格模式下为 undefined

console.log("\n// 隐式绑定");
var obj = { a: 3, foo: foo };

obj.foo();

console.log("\n// 隐式绑定-链式调用");
var objBox = { a: 1, obj: obj };
objBox.obj.foo();

console.log("\n// 丢失绑定对象-1");
var fooMissing1 = obj.foo;
fooMissing1();

console.log("\n// 丢失绑定对象-2-1");
function fooMissing2(fn) { fn() }
fooMissing2(obj.foo);
// console.log("\n// 丢失绑定对象-2-2");
// setTimeout(obj.foo);



console.log("\n// 显示绑定-call");
foo.call(obj);

console.log("\n// 显示绑定-apply");
foo.apply(obj);

console.log("\n// 显示绑定-bind");
var fooBind = foo.bind(obj);
fooBind();

console.log("\n// new绑定")
function newFoo(a) {
  this.a = a;
}
var newBar = new newFoo(2);
console.log(newBar.a);

