let obj = {a: 2};

obj2 = Object.create(obj);

console.log(obj2, obj2.a, 'a' in obj2);

for (o in obj2) {
  console.log('obj2 has: ', o)
}
