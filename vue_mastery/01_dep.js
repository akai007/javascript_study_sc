/* example:
var vm = new Vue({
  el: '#app',
  data: {
    price: 5,
    quatity: 2
  },
  computed: {
    totalPriceWithTax() {
      return this.price * this.quatity * 1.03
    }
  }
})
*/
const targetMap = new WeakMap()

function track(target, key) {
  let depsMap = targetMap.get(target)
  if (!depsMap) {
    targetMap.set(target, (depsMap = new Map()))
  }

  let dep = depsMap.get(key)
  if (!dep) {
    depsMap.set(key, (dep = new Set()))
  }
  dep.add(effect)
}

function trigger(target, key) {
  let depsMap = targetMap.get(target)
  if (!depsMap) return

  let dep = depsMap.get(key)
  if (dep) {
    dep.forEach(effect => {effect()})
  }
}

let price = 5
let quantity = 2

let product = {
  price: 5,
  quantity: 2,
}

let total = 0

let effect = () => { total = product.price * product.quantity }

track(product, 'quantity')
effect()
console.log( total)

product.quantity = 3
trigger(product, 'quantity')

console.log( total)


