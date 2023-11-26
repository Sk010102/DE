#include<bits/stdc++.h>
using namespace std;

char dictionary[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#include "decimal.h"
#include "toAnybase.h"

int count(string str){
    int c=0;
    int n = str.length();
    while(n--){
        if(str[c]=='.') break;
        c++;
    }
    return c;
}

string r_S(string str,int base){
    int length = count(str);
    double num = decimal(str,base);
    int num1 = pow(base,length)-num;
    string compliment = toBase(num1,base);
    return compliment;
}

string r1_S(string str,int base){
    int len1 = count(str);
    int len2 = str.length()-len1-1;
    double num = decimal(str,base);
    int num1 = pow(base,len1)-pow(base,-len2)-num;
    string compliment = toBase(num1,base);
    return compliment;

}

int main(){
    cout << "Enter 1 for r's Compliment---\nEnter 2 for (r-1)'s Compliment---\nEnter Choice:";
    int f=2;
    cin >> f;
    if(f!=1 && f!=2){
        printf("Enter correct choice:");
        return 0;
    } 
    string num;
    cout << "Enter Number:";
    cin >> num;
    int base;
    cout << "Enter base:";
    cin >> base;
    cout << r_S(num,base);
    return 0;
}