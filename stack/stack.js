class Stack {
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
            this.tail = new Stack(data)
        }
    }

    pop() {
        var temp
        if (this.tail) {
            if (this.tail.tail) {
                return this.tail.pop()
            }
            else {
                temp = this.tail.head
                this.tail = null
                return temp
            }
        }
        else {
            temp = this.head
            this.head = null
            return temp
        }
    }
}

var stack = new Stack()
stack.push(1)
stack.push(2)
console.log(stack.pop())
console.log(stack.pop())
console.log(stack.pop())