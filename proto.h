#ifndef proto
#define proto
#include "types.h"
#define max_lines 21 // PLEASE make sure to adjust the number according to maximum lines in the data base file
#define characters 128 //prefer don't play with that , but it's the maximum characters in the line
struct emp{
  u8 name[30];
  u8 phone[15];
  u8 mail[40];
  u8 birthday[10];
  u8 job_title[20];
  struct emp *nxtemp;
  struct emp *prevemp;
}; //employee information
typedef struct emp tstremp;
typedef struct
{
  tstremp* liststart;
  tstremp* listend;
}tstrlist; //employee list
void ADD (void);
/*
        function: To add new candidate by taking her/his info from the user.
        arguments: None.
        return: None.
*/
void LOAD (void);
/*
        function: To load all candidates from a file by taking the file name from the user.
        arguments: None.
        return: None.
*/
void SAVE (void);
/*
        function: To save all candidates in the system in a data file with sorting them alphabiticaly .
        arguments: None.
        return: None.
*/
void EXIT(void);
/*
        function: To exit from the program it has three choices to exit with save or without saving or don't exit.
        arguments: None.
        return: None.
*/
tstremp * SEARCH(u8 *);
/*
        function: To search for a employee by its name and return the pointer of its struct or null if it's not exist.
        arguments: Name of employee to search for.
        return: The pointer to where is it the employee struct and NULL if it's not exist.
*/
void DELETE (void);
/*
        function: To delete a candidate from the system by ask the user about the name.
        arguments: None.
        return: None.
*/
void MODIFY(void);
/*
        function: To modify a candidate by ask the user about the name but it's not allowable to change its name or birthday date.
        arguments: None.
        return: None.
*/
u8 name_validation (u8*);
/*
        function: to make sure that the name doesn't include a number.
        arguments: The name.
        return: 0 if it's okay      --    1 if there's a number.
*/
u8 number_validation (u8*);
/*
        function: to make sure that the phone number doesn't include a letter.
        arguments: The number.
        return: 0 if it's okay      --    1 if there's a letter.
*/
u8 counter(void);
/*
        function: to get the total number of employees.
        arguments: None.
        return: number of employees.
*/
u8 mail_validation(u8*);
/*
        function: to make sure that the mail agent is right it's allowable for gmail/yahoo/outlook/hotmail.
        arguments: The mail.
        return: 0 if it's okay      --    1 if there's another form.
*/
u8 birthday_validation(u8*);
/*
        function: to make sure that the birthday form and range it's okay.
        arguments: The birthday date.
        return: 0 if it's okay      --    1 if there's a problem in range       --       2 there's a problem in the format.
*/
void PRINITING(tstremp*);
/*
        function: to print any candidate information by taking its pointer.
        arguments: The employee pointer , it's prefer using with search as search gets the pointer.
        return: 0 if it's okay      --    1 if there's a number.
*/
void segmentation(u8*phrase ,u8 **token);
/*
        function: to segment any line in the database file by seperated it by the comma.
        arguments: The line wanted to be segmented and the token to put the segmented words on it.
        return: None.
*/
#endif
