#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insert_At_any_position(struct Node** head, int tar, int data) {
    if(tar==1){
        insertAtFront(head,data);
        return;
    }
    int i=1;
    struct Node* temp=*head;
    while(temp && i++!=tar-1){
        temp=temp->next;
    }
    if(!temp){
        printf("error out of boundary\n");
        return;
    }
    struct Node* new=createNode(data);
    new->next=temp->next;
    temp->next=new;
}

void deleteAtFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    free(current);
    previous->next = NULL;
}

void delete_from_any_position(struct Node** head, int tar) {
   if(!(*head)){
        printf("list is empty \n");
        return;
   }
   if(tar==1){
        deleteAtFront(head);
        return;
   }
   int i=1;
   struct Node* current= *head,*preptr;
   preptr=*head;
   while(current && (i++)!=tar){
        preptr=current;
        current=current->next;
   }
   if(!current){
        printf("out of boundary\n");
        return;
   }
   preptr->next=current->next;
   free(current);
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, value,ch;
    struct Node* nodeToInsertAfter = NULL;
    struct Node* nodeToDeleteAfter = NULL;
    int isListCreated = 0;  // Flag to track list creation
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Insert at a particular position\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete at a particular position\n");
        printf("8. Display the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("creating a new List\n");
                head = NULL;
                while(1){
                    printf("Enter the data:");
                    scanf("%d",&data);
                    insertAtEnd(&head,data);
                    isListCreated = 1;  
                    printf("To continue press 1 and to stop press 0:\n");
                    scanf("%d",&ch);
                    if(ch!=1)
                        break;
                }
                break;
            case 2:
                if (!isListCreated) {
                    printf("List does not exist. Create a list first.\n");
                    break;
                }
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 3:
                if (!isListCreated) {
                    printf("List does not exist. Create a list first.\n");
                    break;
                }
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                if (!isListCreated) {
                    printf("List does not exist. Create a list first.\n");
                    break;
                }
                printf("Enter the position: ");
                scanf("%d", &value);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_At_any_position(&head, value, data);
                break;
            case 5:
                if (!isListCreated) {
                    printf("List does not exist. Create a list first.\n");
                    break;
                }
                deleteAtFront(&head);
                break;
            case 6:
                if (!isListCreated) {
                    printf("List does not exist. Create a list first.\n");
                    break;
                }
                deleteAtEnd(&head);
                break;
            case 7:  
                if (!isListCreated) {
                    printf("List does not exist. Create a list first.\n");
                    break;
                }
                printf("Enter target position: ");
                scanf("%d", &value);
                delete_from_any_position(&head, value);
                break;
            case 8:
                if (!isListCreated) {
                    printf("List does not exist. Create a list first.\n");
                    break;
                }
                displayList(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}