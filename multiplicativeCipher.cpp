#include<iostream>
using namespace std;

string encrypt(string msg,int key){

    string ciphertext ="";

    for(int i=0;i<msg.length();i++){

        if(isupper(msg[i])){

            ciphertext +=   char(int((msg[i] -65)* key)%26 +65);
        }
        else{

            ciphertext += char(int((msg[i]-97) * key)%26 + 97);
        }


    }
     return ciphertext;
    //  cout<<ciphertext<<endl;


}
int modinverse(int key){

    for(int i=1;i<26;i++){
        if(((key%26) *(i%26))%26 == 1)
            return i;
    }



}

string decrypt(string cpt,int key){

    int k = modinverse(key);

    string plaintxt =  encrypt(cpt,k);
    return plaintxt;
}

int main(){

    string msg;
    cin>>msg;

    int key;
    //remember for decryption to be possible,key should be coprime with 26
    cin>>key;
    string ciphertxt = encrypt(msg,key);
    string plaintxt = decrypt(ciphertxt,key);
    cout<<"encrypted text is:"<<ciphertxt<<endl;
    cout<<"decrypted text is:"<<plaintxt<<endl;

    return 0;
}

