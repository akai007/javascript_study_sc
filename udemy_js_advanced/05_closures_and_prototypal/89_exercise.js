// How would you be able to create your own .bind() method using call or apply.


const Soraka = {
    health: 100,
    heal: function (num1, num2) {
        this.health = this.health + 10 + (num1 || 0) + (num2 || 0)
    },
};

const Bard = {
    health: 80
};

const Sylas = {
    health: 20,
};

const bardHeal = Soraka.heal.bind(Bard, 1, 2);
console.log(Bard.health);
bardHeal(1, 2);
console.log(Bard.health);

Function.prototype.bind = function (whoIsCallingMe) {
    const self = this;
    return function() {
        return self.call(whoIsCallingMe, ...arguments);
    }
};

const bardHeal2 = Soraka.heal.bind(Bard, 10, 20);
bardHeal2();
console.log(Bard.health);

