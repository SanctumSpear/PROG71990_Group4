#include "event.h"
#include "utils.h"
#include <stdio.h>

void CreateEvent() {
	EVENT newEvent;

	printf("Enter event title: ");
	ClearInputBuffer();
	fgets(newEvent.title, MAX_FIELD_LENGTH, stdin);
	newEvent.title[strcspn(newEvent.title, "\n")] = 0;

}