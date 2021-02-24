const dvdCollection = new Array(15);

class DVD {
  constructor(name, releaseYear, director){
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

dvdCollection[9] = romanHolidayDVD;
dvdCollection[6] = godfatherDVD;
dvdCollection[2] = lionKingDVD;

console.log(dvdCollection);
