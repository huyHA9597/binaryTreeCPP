#include <iostream>
#include "binaryTreeType.h"
#include "bSearchTreeType.h"

using namespace std;

void print(int& x);
void update(int& x);

int main(int argc ,char* argv[])
{
    bSearchTreeType<int> treeRoot;

    int num;

    cout << "Enter numers ending "
         << "with -999. " << endl;
    cin >> num;

    while (num != -999)
    {
        treeRoot.insert(num);
        cin >> num;
    }

    cout << endl
         << "Tree nodes in inorder: ";
    treeRoot.inorderTraversal(print);
    cout << endl << "Tree height: "
         << treeRoot.treeHeight()
         << endl << endl;

    cout << "***************** Update nodes ************" << endl;
    treeRoot.inorderTraversal(update);
    cout << "Tree nodes in inorder "
         << "after the update: " << endl
         << "       ";
    treeRoot.inorderTraversal(print);
    cout << endl << "Tree Height: "
         << treeRoot.treeHeight() << endl;

    return 0;
}

void print(int& x)
{
    cout << x << " ";
}

void update(int& x)
{
    x = 2 * x;
}