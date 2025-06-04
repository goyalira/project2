#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string userName,email,password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    void login();
    void signUp();
    void forgot();
}obj;

int main(){
    char choice;
    cout<<"\n1- Login";
    cout<<"\n2- Sign Up";
    cout<<"\n3- Forgot Passord";
    cout<<"\n4- Exit";
    cout<<"Enter your Choice :: ";
    cin>>choice;

    switch(choice){
        case '1':
        obj.login();

        break;
        case '2':
        obj.signUp();

        break;
        case '3':
        obj.forgot();

        break;
        case '4':
        return 0;

        break;
        default :
        cout<<"Invalid Selection..!";
    }
}
void temp::signUp(){
    cout<<"Enter your username";
    getline(cin,userName);
    cout<<"Enter your email address";
    getline(cin,email);
    cout<<"Enter your password";
    getline(cin,password);
    
    file.open("logindata.txt",ios::out | ios::app);
    file<<userName<<"*"<<email<<"*"<<password<<endl;
    file.close();
}

void temp::login(){
    cout<<"Login"<<endl;
    cout<<"Enter your Username :: ";
    getline(cin,searchName);
    cout<<"Enter your password :: ";
    getline(cin,searchPass);

    file.open("logindata.txt",ios::in);
    getline(file,userName,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
    if(userName==searchName){
        if(password==searchPass){
            cout<<"\nAccount Login Successfull";
            cout<<"\nusername::"<<userName<<endl;
            cout<<"\nEmail:: "<< endl;
        }
        else{
            cout<<"Password is incorrect...!";
        }
    }
    getline(file,userName,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
}
file.close();

}

void temp::forgot(){
    cout<<"\nEnter your Username:: ";
    getline(cin,userName);
    cout<<"\nEnter your Email Address :: ";
    getline(cin,searchEmail);

    file.open("logindata.txt",ios::in);
    getline(file,userName,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName==searchName){
            if(email==searchEmail){
                cout<<"\nAccount Found..!"<<endl;
                cout<<"Your Password:: "<<password<<endl;

            }
            else{
                cout<<"Not found..!\n";
            }
        }
            else{
                cout<<"Not found!\n";
            }
            getline(file,userName,'*');
            getline(file,email,'*');
            getline(file,password,'\n');

        }
        file.close();
    }
    

