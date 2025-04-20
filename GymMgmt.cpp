#include<iostream>
#include<vector>
using namespace std;
class Member{
    private:
    string name;
    int age;
    bool attendance;
    public:
    Member(string name, int age){
        this -> name = name;
        this -> age = age;
        this -> attendance = false;
    }

    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }

    bool getAttendance(){
        return attendance;
    }

   void setAttendance(bool attendance){
        this -> attendance = attendance;
    }
};


class Gym{
    private:
    vector<Member> ve;

    public:
    void add(string name, int age){
        Member member(name,age);
        ve.push_back(member);
        cout<<"Member Added"<<endl<<endl;
    }

   void markAttendance(string name){
        for(int i=0; i<ve.size(); i++){
            if(ve[i].getName()==name){
            ve[i].setAttendance(true);
    cout<<"Attendance marked for member: "<<ve[i].getName()<<endl;
            }
        }
    }

  void fees(){
        int total=0;
        for(int i=0;i<ve.size();i++){
            if(ve[i].getAttendance()){
        int fees = ve[i].getAge()>20? 200 : 100;
        total += fees; 
            }
        }

        cout<<"Total Fees : "<<total<<endl<<endl;
    }
};

int main(){
    Gym gym;
    cout<<"*****Gym Management*****"<<endl;
    int value;
    while(true){
        cout<<"1. For adding member"<<endl;
        cout<<"2. For marking attendance"<<endl;
        cout<<"3. For total fees"<<endl;
        cout<<"0. For exit"<<endl;
        cout<<"Enter Choice : "<<endl;
        cin>>value;

        if(value==1){
            string name;int age;
            cout<<"Enter Name : ";
            cin>>name;
            cout<<"Enter Age : ";
            cin>>age;
            gym.add(name,age);

        }

        else if(value==2){
            string name;
            cout<<"Enter Name : ";
            cin>>name;
            gym.markAttendance(name);

        }

        else if(value==3){
            gym.fees();
        }

        else if(value==0){
            exit(0);
        }

        else{
            cout<<"Invalid Input";
        }
    }

    return 0;
    
}