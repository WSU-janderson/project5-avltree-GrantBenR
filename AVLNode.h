//
// Created by test on 11/5/2025.
//

#ifndef AVLTREE_AVLNODE_H
#define AVLTREE_AVLNODE_H
#include <string>


class AVLNode
{
    private:
        std::string key;
        size_t value;
        size_t height;
        AVLNode* left;
        AVLNode* right;

    public:
        AVLNode();
        AVLNode(std::string key, size_t node_value, AVLNode* left_value, AVLNode* right_value);
        void setLeft(AVLNode* left_value);
        AVLNode* getLeft() const;
        void setRight(AVLNode* right_value);
        AVLNode* getRight() const;
        void setKey(std::string key_value);
        std::string getKey() const;
        void setValue(size_t new_value);
        size_t getValue() const;
        void setHeight(size_t height_value);
        size_t GetHeight() const;
        size_t numChildren() const;
        bool isLeaf() const;
        size_t getHeight() const;
        friend std::ostream& operator<<(std::ostream& os, const AVLNode& avlNode);
};


#endif //AVLTREE_AVLNODE_H