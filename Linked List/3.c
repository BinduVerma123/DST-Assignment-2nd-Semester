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
      struct node*tmp=(struct node*)malloc(sizeof(struct node));
      struct node*nxt=(struct node*)malloc(sizeof(struct node));
      nxt=head;
      tmp=head;
      while(tmp!=NULL)
      {
          if(tmp->num%2==1)
          printf("%d ",tmp->num);
          tmp=tmp->link;
      }
      while(nxt!=NULL)
      {
          if(nxt->num%2==0)
          printf("%d ",nxt->num);
          nxt=nxt->link;
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
      display(head);
      printf("\n");
    }
    return 0;
  }
