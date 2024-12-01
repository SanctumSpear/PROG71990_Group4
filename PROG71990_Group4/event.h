#pragma once
#include <time.h>
#define MAX_FIELD_LENGTH 100
#define MAX_DESC_LENGTH 250

typedef struct event {
	char title[MAX_FIELD_LENGTH];
	char description[MAX_DESC_LENGTH];
	struct tm date;
	int duration; // minutes
	char location[MAX_FIELD_LENGTH];
} EVENT;

void CreateEvent();
