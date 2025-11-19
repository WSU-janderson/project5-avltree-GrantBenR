/**
 * AVLTree.cpp
 *
 * Author: Grant Rynders
 * Class: CS3100
 * Professor: James Anderson
 * Assignment: Project 5
 * Date Created 11/5/25
 *
 */

#include "AVLTree.h"

#include <iostream>
#include <optional>
#include <ostream>
#include <string>
#include <vector>


const std::hash<std::string> AVLTree::hasher = std::hash<std::string>{};
/**
 * Hash a string using the builtin static hasher defined above
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param str
 * @return
 */
size_t AVLTree::hash(const std::string& str) const
{
    return hasher(str); // O(1)
}

/**
 *
 * Gets hashed index value for string
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @param node
 * @return
 */
size_t AVLTree::getIndex(AVLNode* node)
{
    return hash(node->getKey());
}

/**
 *
 * Gets const hashed index value for string
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param node
 * @return
 */
size_t AVLTree::getIndex(const AVLNode* node) const
{
    return hash(node->getKey()); // O(1)
}

/**
 *
 * Insert a new key-value pair into the tree. After a sucessful insert, the tree is rebalanced if necessary.
 * Duplicate keys are disallowed. The insert() method should return true if the insertion was
 * successful, false otherwise. If the insertion was unsuccessful, such as when a duplicate is
 * attempted to be inserted, the method should return false.
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @param key
 * @param value
 * @return
 */
bool AVLTree::insert(const std::string& key, size_t value)
{
    AVLNode*& node = this->getNode(key); // O(logN)
    if (node == nullptr)
    {
        node = new AVLNode(key, value); // O(1)
        this->getRoot()->recalculateHeight();
        if (this->getRoot() == nullptr) // O(1)
        {
            this->setRoot(node); // O(1)
        }
        else
        {
            this->balanceNode(this->getRoot());
        }
        return true;
    }
    else
    {
        return false;
    }
}

/**
 *
 * If the key is in the tree, remove() will delete the key-value pair from the tree. The memory allocated
 * for the node that is removed will be released. After removing the key-value pair, the tree is
 * rebalanced if necessary. If the key was removed from the tree, remove() returns true, if the key
 * was not in the tree, remove() returns false.
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @param key
 * @return
 */
bool AVLTree::remove(const std::string& key)
{
    AVLNode*& node_to_delete = this->getNode(key);
    if (node_to_delete != nullptr)
    {
        removeNode(node_to_delete);
    }
    else
    {
        return false;
    }
}

/**
 *
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @param current
 * @return
 */
bool AVLTree::removeNode(AVLNode*& current)
{
    if (!current) {
        return false;
    }

    AVLNode* toDelete = current;
    auto nChildren = current->numChildren();
    if (current->isLeaf())
    {
        // case 1 we can deletes the node
        current = nullptr;
    }
    else if (current->numChildren() == 1)
    {
        // case 2 - replace current with its only child
        if (current->getRight())
        {
            current = current->getRight();
        }
        else
        {
            current = current->getLeft();
        }
    }
    else
    {
        // case 3 - we have two children,
        // get smallest key in right subtree by
        // getting right child and go left until left is null
        AVLNode* smallestInRight = this->getLeftMostNode(current->getRightRef());
        const std::string newKey = smallestInRight->getKey();
        const int newValue = static_cast<int>(smallestInRight->getValue());
        removeNode(smallestInRight); // delete this one

        current->setKey(newKey);
        current->setValue(newValue);
        current->recalculateHeight();
        balanceNode(current);
        return true; // we already deleted the one we needed to so return
    }
    delete toDelete;
    return true;
}

/**
 *
 * The contains() method returns true if the key is in the tree and false if the key is not in the tree.
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @param key
 * @return
 */
