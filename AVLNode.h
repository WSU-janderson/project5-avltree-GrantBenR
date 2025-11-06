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
        void SetLeft(AVLNode* left_value);
        AVLNode* GetLeft() const;
        void SetRight(AVLNode* right_value);
        AVLNode* GetRight() const;
        void SetKey(std::string key_value);
        std::string GetKey() const;
        void SetValue(size_t new_value);
        size_t GetValue() const;
        void SetHeight(size_t height_value);
        size_t GetHeight() const;
        size_t numChildren() const;
        bool isLeaf() const;
        size_t getHeight() const;
};


#endif //AVLTREE_AVLNODE_H