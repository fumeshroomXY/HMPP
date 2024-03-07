#include <iostream>
#include <string>


int main() {
    // 创建学生对象
    Student student1("Alice", 20);    //发现项目的类视图中没有Student类，在项目文件中生成student.cpp和student.h

    // 设置成绩
    student1.setGrade(0, 95.0);     //发现Student类没有setGrade成员函数，则在对应.cpp和.h文件中生成函数实现和声明
    student1.setGrade(1, 85.0);
    student1.setGrade(2, 90.0);
    student1.setGrade(3, 88.0);
    student1.setGrade(4, 92.0);

    // 显示学生信息
    student1.displayInfo();

    return 0;
}

void initialize(StringList<Student> students)
{

}

