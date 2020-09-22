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
    (bt->right)->right = bt_create(14, nullptr, nullptr);
    (bt->left)->right = bt_create(15, nullptr, nullptr);
    (bt->left)->right->left = bt_create(16, nullptr, nullptr);

    cout << "Tamanho: " << bt_count_leafs(bt) << endl;
    bt_print(bt);

    cout << "Quantidade de folhas com somente um filho: " << bt_one_child(bt) << endl;

    cout << "Quantidade de folhas interativamente " << bt_num_interactive(bt) << endl;
    // Node *no = bt_copy(bt);
    // bt_print(no);

    bt_destroy(bt);

    return 0;
}
