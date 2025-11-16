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

AVLNode*& AVLTree::getRoot()
{
    return this->root;
}
AVLNode*& AVLTree::getRoot() const
{
    return this->root;
}
/**
 *
 * @param value
 * @param key
 */
AVLTree::AVLTree(const std::string& key, size_t value)
{
    auto new_root = new AVLNode(key, value, nullptr, nullptr);
    this->root = new_root;
}

AVLTree::AVLTree(std::vector<std::pair<std::string, size_t>> pairs)
{
    if (!pairs.empty())
    {
        std::pair<std::string, size_t> pair = pairs[0];
        AVLNode* node = new AVLNode(pair.first, pair.second, nullptr, nullptr);
        this->root = node;
        for (size_t i = 1; i < pairs.size(); i++)
        {
            pair = pairs[i];
            this->insert(pair.first, pair.second);
        }
    }
    else
    {
        root = nullptr;
    }
}
/**
 *
 * @param other
 */
AVLTree::AVLTree(const AVLTree& other)
{

}

void AVLTree::setRoot(AVLNode*& new_root)
{
    this->root = new_root;
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
    bool didDestroy = this->recursiveDestroyNode(this->getRoot());
}
bool AVLTree::recursiveDestroyNode(AVLNode* node_to_destroy)
{
    if (!node_to_destroy->isLeaf())
    {
        AVLNode* left = node_to_destroy->getLeft();
        if (left != nullptr)
        {
            this->recursiveDestroyNode(left);
        }
        AVLNode* right = node_to_destroy->getRight();
        if (right != nullptr)
        {
            this->recursiveDestroyNode(right);
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
std::ostream& operator<<(ostream& os, const AVLTree & avlTree)
{
    auto nodes = avlTree.getNodesRightFirst();

    return os;
}
/**
 *
 * @return
 */
AVLNode*& AVLTree::getRightMostNode()
{
    AVLNode*& rightmost_node = this->getRoot();
    while (rightmost_node->getRight() != nullptr)
    {
        rightmost_node = rightmost_node->getRightRef();
    }
    return rightmost_node;
}
/**
 *
 * @return
 */
AVLNode*& AVLTree::getLeftMostNode()
{
    AVLNode*& leftmost_node = this->getRoot();
    while (leftmost_node->getLeft() != nullptr)
    {
        leftmost_node = leftmost_node->getLeftRef();
    }
    return leftmost_node;
}
std::vector<AVLNode*>& AVLTree::getNodesRightFirst()
{
    AVLNode*& rightmost_node = this->getRightMostNode();
    auto nodes = new std::vector<AVLNode*>();
    nodes = this->getNodesRightFirstRecursion(rightmost_node, nodes);
    return *nodes;
}
std::vector<AVLNode*>*& AVLTree::getNodesRightFirstRecursion(AVLNode* current, std::vector<AVLNode*>*& nodes)
{
    if (!current->isLeaf())
    {
        AVLNode* right = current->getRight();
        if (right != nullptr)
        {
            nodes->push_back(right);
            nodes = this->getNodesRightFirstRecursion(current, nodes);
        }
        AVLNode* left = current->getLeft();
        if (left != nullptr)
        {
            nodes->push_back(left);
            nodes = this->getNodesRightFirstRecursion(current, nodes);
        }
    }
    return nodes;
}

bool AVLTree::recursivePrintNode(AVLNode* current)
{
    if (!current->isLeaf())
    {
        AVLNode* left = current->getLeft();
        if (left != nullptr)
        {
            this->recursivePrintNode(left);
        }
        AVLNode* right = current->getRight();
        if (right != nullptr)
        {
            this->recursivePrintNode(right);
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
        remove(this->getRoot(), smallestInRight->getKey()); // delete this one

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
void AVLTree::balanceNode(AVLNode *&node)
{
    int node_balance = node->getBalance();
    if (node_balance > 1)
    {
        if (node->isRight())
        {
            this->leftRightRotation(node);
        }
        else if (node->isLeft())
        {
            this->leftLeftRotation(node);
        }
        else
        {

        }
    }
    if (node_balance < -1)
    {
        if (node->isRight())
        {
            this->rightRightRotation(node);
        }
        else if (node->isLeft())
        {
            this->rightLeftRotation(node);
        }
        else
        {

        }
    }
}

/**
 *
 *          y                         x
 *         / \                       / \
 *        x   T3     ----->         T1  y
 *      / \                            / \
 *     T1  T2                         T2  T3
 *
 * @param node
 */
void AVLTree::rightRotate(AVLNode*& y_node)
{
    AVLNode*& x_node = y_node->getLeftRef();
    AVLNode*& T1_node = x_node->getLeftRef();
    AVLNode*& T2_node = x_node->getRightRef();
    AVLNode*& T3_node = y_node->getRightRef();

    x_node->setType(y_node->getType());
    x_node->setRight(y_node);
    x_node->setLeft(T1_node);
    if (T1_node != nullptr)
    {
        T1_node->setType(NodeType::LEFT);
    }
    y_node->setLeft(T2_node);
    if (T2_node != nullptr)
    {
        T2_node->setType(NodeType::LEFT);
    }
    y_node->setRight(T3_node);
    if (T3_node != nullptr)
    {
        T3_node->setType(NodeType::RIGHT);
    }
    y_node->setType(NodeType::RIGHT);


    x_node->setLeft(T1_node);
    if (T1_node != nullptr)
    {
        T1_node->setType(NodeType::LEFT);
    }
    x_node->setType(y_node->getType());

    x_node->recalculateHeight();
    y_node->recalculateHeight();
}

/**
 *
 * @param node
 */
void AVLTree::leftRotate(AVLNode*& y_node)
{
    AVLNode*& x_node = y_node->getLeftRef();
    AVLNode*& T1_node = x_node->getLeftRef();
    AVLNode*& T2_node = x_node->getRightRef();
    AVLNode*& T3_node = y_node->getRightRef();

    x_node->setType(y_node->getType());
    x_node->setRight(y_node);
    x_node->setLeft(T1_node);
    if (T1_node != nullptr)
    {
        T1_node->setType(NodeType::LEFT);
    }
    y_node->setLeft(T2_node);
    if (T2_node != nullptr)
    {
        T2_node->setType(NodeType::LEFT);
    }
    y_node->setRight(T3_node);
    if (T3_node != nullptr)
    {
        T3_node->setType(NodeType::RIGHT);
    }
    y_node->setType(NodeType::RIGHT);


    x_node->setLeft(T1_node);
    if (T1_node != nullptr)
    {
        T1_node->setType(NodeType::LEFT);
    }
    x_node->setType(y_node->getType());

    x_node->recalculateHeight();
    y_node->recalculateHeight();
}

/**
 *
 *
 * @param node
 */
void AVLTree::leftLeftRotation(AVLNode *& y_node)
{
    this->rightRotate(y_node);
}

/**
 *
 * @param node
 */
void AVLTree::rightRightRotation(AVLNode *&node)
{

}

/**
 *
 * @param node
 */
void AVLTree::leftRightRotation(AVLNode *&node)
{

}

/**
 *
 * @param node
 */
void AVLTree::rightLeftRotation(AVLNode *&node)
{

}