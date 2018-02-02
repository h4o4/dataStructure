import random, time

class BST:
    def __init__(self, first_element=None):
        self.node = first_element
        self.lchild = None
        self.rchild = None

    def insert(self, data):
        if self.node:
            if data > self.node:
                if self.rchild:
                    self.rchild.insert(data)
                else:
                    self.rchild = BST(data)
            else:
                if self.lchild:
                    self.lchild.insert(data)
                else:
                    self.lchild = BST(data)
        else:
            self.node = data

    def preorder(self):
        preorder_list = []
        preorder_list.append(self.node)
        if self.lchild:
            preorder_list.extend(self.lchild.preorder())
        if self.rchild:
            preorder_list.extend(self.rchild.preorder())
        return preorder_list

    def inorder(self):
        inorder_list = []
        if self.lchild:
            inorder_list.extend(self.lchild.inorder())
        inorder_list.append(self.node)            
        if self.rchild:
            inorder_list.extend(self.rchild.inorder())
        return inorder_list

    def postorder(self):
        postorder_list = []
        if self.lchild:
            postorder_list.extend(self.lchild.postorder())
        if self.rchild:
            postorder_list.extend(self.rchild.postorder())
        postorder_list.append(self.node)            
        return postorder_list

a = [random.randint(0, 100) for _ in range(100)]
b = BST()
for i in a:
    b.insert(i)
print(b.preorder())
print(b.inorder())
print(b.postorder())
