// Implementation of binary tree type
// !A binary tree is also a graph!
#ifndef BINARYTREETYPE_H
#define BINARYTREETYPE_H

#include <iostream>

using namespace std;

// Definition of the node
template <class elemType>
struct nodeType
{
    elemType info;                  // Store the data
    nodeType<elemType> *lLink;      // Pointer to the left child
    nodeType<elemType> *rLink;      // Pointer to the right child
};

// Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator= (const binaryTreeType<elemType>&);
    // Overload the assignment operator.

    bool isEmpty() const;
    // Function to determine whether the binary tree is empty.
    // Postcondition:   Returns ture if the binary tree isempty;
    //                  otherwise, returns false.

    void inorderTraversal() const;
    // Function to do an inorder traversal of the binary tree.
    // Postcondition: Nodes are printed in inorder sequence.

    void inorderTraversal(void (*visit) (elemType&)) const;
    //Function to do an inorder traversal of the binary tree.
    //The parameter visit, which is a function, specifies
    //the action to be taken at each node.
    //Postcondition: The action specified by the function
    // visit is applied to each node of the
    // binary tree.

    void preorderTraversal() const;
    // Function to do a preorder traversal of the binary tree.
    // Postcondition: Nodes are printed in preorder sequence.

    void postorderTraversal() const;
    // Function to do a postorder traversal of the binary tree.
    // Postcondition: Nodes are printed in postorder sequence.

    int treeHeight() const;
    // Function to determine the height of a binary tree.
    // Postcondition: Returns the height of the binary tree.

    int treeNodeCount() const;
    // Function to determine the number of nodes in a binary tree.
    // Postcondition: Returns the number of nodes in the binary tree.

    int treeLeavesCount() const;
    // Function to determine the number of leaves in a 
    // binary tree.
    // Postcondition: Returns the number of leaves in the binary tree.

    void destroyTree();
    // Function to destroy the binary tree.
    // Postcondition:   Memory space occupied by each node
    //                  is deallocated.
    //                  root = nullptr;

    virtual bool search(const elemType& searchItem) const = 0;
    // Function to determine if searchItem is in the binary
    // tree.
    // Postcondition:   Returns true if searchItem is found in
    //                  the binary tree; otherwise, returns
    //                  false.

    virtual void insert(const elemType& insertItem) = 0;
    // Function to insert insertItem in the binary tree.
    // Postcondition:   If there is no node in the binary tree
    //                  that has the same info as insertItem, a
    //                  node with the info insertItem is created
    //                  and inserted in the binary search tree.

    virtual void deleteNode(const elemType& deleteItem) = 0;
    // Function to delete deleteItem from the binary tree
    // Postcondition:   If a node with the same info as deleteItem is found, it is deleted
    //                  from the binary tree.
    //                  if the binary tree is empty of deleteItem is not in the binary tree,
    //                  an appropriate message is printed.

    binaryTreeType(const binaryTreeType<elemType>& otherTree);
    // Copy constructor

    binaryTreeType();
    // Default constructor

    ~binaryTreeType();
    // Destructor

protected:
    nodeType<elemType> *root;           // Pointer to the root node of the binary tree