bool AVLTree::contains(const std::string& key) const
{
    AVLNode* node = this->getNode(key); // O(logN)
    if (node != nullptr)
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
 * If the key is found in the tree, get() will return the value associated with that key. If the key is not
 * in the tree, get() will return something called std::nullopt, which is a special value in C++. The
 * get() method returns std::optional<size_t>, which is a way to denote a method might not
 * have a valid value to return. This approach is nicer than designating a special value, like −1, to
 * signify the return value is invalid. It’s also much better than throwing an exception if the key is
 * not found.
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @param key
 * @return
 */
std::optional<size_t> AVLTree::get(const std::string& key) const
{
    AVLNode* node = this->getNode(key);
    if (node != nullptr)
    {
        return node->getValue();
    }
    else
    {
        return std::nullopt;
    }
}

/**
 *
 * Get node with key in the AVL tree. If found returns
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @param key
 * @return
 */
AVLNode*& AVLTree::getNode(const std::string& key)
{
    size_t new_index = this->hash(key);

    AVLNode** current = &this->root;

    while (*current != nullptr)
    {
        size_t existing_index = this->getIndex(*current);

        if (new_index < existing_index)
        {
            current = &((*current)->getLeftRef());
        }
        else if (new_index > existing_index)
        {
            current = &((*current)->getRightRef());
        }
        else
        {
            return *current;
        }
    }
    return *current;
}

/**
 * Get node with key in the AVL tree. If found returns const
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @param key
 * @return
 */
AVLNode* AVLTree::getNode(const std::string& key) const
{
    size_t new_index = this->hash(key);
    AVLNode* current = this->getRoot(); // O(1)

    if (current != nullptr)
    {
        size_t existing_index = 0;
        while (current != nullptr) // O(logN)
        {
            existing_index = this->getIndex(current); // O(1)
            if (new_index < existing_index)
            {
                current = current->getLeftRef(); // O(1)
            }
            else if (new_index > existing_index)
            {
                current = current->getRightRef(); // O(1)
            }
            else
            {
                return current;
            }
        }
        return current;
    }
    else
    {
        return current;
    }
}

/**
 *
 * The bracket operator, operator[], allows us to use our map the same way various programming
 * languages such as C++ and Python allow us to use keys to access values. The bracket operator will
 * work like get() in so that it will return the value stored in the node with the given key. We can
 * retrieve the value associated with a key by saying:
 * int idNum = avlTree[“James”];
 * However, the bracket operator returns a reference to that value. This means we can update the
 * value associated with a key like:
 * avlTree[“James”] = 1234;
 * You do not need to handle missing/invalid keys inside operator[].
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @param key
 * @return
 */
size_t& AVLTree::operator[](const std::string& key)
{
    AVLNode*& node = this->getNode(key); // O(logN)
    if (node != nullptr)
    {
        return node->getValueRef(); // O(1)
    }
    else
    {
        throw std::runtime_error("Operator[]: Table[Key] not found");
    }
}

/**
 *
 * The findRange() method should return a C++ std::vector of size_t containing all the values
 * associated with keys ≥ lowKey and keys ≤ highKey. For each key found in the given range, there
 * will be one value in the vector. If no matching key-value pairs are found, the function should return
 * an empty vector.
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(N)
 *
 * @param lowKey
 * @param highKey
 * @return
 */
std::vector<size_t> AVLTree::findRange( const std::string& lowKey,const std::string& highKey) const
{
    auto range_vector = std::vector<size_t>();
    size_t low_index = this->hash(lowKey);
    size_t high_index = this->hash(highKey);
    range_vector = this->findRangeRecursion(this->getRoot(), range_vector, low_index, high_index);
    return range_vector;
}


/**
 *
 * Recursively get values in the tree that are within the range of indexes
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(N)
 *
 * @param node
 * @param lowIndex
 * @param highIndex
 * @return
 */
std::vector<size_t> AVLTree::findRangeRecursion(const AVLNode* node, std::vector<size_t> values, size_t lowIndex, size_t highIndex) const
{
    if (!node->isLeaf())
    {
        const AVLNode* left = node->getLeft();
        if (left != nullptr)
        {
            size_t left_index = getIndex(left);
            if ((left_index >= lowIndex) && (left_index <= highIndex))
            {
                values.emplace_back(left->getValue()); // O(1)
            }
            values = this->findRangeRecursion(left, values, lowIndex, highIndex); // O(N)
        }
        const AVLNode* right = node->getRight();
        if (right != nullptr)
        {
            size_t right_index = getIndex(right);
            if ((right_index >= lowIndex) && (right_index <= highIndex))
            {
                values.emplace_back(right->getValue()); // O(1)
            }
            values = this->findRangeRecursion(right, values, lowIndex, highIndex); // O(N)
        }
        return values;
    }
    else
    {
        return values;
    }
}

/**
 *
 * The keys() method will return a std::vector with all of the keys currently in the tree. The length
 * of the vector should be the same as the size of the tree.
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @return
 */
std::vector<std::string> AVLTree::keys() const
{
    auto keys_vector = std::vector<std::string>();
    AVLNode* root_node = this->getRoot();
    if (root_node != nullptr)
    {
        return keysRecursion(root_node, keys_vector); // O(N)
    }
    else
    {
        return keys_vector;
    }
}

/**
 *
 * Get all keys in tree recursively
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @param node
 * @param keys_vector
 * @return
 */
std::vector<std::string> AVLTree::keysRecursion(const AVLNode* node, std::vector<std::string> keys_vector) const
{
    if (!node->isLeaf())
    {
        const AVLNode* left = node->getLeft();
        if (left != nullptr)
        {
            keys_vector.emplace_back(left->getKey()); // O(1)
            keys_vector = this->keysRecursion(left, keys_vector); // O(N)
        }
        const AVLNode* right = node->getRight();
        if (right != nullptr)
        {
            keys_vector.emplace_back(right->getKey()); // O(1)
            keys_vector = this->keysRecursion(right, keys_vector); // O(N)
        }
        return keys_vector;
    }
    else
    {
        return keys_vector;
    }
}

/**
 *
 * The size() method returns how many key-value pairs are in the tree.
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @return
 */
size_t AVLTree::size() const
{
    AVLNode* root_node = this->getRoot();
    if (root_node != nullptr)
    {
        return sizeRecursion(root_node, 0); // O(N)
    }
    else
    {
        return 0;
    }
}

/**
 *
 * Recursively find all nodes in tree and count them to find total size
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @param node
 * @param size_counter
 * @return
 */
size_t AVLTree::sizeRecursion(const AVLNode* node, size_t size_counter) const
{
    if (!node->isLeaf())
    {
        const AVLNode* left = node->getLeft();
        if (left != nullptr)
        {
            size_counter += 1;
            size_counter = this->sizeRecursion(left, size_counter); // O(N)
        }
        const AVLNode* right = node->getRight();
        if (right != nullptr)
        {
            size_counter += 1;
            size_counter = this->sizeRecursion(right, size_counter); // O(N)
        }
        return size_counter;
    }
    else
    {
        return size_counter;
    }
}
/**
 *
 * The getHeight() method will return the height of the AVL tree.
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
size_t AVLTree::getHeight() const
{
    // height of the tree every time it is inserted into
    return this->height;
}

/**
 *
 * Setter for height
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
void AVLTree::setHeight(size_t height_value)
{
    // height of the tree every time it is inserted into
    this->height = height_value;
}

/**
 *
 * Getter for root, non-const
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
AVLNode* AVLTree::getRoot()
{
    return this->root;
}
/**
 *
 * Getter for root, const
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @return
 */
AVLNode* const& AVLTree::getRoot() const
{
    return this->root;
}

/**
 *
 * Tree constructor that accepts vector containing key value pairs of size N
 *
 * Average Case Complexity: O( )
 * Worst Case Complexity: O( )
 *
 * @param pairs
 */
// AVLTree::AVLTree(std::vector<std::pair<std::string, size_t>> pairs) : root(nullptr), height(0)
// {
//     if (!pairs.empty())
//     {
//         std::pair<std::string, size_t> pair = pairs[0];
//         AVLNode* node = new AVLNode(pair.first, pair.second, nullptr, nullptr); // O(1)
//         this->root = node;
//         for (size_t i = 1; i < pairs.size(); i++) // O(N)
//         {
//             pair = pairs[i]; // O(1)
//             this->insert(pair.first, pair.second); // O( )
//         }
//     }
//     else
//     {
//         this->root = nullptr;
//     }
// }

/**
 *
 * Copy constructor for AVLTree
 *
 *
 *
 * @param other
 */
AVLTree::AVLTree(const AVLTree& other) : root(nullptr)
{
    AVLNode* other_root = other.getRoot();
    if (other_root != nullptr)
    {
        this->equalsRecursive(other_root, this->getRoot());
        this->setHeight(other.getHeight());
    }
}

/**
 *
 * Set root to new root value
 *
 * Average Case Complexity: O(1)
 * Worst Case Complexity: O(1)
 *
 * @param new_root
 */
void AVLTree::setRoot(AVLNode*& new_root)
{
    this->root = new_root;
}

/**
 *
 * Equals operator for tree. Creates new copies of each value in old tree to place in new tree
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @param other
 */
AVLTree& AVLTree::operator=(const AVLTree& other)
{
    AVLNode* other_root = other.getRoot();
    if (other_root != nullptr)
    {
        this->equalsRecursive(other_root, this->getRoot());
        this->setHeight(other.getHeight());
        return *this;
    }
    else
    {
        return *this;
    }
}

/**
 *
 * Recursive function for setting two trees equal to one another
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @param other_node
 * @param new_node
 */
void AVLTree::equalsRecursive(const AVLNode* other_node, AVLNode* new_node)
{
    new_node = new AVLNode(other_node->getKey(), other_node->getValue());
    new_node->setHeight(other_node->getHeight());
    if (!other_node->isLeaf())
    {
        const AVLNode* other_left = other_node->getLeft();
        if (other_left != nullptr)
        {
            this->equalsRecursive(other_left, new_node->getLeft()); // O(N)
        }
        const AVLNode* other_right = other_node->getRight();
        if (other_right != nullptr)
        {
            this->equalsRecursive(other_right, new_node->getRight()); // O(N)
        }
        return;
    }
    else
    {
        return;
    }
}

/**
 *
 * Destroys all nodes in the tree
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 */
AVLTree::~AVLTree()
{
    bool didDestroy = this->recursiveDestroyNode(this->getRoot()); // O(N)
}
/**
 *
 * Recursively destroy all the nodes in the tree.
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @param node_to_destroy
 * @return
 */
bool AVLTree::recursiveDestroyNode(AVLNode* node_to_destroy)
{
    if (!node_to_destroy->isLeaf())
    {
        AVLNode* left = node_to_destroy->getLeft();
        if (left != nullptr)
        {
            this->recursiveDestroyNode(left); // O(N)
        }
        AVLNode* right = node_to_destroy->getRight();
        if (right != nullptr)
        {
            this->recursiveDestroyNode(right); // O(N)
        }
        delete node_to_destroy;
        return true;
    }
    else
    {
        delete node_to_destroy;
        return false;
    }
}
/**
 *
 * Print all nodes in the tree from right to left
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @param os
 * @param avlTree
 * @return
 */
std::ostream& operator<<(ostream& os, const AVLTree& avlTree)
{
    AVLNode* root_node = avlTree.getRoot();
    avlTree.recursivePrintNode(os, root_node, 0);
    return os;
}

/**
 *
 * Print all nodes in the tree from right to left
 *
 * Average Case Complexity: O(N)
 * Worst Case Complexity: O(N)
 *
 * @param os
 * @param current
 * @return
 */
bool AVLTree::recursivePrintNode(ostream& os, AVLNode* current, size_t depth) const
{
    if (!current->isLeaf())
    {
        AVLNode* right = current->getRightRef(); // O(1)
        if (right != nullptr)
        {
            this->recursivePrintNode(os, right, (depth + 1)); // O(N)
        }

        for (size_t i = 0; i < depth; i++) // worst (O(N)
        {
            os << "\t"; // Print tabs to signify depth
        }
        os << current << std::endl; // O(1)

        AVLNode* left = current->getLeftRef(); // O(1)
        if (left != nullptr)
        {
            this->recursivePrintNode(os, left, depth + 1); // O(N)
        }
        return true;
    }
    else
    {
        for (size_t i = 0; i < depth; i++) // worst (O(N)
        {
            os << "\t"; // Print tabs to signify depth
        }
        os << current << std::endl; // O(1)
        return false;
    }
}

/**
 *
 * Gets rightmost node in the tree
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @return
 */
AVLNode*& AVLTree::getRightMostNode(AVLNode*& node)
{
    AVLNode*& rightmost_node = node;
    while (rightmost_node->getRight() != nullptr)
    {
        rightmost_node = rightmost_node->getRightRef();
    }
    return rightmost_node;
}
/**
 *
 * Gets leftmost node in the tree
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @return
 */
AVLNode*& AVLTree::getLeftMostNode(AVLNode*& node)
{
    AVLNode*& leftmost_node = node;
    while (leftmost_node->getLeft() != nullptr)
    {
        leftmost_node = leftmost_node->getLeftRef();
    }
    return leftmost_node;
}
/**
 *
 * Gets const rightmost node in the tree
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @return
 */
AVLNode*& AVLTree::getRightMostNodeConst(AVLNode*& node) const
{
    AVLNode*& rightmost_node = node;
    while (rightmost_node->getRight() != nullptr)
    {
        rightmost_node = rightmost_node->getRightRef();
    }
    return rightmost_node;
}
/**
 *
 * Gets the furthest left node in the tree as const
 *
 * Average Case Complexity: O(logN)
 * Worst Case Complexity: O(logN)
 *
 * @return
 */
AVLNode*& AVLTree::getLeftMostNodeConst(AVLNode*& node) const
{
    AVLNode*& leftmost_node = node;
    while (leftmost_node->getLeft() != nullptr) // O(logN)
    {
        leftmost_node = leftmost_node->getLeftRef();
    }
    return leftmost_node;
}

/**
 *
 * If a node is inserted or removed, the tree may need to be rebalanced. Depending on the postion
 * of the unbalanced nodes, different rotatations are required.
 *
 * Average Case Complexity: O()
 * Worst Case Complexity: O()
 *
 * @param node
 */
void AVLTree::balanceNode(AVLNode* node)
{
    node->recalculateHeight();
    int node_balance = node->getBalance(); // O(1)
    if (node_balance > 1) // O(1)
    {
        this->balanceNodePos(node);
    }
    else if (node_balance < -1) // O(1)
    {
        this->balanceNodeNeg(node);
    }
    else
    {
        return;
    }
}

void AVLTree::balanceNodePos(AVLNode* node)
{
    AVLNode* left_node = node->getLeft(); // O(1)
    if (left_node != nullptr)
    {
        int left_balance = left_node->getBalance(); // O(1)
        if (left_balance > 0)
        {
            this->leftLeftRotation(node); //
            return;
        }
        else if (left_node->getBalance() < 0)
        {
            this->leftRightRotation(node); //
            return;
        }
    }
    AVLNode* right_node = node->getRight(); // O(1)
    if (right_node != nullptr)
    {
        int right_balance = right_node->getBalance(); // O(1)

        if (right_balance < 0)
        {
            this->rightRightRotation(node); //
            return;

        }
        else if (right_balance > 0)
        {
            this->rightLeftRotation(node); //
            return;
        }
    }
}

void AVLTree::balanceNodeNeg(AVLNode* node)
{
    AVLNode* left_node = node->getLeft(); // O(1)
    if (left_node != nullptr)
    {
        int left_balance = left_node->getBalance(); // O(1)
        if (left_balance > 0)
        {
            this->leftLeftRotation(node); //
            return;
        }
        else if (left_balance < 0)
        {
            this->leftRightRotation(node); //
            return;
        }
    }
    AVLNode* right_node = node->getRight(); // O(1)
    if (right_node != nullptr)
    {
        int right_balance = right_node->getBalance(); // O(1)

        if (right_balance < 0)
        {
            this->rightRightRotation(node); //
            return;
        }
        else if (right_balance > 0)
        {
            this->rightLeftRotation(node); //
            return;
        }
    }
}

/**
 *
 *          x                         y
 *         / \                       / \
 *        y   T3     ----->         T1  x
 *       / \                           / \
 *     T1  T2                         T2  T3
 *
 * @param x_node
 */
AVLNode* AVLTree::rightRotate(AVLNode*& x_node)
{
    AVLNode* y_node = x_node->getLeft();
    AVLNode* T2_node = y_node->getRight();

    y_node->setRight(x_node);
    x_node->setLeft(T2_node);

    x_node->recalculateHeight();
    y_node->recalculateHeight();
    return y_node;
}

/**
 *
 *      x                                 y
 *     / \                               / \
 *    T1  y           ----->            x   T3
 *       / \                           / \
 *      T2  T3                        T1  T2
 *
 * @param x_node
 */
AVLNode* AVLTree::leftRotate(AVLNode* x_node)
{
    AVLNode* y_node = x_node->getRight();
    AVLNode* T2_node = y_node->getLeft();

    y_node->setLeft(x_node);
    x_node->setRight(T2_node);

    x_node->recalculateHeight();
    y_node->recalculateHeight();
    return y_node;
}

/**
 *
 *          y                         x
 *         /                         / \
 *        x         ----->          z   y
 *      /
 *     z
 *
 * @param y_node
 */
void AVLTree::leftLeftRotation(AVLNode* y_node)
{

    y_node = this->rightRotate(y_node);
}

/**
 *
 *      x                                 y
 *       \                               / \
 *        y           ----->            x   z
 *         \
 *          z
 *
 * @param x_node
 */
void AVLTree::rightRightRotation(AVLNode* x_node)
{
    x_node = this->leftRotate(x_node);
}

/**
 *
 *          x                         x
 *         /                         /                        z
 *        y          ----->         z          ----->        / \
 *         \                       /                        y   x
 *          z                     y
 *
 * @param node
 */
void AVLTree::leftRightRotation(AVLNode*& node)
{
    AVLNode* y_node = node->getLeft();
    node->setLeft(this->leftRotate(y_node));
    this->rightRotate(node);
    std::cout << node << std::endl;
}

/**
 *
 *          x                         x
 *           \                         \                          z
 *            y          ----->         z          ----->        / \
 *           /                           \                      y   x
 *          z                             y
 *
 * @param node
 */
void AVLTree::rightLeftRotation(AVLNode* node)
{
    AVLNode* y_node = node->getRightRef();
    node->setRight(this->leftRotate(y_node));
    node = this->rightRotate(node);
}

/**
 * DEFAULT CONSTRUCTOR
 */
AVLTree::AVLTree() : root(nullptr), height(0)
{

}
