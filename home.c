#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

char hospital_name[] = "IITJ HOSPIAL";
char password[100];
int opt;
void baseline();
void generateMD5Hash(const char *password, unsigned char *hash);
void doctor_nextmenu();
void doctor_menu();
void patient_menu();


int main(){

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
    printf("\n");
    baseline();
    printf("1. PATIENT ( PRESS 0 ) \n2. DOCTORS ( PRESS 1 )\nEnter any option : ");
    scanf("%d",&opt);
    baseline();
    switch(opt) 
    {
    	case 0 : 
    	printf("\nPATIENT's MENU\n");
    	patient_menu();
    	break;
    	case 1 : 
    	printf("\nDOCTOR's MENU\n");
    	doctor_menu();
    	break;
    	default : printf("\nINVALID OPTION\n");
    }
    
    return 0;
}



void baseline() {
for(int i=0 ; i< 166 ; i++) printf("*");
}
void generateMD5Hash(const char *password, unsigned char *hash) {
    MD5_CTX md5Context;
    MD5_Init(&md5Context);
    MD5_Update(&md5Context, password, strlen(password));
    MD5_Final(hash, &md5Context);
}
void doctor_nextmenu() {
	baseline();
	printf("1.Patient Record(Press 0)\n2.Scheduled vist(Press 1)\nEnter any option : \n");
	scanf("%d",&opt);
	
}
void doctor_menu() {
    printf("\nEnter password : \n");
    scanf("%s",password);
    printf("\n");
    unsigned char hash[MD5_DIGEST_LENGTH];
    generateMD5Hash(password, hash);
    unsigned char storedHash[MD5_DIGEST_LENGTH] = {
  	 0x38, 0xa0, 0xed, 0x46, 0xde, 0x4e, 0xb0, 0x76,
    	 0xdc, 0x78, 0x20, 0xbb, 0x9f, 0x41, 0x19, 0xe7
	};
    if (memcmp(hash, storedHash, MD5_DIGEST_LENGTH) == 0) {
	    printf("Password is correct. Access granted.\n");
	    doctor_nextmenu();
	} 
    else {
   	 printf("Incorrect password. Access denied.\n");
	}
}
void patient_menu() {
	printf("\n1. NEW \n2. EXISTING\nEnter any option :");
	scanf("%d",&opt);
		
}
