#include <iostream>
using namespace std;

void con(){
    string a,b;
    cout<<"Concatenate two strings..."<<endl;
    cout<<"Enter string 1: ";
    cin>>a;
    cout<<"Enter string 2: ";
    cin>>b;
    cout<<"The result is..."<<endl;
    cout<<a<<b<<endl;
}

void rev(){
    string inp, res;
    cout<<"Enter string to be reversed: ";
    cin>>inp;
    int n = inp.length();
    for(int i=0;i<n;i++){
        res = res + inp[n-i-1];
    }
    cout<<"The reversed string is: "<<res<<endl;
}
void vowel(){
    string inp, res;
    cout<<"Enter the string to remove all vowels from: "<<endl;
    cin>>inp;
    for(int i=0;i<inp.length();i++){
        if(inp[i] != 65 && inp[i] != 69 && inp[i] != 73 && inp[i] != 79 && inp[i] != 85 && inp[i] != 97 && inp[i] != 101 && inp[i] != 105 && inp[i] != 111 && inp[i] != 117){
            res = res + inp[i];
        }
    }
    cout<<"The string without vowels is: "<<res<<endl;
}

void alpha(){
    string inp;
    cout<<"Enter the string to sort in alphabetical order: "<<endl;
    cin>>inp;
    for(int i=0;i<inp.length()-1;i++){
        bool swap=false;
        for(int j=0;j<inp.length()-1-i;j++){
            if (inp[j] > inp[j + 1]) {
                char temp = inp[j];
                inp[j] = inp[j + 1];
                inp[j + 1] = temp;
                swap = true;
            }
        }
        if(!swap){
            break;
        }

    }
    cout<<"The sorted string is: "<<inp<<endl;
}

void utol(){
    string inp;
    cout<<"Enter a string to convert uppercase letter to its lowercase: ";
    cin>>inp;
    for(int i = 0;i<inp.length();i++){
        if(inp[i]>= 65 && inp[i]<=90){
            inp[i]+=32;
        }
    }
    cout<<"The string in lowercase: "<<inp<<endl;
}
int main(){
    cout<<"Strings..."<<endl;
    con();
    rev();
    alpha();
    vowel();
    utol();
    return 0;
}