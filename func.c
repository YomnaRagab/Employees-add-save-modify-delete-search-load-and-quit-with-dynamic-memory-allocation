#include "proto.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
tstrlist list={NULL,NULL};

void segmentation(u8*phrase ,u8 **token)
{
  u16 i=0;
  token[i]=strtok(phrase,",");
  while(token[i]!=NULL)
  {
    i++;
    token[i]=strtok(NULL,",");
  }
}
u8 counter(void) // get the number of all candidates
{
    u8 i=0;
    tstremp * temp=list.liststart;
    while(temp!=NULL) // if it's not the NULL which means after the end of the list
    {
        temp=temp->nxtemp; // make temp equals the next employee
        i++; // and increase the counter by one
    }
    return(i);
}
u8 name_validation (u8*name)
{
  u8 thereIsaNumber=0;
  u8 i;
  for(i = 0 ; i < strlen(name); i++) //as long as the i is less than the name length count and check for each character
    {
        if((!isalpha(name[i]))&&(name[i]!=' ')) //to make sure that there's no number in the name and not aslo a space , as isalpa function consider the space is not alpha , but here we need the space so we execlude it
        {
            thereIsaNumber = 1; // if there is a number make it one else it won't be changes
            printf("THERE IS A NUMBER\n"); //print it
            break; // and break the loop
        }
    }
    return(thereIsaNumber); //if there's a number it will return zero if not it will change to one
}
u8 number_validation (u8* number)
{
  u8 thereIsaLetter=0;
  u8 i;
  for(i = 0 ; i < strlen(number); i++) //as long as the i is less than the number length count and check for each number
    {
        if(!isdigit(number[i])) //to make sure that there's no letter in the phone number
        {
            thereIsaLetter = 1; // if there is a letter make it one else it won't be changes
            printf("THERE IS A LETTER\n");//print it
            break;// and break the loop
        }
    }
    return(thereIsaLetter);//if there's a letter it will return zero if not it will change to one
}

