#include <iostream>
using namespace std;

struct node
{
    string nama;
    node *front;
    node *back;
};

node *train;
node *head;
node *tail;
node *helperAF;
node *helperAM;

int main()
{
    // to add data when the linked list is empty
    train = new node;     // to make new object/new train
    train->nama = "Afiq"; // to fill nama variable with "afiq"
    train->front = NULL;  // to make front pointer pointing to NULL
    train->back = NULL;   // to make back pointer pointing to NULL
    head = train;         // to move/to make head pointer pointing to train
    tail = train;         // to move/ to make tail pointer pointing to train

    train = new node;    // to make new object/new train
    train->nama = "Ani"; // to fill nama variable with "Ani"
    train->back = tail;
    tail->front = train;
    head = train;
    train->front = NULL;

    train = new node;       // to make new object/new train
    train->nama = "Amelia"; // to fill nama variable with "Ani"
    tail->back = train;
    train->front = tail;
    tail = train;
    train->back = NULL;

    train = new node;
    train->nama = "ASBI";
    tail->front = train;
    head->back->back = train;
    train->back = tail;
    train->front = head->back;

    helperAF = head;
    while (helperAF->nama != "Afiq")
    {
        helperAF = helperAF->back;
    }
    helperAM = helperAF->back;

    train = new node;
    train->nama = "ASBI";
    helperAM->front = train;
    helperAF->back = train;
    train->back = helperAM;
    train->front = helperAF;
}