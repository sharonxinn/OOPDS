#include <iostream>
#include <string>
using namespace std;

enum class Discipline{ARCHELOGY, BIOLOGY,  COMPUTER_SCIENCE};

const string dName[]=
{
    "ARCHELOGY",
    "BIOLOGY",
    "COMPUTER_SCIENCE"
};

class Person
{
    protected:
    string name;
    public:
    Person()
    {
        setName("");
    }
    Person(const string& pName)
    {
        setName(pName);
    }
    void setName(const string& pName)
    {
        name = pName;
    }
    string getName() const
    {
        return name;
    }
};

class Student: public Person{
    private:
    Discipline major;
    Person* advisor;
    public:
    Student(const string& sname, Discipline d,
    Person*adv)
    {
        name=sname;
        major=d;
        advisor=adv;
    }
    void setMajor(Discipline d)
    {
        major=d;
    }
    Discipline getMajor() const
    {
        return major;
    }
    void setAdvisor(Person* adv)
    {
        advisor=adv;
    }
    Person* getAdvisor() const
    {
        return advisor;
    }
};

class Faculty: public Person{
    private:
    Discipline department;
    public:
    Faculty(const string& fname, Discipline d)
    {
        name=fname;
        department=d;
    }
    void setDepartment(Discipline d)
    {
        department=d;
    }
    Discipline getDepartment() const
    {
        return department;
    }
};

int main()
{
    Faculty *prof = new Faculty("Dr. Smith", Discipline::BIOLOGY);
    Student *stu= new Student("Alice", Discipline::COMPUTER_SCIENCE, prof);
    cout <<"Professor: " << prof->getName() << "teaches"<< dName[static_cast<int>(prof->getDepartment())] << "." << endl;

    Person* pAdvisor = stu->getAdvisor();
    cout <<stu->getName() << "is advised by" << pAdvisor->getName() << "." << endl;

    delete prof;
    prof = nullptr;

    delete stu;
    stu = nullptr;

    return 0;

}