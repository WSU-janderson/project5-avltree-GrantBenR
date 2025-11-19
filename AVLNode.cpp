/**
 * AVLNode.cpp
 *
 * Author: Grant Rynders
 * Class: CS3100
 * Professor: James Anderson
 * Assignment: Project 5
 * Date Created 11/5/25
 *
 */

#include "AVLNode.h"

#include <ostream>
#include <utility>

/**
 *
 * Default Constructor
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 */
AVLNode::AVLNode() : value(0), height(0), left(nullptr), right(nullptr)
{

}
AVLNode::AVLNode(std::string key, const size_t value) : key(std::move(key)), value(value), height(0), left(nullptr), right(nullptr)
{

}
/**
 *
 * Setter for left
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param left_value
 */
void AVLNode::setLeft(AVLNode* left_value)
{
    this->left = left_value;
}

/**
 *
 * Getter for left const
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
AVLNode* AVLNode::getLeft() const
{
    return left;
}

/**
 *
 * Getter for left ref
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
AVLNode*& AVLNode::getLeftRef()
{
    return left;
}

/**
 *
 * Setter for right
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param right_value
 */
void AVLNode::setRight(AVLNode* right_value)
{
    this->right = right_value;
}

/**
 *
 * Getter for right const
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
AVLNode* AVLNode::getRight() const
{
    return right;
}
/**
 *
 * Getter for right ref
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
AVLNode*& AVLNode::getRightRef()
{
    return right;
}
/**
 *
 * Setter for key
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param key_value
 */
void AVLNode::setKey(std::string key_value)
{
    this->key = std::move(key_value);
}

/**
 *
 * Getter for key const
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
std::string AVLNode::getKey() const
{
    return key;
}
/**
 *
 * Getter for key ref
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
std::string& AVLNode::getKeyRef()
{
    return key;
}
/**
 *
 * Setter for value
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param new_value
 */
void AVLNode::setValue(const size_t new_value)
{
    this->value = new_value;
}

/**
 *
 * Getter for value const
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
size_t AVLNode::getValue() const
{
    return this->value;
}

/**
 *
 * Getter for value ref
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
size_t& AVLNode::getValueRef()
{
    return this->value;
}

/**
 *
 * Setter for node height
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param height_value
 */
void AVLNode::setHeight(const size_t height_value)
{
    this->height = height_value;
}

/**
 *
 * Recalculates height of cell and sets it
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
size_t AVLNode::recalculateHeight()
{
    return this->recalculateHeightRecursion(0);
}
size_t AVLNode::recalculateHeightRecursion(size_t init_height)
{
    size_t total_height = 0;
    if (!(this->isLeaf()))
    {
        AVLNode** left_ptr = &(this->getLeftRef());
        AVLNode** right_ptr = &(this->getRightRef());
        if (*left_ptr != nullptr)
        {
            size_t left_height = 0;
            (*left_ptr)->setHeight(init_height + 1);
            left_height = (*left_ptr)->recalculateHeightRecursion(init_height + 1);
            if (left_height > total_height)
            {
                total_height = left_height;
            }
        }
        if (*right_ptr != nullptr)
        {
            size_t right_height = 0;
            (*right_ptr)->setHeight(init_height + 1);
            right_height = (*right_ptr)->recalculateHeightRecursion(init_height + 1);

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
 * Gets number of direct children of a node between 0 and 2
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
size_t AVLNode::numChildren() const
{
    size_t num_children = 0;
    if (getRight()) // O(1)
    {
        num_children += 1;
    }
    if (getLeft()) // O(1)
    {
        num_children += 1;
    }
    return num_children;
}

/**
 *
 * If the Node has no left or right value it is a leaf on the BST
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
bool AVLNode::isLeaf() const
{
    if (getLeft() && getRight()) // O(1)
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
 * Getter for height const
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
size_t AVLNode::getHeight() const
{
    return this->height;
}

/**
 *
 * Calculates balance based on left and right nodes
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
int AVLNode::getBalance() const
{
    int balance = 0;
    AVLNode* left_node = this->getLeft();
    if (left_node != nullptr)
    {
        balance += static_cast<int>(left_node->getHeight()); // O(1)
    }
    else
    {
        balance -= 1;
    }
    AVLNode* right_node = this->getRight();
    if (right_node != nullptr)
    {
        balance -= static_cast<int>(right_node->getHeight()); // O(1)
    }
    else
    {
        balance = balance + 1; // O(1)
    }
    return balance;
}

/**
 *
 * ostream operator for node
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param os
 * @param avlNode
 * @return
 */
std::ostream& operator<<(std::ostream& os, const AVLNode* avlNode)
{
    if (avlNode != nullptr)
    {
        std::string key = avlNode->getKey();
        size_t value = avlNode->getValue();
        os << "{" << key << ": " << value << "}";
    }
    else
    {
        os << "{NULL}";
    }
    return os;
}
