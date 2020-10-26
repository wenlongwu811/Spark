// List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    int a[9] = { 9,8,7,5,6,4,3,2,1 };
    List list(a, 9);
    int flag =list.EmptyList();
    //cout << flag << endl;
    int e;
    flag=list.GetElem(2,e);
    //if (flag != 0)cout << e << endl;
    //list.InsertList(1, 7);
    //list.InsertList(8,0);
    //list.InsertList(10, 10);
    //list.DeleteList(7, e);
    //list.DeleteList(1, e);
    //List list2;
    //list.Split(list2);
    //list2.DispList();
    //list.DispList();
    int max;
    list.DelMax(max);
    list.Sort();
    list.DispList();

    return 0;
}

