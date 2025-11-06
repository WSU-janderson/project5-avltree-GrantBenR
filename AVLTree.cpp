#include "AVLTree.h"

#include <optional>
#include <string>
#include <vector>

/**
 *
 * Insert a new key-value pair into the tree. After a sucessful insert, the tree is rebalanced if necessary.
 * Duplicate keys are disallowed. The insert() method should return true if the insertion was
 * successful, false otherwise. If the insertion was unsuccessful, such as when a duplicate is
 * attempted to be inserted, the method should return false.
 *
 * @param key
 * @param value
 * @return
 */
bool AVLTree::insert(const std::string& key, size_t value)
{
    return 0;
}

/**
 *
 * If the key is in the tree, remove() will delete the key-value pair from the tree. The memory allocated
 * for the node that is removed will be released. After removing the key-value pair, the tree is
 * rebalanced if necessary. If the key was removed from the tree, remove() returns true, if the key
 * was not in the tree, remove() returns false.
 *
 * @param current
 * @param key
 * @return
 */
bool AVLTree::remove(AVLNode *&current, KeyType key) {
    return false;
}

/**
 *
 * The contains() method returns true if the key is in the tree and false if the key is not in the tree.
 *
 * @param key
 * @return
 */
bool AVLTree::contains(const std::string& key) const
{
    return false;
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
 * @param key
 * @return
 */
std::optional<size_t> AVLTree::get(const std::string& key) const
{
    return std::nullopt;
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
 * @param key
 * @return
 */
std::string& AVLTree::operator[](const size_t& key)
{
    return std::vector<std::string>();
}

/**
 *
 * The findRange() method should return a C++ std::vector of size_t containing all the values
 * associated with keys ≥ lowKey and keys ≤ highKey. For each key found in the given range, there
 * will be one value in the vector. If no matching key-value pairs are found, the function should return
 * an empty vector.
 *
 * @param lowKey
 * @param highKey
 * @return
 */
std::vector<std::string> AVLTree::findRange( const std::string& lowKey,const std::string& highKey) const
{
    return std::vector<std::string>();
}

/**
 *
 * The keys() method will return a std::vector with all of the keys currently in the tree. The length
 * of the vector should be the same as the size of the tree.
 *
 * @return
 */
std::vector<std::string> AVLTree::keys() const
{
    return std::vector<std::string>();
}

/**
 *
 * The size() method returns how many key-value pairs are in the tree.
 *
 * @return
 */
size_t AVLTree::size() const
{

}

/**
 *
 * The getHeight() method will return the height of the AVL tree.
 *
 * @return
 */
size_t AVLTree::getHeight() const
{

}

/**
 *
 * @param other
 */
AVLTree::AVLTree(const AVLTree& other)
{

}


/**
 *
 * @param other
 */
AVLTree& AVLTree::operator=(const AVLTree& other)
{
    return *this;
}

/**
 *
 */
AVLTree::~AVLTree()
{

}

std::ostream& operator<<(ostream& os, const AVLTree & avlTree)
{
    return os;
}

/**
 *
 * @param current
 * @return
 */
bool AVLTree::removeNode(AVLNode*& current){
    if (!current) {
        return false;
    }

    AVLNode* toDelete = current;
    auto nChildren = current->numChildren();
    if (current->isLeaf()) {
        // case 1 we can deletes the node
        current = nullptr;
    } else if (current->numChildren() == 1) {
        // case 2 - replace current with its only child
        if (current->getRight()) {
            current = current->getRight();
        } else {
            current = current->getLeft();
        }
    } else {
        // case 3 - we have two children,
        // get smallest key in right subtree by
        // getting right child and go left until left is null
        AVLNode* smallestInRight = current->getRight();
        // I could check if smallestInRight is null,
        // but it shouldn't be since the node has two children
        while (smallestInRight->getLeft()) {
            smallestInRight = smallestInRight->getLeft();
        }
        const std::string newKey = smallestInRight->getKey();
        const int newValue = static_cast<int>(smallestInRight->getValue());
        remove(root, smallestInRight->getKey()); // delete this one

        current->setKey(newKey);
        current->setValue(newValue);
        current->setHeight(current->getHeight());
        balanceNode(current);
        return true; // we already deleted the one we needed to so return
    }
    delete toDelete;

    return true;
}

/**
 *
 * @param node
 */
void AVLTree::balanceNode(AVLNode *&node) {
}
