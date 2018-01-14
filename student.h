typedef struct
{
	int num;
	char name[5];
	int age;
}STUDENT;


struct Courses
{
	int Chineses;
	int Maths;
	int Englishes;
}COURSE;

typedef struct
{
	int num;
	struct Courses degree;
}SCORE;

typedef struct
{
	char name[5];
	char password[5];
}USER;
