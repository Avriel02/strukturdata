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
node *heplerAf;
node *helperAm;

void tampilData()
{
    if (head == NULL)
    {
        cout << "Tidak ada data dalam linked list." << endl;
    }
    else
    {
        node *heplerAf = head;
        cout << "Data linked list: ";
        while (heplerAf != NULL)
        {
            cout << heplerAf->nama << " ";
            heplerAf = heplerAf->back;
        }
        cout << endl;
    }
}

bool cariNama(string namaDicari)
{
    if (head == NULL)
    {
        return false;
    }
    else
    {
        node *helper = head;
        do
        {
            if (helper->nama == namaDicari)
            {
                return true;
            }
            helper = helper->back;
        } while (helper != head);
        return false;
    }
}

int main()
{
    // to add data when the linkedlist is empty.
    train = new node;     // to make new object or new train
    train->nama = "Afiq"; // to fill name variable with "Afiq"
    train->front = NULL;  // to make front pointer pointing to null
    train->back = NULL;   // to make back pointer pointing to null

    head = train; // to make or move head pointer pointing to train
    tail = train; // to make or move tail= pointer pointing to train

    train = new node;
    train->nama = "Ani";
    train->back = head;
    head->front = train;
    head = train;

    train = new node;
    train->nama = "Amelia";
    train->back = train;
    train->front = tail;
    tail = train;
    train->back = NULL;

    heplerAf = head; // to move or to pointing helperAf to the head
    while (heplerAf->nama != "Afiq")
    {
        heplerAf = heplerAf->back;
    }

    helperAm = heplerAf->back; // to give new label to the node in the back of searching node
    train = new node;          // make new object
    train->nama = "Asbi";      // fill name variable with asbi
    heplerAf->back = train;    // connect helperAf to train
    train->front = heplerAf;   // connect train to helperAf
    train->back = helperAm;    // connect train to helperAm
    helperAm->front = train;   // connect helperAm to train

    train = new node;     // make new object
    train->nama = "Asbi"; // fill name variable with asbi
    tail->front = train;
    head->back->back = train;
    train->back = tail;
    train->front = head->back;

    heplerAf = head; // to move or to pointing helperAf to the head
    while (helperAm != NULL && heplerAf != NULL)
    {
        if (helperAm->nama == "Cinta")
        {
            break;
        }
        heplerAf = heplerAf->back;
        helperAm = helperAm->back;
    }

    // make it circular
    tail->back = head;
    head->front = tail;

    // delete Ani from linkedlist
    node *hero;
    hero = head;
    head = head->back;
    hero->front = NULL;
    hero->back = NULL;
    tail->back = head;
    delete (hero);

    string namaCari = "Ani";
    if (cariNama(namaCari))
    {
        cout << namaCari << " ada di Linkedlist." << endl;
    }
    else
    {
        cout << namaCari << " tidak ada di linked list." << endl;
    }

    tampilData();
}