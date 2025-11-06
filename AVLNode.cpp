//
// Created by test on 11/5/2025.

#include "AVLNode.h"

#include <utility>

/**
 *
 */
AVLNode::AVLNode()
{

}

/**
 *
 * @param left_value
 */
void AVLNode::SetLeft(AVLNode* left_value)
{
    this->left = left_value;
}

/**
 *
 * @return
 */
AVLNode* AVLNode::GetLeft() const
{
    return left;
}

/**
 *
 * @param right_value
 */
void AVLNode::SetRight(AVLNode* right_value)
{
    this->right = right_value;
}

/**
 *
 * @return
 */
AVLNode* AVLNode::GetRight() const
{
    return right;
}

/**
 *
 * @param key_value
 */
void AVLNode::SetKey(std::string key_value)
{
    this->key = std::move(key_value);
}

/**
 *
 * @return
 */
std::string AVLNode::GetKey() const
{
    return key;
}

/**
 *
 * @param new_value
 */
void AVLNode::SetValue(const size_t new_value)
{
    this->value = new_value;
}

/**
 *
 * @return
 */
size_t AVLNode::GetValue() const
{
    return this->value;
}

/**
 *
 * @param height_value
 */
void AVLNode::SetHeight(const size_t height_value)
{
    this->height = height_value;
}

/**
 *
 * @return
 */
size_t AVLNode::GetHeight() const
{
    return this->height;
}

/**
 *
 * @return
 */
size_t AVLNode::numChildren() const {
    return 0;
}

/**
 *
 * @return
 */
bool AVLNode::isLeaf() const {
    return false;
}

/**
 *
 * @return
 */
size_t AVLNode::getHeight() const {
    return 0;
}

/**
 *
 * @param os
 * @param avlNode
 * @return
 */
std::ostream& operator<<(std::ostream& os, const AVLNode& avlNode)
{
    return os;
}
