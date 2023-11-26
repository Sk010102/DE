#include<bits/stdc++.h>

using namespace std;
char dictionary[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


void IP(string s,string &iS,string &oS,int &iP,int &oP){
    iS = "",oS = "",iP = 0,oP = 0;
    for(iP=0;s[iP]!='.';iP++){
        if(s[iP]=='\0') return;
        iS+=s[iP];
    }
    for(oP=iP+1;s[oP]!='\0';oP++){
        if(s[oP]=='.'){
            printf("Error: Invalid Number!!");
            iP=0;oP=0;iS="";oS="";
            return;
        }
        oS+=s[oP];
    }
    oP = oP-iP-1;
}

double decimal(string s,int base){
    string s1,s2;
    int iP,oP;
    IP(s,s1,s2,iP,oP);
    iP--;
    double num=0;
    int sl1 = s1.length();
    for(int i=0;i<sl1;i++){
        int k;
        if(s[i]>='A' && s[i]<='Z') k = s[i]-'A'+10;
        else k = s[i]-'0';
        if(k>=base){
            printf("Invalid Number!\n");
            return 0;
        }
        num = num + k*pow(base,iP--);
    }
    int power = -1;
    int sl2 = s2.length();
    for(int i=0;i<sl2;i++){
        int k;
        if(s[i]>='A' && s[i]<='Z') k = s[i]-'A'+10;
        else k = s[i]-'0';

        if(k>=base){
            printf("Invalid Number!\n");
            return 0;
        }
        num = num + k*pow(base,power--);
    }
    return num;
}



string reverse(string s){
    string k="";
    for(int i=s.length()-1; i>=0;i--){
        k+=s[i];
    }
    return k;
}


string fraction1(double num,int base){
    string k=".";
    int a = 5;
    while(num!=0 || a--){
        num = num * base;
        int i = (int)num;
        num-=i;
        k+=dictionary[i];
    }
    return k;
}

string toBase(double num,int base){
    int integer = (int)num;
    double fraction = num - integer;
    string fractional = fraction1(fraction,base);
    string num1="";
    while(integer>0){
        num1+=dictionary[integer%base];
        integer/=base;
    }
    num1 = reverse(num1);
    return num1+fractional;
}

int main(){
    string Num;
    int base1,base2;
    cout << "Enter Number:";
    cin >> Num;    
    cout << "Base of Entered Number:";
    cin >> base1;
    cout << "Base of Output Number:";
    cin >> base2;
    if(base1>=63 || base2>=63){
        printf("BASE EXCEEDED!!");
        return 0;
    }
    double Decimal = decimal(Num,base1);
    cout << toBase(Decimal,base2);
    return 0;
}