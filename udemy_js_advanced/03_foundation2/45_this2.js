
function singRap() {
  console.log('yoyoyo,' + this.name)
}

const obj = {
  name: 'Akai',
  sing: function () {
    console.log('lalala' + this.name)
  },
  singTwice: function() {
    console.log('sing twice');
    this.sing()
    this.sing()
  },
  singRap: singRap
}
const obj2 = {
  name: 'Meng',
  singRap: singRap
}

obj.sing()
obj.singTwice()

obj.singRap()
obj2.singRap()