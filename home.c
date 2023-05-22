#include<stdio.h>
#include<string.h>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <termios.h>
#include <unistd.h>

FILE *fptr;
char hospital_name[] = "IITJ HOSPIAL";
char password[100];
int opt;


void baseline();
void generateMD5Hash(const char *password, unsigned char *hash);
void doctor_nextmenu();
void doctor_menu();
void patient_menu();
void disableEcho();
void enableEcho();
int createPatient(FILE*);
int patientId(int,int);
void createDate(char*);
struct Patient{
    char name[100];
    int age;
    int dob;
    char sex[100];
    long contact;
    char email[100];
    char address[100];
};
int main(){


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
int createPatient(FILE *fptr){

    struct Patient patient1;
    //Code to input patient details
    printf("Enter your full name : ");
    getchar();
    fgets(patient1.name,100,stdin);
    printf("Enter your sex : ");
    fgets(patient1.sex,100,stdin);
    printf("Enter your email : ");
    fgets(patient1.email,100,stdin);
    printf("Enter your address : ");
    fgets(patient1.address,100,stdin);
    printf("Enter your DOB(DDMMYYYY) : ");
    scanf("%d",&patient1.dob);
    getchar();
    printf("Enter your age : ");
    scanf("%d",&patient1.age);
    printf("Enter your phone number : ");
    scanf("%ld",&patient1.contact);
    //Code to generate Patient Id
    int patientid = patientId(patient1.age,patient1.dob);

    //to get the date of record creation
    char date[100];
    createDate(date); 

    //Code to create patient file
    fptr = fopen("Patients/patient1.txt","w");
    fprintf(fptr,"PatientID : %d                      Date : %s",patientid,date);
    fprintf(fptr,"Name : %s",patient1.name);
    fprintf(fptr,"Age : %d\n",patient1.age);
    fprintf(fptr,"Sex : %s",patient1.sex);
    fprintf(fptr,"Phone : %ld\n",patient1.contact);
    fprintf(fptr,"Email : %s",patient1.email);
    fprintf(fptr,"Address : %s",patient1.address);
    fptr = fopen("Patients/aditya.txt","w");
    fprintf(fptr,"Hello");
    fclose(fptr);
 
    return 0;
}




void baseline() {
for(int i=0 ; i< 166 ; i++) printf("*");
}
int patientId(int age,int dob){
    int id = 0;
   while(age != 0){
        id = id * 10 + (age % 10);
        age = age / 10;
   }
   id = id + dob;
   return id;
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
    disableEcho();
    scanf("%s",password);
    enableEcho();
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
	switch(opt)
	{
		case 1: createPatient(fptr);
	}

}
void createDate(char *date ){
struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    char d[100];
    strcpy(date,asctime(ptr));

}
void disableEcho() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void enableEcho() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
