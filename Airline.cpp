#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>

using namespace std;

class Airline{
    private:
    string Flight, Des, Dep;
    int Seats;

    public:
    Airline(string flight, string des, string dep, int seats){
        Flight=flight;
        Des = des;
        Dep = dep;
        Seats = seats;
    }

string getFlight(){
    return Flight;
}  

string getDes(){
    return Des;
}

string getDep(){
    return Dep;
}

int getSeat(){
    return Seats;
}

void update(string flight){
    ifstream in("C:/Flight.txt");
    ofstream out("C:/Flight Temp.txt");

    string line;
    while(getline(in,line)){
        int pos = line.find(flight);
        if(pos != string::npos){
            int current = Seats-1;
            Seats = current;
            stringstream ss;
            ss<<current;
            string strCurrent = ss.str();

            int seatPos = line.find_last_of(':');
            line.replace(seatPos+2, string::npos, strCurrent);
           
        }
        out<<line<<endl;

    }
out.close();
in.close();
remove("C:/Flight.txt");
rename("C:/Flight Temp.txt", "C:/Flight.txt");
cout<<"Seat Reserved Sucessfully!"<<endl;
}

};

void display(){
    ifstream in("C:/Flight.txt");
    if(!in){
        cout<<"Error : File Can't Open"<<endl;
    }
    else{
        string line;
        while(getline(in,line)){
            cout<<line<<endl;

        }
    }

}

int main(){
    Airline f1("F101","UAE","England",50);
    Airline f2("F102","UAE","Canada",50);
    Airline f3("F103","India","Germany",100);
    Airline f4("F104","Russia","India",100);

ofstream out("C:/Flight.txt");
if(!out){
    cout<<"Error : File Can't open"<<endl;
}
else{
    out<<f1.getFlight()<<"  : "<<f1.getDes()<<" : "<<f1.getDep()<<" : "<<f1.getSeat()<<endl;

    out<<f2.getFlight()<<"  : "<<f2.getDes()<<" : "<<f2.getDep()<<" : "<<f2.getSeat()<<endl;

    out<<f3.getFlight()<<"  : "<<f3.getDes()<<" : "<<f3.getDep()<<" : "<<f3.getSeat()<<endl;

cout<<"Data Saved Successfully";
out.close();

}

bool exit = false;
while(!exit){
    system("cls");
    cout<<"\t\n Welcome to Airline Management System"<<endl;
    cout<<"\t\n*****************************";
    cout<<"\t\n1.Reserve A seat."<<endl;
    cout<<"\t\n 2.Exit."<<endl;
    cout<<"\t\n Enter Your Choice : "<<endl;

    int val;
    cin>>val;

    if(val==1){
        display();
        string flight;
        cout<<"\nEnter Flight Number = ";
        cin>>flight;
        if(flight == f1.getFlight() && f1.getSeat() > 0){
            f1.update(flight);
        }
        else if(f1.getSeat() <= 0){
            cout<<"\nSorry, Seats not available!"<<endl;
        }

        if(flight == f2.getFlight() && f2.getSeat() > 0){
            f2.update(flight);
        }
        else if(f2.getSeat() <= 0){
            cout<<"\nSorry, Seats not available!"<<endl;
        }

        if(flight == f3.getFlight() && f3.getSeat() > 0){
            f3.update(flight);
        }
        else if(f3.getSeat() <= 0){
            cout<<"\nSorry, Seats not available!"<<endl;
        }

        Sleep(5000);

    }
    else if(val==2){
        system("cls");
        exit = true;
        cout<<"\nGood Luck!"<<endl;
        Sleep(3000);



    }


}
}

    