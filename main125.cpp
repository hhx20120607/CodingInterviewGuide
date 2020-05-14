#include<stdio.h>
#include <malloc.h>

/**
 * 设计一个没有扩容负担的堆结构
 * 一种基于链式存储结构的堆
 */

typedef struct node {
    struct node *l;
    struct node *r;
    struct node *p;
    int val;
} node;

typedef struct heap {
    node *first;
    node *last;
    int size;
    bool big;
} heap;

void init(heap *&h, bool big) {
    h = (heap *) malloc(sizeof(heap));
    h->first = NULL;
    h->last = NULL;
    h->size = 0;
    h->big = big;
}

static void midOrderTraverse(node *n) {
    node *l = n->l, *r = n->r;
    if (l)
        midOrderTraverse(l);
    free(n);
    if (r)
        midOrderTraverse(r);
}

void destroy(heap *&h) {
    midOrderTraverse(h->first);
    h = NULL;
}

static node *getParentOfNew(const heap *h) {
    int t = h->size + 1;
    node *first = h->first;
    node *last = h->last;
    if (!last) {
        return NULL;
    } else if (!last->p) {
        return last;
    } else if (last->p->l == last) {
        return last->p;
    } else if ((t - (t & (~t + 1))) == 0) {
        node *ans = first;
        while (ans->l) {
            ans = ans->l;
        }
        return ans;
    } else {
        node *ans = last;
        while (ans->p->r == ans)
            ans = ans->p;
        ans = ans->p->r;
        while (ans->l)
            ans = ans->l;
        return ans;
    }
}

static node *getPreviousOfLast(const heap *h) {
    int t = h->size;
    node *first = h->first;
    node *last = h->last;
    node *p = last->p;
    if (!last || !last->p) {
        return NULL;
    } else if (last->p->r == last) {
        return last->p->l;
    } else if ((t - (t & (~t + 1))) == 0) {
        node *ans = first;
        while (ans->r) {
            ans = ans->r;
        }
        return ans;
    } else {
        node *ans = last->p;
        while (ans->p->l == ans)
            ans = ans->p;
        ans = ans->p->l;
        while (ans->r)
            ans = ans->r;
        return ans;
    }
}

static void swim(const heap *h, node *n) {
    while (n->p) {
        node *p = n->p;
        int ttt1 = p->val;
        int ttt2 = n->val;
        bool temp = h->big;
        if (h->big && n->val > p->val || !h->big && n->val < p->val) {
            int tmp = p->val;
            p->val = n->val;
            n->val = tmp;
            n = p;
        } else
            break;
    }
}

static void sink(const heap *h, node *n) {
    while (true) {
        node *m = n;
        if (h->big) {
            if (n->l && n->l->val > m->val)
                m = n->l;
            if (n->r && n->r->val > m->val)
                m = n->r;
        } else {
            if (n->l && n->l->val < m->val)
                m = n->l;
            if (n->r && n->r->val < m->val)
                m = n->r;
        }
        if (m == n)
            break;
        else {
            int t = m->val;
            m->val = n->val;
            n->val = t;
            n = m;
        }
    }
}

void add(heap *&h, int val) {
    node *t = (node *) malloc(sizeof(node));
    t->val = val;
    t->l = NULL;
    t->r = NULL;
    t->p = NULL;
    node *p = getParentOfNew(h);
    int ttt;
    if (p) {
        ttt = p->val;
    }
    if (!p) {
        h->first = t;
        h->last = t;
    } else {
        if (p->l)
            p->r = t;
        else
            p->l = t;
        t->p = p;
        h->last = t;
    }
    swim(h, t);
    h->size++;
}

void popHead(heap *&h) {
    if (h->size > 0) {
        node *first = h->first;
        node *last = h->last;
        node *p = last->p;
        int ttt1 = first->val;
        int ttt2 = last->val;
        first->val = last->val;
        int ddd;
        if (p)
            ddd = p->val;
        if (p) {
            h->last = getPreviousOfLast(h);
            if (p->r == last)
                p->r = NULL;
            else
                p->l = NULL;
            sink(h, first);
        }
        free(last);
        last = NULL;
        h->size--;
    }
}

node *getHead(const heap *h) {
    return h->first;
}

int getSize(const heap *h) {
    return h->size;
}

int main() {
    freopen("data.in", "r", stdin);
    heap *h = NULL;
    init(h, true);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        add(h, t);
        printf("%d %d %d\n", getSize(h), getHead(h)->val, h->last->val);
    }
    destroy(h);
    return 0;
}