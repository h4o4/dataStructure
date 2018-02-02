function BST(thisroot = null) {
    this.root = thisroot
    this.left = null
    this.right = null
}

BST.prototype.insert = function (value) {
    if (this.root) {
        if (this.root < value) {
            if (this.right) {
                this.right.insert(value)
            } else {
                this.right = new BST(value)
            }
        } else {
            if (this.left) {
                this.left.insert(value)
            } else {
                this.left = new BST(value)
            }
        }
    } else {
        this.root = value
    }
}

BST.prototype.preorder = function () {
    var preorder_list = []
    preorder_list.push(this.root)
    if (this.left) {
        this.left.preorder().forEach(function (item) { preorder_list.push(item) })
    }
    if (this.right) {
        this.right.preorder().forEach(function (item) { preorder_list.push(item) })
    }
    return preorder_list
}

BST.prototype.inorder = function () {
    var inorder_list = []
    if (this.left) {
        this.left.inorder().forEach(function (item) { inorder_list.push(item) })
    }
    inorder_list.push(this.root)
    if (this.right) {
        this.right.inorder().forEach(function (item) { inorder_list.push(item) })
    }
    return inorder_list
}

BST.prototype.postorder = function () {
    var postorder_list = []
    if (this.left) {
        this.left.postorder().forEach(function (item) { postorder_list.push(item) })
    }
    if (this.right) {
        this.right.postorder().forEach(function (item) { postorder_list.push(item) })
    }
    postorder_list.push(this.root)
    return postorder_list
}

var tree = new BST()
var list = [2, 6, 4, 9, 3, 7, 5, 10, 1000, 27, 82, 36]
for (i of list) {
    tree.insert(i)
}
console.log(tree.preorder())
console.log(tree.inorder())
console.log(tree.postorder())