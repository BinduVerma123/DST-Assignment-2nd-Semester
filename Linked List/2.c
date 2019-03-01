#include <stdio.h> 
#include <stdlib.h> 
 struct node {
  int num;          
  struct node*link;
}; 
// A linked list node 
int max(struct node *head)
{
    int max=head->num;
    while(head!=NULL)
    {
        if(max<head->num)
        max=head->num;
        head=head->link;
    }
    return max;
}
int min(struct node *head)
{
    int min=head->num;
    while(head!=NULL)
    {
        if(min>head->num)
        min=head->num;
        head=head->link;
    }
    return min;
} 
struct node*create(struct node *head,int x) 
{
  if(head==NULL)
   { 
       struct node*tmp=(struct node*)malloc(sizeof(struct node));
       tmp->num=x;
       tmp->link=NULL;
       return tmp;
   }
  head->link=create(head->link,x);
  return head;
} 
void del(struct node **head_ref, int key) 
{ 
	// Store head node 
	struct node* tmp = *head_ref, *prev; 
	// If head node itself holds the key to be deleted 
	if (tmp != NULL && tmp->num == key) 
	{ 
		*head_ref = tmp->link; // Changed head 
		free(tmp);			 // free old head 
		return; 
	} 
	// Search for the key to be deleted, keep track of the 
	// previous node as we need to change 'prev->next' 
	while (tmp != NULL && tmp->num!= key) 
	{ 
		prev = tmp; 
		tmp = tmp->link; 
	} 
	// If key was not present in linked list 
	if (tmp == NULL) return; 

	// Unlink the node from linked list 
	prev->link = tmp->link; 
	free(tmp); // Free memory 
} 

void display(struct node *head) 
{ 
    while (head != NULL) 
    { 
        printf("%d ", head->num); 
        head = head->link; 
    } 
} 
int main() {
    int n, x, i,t;
    scanf("%d", &t);
    while(t--)
     {
      struct node *head = NULL;
      scanf("%d", &n);
      for (i=0;i<n;i++)
       {
        scanf("%d",&x);
        head = create(head, x);
      }
      int k=max(head);
      int j=min(head);
      del(&head,k);
      del(&head,j);
      display(head);
      printf("\n");
    }
    return 0;
  }