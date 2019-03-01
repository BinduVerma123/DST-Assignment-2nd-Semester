#include<stdio.h>
#include<stdlib.h>
struct node {
  int num;
  struct node*link;
};
void display(struct node *head)
{
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp=head;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->num);
        tmp=tmp->link;
    }
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
void swap(struct node *a,struct node *b)
{
    int tmp=a->num;
    a->num=b->num;
    b->num=tmp;

}
void sort(struct node *head)
{
struct node*tmp=(struct node*)malloc(sizeof(struct node));
struct node*nxt=(struct node*)malloc(sizeof(struct node));
struct node*ptr=(struct node*)malloc(sizeof(struct node));
int s=0,i;
nxt=head;
while(nxt!=NULL)
{
    nxt=nxt->link;
    s++;
}
for(i=0;i<s;i++)
{
    tmp=head;
    while(tmp->link!=NULL)
    {
        if(tmp->num<=tmp->link->num)
        {
            swap(tmp,tmp->link);

        }
        tmp=tmp->link;
    }
    ptr=tmp;
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
      sort(head);
      display(head);
      printf("\n");
    }
    return 0;
  }
