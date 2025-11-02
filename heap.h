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
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif