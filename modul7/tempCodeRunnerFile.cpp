#include <stdio.h>
#include <stdlib.h>

// Deklarasi struct untuk node
struct Node
{
    struct Node *prev; // Pointer ke node sebelumnya, diinisialisasi NULL secara implisit
    int data;          // Data dalam node
    struct Node *next; // Pointer ke node selanjutnya, diinisialisasi NULL secara implisit
};

// Fungsi untuk membuat node baru dengan data tertentu
struct Node *createNode(int data)
{
    // Alokasi memori untuk node baru
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Inisialisasi data
    newNode->data = data;

    return newNode;
}

int main()
{
    // Contoh penggunaan
    struct Node *head = NULL; // Pointer ke node pertama (head)

    // Membuat node pertama dengan data 10
    head = createNode(10);

    // Sekarang kita memiliki linked list dengan 1 node: 10

    // Menampilkan isi linked list
    printf("Linked list: ");
    struct Node *current = head; // Pointer untuk traversing linked list dari head
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Dealokasi memori untuk node setelah digunakan
    free(head);

    return 0;
}
