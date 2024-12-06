//kian cloutier - prog71990 - group 4 project - fall24

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void Add(PNODE* list, EVENT event) {
	PNODE newNode = (PNODE)malloc(sizeof(NODE));
	if (!newNode) {
		fprintf(stderr, "Error allocating memory for node\n");
		exit(EXIT_FAILURE);
	}

	newNode->data = event;
	newNode->next = *list;
	*list = newNode;
	printf("Event added");
}

void Remove(PNODE* list, EVENT event) {
    PNODE current = *list;

    if (current && CompareEvents(&current->data, &event)) {
        *list = current->next;
        free(current);
        printf("Event removed successfully.\n");
        return;
    }

    PNODE prev = NULL;
    while (current && !CompareEvents(&current->data, &event)) {
        prev = current;
        current = current->next;
    }

    if (!current || !prev) {
        printf("Event not found\n");
        return;
    } else {
        prev->next = current->next;
        free(current);
    }


    printf("Event removed\n");
}

void Print(PNODE* list, EVENT event){
    PNODE current = *list;
    if (current && CompareEvents(&current->data, &event)) {
       printf("%s", event.title);
    }
}