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
void AVLNode::setHeight(const int height_value)
{
    this->height = height_value;
}

/**
 *
 * Recalculates height of cell and sets it
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @return
 */
int AVLNode::recalculateHeight()
{
    return this->recalculateHeightRecursion();
}
/**
 *
 * Recursive function for recalculating height
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @return
 */
int AVLNode::recalculateHeightRecursion()
{
    int left_height = -1;
    AVLNode* left_node = this->getLeft();
    if (left_node != nullptr)
        left_height = left_node->recalculateHeightRecursion();
    int right_height = -1;
    AVLNode* right_node = this->getRight();
    if (right_node != nullptr)
        right_height = right_node->recalculateHeightRecursion();

    this->setHeight(1 + std::max(left_height, right_height));
    return this->getHeight();
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
int AVLNode::getHeight() const
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

AVLNode& AVLNode::operator=(const AVLNode& other)
{
    this->key = other.key;
    this->value = other.value;
    this->height = other.height;
    this->setLeft(other.getLeft());
    this->setRight(other.getRight());
    return *this;
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
