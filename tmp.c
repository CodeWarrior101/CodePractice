#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#define TABLE_SIZE 100000

struct data
{
  char name[25];
  int roll;
  struct data * ptr;
};
struct data* table[TABLE_SIZE] = {NULL,};

int hash_fun(int num)
{
  return num%TABLE_SIZE;
}

void insert(int roll,char* name)
{
  int index;
  index = hash_fun(roll);
  struct data *node = NULL;
  
  node = (struct data *)calloc(1,(sizeof(struct data)));

  if(!node)
  {
      //cout<<"not sufficient memory\n";
      printf("not sufficient memory\n");
      return;
  }
  int i =0;
  while(name[i])
  {
    node->name[i] = name[i];
    i++;
  }
  node->name[i] ='\0';

  node->roll = roll;
  node->ptr = NULL;
  if(!table[index])
  {
    table[index] = node;
  }
  else
  {
    struct data * tmp;
    tmp = table[index];
    table[index] = node;
    table[index]->ptr = tmp;
  }
  return;
}

void search(int roll)
{
  int index = hash_fun(roll);
  struct data *tmp = table[index];
  if(!tmp)
      printf("name not found\n");
  else
  {
    while(tmp)
    {
      if(tmp->roll==roll)
      {
        printf("name is:%s\n",tmp->name);
        return;
      }
        tmp = tmp->ptr;
    }
    printf("name no found\n");
  }
  return;
}

int main()
{
  int roll;
  int num;
  int i,j;
  int index;
  int q;
  scanf("%d",&num);
  for(i=0;i<num;i++)
  {
    char name[25]={0,};
    scanf("%d",&roll);
    scanf("%s",name);
    insert(roll,name);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++)
  {
    scanf("%d",&roll);
    search(roll);
  }
  if(table[1])
    {
      printf("table is not empty\n");
      struct data * tmp = table[1];
      while(tmp)
      {
        printf("roll = %d name =%s\n",tmp->roll,tmp->name);
        tmp = tmp->ptr;
      }
    }
  return 0;
}
