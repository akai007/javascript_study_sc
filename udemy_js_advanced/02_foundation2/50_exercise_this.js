

var a = {
  say() {
    console.log(this);
  }
}
a.say()

var b = {
  say() {
    return function() {console.log(this)};
  }
}
b.say()()

var c = {
  say() {
    return () => {console.log(this)}
  }
}
c.say()()