var obj = {
  id: "123",
  cool: function collFn() {
    console.log(this.id);
  }
}

var id = "456"
obj.cool()

setTimeout(obj.cool, 100) // 在浏览器中 会改变this 输出456

setTimeout(() => obj.cool(), 100)
