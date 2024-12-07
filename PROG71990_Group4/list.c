//kian cloutier && ali sheppard - prog71990 - group 4 project - fall24
#define _CRT_SECURE_NO_WARNINGS

#include "event.h"
#include "list.h"
#include "utils.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


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
    struct tm newDate = { 0 };
    int newDuration;
    char newLocation[MAX_FIELD_LENGTH];

    printf("Enter new title (or press enter to skip): ");
    scanf_s("%s", newTitle, MAX_FIELD_LENGTH);
    ClearInputBuffer();

    printf("Enter new description (or press enter to skip): ");
    scanf_s("%s", newDesc, MAX_DESC_LENGTH);
    ClearInputBuffer();

    printf("Enter new time (or press enter to skip): ");
    newDate = GetDateInput();

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

    if (newLocation[0] != '\0')
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
    printf("Event added\n");
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

void Print(PNODE* list, PEVENT event){
    PNODE current = *list;

    while (current && !CompareEvents(&current->data, &event)) {
        current = current->next;
    if (current && CompareEvents(&current->data, &event)) {
        PrintEvent;
    }
    }
}

void PrintAll(PNODE list) {
    if (!list) {
        printf("No events to display\n");
        return;
    }
    PNODE current = list;
    int count = 0;
    printf("--------------------------\n");
    while (current) {
        PrintEvent(&current->data);
        printf("--------------------------\n");
        current = current->next;
        count++;
    }
    printf("Total events: %d\n", count);
}

void PrintRange() {

}

void Destroy(PNODE* list) {
    if (!list) {
        return;
    }

    PNODE current = *list;

    while (current) {
        PNODE tmp = current;
        current = current->next;
        free(tmp);
    }

    *list = NULL;
}

int SaveData(PNODE list) {
    FILE* data = fopen(FILENAME, "wb");

    if (!data) {
        fprintf(stderr, "Error saving to file");
        return 0;
    }
    
    PNODE current = list;
    if (!current)
        return 0;

    while (current) {
        fwrite(&current->data, sizeof(EVENT), 1, data);
        current = current->next;
    }

    fclose(data);
    printf("Saved to file succesfully\n");
    return 1;
}

PNODE LoadData() {
    FILE* data = fopen(FILENAME, "rb");
    PNODE list = NULL;

    if (!data) {
        fprintf(stderr, "Error loading from file");
        return NULL;
    }

    EVENT temp;
    while (fread(&temp, sizeof(EVENT), 1, data)) {
        Add(&list, temp);
    }

    fclose(data);
    printf("Loaded from file succesfully\n");
    return list;
}