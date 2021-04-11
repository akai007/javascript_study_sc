/**
 * 4 way of this
 */

// first
function Person(name, age) {
  this.name = name;
  this.age = age;
}

const person1 = new Person('Meng', 19);
console.log('1', person1);

const person2 = {
  name: 'Akai',
  age: 20,
  hi: function() {
    console.log('2: hi', this.setTimeout);
  }.bind(global || window)
}
person2.hi();


const person3 = {
  name: 'Liao',
  age: 10,
  hi: function() {
    console.log('3: hi, my last name is ' + this.name);
  }
}
person3.hi();

const person4 = {
  name: 'Kai',
  age: 10,
  hi: function() {
    return () => {
      console.log('4: hi, my first name is ' + this.name);
    }
  }
}
person4.hi()();