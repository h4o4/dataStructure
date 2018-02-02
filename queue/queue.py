class Queue:
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
            self.tail = Queue(data)

    def pop(self):
        temp = self.head
        if self.tail:
            self.head = self.tail.head
            self.tail = self.tail.tail
        else:
            self.head = None
        return temp

a = Queue()
a.push(1)
a.push(2)
print(a.pop())
print(a.pop())
print(a.pop())
