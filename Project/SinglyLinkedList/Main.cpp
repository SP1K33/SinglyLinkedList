#include <iostream>
#include <algorithm>

#include "SinglyLinkedList.h"

using std::cout;
using std::endl;
using std::cin;

void Fill(SinglyLinkedList<int>& list)
{
    for (int i = 0; i < 10; ++i)
    {
        list.PushBack(rand() % 10);
    }
}

void Out(SinglyLinkedList<int>& list)
{
    cout << endl << "Size: " << list.Size() << endl;
    auto it = list.begin();
    while (it != list.end())
    {
        cout << *it << " ";
        it++;
    }
}

int main()
{
    SinglyLinkedList<int> firstList;
    Fill(firstList);

    cout << "Front: " << firstList.Front() << endl;

    cout << "Input some number: ";
    int number;
    cin >> number;
    cout << "Push back: ";
    firstList.PushBack(number);
    Out(firstList);

    cout << endl << "Push front: ";
    firstList.PushFront(number);
    Out(firstList);

    cout << endl << "Pop front: ";
    firstList.PopFront();
    Out(firstList);

    cout << endl << "Index to erase: ";
    int eraseIdx;
    cin >> eraseIdx;
    eraseIdx--;
    firstList.EraseAfter(firstList.begin() + eraseIdx);
    Out(firstList);

    cout << endl << "Index to insert: ";
    int insertIdx;
    cin >> insertIdx;
    insertIdx--;
    cout << "Input some number: ";
    cin >> number;
    firstList.InsertAfter(number, firstList.begin() + insertIdx);
    Out(firstList);

    SinglyLinkedList<int> secondList;
    Fill(secondList);
    cout << endl << "Second List: ";
    Out(secondList);

    cout << endl << "Merged frist and second list: ";
    firstList.Merge(secondList);
    Out(firstList);

    cout << endl << "Cleared first list: ";
    firstList.Clear();
    Out(firstList);

    cin.get();
    return 0;
}