#include <iostream>
#include <fstream>
const char CDfv[] = "U1.txt";
const char CDfr[] = "U1rez.txt";
const int CMax = 10;

using namespace std;
void Skaityti(int B1[],int B2[],int B3[], int& n, int& d1, int& d2, int& d3);
void Skyrius (int B1[],int B2[],int B3[], int& n, int& t1, int& t2, int& t3, int max, int& s1, int& s2, int& s3);
void Geriausia(int& t1, int& t2, int& t3, int& d1, int& d2, int& d3, int & max);
int main()
{
    int B1[CMax], B2[CMax], B3[CMax], n, t1, t2, t3, max, s1, s2, s3, d1, d2, d3;
    max = 0;
    ofstream fd(CDfr);
    Skaityti(B1, B2, B3, n, d1, d2, d3);
    Skyrius (B1, B2, B3, n, t1, t2, t3, max, s1, s2, s3);
    fd<<s1<<" "<<s2<<" "<<s3<<endl;
    fd<<t1<<" "<<t2<<" "<<t3<<endl;
    Geriausia(t1, t2, t3, d1, d2, d3, max);
    if(t1==max) fd<<"1";
    if(t2==max) fd<<"2";
    if(t3==max) fd<<"3";
    return 0;
}


void Skaityti(int B1[],int B2[],int B3[], int& n, int& d1, int& d2, int& d3)
{
    ifstream df(CDfv);
    df>>n;
    for(int i=0;i<n;i++)
    {
        df>>B1[i]>>B2[i]>>B3[i];
    }
    df>>d1>>d2>>d3;
}

void Skyrius (int B1[],int B2[],int B3[], int& n, int& t1, int& t2, int& t3, int max, int& s1, int& s2, int& s3)
{
    s1=0;
    s2=0;
    s3=0;
    t1=0;
    t2=0;
    t3=0;
    for (int i=0;i<n;i++)
    {
        max=0;
        if(B1[i]>B2[i]) max=B1[i];
        else max=B2[i];
        if (max<B3[i]) max=B3[i];
        if(B1[i]==max&&B1[i]!=B2[i]&&B1[i]!=B3[i]) t1=t1+4;
        else if(((B1[i]==max&&B1[i]==B2[i])||(B1[i]==B3[i]))&&(B1[i]!=B2[i]!=B3[i])) t1 =t1+2;
        if(B2[i]==max&&B1[i]!=B2[i]&&B2[i]!=B3[i]) t2=t2+4;
        else if(((B2[i]==max&&B1[i]==B2[i])||(B2[i]==B3[i]))&&(B1[i]!=B2[i]!=B3[i])) t2 =t2+2;
        if(B3[i]==max&&B3[i]!=B2[i]&&B1[i]!=B3[i]) t3=t3+4;
        else if(((B3[i]==max&&B3[i]==B2[i])||(B1[i]==B3[i]))&&(B1[i]!=B2[i]!=B3[i])) t3 =t3+2;
        s1=s1+B1[i];
        s2=s2+B2[i];
        s3=s3+B3[i];
    }
}

void Geriausia(int& t1, int& t2, int& t3, int& d1, int& d2, int& d3,int & max)
{
    max=0;
    if (t1==t2||t1==t3||t2==t3) {
        t1=t1+d1;
        t2=t2+d2;
        t3=t3+d3;
    }
    if(t1>max) max=t1;
    if(t2>max) max=t2;
    if(t3>max) max=t3;
}
