#include <iostream>
using namespace std;

struct human
{
    human *front; // Pointer to the front human
    string nama;
    float ages;
    human *back; // Pointer to the back human
};

human *head;
human *tail;
human *helper;
human *hero;
human *student;
human *visit;
int main()
{

    student = new human;
    student->nama = "Toni";
    student->ages = 21;
    student->front = student;
    student->back = student;
    head = student;
    tail = student;

    student = new human;
    student->nama = "Runa";
    student->ages = 17;
    student->back = head;
    student->front = tail;
    head->front = student;
    tail->back = student;
    head = student;

    student = new human;
    student->nama = "Arum";
    student->ages = 19;
    student->front = tail;
    student->back = head;
    tail->back = student;
    head->front = student;
    tail = student;

    student = new human;
    student->nama = "Jack";
    student->ages = 25;
    student->back = head;
    student->front = tail;
    head->front = student;
    tail->back = student;
    head = student;

    helper = tail->front;
    student = new human;
    student->nama = "Late";
    student->ages = 23;
    student->back = tail;
    student->front = helper;
    helper->back = student;
    tail->front = student;

    student = new human;
    student->nama = "Praz";
    student->ages = 27;
    student->front = tail;
    student->back = head;
    head->front = student;
    tail->back = student;
    tail = student;

    helper = head->back;
    student = new human;
    student->nama = "Zop";
    student->ages = 30;
    student->front = head;
    student->back = helper;
    helper->front = student;
    head->back = student;

    student = new human;
    student->nama = "Jasmine";
    student->ages = 15;
    student->back = head;
    student->front = tail;
    head->front = student;
    tail->back = student;
    head = student;

    student = new human;
    student->nama = "Ivan";
    student->ages = 20;
    student->front = tail;
    student->back = head;
    head->front = student;
    tail->back = student;
    tail = student;

    helper = tail->front;
    hero = helper->front;
    tail->front = hero;
    hero->back = tail;
    helper->back = nullptr;
    helper->front = nullptr;
    delete helper;

    visit = head;
    do
    {
        cout << "Nama: " << visit->nama << ", Umur: " << visit->ages << endl;
        visit = visit->back;
    } while (visit != head);

    visit = head;
    do
    {
        human *temp = visit;
        visit = visit->back;
        delete temp;
    } while (visit != head);

    return 0;
}
