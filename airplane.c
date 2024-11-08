#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNTRY_NAME 31

// Node structure for the linked list
typedef struct PlaneNode {
    int planeID;
    char countryName[MAX_COUNTRY_NAME];
    int seatingCapacity;
    struct PlaneNode *next;
} PlaneNode;

// Function to create a new node
PlaneNode* createNode(int planeID, char* countryName, int seatingCapacity) {
    PlaneNode* newNode = (PlaneNode*)malloc(sizeof(PlaneNode));
    newNode->planeID = planeID;
    strcpy(newNode->countryName, countryName);
    newNode->seatingCapacity = seatingCapacity;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(PlaneNode** head, int planeID, char* countryName, int seatingCapacity) {
    PlaneNode* newNode = createNode(planeID, countryName, seatingCapacity);
    if (*head == NULL) {
        *head = newNode;
    } else {
        PlaneNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the list
void printList(PlaneNode* head) {
    PlaneNode* temp = head;
    while (temp != NULL) {
        printf("%d %s %d\n", temp->planeID, temp->countryName, temp->seatingCapacity);
        temp = temp->next;
    }
}

// Function to find the plane with the maximum seating capacity in the list
PlaneNode* findMaxCapacityPlane(PlaneNode* head) {
    if (head == NULL) return NULL;
    
    PlaneNode* maxPlane = head;
    PlaneNode* temp = head->next;

    while (temp != NULL) {
        if (temp->seatingCapacity > maxPlane->seatingCapacity) {
            maxPlane = temp;
        }
        temp = temp->next;
    }

    return maxPlane;
}

int main() {
    int N, planeID, seatingCapacity;
    char countryName[MAX_COUNTRY_NAME], CName[MAX_COUNTRY_NAME];

    // Linked list for planes in the second runway
    PlaneNode* secondRunway = NULL;

    int firstRunwayCount = 0, secondRunwayCount = 0;

    // Input the number of planes
    scanf("%d", &N);

    // Input plane details
    for (int i = 0; i < N; i++) {
        scanf("%d %s %d", &planeID, countryName, &seatingCapacity);
        
        // Check if the plane's destination matches CName
        if (strcmp(countryName, CName) == 0) {
            firstRunwayCount++;
        } else {
            insertEnd(&secondRunway, planeID, countryName, seatingCapacity);
            secondRunwayCount++;
        }
    }

    // Input the CName
    scanf("%s", CName);

    // Output the results
    printf("%d\n", firstRunwayCount);
    printf("%d\n", secondRunwayCount);

    // Print planes in the second runway
    printList(secondRunway);

    // Find and print the plane with the maximum seating capacity in the second runway
    if (secondRunwayCount > 0) {
        PlaneNode* maxPlane = findMaxCapacityPlane(secondRunway);
        printf("%d %s %d\n", maxPlane->planeID, maxPlane->countryName, maxPlane->seatingCapacity);
    }

    return 0;
}
