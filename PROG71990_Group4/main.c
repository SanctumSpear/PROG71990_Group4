//kian cloutier - prog71990 - group 4 project - fall24
#include <stdio.h>
#include "event.h"
#include "list.h"
#include "utils.h"
#include <stdlib.h>

int main(void) {
	
	PNODE eventList = LoadData();
	int choice;
	char title[MAX_FIELD_LENGTH];
	int result;
	PNODE searchedEvent;
	do {
		
		PrintMenu();
		scanf_s("%d", &choice);
		ClearInputBuffer();
		result = 0;
		searchedEvent = NULL;

		switch (choice) {
			case 1:
				//new event
				Add(&eventList, CreateEvent());
				break;
			case 2:
				//delete event
				printf("Enter event name to delete: ");
				result = scanf_s("%s", title, MAX_FIELD_LENGTH);
				searchedEvent = SearchEvent(eventList, title);
				if (result == 1) {
					if (searchedEvent) {
						Remove(&eventList, searchedEvent->data);
					} else {
						printf("No event found with that name\n");
					}
				} else {
					printf("Invalid input");
				}
				ClearInputBuffer();
				break;
			case 3:
				printf("Enter event name to update: ");
				result = scanf_s("%s", title, MAX_FIELD_LENGTH);
				searchedEvent = SearchEvent(eventList, title);
				if (result == 1) {
					if (searchedEvent) {
						UpdateEvent(eventList, title);
					}
					else {
						printf("No event found with that name\n");
					}
				}
				else {
					printf("Invalid input");
				}
				ClearInputBuffer();
				break;
			case 4:
				//print single event
				printf("Enter event name to print: ");
				result = scanf_s("%s", title, MAX_FIELD_LENGTH);
				searchedEvent = SearchEvent(eventList, title);
				if (result == 1) {
					if (searchedEvent) {
						//Print(eventList, title);
					}
					else {
						printf("No event found with that name\n");
					}
				}
				else {
					printf("Invalid input");
				}
				ClearInputBuffer();
				break;
			case 5:
				//print all events
				PrintAll(eventList);
				break;
			case 6:
				//display events in range
				break;
			case 7:
				//search event
				printf("Enter event name to search: ");
				result = scanf_s("%s", title, MAX_FIELD_LENGTH);
				searchedEvent = SearchEvent(eventList, title);
				if (result == 1) {
					if (searchedEvent) {
						PrintEvent(searchedEvent);
					}
					else {
						printf("No event found with that name\n");
					}
				}
				else {
					printf("Invalid input");
				}
				ClearInputBuffer();
				break;
			case 0:
				SaveData(eventList);
				Destroy(&eventList);
				exit(EXIT_SUCCESS);
				break;
			default:
				printf("Invalid choice, try again\n");
				break;
		}

	} while (1);
}