#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <vector>
#include <unordered_map>

#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)
#define PARENT(i) ((i)/2)

using namespace std;


template <class K, class V>
/**
 * Useful to implement algorithms for scenario 1.1 in order to find the edge with the highest capacity
 * @tparam K
 * @tparam V
 */
class MaxHeap {
    struct Node {
        K key;
        V value;
    };

    int size;
    int maxSize;
    vector<Node> a;
    unordered_map<K, int> pos;
    const K KEY_NOT_FOUND;

    void upHeap(int i);
    void downHeap(int i);
    void swap(int i1, int i2);

public:
    MaxHeap(int n, const K& notFound);
    int getSize();
    bool hasKey(const K& key);
    void insert(const K& key, const V& value);
    void increaseKey(const K& key, const V& value);
    K removeMax();
};


template <class K, class V>
void MaxHeap<K,V>::upHeap(int i) {
    while (i>1 && a[i].value > a[PARENT(i)].value) {
        swap(i, PARENT(i));
        i = PARENT(i);
    }
}


template <class K, class V>
void MaxHeap<K,V>::downHeap(int i) {
    while (LEFT(i) <= size) {
        int j = LEFT(i);
        if (RIGHT(i)<=size && a[RIGHT(i)].value > a[j].value) j = RIGHT(i);
        if (a[i].value > a[j].value) break;
        swap(i, j);
        i = j;
    }
}

template <class K, class V>
void MaxHeap<K,V>::swap(int i1, int i2) {
    Node tmp = a[i1]; a[i1] = a[i2]; a[i2] = tmp;
    pos[a[i1].key] = i1;
    pos[a[i2].key] = i2;
}


template <class K, class V>
MaxHeap<K,V>::MaxHeap(int n, const K& notFound) : KEY_NOT_FOUND(notFound), size(0), maxSize(n), a(n+1) {
}

template <class K, class V>
int MaxHeap<K,V>::getSize() {
    return size;
}

template <class K, class V>
bool MaxHeap<K, V>::hasKey(const K& key) {
    return pos.find(key) != pos.end();
}

template <class K, class V>
void MaxHeap<K,V>::insert(const K& key, const V& value) {
    if (size == maxSize) return;
    if (hasKey(key)) return;
    a[++size] = {key, value};
    pos[key] = size;
    upHeap(size);
}

template <class K, class V>
void MaxHeap<K,V>::increaseKey(const K &key, const V &value) {
    if (!hasKey(key)) return;
    int i = pos[key];
    if (value < a[i].value) return;
    a[i].value = value;
    upHeap(i);
}

template <class K, class V>
K MaxHeap<K,V>::removeMax() {
    if (size == 0) return KEY_NOT_FOUND;
    K min = a[1].key;
    pos.erase(min);
    a[1] = a[size--];
    downHeap(1);
    return min;
}

#endif