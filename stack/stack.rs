// use std::io;

#[derive(Debug)]
struct Stack<T> {
    head: Option<T>,
    tail: Option<Box<Stack<T>>>,
}

impl<T: Copy> Stack<T> {
    fn new() -> Stack<T> {
        Stack {
            head: None,
            tail: None,
        }
    }

    fn push(&mut self, data: T) {
        if self.head.is_none() {
            self.head = Some(data);
            return;
        }
        match self.tail {
            Some(ref mut current_data) => current_data.push(data),
            None => {
                self.tail = Some(Box::new(Stack{
                    head: Some(data),
                    tail: None,
                }));  
            }
        }
    }

    fn pop(&mut self) -> Option<T> {
        let temp;
        match self.tail {
            Some(ref mut stack) => {
                if stack.tail.is_some() {
                    return stack.pop();
                } else {
                    temp = stack.head;
                }
            },
            None => {
                temp = self.head;
                self.head = None;
                return temp;
            },
        }
        self.tail = None;
        return temp;
    }
}

fn main() {
    let mut a = Stack::new();
    let b = vec![1,2,3,4,3,4,7];
    for i in b {
        a.push(i);
    }
    println!("{:?}", a.pop());
    println!("{:?}", a.pop());
    println!("{:?}", a.pop());
    println!("{:?}", a.pop());
    println!("{:?}", a.pop());
    // println!("{:?}", a.pop());
    // println!("{:?}", a.pop());
    // println!("{:?}", a.pop());
    println!("{:?}", a);
}