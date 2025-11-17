/**
 * AVLNode.h
 *
 * Author: Grant Rynders
 * Class: CS3100
 * Professor: James Anderson
 * Assignment: Project 5
 * Date Created 11/5/25
 *
 */

#ifndef AVLTREE_AVLNODE_H
#define AVLTREE_AVLNODE_H
#include <string>

enum class NodeType {ROOT, LEFT, RIGHT};

class AVLNode
{
    private:
        std::string key;
        size_t value;
        size_t height;
        AVLNode* left;
        AVLNode* right;
        NodeType nodeType;
    public:
        AVLNode();
        void setLeft(AVLNode* left_value);
        AVLNode* getLeft() const;
        AVLNode*& getLeftRef();
        void setRight(AVLNode* right_value);
        AVLNode* getRight() const;
        AVLNode*& getRightRef();
        void setKey(std::string key_value);
        std::string getKey() const;
        std::string& getKeyRef();
        void setValue(size_t new_value);
        size_t getValue() const;
        size_t& getValueRef();
        void setHeight(size_t height_value);
        size_t numChildren() const;
        bool isLeaf() const;
        bool isRoot() const;
        bool isLeft() const;
        bool isRight() const;
        void setType(NodeType new_type);
        NodeType getType() const;
        NodeType& getTypeRef();
        size_t getHeight() const;
        int getBalance() const;
        size_t recalculateHeight();
        friend std::ostream& operator<<(std::ostream& os, const AVLNode& avlNode);
};


#endif //AVLTREE_AVLNODE_H