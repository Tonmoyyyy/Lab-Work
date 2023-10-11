#include<iostream>
#include<string>
using namespace std;

struct Student{
    int id;
    int creditCompleted;
    int semesterCompleted;
    double cgpa;
};

int main()
{
    Student s[15];
    for(int i=0;i<15;i++)
    {   cout<<"Enter students information :"<<i+1<<endl;

        cout<<"Unique ID :"<<endl;
        cin>>s[i].id;

        cout<<"Credit completed :"<<endl;
        cin>>s[i].creditCompleted;

        cout<<"Semester completed :"<<endl;
        cin>>s[i].semesterCompleted;

        cout<<"CGPA :"<<endl;
        cin>>s[i].cgpa;
    }
    cout<<"Student information who have cgpa more than 3.75 :"<<endl;
    for(int i=0;i<15;i++)
    {
        if(s[i].cgpa>=3.75)
        {
            cout<<s[i].id<<endl;
        }
    }
    cout<<"Student information who completed more than 50 credit :"<<endl;
    for(int i=0;i<15;i++)
    {
        if(s[i].creditCompleted>=50)
        {
            cout<<s[i].id<<endl;
        }
    }
    cout << "Students with at least 2 semesters and 28 credits:" << endl;
    for (int i = 0; i < 15; i++) {
        if (s[i].semesterCompleted >= 2 && s[i].creditCompleted >= 28) {
            cout << "Student ID: " << s[i].id << endl;
        }
    }
    return 0;
}
