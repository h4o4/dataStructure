#include <iostream>
#include <vector>
using namespace std;

template <class T> 
class Heap {
  private:
    int tail;
    T *array;
    int parent(const int index) { return index >> 1; }
    int left(const int index) { return index << 1; }
    int right(const int index) { return (index << 1) | 1; }

  public:
    Heap(const int volume)
        : tail(1) {
        array = new T[volume + 1];
    }
    ~Heap() { delete[] array; }
    T top() { return array[1]; }
    void push(const int &key) {
        array[tail] = key;
        int cur = tail;
        int p_cur = parent(cur);
        while (p_cur > 0 && array[p_cur] < array[cur]) {
            int temp = array[p_cur];
            array[p_cur] = array[cur];
            array[cur] = temp;
            cur = p_cur;
            p_cur = parent(cur);
        }
        tail += 1;
    }
    void pop() {
        array[1] = array[tail - 1];
        array[tail - 1] = T();
        int cur = 1;
        int l_cur = left(cur);
        int r_cur = right(cur);
        while (true) {
            if (l_cur < tail && array[l_cur] > array[cur]) {
                int temp = array[l_cur];
                array[l_cur] = array[cur];
                array[cur] = temp;
                cur = l_cur;
            }
            if (r_cur < tail && array[r_cur] > array[cur]) {
                int temp = array[r_cur];
                array[r_cur] = array[cur];
                array[cur] = temp;
                cur = r_cur;
            }
            else break;
            l_cur = left(cur);
            r_cur = right(cur);
        }
        if (tail > 0) {
            tail -= 1;
        }
    }
    void traverse() {
        for (int i = 1; i < tail; i++)
            cout << array[i] << ' ';
        cout << endl;
    }
};

int main() {
    Heap<int> h(15);
    for (int i = 0; i < 15; i++) 
        h.push(i);
    h.pop();
    h.traverse();
}