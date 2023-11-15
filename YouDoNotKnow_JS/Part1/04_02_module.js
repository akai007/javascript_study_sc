function CoolModule() {
  var somthing = 'cool';
  var another = [1, 2, 3];

  function doSomething() {
    console.log( somthing );
  }

  function doAnother() {
    console.log( another.join(" ! "))
  }

  return {
    doSomething: doSomething,
    doAnother: doAnother
  }
}

var foo = CoolModule();

foo.doSomething();
foo.doAnother();