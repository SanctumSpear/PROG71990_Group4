//kian cloutier - prog71990 - group 4 project - fall24
#include "utils.h"
#include <stdio.h>

void ClearInputBuffer() {
	int c;
	while ((c = getchar()) != 'n' && c != EOF);
}

struct tm GetDateInput() {
	struct tm date = { 0 };

    printf("Enter year (YYYY): ");
    scanf_s("%d", &date.tm_year);
    date.tm_year -= 1900;  // years since 1900

    printf("Enter month (1-12): ");
    scanf_s("%d", &date.tm_mon);
    date.tm_mon -= 1;  // 0-based month

    printf("Enter day (1-31): ");
    scanf_s("%d", &date.tm_mday);

    ClearInputBuffer();

    return date;
}