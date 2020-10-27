#include <iostream>
#include "SqTable.h"

int main()
{
    int a[9] = { 1,2,3,2,3,3,1,1,1 };
    int b[6] = { 3,5,1,6,3,4 };
    SqTable table1(3,3,a);
    SqTable table2(3, 2, b);
    cout << "表1：----------------" << endl;
    table1.Display();
    cout<< "表2：----------------" << endl;
    table2.Display();
    int col = table1.GetCol() + table2.GetCol();
    int s[50];
    int row;
    table1.LinkTable(table2, 3, 1, s,row);
    SqTable table3(row,col,s);
    cout << "表3：----------------" << endl;
    table3.Display();
    return 0;
}

