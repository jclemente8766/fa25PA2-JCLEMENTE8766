//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size] = idx; //insert index at end
        size++; //increment heap size
        upheap(idx-1, weightArr); //call upheap
    }

    int pop(int weightArr[]) {
        if (size <= 0) { //throws error if heap is empty
            throw std::runtime_error ("Empty");
        }
        size--;
        int min = data[0]; //stores root before pop for return
        if (size > 0) { // replaces root
            data[0] = data[size];
            downheap(0, weightArr);
        }
        return min; //returns stored root (smallest index)
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) { //upward swap if smaller
            int parent = (pos-1)/2;
            while (weightArr[parent] > weightArr[pos]) { // checks weight and if smaller swaps
                int curr = data[pos];
                data[pos] = data[parent];
                data[parent] = curr;
                pos = parent;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        while (pos < size) { // swaps parent with child while larger
            int leftChild = 2*pos+1;
            int rightChild = 2*pos+2;
            int min = pos;
            if (leftChild < size && weightArr[data[leftChild]] > weightArr[data[min]]) { // left child comparison (checks if smaller)
                min = leftChild;
            }
            if (rightChild < size && weightArr[data[rightChild]] > weightArr[data[min]]) { // right child comparison (checks if smaller)
                min = rightChild;
            }
            if (min != pos) { // swaps and continues til min
                int curr = data[pos];
                data[pos] = data[min];
                data[min] = curr;
                pos = min;
            }
        }
    }
};

#endif