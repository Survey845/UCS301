#include <iostream>
using namespace std;

int arr1[50], arr2[50], n;
void create(){
    cout<<"Creating an array..."<<endl;
    cout<<"Enter the lenght of your array: ";
    cin>>n;
    if(n>50){
        cout<<"Please select n less than 50..."<<endl;
    } else{
    for(int i = 0;i<n;i++){
        cout<<"Enter the element at index "<<i<<": ";
        cin>>arr1[i];
    }
}

}
void display(){
    for(int j=0;j<n;j++){
        cout<<arr1[j]<<" ";
    }
    cout<<endl;
}
void insert(){
    int el, ind;
    cout<<"Enter the new element: ";
    cin>>el;
    cout<<"Enter the index of new el: ";
    cin>>ind;
    n+=1;
    for(int l = n; l>ind; l--){
        arr1[l]=arr1[l-1];
    }
    arr1[ind] = el;
}
void del(){
    int ind;
    cout<<"Enter the index of the element you want to delete: ";
    cin>>ind;
    n-=1;
    for(int m = ind;m<n;m++){
        arr1[m] = arr1[m+1];
    }
}
void lsearch(){
    int el;
    cout<<"Enter the element you want to search for: ";
    cin>>el;
    for(int r = 0;r<n;r++){
        if(arr1[r]==el){
            cout<<"The position of element is index: "<<r<<endl;
            return;
        }
    }
    cout<<"Element not in array..."<<endl;
}

int main(){
    int command;
    bool check = true;
    while(check==true){
        cout<<"--- MENU ---"<<endl;
        cout<<"1. CREATE"<<endl;
        cout<<"2. DISPLAY"<<endl;
        cout<<"3. INSERT"<<endl;
        cout<<"4. DELETE"<<endl;
        cout<<"5. LINEAR SEARCH"<<endl;
        cout<<"6. EXIT"<<endl;
        cout<<"Enter the serial number of the command you want to run: ";
        cin>>command;
        switch(command){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                del();
                break;
            case 5:
                lsearch();
                break;
            case 6:
                check = false;
                cout<<"Logging out..."<<endl;
                break;
        }

    }
    return 0;
}