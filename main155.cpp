#include <stdio.h>
#include <malloc.h>
#include <map>

using namespace std;

typedef struct node {
    struct node *next;
    int data;
} node;

/**
 * 返回环中第一个节点
 * @param h
 * @return
 */
node *getFirstNodeOfCircle(node *h) {
    node *fast = h, *slow = h;
    bool has = false;
    while (true) {
        if (!slow)
            break;
        else
            slow = slow->next;
        if (!fast || !fast->next)
            break;
        else
            fast = fast->next->next;
        if (fast == slow) {
            has = true;
            break;
        }
    }
    if (!has)
        return NULL;
    fast = h;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

/**
 * 返回两个无环链表的第一个交点
 * @param h1
 * @param h2
 * @return
 */

node *getFirstNodeOfInter(node *h1, node *h2) {
    if (!h1 || !h2)
        return NULL;
    int c1 = 0;
    node *t1 = h1;
    while (t1->next) {
        c1++;
        t1 = t1->next;
    }
    int c2 = 0;
    node *t2 = h2;
    while (t2->next) {
        c2++;
        t2 = t2->next;
    }
    if (t1 != t2)
        return NULL;
    if (c1 > c2) {
        node *h = h1;
        h1 = h2;
        h2 = h;
    }
    int c = c2 - c1;
    while (c > 0) {
        h2 = h2->next;
        c--;
    }
    while (h1 != h2) {
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1;
}

map<int, node *> map1;

int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    node *h1 = NULL, *t1 = NULL;
    node *h2 = NULL, *t2 = NULL;
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        node *n = NULL;
        if (map1.find(d) == map1.end()) {
            n = (node *) malloc(sizeof(node));
            n->next = NULL;
            n->data = d;
            map1[d] = n;
        } else
            n = map1[d];
        if (i == 0) {
            h1 = n;
            t1 = n;
        } else {
            t1->next = n;
            t1 = n;
        }
    }
    for (int i = 0; i < m; i++) {
        int d;
        scanf("%d", &d);
        node *n = NULL;
        if (map1.find(d) == map1.end()) {
            n = (node *) malloc(sizeof(node));
            n->next = NULL;
            n->data = d;
            map1[d] = n;
        } else
            n = map1[d];
        if (i == 0) {
            h2 = n;
            t2 = n;
        } else {
            t2->next = n;
            t2 = n;
        }
    }
    node *c1 = getFirstNodeOfCircle(h1);
    node *c2 = getFirstNodeOfCircle(h2);
    if (c1 || c2) {
        if (c1)
            printf("%d\n", c1->data);
        if (c2)
            printf("%d\n", c2->data);
    } else {
        node *t = getFirstNodeOfInter(h1, h2);
        if (t)
            printf("%d\n", t->data);
    }
    return 0;
}