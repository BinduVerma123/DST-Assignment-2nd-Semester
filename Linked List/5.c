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
void display(struct node *head,int x)
 {
      struct node*tmp=(struct node*)malloc(sizeof(struct node));
      struct node*nxt=(struct node*)malloc(sizeof(struct node));
      tmp=head;
      nxt=head;
      int s=0,i;
  while(tmp!=NULL)
  {
      tmp=tmp->link;
      s++;
 }
 for(i=0;i<s;i++)
 {
     if(i==x)
     printf("%d ",nxt->num);
     nxt=nxt->link;
 }
 }
  int main() {
    int n, x, i,l,t;
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
      for(i=0;i<n;i++)
      {
          scanf("%d",&l);
      display(head,l);
    }
    printf("\n");
     }
    return 0;
  }
