#define highest_char 100
#define MAX_STUDENTS 100

// Define the structure
struct Student_data {
    char name[highest_char];
    int student_id;
    int wants_enrolment;
};

// Function prototypes
void clearInputBuffer();
void openingMessage();
void saveStudentNameToFile(const char *student_name, const int stdid, const int enrolled_in_courses);
void optionChoose(struct Student_data *student);