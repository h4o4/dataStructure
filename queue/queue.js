class Queue {
    constructor(first_element=null) {
        this.head = first_element
        this.tail = null
    }

    push(data) {
        if (this.head == null) {
            this.head = data
            return null
        }
        if (this.tail) {
            this.tail.push(data)
        } else {
            this.tail = new Queue(data)
        }
    }

    pop() {
        var temp = this.head
        if (this.tail) {
            this.head = this.tail.head
            this.tail = this.tail.tail
        } else {
            this.head = null
        }
        return temp
    }
}

var a = new Queue()
a.push(1)
a.push(2)
console.log(a.pop())
console.log(a.pop())
console.log(a.pop())