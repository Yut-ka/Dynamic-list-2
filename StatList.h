#pragma once
#include <string>
#include <iostream>

struct TList_Item {
	int inf;
	TList_Item* next;
};

struct Stack {
public:
	TList_Item* sp;
	Stack() {
		sp = NULL;
	}
};

struct Stat_List {
public:
	TList_Item* pHead;
	Stat_List() {
		pHead = new TList_Item();
		pHead->next = NULL;
	}
};

	int Push_after(Stat_List* list, int inf1, int inf2) {
		TList_Item* pCurrent = list->pHead;
		TList_Item* pTemp = new TList_Item();
		while(pCurrent != NULL) {
			if (pCurrent->inf == inf1 || list->pHead->next == NULL) {
				pTemp->next = pCurrent->next;
				pCurrent->next = pTemp;
				pTemp->inf = inf2;
				return 1;
			}
			pCurrent = pCurrent->next;
		}
		return 0;
	}
	int Push_before(Stat_List* list, int inf1, int inf2) {
		TList_Item* pCurrent = list->pHead->next;
		TList_Item* pPrev = list->pHead;
		TList_Item* pTemp = new TList_Item();
		while(pCurrent != NULL) {
			if (pCurrent->inf == inf1) {
				pTemp->next = pCurrent;
				pPrev->next = pTemp;
				pTemp->inf = inf2;
				return 1;
			}
			pPrev = pCurrent;
			pCurrent = pCurrent->next;
		}
		return 0;
	}

	std::string Delete(Stat_List* list, int inf) {
		TList_Item* pCurrent = list->pHead->next;
		TList_Item* pPrev = list->pHead;
		while(pCurrent != NULL) {
			if (pCurrent->inf == inf) {
				pPrev->next = pCurrent->next;
				delete(pCurrent);
				return "The element was deleted.";
			}
			pPrev = pCurrent;
			pCurrent = pCurrent->next;
		}
		return "The element not found.";
	}

	TList_Item* Pop(Stat_List* list, int inf) {
		TList_Item* pCurrent = list->pHead->next;
		TList_Item* pPrev = list->pHead;
		while (pCurrent != NULL) {
			if (pCurrent->inf == inf) {
				pPrev->next = pCurrent->next;
				return pCurrent;
			}
			pPrev = pCurrent;
			pCurrent = pCurrent->next;
		}
		return NULL;
	}

	void Push(Stack* stack, TList_Item* a) {
		if (a != NULL) {
			a->next = stack->sp;
			stack->sp = a;
		}
	}


	std::string Get(Stat_List* list, int inf) {
		TList_Item* pCurrent = list->pHead->next;
		int i = 1;
		while (pCurrent->next != NULL) {
			pCurrent = pCurrent->next;
			if (pCurrent->inf == inf) return "The number with inf: | " + std::to_string(pCurrent->inf)+" | has index: | " + std::to_string(i) + " |.";
			i++;
		}
		return "The number with inf : | " + std::to_string(inf)+" | not found. ";
	}

	std::string Show(Stat_List* list) {
		std::string str;
		TList_Item* pCurrent = list->pHead->next;
		while(pCurrent != NULL) {
			str += " || " + std::to_string(pCurrent->inf) + " || ";
			pCurrent = pCurrent->next;
		}
		return str;
	}

	std::string Show(Stack* stack) {
		std::string str;
		TList_Item* pCurrent = stack->sp;
		while (pCurrent != NULL) {
			str += " || " + std::to_string(pCurrent->inf) + " || ";
			pCurrent = pCurrent->next;
		}
		return str;
	}


