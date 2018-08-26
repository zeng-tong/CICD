//
// Created by zengtong on 2018/8/25 2:49 PM.
//
#include <iostream>
#include <vector>

using namespace std;

class Heap{
private:
    vector<int> numbers;
    int size;
public:
    Heap(vector<int> num);
    int extractMin();
    void insert(int num);
    bool isEmpty();
private:
    void shiftDown(int pos);
    void shiftUp(int pos);
};
Heap::Heap(vector<int> num) : numbers(std::move(num)), size(numbers.size()) {
    for (int i = size / 2; i >= 0; --i) {
        shiftDown(i);
    }
}
bool Heap::isEmpty() {
    return size == 0;
}
void Heap::shiftDown(int pos) {
    while (size > 1 && pos*2 < size) {
        int k = pos * 2;
        if (k == 0) k = 1;
        if (k + 1 < size && numbers[k + 1] < numbers[k]) ++k;
        if (numbers[k] < numbers[pos]) swap(numbers[k], numbers[pos]);
        pos = k;
    }
}
void Heap::shiftUp(int pos) {
    while (pos > 0 && numbers[pos / 2] > numbers[pos]) {
        swap(numbers[pos / 2], numbers[pos]);
        pos /= 2;
    }
}
void Heap::insert(int num) {
    numbers.push_back(num);
    ++size;
    int pos = numbers.size() - 1;
    shiftUp(pos);
}
int Heap::extractMin() {
    if (isEmpty()) {
        throw("No elements.");
    }
    int res = numbers[0];
    swap(numbers[0], numbers[--size]);
    shiftDown(0);
    return res;
}

int main() {
    vector<int> input{1, 4, 5, 2, 7, 3, 9};
    Heap heap(input);
    heap.insert(14);
    heap.insert(-1);
    while (!heap.isEmpty()) {
        cout << heap.extractMin() << " ";
    }
    return 0;
}
