#ifndef BTREENODE_H
#define BTREENODE_H

typedef int DataType;
class BTree;

class BTreeNode
{

    friend class BTree;

    public:
        BTreeNode()
        :
            data(0),
            leftChild(NULL),
            rightChild(NULL)
        {

        }

        BTreeNode(DataType _data, BTreeNode* left=NULL, BTreeNode* right=NULL)
        :
            data(_data),
            leftChild(left),
            rightChild(right)
        {

        }
        virtual ~BTreeNode();

        DataType getData()
        {
            return data;
        }

        BTreeNode* getLeftChild()
        {
            return leftChild;
        }

        BTreeNode* getRightChild()
        {
            return rightChild;
        }

        void setData(DataType _data)
        {
            data = _data;
        }

        void setLeftChild(BTreeNode *left)
        {
            leftChild  =left;
        }

        void setRightChild(BTreeNode *right)
        {
            rightChild = right;
        }

    private:
        DataType data;
        BTreeNode *leftChild;
        BTreeNode *rightChild;
};

#endif // BTREENODE_H
