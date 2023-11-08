function foo () {
  function bar () {
    console.log(this) // 取决于调用方式，跟调用位置无关
  }

  return bar
}

let fn = foo()
let obj = { name: 'obj', fn: foo() }

fn() // window / Global
obj.fn() // obj  隐式调用

