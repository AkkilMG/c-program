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

void insert(int m, int n) {
    if(m==1) {
        if(q1.rear==MAXSIZE) {
            printf("Queue is full.");
        } else {
            q1.item[++q1.rear]=n;
        }
    } else if(m==2) {
        if(q2.rear==MAXSIZE) {
            printf("Queue is full.");
        } else {
            q2.item[++q2.rear]=n;
        }
    } else if(m==3) {
        if(q3.rear==MAXSIZE) {
            printf("Queue is full.");
        } else {
            q3.item[++q3.rear]=n;
        }
    } else {
        if(q4.rear==MAXSIZE) {
            printf("Queue is full.");
        } else {
            q4.item[++q4.rear]=n;
        }
    }
}

int delete(queue q) {
    if(q.rear<q.front) {
        printf("Queue is empty.");
    } else {
        return q.item[q.front++];
    }
}

void display(queue q) {
    int i;
    if(q.rear<q.front) {
        printf("Queue is empty.");
    } else {
        printf("Contents of queue are ");
        for(i=q.front; i<=q.rear; i++) {
            printf("%d ", q.item[i]);
        }
    }
    printf("\n");
}

// Insertion Sort Function
void insertionSort(int array[], int n) 
{ 
    int i, element, j; 
    for (i = 1; i < n; i++) { 
        element = array[i]; 
        j = i - 1; 
        while (j >= 0 && array[j] > element) { 
            array[j + 1] = array[j]; 
            j = j - 1; 
        } 
        array[j + 1] = element; 
    } 
}
void insertionSort(int[], int);
void insert(int, int);
void display(queue);
void main() {
    
    q1.front=0,q2.front=0,q3.front=0,q4.front=0;
    q1.rear=-1,q2.rear=-1,q3.rear=-1,q4.rear=-1;

    int i, a[10];
    printf("Enter the elements(count of 10): ");
    for(i=0;i<10;i++) {
        scanf("%d",&a[i]);
    }
    insertionSort(a,10);
    for(i=0;i<10;i++) {
        if(a[i]>=0 && a[i]<10) {
            insert(1, a[i]);
        } else if (a[i]>=10 && a[i]<20){
            insert(2, a[i]);
        } else if (a[i]>=20 && a[i]<30) {
            insert(3, a[i]);
        } else if (a[i]>=30) {
            insert(4, a[i]);
        }
    }
    display(q1);
    display(q2);
    display(q3);
    display(q4);
}
