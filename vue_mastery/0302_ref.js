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
let activeEffect = null

function track(target, key) {
  if (activeEffect) {
    let depsMap = targetMap.get(target)
    if (!depsMap) {
      targetMap.set(target, (depsMap = new Map()))
    }
  
    let dep = depsMap.get(key)
    if (!dep) {
      depsMap.set(key, (dep = new Set()))
    }
    dep.add(activeEffect)
  }
}

function trigger(target, key) {
  let depsMap = targetMap.get(target)
  if (!depsMap) return

  let dep = depsMap.get(key)
  if (dep) {
    dep.forEach(eff => {eff()})
  }
}

function reactive(target) {
  const handler = {
    get(target, key, receiver) {
      let result = Reflect.get(target, key, receiver)
      track(target, key)
      return result
    },
    set(target, key, value, receiver) {
      let oldValue = target[key]
      let result = Reflect.set(target, key, value, receiver)
      if (oldValue != result) {
        trigger(target, key)
      }
      return result
    }
  }
  return new Proxy(target, handler)
}

function ref(raw) {
  const r = {
    get value() {
      track(r, 'value')
      return raw
    },
    set value(newVal) {
      if (newVal == raw) return
      raw = newVal
      trigger(r, 'value')
    }
  }
  return r
}

function effect(eff) {
  activeEffect = eff
  activeEffect()
  activeEffect = null
}

let price = 5
let quantity = 2

let product = reactive({
  price: 5,
  quantity: 2,
})

let total = 0
let salePrice = ref(0)

effect(() => {
  total = salePrice.value * product.quantity
})
effect(() => {
  salePrice.value = product.price * 0.9
})

console.log(total)

product.quantity = 3
console.log(total, salePrice.value)

product.price = 20
console.log(total, salePrice.value)


