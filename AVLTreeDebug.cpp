/*
Driver code for testing your AVL Tree
This is NOT the test code for grading,
instead for you to get an idea of how to test the tree
 */
#include "AVLTree.h"
#include <iostream>
#include <string>
//#include <ranges>
#include <vector>
using namespace std;


int main() {

    std::cout << "CREATE BASIC TREE: " << std::endl;
    AVLTree tree;
    bool insertResult;
    std::cout << "INSERTS PART 1: " << std::endl;
    insertResult = tree.insert("F", 'F');
    insertResult = tree.insert("F", 'D'); // false, no duplicates allowed
    insertResult = tree.insert("K", 'K');
    insertResult = tree.insert("X", 'X');// single rotate
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER INSERTS PART 1: " << std::endl;
    std::cout << tree << std::endl;
    std::cout << "INSERTS PART 2: " << std::endl;
    insertResult = tree.insert("C", 'C');
    insertResult = tree.insert("A", 'A'); // single rotate right
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER INSERTS PART 2: " << std::endl;
    std::cout << tree << std::endl;
    std::cout << "INSERTS PART 3: " << std::endl;
    insertResult = tree.insert("D", 'D'); // double rotate right
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER INSERTS PART 3: " << std::endl;
    std::cout << tree << std::endl;
    std::cout << "INSERTS PART 4: " << std::endl;
    insertResult = tree.insert("R", 'R'); // double rotate left
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER INSERTS PART 4: " << std::endl;
    std::cout << tree << std::endl;
    std::cout << "INSERTS PART 5: " << std::endl;
    insertResult = tree.insert("V", 'V');
    insertResult = tree.insert("A", 'A'); // false, duplicate
    insertResult = tree.insert("Z", 'Z');
    insertResult = tree.insert("M", 'M');
    insertResult = tree.insert("D", 'D'); // false, duplicate
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER INSERTS PART 5: " << std::endl;
    std::cout << tree << std::endl;

    // size and getHeight
    std::cout << "TREE SIZE AND HEIGHT: " << std::endl;
    std::cout << "tree size: " << tree.size() << std::endl; // 10
    std::cout << "tree height: " << tree.getHeight() << std::endl; // 3
    std::cout << std::endl;

    // contains
    bool containsResult;
    std::cout << "TREE CONTAINS: " << std::endl;
    containsResult = tree.contains("A"); // true
    std::cout << "Does table contain A?: " << containsResult << std::endl;
    containsResult = tree.contains("N"); // false
    std::cout << "Does table contain N?: " << containsResult << std::endl;

    // get
    optional<int> getResult;
    std::cout << "TREE GET PART 1: " << std::endl;
    getResult = tree.get("A"); // 65
    std::cout << "A: " << getResult.value() << std::endl;
    std::cout << "TREE GET PART 2: " << std::endl;
    getResult = tree.get("C"); // 67
    std::cout << "C: " << getResult.value() << std::endl;
    std::cout << "TREE GET PART 3: " << std::endl;
    getResult = tree.get("Q"); // getResult has no value
    std::cout << "Q: " << getResult.has_value() << std::endl; // print 0
    std::cout << std::endl;

    // findRange
    std::cout << "TREE FIND RANGE: " << std::endl;
    vector<size_t> rangeTest = tree.findRange("D", "W");
    // 70 68 82 75 77 86
    for (auto val: rangeTest) {
    std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    // operator[]
    std::cout << "TREE OPERATOR[]: " << std::endl;
    tree["A"] = 108;
    std::cout << tree << std::endl;
    std::cout << std::endl;

    // remove
    bool removeResult;
    std::cout << "TREE REMOVE PART 1: " << std::endl;
    removeResult= tree.remove("A"); // "A" is a leaf
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER REMOVE PART 1: " << std::endl;
    std::cout << tree << std::endl;

    std::cout << "TREE REMOVE PART 2: " << std::endl;
    removeResult = tree.remove("C"); // "C" has one child, single rotate left
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER REMOVE PART 2: " << std::endl;
    std::cout << tree << std::endl;

    std::cout << "TREE REMOVE PART 3: " << std::endl;
    removeResult = tree.remove("F"); // "F" has two children
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER REMOVE PART 3: " << std::endl;
    std::cout << tree << std::endl;

    std::cout << "TREE REMOVE PART 4: " << std::endl;
    removeResult = tree.remove("V");
    removeResult = tree.remove("X");
    removeResult = tree.remove("Z"); // double rotate right
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER REMOVE PART 4: " << std::endl;
    std::cout << tree << std::endl;

    return 0;
}
