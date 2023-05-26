#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include<ctype.h>


#define MAX_LENGTH 50
void removeBlankLines();
void showProfile(char*);
void newPatient();
void visitRecord(char*);
void scheduleVisit();
void existingPatient();
int searchPatient(char*);
void updatePatient(char*);
void createPatient(char*);
void extractText(FILE*,char*,int,char*);
void createPath();
void extractPD();
int patientId();
void createDate(char*);
int visitCount = 0;
char doctor[100] = "Hitesh Singh";
char doctor_pass[100] = "iitj@2023";
char hospital_name[] = "IITJ HOSPIAL";
char password[100];
int opt;
void baseline();
//void generateMD5Hash(const char *password, unsigned char *hash);
void doctor_nextmenu();
void doctor_menu();
void patient_menu();


struct Patient{
    char name[100];
    char age[100];
    char dob[100];
    char sex[100];
    char contact[100];
    char email[100];
    char address[100];
    char medHistory[1000];
};


//int main() function
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



//showProfile() function
void showProfile(char *path)
{
    FILE *ptr;
    char str[100];
    ptr = fopen(path,"r");
    if(ptr != NULL){
    while(fgets(str,100,ptr)){
        printf("%s\n",str);
    }
    }
    else{
        printf("Sorry. Not able to open the file.\n");
    }
    fclose(ptr);
}
//searchPatient() function
int searchPatient(char *pass){
   FILE *ptr;
   ptr = fopen("Patients/database.txt","r");
   char str[100];
   char numberString[100];  
   while(fgets(str,100,ptr)){
  
    char *numberStart = str;
    while (*numberStart != '\0' && !isdigit(*numberStart)) {
        numberStart++;
    }

    // Copy the number characters to numberString
    int i = 0;
    while (*numberStart != '\0' && isdigit(*numberStart)) {
        numberString[i++] = *numberStart++;
    }
    numberString[i] = '\0';

   }
    if(strcmp(pass,numberString) == 0)
     {return 1;}
    else{
        return 0;
    }
  
}
//scheduleVisit() function
void scheduleVisit(char *name,char *patientid,char *path, char *path1){
    FILE *fp;
    fp = fopen("doctorVisit.txt","a+");
    
    // FILE *fptr;
    // fptr = fopen("Patients/profile_25042004.txt","r");

    FILE *ptr;
    ptr = fopen(path,"a+");
    int n = 1;
    int id  = 0;
    char date[100];
    
    printf("Enter the date (DDMMYYYY) on which you want to visit : ");
    fflush(stdin);
    scanf("%s",date);
    if(ptr != NULL){
    fprintf(ptr,"%s         %s                      %s          %s\n",patientid,name,doctor,date);
    }else{
        printf("Sorry. Not able to write  in file.\n");
    }
    fprintf(fp,"%s         %s                      %s          %s\n",patientid,name,doctor,date);
    fclose(ptr);
    fclose(fp);
    printf("Thank you for scheduling a visit !!!\n");
    baseline();
   
}
//visitRecord() function
void visitRecord(char *path){
     
     FILE *ptr;
    char str[100];
    ptr = fopen(path,"r");
    if(ptr != NULL){
      printf("PatientID     Name                       Doctor                Date\n");
    while(fgets(str,100,ptr)){
        printf("%s\n",str);
    }
    }
    else{
        printf("Sorry. Not able to open the file.\n");
    }

}
//existingPatient() function
void existingPatient(){
    char password[100];
    char name[100];
    printf("Enter the name : ");
    fflush(stdin);
    getchar();
    scanf("%[^\n]s",name);
    printf("Enter the password : ");
    fflush(stdin);
    scanf("%s",password);
    int res = searchPatient(password);
    // if(patientid == 0)
    //  {
    //     printf("Sorry. User not authorized!\n");
    //  }
      if(res==1){
        printf("Successfully logged in.\n");
        baseline();
        printf("Choose the option\n1. Show Profile \n2. Update Profile \n3. Visit Record \n4. Schedule Visit\n\n");
        printf("Enter the option : ");
        fflush(stdin);
        int ch;
        scanf("%d",&ch);
        printf("\n");
        baseline();
        char path1[100];
        char path2[100];
        char path3[100];
        char path4[100];
        char path5[100];
        switch (ch)
        {
        case 1:
         
         createPath(path1,password,"profile");
         showProfile(path1);

            break;
        case 2:
        
        createPath(path2,password,"profile");
        updatePatient(path2);
        break; 
        case 3:
        createPath(path3,password,"visit");
        visitRecord(path3);
        break; 
        case 4:
        
        createPath(path4,password,"visit");
        createPath(path5,password,"profile");
        scheduleVisit(name,password,path4,path5);
        break;  
        default:
         printf("Invalid Option.");
            break;
        }
     }
     else{
       printf("Sorry. User not authorized!\n");
     }
     baseline();
}

