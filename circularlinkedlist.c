#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int rollno;
    char name[30];
    struct student *next;
};
typedef struct student *Node;

Node getnode() {
    return (Node)malloc(sizeof(struct student));
}

void readinfo(Node p) {
    printf("Enter details (Roll number and Name): ");
    scanf("%d %s", &p->rollno, p->name);
}

void displayinfo(Node p) {
    printf("%d %s\n", p->rollno, p->name);
}

// Create list to the right (circular linked list)
Node createright(int n) {
    int i;
    Node first = NULL, nw, prev = NULL;

    for (i = 1; i <= n; i++) {
        nw = getnode();
        readinfo(nw);
        if (first == NULL) {
            first = nw;
        } else {
            prev->next = nw;
        }
        prev = nw;
    }
    if (prev != NULL) {
        prev->next = first;
    }
    return first;
}

// Create list to the left (circular linked list)
Node createLEFT(int n) {
    int i;
    Node first = NULL, nw, last = NULL;

    for (i = 1; i <= n; i++) {
        nw = getnode();
        readinfo(nw);
        if (first == NULL) {
            last = nw;
            nw->next = nw;
        } else {
            nw->next = first;
            last->next = nw;
        }
        first = nw;
    }
    return first;
}

// INSERT FRONT
Node Insertfront(Node first) {
    Node nw, last;
    nw = getnode();
    readinfo(nw);
    if (first == NULL) {
        first = nw->next = nw;
    } else {
        nw->next = first;
        for (last = first; last->next != first; last = last->next);
        last->next = nw;
        first = nw;
    }
    return nw;
}

// INSERT REAR
Node Insertrear(Node first) {
    Node nw, last;
    nw = getnode();
    readinfo(nw);
    if (first == NULL) {
        first = nw->next = nw;
    } else {
        nw->next = first;
        for (last = first; last->next != first; last = last->next);
        last->next = nw;
    }
    return nw;
}

// INSERT AT ANY POSITION
Node InsertatanyPosition(Node first, int pos) {
    int i;
    Node prev, curr, nw;
    nw = getnode();
    readinfo(nw);

    for (prev = NULL, curr = first, i = 1; i < pos && curr->next != first; prev = curr, curr = curr->next, i++);
    if (i == 1) {
        nw->next = first;
        for (; curr->next != first; curr = curr->next);
        curr->next = nw;
        return nw;
    }
    nw->next = curr->next;
    curr->next = nw;
    return first;
}

// INSERT AFTER A GIVEN NODE
Node insertafteranode(Node first, int pos) {
    Node nw, cur;
    int i;

    nw = getnode();
    readinfo(nw);
    if (first == NULL) {
        first = nw->next = nw;
    } else {
        cur = first;
        for (i = 1; i < pos && cur->next != first; i++) {
            cur = cur->next;
        }
        nw->next = cur->next;
        cur->next = nw;
    }
    return first;
}

// INSERT BEFORE A GIVEN NODE
Node insertbeforeanode(Node first, int pos) {
    Node nw, cur, prev = NULL;
    int i;

    nw = getnode();
    readinfo(nw);

    if (first == NULL) {
        first = nw->next = nw;
    } else if (pos == 1) {
        cur = first;
        while (cur->next != first) {
            cur = cur->next;
        }
        nw->next = first;
        cur->next = nw;
        first = nw;
    } else {
        cur = first;
        for (i = 1; i < pos - 1 && cur->next != first; i++) {
            cur = cur->next;
        }
        nw->next = cur->next;
        cur->next = nw;
    }
    return first;
}

// DELETE FRONT
Node deletefrontcsll(Node first) {
    Node cur, last;
    if (first == NULL) {
        printf("\n List is empty");
        return first;
    } else if (first == first->next) {
        free(first);
        return NULL;
    } else {
        cur = first;
        for (last = first; last->next != first; last = last->next);
        first = first->next;
        last->next = first;
        free(cur);
    }
    return first;
}

// DELETE REAR
Node deleterearcsll(Node first) {
    Node cur, prev;
    if (first == NULL) {
        printf("\n List is empty");
        return first;
    } else if (first == first->next) {
        free(first);
        return NULL;
    } else {
        cur = first;
        for (prev = NULL; cur->next != first; prev = cur, cur = cur->next);
        prev->next = first;
        free(cur);
    }
    return first;
}

