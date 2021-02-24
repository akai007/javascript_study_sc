const dvdCollection = new Array(15);

class DVD {
  constructor(name, releaseYear, director) {
    this.name = name;
    this.releaseYear = releaseYear;
    this.director = director;
  }
  toString() {
    console.log(this.name);
  }
}

const romanHolidayDVD = new DVD('Roman Holiday', 1953, 'Bernard Vorhaus');
const godfatherDVD = new DVD('The Godfather', 1991, 'Francis Ford Coppola');
const lionKingDVD = new DVD("The Lion King", 2019, "Jon Favreau");

// Writing Items into an Array
dvdCollection[9] = romanHolidayDVD;
dvdCollection[6] = godfatherDVD;
dvdCollection[2] = lionKingDVD;

// Reading Items from an Array
console.log(dvdCollection[2], dvdCollection[6], dvdCollection[9]);
console.log(dvdCollection[10]);

// Writing Items into an Array with a Loop
squareNumbers = new Array(10);
for (let i = 0; i < squareNumbers.length; i++) {
  const square = Math.pow(i + 1, 2);
  squareNumbers[i] = square;
}

// Reading Items from an Array with a Loop
for (let i = 0; i < squareNumbers.length; i++) {
  console.log(squareNumbers[i]);
}