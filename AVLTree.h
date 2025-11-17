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
        size_t height;
        static const std::hash<std::string> hasher;
        void setRoot(AVLNode*& new_root);
        std::vector<AVLNode*>*& getNodesRightFirstRecursion(AVLNode* current, std::vector<AVLNode*>*& nodes);
        std::vector<size_t> findRangeRecursion(AVLNode* node, std::vector<size_t> vals, size_t lowIndex, size_t highIndex) const;
        size_t sizeRecursion(const AVLNode* node, size_t size_counter) const;
        std::vector<std::string> keysRecursion(const AVLNode* node, std::vector<std::string> keys_vector) const;
        AVLNode*& getNode(const std::string& key);
        AVLNode*& getNode(const std::string& key) const;
        AVLNode*& getRightMostNode(AVLNode*& node);
        AVLNode*& getLeftMostNodeConst(AVLNode*& node) const;
        AVLNode*& getLeftMostNode(AVLNode*& node);
        AVLNode*& getRightMostNodeConst(AVLNode*& node) const;

        std::vector<AVLNode*>& getNodesRightFirst();

        bool removeNode(AVLNode*& current);

        void balanceNode(AVLNode*& node);

        void rightRotate(AVLNode*& y_node);
        void leftRotate(AVLNode*& x_node);
        void leftLeftRotation(AVLNode*& y_node);
        void rightRightRotation(AVLNode*& x_node);
        void leftRightRotation(AVLNode*& node);
        void rightLeftRotation(AVLNode*& node);

        bool recursiveDestroyNode(AVLNode* node_to_destroy);
        void balanceNodePos(AVLNode*& node);
        void balanceNodeNeg(AVLNode*& node);

    public:
        using KeyType = std::string;
        using ValueType = size_t;
        bool remove(AVLNode* root_node, const std::string& key);
        bool contains(const std::string& key) const;
        std::optional<size_t> get(const std::string& key) const;
        size_t& operator[](const std::string& key);
        std::vector<size_t> findRange(const std::string& lowKey, const std::string& highKey) const;
        std::vector<std::string> keys() const;
        size_t size() const;
        size_t getHeight() const;
        AVLNode*& getRoot();
        AVLNode*& getRoot() const;
        AVLTree(const AVLTree& other);
        AVLTree& operator=(const AVLTree& other);
        ~AVLTree();
        size_t hash(const std::string& str) const;
        size_t getIndex(AVLNode* node);
        size_t getIndex(const AVLNode* node) const;
        bool insert(const std::string& key, size_t value);
        bool recursivePrintNode(AVLNode* current);
        friend std::ostream& operator<<(ostream& os, const AVLTree & avlTree);
};

#endif //AVLTREE_H
