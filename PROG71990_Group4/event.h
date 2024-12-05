#pragma once
#include <time.h>
#define MAX_FIELD_LENGTH 100
#define MAX_DESC_LENGTH 250
#define MAX_EVENTS 50

typedef struct event {
	char title[MAX_FIELD_LENGTH];
	char description[MAX_DESC_LENGTH];
	struct tm date;
	int duration; // minutes
	char location[MAX_FIELD_LENGTH];
} EVENT, *PEVENT;

EVENT CreateEvent(const char* title, const char* description, struct tm date, int duration, const char* location);

int CompareEvents(PEVENT event1, PEVENT event2);