#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef struct node {
    char name[SIZE];
    char telNum[SIZE];
    struct node* next;
}Node;

void showMenu(void);
void addElem(Node** target);
Node* delElem(Node* target);
void findElem(Node* node);
void printAll(Node* node);

int main(void)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node* curr = head;

    while (1) {
      showMenu();

      int item=0;
      printf("Choose the item: "); scanf("%d", &item);

      switch (item) {
      case 1:
        addElem(&curr); break;
      case 2:
        curr = delElem(head); break;
      case 3:
        findElem(head->next); break; 
      case 4:
        printAll(head->next); break;
      case 5:
        curr = head->next;
        while (curr != NULL) {
            Node* next = curr->next;
            free(curr);
            curr = next;
        }
        free(head);
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

void addElem(struct node** target) {

    printf("[ INSERT ]\n");

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
      return;

    newNode->next = NULL;

    printf("Input Name: "); scanf("%s", newNode->name);
    printf("Input TelNumber: "); scanf("%s", newNode->telNum);

    (*target)->next = newNode;
    (*target) = newNode;

    printf("\t\t Data Inserted\n");
}

Node* delElem(Node* target) {
    if (target->next == NULL){
      printf("\t\t Empty\n");
      return target;
    }

    printf("[ DELETE ]\n");
    Node* prev = target; target = target->next;

    char name[SIZE];
    printf("Input a name to delete: "); scanf("%s", name);

    while (target != NULL) {
      if (!strcmp(target->name, name)) {
        if (target->next == NULL) {
          prev->next = NULL;
          free(target);
          printf("\t\t Data Deleted\n");
          return prev;
        }
        else {
          prev->next = target->next;
          free(target);
          printf("\t\t Data Deleted\n");
          break;
        }
      }
      else {
        if (target->next == NULL)
          printf("\t\t Can not find the data\n");
      }

      prev = target;
      target = target->next;
    }
}

void findElem(Node* node) {
    if (node == NULL){
      printf("\t\t Empty\n");
      return;
    }

    printf("[ SEARCH ]\n");

    char name[SIZE];
    printf("Input a name to find: "); scanf("%s", name);

    while (node != NULL) {
      if (!strcmp(node->name, name)) {
        printf("Name: %s \tTelNum: %s \n", node->name, node->telNum);
        break;
      }
      else {
        if (node->next == NULL)
          printf("\t\t Can not find the data\n");
      }

      node = node->next;
    }
}

void printAll(Node* node) {
    if (node == NULL){
      printf("\t\t Empty\n");
      return;
    }

    while (node != NULL) {
      printf("Name: %s \tTelNumber: %s \n", node->name, node->telNum);
      node = node->next;
    }
}
