/**
 * constructor function
 */

class Elf{
  constructor(name, weapon) {
    this.name = name;
    this.weapon = weapon;
  }
  attack() {
    return this.name + ' attack with ' + this.weapon;
  }
}

const peter = new Elf('Peter', 'stones');
const sam = new Elf('Sam', 'fire');

console.log( peter.attack() );
console.log( sam.attack() );
