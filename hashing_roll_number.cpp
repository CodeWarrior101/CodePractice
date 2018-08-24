#include<iostream>
#include<cstdlib>
#include <string.h>
#define TABLE_SIZE 100000

using namespace std;

struct data
{
  char name[25];
  long roll;
  data * ptr;
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
  //char *tmp = (char*)malloc(3000);

  //memset(tmp, 1, 3000);
  node = (struct data *)calloc(1,(sizeof(struct data)));
  //char *x = (char *)calloc(1, sizeof(struct data));
  //node = (struct data *)x;
  //memset(x, 0, sizeof(struct data));
  //cout << "STRING: " << sizeof(char*) <<  endl;
  //node = new data();

  if(!node)
  {
      cout<<"not sufficient memory\n";
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
    /*while((tmp->ptr))
          tmp = tmp->ptr;
    tmp->ptr = node;*/
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
      cout<<"name not found\n";
  else
  {
    while(tmp)
    {
      if(tmp->roll==roll)
      {
        cout<<"name is:"<<tmp->name<<endl;
        return;
      }
        tmp = tmp->ptr;
    }
    cout<<"name not found\n";
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
  cin>>num;
  for(i=0;i<num;i++)
  {
    char name[25]={0,};
    cin>>roll;
    cin>>name;
    insert(roll,name);
  }
  cin>>q;
  for(i=0;i<q;i++)
  {
    cin>>roll;
    search(roll);
  }
  //LL;
  //if(!table[index])
    // free memory;
  return 0;
}
