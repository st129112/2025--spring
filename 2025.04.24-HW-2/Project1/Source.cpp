#include <iostream>
#include <string>

class Student {
private:
    int blood_type;
    std::string name;

public:
    Student(std::string name, int blood_type = 0) {
        this->name = name;
        this->blood_type = blood_type;
    }
    int getBloodType() {
        return blood_type;
    }
    std::string getName() {
        return name;
    }
    void setName(std::string name) {
        bool hasSpace = false;
        for (char c : name) {
            if (c == ' ') {
                hasSpace = true;
                break;
            }
        }
        if (!hasSpace && !name.empty() && isupper(name[0])) {
            this->name = name;
        }
        else {
            std::cout << "Error\n";
        }
    }
};
int main() {
    std::string name;
    int bloodType;

    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Blood type: ";
    std::cin >> bloodType;

    Student student(name, bloodType);
    student.setName(name);

    if (!student.getName().empty() && isupper(student.getName()[0])) {
        std::cout << "Name: " << student.getName() << "\n";
        std::cout << "Blood type: " << student.getBloodType() << "\n";
    }

    return 0;
}