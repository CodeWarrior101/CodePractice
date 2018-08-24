//https://www.geeksforgeeks.org/power-set/
#include <stdio.h>
#include<time.h>

#pragma GCC optimize ("-Ofast")

void printPowerSet(char *set, int set_size)
{
    //set_size of power set of a set with set_size
    // left shift 1 by 1 is equivalent to multiply by 2
    unsigned int pow_set_size = 1<<set_size;
    int counter, j;

    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j))
          {
            printf("%c", set[j]);
          }
       }
       printf("\n");
    }
}

/*Driver program to test printPowerSet*/
int main()
{
    char set[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u'};
    int n = sizeof(set)/sizeof(set[0]);
    clock_t start_time = clock();
    printPowerSet(set, n);
    printf("time taken is: %f seconds\n",((double)(clock()-start_time))/CLOCKS_PER_SEC);
    return 0;
}
