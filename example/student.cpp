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
    double grades[5];  // ������5�ſγ�

public:
    // ���캯��
    Student(std::string n, int a) : name(n), age(a) {
        // ��ʼ����Ա����
        for (int i = 0; i < 5; ++i) {
            grades[i] = 0.0;
        }
    }

    // ����ѧ������
    void setName(std::string n) {
        name = n;
    }

    // ��ȡѧ������
    std::string getName() const {
        return name;
    }

    // ����ѧ������
    void setAge(int a) {
        age = a;
    }

    // ��ȡѧ������
    int getAge() const {
        return age;
    }

    // ����ĳ�ſγ̵ĳɼ�
    void setGrade(int courseIndex, double grade) {
        if (courseIndex >= 0 && courseIndex < 5) {
            grades[courseIndex] = grade;    //����Student��û��grades��Ա���ԣ���.h�ļ������ɳ�Ա����
        } else {
            std::cerr << "Invalid course index." << std::endl;
        }
    }

    // ��ȡĳ�ſγ̵ĳɼ�
    double getGrade(int courseIndex) const {
        if (courseIndex >= 0 && courseIndex < 5) {
            return grades[courseIndex];
        } else {
            std::cerr << "Invalid course index." << std::endl;
            return 0.0;
        }
    }

    // ����ƽ���ɼ�
    double calculateAverage() const {
        double sum = 0.0;
        for (int i = 0; i < 5; ++i) {
            sum += grades[i];
        }
        return sum / 5.0;
    }

    // ��ʾѧ����Ϣ
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