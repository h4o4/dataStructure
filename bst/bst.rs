use std::cmp::Ordering;

#[derive(Debug)]
struct Tree<T> {
    node: Option<T>,
    leftchild: Option<Box<Tree<T>>>,
    rightchild: Option<Box<Tree<T>>>,
}

impl<T: Ord> Tree<T> {
    fn new() -> Self {
        Tree {
            node: None,
            leftchild: None,
            rightchild: None,
        }
    }

    fn insert(&mut self, key: T) -> bool {
        if self.node.is_none() {
            self.node = Some(key);
            return true;
        }
        match self.node.as_ref().unwrap().cmp(&key) {
            Ordering::Greater => {
                match self.leftchild {
                    Some(ref mut x) => x.insert(key),
                    None => {
                        self.leftchild = Some(Box::new(Tree {
                            node: Some(key),
                            leftchild: None,
                            rightchild: None,
                        }));
                        true
                    },
                }
            },
            Ordering::Less => {
                match self.rightchild {
                    Some(ref mut x) => x.insert(key),
                    None => {
                        self.rightchild = Some(Box::new(Tree {
                            node: Some(key),
                            leftchild: None,
                            rightchild: None,
                        }));
                        true
                    },
                }
            },
            Ordering::Equal => false,
        }
    }

    fn find(&self, key: &T) -> bool {
        if let Ordering::Equal = self.node.as_ref().unwrap().cmp(key) {
            return true;
        }
        if let Some(ref x) = self.leftchild {
            if x.find(key) {
                return true;
            }
        }
        if let Some(ref x) = self.rightchild {
            if x.find(key) {
                return true;
            }
        }
        false
    }

    fn preorder(&self) -> Vec<&T> {
        let mut preorder_list: Vec<&T> = vec![];
        preorder_list.push(self.node.as_ref().unwrap());
        if self.leftchild.is_some() {
            let tmp = self.leftchild.as_ref().unwrap().preorder();
            for item in tmp {
                preorder_list.push(item);
            }
        }
        if self.rightchild.is_some() {
            let tmp = self.rightchild.as_ref().unwrap().preorder();
            for item in tmp {
                preorder_list.push(item);
            }
        }
        preorder_list
    }

    fn inorder(&self) -> Vec<&T> {
        let mut inorder_list: Vec<&T> = vec![];
        if self.leftchild.is_some() {
            let tmp = self.leftchild.as_ref().unwrap().inorder();
            for item in tmp {
                inorder_list.push(item);
            }
        }
        inorder_list.push(self.node.as_ref().unwrap());
        if self.rightchild.is_some() {
            let tmp = self.rightchild.as_ref().unwrap().inorder();
            for item in tmp {
                inorder_list.push(item);
            }
        }
        inorder_list
    }

    fn postorder(&self) -> Vec<&T> {
        let mut postorder_list: Vec<&T> = vec![];
        if self.leftchild.is_some() {
            let tmp = self.leftchild.as_ref().unwrap().postorder();
            for item in tmp {
                postorder_list.push(item);
            }
        }
        if self.rightchild.is_some() {
            let tmp = self.rightchild.as_ref().unwrap().postorder();
            for item in tmp {
                postorder_list.push(item);
            }
        }
        postorder_list.push(self.node.as_ref().unwrap());
        postorder_list
    }
}

// fn main() {
//         let mut root = Tree::<i32>::new();
//         let data = vec![5, 6, 10, 2, 9, 1, 4, 0, 3];
//         for v in data {
//             root.insert(v);
//         }

//         println!("\nPreorder");
//         for v in root.preorder() {
//             print!("{:?} ", v);
//         };

//         println!("\nInorder");
//         for v in root.inorder() {
//             print!("{} ", v);
//         };

//         // println!("Postorder");
//         // for v in root.postorder() {
//         //     println!("{}", v);
//         // };
//     }
