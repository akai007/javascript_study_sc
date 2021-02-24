// Inserting at the End of an Array

// Declare an integer array of 6 elements
const intArray = new Array(6);
let length = 0;

// printArray
function printArray() {
  for (let i = 0; i < intArray.length; i++) {
    console.log(`Index ${i} contains ${intArray[i]}`);
  }
  console.log();
}

console.log('Insert to end');
for (let i = 0; i < 3; i++) {
  intArray[length] = i;
  length++;
}
printArray();

console.log('Inserting at the End of an Array');
intArray[length] = 10;
length++;
printArray();


console.log('Inserting at the Start of an Array');
for (let i = 3; i >= 0; i--) {
  intArray[i + 1] = intArray[i];
}
intArray[0] = 20;
printArray();