//newPatient() function
void newPatient(){
    char patientPass[100];
    createPatient(patientPass);
    printf("Profile created successfully.\n");
    printf("This is your password : %s\n",patientPass);
    baseline();
    main();

}

//createPatient() function
void createPatient(char *patientPass){
    FILE *data;
    FILE *pptr;
    
    FILE *vptr;
    struct Patient patient;
    //Code to input patient details
    printf("Enter your full name : ");
    fflush(stdin);
    getchar();
    fgets(patient.name,100,stdin);
    printf("Enter your sex : ");
    fgets(patient.sex,100,stdin);
    printf("Enter your email : ");
    fgets(patient.email,100,stdin);
    printf("Enter your address : ");
    fgets(patient.address,100,stdin);
    printf("Enter your DOB(DDMMYYYY) : ");
    fgets(patient.dob,100,stdin);
    printf("Enter your age : ");
    fgets(patient.age,100,stdin);
    printf("Enter your phone number : ");
    fgets(patient.contact,100,stdin);
    printf("Enter your medical history : ");
    fgets(patient.medHistory,1000,stdin);

    //Code to generate Patient Id
    int patientid = patientId(patient.contact,patient.dob);
    char patient_id[100];
    sprintf(patient_id, "%d", patientid);
    strcpy(patientPass,patient_id);
   
    //to get the date of record creation
    char date[100];
    createDate(date); 
    //Create the unique file path
    char pathVisit[100];
    char pathProfile[100];
    
    createPath(pathVisit,patient_id,"visit");
   
    createPath(pathProfile,patient_id,"profile");
    
    
    //Code to create patient file
    vptr = fopen(pathVisit,"w");
   
    pptr = fopen(pathProfile,"w");
    
    
    fprintf(pptr,"PatientID : %s                      Date : %s",patient_id,date);
    fprintf(pptr,"Name : %s",patient.name);
    fprintf(pptr,"Age : %s",patient.age);
    fprintf(pptr,"Sex : %s",patient.sex);
    fprintf(pptr,"Phone : %s",patient.contact);
    fprintf(pptr,"Email : %s",patient.email);
    fprintf(pptr,"Address : %s",patient.address);
    fprintf(pptr,"Medical History : %s",patient.medHistory);
    fclose(pptr);
    data = fopen("Patients/database.txt","a+");
    fprintf(data,"%s                                           %s",patient_id,patient.name);
    fclose(data);
    
    
}
//patientId() function
int patientId(char* contact,char* dob){
    int con = atoi(contact);
    int dob1 = atoi(dob);
    int pass=con%100;
    pass+=dob1;
    return pass;
}

//baseline() function

