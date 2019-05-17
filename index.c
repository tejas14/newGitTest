#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *NEXT;
};
	
struct node *FIRST = NULL;
struct node *LAST = NULL;

void insert(int);
int delete(int);
void print(void);
struct node *search(int);

int main()
{
	int a, b, choice;
	struct node *location;
	
   while(1)
   {
		
	printf("Enter an option:\n");
	printf("1. Insert \n");
	printf("2. Delete \n");
	printf("3. Search \n");
	printf("4. print  \n");
	printf("5. Exit   ");
	
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
		{
			printf("Enter the element to be inserted: ");	
			scanf("%d", &a);
			insert(a);
			printf("%d is successfully inserted into linked list.\n\n", a);
			
			break;
		}
			
		case 2:
		{
			printf("Enter the element to be deleted from the linked list: \n");
			scanf("%d", &a);
			b = delete(a);
			
			if (b == -999)
			printf("%d is not present in linked list",a);
			else
			printf("element %d successfully deleted from the linked list\n\n", b);
			
			break;
		}
		
		case 3:
		{
			printf("Enter the element to be searched\n");
			scanf("%d", &a);
			location = search(a);
			
			if (location = NULL)
			printf("Element %d is the last element in the list\n\n", a);
			else
			printf("Element %d is present before element %d in the linked list\n\n", a, (location-> NEXT)-> data );
			
			break;
		}
		
		case 4:	
		{
			print();
			break;
		}
		
		case 5:
		{
			exit(1);
			break;
		}
		
		default:
		{
			printf("incorrect choice.\n\n");
			break;
		}
	}
    }
}


void insert(int a)
{
	struct node *NODE;
	NODE = (struct node*)malloc(sizeof(struct node));

	NODE-> data = a;

	if (FIRST == NULL)
	{
		FIRST = LAST = NODE;		
		FIRST-> NEXT = NULL;
	}
	else
	{
		LAST -> NEXT = NODE;
		NODE -> NEXT = NULL;
		LAST = NODE;
	}
}

int delete(int a)
{
	struct node *LOC, *TEMP;
	int i;
	i = a;

	LOC = search(i);
	
	if (LOC == NULL)
	return(-999);
	
	if (LOC == FIRST)
	{
		if (FIRST == LAST)
		FIRST = LAST = NULL;
		else
		FIRST = FIRST -> NEXT;
		return(a);
	}
	
	for( TEMP=FIRST; TEMP-> NEXT!= LOC; TEMP = TEMP -> NEXT ) 
	;
	TEMP -> NEXT = LOC -> NEXT;
	
	if (LOC == LAST)
	LAST = TEMP;
	return(LOC -> data);
}	

struct node *search(int a)
{
	struct node *NODE;
	
	if (FIRST == NULL)
	return(NULL);
	
	for (NODE = FIRST; NODE != LAST; NODE = NODE -> NEXT)
		if (NODE -> data == a)
		return(NODE);
	
	if (LAST -> data == a)
	return(LAST);
	else
	return(NULL);
}
	
void print()
{
	struct node *NODE;
	
	if (FIRST == NULL)
	{
		printf("Empty List. \n\n");	
		return;
	}
	
	printf("Linked list elements:\n");
	if (FIRST == LAST)
	{
		printf("%d\n", FIRST -> data);
		return;
	}
	
	for(NODE = FIRST; NODE != LAST; NODE = NODE -> NEXT)
	printf("%d\n", NODE -> data);	
	printf("%d\n\n", LAST -> data);
}	 		

		
	 
			
	

