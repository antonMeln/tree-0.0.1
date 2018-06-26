// ConsoleApplication17.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include "stdafx.h"
#include <iostream>

using namespace std;

class tree_t {

    private:
        struct node_t {
            node_t *left;
            node_t *right;
            int key;

            node_t() {
                left = nullptr;
                right = nullptr;
                key = 0;

            }

            void print_t(ostream & stream, int size) const {
                if (right != nullptr) right -> print_t(stream , size+4);
                for (int i = 0; i < size + 4; i++)
                    stream << '-';
                stream <<  key << endl;

                if (left != nullptr) left -> print_t(stream , size+4);
            }

            ~node_t() {
                if (left != nullptr) delete left;
                if (right != nullptr) delete right;
            }
        };

        node_t *root;
public:
    tree_t() {
        root = nullptr;
    }
    void insert( int key) {

        if (root == nullptr) {
            root = new node_t;
            root -> key = key;
        }
        else {

            node_t *first = root;

            while (root -> right != nullptr || root -> left != nullptr) {
                if (root -> key > key) {
                    if (root -> left != nullptr) {root = root -> left;}
                    else break;
                }
                else if (root -> key < key) {
                    if (root -> right != nullptr) {root = root -> right;}
                    else break;
                }

            }
            if (root -> key > key) {
                root -> left = new node_t;
                root -> left -> key = key;
            }
			else if (root -> key < key) {
                root -> right = new node_t;
                root -> right -> key = key;
            }
            root = first;
        }

    }

    bool find( int key) const {

        if (root == nullptr) return false;
            
         else {
            node_t *temp = root;

            while (temp != nullptr) {
                if (temp->key == key) return true;
                else if (temp->key > key) temp = temp->left;
                else if (temp->key < key) temp = temp->right;
            }

            return false;
        }
    }

    void print(ostream &stream) {
        if (root == nullptr) {
            stream << "ERROR" << endl;
        }
        else root -> print_t(stream , 0);
    }

    ~tree_t() {
        if (root != nullptr) delete root;
    }

};

int main() {
    char op;
    tree_t tree;
    int data;

    cin >> op;

    while ( op != 'q') {

        switch(op){

            case '+':
                cin >> data;
                tree.insert(data);
                tree.print(cout);
                break;

            case '?':
                cin >> data;
                if(tree.find(data)) cout << "true" << endl;
                else cout << "false" << endl;
                break;
            case '=':
                tree.print(cout);
                break;
        }
        cin >> op;
    }
    return 0;
}

