#include<iostream>
using namespace std;

string encrypt(string mesg,int key){

    string s = "";

    for(int i=0;i<mesg.length();i++){

        if(isupper(mesg[i])){

            s += char(int(mesg[i]+key-65)%26 +65); 

        }
        else{

            s += char(int(mesg[i]+key-97)%26 +97);
        }
    }

    return s;
}
string decrypt(string mesg,int key){

    string s = "";

    for(int i=0;i<mesg.length();i++){

        if(isupper(mesg[i])){

            s += char(int(mesg[i]-key-65)%26 +65); 

        }
        else{

            s += char(int(mesg[i]-key-97)%26 +97);
        }
    }

    return s;
}

int main(){

    string mesg;
    int key;
    cin>>mesg;

    cin>>key;
    string t= encrypt(mesg,key);

    cout<<"encrypted message is :"<<t<<endl;

    cout<<"decrypted method is :"<<decrypt(t,26-key);

    return 0;



}