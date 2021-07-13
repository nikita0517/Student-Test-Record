#include<stdio.h>
 #include<stdlib.h>
 int roll_number, marks[3], total;
 char name[15];
float percentage;
FILE *file;
void add_new_student_details()
{ system("cls");
file = fopen("SRS.txt", "a");
 printf("\nEnter roll number: ");
 scanf("%d", &roll_number);
 printf("Enter name: ");
  scanf("%s", name);
  fprintf(file, "%d %s ", roll_number, name);
  total = 0;
  for(int i = 0; i <= 2; i++) {
      printf("Enter marks of subject %d: ", i + 1);
  scanf("%d", &marks[i]);
  fprintf(file, "%d ", marks[i]);
  total += marks[i];
  }
   percentage = (float)total / 3;
    fprintf(file, "%d %f ",total, percentage);
    fclose(file);
    printf("\nStudent details are added successfully\n");
    }
    void view_all_students_details()
    {
         system("cls");
     file = fopen("SRS.txt", "r");
     if(file != NULL)
        {
         printf("\nDetails of all students are\n");
    while(fscanf(file, "%d%s", &roll_number, name) != EOF)
        {
            printf("\nRoll Number: %d\nName: %s\n", roll_number, name);
    for(int i = 0; i <= 2; i++)
        {
            fscanf(file, "%d", &marks[i]);
    printf("Marks of subject %d: %d\n", i + 1, marks[i]);
    }
    fscanf(file, "%d%f", &total, &percentage);
    printf("Total: %d\nPercentage: %.2f\n", total, percentage); }
     fclose(file);
     }
     else {
          printf("\nNo student details to view\n");
          }
           }
     void search_student_details()
     {
         system("cls");
     file = fopen("SRS.txt", "r");
      if(file != NULL)
      {
            int r_no, found = 0;
      printf("\nEnter roll number: ");
      scanf("%d", &r_no);
      while(fscanf(file, "%d%s", &roll_number, name) != EOF)
        {
          for(int i = 0; i <= 2; i++) {
                fscanf(file, "%d", &marks[i]);
      }
          fscanf(file, "%d%f", &total, &percentage);
          if(roll_number == r_no) {
              found = 1;
               printf("\nRoll Number: %d\nName: %s\n", roll_number, name);
           for(int i = 0; i <= 2; i++) {
                printf("Marks of subject %d: %d\n", i + 1, marks[i]); }
           printf("Total: %d\nPercentage: %.2f\n", total, percentage);
            break;
            }
            }
            if(!found)
                {
                printf("\nStudent of %d roll number does not exist\n", r_no); }
                fclose(file);
                 }
                else {
                    printf("\nNo student details to search\n"); }
                    }
int main()
                     {
                        int ch;
                         do
                            {
                system("cls");
                printf("\nEnter 1 to add new student details\n");
                printf("Enter 2 to view all students details\n");
                printf("Enter 3 to search student details\n");
                 printf("Enter 4 to exit from application\n");
                 printf("Enter your choice: ");
                 scanf("%d", &ch);
                  switch(ch) {
    case 1:
                          add_new_student_details();
                           break;
     case 2:
          view_all_students_details();
                       break;
     case 3:
          search_student_details();
                       break;
    case 4:
                      exit(0);
    default:
printf("\nWrong choice entered\n");
 }
          printf("\nEnter 0 to goto main menu\n");
          scanf("%d", &ch);
          }
 while(ch == 0);
 return 0; }