u8 mail_validation(u8*mail)
{
    u8 j=0;
    u8 k=0;
    u8 temp[40];
        while(mail[j]!='@')//check for the @ to get its position
        {
            j++;
        }
        j++; //increase it by one to get the first letter after @
        while(mail[j]!='.') //check to get the position of .
        {
            temp[k]=mail[j]; //save the mail agent between @ and .
            j++;
            k++;
            if (k>10) return(1); //which means it can't find the dott (.) and there's no mail agent has length more than 10


        }
        if (k!=0)//if k equal zero means the mail format is wrong !
    {
        if(!(strcmp(temp,"gmail")) || !(strcmp(temp,"yahoo")) || !(strcmp(temp,"hotmail")) || !(strcmp(temp,"outlook")))
        {

            return(0); //there's no error
        }
        else{

            return(1); //there's error
        }

        }
        else return(1); //the k=0 so there's error as the form like that @. , there's no letters between the @ and .


}
u8 birthday_validation(u8*bd)
{
    u8 i=0;
    u8 j=0;
    u8 day[3];
    u8 month[3];
    u8 year[5];
    while(bd[i]!='/') //get the day as it's from the start till the first slash
    {
        day[i]=bd[i]; //save it in the day variable
        i++;
        if(i>3) // if i more than 2 which means the birthday format is wrong
        {
            return(2); //then break and return 2
        }
    }
day[i]='\0';
    i++;

    while(bd[i]!='/') //get the month
    {
        month[j]=bd[i];
        i++;
        j++;
        if(j>3)
        {
            return(2);
        }
    }
    month[j]='\0';
    i++;
    j=0;

    while(bd[i]!='\0')
    {
        year[j]=bd[i];
        j++;
        i++;
        if(j>4)
        {
            return(2);
        }
    }
    year[j]='\0';

    u32 year1=atoi(year);
    u32 day1=atoi(day);
    u32 month1=atoi(month);
if((year1>1960) && (year1<1997)&&(month1>0)&&(month1<13)&&(day1<32)&&(day1>0)) //year it has to be in the range more than 1959 and less the 1997 ,and make sure about the day and month ranges
{
    if(month1 == 1 || month1==3 || month1==5 || month1==7 || month1==8 || month1==10 || month1==12) // it has to be less than or equal 31 days for those months
    {
        if(day1<32)
            return(0); // there is no error
        else
            return(1); //there is error
    }
    else if(month1==2)
    {
        if(day1<30) // it has to be less than 30 for february
            return(0); // there is no error
        else
            return(1); //there is error
    }
    else
    {
        if(day1<31) // for other months it has to be less than 31
            return(0); // there is no error
        else
            return(1); //there is error
    }
}
else
    return(1);//there is error

}
void ADD (void)
{
  u8 thereIsaNumber=0;
  u8 thereIsaLetter=0;
  u8 thereIserrorInMail=0;
  u8 thereIserrorInBirthday=0;
  tstremp *ptremployee=(tstremp*)malloc(sizeof(tstremp));
  printf("Enter the ptrempoyee name:");
 //gets(ptremployee->name);
//fgets(ptremployee->name, 20, stdin);
  scanf(" %[^\n]%*c",ptremployee->name);
thereIsaNumber=name_validation(ptremployee->name);
while (thereIsaNumber==1) // as long as there's a number in the name it will try to get the name correct
{
  printf("The name mustn't contain number ,please try again\nEnter the employee name:");
  //fgets(ptremployee->name,30, stdin);
  scanf(" %[^\n]%*c",ptremployee->name);
  //gets(ptremployee->name);
thereIsaNumber=name_validation(ptremployee->name);
}

    printf("Enter the ptrempoyee phone number:");
    scanf(" %s",ptremployee->phone);

    thereIsaLetter=number_validation(ptremployee->phone);
    while (thereIsaLetter==1) // as long as there's a letter in the number it will try to get the number correct
    {
      printf("The phone number mustn't contain number ,please try again\nEnter the employee phone number:");
      scanf(" %s",ptremployee->phone);
      thereIsaLetter=number_validation(ptremployee->phone);
    }

    printf("Enter the ptrempoyee e-mail:");
    scanf(" %s",ptremployee->mail);
    thereIserrorInMail=mail_validation(ptremployee->mail);
    while (thereIserrorInMail==1) // as long as there's a false mail it will try to get the mail form correct
    {
      printf("The mail form is wrong it has to be gmail or yahoo or outlook or hotmail ,please try again\nEnter the employee mail:");
      scanf(" %s",ptremployee->mail);
      thereIserrorInMail=mail_validation(ptremployee->mail);
    }


    printf("Enter the ptrempoyee BD:");
    scanf(" %s",ptremployee->birthday);
    thereIserrorInBirthday=birthday_validation(ptremployee->birthday);
    while (thereIserrorInBirthday==1 || thereIserrorInBirthday==2) // as long as there's a false birthday it will try to get the birthday form or range correct
    {
        if(thereIserrorInBirthday==2)
            printf("The birthday date form is wrong it has to be dd/mm/yyyy ,please try again\nEnter the employee mail:");
        else
            printf("The birthday date range is wrong ,please try again\nEnter the employee mail:");
      scanf(" %s",ptremployee->mail);
      thereIserrorInMail=mail_validation(ptremployee->mail);
    }
    printf("Enter the ptrempoyee job titles:");
    scanf(" %s",ptremployee->job_title);
    // printf("%s\n",ptremployee->name);
    // printf("%d\n",ptremployee->phone);
    // printf("%s\n",ptremployee->mail);
    // printf("%s\n",ptremployee->birthday);
    // printf("%s\n",ptremployee->job_title);
  if (list.liststart ==NULL)
  {
      list.liststart=list.listend=ptremployee;
      ptremployee->nxtemp=ptremployee->prevemp=NULL;
  }
  else
  {
    list.listend->nxtemp=ptremployee;
    ptremployee->prevemp=list.listend;
    list.listend=ptremployee;
    ptremployee->nxtemp=NULL;
  }
}
void LOAD (void)
{
  u8 thereIsaNumber=0;
  u8 thereIsaLetter=0;
  u8 thereIserrorInMail=0;
  u8 thereIserrorInBirthday=0;
  tstremp *temp_ptr;
  u8 filename[20];
  u8 line[max_lines][characters];
  u8 *token[40];
  u8 i=0;
  u8 rows=0;
  FILE *fptr=NULL;
  printf("Enter the file name:");
  scanf(" %s",filename);
  fptr=fopen(filename,"r");
  if (fptr==NULL) exit(-1);
  while(fgets(line[rows],characters,fptr))
  {
    line[rows][strlen(line[rows]-1)]='\0';
    rows++;
  }
  fclose(fptr);
  for(i=0;i<rows;i++)
  {
    segmentation(line[i],token);
    tstremp *ptremployee=(tstremp*)malloc(sizeof(tstremp));
    strcpy(ptremployee->name,token[0]);
    thereIsaNumber=name_validation(ptremployee->name);
    if (thereIsaNumber==1) //  there's a number in the name it will break
    {
        printf("The name mustn't contain number , the error in line number %d\n",i+1);
        break;
    }
    strcpy(ptremployee->phone,token[1]);
    thereIsaLetter=number_validation(ptremployee->phone);
    if (thereIsaLetter==1) // as long as there's a letter in the number it will try to get the number correct
    {
      printf("The phone number mustn't contain number ,the error in line number %d\n",i+1);
      break;
    }
    strcpy(ptremployee->mail,token[2]);
    thereIserrorInMail=mail_validation(ptremployee->mail);
    if (thereIserrorInMail==1) // as long as there's a false mail it will try to get the mail form correct
    {
      printf("The mail form is wrong it has to be gmail or yahoo or outlook or hotmail ,the error in line number %d\n",i+1);
      break;
    }
    strcpy(ptremployee->birthday,token[3]);
    thereIserrorInBirthday=birthday_validation(ptremployee->birthday);
    if (thereIserrorInBirthday==1 || thereIserrorInBirthday==2) // as long as there's a false birthday it will try to get the birthday form or range correct
    {
        if(thereIserrorInBirthday==2)
            printf("The birthday date form is wrong it has to be dd/mm/yyyy ,the error in line number %d\n",i+1);
        else
            printf("The birthday date range is wrong ,the error in line number %d\n",i+1);
    break;
    }
    strcpy(ptremployee->job_title,token[4]);
     if (list.liststart ==NULL)
  {

      list.liststart=list.listend=ptremployee;
      temp_ptr=list.liststart;
      ptremployee->nxtemp=ptremployee->prevemp=NULL;
  }

  else
  {
    list.listend->nxtemp=ptremployee;
    ptremployee->prevemp=list.listend;
    list.listend=ptremployee;
    ptremployee->nxtemp=NULL;

  }
  }
}
tstremp * SEARCH (u8 * name)
{
tstremp * temp=list.liststart;
  if(temp==NULL) // if the list is empty by checking the list start then break and return null
  {
    return(NULL);
  }
  else
  {
      while((strcmp(temp->name,name))&&(temp->nxtemp!=NULL)) temp=temp->nxtemp; //if the name not equal the current employee and the next of current employee is not NULL which means the current employee's not the last one in the list then make the current equal the next
      if(temp->nxtemp!=NULL) temp=temp; //if the next employee not equal null , which means it finds the searched one , so it breaks the above loop then the searched one is the temp one
      else if((temp->nxtemp==NULL)&&(!strcmp(temp->name,name))) temp=temp;// else if nxt employee is NULL so the current employee is the last one , so check for the last employee if it equals to the searched name
      else temp=NULL;// so we didn't find the searched one as we reached to the last elemnet and checked it so the temp equal to NULL
  }
  return(temp);
}
void DELETE (void)
{
    tstremp *data;
    u8 name[30];
    printf("Please enter the name to delete:"); // get the name on deleted one
    scanf(" %[^\n]%*c",name);
    data=SEARCH(name); //search for it in the list and get the pointer of it
    if(data==NULL) // we didn't find it
    {
        printf("The name isn't exist\n");
        printf("1\n");
    }
    else if ((data->prevemp==NULL)&&(data->nxtemp==NULL))//there is only one element in the list and it's the searched one
    {
        list.liststart=list.listend=NULL;//so make the list empty
    }
    else if(data->prevemp==NULL) // the name is the first element in the list
    {
        list.liststart=data->nxtemp; // make the start of the list , next employee of the deleted one
        data->nxtemp->prevemp=NULL;// and the previous of the next employee( which will be the list start ) point to null
    }
    else if(data->nxtemp==NULL) // the name is the last element in the list
    {
        list.listend=data->prevemp; // change the end of the list to be the previous of deleted one
        data->prevemp->nxtemp=NULL; //and the next of the previous of the deleted one(which will be the end of the list) points to null
    }
    else
    {
        data->nxtemp->prevemp=data->prevemp; //the previous of the next employee of the deleted one will be the previous of the deleted element
        data->prevemp->nxtemp=data->nxtemp; //the next of the previous employee of the deleted one will be the next of the deleted element

    }
}

