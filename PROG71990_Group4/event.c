//kian cloutier - prog71990 - group 4 project - fall24

#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include "utils.h"
#include "time.h"
#include "list.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

EVENT CreateEvent() {
    EVENT newEvent = { 0 };
    char newTitle[MAX_FIELD_LENGTH];
    char newDesc[MAX_DESC_LENGTH];
    struct tm newDate = { 0 };
    int newDuration;
    char newLocation[MAX_FIELD_LENGTH];

    printf("Enter title (or press enter to skip): ");
    fgets(newTitle, MAX_FIELD_LENGTH, stdin);
    newTitle[strcspn(newTitle, "\n")] = 0;

    printf("Enter description (or press enter to skip): ");
    fgets(newDesc, MAX_DESC_LENGTH, stdin);
    newDesc[strcspn(newDesc, "\n")] = 0;

    printf("Enter time (or press enter to skip): ");
    newDate = GetDateInput();

    printf("Enter new duration in minutes: (or press enter to skip): ");
    scanf_s("%d", &newDuration);
    ClearInputBuffer();

    printf("Enter new location: (or press enter to skip): ");
    fgets(newLocation, MAX_FIELD_LENGTH, stdin);
    newLocation[strcspn(newLocation, "\n")] = 0;

    strcpy(newEvent.title, newTitle);
    strcpy(newEvent.description, newDesc);
    newEvent.date = newDate;
    newEvent.duration = newDuration;
    strcpy(newEvent.location, newLocation);

    return newEvent;
}

int CompareEvents(PEVENT event1, PEVENT event2) {
    return strcmp(event1->title, event2->title) == 0;
}

void PrintEvent(PEVENT event) {
    printf("Title: %s\n", event->title);
    printf("Description: %s\n", event->description);
    printf("Date: %d/%02d/%02d\n", event->date.tm_year, event->date.tm_mon, event->date.tm_mday);
    printf("Duration: %d minutes\n", event->duration);
    printf("Location: %s\n", event->location);
}

