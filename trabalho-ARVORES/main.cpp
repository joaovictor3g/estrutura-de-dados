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

    bt = bt_create(8, nullptr, nullptr);
    bt->left = bt_create(3, nullptr, nullptr);
    bt->right = bt_create(10, nullptr, nullptr);
    (bt->left)->left = bt_create(1, nullptr, nullptr);
    (bt->right)->right = bt_create(14, nullptr, nullptr);
    (bt->left)->right = bt_create(6, nullptr, nullptr);
    (bt->left)->right->left = bt_create(4, nullptr, nullptr);
    (bt->left)->right->right = bt_create(7, nullptr, nullptr);
    (bt->right)->right->right = bt_create(13, nullptr, nullptr);

    // cout << "Tamanho: " << bt_count_leafs(bt) << endl;
    // bt_print(bt);

    // cout << "Quantidade de folhas com somente um filho: " << bt_one_child(bt) << endl;

    // cout << "Quantidade de folhas interativamente " << bt_num_interactive(bt) << endl;
    // Node *no = bt_copy(bt);
    // bt_print(no);
    Node *bt2 = bt_emptyTree();

    bt2 = bt_create(8, nullptr, nullptr);
    bt2->left = bt_create(3, nullptr, nullptr);
    bt2->right = bt_create(10, nullptr, nullptr);
    (bt2->left)->left = bt_create(1, nullptr, nullptr);
    (bt2->right)->right = bt_create(14, nullptr, nullptr);
    (bt2->left)->right = bt_create(6, nullptr, nullptr);
    (bt2->left)->right->left = bt_create(4, nullptr, nullptr);
    (bt2->left)->right->right = bt_create(7, nullptr, nullptr);
    (bt2->right)->right->left = bt_create(13, nullptr, nullptr);
    // bt2->left->left->left = bt_create(19, nullptr, nullptr);

    if(bt_equal(bt, bt2)) 
        cout << "São iguais" << endl;
    else cout << "São diferentes" << endl;

    bt_destroy(bt);
    bt_destroy(bt2);
    return 0;
}
