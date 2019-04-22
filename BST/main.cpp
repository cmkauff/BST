// Sample driver
// EE 312 Fall 2018
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for 
// output.
//

#include <iostream>
#include <fstream>
#include "BST312.h"
#include <cstdlib>
#include "string.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << endl;;
    }
}

int main() {

    ifstream inFile;
//    inFile.open("test");
//
//    BST_312<string> bst;
//
//    string s;
//    inFile >> s;
//    while (inFile) {;
//        cout << "inserting ... " << s << endl;
//        bst.insertItem(s);
//        inFile >> s;
//    }
//
//    cout << "postorder traversal is " << endl;
//    print(bst.postOrderTraversal());
//    cout << endl;
//
//    cout << "preorder traversal is " << endl;
//    print(bst.preOrderTraversal());
//    cout << endl;
//
//    cout << "inorder traversal is " << endl;
//    print(bst.inOrderTraversal());
//    cout << endl;
//
//    cout << "Remove items " << endl;
//    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
//    s = "The";
//    bst.deleteItem(s);
//    print(bst.postOrderTraversal());
//    cout << endl;
//    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
//    cout << endl;

    inFile.open("test.txt");

    BST_312<int> bst2;
    BST_312<int> bst5 = BST_312<int>(bst2);

    int s2;
    inFile >> s2;
    while (inFile) {;
        cout << "inserting ... " << s2 << endl;
        bst2.insertItem(s2);
        bst5.insertItem(s2);
        inFile >> s2;
    }

    cout << "postorder traversal is " << endl;
    print(bst2.postOrderTraversal());
    cout << endl;

    cout << "preorder traversal is " << endl;
    print(bst2.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst2.inOrderTraversal());
    cout << endl;

    cout << "postorder traversal of copied tree is " << endl;
    print(bst5.postOrderTraversal());
    cout << endl;


    cout << "Add item to bst2, not bst5 " << endl;
    cout << "number of nodes in bst2 before add is " << bst2.countNodes() << endl;
    s2 = 19;
    bst2.insertItem(s2);
    cout << "inorder traversal of bst2 is " << endl;
    print(bst2.inOrderTraversal());
    cout << endl;
    cout << "number of nodes in bst2 after add is " << bst2.countNodes() << endl;
    cout << endl;
    cout << "number of nodes in bst5 after add to bst2 is " << bst5.countNodes() << endl;
    cout << endl;
    cout << "inorder traversal of bst5 is " << endl;
    print(bst5.inOrderTraversal());
    cout << endl;

    cout << "Remove items " << endl;
    cout << "number of nodes in tree before delete is " << bst2.countNodes() << endl;
    s2 = 100;
    bst2.deleteItem(s2);
    print(bst2.postOrderTraversal());
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst2.countNodes() << endl;
    cout << endl;

    //is full, is empty, make empty
    //isitemintree



//    inFile.open("test3");
//
//    BST_312<float> bst3;
//
//    float s3;
//    inFile >> s3;
//    while (inFile) {;
//        cout << "inserting ... " << s3 << endl;
//        bst3.insertItem(s3);
//        inFile >> s3;
//
//    cout << "postorder traversal is " << endl;
//    print(bst3.postOrderTraversal());
//    cout << endl;
//
//    cout << "preorder traversal is " << endl;
//    print(bst3.preOrderTraversal());
//    cout << endl;
//
//    cout << "inorder traversal is " << endl;
//    print(bst3.inOrderTraversal());
//    cout << endl;
//
//    cout << "Remove items " << endl;
//    cout << "number of nodes in tree before delete is " << bst3.countNodes() << endl;
//    s3 = "880";
//    bst3.deleteItem(s3);
//    print(bst3.postOrderTraversal());
//    cout << endl;
//    cout << "number of nodes in tree after delete is " << bst3.countNodes() << endl;
//    cout << endl;

}




