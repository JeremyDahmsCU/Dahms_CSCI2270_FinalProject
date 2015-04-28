#include "Manipulator.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

Manipulator::Manipulator()
{
    node * root = NULL;
}

Manipulator::~Manipulator()
{
    //dtor
}
/*
Function prototype:
int Manipulator::getS();

Function description:
This function returns the size of the vector by called the size() function and returning the value of it.

Example:
Manipulator m;
m.getS();

Pre-conditions: None
Post-conditions: returns size of vector
*/
int Manipulator::getS()
{
    return (numbers.size());
}

/*
Function prototype:
void Manipulator::printNumbers();

Function description:
This function prints the numbers stored in the vector in order.

Example:
Manipulator m;
m.printNumbers();

Pre-conditions: numbers.size() > 0
Post-conditions: prints numbers in order of how they are in the vector
*/
void Manipulator::printNumbers()
{
    cout<<"These are you numbers:"<<endl;
    for(int i = 0; i < numbers.size(); i++)
    {
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
}

/*
Function prototype:
void Manipulator::addNumber(string numb);

Function description:
This function adds a number to the vector by converting it from a string to an integer and adding it.

Example:
Manipulator m;
m.addNumber("12");

Pre-conditions: None
Post-conditions: Adds non-zero number to vector
*/
void Manipulator::addNumber(string numb)
{
    int number = atoi(numb.c_str());
    if(number != 0)
    {
        numbers.push_back(number);
    }
}

/*
Function prototype:
void Manipulator::quickSort(int l, int r);

Function description:
This function sorts the numbers vector with quick sort.

Example:
Manipulator m;
m.quickSort(0, m.getS()-1);

Pre-conditions: numbers.size() > 0
Post-conditions: Vector is put in numerical order
*/
void Manipulator::quickSort(int l, int r)
{
    int i = l;
    int j = r;
    int tmp;
    int pivot = numbers[(l+r)/2];
    while(i<=j)
    {
        while(numbers[i] < pivot)
        {
            i++;
        }
        while(numbers[j] > pivot)
        {
            j--;
        }
        if(i<=j)
        {
            tmp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = tmp;
            i++;
            j--;
        }
    }
    if(l < j)
    {
        quickSort(l, j);
    }
    if(i < r)
    {
        quickSort(i, r);
    }
}

/*
Function prototype:
void Manipulator::bubbleSort();

Function description:
This function sorts the numbers vector with bubble sort.

Example:
Manipulator m;
m.bubbleSort();

Pre-conditions: numbers.size() > 0
Post-conditions: Vector is put in numerical order
*/
void Manipulator::bubbleSort()
{
    int flip;
    int n = numbers.size();
    for(int c = 0; c < n - 1; c++){
        for(int d = 0; d < n - c - 1; d++){
            if(numbers[d] > numbers[d+1]){
                flip = numbers[d];
                numbers[d] = numbers[d+1];
                numbers[d+1] = flip;
            }
        }
    }
}

/*
Function prototype:
void Manipulator::insertionSort();

Function description:
This function sorts the numbers vector with insertion sort.

Example:
Manipulator m;
m.insertionSort();

Pre-conditions: numbers.size() > 0
Post-conditions: Vector is put in numerical order
*/
void Manipulator::insertionSort()
{
    int index, j;
    int vectorSize = numbers.size();
    for(int i = 1; i < vectorSize; i++){
        index = numbers[i];
        j = i;
        while((j > 0) && (numbers[j - 1] > index)){
            numbers[j] = numbers[j - 1];
            j = j - 1;
        }
        numbers[j] = index;
    }
}

/*
Function prototype:
void Manipulator::preOrder(node * root);

Function description:
This function prints the nodes in pre-order

Example:
Manipulator m
m.BST(4)

Pre-conditions: None
Post-conditions: Prints numbers
*/
void Manipulator::preOrder(node * root)
{
    node * x = root;
    cout<<x->key<<" ";
    if(x->left != NULL)
        preOrder(x->left);
    if(x->right != NULL)
        preOrder(x->right);
}

/*
Function prototype:
void Manipulator::inOrder(node * root);

Function description:
This function prints the nodes in in-order

Example:
Manipulator m
m.BST(5)

Pre-conditions: None
Post-conditions: Prints numbers
*/
void Manipulator::inOrder(node * root)
{
    node * x = root;
    if(x->left != NULL)
        inOrder(x->left);
    cout<<x->key<<" ";
    if(x->right != NULL)
        inOrder(x->right);
}

/*
Function prototype:
void Manipulator::postOrder(node * root);

Function description:
This function prints the nodes in post-order

Example:
Manipulator m
m.BST(6)

Pre-conditions: None
Post-conditions: Prints numbers
*/
void Manipulator::postOrder(node * root)
{
    node * x = root;
    if(x->left != NULL)
        postOrder(x->left);
    if(x->right != NULL)
        postOrder(x->right);
    cout<<x->key<<" ";
}

/*
Function prototype:
void Manipulator::BST(int selection);

Function description:
This function puts the numbers in the numbers vector into a temporary Binary Search Tree.  Then, depending on which function was called from main, it prints
the numbers in the BST in pre-order, in-order, or post-order.

Example:
Manipulator m
m.BST(6)

Pre-conditions: int selection = 4, 5, or 6
Post-conditions: Prints numbers
*/
void Manipulator::BST(int selection)
{
    node * newNode = new node;
    node * root = new node;
    root = newNode;
    root->key = numbers[numbers.size()/2];
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    for(int i = (numbers.size()/2)+1; i < numbers.size(); i++)
    {
        node * newNode = new node;
        newNode->key = numbers[i];
        node * x = root;
        node * y = NULL;

        while (x != NULL)
        {
            y = x;
            if(newNode->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        newNode->parent = y;
        if (newNode->key < y->key)
            y->left = newNode;
        else
            y->right = newNode;
    }
    for(int i = 0; i < (numbers.size()/2); i++)
    {
        node * newNode = new node;
        newNode->key = numbers[i];
        node * x = root;
        node * y = NULL;

        while (x != NULL)
        {
            y = x;
            if(newNode->key < x->key)
                x = x->left;
            else
                x = x->right;
        }
        newNode->parent = y;
        if (newNode->key < y->key)
            y->left = newNode;
        else
            y->right = newNode;
    }
    if(selection == 4)
    {
        preOrder(root);
        cout<<endl;
    }
    if(selection == 5)
    {
        inOrder(root);
        cout<<endl;
    }
    if(selection == 6)
    {
        postOrder(root);
        cout<<endl;
    }
}
