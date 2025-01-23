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
    train->back = tail;  // to make back pointer to tail
    tail->front = train; // mengatur pointer front dari node tail ke train
    head = train;        // mengatur haed ke train
    train->front = NULL; // mengatur front dari node train menjadi null

    train = new node;       // to make new object/new train
    train->nama = "Amelia"; // to fill nama variable with "Ani"
    tail->back = train;     // mengatur pointer back dari node tail ke node baru train
    train->front = tail;    // mengatur front dari train ke tail
    tail = train;           // mengatur tail ke train
    train->back = NULL;     // mengatur back dari train menjadi NULL

    train = new node;          // membuat objek baru
    train->nama = "ASBI";      // mengisi variabel dengan asbi
    tail->front = train;       // mengatur front dari node tail ke train
    head->back->back = train;  // mengatur back dari head lalu ke train
    train->back = tail;        // mengatur back ke train
    train->front = head->back; // mengatur front ke node baru train lalu menunjuk ke head

    helperAF = head;
    while (helperAF->nama != "Afiq" && helperAF != NULL)
    {
        helperAF = helperAF->back;
    }
    if (helperAF != NULL && helperAF != tail)
    {
        helperAM = helperAF->back;

        tail->back = head;
        head->front = tail;

        train = new node;
        train->nama = "ASBI";
        helperAM->front = train;
        helperAF->back = train;
        train->back = helperAM;
        train->front = helperAF;
    }

    train->back = tail;
    train->front = head->back;

    node *hero;
    hero = head;
    head = head->back;
    hero->front = NULL;
    hero->back = NULL;
    tail->back = head;
    delete (hero);
}