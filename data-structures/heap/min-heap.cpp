#include <bits/stdc++.h>
using namespace std;

class MinHeap {
  int *array { };
  int size { };
  int capacity { };

  int parent(int node) {
    return node == 0 ? -1 : (node - 1) / 2;
  }

  int left(int pos) {
    int p = 2 * pos + 1;
    if (p >= size)
      return -1;
    return p;
  }

  int right(int pos) {
    int p = 2 * pos + 2;
    if (p >= size)
      return -1;
    return p;
  }

  void heapify_up(int child_pos) {
    int par = parent(child_pos);
    if (child_pos == 0 || array[par] < array[child_pos])
      return;

    swap(array[par], array[child_pos]);
    heapify_up(par);
  }

  void heapify_down(int parent) {
    int child_pos = left(parent);
    int right_pos = right(parent);

    if (child_pos == -1)
      return;
    
    if (right_pos != -1 && array[right_pos] < array[child_pos])
      child_pos = right_pos;
    
    if (array[parent] > array[child_pos]) {
      swap(array[parent], array[child_pos]);
      heapify_down(child_pos);
    }
  }

  void heapify() {	// O(n)
		for (int i = size / 2 - 1; i >= 0; --i)
			heapify_down(i);
	}


public:
  MinHeap(int capacity = 1000) : array(new int [capacity]), size(0), capacity(capacity) {
  }

  MinHeap(const vector<int> &v) : capacity(v.size()) {
		assert((int )v.size() <= capacity);
		array = new int[capacity] { };
		size = v.size();

		for (int i = 0; i < (int) v.size(); ++i)
			array[i] = v[i];

		heapify();
	}

  ~MinHeap() {
    delete[] array;
    array = nullptr;
  }

  void push(int key) {
    assert(size + 1 <= capacity);
    array[size++] = key;
    heapify_up(size - 1);
  }

  void pop() {
    assert(!isempty());
    array[0] = array[--size];
    heapify_down(0);
  }

  int top() {
    assert(!isempty());
    return array[0];
  } 

  bool isempty() {
    return size == 0;
  }
};

void creat_heap_n() {
	vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };
	MinHeap heap(v);

	while (!heap.isempty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
}

int main() {
	MinHeap heap;
	vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };

	for (int i = 0; i < v.size(); ++i) // O(nlogn)
		heap.push(v[i]);

  while (!heap.isempty()) {
    cout << heap.top() << " ";
    heap.pop();
  }

  cout << endl;
  creat_heap_n();

	return 0;

}