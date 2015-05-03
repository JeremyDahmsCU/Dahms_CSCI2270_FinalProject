#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Manipulator.h"

using namespace std;

void displayMenu()
{
    cout<<"===Main Menu======"<<endl;
    cout<<"1. Quick sort"<<endl;
    cout<<"2. Insertion sort"<<endl;
    cout<<"3. Bubble sort"<<endl;
    cout<<"4. BST Pre-order"<<endl;
    cout<<"5. BST In-order"<<endl;
    cout<<"6. BST Post-order"<<endl;
    cout<<"7. Randomize Vector"<<endl;
    cout<<"8. Quit" << endl;
    cout<<"=================="<<endl;
    cout<<endl;
}

int main()
{
    Manipulator m;
    cout<<"Enter number, press enter, enter another number or type 'q'"<<endl;
    string input;
    cin>>input;
    while(input != "q")
    {
        m.addNumber(input);
        cin>>input;
    }

    m.printNumbers();
    cout<<"You can now manipulate these numbers with the following menu."<<endl;

    displayMenu();
    int in;
    cin>>in;
    cout<<endl;
    while(in != 8 && m.getS() > 0)
    {
        if(in == 1)
        {
            m.quickSort(0, m.getS()-1);
            m.printNumbers();
        }
        else if(in == 2)
        {
            m.insertionSort();
            m.printNumbers();
        }
        else if(in == 3)
        {
            m.bubbleSort();
            m.printNumbers();
        }
        else if(in == 4)
        {
            m.BST(in);
        }
        else if(in == 5)
        {
            m.BST(in);
        }
        else if(in == 6)
        {
            m.BST(in);
        }
        else if (in == 7)
        {
            m.randomizeVector();
            m.printNumbers();
        }
        else
        {
            cout<<"Not a valid input"<<endl;
        }
        cout<<endl;
        displayMenu();
        cin>>in;
        cout<<endl;
    }
    if(m.getS() == 0)
    {
        cout<<"There were no numbers to work with. Goodbye"<<endl;
    }
    else
    {
        cout<<"Goodbye"<<endl;
    }
    return 0;
}
