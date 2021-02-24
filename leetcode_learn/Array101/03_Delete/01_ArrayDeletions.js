/**
 * delete base operation
 */

 // Declare an integer array of 10 elements.
 let intArray = new Array(10)

 // The array currently contains 0 elements.
 length = 0;
 console.log(length);

 // Add elements at the first 6 indexes of the Array.
 for ( let i = 0; i < 6; i++ ) {
   intArray[length] = i;
   length++;
 }

 console.log('Array before delete:', intArray);
 // delete one 
 intArray.length = --length;

 console.log('after before delete:', intArray);