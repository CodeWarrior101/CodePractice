//https://codeforces.com/contest/2/problem/A
#include<iostream>
#define TABLE_SIZE 1000
#define INT_MIN (1<<31)
#define log 1
using namespace std;

int max_score = INT_MIN;
int max_index = 0;
int first_found = 0;
string winner_name;
//string max_score_name;

struct data
{
	string name;
	int score = 0;
	struct data *ptr;
};

struct data* arr[TABLE_SIZE] = {NULL,};

int hashfun(string name)
{
	long int val = 0;
	int len = name.size();
	int i;
	for(i=0;i<len;i++)
	{
		val = val+((int)(name[i])-96)*(len-i);
	}
	return val%TABLE_SIZE;
}


int max_value()
{
	int i;
	//string name;
	for(i=0;i<TABLE_SIZE;i++)
    {
		struct data *tmp = arr[i];
		if(tmp)
		{
            while(tmp)
			{
			if((tmp->score)>max_score)
            {
				max_score = tmp->score;
                max_index = i;
			}
			tmp = tmp->ptr;
            }
		}
	}
    return max_score;
}

void insert(string name,int score)
{
	int index = hashfun(name);
	if(log)
	cout<<"\nhash value of "<<name<<":"<<index;
	if(arr[index] && arr[index]->name ==name)
    {
        arr[index]->score += score;
		if(log)
			cout<<"\narr["<<index<<"]->score:"<<arr[index]->score<<endl;
		return;
	}
	struct data *node = (struct data*)calloc(1,sizeof(struct data));
	if(!node)
	{
		cout<<"not sufficient memory"<<endl;
		return;
    }
	node->name = name;
    node->score = score;

    node->ptr = arr[index];
	arr[index] = node;

	if(log)
		cout<<"\narr["<<index<<"]->score:"<<arr[index]->score<<endl;
	
}

void insert_second(string name,int score,int maxs,string winner_list[],int now)
{
	int i;
	int index = hashfun(name);
    if(log)
	cout<<"\nhash value of "<<name<<":"<<index;
	if(arr[index] && arr[index]->name ==name)
	{
		arr[index]->score += score;
		for(i=0;i<now;i++)
		{
			if((arr[index]->score==maxs) && (winner_list[i]==arr[index]->name))
            {
				winner_name = arr[index]->name;
			}
		}
        if(log)
			cout<<"\narr["<<index<<"]->score:"<<arr[index]->score<<endl;
		return;
	}
	struct data *node = (struct data*)calloc(1,sizeof(struct data));
	if(!node)
	{
		cout<<"not sufficient memory"<<endl;
		return;
	}
	node->name = name;
	node->score = score;
	
	node->ptr = arr[index];
	arr[index] = node;
	
	for(i=0;i<now;i++)
	{
		if((arr[index]->score==maxs) && (winner_list[i]==arr[index]->name))
		{
			winner_name =  node->name;
		}
	}
}

int cal_winners(string winner_list[],int max)
{
	int i,j;
	int list_index = 0;
	for(i=0;i<TABLE_SIZE;i++)
	{
		struct data *tmp = arr[i];
		if(tmp)
		{
			while(tmp)
			{
				if(tmp->score ==max)
				{
					winner_list[list_index] = tmp->name;
					list_index++;
				}
				tmp = tmp->ptr;
			}
		}
	}
	return list_index;
}

void printArr()
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
	{
		struct data *cur = arr[i];
		if(cur)
		{
			while(cur)
			{
				cout<<"("<<cur->name<<", "<<cur->score<<")"<<" ";
				cur = cur->ptr;
			}
			cout<<endl;
		}
	}	
}

void free_memory()
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
	{
		struct data *cur = arr[i];
		struct data *pre =	cur;
		if(cur)
		{
			while(cur)
			{
				pre = cur;
				cur = cur->ptr;
				free(pre);
			}
		arr[i] = NULL;
		}
	}
}

int main()
{
	int i,j;
	int n;
	int number_of_winners = 0;
	string name[TABLE_SIZE];
	string winner_list[TABLE_SIZE];
	int score[TABLE_SIZE];
	max_score = INT_MIN;
	first_found = 0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>name[i];
		cin>>score[i];
		insert(name[i],score[i]);
	}
	int maxs = max_value();
	number_of_winners = cal_winners(winner_list,maxs);
	if(log)
	{
		cout<<"max score:"<<maxs<<endl;
		cout<<"total winners:"<<number_of_winners<<endl<<"winners are:"<<endl;
		for(i=0;i<number_of_winners;i++)
		{
			cout<<winner_list[i]<<endl;
		}
		
	}
	//declare_winner(winner_list,number_of_winners,maxs);
	if(log)
		printArr();
	free_memory();
	for(i=0;i<n;i++)
	{
		insert_second(name[i],score[i],maxs,winner_list,number_of_winners); // second simulation to choose the first winnner
	}
	cout<<winner_name<<endl;
	return 0;
}
