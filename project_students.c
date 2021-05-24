#include<stdio.h>
#include<stdlib.h>
typedef struct student{
    int ID,p_n,c_n,b_n;
    char name[100];
    double av;
}student;
int find_exist_roll(int rno)
{
 FILE *fp;
 student s1;
 int c = 0;
 fp = fopen("record1.txt","r");
 while (!feof(fp))
 {
  fread(&s1, sizeof(student), 1, fp);

  if (rno== s1.ID)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
void border(){
    printf("ID\t\tname\t\t\tp\tc\tb\tav\n-------------------------------------------------------------------------\n");
}
void screen_clear(){
   system("clear");
}
void enter_new_rcd(){
    int  i,exist_R;
    student *s;
    FILE *fp1;
    int s_r;
    fp1=fopen("record1.txt","a");
    printf("How many record you want to save:");
    scanf("%d",&s_r);
    s=(student*)calloc(s_r,sizeof(student));
    for(i=0;i<s_r;i++){
        printf("Enter stdent no-- %d id :",i+1);
        scanf("%d%*c",&s[i].ID);
        exist_R=find_exist_roll(s[i].ID);
        if(exist_R==0){
         printf("Enter student no-- %d name:",i+1);
         gets(s[i].name);
         printf("Enter student no-- %d physics number:",i+1);
         scanf("%d",&s[i].p_n);
         printf("Enter student no-- %d chemistry number:",i+1);
         scanf("%d",&s[i].c_n);
         printf("Enter student no-- %d biology number:",i+1);
         scanf("%d",&s[i].b_n);
         s[i].av=(s[i].p_n+s[i].c_n+s[i].b_n)/3.0;
         fwrite(&s[i], sizeof(student), 1, fp1);
        }
        else{
            printf("%d roll is already exixt in the file\nEnter your id again\n",s[i].ID);
            i--;
        }

    }

    fclose(fp1);
    if(exist_R==0){
         printf("%d records saved successfull\n",s_r);
    }
    sleep(2);
    screen_clear();
}
void  display_rcd(){ 
    char disp[200],ch;   
    FILE *fp1;
    student s1;
    fp1=fopen("record1.txt","r");
    screen_clear();
    border();
    while((fread(&s1, sizeof(student), 1, fp1))){
       printf("%d\t\t%s\t\t\t%d\t%d\t%d\t%lf\n", s1.ID, s1.name, s1.p_n,s1.c_n,s1.b_n,s1.av);
    }
    fclose(fp1);
}
void total_rec(){
    student s1;
    FILE *fp1;
    fp1=fopen("record1.txt","r");
    fseek(fp1,0,SEEK_END);
    int lines=ftell(fp1)/sizeof(student);
    screen_clear();
    printf("\n\t\t\tTotal number of records are : %d\n",lines);
    fclose(fp1);

}
void modify_rcd(){
    student s1,s2;
    int found=0,ro_ll;
    double av;
    FILE *fp1,*fp2;
    fp1=fopen("record1.txt","r");
    fp2=fopen("temp.txt","a");
    printf("Enter the roll you want to update :");
    scanf("%d",&ro_ll);
    while((fread(&s1, sizeof(student), 1, fp1))){
        if(s1.ID==ro_ll){
        printf("Enter stdent id :");
        scanf("%d%*c",&s1);
        printf("Enter student new name:");
        scanf("%s",&s1.name);
        printf("Enter student physics new number:");
        scanf("%d",&s1.p_n);
        printf("Enter student chemistry new number:");
        scanf("%d",&s1.c_n);
        printf("Enter student biology new number:");
        scanf("%d",&s1.b_n);
        s1.av=(s1.p_n+s1.c_n+s1.b_n)/3.0;
        found=1;
        }
        fwrite(&s1,sizeof(student),1,fp2);
    }
    if(found==1){
        printf("\n\tRecord modified successful\n");
    }
    else{
        printf("\n\t%d roll number doesn't exist\n",ro_ll);
    }
   sleep(2);
   screen_clear();
   fclose(fp1);
   fclose(fp2);
   remove("record1.txt");
   rename("temp.txt","record1.txt");

}
void search_rcd(){  
    student s1;
    int found=0,ro_ll;
    double m_av;
    char text[100],disp[100];   
    FILE *fp1;
    fp1=fopen("record1.txt","r");
    printf("Enter the roll you want to search : ");
    scanf("%d",&ro_ll);
    screen_clear();
    border();
    while(fread(&s1,sizeof(student),1,fp1)!=EOF){
        if(s1.ID==ro_ll){
            found=1;
           printf("%d\t\t%s\t\t\t%d\t%d\t%d\t%lf\n", s1.ID, s1.name, s1.p_n,s1.c_n,s1.b_n,s1.av);
            break;
        }
    }
    if(!found){
        printf("Record not found");
    }
    fclose(fp1);
}
void delete_rcd(){
    student s1,s2;
    int found=0,ro_ll; 
    double av;
    FILE *fp1,*fp2;
    char disp[100],save_line[200];
    fp1=fopen("record1.txt","r");
    fp2=fopen("temp.txt","a");
    printf("Enter the roll you want to delete :");
    scanf("%d",&ro_ll);
    screen_clear();
    while((fread(&s1, sizeof(student), 1, fp1))){
        if(s1.ID==ro_ll){
        found=1;
        }
        else{
         fwrite(&s1,sizeof(student),1,fp2);
        }
    }
    if(found==1){
        printf("\n\t\tData deleted successful\n");
    }
    else{
        printf("%d, this number doesn't exist\n");
    }


   fclose(fp1);
   fclose(fp2);
   remove("record1.txt");
   rename("temp.txt","record1.txt");

}
int main(){
    int ch;
    do{
        printf("\n1.Enter new record");
        printf("\n2.Display record");
        printf("\n3.Total number of records");
        printf("\n4.Modify record");
        printf("\n5.search record");
        printf("\n6.Delete record");
        printf("\n0.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
             enter_new_rcd();
             break;
            case 2:
             display_rcd();
              break;
            case 3:
             total_rec();
             break;
            case 4:
              modify_rcd();
             break;
            case 5:
             search_rcd();
             break;
            case 6:
             delete_rcd();
             break;
            
                         
        }
       
    }
    while(ch!=0);
}