private:
    void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot);
    // Makes a copy of the binary tree to which
    // otherTreeRoot points.
    // Postcondition: The pointer copiedTreeRoot points to
    //                the root of the copied binary tree.

    void destroy(nodeType<elemType>* &p);
    // Function to destroy the binary tree to which p points.
    // Postcondition: Memory space occupied by each node, in
    //                the binary tree to which p points, is
    //                deallocated.
    //                p = nullptr;

    void inorder(nodeType<elemType> *p) const;
    // Function to do an inorder traversal of the binary
    // tree to which p points.
    // Postcondition: Nodes of the binary tree, to which p
    //                points, are printed in inorder sequence.

    void inorder(nodeType<elemType> *p, void (*visit) (elemType&)) const;
    //Function to do an inorder traversal of the binary tree
    //starting at the node specified by the parameter p.
    //The parameter visit, which is a function, specifies the
    //action to be taken at each node.
    //Postcondition: The action specified by the function visit
    // is applied to each node of the binary tree
    // to which p points.

    void preorder(nodeType<elemType> *p) const;
    // Function to do a preorder traversal of the binary
    // tree to which p points.
    // Postcondition: Notes of the binary tree, to which p
    //                points are printed in preorder sequence.

    void postorder(nodeType<elemType> *p) const;
    // Function to do a postorder traversal of the binary
    // tree to which p points.
    // Postcondition: Notes of the binary tree, to which p
    //                points are printed in postorder sequence.

    int height(nodeType<elemType> *p) const;
    // Function to determine the height of the binary tree
    // to which p points.
    // Postcondition: Height of the binary tree to which
    //                p points is returned.

    int max(int x, int y) const;
    // Function to determine the larger of x and y.
    // Postcondition: Returns the larger of x and y.

    int nodeCount(nodeType<elemType> *p) const;
    // Function to determine the number of nodes in
    // the binary tree to which p points.
    // Postcondition: The number of nodes in the binary
    //                tree to which p points is returned.

    int leavesCount(nodeType<elemType> *p) const;
    // Function to determine the number of leaves in
    // the binary tree to which p points.
    // Postcondition: The number of leaves in the binary
    //                tree to which p points is returned.
};

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == nullptr);
}

// Constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = nullptr;
}

// Binary tree traversal
// The item insertion, deletion and lookup operations require
// that the binary tree be traversed.
// *******************Application*********************************
// Preorder traversal: Make a copy of a binary tree while preserving 
// the structure of the binary tree
// Postorder traversal: Delete all of the nodes of a binary tree
// Inorder traversal: Visits the nodes in sorted order in binary 
// search trees.
template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
// The binary tree is traversed as follows:
// 1. Traverse the left subtree.
// 2. Visit the node
// 3. Traverse the right subtree.
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
// The binary tree is traversed as follows:
// 1. Visit the node.
// 2. Traverse the left subtree.
// 3. Traverse the right subtree.
{
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
// The binary tree is traversed as follows:
// 1. Traverse the left subtree.
// 2. Traverse the right subtree.
// 3. Visit the node
{
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) const
// The binary tree is traversed as follows:
// 1. Traverse the left subtree.
// 2. Visit the node
// 3. Traverse the right subtree.
{
    if (p != nullptr)
    {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p) const
// The binary tree is traversed as follows:
// 1. Visit the node.
// 2. Traverse the left subtree.  
// 3. Traverse the right subtree.
{
    if (p != nullptr)
    {   
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p) const
// The binary tree is traversed as follows:
// 1. Traverse the left subtree.
// 2. Traverse the right subtree.
// 3. Visit the node
{
    if (p != nullptr)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

template <class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p) const
// Height(p) denotes the height of the binary tree with root p
// If the binary tree is empty, then the height is 0
// If tree is non-binary, first find the height of the left subtree and 
// the height of the right subtree. Then take the maximum of these two 
// heights and add 1 to find the height of the binary tree.
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
// Determine the larger of two intergers.
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class elemType>
void binaryTreeType<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot)
// To make an identical copy of a binary tree
// If we use just the value of the pointer of the root node to make 
// a copy of a binary tree, we get a shallow copy of the data.
// -> We need to create as many nodes as there are in the binary
// tree to be copied.
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;             // Copy info into the copy tree root
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);  // Copy pointer left link
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);  // Copy pointer right link
    }
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
    if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

//Destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

//Overload the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=(const binaryTreeType<elemType>& otherTree)
{
    if (this != &otherTree) //avoid self-copy
    {
        if (root != nullptr) //if the binary tree is not empty,
        //destroy the binary tree
            destroy(root);
        if (otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }//end else
    return *this;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal(void (*visit) (elemType& item)) const
{
    inorder(root, *visit);
}

template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType>* p, void (*visit) (elemType& item)) const
{
    if (p != nullptr)
    {
        inorder(p->lLink, *visit);
        (*visit)(p->info);
        inorder(p->rLink, *visit);
    }
}

#endif