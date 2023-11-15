var data = [];

for (let i = 0; i < 3; i++) {
  data[i] = function() {
    console.log(i)
  }
}

data[0]();
data[1]();
data[2]();

for (let i = 0; i < 3; i++) {
  var m = i;
  let j = i;
  data[i] = (function(k) {
    return function() {
      console.log(i, j, k, m)
    }
  })(i);
}

data[0]();
data[1]();
data[2]();