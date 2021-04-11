let dragon = {
  name: 'Taya',
  fight() {
    return 5;
  },
  sing() {
    console.log('sing');
    return `I am ${this.name}, the breather of fire`;
  }
}

let lizard = {
  name: 'Kiki',
  fight() {
    return 0;
  }
}

const singLizard = dragon.sing.bind(lizard);
console.log(singLizard());

lizard.__proto__ = dragon; // in browser
console.log(lizard.sing());