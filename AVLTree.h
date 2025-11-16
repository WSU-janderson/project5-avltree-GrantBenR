/**
 * AVLTree.h
 */

#ifndef AVLTREE_H
#define AVLTREE_H
#include <optional>
#include <string>
#include <bits/stl_vector.h>

#include "AVLNode.h"

using namespace std;

class AVLTree {
    private:
        AVLNode *&root;
        static const std::hash<std::string> hasher;
        void setRoot(AVLNode*& new_root);
        std::vector<AVLNode*>*& getNodesRightFirstRecursion(AVLNode* current, std::vector<AVLNode*>*& nodes);
        bool recursiveDestroyNode(AVLNode* node_to_destroy);
        void balanceNodePos(AVLNode*& node);
        void balanceNodeNeg(AVLNode*& node);
    public:
        using KeyType = std::string;
        using ValueType = size_t;
        bool remove(AVLNode*& current, KeyType key);
        bool contains(const std::string& key) const;
        std::optional<size_t> get(const std::string& key) const;
        AVLNode*& getNode(const std::string& key);
        std::string& operator[](const size_t& key);
        std::vector<std::string> findRange(const std::string& lowKey, const std::string& highKey) const;
        std::vector<std::string> keys() const;
        size_t size() const;
        size_t getHeight() const;
        AVLNode*& getRoot();
        AVLNode*& getRoot() const;
        AVLTree(const AVLTree& other);
        AVLTree& operator=(const AVLTree& other);
        ~AVLTree();
        AVLNode*& getRightMostNode(AVLNode*& node);
        AVLNode*& getLeftMostNode(AVLNode*& node);
        std::vector<AVLNode*>& getNodesRightFirst();
        size_t hash(const std::string& str) const;
        size_t getIndex(AVLNode* node);
        size_t getIndex(const AVLNode* node) const;
        bool insert(const std::string& key, size_t value);
        // removeNode contains the logic for actually removing a node based on the numebr of children
        bool removeNode(AVLNode*& current);
        // You will implement this, but it is needed for removeNode()
        void balanceNode(AVLNode*& node);
        void rightRotate(AVLNode*& y_node);
        void leftRotate(AVLNode*& x_node);
        void leftLeftRotation(AVLNode*& y_node);
        void rightRightRotation(AVLNode*& x_node);
        void leftRightRotation(AVLNode*& node);
        void rightLeftRotation(AVLNode*& node);
        bool recursivePrintNode(AVLNode* current);
        friend std::ostream& operator<<(ostream& os, const AVLTree & avlTree);
};

#endif //AVLTREE_H
