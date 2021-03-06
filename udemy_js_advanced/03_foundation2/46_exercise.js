/** part 1 */


const a = function() {
    console.log('a', this)
    const b = function() {
        console.log('b', this)
        const c = {
            hi: function() {
                console.log('c', this)
            }
        }
        c.hi()
    }
    b()
}
a()


/** part 2 */

const obj = {
    name: 'akai',
    sing() {
        console.log('sing'. this)
        var self = this
        const innerSing = function () {
            console.log('self', self)
            console.log('innerSing', this)
        }
        const innerSingRap = () => {
            console.log('innerSingRap', this)
        }
        innerSing()
        innerSingRap()
        return innerSing.bind(this)()
    }
}
obj.sing()