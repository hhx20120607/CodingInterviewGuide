#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>

/**
 * 动态topK结构
 */

using namespace std;

typedef struct {
    string s;
    int c;
} rcd;

bool cmpRcd(rcd a, rcd b) {
    if (a.c != b.c)
        return a.c > b.c;
    return a.s < b.s;
}

typedef struct {
    rcd *elements;
    int size;
    int k;
    map<string, int> *map1;
} heap;

typedef struct {
    heap *h;
    map<string, int> *map1;
} topK;

static void initHeap(heap *&h, int k);

static void destroyHeap(heap *&h);

static void swim(heap *&h, int i);

static void sink(heap *&h, int i);

static rcd getTop(const heap *h);

static void pop(heap *&h);

static void add(heap *&h, rcd r);

static void print(heap *h);

/**
 * topK API: public
 */

void initTopK(topK *&t, int k) {
    t = new topK();
    initHeap(t->h, k);
    t->map1 = new map<string, int>();
}

void destroyTopK(topK *&t) {
    destroyHeap(t->h);
    delete t->map1;
    delete t;
    t = NULL;
}

void addElement(topK *&t, string s) {
    int c = 1;
    map<string, int>::iterator iter;
    if ((iter = t->map1->find(s)) != t->map1->end()) {
        iter->second++;
        c = iter->second;
    } else
        t->map1->insert(pair<string, int>(s, c));
    rcd r = {s, c};
    add(t->h, r);
}

void printTopK(topK *t) {
    print(t->h);
}

/**
 *  heap API: private
 */
static void initHeap(heap *&h, int k) {
    h = new heap();
    h->elements = new rcd[k + 1];
    h->size = 0;
    h->k = k;
    h->map1 = new map<string, int>();
}

static void destroyHeap(heap *&h) {
    delete[] h->elements;
    delete h->map1;
    delete h;
    h = NULL;
}

static void swim(heap *&h, int i) {
    while (i > 0) {
        int j = (i - 1) / 2;
        if (cmpRcd(h->elements[j], h->elements[i])) {
            rcd t = h->elements[i];
            h->elements[i] = h->elements[j];
            h->elements[j] = t;
            h->map1->find(h->elements[i].s)->second = i;
            h->map1->find(h->elements[j].s)->second = j;
            i = j;
        } else
            break;
    }
}

static void sink(heap *&h, int i) {
    while (i < h->size) {
        int j = i;
        if (2 * i + 1 < h->size && cmpRcd(h->elements[j], h->elements[2 * i + 1])) {
            j = 2 * i + 1;
        }
        if (2 * i + 2 < h->size && cmpRcd(h->elements[j], h->elements[2 * i + 2])) {
            j = 2 * i + 2;
        }
        if (j == i) {
            break;
        } else {
            rcd t = h->elements[i];
            h->elements[i] = h->elements[j];
            h->elements[j] = t;
            h->map1->find(h->elements[i].s)->second = i;
            h->map1->find(h->elements[j].s)->second = j;
            i = j;
        }
    }
}

static rcd getTop(const heap *h) {
    rcd t;
    if (h->size > 0)
        t = h->elements[0];
    return t;
}

static void pop(heap *&h) {
    if (h->size > 0) {
        h->map1->erase(h->map1->find(h->elements[0].s));
        h->map1->find(h->elements[h->size - 1].s)->second = 0;
        h->elements[0] = h->elements[h->size - 1];
        h->size--;
        sink(h, 0);
    }
}

static void add(heap *&h, rcd r) {
    if (h->map1->find(r.s) != h->map1->end()) {
        int i = h->map1->find(r.s)->second;
        h->elements[i].c++;
        sink(h, i);
    } else {
        h->elements[h->size] = r;
        h->map1->insert(pair<string, int>(r.s, h->size));
        h->size++;
        swim(h, h->size - 1);
        if (h->size > h->k) {
            pop(h);
        }
    }
}

static void print(heap *h) {
    vector<rcd> vector1;
    for (int i = 0; i < h->size; i++) {
        vector1.push_back(h->elements[i]);
    }
    sort(vector1.begin(), vector1.end(), cmpRcd);
    for (auto e:vector1) {
        cout << e.s << " " << e.c << endl;
    }
}

int main() {
    freopen("data.in", "r", stdin);
    topK *t = NULL;
    initTopK(t, 2);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        addElement(t, s);
    }
    printTopK(t);
    destroyTopK(t);
    return 0;
}