#include <iostream>
#include <string>


int main() {
    // ����ѧ������
    Student student1("Alice", 20);    //������Ŀ������ͼ��û��Student�࣬����Ŀ�ļ�������student.cpp��student.h

    // ���óɼ�
    student1.setGrade(0, 95.0);     //����Student��û��setGrade��Ա���������ڶ�Ӧ.cpp��.h�ļ������ɺ���ʵ�ֺ�����
    student1.setGrade(1, 85.0);
    student1.setGrade(2, 90.0);
    student1.setGrade(3, 88.0);
    student1.setGrade(4, 92.0);

    // ��ʾѧ����Ϣ
    student1.displayInfo();

    return 0;
}

void initialize(StringList<Student> students)
{
    
}

