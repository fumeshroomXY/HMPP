int main(){

Student student1("Alice", 20);
	
	Student student2();
	student2->setName();
	
	Student mary('a', 33);

    // ���óɼ�
    student1.setGrade(0, 95.0);
    student1.setGrade(1, 85.0);
    student1.setGrade(2, 90.0);
    student1.setGrade(3, 88.0);
    student1.setGrade(4, 92.0);

    // ��ʾѧ����Ϣ
    student1.displayInfo();

    return 0;
}