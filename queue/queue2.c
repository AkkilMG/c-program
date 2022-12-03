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

int delete(int m) {
    if(m==1) {
        if(q1.rear<q1.front) {
            printf("Queue is empty.");
        } else {
            return q1.item[q1.front++];
        }
    } else if(m==2) {
        if(q2.rear<q2.front) {
            printf("Queue is empty.");
        } else {
            return q2.item[q2.front++];
        }
    } else if(m==3) {
        if(q3.rear<q3.front) {
            printf("Queue is empty.");
        } else {
            return q3.item[q3.front++];
        }
    } else {
        if(q4.rear<q4.front) {
            printf("Queue is empty.");
        } else {
            return q4.item[q4.front++];
        }
    }
}

void display(int m, queue q) {
    int i;
    if(q.rear<q.front) {
        printf("Queue is empty.");
    } else {
        if(m==1) {
            printf("Contents of queue before sorting are ");
        } else {
            printf("Contents of queue after sorting are ");
        }
        for(i=q.front; i<=q.rear; i++) {
            printf("%d ", q.item[i]);
        }
    }
    printf("\n");
}

// Insertion Sort Function
void insertionSort(int m, int n)
{ 
    int i, element, j; 
    if(m==1) {
        for (i = 1; q1.item[i]!='\0'; i++) { 
            element = q1.item[i]; 
            j = i - 1; 
            while (j >= 0 && q1.item[j] > element) { 
                q1.item[j + 1] = q1.item[j]; 
                j = j - 1; 
            } 
            q1.item[j + 1] = element; 
        } 
    } else if(m==2) {
        for (i = 1; q2.item[i]!='\0'; i++) { 
            element = q2.item[i]; 
            j = i - 1; 
            while (j >= 0 && q2.item[j] > element) { 
                q2.item[j + 1] = q2.item[j]; 
                j = j - 1; 
            } 
            q2.item[j + 1] = element; 
        } 
    } else if(m==3) {
        for (i = 1; q3.item[i]!='\0'; i++) { 
            element = q3.item[i]; 
            j = i - 1; 
            while (j >= 0 && q3.item[j] > element) { 
                q3.item[j + 1] = q3.item[j]; 
                j = j - 1; 
            } 
            q3.item[j + 1] = element; 
        } 
    } else {
        for (i = 1; q4.item[i]!='\0'; i++) { 
            element = q4.item[i]; 
            j = i - 1; 
            while (j >= 0 && q4.item[j] > element) { 
                q4.item[j + 1] = q4.item[j]; 
                j = j - 1; 
            } 
            q4.item[j + 1] = element; 
        } 
    }
}

void insertionSort(int, int);

void insert(int, int);
void display(int, queue);

void main() {
    
    q1.front=0,q2.front=0,q3.front=0,q4.front=0;
    q1.rear=-1,q2.rear=-1,q3.rear=-1,q4.rear=-1;

    int i, a[10], qu1=0, qu2=0, qu3=0, qu4=0;
    printf("Enter the elements(count of 10): ");
    for(i=0;i<10;i++) {
        scanf("%d",&a[i]);
    }
    // insertionSort(a,10);
    for(i=0;i<10;i++) {
        if(a[i]>=0 && a[i]<10) {
            insert(1, a[i]);
            qu1++;
        } else if (a[i]>=10 && a[i]<20){
            insert(2, a[i]);
            qu2++;
        } else if (a[i]>=20 && a[i]<30) {
            insert(3, a[i]);
            qu3++;
        } else if (a[i]>=30) {
            insert(4, a[i]);
            qu4++;
        }
    }
    display(1,q1);
    insertionSort(1,qu1);
    display(2,q1);
    display(1,q2);
    insertionSort(2,qu2);
    display(2,q2);
    display(1,q3);
    insertionSort(3,qu3);
    display(2,q3);
    display(1,q4);
    insertionSort(4,qu4);
    display(2,q4);
}
