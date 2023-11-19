
function mixin( sourceObj, targetObj ) {

  for (key in sourceObj) {
    if (!(key in targetObj)) { // 子类重写父类方法 因此不copy
      targetObj[key] = sourceObj[key]
    }
  }

  return targetObj;
}

let animal = {}