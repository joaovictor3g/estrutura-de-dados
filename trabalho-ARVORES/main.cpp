#include <iostream>
#include "BinaryTree.h"

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};

int main() {
    Node *bt = bt_emptyTree();

    bt = bt_create(10, nullptr, nullptr);
    bt->left = bt_create(11, nullptr, nullptr);
    bt->right = bt_create(12, nullptr, nullptr);
    (bt->left)->left = bt_create(13, nullptr, nullptr);

    cout << "Tamanho: " << bt_count_leafs(bt) << endl;
    bt_print(bt);

    Node *no = bt_copy(bt);
    bt_print(no);

    bt_destroy(bt);

    return 0;
}
