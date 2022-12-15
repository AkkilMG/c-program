/**
 * Design and Implement an program in c to categorise the data. Consider the following same list of data.
 * Categorise and sort them into different groups as mentioned below.
 * 
 * Group 1: Less than 10
 * Group 2: Between 10 & 19
 * Group 3: Between 20 & 29
 * Group 4: 30 & greater
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct {
    int front, rear;
    int item[MAXSIZE];
} queue;

queue q1, q2, q3, q4;
int a[10], no=0, no2=0;

// Insert
void insert(queue *q, int n) {
    if(q->rear==MAXSIZE) {
        printf("Queue is full.");
    } else {
        q->item[++q->rear]=n;
    }
}

// Delete
int delete(queue *q) {
    if(q->rear<q->front)
        printf("Queue is empty.");
    else
        return q->item[q->front++];
}

// Display from queue
void display(queue *q) {
    int i;
    if(q->rear<q->front) {
        printf("Queue is empty.");
    } else {
        no++;
        printf("Group %d: Contents of queue%d are ", no,no);
        for(i=q->front; i<=q->rear; i++) {
            printf("%d ", q->item[i]);
        }
    }
    printf("\n");
}

// Display the temp array
void displayQ(int a[]) {
    no2++;
    printf("Group %d: Contents of sorted array are ", no2);
    for(int i=0; a[i]!='\0';i++) {
        printf("%d ", a[i]);
        a[i]='\0';
    }
    printf("\n");
}

// Insertion Sort Function
void insertionSort()
{ 
    for (int i = 1; a[i]!='\0'; i++) { 
        int element = a[i]; 
        int j = i - 1; 
        while (j >= 0 && a[j] > element) { 
            a[j + 1] = a[j]; 
            j = j - 1; 
        } 
        a[j + 1] = element; 
    } 
}

void insert(queue*, int);
void display(queue*);
void displayQ(int[]);
int delete(queue*);
void insertionSort();

// does most of the work
void delete_sort(queue *q) {
    for(int i=0;q->item[i]!='\0';i++) {
        a[i]=delete(q);
    }
    
    insertionSort(a);
    displayQ(a);
}

void delete_sort(queue*);

void main() {
    
    q1.front=0,q2.front=0,q3.front=0,q4.front=0;
    q1.rear=-1,q2.rear=-1,q3.rear=-1,q4.rear=-1;

    int i, a[10];
    // input
    printf("Enter the data/elements(count of 10): ");
    for(i=0;i<10;i++) {
        scanf("%d",&a[i]);
    }
    // insert with grouping
    for(i=0;i<10;i++) {
        if(a[i]>=0 && a[i]<10) {
            insert(&q1, a[i]);
        } else if (a[i]>=10 && a[i]<20){
            insert(&q2, a[i]);
        } else if (a[i]>=20 && a[i]<30) {
            insert(&q3, a[i]);
        } else if (a[i]>=30) {
            insert(&q4, a[i]);
        }
    }

    // Calling
    printf("Categorised data into different group:\n");
    display(&q1);
    display(&q2);
    display(&q3);
    display(&q4);
    printf("\nSorted data:\n");
    delete_sort(&q1);
    delete_sort(&q2);
    delete_sort(&q3);
    delete_sort(&q4);
}