void baseline() {
for(int i=0 ; i < 166 ; i++) printf("*");
}
/*void generateMD5Hash(const char *password, unsigned char *hash) {
    MD5_CTX md5Context;
    MD5_Init(&md5Context);
    MD5_Update(&md5Context, password, strlen(password));
    MD5_Final(hash, &md5Context);
}*/
void doctor_nextmenu() {
	baseline();
	printf("1.Patient Record(Press 1)\n2.Scheduled vist(Press 2)\nEnter any option : \n");
    fflush(stdin);
	scanf("%d",&opt);
   baseline();
    FILE *fp1;
    FILE *fp2;
    switch (opt)
    {
    case 1:
     
     fp1 = fopen("Patients/database.txt","r");
     char str1[100];
     printf("PatientID                                         NAME\n");
     if(fgets(str1,100,fp1)){
        rewind(fp1);
      while(fgets(str1,100,fp1)){
      printf("%s\n",str1);
      }
     int id;
     printf("\nEnter the id of patient to see record : ");
     scanf("%d",&id);
     char patient_id[100];
     sprintf(patient_id, "%d", id);
     char path1[100];
     
     createPath(path1,patient_id,"profile");
     showProfile(path1);
     }
     else{
        printf("NO DATA TO DISPLAY.\n");
     }

    break;
    case 2:
     fp2 = fopen("doctorVisit.txt","r");
     char str2[100];
     if(fgets(str2,100,fp2)){
       rewind(fp2);
       printf("PatientID       Name                       Doctor                Date\n");
       while(fgets(str2,100,fp2)){
          printf("%s",str2);
        }
     printf("\n");
     }
     else{
        printf("NO DATA TO DISPLAY.\n");
     }
    break;
    default:
        break;
    }
	
}
void doctor_menu() {
    printf("\nEnter password : \n");
    scanf("%s",password);
    printf("\n");
   
    if (strcmp(password,doctor_pass) == 0) {
	    printf("Password is correct. Access granted.\n");
	    doctor_nextmenu();
	} 
    else {
   	 printf("Incorrect password. Access denied.\n");
	}
    main();
}
void patient_menu() {
	printf("\n1. NEW \n2. EXISTING\nEnter any option : ");
	scanf("%d",&opt);
    switch(opt){
        case 1:
         newPatient();
         break;
        case 2:
         existingPatient(); 
         break;
        default:
         printf("Invalid Option.\n"); 
    }
    main();
		
}
void createDate(char *date ){
struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    char d[100];
    strcpy(date,asctime(ptr));
    
}

