function loop() {
  for(var i = 0; i < 5; i++) {
    console.log(i)
  }
  console.log(`finall i: ${i}`);
  for(let j = 0; j < 5; j++) {
    console.log(j)
  }
  // console.log(`finall j: ${j}`); // j is not defined
}

loop()