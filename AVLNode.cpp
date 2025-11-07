//
// Created by test on 11/5/2025.

#include "AVLNode.h"

#include <ostream>
#include <utility>

/**
 *
 * Default Constructor
 *
 */
AVLNode::AVLNode() : value(0), height(0), left(nullptr), right(nullptr)
{

}

/**
 *
 * Customized Constructor
 *
 * @param key
 * @param node_value
 * @param left_value
 * @param right_value
 */
AVLNode::AVLNode(std::string key,size_t node_value, AVLNode* left_value, AVLNode* right_value) : key(std::move(key)), value(node_value), left(left_value), right(right_value)
{
 this->setHeight(this->getHeight());
}
/**
 *
 * @param left_value
 */
void AVLNode::setLeft(AVLNode* left_value)
{
    this->left = left_value;
}

/**
 *
 * @return
 */
AVLNode* AVLNode::getLeft() const
{
    return left;
}

/**
 *
 * @param right_value
 */
void AVLNode::setRight(AVLNode* right_value)
{
    this->right = right_value;
}

/**
 *
 * @return
 */
AVLNode* AVLNode::getRight() const
{
    return right;
}

/**
 *
 * @param key_value
 */
void AVLNode::setKey(std::string key_value)
{
    this->key = std::move(key_value);
}

/**
 *
 * @return
 */
std::string AVLNode::getKey() const
{
    return key;
}

/**
 *
 * @param new_value
 */
void AVLNode::setValue(const size_t new_value)
{
    this->value = new_value;
}

/**
 *
 * @return
 */
size_t AVLNode::getValue() const
{
    return this->value;
}

/**
 *
 * @param height_value
 */
void AVLNode::setHeight(const size_t height_value)
{
    this->height = height_value;
}

/**
 *
 * @return
 */
size_t AVLNode::numChildren() const
{
    size_t num_children = 0;
    if (getRight())
    {
        num_children += 1;
    }
    if (getLeft())
    {
        num_children += 1;
    }
    return num_children;
}

/**
 *
 * If the Node has no left or right value it is a leaf on the BST
 *
 * @return
 */
bool AVLNode::isLeaf() const
{
    if (getLeft() && getRight())
    {
        return true;
    }
    else
    {
        return false;
    }

}

/**
 *
 * @return
 */
size_t AVLNode::getHeight() const
{
    return this->height;
}

/**
 *
 * @return
 */
size_t AVLNode::recalculateHeight()
{
    AVLNode* current = this;
    size_t total_height = 0;
    size_t left_height = 0;
    size_t right_height = 0;
    if (!current->isLeaf())
    {
        AVLNode* left_ptr = current->getLeft();
        AVLNode* right_ptr = current->getRight();
        if (left_ptr)
        {
            left_height = left_ptr->recalculateHeight();
            if (left_height > total_height)
            {
                total_height = left_height;
            }
        }
        if (right_ptr)
        {
            right_height = right_ptr->recalculateHeight();
            if (right_height > total_height)
            {
                total_height = right_height;
            }
        }
    }
    this->setHeight(total_height);
    return total_height;
}

/**
 *
 * @param os
 * @param avlNode
 * @return
 */
std::ostream& operator<<(std::ostream& os, const AVLNode& avlNode)
{
    os << "{\"" << avlNode.getKey() << "\": " << avlNode.getValue() << "}" << std::endl;
    return os;
}
