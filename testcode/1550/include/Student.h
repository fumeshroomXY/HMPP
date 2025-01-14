#ifndef STUDENT_H
#define STUDENT_H

class Student
{

public:
	Student Student(QString name, int age, bool gender, int score);

	Student Student(char* str, int integer);

	Student Student();

	Student Student(char c, int integer);

	UNSPECIFIED setGrade(int integer, double decimal);

	UNSPECIFIED displayInfo();

	UNSPECIFIED setName();

	int calculate(int score);

	void setGrade();

	QString getName() const { return name; }

	void setAge(const int& value){ age = value; }

	int getAge() const { return age; }

	void setGender(const bool& value){ gender = value; }

	bool getGender() const { return gender; }

	void setScore(const int& value){ score = value; }

	int getScore() const { return score; }



private:
	QString name;

	int age;

	bool gender;

	int score;

};
#endif //STUDENT_H
