///////// Сортировка вставкой \\\\\\\\\\\\\\
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>

#define NU 125000/2

using namespace std;

int stop = 0; int step = 5000;

int NUM = NU;
int rr= 0;
double long count =0;

long double ce=0;
long double ca=0;

vector <int> a;
vector <int> b;

int main()
{
    ofstream fout("cppstudio.txt");

    long double count = 0;

    a.reserve(NU+5);
     b.reserve(NU+5);

    ///cout << " start massiv base" << endl;

    for (int i = 0; i < NUM; i++){
        a.push_back  (i);
        b.push_back  (i);
    }

    random_shuffle(b.begin(), b.end());

    do {
    ///
        for (int i = 0; i < NUM; i++) a[i]= b[i];

      for (int i = 0; i < NUM; i++)
    {
        int min = i;
        ///int minval = a[i]; /// здесь сравнение элементов
        ///ce++;
        count ++;
        for (int j = i + 1; j < NUM; j++)
        {
            ca++;
            if (a[j] < a[i])/// здесь сравнение элементов
            {
              min = j;
              a[i] = a[j];/// здесь сравнение элементов
              ce++;
              count +=2;
            }
            else { count ++;}
        }

        swap (a[i], a[min]); ce++;//////////////////////
        count+=3;
    }

    ///fout << count << "    " << NUM<< endl;
    fout << ce<< "    "<< ca + ce << "    " << NUM<< endl; ca=ce=0;
    count =0;
    stop++;
    NUM = NUM/2;

    } while (NUM >500);

    fout.close();

    return 0;
}






