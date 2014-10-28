#include <iostream>

using namespace std;

const int digits = 11;

void qsort (int values[], int &s, int &e)
{
    int dividertemp,swaptemp;
    int pivot = s;
    s++;
    int l = s;
    int r = e;
    if (s==e)
    {
        if (values[s] < values[pivot])
        {
            swaptemp=values[pivot];
            values[pivot]=values[s];
            values[s]=swaptemp;
            ///swap(values[s], values[pivot]);
        }
    }
    else
    {
        while (values[pivot] >= values[l] && l < e)
        {
            l++;
        }
        while ((values[pivot] < values[r]) && (r > l))
        {
            r--;
        }

        if (values[l] >= values[pivot] && l==e)
        {
            dividertemp = e-1;
            qsort(values, pivot, dividertemp);
        }
        else if (r==s)
        {
            qsort(values, s, e);
        }
        else if (l==e)
        {
            swaptemp=values[e];
            values[e]=values[pivot];
            values[pivot]=swaptemp;
            ///swap(values[pivot], values[e]);
            dividertemp = e-1;
            qsort(values, pivot, dividertemp);
        }
        else if (l < r)
        {
            swaptemp=values[r];
            values[r]=values[l];
            values[l]=swaptemp;
            ///swap(values[l], values[r]);
            qsort(values, pivot, e);
        }
        else if (l == r)
        {
            swaptemp=values[l-1];
            values[l-1]=values[pivot];
            values[pivot]=swaptemp;
            ///swap(values[pivot], values[l-1]);
            dividertemp = l-2;
            qsort(values, pivot, dividertemp);
            qsort(values, l, e);
        }
    }

}
/*
void swap (int &a, int &b)
{
    int dividertemp = b;
    b = a;
    a = dividertemp;
}
*/
int main ()
{
    int values[digits] = {4, 1, 2, 8, 3, 0, 9, 5, 5, 4, 0},s = 0, e = digits-1;

    cout << "input\n";
    for (int i = 0; i < digits; i++)
    {
        cout << values[i] << " ";
    }
    qsort(values, s, e);
    cout << endl<<endl;
    cout << "qsort\n";

    for (int i = 0; i < digits; i++)
    {
        cout << values[i] << " ";
    }
    return 0;
}
