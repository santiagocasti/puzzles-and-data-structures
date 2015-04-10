#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**
 * Double Linked List implementation
 */
typedef struct Node{
	struct Node *next;
	struct Node *prev;
	int data;
} Node;

/**
 * Insert a node with 'value' at the end of the list starting
 * at the pointer pointed by root.
 */
void insertNode(Node **root, int value){
	if (*root == NULL){
		// base case: empty list
		(*root) = (Node*)malloc(sizeof(Node));
		(*root)->prev = NULL;
		(*root)->next = NULL;
		(*root)->data = value;
	}else{
		// the list is not empty, we need to get to the end
		Node *curr = *root;
		while (curr->next != NULL){
			curr = curr->next;
		}
		Node *node = (Node*)malloc(sizeof(Node));
		node->data = value;
		node->next = NULL;
		node->prev = curr;
		curr->next = node;
	}
}

/**
 * Reverse the list's order.
 */
void reverseList(Node **root){
	//we assume that we have at least 2 elements
	Node* prev = (*root)->prev;

	while( (*root)->next != NULL){
		(*root)->prev = (*root)->next;
		(*root)->next = prev;
		prev = (*root);
		(*root) = (*root)->prev; 
	}

	(*root)->prev = (*root)->next;
	(*root)->next = prev;
}

/**
 * Insert a node with 'value' in the ordered list starting
 * at the pointer pointed by root.
 */
void insertNodeOrdered(Node **root, int value){

		Node* curr = *root;

		while (curr != NULL && curr->next != NULL && curr->data < value){
			curr = curr->next;
		}

		Node* node = (Node*)malloc(sizeof(Node));
		node->data = value;
		node->next = NULL;
		node->prev = NULL;

		if (curr == NULL){
			// insert as first node
			*root = node;
		}else{
			// insert after curr
			node->next = curr->next;
			node->prev = curr;
			curr->next = node;
			if (node->next != NULL)
				node->next->prev = node;
		}
}

/**
 * Print the data in the list's nodes
 */
void print(Node *root){
	int i;
	Node *aux = root;
	
	while (aux != NULL){
		printf("%d -> ", aux->data);
		aux = aux->next;
		//scanf("%d",&i);
	}

	printf("NULL\n");
}

/**
 * Check whether the list has a cycle or not.
 */
int isCyclic(Node *root){
	Node *fast, *slow;
	fast = root->next;
	slow = root;
	
	while (1){
		if (fast == NULL || fast->next == NULL)
			return 0;
		if (fast == slow || fast->next == slow)
			return 1;
		fast = fast->next->next;
		slow = slow->next;
	}
}

int main(int argc, char* argv[]){
	Node *root, *aux = NULL;
	int i;
	char answer;

	srand(time(NULL));

	for (i=0; i<20; i++){
		if (i!=8) insertNodeOrdered(&root, rand()%100);
	}
	print(root);

	reverseList(&root);
	print(root);

	printf("The list provided is %s.\n", isCyclic(root)?"cyclic":"acyclic");

	Node *first = root, *second;
	while (first != NULL){
		second = first->next;
		free(first);
		first = second;
	}

}
