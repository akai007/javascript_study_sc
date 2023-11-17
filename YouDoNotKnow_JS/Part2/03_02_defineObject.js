var obj = {
  get a() {
    return 2;
  }
}

Object.defineProperty(obj, "b", {
  get: function() {
    return this.a * 2
  },
  // enumerable: true
});

console.log(obj.a, obj.b);

Object.defineProperty(obj, "c", {
  value: "can not be changed",
  writable: false,
  configurable: true,
  enumerable: true,
})
obj.c = "try to change"
console.log(obj.c)

Object.defineProperty(obj, "d", {
  value: "",
  writable: true,
  configurable: false,
  enumerable: true,
});
delete obj.c;
obj.d = "can not be delected";
delete obj.d;
console.log(obj.c, obj.d);

obj2 = {a: 'a', b: 'b'};
Object.seal(obj2);
obj2.a = "can not be deleted too";
delete obj2.a;
console.log(obj2.a);

obj3 = {a: 'can not be deleted and changed', b: 'b'};
Object.freeze(obj3);
obj3.a = 'try to change';
delete obj3.a;
console.log(obj3.a);

obj4 = {a: 'a'};
Object.preventExtensions(obj4);
obj4.b = 'b';
console.log(obj4.b);