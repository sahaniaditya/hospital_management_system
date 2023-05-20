#include<stdio.h>
#include<string.h>
#include<time.h>

void createPatient();
int patientId();
void createDate();
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

    char hospital_name[] = "IITJ HOSPITAL";
    FILE *fptr;
    createPatient(fptr);
    return 0;
}
void createPatient(FILE *fptr){
    struct Patient patient1;
    //Code to input patient details
    printf("Enter your full name : ");
    fgets(patient1.name,100,stdin);
    printf("Enter your sex : ");
    fgets(patient1.sex,100,stdin);
    printf("Enter your email : ");
    fgets(patient1.email,100,stdin);
    printf("Enter your address : ");
    fgets(patient1.address,100,stdin);
    printf("Enter your DOB(DDMMYYYY) : ");
    scanf("%d",&patient1.dob);
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
    fprintf(fptr,"PatientID : %s                       Date : %s",patientid,date);
    fprintf(fptr,"Name : %s",patient1.name);
    fprintf(fptr,"Age : %d\n",patient1.age);
    fprintf(fptr,"Sex : %s",patient1.sex);
    fprintf(fptr,"Phone : %ld\n",patient1.contact);
    fprintf(fptr,"Email : %s",patient1.email);
    fprintf(fptr,"Address : %s",patient1.address);
    fclose(fptr);
    




}
int patientId(int age,int dob){
    int id = dob;
   while(age != 0){
        id = id * 10 + (age % 10);
        age = age / 10;
   }
   return id;
}
void createDate(char *date ){
struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    char d[100];
    strcpy(date,asctime(ptr));
    
}