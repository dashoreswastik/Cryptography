#include<iostream>
using namespace std;

string encrypt(string msg,int key1,int key2){

    string cphtxt = "";

    for (int i=0;i<msg.length();i++){

        if(msg[i]!=' '){

            if(isupper(msg[i])){

                cphtxt += char((key1 *(msg[i] - 'A')+key2)%26 + 'A');
            }
            else{

                cphtxt += char((key1 *(msg[i] - 'a')+key2)%26 + 'a');
            }
        }
        else{

            cphtxt +=msg[i];
        }


    }
    return cphtxt;


    
}

string decrypt(string cphtxt,int key1,int key2){

    int inv_key1 = 0;
    int inv_key2 = 26 - key2;
    string plaintxt ="";

    for(int i=0;i<26;i++){

        if((key1 * i)%26 == 1){
            inv_key1 = i;
            // cout<<i<<endl;
        }
    }


    for(int i=0;i<cphtxt.length();i++){

        if(cphtxt[i]!=' '){

            if(isupper(cphtxt[i])){

               plaintxt = plaintxt +
                       (char) (((inv_key1 * ((cphtxt[i]+'A' - inv_key2)) % 26)) + 'A');


            }
            else{

                plaintxt = plaintxt +
                       (char) (((inv_key1 * ((cphtxt[i]+'a' - inv_key2)) % 26)) + 'a');
            }


        }else{
            plaintxt += cphtxt[i];
        }
    }

    return plaintxt;

}

int main(){

    string msg;
    cin>>msg;

    const int key1 = 17;
    const int key2 = 20;

    string cph  = encrypt(msg,key1,key2);
    string pltxt = decrypt(cph,key1,key2);

    cout<<"ecrypted text is : "<<cph<<endl;
    cout<<"decrypted text is: "<<pltxt<<endl;

    return 0; 
}