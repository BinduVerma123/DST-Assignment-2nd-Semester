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
int min(int g,int k,int l)
{
    if(g<k && g<l)
    return g;
    else if(k<l)
    return k;
    else if(l<g && l<k)
    return l;
    else if(g==l || g==k)
    return g;
    else if(k==l)
    return k;
    
}
int sum(struct node*aa)
{int s=0;
    while(aa!=NULL)
    {
       s=s+aa->num;
       aa=aa->link;
    }
    return s;
}
void print(struct node *aa)
{
    aa=aa->link;
    while(aa!=NULL)
    {
        printf("%d ",aa->num);
        aa=aa->link;
    }
}
void display(struct node *head)
 {
      struct node*aa=(struct node*)malloc(sizeof(struct node));
      struct node*bb=(struct node*)malloc(sizeof(struct node));
      struct node*cc=(struct node*)malloc(sizeof(struct node));
      struct node*tmp=(struct node*)malloc(sizeof(struct node));
      tmp=head;
      int c=0;
       int g,k,l;
      while(tmp!=NULL)
      {
         
          if(c==0)
          {
              aa=create(aa,tmp->num);
              g=sum(aa);
          }
          else if(c==1)
          {
              bb=create(bb,tmp->num);
              k=sum(bb);
          }
          else if(c==2)
          {
              cc=create(cc,tmp->num);
              l=sum(cc);
          }
          else if(c>2)
          {
          int j=min(g,k,l);
          if(j==g)
          {
            aa=create(aa,tmp->num);
            g=sum(aa);

          }
          else if(j==k)
          {
              bb=create(bb,tmp->num);
              k=sum(bb);
          }
          else
          {
              cc=create(cc,tmp->num);
              l=sum(cc);
          }
          }
          c++;

         tmp=tmp->link;
      }
   print(aa);
   printf("\n");
   print(bb);
   printf("\n");
   print(cc);
   printf("\n");
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
    }
    return 0;
  }

