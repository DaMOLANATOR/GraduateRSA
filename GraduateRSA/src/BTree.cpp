#include "BTree.h"


void BTree::build(DataType[] data)
{

}

void BTree::insert(BTreeNode* child, BTreeNode* root)
{
    if(child == NULL) return;
    if(child->leftChild==NULL)
    {
        insertAsLeft(child,root);
        return;
    }
    if(child->rightChild==NULL)
    {
        insertAsRight(child,root);
        return;
    }
}


void BTree::insertAsLeft(BTreeNode* child, BTreeNode *root)
{
    if(child == NULL) return;
    child->leftChild = root;
}

void insertAsRight(BTreeNode* child, BTreeNode *root)
{
    if(child == NULL) return ;
    child->rightChild = root;
}


BTree::~BTree()
{
    //dtor
}
