//
// Created by syonfox on 1/14/19.
//

#include <stdlib.h>
#include "dlist.h"



/*
 * Allocate memory for a node of type struct nodeStruct and initialize
 * it with the value item. Return a pointer to the new node.
 */
struct nodeStruct* List_createNode(int item) {
    struct nodeStruct* n = malloc(sizeof(struct nodeStruct));
    n->next = NULL;
    n->prev = NULL;
    n->item = item;
    return n;
}


/*
 * Insert node at the head of the list.
 */
void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node){
    node->next = *headRef;
    node->prev = NULL;
    *headRef = node;
}


/*
 * Insert node after the tail of the list.
 */
void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node){
    //struct nodeStruct * next = *headRef;
    if(*headRef == NULL) {
        *headRef = node;
        return;
    }
    struct nodeStruct * next = *headRef; //cant just use head since it will overwrite outside of the function
    while(next->next != NULL) {
        next = next->next;
    }
    next->next = node;
    node->prev = next;
}


/*
 * Count number of nodes in the list.
 * Return 0 if the list is empty, i.e., head == NULL
 */
int List_countNodes (struct nodeStruct *head) {
    //struct nodeStruct * next = head;
    int count = 0;
    while(head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}


/*
 * Return the first node holding the value item, return NULL if none found
 */
struct nodeStruct* List_findNode(struct nodeStruct *head, int item){
    //struct nodeStruct* node = NULL;
    while(head != NULL) {
        if(head->item == item){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

/*
 * Delete node from the list and free memory allocated to it.
 * This function assumes that node has been properly set to a valid node
 * in the list. For example, the client code may have found it by calling
 * List_findNode(). If the list contains only one node, the head of the list
 * should be set to NULL.
 */
void List_deleteNode (struct nodeStruct **headRef, struct nodeStruct *node){
    if(node == *headRef) {
        *headRef = NULL;
        free(node);
        return;
    }
    if(node->next != NULL){
        node->next->prev = node->prev;
    }
    if(node->prev != NULL){
        node->prev->next = node->next;
    }

    free(node);
}


/*
 * Sort the list in ascending order based on the item field.
 * Any sorting algorithm is fine.
 */
void List_sort (struct nodeStruct **headRef){
    struct nodeStruct *end = NULL;
    while(*headRef != end){
        struct nodeStruct *node = *headRef;
        while(node->next != end) {
            //compare
            if(node->item > node->next->item) {
                //swap
                int tmp = node->next->item;
                node->next->item = node->item;
                node->item = tmp;
            }
            node = node->next;
        }
        end = node;
    }

}

