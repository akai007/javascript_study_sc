/**
 * constructor function
 */

function Elf(name, weapon) {
  this.name = name;
  this.weapon = weapon;
}

Elf.prototype.attack = function (){
  return this.name + ' attack with ' + this.weapon;
};

const peter = new Elf('Peter', 'stones');
const sam = new Elf('Sam', 'fire');

console.log( peter.attack() );
console.log( sam.attack() );
