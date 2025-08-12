#include "push_swap.h"

typedef struct node {
	int	val;
	struct node *next;
} node_t;

int	main()
{
	//created two variables on the list
	node_t *head = NULL;
	head = (node_t *)malloc(sizeof(node_t));
	if (head = NULL)
	{
		return (1);
	}
	head->val = 1;
	head->next = (node_t *)malloc(sizeof(node_t));
	head->next->val = 2;
	head->next->next = NULL;
}

//iterating over a list
void	print_list(node_t *head)
{
	node_t *current = head; //initializing a current to iterate through the list

	while (current != NULL) //while we have some value and the list is not over
	{
		printf("%d\n", current->val); //print the value that is on the node
		current = current->next; //assign the next node to current so that in the last call
		//we print the next value
	}
}

//adding an item to the end of the list
void	push(node_t *head, int val)
{
	node_t *current = head; //initializing a current node to iterate through the list
				//and putting the first element of the list which is the head
				//to the current
	while (current->next != NULL) //while we are not at the end of the list
		current = current->next; //iterate

	current->next = (node_t *)malloc(sizeof(node_t)); //now that we are at the last element
	//which is pointing to NULL, we can allocate memory for the next to put a value in it
	current->next->val = val; // assigning the value that was given to us, to the actual value
				  // variable
	current->next->next = NULL; //as the last element of the list always points to NULL, we must
				    //now also initialize the next element of the last node to NULL.
}

//adding an item to the beginning of the list
void	push_first(node_t **head, int val)
{
	node_t *new_node; //we initialize a new_node
	new_node = (node_t *)malloc(sizeof(node_t)); //allocate memory of the size of the node

	new_node->val = val; // assign the given value to the actual value of the node
	new_node->next = *head; //point the new_node to the head of the list
	*head = new_node; // assign new_node as the head
}

//removing the first item(popping from the list)
int	pop(node_t **head)
{
	int	retval = -1; //default, fallback value that's why it is initialized as -1
	node_t *next_node = NULL;

	if (*head == NULL)
		return (-1);//if the list is empty function must return -1
	next_node = (*head)->next; //we assign the second element of the list as next_node
	retval = (*head)->val; //assign the value of the element that must be deleted to retval
	free(*head); //now that we retrieved the value of the element and have a pointer
		     //pointing to the second element we now can free head
	*head = next_node; // now we assign the second node as the head which is the first element

	return (retval); // if we successfully popped the element then function returns the value
			 // of the element that was broken from the list
}

//removing the last item of the list

int	remove_last(node_t *head)
{
	int	retval = 0;
	if (head->next == NULL) //if there is only one item on the list retrieve the value of it and
				//free it 
	{
		retval = head->val;
		free(head);
		return (retval);
	}
	node_t *current = head; //we must go to the second to last item on the list
	while (current->next->next != NULL)
		current = current->next;
	retval = current->next->val; //assign second to the last item's next's value
	//which is the last member's value, to the retval variable
	free(current->next); //free the last item
	current->next = NULL; //now since we freed the last item, current->next doesnt point
	//point to anything, and since now we are in the new last item of the list we must
	//assign it to null
	return (retval); //we return the value that has been retrieved from the last removed
			 //item on the list
}

//removing a specific item
//to remove a specific item from the list, either by its index from the beginning of the list
//or by its value, we will need to go over all the items, continuously looking ahead
//to find out if we've reached the node before the item we wish to remove. this is because
//we need to change the location to where the previous node points to as well.
//
//here is the algorithm:
//1.iterate to the node before the node we wish to delete
//2.save the node we wish to delete in a temporary pointer
//3.set the previous node's next pointer to point to the node after the node we wish to delete
//4.delete the node using the temporary pointer

int	remove_by_index(node_t **head, int n)
{
	int	i = 0;
	int	retval = -1;
	node_t *temp = NULL;
	if (*head ==  NULL)
		return (-1);
	if (n == 0)
		return (pop(head));
	node_t *current = *head;
	while (i < n - 1)
	{
		if (current->next == NULL)
			return (-1); //index out of bounds
		current = current->next;
		i++;
	}
	if (current->next == NULL)
		return (-1);
	temp = current->next; // we assigned the node we want to remove to a temp pointer
	retval = temp->val; // we assigned the value of the node we want to remove
	//to the retval variable
	current->next = temp->next; //we assigned the the nextpointer of the node that we want to delete
	//to the previous node's next pointer
	free(temp); //always free temp
	return (retval); // return the value of the node that we deleted
}

int	remove_by_value(node_t **head, int value)
{
	int	retval = -1;
	node_t	*temp = NULL;
	//if the list does not exist we return -1 and exit
	if (*head == NULL)
		return (-1);
	node_t *current = *head; // after we make sure the list exists then we can assign
	//the current node to the head to iterate

	//if the value equals to the head's value we dont need to iterate we just delete the head node
	if (current->val == value)
		return (pop(head));
	// to avoid seg fault you must always check if the current->next exists(first condition) before 
	// accessing the value of the next node. 
	// while value of the current next is not equal to the value given we continue the loop
	while (current->next != NULL && current->next->val != value) 
		current = current->next;
	if (current->next == NULL) // if value is not found just return -1 and exit
		return (-1);

	//deleting the node
	temp = current->next;
	retval = temp->val;
	current->next = temp->next;
	free(temp);
	return (retval);
}













































