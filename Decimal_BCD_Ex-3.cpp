#include<iostream>
using namespace std;

//Function to convert Decimal to Binary Coded Decimal(BCD).
void Dec_BCD(int n, float arr[]){
    int i = 3;
    while(n>0){
        arr[i] = n%2;  //stores the reminder in array
        n = n/2;
        i--;  //loop is in reverse since the '%' gives our required answer in reverse order.
    }
}

//Function to convert Binary Coded Decimal(BCD) to Excess-3.
void BCD_XS3(int n, float arr[]){
    float arr1[]={0,0,1,1};              //0011 i.e 3 for addition.
    float sum[4]={},carry[4];           

    for(int i=3;i>=0;i--){          //reverse loop. since we add no.s from LSB.
        sum[i]=arr[i]+arr1[i]+carry[i]; 
        if(sum[i]==2)          //when carry is 1 & either BCD or 0011 is 1. So addition result 2.
        {              
            sum[i]=0;
            carry[i-1]=1;
        }
        else if (sum[i]==3)    //when carry, BCD & 0011 is 1. So addition result 3.
        {
            sum[i]=1;
            carry[i-1]=1;
        }
        else{
            carry[i-1]=0;
        } 
    }
    for(int i=0;i<4;i++){
            cout << sum[i];  //displays the result of sum i.e Ex-3.
        }
}

int main(){
    int n;
//initialized w/ 0 otherwise when the bcd is only 3 or 2 digits rest of the array elmts will be garbage.
//Float data type is used because '%' operation returns value in float.
    float arr[4]={0,0,0,0}; 
    cout << "Enter decimal no. ";
    cin>>n;
    if(n<10){  //Since BCD and EX-3 both require more than 5 bits to represent no. >9.
        cout<<"BCD equivalent is ";
        Dec_BCD(n,arr); // converts decimal to BCD.
        for(int i=0;i<4;i++){
            cout << arr[i];   //displays BCD result.
        }
        cout <<"\n";
        cout<< "Excess-3 equivalent is ";
        BCD_XS3(n,arr);   //converts and displays Ex-3 result.
    }
    else{
        cout << "\nERROR!!! The decimal number can't be represented in BCD and Excess-3 using only 4 bits.\n\n";
    }
    
    return 0;
}
