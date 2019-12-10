// newly created node follows previous node 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  char name[20];
  char phone[20];
  struct node *next;
} Node;

void showMenu(void);
void addNode(Node *target);
void delNode(Node *target);
void findNode(Node *target);
void printAll(Node *target);

int main(void)
{
  Node *head = malloc(sizeof(Node));
  head->next = NULL;
  Node *curr = head->next;

  while(1){
    showMenu();
    int item=0;
    printf("Choose the item: "); scanf("%d", &item);
    
    switch(item){
      case 1:
        addNode(head); break;
      case 2:
        delNode(head); break;
      case 3:
        findNode(head); break;
      case 4:
        printAll(head); break;
      case 5:
        while(curr != NULL){
          Node *next = curr->next;
          free(curr);
          curr=next;
        }
        free(head);
        printf("\t\t Bye\n");
        return 0;
      default:
        printf("Please select item in range of 1 to 5 \n");
    }
  }

  return 0;
}

void showMenu(void){
  printf("*****MENU*****\n");
  printf("1. Insert \n");
  printf("2. Delete \n");
  printf("3. Search \n");
  printf("4. Print All \n");
  printf("5. Exit \n");
}

void addNode(Node *target){
  printf("[ INSERT ]\n");

  Node *newNode = malloc(sizeof(Node));
  newNode->next = target->next;
  printf("Input Name: "); scanf("%s", newNode->name);
  printf("Input TelNum: "); scanf("%s", newNode->phone);

  target->next = newNode;
  printf("\t\t Data Inserted\n");
}

void delNode(Node *target){
  if(target->next == NULL){
    printf("\t\t Empty\n");
    return;
  }

  printf("[ DELETE ]\n");

  char name[20];
  printf("Input name to delete: "); scanf("%s", name);
  
  Node *prev = target;
  Node *curr = target->next;

  while(curr!=NULL){
    if(!strcmp(curr->name, name)){
      prev->next = curr->next;
      free(curr);
      break;
    }
    else
      if(curr->next == NULL){
        printf("\t\t Can't find the data\n");
        return;
      }
    prev = curr;
    curr = curr->next;
  }
  printf("\t\t Data Deleted\n");
}

void findNode(Node *target){
  if(target->next == NULL){
    printf("\t\t Empty\n");
    return ;
  }

  printf("[ SEARCH ]\n");

  char name[20];
  printf("Input name to search: "); scanf("%s", name);

  Node *curr = target->next;
  while(curr != NULL){
    if(!strcmp(curr->name, name)){
      printf("Name: %s \tTelNum: %s \n", curr->name, curr->phone);
      break;
    }
    else
      if(curr->next == NULL){
        printf("\t\t Can't find the data\n");
        break;
      }
    curr = curr->next;
  }
}

void printAll(Node *target){
  if(target->next == NULL){
    printf("\t\t Empty\n");
    return;
  }
  
  printf("[ Print All ]\n");

  Node *curr = target->next;
  while(curr != NULL){
    printf("Name: %s \tTelNum: %s \n", curr->name, curr->phone);
    curr = curr->next;
  }
}

