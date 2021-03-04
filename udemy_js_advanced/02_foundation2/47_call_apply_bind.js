

const Soraka = {
  health: 100,
  heal: function(num1, num2) {
    this.health = this.health + 10 + (num1 || 0) + (num2 || 0)
  }
}

const Bard = {
  health: 80
}

const Sylas = {
  health: 20,
}

console.log('Soraka', Soraka.health)
Soraka.heal()
Soraka.heal.call(Soraka)
console.log('Soraka', Soraka.health)

console.log('Bard', Bard.health)
Soraka.heal.call(Bard)
Soraka.heal.call(Bard, 1, 2)
Soraka.heal.apply(Bard, [3, 4])
console.log('Bard', Bard.health)

console.log('Sylas', Sylas.health)
Soraka.heal.call(Sylas, 1, 2)
sylasHijackHeal = Soraka.heal.bind(Sylas, 100, 100)
sylasHijackHeal()
console.log('Sylas', Sylas.health)