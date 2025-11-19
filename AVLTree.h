/**
 * AVLTree.cpp
 *
 * Author: Grant Rynders
 * Class: CS3100
 * Professor: James Anderson
 * Assignment: Project 5
 * Date Created 11/5/25
 *
 */

#ifndef AVLTREE_H
#define AVLTREE_H
#include <optional>
#include <string>
#include <vector>
#include "AVLNode.h"

using namespace std;

class AVLTree {
    private:
        // PRIVATE VARIABLES
        AVLNode* root;
        size_t height;
        static const std::hash<std::string> hasher;
        // PRIVATE SETTERS
        void setRoot(AVLNode*& new_root);
        // RECURSION FOR UTILITY FUNCTIONS
        void equalsRecursive(const AVLNode* other_node, AVLNode*& new_node);
        std::vector<size_t> findRangeRecursion(const AVLNode* node, std::vector<size_t> values, size_t lowIndex, size_t highIndex) const;
        size_t sizeRecursion(const AVLNode* node, size_t size_counter) const;
        std::vector<std::string> keysRecursion(const AVLNode* node, std::vector<std::string> keys_vector) const;
        // GET NODE
        AVLNode*& getNode(const std::string& key);
        AVLNode* getNode(const std::string& key) const;
        // GET FURTHEST NODES
        AVLNode*& getRightMostNode(AVLNode*& node);
        AVLNode*& getLeftMostNodeConst(AVLNode*& node) const;
        AVLNode*& getLeftMostNode(AVLNode*& node);
        AVLNode*& getRightMostNodeConst(AVLNode*& node) const;
        // CRUD ACTIONS
        bool removeNode(AVLNode*& current);
        bool recursiveDestroyNode(AVLNode* node_to_destroy);
        // BALANCE AND ROTATE FUNCS
        void balanceNode(AVLNode*& node);
        void balanceNodePos(AVLNode*& node);
        void balanceNodeNeg(AVLNode*& node);
        void rightRotate(AVLNode*& y_node);
        void leftRotate(AVLNode*& x_node);
        void leftLeftRotation(AVLNode*& y_node);
        void rightRightRotation(AVLNode*& x_node);
        void leftRightRotation(AVLNode*& node);
        void rightLeftRotation(AVLNode*& node);
    public:
        using KeyType = std::string;
        using ValueType = size_t;
        // DEFAULT CONSTRUCTOR
        AVLTree();
        AVLTree(std::vector<std::pair<std::string, size_t>> pairs);

        // CRUD
        bool insert(const std::string& key, size_t value);
        bool remove(const std::string& key);
        bool contains(const std::string& key) const;
        // GET OPERATIONS
        std::optional<size_t> get(const std::string& key) const;
        size_t& operator[](const std::string& key);
        std::vector<size_t> findRange(const std::string& lowKey, const std::string& highKey) const;
        std::vector<std::string> keys() const;
        size_t size() const;
        size_t getHeight() const;
        void setHeight(size_t height_value);
        AVLNode*& getRoot();
        AVLNode* const& getRoot() const;
        // EQUALS AND COPY CONSTRUCTORS
        AVLTree(const AVLTree& other);
        AVLTree& operator=(const AVLTree& other);
        // DESTRUCTOR
        ~AVLTree();
        // HASHING AND INDEXING
        size_t hash(const std::string& str) const;
        size_t getIndex(AVLNode* node);
        size_t getIndex(const AVLNode* node) const;
        // PRINTING
        bool recursivePrintNode(ostream& os, AVLNode* current, size_t depth) const;
        friend std::ostream& operator<<(ostream& os, const AVLTree& avlTree);
};

#endif //AVLTREE_H
