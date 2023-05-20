#include<stdio.h>
#include<string.h>

int main(){

    char hospital_name[] = "IITJ HOSPIAL";
    FILE *fptr;
    fptr = fopen("Patients/aditya.txt","w");
    fprintf(fptr,"Hello");
    fclose(fptr);
    return 0;
}