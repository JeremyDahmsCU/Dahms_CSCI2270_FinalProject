#ifndef MANIPULATOR_H
#define MANIPULATOR_H
#include <vector>
#include <string>

struct node;

struct node
{
    node* left;
    node* right;
    node* parent;
    int key;
};

class Manipulator
{
    public:
        Manipulator();
        virtual ~Manipulator();
        int getS();
        void printNumbers();
        void addNumber(std::string numb);
        void quickSort(int l, int r);
        void bubbleSort();
        void insertionSort();
        void preOrder(node * root);
        void inOrder(node * root);
        void postOrder(node * root);
        void BST(int selection);
        void randomizeVector();

    protected:
    private:
        std::vector<int> numbers;
};

#endif // MANIPULATOR_H
