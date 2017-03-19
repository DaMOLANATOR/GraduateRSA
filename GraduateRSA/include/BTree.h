#ifndef BTREE_H
#define BTREE_H

#define "BTreeNode.h"

class BTree
{
    public:
        BTree()
        {
            root = new BTreeNode();
        }

        BTree(DataType data)
        {
            root = new BTreeNode(data);
        }
        virtual ~BTree();

        BTreeNode* getRoot()
        {
            return root;
        }

        void setRoot(BTreeNode *_root)
        {
            root = _root;
        }

        void build(DataType[] data);
        void insert(BTreeNode* child, BTreeNode* root);
        void insertAsLeft(BTreeNode* child, BTreeNode *root);
        void insertAsRight(BTreeNode* child, BTreeNode *root);

    private:
        BTreeNode *root;
};

#endif // BTREE_H
