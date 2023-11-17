let obj = {a: 2, b: 3};

Object.defineProperty(obj, Symbol.iterator, {
  enumerable: false,
  writable: false,
  configurable: true,
  value: function() {
    let th = this;
    let idx = 0;
    let ks = Object.keys(th);
    return {
      next: function() {
        return {
          value: th[ks[idx++]],
          done: (idx > ks.length)
        }
      }
    }
  }
});

let it = obj[Symbol.iterator]();
console.log(it.next());
console.log(it.next());
console.log(it.next());

for (let o of obj) {
  console.log(o);
}