void createPath(char *path,char *patientid,char *text){
    char filename[MAX_LENGTH];
    sprintf(filename, "Patients/%s_%s.txt",text,patientid);
    strcpy(path,filename);
}
//updatePatient() function
void updatePatient(char *path){
    
    FILE *fptr;
    fptr = fopen(path,"r");
    int id = 0;
    int n = 1;
    int a = 2;
    int s = 3;
    int p = 4;
    int e = 5;
    int ad = 6;
    
    char name[100];
    char age[100];
    char dob[100];
    char sex[100];
    char contact[100];
    char email[100];
    char address[100];
    char c;
    //getting the sex  value
    extractText(fptr,path,3,sex);
    //updating name
    printf("Want to update name?(y/n) : ");
    fflush(stdin);
    getchar();
    scanf("%c",&c);
    if(c == 'y' || c == 'Y'){
        printf("Enter the new name : ");
        getchar();
       // fflush(stdin);
        scanf("%[^\n]s",name);
        //name[strlen(name) - 1] = '\0';
        printf("%s\n",name);
    }
    else{
       char str[100]; 
       extractText(fptr,path,n,str);
       strcpy(name,str);
       printf("%s\n",name);
    }
    
    //updating age
    char c1;
    printf("Want to update age?(y/n) : ");
    fflush(stdin);
    getchar();
    scanf("%c",&c1);
    if(c1 == 'y' || c1 == 'Y'){
        printf("Enter the new age : ");
        fflush(stdin);
        scanf("%s",age);
        printf("%s\n",age);
    }
    else{
       char str[100];
       extractText(fptr,path,a,str);
       strcpy(age,str);
       printf("%s\n",age);
    }
    
    //update the phone number
    char c2;
    printf("Want to update contact?(y/n) : ");
    fflush(stdin);
    getchar();
    scanf("%c",&c2);
    if(c2 == 'y' || c2 == 'Y'){
        printf("Enter the new contact : ");
        fflush(stdin);
        scanf("%s",contact);
        printf("%s\n",contact);
    }
    else{
       char str[100]; 
       extractText(fptr,path,p,str);
       strcpy(contact,str);
       printf("%s\n",contact);
    }
    
    //update the email
    char c3;
     printf("Want to update email?(y/n) : ");
     fflush(stdin);
     getchar();
    scanf("%c",&c3);
    if(c3 == 'y' || c3 == 'Y'){
        printf("Enter the new email : ");
        fflush(stdin);
        scanf("%s",email);
        printf("%s\n",email);
    }
    else{
       char str[100];
       extractText(fptr,path,e,str);
       strcpy(email,str);
       printf("%s\n",email);
    }
    //update the address
    char c4;
     printf("Want to update address?(y/n) : ");
     fflush(stdin);
     getchar();
    scanf("%c",&c4);
    if(c4 == 'y' || c4 == 'Y'){
        printf("Enter the new address : ");
        fflush(stdin);
        fgets(address,100,stdin);
        address[strlen(address) - 1] = '\0';
        printf("%s\n",address);
    }
    else{
       char str[100];
       extractText(fptr,path,ad,str);
       strcpy(address,str);
       printf("%s\n",address);
    }
    //overridding the text file
    char patientid[100];
    char date[100];
    createDate(date);
    extractPD(fptr,path,patientid);
    fptr = fopen(path,"w");
    fprintf(fptr,"PatientID : %s                      Date : %s\n",patientid,date);
    fprintf(fptr,"Name : %s\n",name);
    fprintf(fptr,"Age : %s\n",age);
    fprintf(fptr,"Sex : %s\n",sex);
    fprintf(fptr,"Phone : %s\n",contact);
    fprintf(fptr,"Email : %s\n",email);
    fprintf(fptr,"Address : %s\n",address);
    fclose(fptr);
    removeBlankLines(path);

    
    
}
void extractText(FILE *ptr ,char *path, int i, char *name){
     ptr = fopen(path,"r");
     int j = 0;
     char text[100];
     char str[100];
     while(fgets(str,100,ptr)){
        if(i == j){
         strcpy(text,str);
         break;
        }
        else
         j++; 
     }
     
    char* t = strstr(text, ":") + 2; 
    strcpy(name,t);
}

void extractPD(FILE *ptr,char* path,char *patientid){
    ptr = fopen(path,"r");
    char input[100];
    char p[100];
    char ch[100];
    fscanf(ptr,"%s %s %s",input,ch,p);
    strcpy(patientid,p);
}
//removeBlankLines()
void removeBlankLines(char *filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    // Create a temporary file to write the modified content
    FILE *tempFile = tmpfile();
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    char line[1000];

    // Read each line from the original file
    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Check if the line is empty or contains only whitespace characters
        int isEmpty = 1;
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] != ' ' && line[i] != '\t') {
                isEmpty = 0;
                break;
            }
        }

        // If the line is not empty, write it to the temporary file
        if (!isEmpty) {
            fputs(line, tempFile);
            fputc('\n', tempFile);
        }
    }

    // Close the original file
    fclose(file);

    // Open the original file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing: %s\n", filename);
        fclose(tempFile);
        return;
    }

    // Move the file pointer of the temporary file to the beginning
    rewind(tempFile);

    // Copy the content from the temporary file to the original file
    int c;
    while ((c = fgetc(tempFile)) != EOF) {
        fputc(c, file);
    }

    // Close the temporary file
    fclose(tempFile);

    // Close the original file
    fclose(file);

   
}
