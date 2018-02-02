#[derive(Debug)]
struct Queue<T> {
    head: Option<T>,
    tail: Option<Box<Queue<T>>>,
}

impl<T> Queue<T> {
    fn new() -> Queue<T> {
        Queue {
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
                self.tail = Some(Box::new(Queue{
                    head: Some(data),
                    tail: None,
                }));
            }
        }
    }

    fn pop(&mut self) -> Option<T> {
        let temp = &self.head;
        match self.tail {
            Some(ref next) => {
                self.head = next.head;
                self.tail = next.tail;
            }
            None => self.head = None,
        }
        *temp
    }
}

fn main() {
    let mut a = Queue::new();
    a.push(1);
    a.push(2);
    println!("{:?}", a.pop());
    println!("{:?}", a.pop());
    println!("{:?}", a.pop());
}