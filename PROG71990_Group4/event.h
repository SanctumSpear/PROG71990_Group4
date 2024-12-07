#pragma once
//kian cloutier - prog71990 - group 4 project - fall24

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

EVENT CreateEvent();

int CompareEvents(PEVENT event1, PEVENT event2);

void PrintEvent(PEVENT event);