// DELETE AT ANY POSITION
Node deleteatAnyPosCLL(Node first, int pos) {
    Node curr = first, prev, last;
    int i;

    if (first == NULL) {
        printf("List is empty");
        return NULL;
    } else {
        for (last = first; last->next != first; last = last->next);
        for (curr = first, prev = NULL, i = 1; curr->next != first && i < pos; i++, prev = curr, curr = curr->next);
        printf("Deleting node is: ");
        displayinfo(curr);

        if (curr == curr->next) return NULL;

        if (pos == 1 && curr != curr->next) {
            first = first->next;
            last->next = first;
            free(curr);
            return first;
        }
        if (curr == last) {
            prev->next = first;
            free(curr);
            return first;
        } else {
            prev->next = curr->next;
            free(curr);
            return first;
        }
    }
}

// SEARCHING
Node searchonRollno(Node first, int rno) {
    Node curr;
    if (first == NULL) {
        printf("List is empty");
    } else {
        for (curr = first; curr->next != first && curr->rollno != rno; curr = curr->next);
        if (curr->rollno != rno) {
            printf("\n Node with roll number %d is not found", rno);
        } else {
            printf("\n Node with roll number %d is found", rno);
        }
    }
    return first;
}

// SORTING
Node sortSLL(Node first) {
    Node i, j;
    int rno;
    char nm[20];
    for (i = first; i->next != first; i = i->next) {
        for (j = first; j->next != first; j = j->next) {
            if (j->rollno > j->next->rollno) {
                rno = j->rollno;
                strcpy(nm, j->name);

                j->rollno = j->next->rollno;
                strcpy(j->name, j->next->name);

                j->next->rollno = rno;
                strcpy(j->next->name, nm);
            }
        }
    }
    return first;
}

void displayall(Node first) {
    if (first == NULL) {
        printf("\nList is empty\n");
        return;
    }
    Node curr = first;
    do {
        displayinfo(curr);
        curr = curr->next;
    } while (curr != first);
}

int main() {
    int ch, ch2, ch1, ch3;
    int pos;
    char nm[20];
    int N;
    Node first = NULL;
    do {
        printf("\n ENTER THE OPERATION TO PERFORM \n");
        printf("1] CREATE LIST \t 2]INSERTION \t 3] DELETION \t 4]SEARCHING \t 5]SORTING \t 6]DISPLAY ALL \t 7]EXIT \n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("1] CREATE LIST RIGHT \t 2] CREATE LIST LEFT \n");
                scanf("%d", &ch1);
                printf("Enter number of nodes: ");
                scanf("%d", &N);
                switch (ch1) {
                    case 1:
                        printf("\nCreating list at right\n");
                        first = createright(N);
                        break;
                    case 2:
                        printf("\nCreating list at left\n");
                        first = createLEFT(N);
                        break;
                }
                break;
            case 2:
                printf("1] INSERT FRONT \t 2] INSERT REAR \t 3] INSERT AT ANY POSITION \t 4] INSERT AFTER A GIVEN NODE \t 5] INSERT BEFORE A GIVEN NODE\n");
                scanf("%d", &ch2);
                switch (ch2) {
                    case 1:
                        printf("\nInserting front\n");
                        first = Insertfront(first);
                        break;
                    case 2:
                        printf("\nInserting rear\n");
                        first = Insertrear(first);
                        break;
                    case 3:
                        printf("Enter the position of insertion: ");
                        scanf("%d", &pos);
                        first = InsertatanyPosition(first, pos);
                        break;
                    case 4:
                        printf("Enter the position to insert after\n");
                        scanf("%d", &pos);
                        first = insertafteranode(first, pos);
                        break;
                    case 5:
                        printf("Enter the position to insert before\n");
                        scanf("%d", &pos);
                        first = insertbeforeanode(first, pos);
                        break;
                }
                break;
            case 3:
                printf("1] DELETE FRONT \t 2] DELETE REAR \t 3] DELETE AT ANY POSITION \n");
                scanf("%d", &ch2);
                switch (ch2) {
                    case 1:
                        printf("\nDeleting front\n");
                        first = deletefrontcsll(first);
                        break;
                    case 2:
                        printf("\nDeleting rear\n");
                        first = deleterearcsll(first);
                        break;
                    case 3:
                        printf("Enter the position to delete: ");
                        scanf("%d", &pos);
                        first = deleteatAnyPosCLL(first, pos);
                        break;
                }
                break;
            case 4:
                printf("\nSEARCHING NAME BASED ON ROLL NUMBER\n");
                int rno;
                printf("Enter the roll number to search for: ");
                scanf("%d", &rno);
                first = searchonRollno(first, rno);
                break;
            case 5:
                printf("\nSORTING\n");
                sortSLL(first);
                break;
            case 6:
                printf("\nDisplay all\n");
                displayall(first);
                break;
            case 7:
                break;
        }
    } while (ch != 7);
}
