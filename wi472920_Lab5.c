#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
    node* temp = head;
    int counter = 0;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function will return "abc"
char* toCString(node* head) {
	int len = length(head);
    char* string = (char*)malloc((len + 1) * sizeof(char));

    node* temp = head;
    char* ptr = string + len - 1;
    while (temp != NULL) {
        *ptr = temp->letter;
        ptr--;
        temp = temp->next;
    }
    string[len] = '\0';

    return string;
}


// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = *pHead;
    *pHead = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead) {
    node* tmp = NULL;
    while (*pHead != NULL) {
        tmp = *pHead;
        *pHead = (*pHead)->next;
        free(tmp);
    }
}

int main(void) {
    int i, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");

    if (inFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        int strLen;
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is: %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL) {
            printf("deleteList is not correct!\n");
            break;
        }
    }

    fclose(inFile);
    return 0;
}
