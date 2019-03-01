#include<stdio.h>
#include<stdlib.h>
struct node {
  int num;          
  struct node*link;
};
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
void display(struct node *head)
 {
  struct node *tmp=head;
  int s=0;
  while(tmp!=NULL)
  {
      printf("%d ",tmp->num);
      s=s+tmp->num;
      tmp=tmp->link;
  }
  printf("%d\n",s);
 }
  int main() {
    int n, x, i,t;
    scanf("%d\n", &t);
    while(t--)
     {
      struct node *head = NULL;
      scanf("%d", &n);
      for (i=0;i<n;i++)
       {
        scanf("%d",&x);
        head = create(head, x);
      }
      display(head);
    }
    return 0;
  }
