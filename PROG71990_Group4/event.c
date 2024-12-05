#include "event.h"
#include "list.h"
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