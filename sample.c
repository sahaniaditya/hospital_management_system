#include <stdio.h>
#include <time.h>
#include<string.h>
int main()
{
   FILE *ptr;
   ptr = fopen("Patients/adi.txt","w");
   fprintf(ptr,"I am good");
   fclose(ptr);
    return 0;
}