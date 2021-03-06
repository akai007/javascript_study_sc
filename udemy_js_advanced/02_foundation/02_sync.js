//fill array with 60000 elements
const list = new Array(60000).join('1.1').split('.');
 
function removeItemsFromList() {
    var item = list.pop();
    console.log(list)
    if (item) {
        setTimeout(() => { // ** avoid stack overflow
            removeItemsFromList();
        })
    }
};
 
removeItemsFromList();