#pragma once
#include "event.h"
//kian cloutier - prog71990 - group 4 project - fall24

typedef struct node {
	EVENT data;
	struct node* next;
} NODE, * PNODE;

void Add(PNODE* list, EVENT event);

void Remove(PNODE* list, EVENT event);

PNODE SearchEvent(PNODE list, const char* title);

void Print(PNODE* list, EVENT event);

void UpdateEvent(PNODE* list, const char* title);

void Destroy(PNODE* list);