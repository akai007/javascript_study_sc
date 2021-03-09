/** */


function callMe() {
    const callMe = 'Hi! I am  Akai~'

    setTimeout(() => {
        console.log(callMe, notCallMe);
    }, 6666);

    const notCallMe = 'Bye!'
}

callMe()