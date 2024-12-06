#pragma once
#include "event.h"

typedef struct node {
	EVENT data;
	struct node* next;
} NODE, * PNODE;

void Add(PNODE* list, EVENT event);

void Remove(PNODE* list, EVENT event);

PNODE SearchEvent(PNODE list, const char* title);
void Print(PNODE* list, EVENT event);

void UpdateEvent(PNODE* list, const char* title);
