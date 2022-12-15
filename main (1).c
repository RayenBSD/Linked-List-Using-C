#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int value;
  struct Node *next;
}Node;

Node *head = NULL;

// Linked List
void addNodeToStart(int);
void addNodeToEnd(int);
void deleteNodeFromStart();
void deleteNodeFromEnd();
void addNodeToStartByPosition(int, int);
void deleteNodeFromEndByPosition(int);
void printLinkedListFromTheStart(Node *);
void printLinkedListFromTheEnd(Node *);

//Menu
void menu(int*);

int main () {

  int choice = 0, value = 0, position = 0;
  
  while (true) {
    menu(&choice);

    switch(choice) {
      case 1:
      case 2:
      case 5:
        printf("Enter your value: "), scanf("%d", &value);
    }

    switch (choice) {
      case 5:
      case 6:
        printf("Enter your position: "), scanf("%d", &position);
    }

    switch (choice) {
      case 0:
        exit(0);
      case 1:
        addNodeToStart(value);
      break;
      case 2:
        addNodeToEnd(value);
      break;
      case 3:
        deleteNodeFromStart();
      break;
      case 4:
        deleteNodeFromEnd();
      break;
      case 5:
        addNodeToStartByPosition(value, position);
      break;
      case 6:
        deleteNodeFromEndByPosition(position);
      break;
      case 7: {
        Node *current = head;
        printLinkedListFromTheStart(current);
        printf("\n");
      } break;
      case 8: {
        Node *current = head;
        printLinkedListFromTheEnd(current);
        printf("\n");
      } break;
      default:
        printf("Wrong choice");
    }
  }
  
  return 0;
}

void menu(int *choice) {
  do {
    printf("0.Exit\n");
    printf("1.Add new node in the head\n");
    printf("2.Add new node in the tail\n");
    printf("3.Delete node in the head\n");
    printf("4.Delete node in the tail\n");
    printf("5.Add new node by position\n");
    printf("6.Delete node by position\n");
    printf("7.print the linked list from the start\n");
    printf("8.print the linked list from the end\n");

    printf("> "), scanf("%d", choice);
  } while (!(*choice >= 0 && *choice < 9));
}

void addNodeToStart (int v) {
  Node *newNode = (Node *) malloc(1);

  newNode->value = v;
  newNode->next = NULL;
  
  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *current = head;
  head = newNode;

  head->next = current;
}

void addNodeToEnd(int v) {
  Node *newNode = (Node *) malloc(1);

  newNode->value = v;
  newNode->next = NULL;
  
  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *current = head;
  
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
}

void deleteNodeFromStart() {
  if (head == NULL) {
    printf("Your linked list is Empty\n");
    return;
  }
  
  Node *current = head;

  head = head->next;
  free(current);
}

void deleteNodeFromEnd() {
  if (head == NULL) {
    printf("Your linked list is Empty\n");
    return;
  }

  Node *current, *prev;
  current = prev = head;

  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }

  free(current);
  prev->next = NULL;
}

void addNodeToStartByPosition(int v, int p) {
  Node *newNode = (Node *) malloc(1);

  newNode->value = v;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *current = head;
  
  while (--p) {
    if (current == NULL) {
      printf("Your linked list is short\n");
      return;
    }
    current = current->next;
  }

  newNode->next = current->next;
  current->next = newNode;
  
}

void deleteNodeFromEndByPosition(int p) {
  if (head == NULL) {
    printf("Your linked list is Empty");
    return;
  }

  Node *current, *prev;
  current = prev = head;

  while (--p) {
    if (current == NULL) {
      printf("Your linked list is short\n");
      return;
    }
    prev = current;
    current = current->next;
  }

  if (current == head) {
    head = head->next;
    free(current);
    return;
  }

  prev->next = current->next;
  free(current);
}

void printLinkedListFromTheStart(Node *current) {
  if (current == NULL) return;

  printf("%d ", current->value);

  printLinkedListFromTheStart(current->next);
}

void printLinkedListFromTheEnd(Node *current) {
  if (current == NULL) return;

  printLinkedListFromTheEnd(current->next);
  
  printf("%d ", current->value);
}