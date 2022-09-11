#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)


struct Item
{
	int val1;
	int val2;
	int id;
	struct Item* next;
	struct Item* prev;
};

struct Item* head =NULL;s
struct Item* tail =NULL;
int ID_COUNTER = 1;



void Push(int val1, int val2)
{
	struct Item* theNumbers;
	struct Item* Numbersfree;
	theNumbers = (struct Item*)malloc(sizeof(struct Item));
	Numbersfree = theNumbers;
	
	

	if (head == NULL)
	{
		head = theNumbers;
		tail = theNumbers;
		theNumbers->next = NULL;
		theNumbers->prev = NULL;

	}
	else
	{
		theNumbers->next = NULL;
		theNumbers->prev = head;
		head->next = theNumbers;

	}
	theNumbers->val1 = val1;
	theNumbers->val2 = val2;
	theNumbers->id = ID_COUNTER;
	head = theNumbers;
	ID_COUNTER++;
}

void PrintList()
{
	struct Item* List = tail;
	while (List != NULL)
	{
		printf(" val1:%d val2:%d id:%d\n", List->val1, List->val2, List->id);
		List = List->next;
    }


}

struct Item* Pop()
{
	struct Item* remove = tail;
	if (tail->next != NULL)
	{
		tail = tail->next;
		printf("val1:%d val2:%d id:%d", remove->val1, remove->val2, remove->id);
		free(remove);
	}
	else
	{
		printf("no numbers");
	}
	
	return remove;
	
}


int main()
{
	time_t Time = time(NULL);

	int a,b,c;
	a = 0;
	
	while (a!= 4)
	{
		printf("pleas enter number between 1-4\n 1:to add number to the list\n 2: to print the list\n 3:to remove the first number and print them\n 4:to end the program\n");
		scanf("%d",&a);
		
		switch (a)
		{
		case 1:srand(Time);
			b = rand();
			c = rand();
			Push(c, b);
			printf("\n");
			break;
		case 2:
			PrintList();
			printf("\n");
			break;
		case 3:
			Pop();
			printf("\n");
			break;
		case 4:
			printf("the program is over");
			break;
		default:
			printf("Wrong selection. Try be more sharp\n");
			break;
		}
	}
	


	

}