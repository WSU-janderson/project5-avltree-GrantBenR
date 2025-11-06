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
    public:
        using KeyType = std::string;
        using ValueType = size_t;
        bool remove(AVLNode*& current, KeyType key);
        bool contains(const std::string& key) const;
        std::optional<size_t> get(const std::string& key) const;
        std::string& operator[](const size_t& key);
        std::vector<std::string> findRange(const std::string& lowKey, const std::string& highKey) const;
        std::vector<std::string> keys() const;
        size_t size() const;
        size_t getHeight() const;
        AVLTree(const AVLTree& other);
        AVLTree& operator=(const AVLTree& other);
        ~AVLTree();
        bool insert(const std::string& key, size_t value);
        // removeNode contains the logic for actually removing a node based on the numebr of children
        bool removeNode(AVLNode*& current);
        // You will implement this, but it is needed for removeNode()
        void balanceNode(AVLNode*& node);
        friend std::ostream& operator<<(ostream& os, const AVLTree & avlTree);
};

#endif //AVLTREE_H