void SAVE (void)
{
    tstremp *tempi=list.liststart;
    tstremp *tempj=tempi->nxtemp;
    u8 count=counter();
    u8 i=0;
    u8 j=1;
    FILE *fptr=NULL;
    u8*name;
    tstremp temp_data;
    //printf("Please enter the file name to load the data in:");
   // scanf(" %s",name);
    fptr=fopen("data.txt","w");
    if (count==1)
    {
        fprintf(fptr,"%s,%s,%s,%s,%s\n",tempi->name,tempi->phone,tempi->birthday,tempi->mail,tempi->job_title);
    }
    for(i=0;i<count-1;i++)
    {
        for(j=i+1;j<count;j++)
        {
        if(strcmp(tempi->name,tempj->name)>0)
        {

            strcpy(temp_data.name,tempi->name);
            strcpy(temp_data.phone,tempi->phone);
            strcpy(temp_data.mail,tempi->mail);
            strcpy(temp_data.birthday,tempi->birthday);
            strcpy(temp_data.job_title,tempi->job_title);


           // printf("%s\t%s\n",tempi->name,temp_data.name);

            strcpy(tempi->name,tempj->name);
            strcpy(tempi->phone,tempj->phone);
            strcpy(tempi->mail,tempj->mail);
            strcpy(tempi->birthday,tempj->birthday);
            strcpy(tempi->job_title,tempj->job_title);


           // printf("%s\t%s\t%s\n",tempi->name,temp_data.name,tempj->name);

            strcpy(tempj->name,temp_data.name);
            strcpy(tempj->phone,temp_data.phone);
            strcpy(tempj->mail,temp_data.mail);
            strcpy(tempj->birthday,temp_data.birthday);
            strcpy(tempj->job_title,temp_data.job_title);


           // printf("%s\t%s\t%s\n",tempi->name,temp_data.name,tempj->name);

        }
        tempj=tempj->nxtemp;
    }
    fprintf(fptr,"%s,%s,%s,%s,%s\n",tempi->name,tempi->phone,tempi->birthday,tempi->mail,tempi->job_title);

   // fwrite(tempi,sizeof(tempi),1,fptr);
   // printf(" %s\n",tempi->name);
   // printf(" %s\n",tempi->phone);
    //printf(" %s\n",tempi->birthday);
    //printf(" %s\n",tempi->mail);
    //printf(" %s\n",tempi->job_title);
    tempi=tempi->nxtemp;
    if(tempi!=list.listend)tempj=tempi->nxtemp;
    else fprintf(fptr,"%s,%s,%s,%s,%s\n",tempi->name,tempi->phone,tempi->birthday,tempi->mail,tempi->job_title);


}
fclose(fptr);
}
void MODIFY(void)
{
    u8 modified_name[30];
    u32 option;
    tstremp *data;
    printf("Enter the name to be modified:");
    scanf(" %[^\n]%*c",modified_name);
    data=SEARCH(modified_name);
    if(data == NULL)
    {
        printf("There's name such like that\n");
    }
    printf("Enter the field which you want to modify:1)E-mail\n2)Birthday date\n3)Job title\nYour choice is:");
    scanf(" %d",&option);
    switch (option)
    {
    case 1:
        printf("Enter the e-mail:");
        scanf(" %s",modified_name);
        strcpy(data->mail,modified_name);
        break;
    case 2:
        printf("Enter the birthday date:");
        scanf(" %s",modified_name);
        strcpy(data->birthday,modified_name);
        break;
    case 3:
        printf("Enter the seniority:");
        scanf(" %s",modified_name);
        strcpy(data->job_title,modified_name);
        break;
    default:
        printf("Wrong choice\n");
        break;
    }
}
void PRINITING(tstremp*data)
{
    printf("Name: %s,phone: %s,Mail: %s,Birthday: %s, Job title: %s\n",data->name,data->phone,data->mail,data->birthday,data->job_title);
}
void EXIT(void)
{
    u32 i=0;
    printf("Do you want to:\n1)Save and exit\n2)Exit without saving\n3)Stay ? ");
    scanf(" %d",&i);
    switch (i)
    {
    case 1:
        SAVE();
        printf("BYE BYE\n");
        exit(-1);
    case 2:
        printf("BYE BYE\n");
        exit(-1);
    case 3:
        break;
    default:
        printf("Error choice\n");
        break;
    }
}
