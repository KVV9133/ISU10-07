#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct list {
 char id[30];
 struct list *next;
} list;

void add_to_list(list **head,char* key)
{
	list *new=calloc(1,sizeof(list));
	strncpy(new->id,key,29);
	new->next=NULL;
	if(*head==NULL)
		*head=new;
	else
	{
		list *p=*head;
		while(p->next!=NULL)
			p=p->next;
		p->next=new;
	}
	
	
}

void print_list(list *p)
{
	while(p)
	{
		printf("%s ",p->id);
		p=p->next;
	}
	
}

void swap_elements(list *one, list* two)
{
	char temp[30];
	strcpy(temp,one->id);
	strcpy(one->id,two->id);
	strcpy(two->id,temp);
}

void sort_list(list *head) {
    if (head == NULL)
        return; 
    
    int swapped;
    struct list *ptr;
    struct list *last = NULL; 
    
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != last) {
            if (strcmp(ptr->id, ptr->next->id) > 0) {
                swap_elements(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}
void delete_list(struct list *head) 
{
    list *tmp;
    while (head) 
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
int main()
{
	char input[1000];
	fgets(input,sizeof(input),stdin);
	
	size_t len = strlen(input);
	if (len > 0 && input[len - 1] == '\n')
	{
        input[len - 1] = '\0';
        len = strlen(input);
    }
	if (len > 0 && input[len - 1] == '.')
        input[len - 1] = '\0';

	list *head=NULL;
	char *token=strtok(input," ");
	while(token!=NULL)
	{
		add_to_list(&head,token);
		token=strtok(NULL," ");
		
	}
	sort_list(head);
	print_list(head);
	delete_list(head);
	return 0;
}
