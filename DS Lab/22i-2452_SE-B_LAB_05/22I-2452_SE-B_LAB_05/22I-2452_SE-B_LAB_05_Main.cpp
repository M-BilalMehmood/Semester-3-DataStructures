#include<iostream>
#include<string>
#include"22I-2452_SE-B_LAB_05_H3.h"
using namespace std;



int main()
{
    int* ptr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        ptr[i] = 1 + rand() % 100;
        cout << ptr[i] << endl;
    }
    cout << "-------bubble sort------------" << endl;
    bool flag;
    int i = 1;
    int x = 0, y = 0;
    do
    {
        flag = false;
        for (int j = 0; j < 10 - i; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                int temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
                flag = true;
                x++;
            }
            y++;
        }
        i++;
    } while (flag);
    for (int i = 0; i < 10; i++)
    {
        cout << ptr[i] << endl;
    }
    cout << "--------result-----------" << endl;
    cout << "swaps: " << x << endl;
    cout << "comparisons: " << y << endl;
    x = 0;
    y = 0;
    for (int i = 0; i < 10; i++)
    {
        ptr[i] = 1 + rand() % 100;
        cout << ptr[i] << endl;
    }
    cout << "---------Selection sort-----------------" << endl;
    for (int i = 9; i > 0; i--)
    {
        int max = 0;
        for(int j = 1; j <= i; j++)
		{
			if (ptr[j] > ptr[max])
			{
				max = j;
			}
			y++;
		}
        if (ptr[max] > ptr[i])
        {
            int temp=ptr[max];
            ptr[max]=ptr[i];
            ptr[i]=temp;
			x++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << ptr[i] << endl;
    }
    cout << "--------result-----------" << endl;
    cout << "swaps: " << x << endl;
    cout << "comparisons: " << y << endl;
    x = 0;
    y = 0;
    for (int i = 0; i < 10; i++)
    {
        ptr[i] = 1 + rand() % 100;
        cout << ptr[i] << endl;
    }
    return 0;
}