#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
    struct Node* previous;
};
//adding every time it needs a new floor
void append(struct Node** desiredfloor, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*desiredfloor);
    new_node->previous = NULL;
	if((*desiredfloor) != NULL){
		(*desiredfloor)->previous = new_node;

	
	}
    (*desiredfloor) = new_node;


}

//this will print the floors backwards and the while loop will make it go backwards whenever you enter last that entered
void print_list(struct Node *n)
{
	struct Node *End;
    while (n != NULL )
    {
        printf("%d ", n->data);
        End = n;
        n = n->next;
        
    }
    while(End != NULL){
		printf("%d\n", End->data);
		End = End->previous;
	}

}

void clear_list(struct Node** n)
{
	struct Node* current = *n;
	struct Node* next;
	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	*n = NULL;
}

//the floors getting inserted for the elevator and it starts from 1 to 12 and then goes 12 to 1.
int main()
{
struct Node* desiredfloor = NULL;
append(&desiredfloor, 12); 
printf("ding");
append(&desiredfloor, 11);
append(&desiredfloor, 10);
append(&desiredfloor, 9);
append(&desiredfloor, 8);
append(&desiredfloor, 7);
append(&desiredfloor, 6); 
printf("ding");
append(&desiredfloor, 5);
append(&desiredfloor, 4);
append(&desiredfloor, 3);
append(&desiredfloor, 2);
append(&desiredfloor, 1);
print_list(desiredfloor);
}
