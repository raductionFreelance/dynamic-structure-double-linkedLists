#include <iostream>
#include <string>
using namespace std;

//3
class Transport{
public:
    virtual void price() = 0;
    virtual ~Transport() = default;
    
};

class Auto : public Transport{
public:
    int t, v, s, p1k;
    
    Auto(const int& v, const int& s, const int& p1k) : v(v), s(s), p1k(p1k) {};
    
    void price() override{
        int price = 0;
        t = s / v;
        price = p1k * s;
        cout << "Your time for trip: " << t << " hours, your money, which were spent fot this one, is " << price << endl;
    }
};

class Bike : public Transport{
public:
    int t, v, s, p1k;
    
    Bike(const int& v, const int& s, const int& p1k) : v(v), s(s), p1k(p1k) {};
    
    void price() override{
        int price = 0;
        t = s / v;
        price = p1k * s;
        cout << "Your time for trip: " << t << " hours, your money, which were spent fot this one, is " << price << endl;
    }
};

class Cart : public Transport{
public:
    int t, v, s, p1k;
    
    Cart(const int& v, const int& s, const int& p1k) : v(v), s(s), p1k(p1k) {};
    
    void price() override{
        int price = 0;
        t = s / v;
        price = p1k * s;
        cout << "Your time for trip: " << t << " hours, your money, which were spent fot this one, is " << price << endl;
    }
};



//1
class Student{
private:
    string name;
    int age;
    string university, faculty, specialty;
    int course;
    double averageMark;
public:
    Student(const string& name, const int& age, const string& university, const string& faculty, const string& specialty, const int& course, const double& avarageMark) : name(name), age(age), university(university), faculty(faculty), specialty(specialty), course(course), averageMark(avarageMark) {};
    
    virtual ~Student() = default;
    
    void printInfo() const {
            cout << "Name: " << name << "\nAge: " << age << "\nUniversity: " << university
                 << "\nFaculty: " << faculty << "\nSpecialty: " << specialty << "\nCourse: " << course
                 << "\nAverage Mark: " << averageMark << endl;
        }
    
};

class Aspirant : public Student{
private:
    string researchTopic, supervisor, degree;
    int publications;
public:
    Aspirant(const string& name, int age, const string& university, const string& faculty, const string& specialty, int course, double averageMark, const string& researchTopic, const string& supervisor, const string& degree, int publications) : Student(name, age, university, faculty, specialty, course, averageMark), researchTopic(researchTopic), supervisor(supervisor), degree(degree), publications(publications) {};
    
    void printInfo() const {
            Student::printInfo();
            cout << "Research Topic: " << researchTopic << "\nSupervisor: " << supervisor
                 << "\nDegree: " << degree << "\nPublications: " << publications << endl;
        }
};



int main() {
    Transport* bike = new Bike(15, 30, 0);
    Transport* car = new Auto(90, 1000, 2);
    Transport* cart = new Cart(10, 30, 1);
    
    bike->price();
    car->price();
    cart->price();
    
    delete bike;
    delete car;
    delete cart;
    
    Student s1("Ivan Ivanov", 20, "Kyiv University", "Computer Science", "Software Engineering", 2, 4.5);
    Aspirant a1("Olena Petrenko", 24, "Kyiv University", "Physics", "Quantum Mechanics", 1, 4.8, "Quantum Computing", "Dr. Shevchenko", "PhD", 3);

    cout << "---Student Info---" << endl;
    s1.printInfo();

    cout << "\n---Aspirant Info---" << endl;
    a1.printInfo();

    return 0;
    

    return 0;
}
