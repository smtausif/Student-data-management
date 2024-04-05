#include <stdio.h>
#include "main.h"

void clearInputBuffer(){
    while (getchar() != '\n');
}

void openingMessage(void){
    printf("\n");
    printf("**************************************\n");
    printf("Welcome to the STUDENT DATA MANAGEMENT\n");
    printf("**************************************\n");
    printf("\n");
}

void saveStudentNameToFile(const char *student_name, const int stdid, const int enrolled_in_courses){

    static int count = 0; // Make count static

    FILE *fileptr = NULL;
    fileptr = fopen("student_data.txt", "a");
    
    if (fileptr != NULL)
    {
        if (count == 0)
        {
            fprintf(fileptr, "Students             id     courses\n");
            count++;
        }
        fprintf(fileptr, "%-20s%-10d%-30d\n", student_name, stdid, enrolled_in_courses);   
        fclose(fileptr); // Close the file after writing
    }
    else{
        printf("Error opening file\n");
    }
}


void overview(void){
    char content[30000];

    FILE *fileptr = NULL;
    fileptr = fopen("student_data.txt", "r");

    if (fileptr != NULL)
    {
        while (fgets(content, 3000, fileptr))
        {
            printf("-----------------------------------\n");
            printf("%s", content);
        }      
    }else{
        printf("File open denied");
    }
    
}

void optionChoose(struct Student_data *student){
    int option;

    while (option != 0) // the loop will continue unless the user puts 0
    {

    printf("---------------------------\n");
    printf("1 - Enter new student data \n");
    printf("2 - Overview\n");
    printf("3 - Delete specific data\n");
    printf("0 - exit\n");
    printf("---------------------------\n");
    printf("\n");

    printf("Choose your option: ");
    scanf("%d", &option);
    printf("\n");

    clearInputBuffer(); // Clearing the input buffer after the first int input

    
    if (option == 1)
    {
        printf("-------------------------------------------\n");
        printf("Enter the student name: ");  // Asking for name and storing it in student->name
        scanf("%99[^\n]", student->name);

        printf("Enter the student ID  : ");  // Asking for ID and storing it in student->student_id
        scanf("%d", &student->student_id);

        printf("Amount of courses     : ");
        scanf("%d", &student->wants_enrolment);
        printf("--------------------------------------------\n");

        // Save student data to file
        saveStudentNameToFile(student->name, student->student_id, student->wants_enrolment);
        printf("DATA ADDED TO THE \'student_data.txt\' FILE\n\n");
    }
    else if (option == 2)
    {   
        overview();
        printf("\n");
    }
    }    
}

int main(void){
    struct Student_data students[MAX_STUDENTS];
    int numStudents;

    openingMessage();
    optionChoose(&students[0]); // Pass the address of the first element of the students array

    return 0;
}