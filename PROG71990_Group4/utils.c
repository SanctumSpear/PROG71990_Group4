//kian cloutier - prog71990 - group 4 project - fall24
#include "utils.h"
#include <stdio.h>

void ClearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct tm GetDateInput() {
	struct tm date = { 0 };

    printf("Enter year (YYYY): ");
    scanf_s("%d", &date.tm_year);

    printf("Enter month (1-12): ");
    scanf_s("%d", &date.tm_mon);

    printf("Enter day (1-31): ");
    scanf_s("%d", &date.tm_mday);

    ClearInputBuffer();

    return date;
}



void PrintMenu() {
    printf("\n=== Event Management System ===\n");
    printf("1. Add Event\n");
    printf("2. Delete Event\n");
    printf("3. Update Event\n");
    printf("4. Display Event\n");
    printf("5. Display All Events\n");
    printf("6. Display Events in Date Range\n");
    printf("7. Search Event\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}