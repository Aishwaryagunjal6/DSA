#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<climits>
using namespace std;
struct student{
    int roll;
    string name;
    float sgpa;
};

class info{
    public:

    fstream file;
    struct student s;

    void header(){
        file.open("abc.txt", ios::in | ios::out | ios::app);
        file<<"Rollno\t\tSgpa\t\tName"<<endl;
        file.close();
    }

    void addstudent(){
        file.open("abc.txt", ios::in | ios::out | ios::app);
        cout<<"Enter name: ";
        cin>>s.name;
        cout<<"Enter rollno: ";
        cin>>s.roll;
        cout<<"Enter sgpa: ";
        cin>>s.sgpa;

        file<<s.roll<<"\t\t"<<s.sgpa<<"\t\t"<<s.name<<endl;
        file.close();
    }

    void display(){
        file.open("abc.txt", ios::in | ios::out | ios::app);
        string str;
        while(getline(file,str)){
            cout<<str<<endl;
        }
        file.close();
    }

    void search(){
        file.open("abc.txt", ios::in | ios::out | ios::app);
        cout<<"Enter roll no: ";
        int rn;
        cin>>rn;
        string str;
        while(getline(file,str)){
            string arr[3];
            int i=0;
            stringstream input(str);
            while(input.good() && i<3){
                input>>arr[i];
                i++;
            }

            if(to_string(rn)==arr[0]){
                cout<<"Element found! "<<endl;
            }
        }
        file.close();
    }

    void deletestudent(){
        file.open("abc.txt", ios::in | ios::out | ios::app);
        fstream temp;
        temp.open("copy.txt", ios::in | ios::out | ios::app);
        cout<<"Enter roll no: ";
        int rn;
        cin>>rn;
        string str;
        while(getline(file,str)){
            string arr[3];
            int i=0;
            stringstream input(str);
            while(input.good() && i<3){
                input>>arr[i];
                i++;
            }

            if(to_string(rn)==arr[0]){
                cout<<"Element deleted! "<<endl;
            }
            else{
                temp<<arr[0]<<"\t\t"<<arr[1]<<"\t\t"<<arr[2]<<endl;
            }
        }
        file.close();
        temp.close();
        remove("abc.txt");
        rename("copy.txt", "abc.txt");
    }

    void modify(){
        file.open("abc.txt", ios::in | ios::out | ios::app);
        fstream temp;
        temp.open("copy.txt", ios::in | ios::out | ios::app);
        cout<<"Enter roll no: ";
        int rn;
        cin>>rn;
        string str;
        while(getline(file,str)){
            string arr[3];
            int i=0;
            stringstream input(str);
            while(input.good() && i<3){
                input>>arr[i];
                i++;
            }

            if(to_string(rn)==arr[0]){
                string nm;
                float sg;
                cout<<"Enter modified name: ";
                cin>>nm;
                cout<<"Enter modified sgpa: ";
                cin>>sg;
                arr[1]=sg;
                arr[2]=nm;
            }
            
            temp<<arr[0]<<"\t\t"<<arr[1]<<"\t\t"<<arr[2]<<endl;
            
        }
        file.close();
        temp.close();
        remove("abc.txt");
        rename("copy.txt", "abc.txt");
    }
};
int main(){
    info a;
    a.header();
    int ch=1;
    cout<<"Enter no of students: ";
    int n;
    cin>>n;
    for(int i=0; i<n ; i++){
       a.addstudent();
    }
    
    while(ch!=6){
        cout<<"1.display\n2.search\n3.delete\n4.modify\n5.addstudent\nenter: "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
            a.display();
            break;

            case 2:
            a.search();
            break;

            case 3:
            a.deletestudent();
            break;

            case 4:
            a.modify();
            break;

            case 5:
            a.addstudent();
            break;
        }
    }
}
