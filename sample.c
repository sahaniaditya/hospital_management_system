#include <stdio.h>
#include <time.h>
#include<string.h>
int main()
{
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    char d[100];
    strcpy(d,asctime(ptr));
    printf("%s",d);
    char date[100];
    int p = 0;
    int pos1 = 0;
    int pos2 = 0;
    int pos3 = 0;
    int pos = 0;
    for(int i  = 0;i<strlen(d);i++){
        if(d[i] == ' ')
         {
            pos++;
         }
         if(pos == 1)
          pos1 = i;
         if(pos == 3)
          pos2 = i;
         if(pos == 4)
          pos3 = i;  
        
    }
    for(int i  = 0;i<strlen(d);i++){
        
    }
    printf("%s",date);
    return 0;
}