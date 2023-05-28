#include "example.h"
#include <string.h>
#include <iostream>
using namespace std;
namespace Fun1 {
    //  ôóíêö³ÿ - øàáëîí
    template <typename T>
    void Search(T A[], int n) {
        T max = A[0], min = A[0];
        int mi = 0, ma = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (A[i] > max) { max = A[i]; ma = i; }
            if (A[i] < min) { min = A[i]; mi = i; }
        }
        A[ma] = min;
        A[mi] = max;
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    //ñïåöèô³êàö³ÿ ôóíêö³¿ - øàáëîí äëÿ òèïó char*
    template<>  void Search(char* A[], int n)
    {
        char* max = A[0]; char* min = A[0];
        int mi = 0, ma = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (strcmp(max, A[i]) == 1) { max = A[i]; ma = i; }
            if (strcmp(A[i], min) == 1) { min = A[i]; mi = i; }
        }
        A[ma] = min;
        A[mi] = max;
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    int smain()
    {
        char* t1 = (char*)"text"; char* t2 = (char*)"tzsha";
        cout << strcmp(t1, t2) << endl;
        cout << "template\n";
        int  a[10] = { 1,7,2,-1,0,11,7,2,8,0 };
        double t[10] = { 2,8,9.2,0.2,6.3,8.76,8.7,12,12.8,10 };
        char  s[10] = { 'a','u','c','p','s','b','z','s','s','t' };
        cout << "Int: " << endl;
        Search(a, 10);
        cout << "Double: " << endl;
        Search(t, 10);
        cout << "Char: " << endl;
        Search(s, 10);
        cout << "Char* " << endl;
        char* b[5] = { (char*)"zext",(char*)"bogaboga",(char*)"abo",(char*)"texta",(char*)"sasha" };
        Search(b, 5);
        return 0;
    }
}
void example1()
{
    Fun1::smain();
}
