#include <iostream>
#include <string>

const int studentNum = 50;
enum gender
{
    MALE = 1,
    FEMALE = 2,
}

class Student {
private:
    std::string name;
    int age;
    double grades[5];  // 假设有5门课程

public:
    // 构造函数
    Student(std::string n, int a) : name(n), age(a) {
        // 初始化成员变量
        for (int i = 0; i < 5; ++i) {
            grades[i] = 0.0;
        }
    }

    // 设置学生姓名
    void setName(std::string n) {
        name = n;
    }

    // 获取学生姓名
    std::string getName() const {
        return name;
    }

    // 设置学生年龄
    void setAge(int a) {
        age = a;
    }

    // 获取学生年龄
    int getAge() const {
        return age;
    }

    // 设置某门课程的成绩
    void setGrade(int courseIndex, double grade) {
        if (courseIndex >= 0 && courseIndex < 5) {
            grades[courseIndex] = grade;
        } else {
            std::cerr << "Invalid course index." << std::endl;
        }
    }

    // 获取某门课程的成绩
    double getGrade(int courseIndex) const {
        if (courseIndex >= 0 && courseIndex < 5) {
            return grades[courseIndex];
        } else {
            std::cerr << "Invalid course index." << std::endl;
            return 0.0;
        }
    }



    // 计算平均成绩
    double calculateAverage() const {
        double sum = 0.0;
        for (int i = 0; i < 5; ++i) {
            sum += grades[i];
        }
        return sum / 5.0;
    }

    // 显示学生信息
    void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Grades: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << grades[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Average Grade: " << calculateAverage() << std::endl;
    }
};

struct student
{
	
}

int main(){

	// 创建学生对象
    Student student1("Alice", 20);

	
	//Student* student2 = new Student("Bob", 21);
	Student student2();
	
	Student mary('a', 33);

    // 设置成绩
    student1.setGrade(0, 95.0);

	
    student1.setGrade(1, 85.0);
    student1.setGrade(2, 90.0);
    student1.setGrade(3, 88.0);
    student1.setGrade(4, 92.0);

	int 
	setGrade();

    // 显示学生信息
    student1.displayInfo();

    return 0;
}

int Student::calculate(int score){
	
}

static char a = 's';

void initialize(StringList<Student> students)
{
	int a* = 0;
}



Student::Student(QString name, int age, bool gender, int score): name(name), age(age), gender(gender), score(score)
{
	this->name = 
	setName();
	Student stu;
	stu.name = 
	stu.setName()
}





name = 

Student.name = name;


int Class::todo(){

}



void Student::setGrade()
{
}
