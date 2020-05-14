#include <stdio.h>
#include <cstdlib>

/**
 * 循环队列
 *
 */

typedef struct {
    int *addr;
    int len;
    int r;
    int w;
    bool fliped;
} queue;

void init(queue *&q, int len) {
    q = (queue *) malloc(sizeof(queue));
    q->addr = (int *) malloc(sizeof(int) * len);
    q->len = len;
    q->r = 0;
    q->w = 0;
    q->fliped = false;
}

bool isEmpty(queue *q) {
    return q->fliped == false && q->r == q->w;
}

bool isFull(queue *q) {
    return q->fliped == true && q->r == q->w;
}

bool add(queue *&q, int ele) {
    if (isFull(q))
        return false;
    *(q->addr + q->w) = ele;
    q->w++;
    if (q->w == q->len) {
        q->w = 0;
        q->fliped = true;
    }
    return true;
}

bool remove(queue *&q, int &ele) {
    if (isEmpty(q))
        return false;
    ele = *(q->addr + q->r);
    q->r++;
    if (q->r == q->len) {
        q->r = 0;
        q->fliped = false;
    }
    return true;
}