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
 * Is node of type ROOT
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
bool AVLNode::isRoot() const
{
    if (this->nodeType == NodeType::ROOT)
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
 * Is node of type LEFT
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
bool AVLNode::isLeft() const
{
    if (this->nodeType == NodeType::LEFT)
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
 * Is node of type RIGHT
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
bool AVLNode::isRight() const
{
    if (this->nodeType == NodeType::RIGHT)
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
 * Setter for type
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param new_type
 */
void AVLNode::setType(NodeType new_type)
{
    this-> nodeType = new_type;
}

/**
 *
 * Getter for type const
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
NodeType AVLNode::getType() const
{
    return this->nodeType;
}

/**
 *
 * Getter for type ref
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
NodeType& AVLNode::getTypeRef()
{
    return this->nodeType;
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
 * Recalculates height of cell and sets it
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
size_t AVLNode::recalculateHeight()
{
    AVLNode* current = this;
    size_t total_height = 0;
    if (!current->isLeaf())
    {
        AVLNode* left_ptr = current->getLeft();
        AVLNode* right_ptr = current->getRight();
        if (left_ptr)
        {
            size_t left_height = 0;
            left_height = left_ptr->recalculateHeight();
            if (left_height > total_height)
            {
                total_height = left_height;
            }
        }
        if (right_ptr)
        {
            size_t right_height = 0;
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
 * ostream operator for node
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
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
