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
    insertResult = tree.insert("1", 'F');
    insertResult = tree.insert("1", 'D'); // false, no duplicates allowed
    insertResult = tree.insert("2", 'K');
    insertResult = tree.insert("3", 'X');// single rotate
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER INSERTS PART 1: " << std::endl;
    std::cout << tree << std::endl;
    std::cout << "INSERTS PART 2: " << std::endl;
    insertResult = tree.insert("4", 'C');
    insertResult = tree.insert("5", 'A'); // single rotate right
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER INSERTS PART 2: " << std::endl;
    std::cout << tree << std::endl;
    std::cout << "INSERTS PART 3: " << std::endl;
    insertResult = tree.insert("6", 'D'); // double rotate right
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER INSERTS PART 3: " << std::endl;
    std::cout << tree << std::endl;
    std::cout << "INSERTS PART 4: " << std::endl;
    insertResult = tree.insert("7", 'R'); // double rotate left
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER INSERTS PART 4: " << std::endl;
    std::cout << tree << std::endl;
    std::cout << "INSERTS PART 5: " << std::endl;
    insertResult = tree.insert("8", 'V');
    insertResult = tree.insert("6", 'A'); // false, duplicate
    insertResult = tree.insert("9", 'Z');
    insertResult = tree.insert("10", 'M');
    insertResult = tree.insert("9", 'D'); // false, duplicate
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
    containsResult = tree.contains("1"); // true
    std::cout << "Does table contain 1?: " << containsResult << std::endl;
    containsResult = tree.contains("wumbo"); // false
    std::cout << "Does table contain wumbo?: " << containsResult << std::endl;

    // get
    optional<int> getResult;
    std::cout << "TREE GET PART 1: " << std::endl;
    getResult = tree.get("2"); // 65
    std::cout << "{A: " << getResult.value() << "}" << std::endl;
    std::cout << "TREE GET PART 2: " << std::endl;
    getResult = tree.get("3"); // 67
    std::cout << "{C: " << getResult.value() << "}" << std::endl;
    std::cout << "TREE GET PART 3: " << std::endl;
    getResult = tree.get("wumbo"); // getResult has no value
    std::cout << "{Q: " << getResult.has_value() << "}" << std::endl; // print 0
    std::cout << std::endl;

    // findRange
    std::cout << "TREE FIND RANGE: " << std::endl;
    vector<size_t> rangeTest = tree.findRange("3", "6");
    // 70 68 82 75 77 86
    for (auto val: rangeTest) {
    std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    // operator[]
    std::cout << "TREE OPERATOR[]: " << std::endl;
    tree["4"] = 108;
    std::cout << tree << std::endl;
    std::cout << std::endl;

    // remove
    bool removeResult;
    std::cout << "TREE REMOVE PART 1: " << std::endl;
    removeResult = tree.remove("5"); // "A" is a leaf
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER REMOVE PART 1: " << removeResult << std::endl;
    std::cout << tree << std::endl;

    std::cout << "TREE REMOVE PART 2: " << std::endl;
    removeResult = tree.remove("7"); // "C" has one child, single rotate left
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER REMOVE PART 2: " << removeResult << std::endl;
    std::cout << tree << std::endl;

    std::cout << "TREE REMOVE PART 3: " << std::endl;
    removeResult = tree.remove("6"); // "F" has two children
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER REMOVE PART 3: " << removeResult << std::endl;
    std::cout << tree << std::endl;

    std::cout << "TREE REMOVE PART 4: " << std::endl;
    removeResult = tree.remove("1");
    removeResult = tree.remove("2");
    removeResult = tree.remove("3"); // double rotate right
    std::cout << std::endl << std::endl;
    std::cout << "TREE AFTER REMOVE PART 4: " << removeResult << std::endl;
    std::cout << tree << std::endl;

    return 0;
}
