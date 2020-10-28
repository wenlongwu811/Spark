// List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    int a[9] = { 3,25,7,5,10,4,3,2,1 };
    List list(a, 9);
    int b[6] = { 6,3,8,2,5,7 };
    List list1(b, 6);
    List list3;
    //list3.Union(list, list1);
    //list3.Intersection(list, list1);
    list3.Complementary(list, list3);
    //int flag =list.EmptyList();
    //cout << flag << endl;
    //int e;
    //flag=list.GetElem(2,e);
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
    //int max;
    //list.DelMax(max);
    //list.Sort();
    list.DispList();
    list1.DispList();
    list3.DispList();
    return 0;
}

