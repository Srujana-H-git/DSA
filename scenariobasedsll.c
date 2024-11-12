/*
Consider the SGPA scored by students which are in fractional format in subject C Programming 	Problem Solving during 1st semester. Write a modular C program to perform the following operations.
	a) Create a  Singly Linked List to store SGPA of the student using Insert Front 	   operation.
	b) Display all the students SGPA on the standard output device.
	c) Count and Display SGPAs above 9.0.
	d) Make a new Singly Linked List of SGPAs less than 4.0. (Original List of grades should be present without any changes).

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SGPA {
    int rollno;
    char name[30];
    float SGPA;
    struct SGPA *next;
};

struct SGPA *getnode() {
    return (struct SGPA *)malloc(sizeof(struct SGPA));
}

void Readdata(struct SGPA *nw) {
    printf("Enter the Roll No, Name, and SGPA: \n");
    scanf("%d %s %f", &nw->rollno, nw->name, &nw->SGPA);
}

void displaydata(struct SGPA *nw) {
    printf("%d\t%s\t%f\n", nw->rollno, nw->name, nw->SGPA);
}

struct SGPA *createlistRight(int N) {
    struct SGPA *nw, *prev, *first = NULL;
    int i;
    for (i = 0; i < N; i++) {
        nw = getnode();
        Readdata(nw);
        nw->next = NULL;
        if (first == NULL) {
            first = nw;
        } else {
            prev->next = nw;
        }
        prev = nw;
    }
    return first;
}

struct SGPA *Insertfront(struct SGPA *first) {
    struct SGPA *nw = getnode();
    Readdata(nw);
    nw->next = first;
    return nw;
}

void displayall(struct SGPA *first) {
    struct SGPA *curr = first;
    if (curr == NULL) {
        printf("\nList is empty\n");
    } else {
        while (curr != NULL) {
            displaydata(curr);
            curr = curr->next;
        }
    }
}

void SGPAabove9(struct SGPA *first) {
    struct SGPA *curr = first;
    while (curr != NULL) {
        if (curr->SGPA > 9.0) {
            displaydata(curr);
        }
        curr = curr->next;
    }
}

struct SGPA *SGPAbelow4(struct SGPA *first1) {
    struct SGPA *newList = NULL, *nw, *last = NULL;
    struct SGPA *curr = first1;
    
    while (curr != NULL) {
        if (curr->SGPA < 4.0) {
            nw = getnode();
            nw->rollno = curr->rollno;
            strcpy(nw->name, curr->name);
            nw->SGPA = curr->SGPA;
            nw->next = NULL;
            
            if (newList == NULL) {
                newList = nw;
            } else {
                last->next = nw;
            }
            last = nw;
        }
        curr = curr->next;
    }
    
    return newList;
}

int main() {
    int ch, N;
    struct SGPA *first1 = NULL, *first2 = NULL, *first3 = NULL;

    printf("Enter number of nodes to create a list: ");
    scanf("%d", &N);
    first1 = createlistRight(N);

    do {
        printf("\nENTER THE OPERATION TO PERFORM:\n");
        printf("1] INSERT FRONT\n");
        printf("2] DISPLAY ALL\n");
        printf("3] DISPLAY SGPA ABOVE 9.0\n");
        printf("4] SLL FOR SGPA BELOW 4.0\n");
        printf("5] EXIT\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: 
                printf("Insert Front\n");
                first1 = Insertfront(first1);
                break;

            case 2:
                printf("Display All\n");
                displayall(first1);
                break;
            
            case 3:
                printf("Display SGPA above 9.0\n");
                SGPAabove9(first1);
                break;
            
            case 4:
                printf("SGPA below 4.0\n");
                first3 = SGPAbelow4(first1);
                displayall(first3);
                break;

            case 5:
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    } while(ch != 5);

    return 0;
}
