#include <iostream>
using namespace std;

struct node
{
    string nama;
    node *next;
};
node *woosh;
node *head;
node *tail;
node *helper;

int main()
{
    woosh = new node;
    woosh->nama = "abdul";
    woosh->next = NULL;
    head = woosh;
    tail = woosh;

    woosh = new node;
    woosh->nama = "Ani";
    woosh->next = NULL;
    tail->next = woosh;
    tail = woosh;

    woosh = new node;
    woosh->nama = "budi";
    woosh->next = head;
    head = woosh;

    woosh = new node;
    woosh->nama = "jhon";
    woosh->next = tail;
    head->next->next = woosh;
    tail->next = head;
    helper = head;
    do
    {
        cout << helper->nama << endl;
        helper = helper->next;
    } while (helper != head);
}