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
int qu[10];

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
        printf("Contents of queue before sorting are ");
        for(i=q->front; i<=q->rear; i++) {
            printf("%d ", q->item[i]);
        }
    }
    printf("\n");
}

// Display the temp array
void displayQ(int qu[]) {
    printf("Contents of queue after sorting are ");
    for(int i=0; qu[i]!='\0';i++) {
        printf("%d ", qu[i]);
        qu[i]='\0';
    }
    printf("\n");
}

// Insertion Sort Function
void insertionSort()
{ 
    for (int i = 1; qu[i]!='\0'; i++) { 
        int element = qu[i]; 
        int j = i - 1; 
        while (j >= 0 && qu[j] > element) { 
            qu[j + 1] = qu[j]; 
            j = j - 1; 
        } 
        qu[j + 1] = element; 
    } 
}

void insert(queue*, int);
void display(queue*);
void displayQ(int[]);
int delete(queue*);
void insertionSort();

// does most of the work
void helper(queue *q) {
    display(q);
    for(int i=0;q->item[i]!='\0';i++) {
        qu[i]=delete(q);
    }
    insertionSort(qu);
    displayQ(qu);
}

void helper(queue*);

void main() {
    
    q1.front=0,q2.front=0,q3.front=0,q4.front=0;
    q1.rear=-1,q2.rear=-1,q3.rear=-1,q4.rear=-1;

    int i, a[10];
    // input
    printf("Enter the elements(count of 10): ");
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
    helper(&q1);
    helper(&q2);
    helper(&q3);
    helper(&q4);
}
