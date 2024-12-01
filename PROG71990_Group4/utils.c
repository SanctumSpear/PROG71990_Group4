//kian cloutier - prog71990 - group 4 project - fall24
#include "utils.h"
#include <stdio.h>

void ClearInputBuffer() {
	int c;
	while ((c = getchar()) != 'n' && c != EOF);
}