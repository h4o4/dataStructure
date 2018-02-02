class Stack:
    def __init__(self, first_element=None):
        self.head = first_element
        self.tail = None

    def push(self, data):
        if self.head is None:
            self.head = data
            return None
        if self.tail:
            self.tail.push(data)
        else:
            self.tail = Stack(data)

    def pop(self):
        if self.tail:
            if self.tail.tail:
                return self.tail.pop()
            else:
                temp = self.tail.head
                self.tail = None
                return temp
        else:
            temp = self.head
            self.head = None
            return temp


a = Stack()
a.push(1)
a.push(2)
print(a.pop())
print(a.pop())
print(a.head)
