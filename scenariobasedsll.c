#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for plane information
typedef struct Plane {
    int id;
    char country[31];
    int capacity;
    struct Plane* next;
} Plane;

// Function to create a new plane node
Plane* createPlane(int id, const char* country, int capacity) {
    Plane* newPlane = (Plane*)malloc(sizeof(Plane));
    newPlane->id = id;
    strncpy(newPlane->country, country, 30);
    newPlane->country[30] = '\0'; // Ensure null-termination
    newPlane->capacity = capacity;
    newPlane->next = NULL;
    return newPlane;
}

// Function to insert a plane into the linked list
void insertPlane(Plane** head, int id, const char* country, int capacity) {
    Plane* newPlane = createPlane(id, country, capacity);
    newPlane->next = *head;
    *head = newPlane;
}

// Function to free the linked list
void freeList(Plane* head) {
    Plane* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to process planes and categorize them
void processPlanes(Plane* head, const char* cname, int* countTakeOff, int* countSecondRunway, Plane** secondRunwayHead, Plane** maxCapacityPlane) {
    Plane* current = head;
    *countTakeOff = 0;
    *countSecondRunway = 0;
    *maxCapacityPlane = NULL;
    
    while (current != NULL) {
        if (strcmp(current->country, cname) == 0) {
            (*countTakeOff)++;
        } else {
            (*countSecondRunway)++;
            insertPlane(secondRunwayHead, current->id, current->country, current->capacity);
            if (*maxCapacityPlane == NULL || current->capacity > (*maxCapacityPlane)->capacity) {
                *maxCapacityPlane = current;
            }
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(Plane* head) {
    Plane* current = head;
    while (current != NULL) {
        printf("%d %s %d\n", current->id, current->country, current->capacity);
        current = current->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    Plane* planeList = NULL;
    int id, capacity;
    char country[31];
    
    // Reading plane information
    for (int i = 0; i < N; i++) {
        scanf("%d %s %d", &id, country, &capacity);
        insertPlane(&planeList, id, country, capacity);
    }
    
    // Read the destination country name
    char cname[31];
    scanf("%s", cname);
    
    int countTakeOff, countSecondRunway;
    Plane* secondRunwayHead = NULL;
    Plane* maxCapacityPlane = NULL;
    
    // Process the planes
    processPlanes(planeList, cname, &countTakeOff, &countSecondRunway, &secondRunwayHead, &maxCapacityPlane);
    
    // Output results
    printf("%d\n", countTakeOff);
    printf("%d\n", countSecondRunway);
    printList(secondRunwayHead);
    
    if (maxCapacityPlane != NULL) {
        printf("%d %s %d\n", maxCapacityPlane->id, maxCapacityPlane->country, maxCapacityPlane->capacity);
    }
    
    // Free allocated memory
    freeList(planeList);
    freeList(secondRunwayHead);
    
    return 0;
}
