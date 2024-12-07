//kian cloutier - prog71990 - group 4 project - fall24

#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include "utils.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

EVENT CreateEvent(const char* title, const char* description, struct tm date, int duration, const char* location) {
    EVENT newEvent;

    strcpy(newEvent.title, title);
    strcpy(newEvent.description, description);
    newEvent.date = date;
    newEvent.duration = duration;
    strcpy(newEvent.location, location);

    return newEvent;
}

int CompareEvents(PEVENT event1, PEVENT event2) {
    return strcmp(event1->title, event2->title) == 0;
}

void PrintEvent(PEVENT event) {
    printf("Title: %s\n", event->title);
    printf("Description: %s\n", event->description);
    printf("Date: %d/%02d/%02d", event->date.tm_year + 1900, event->date.tm_mon + 1, event->date.tm_mday);
    printf("Duration: %d minutes\n", event->duration);
    printf("Location: %s\n", event->location);
}

