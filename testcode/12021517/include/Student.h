#ifndef STUDENT_H
#define STUDENT_H

class Student
{

public:
	Student Student(char* str, int integer);

	Student Student();

	Student Student(char c, int integer);

	void setName();

	void setGrade(int integer, double decimal);

	void displayInfo(char* str);



private:
};
#endif //STUDENT_H
