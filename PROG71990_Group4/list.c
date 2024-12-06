#include "event.h"
#include "list.h"
#include "utils.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FILENAME "eventData.bin"

PNODE SearchEvent(PNODE list, const char* title) {
    PNODE current = list;
    while (current) {
        if (strcmp(current->data.title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void UpdateEvent(PNODE* list, const char* title) {
    PNODE event = SearchEvent(*list, title);
    if (!event) {
        printf("Event not found\n");
        return;
    }

    printf("Updating event: %s\n", event->data.title);

    char newTitle[MAX_FIELD_LENGTH];
    char newDesc[MAX_DESC_LENGTH];
    struct tm newDate;
    int newDuration;
    char newLocation[MAX_FIELD_LENGTH];

    printf("Enter new title (or press enter to skip): ");
    scanf_s("%s", newTitle, MAX_FIELD_LENGTH);
    ClearInputBuffer();

    printf("Enter new description (or press enter to skip): ");
    scanf_s("%s", newDesc, MAX_DESC_LENGTH);
    ClearInputBuffer();

    printf("Enter new time (or press enter to skip): ");
    GetDateInput();

    printf("Enter new duration in minutes: (or press enter to skip): ");
    scanf_s("%d", &newDuration);
    ClearInputBuffer();

    printf("Enter new location: (or press enter to skip): ");
    scanf_s("%s", newLocation, MAX_FIELD_LENGTH);
    ClearInputBuffer();

    if (newTitle[0] != '\0')
        strncpy(event->data.title, newTitle, MAX_FIELD_LENGTH - 1);

    if (newDesc[0] != '\0')
        strncpy(event->data.description, newDesc, MAX_DESC_LENGTH - 1);

    if (newDate.tm_year)
       event->data.date = newDate;

    if (newDuration)
        event->data.duration = newDuration;

    if (newLocation[0] != '\0');
    strncpy(event->data.location, newLocation, MAX_FIELD_LENGTH - 1);

    printf("event updated");
}

void Add(PNODE* list, EVENT event) {
    PNODE newNode = (PNODE)malloc(sizeof(NODE));
    if (!newNode) {
        fprintf(stderr, "Error allocating memory for node\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = event;
    newNode->next = *list;
    *list = newNode;
    printf("Event added");
}

void Remove(PNODE* list, EVENT event) {
    PNODE current = *list;

    if (current && CompareEvents(&current->data, &event)) {
        *list = current->next;
        free(current);
        printf("Event removed successfully.\n");
        return;
    }

    PNODE prev = NULL;
    while (current && !CompareEvents(&current->data, &event)) {
        prev = current;
        current = current->next;
    }

    if (!current || !prev) {
        printf("Event not found\n");
        return;
    }
    else {
        prev->next = current->next;
        free(current);
    }


    printf("Event removed\n");
}

void Print(PNODE* list, EVENT event){
    PNODE current = *list;

    while (current && !CompareEvents(&current->data, &event)) {
        current = current->next;
    if (current && CompareEvents(&current->data, &event)) {
       printf("%s", event.title);
    }
    }
}

void Destroy(PNODE* list) {
    PNODE current = *list;

    while (current) {
        PNODE tmp = current;
        current = current->next;
        free(tmp);
    }

    list = NULL;
}
