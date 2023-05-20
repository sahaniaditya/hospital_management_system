#include<stdio.h>
#include<string.h>

int main(){

    char hospital_name[] = "IITJ HOSPIAL";
    int opt;
    FILE *fptr;
    fptr = fopen("Patients/aditya.txt","w");
    fprintf(fptr,"Hello");
    fclose(fptr);
    for(int i=0;i<10;i++) printf(" ");
    for(int i=0 ; i< 63 ; i++)
    {
     	printf("*");
    }
	printf("      IITJ HOSPITAL     ");
    for(int i=0 ; i< 63 ; i++)
    {
     	printf("*");
    }
    for(int i=0;i<6;i++) printf(" ");
    printf("\n");
    for(int i=0 ; i< 166 ; i++)
    {
     	printf("*");
    }
    printf("1. PATIENT ( PRESS 0 ) \n2. DOCTORS ( PRESS 1 )\n");
    printf("Enter : ");
    scanf("%d",&opt);
    for(int i=0 ; i< 166 ; i++) printf("*");
    switch(opt) 
    {
    	case 0 : printf("\nPATIENT's MENU\n");
    	break;
    	case 1 : printf("\nDOCTOR's MENU\n");
    	break;
    	default : printf("\nINVALID OPTION\n");
    }
    return 0;
}
