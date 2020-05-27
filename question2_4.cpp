#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

/**
 * 二叉树的序列化和反序列化
 */
using namespace std;

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} node;

static void construct(node *&t) {
    int data;
    scanf("%d", &data);
    if (data) {
        t = (node *) malloc(sizeof(node));
        t->data = data;
        construct(t->left);
        construct(t->right);
    } else
        t = NULL;
}

void serializeTree(node *t, ostringstream *ostream) {
    if (t) {
        *ostream << (t->data) << ' ';
        serializeTree(t->left, ostream);
        serializeTree(t->right, ostream);
    } else
        *ostream << "NULL" << ' ';
}

void deserializeTree(node *&t, istringstream *istream) {
    string s;
    *istream >> s;
    if (s != "NULL") {
        t = (node *) malloc(sizeof(node));
        t->data = stoi(s);
        deserializeTree(t->left, istream);
        deserializeTree(t->right, istream);
    } else
        t = NULL;
}

int main() {
    node *t = NULL;
    construct(t);
    ostringstream ostream;
    serializeTree(t, &ostream);
    cout << ostream.str();
    node *n = NULL;
    istringstream istream(ostream.str());
    deserializeTree(n, &istream);
    return 0;
}