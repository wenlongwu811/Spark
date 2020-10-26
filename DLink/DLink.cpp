// DLink.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Dlink.h"

int main()
{
    int a[6] = { 6,5,4,3,2,1 };
    Dlink dlink(a, 6);
    dlink.Reverse();
    dlink.DIsplay();
    dlink.Sort();
    dlink.DIsplay();
    dlink.InsertList(1, 0);
    dlink.InsertList(8, 7);
    int e;
    dlink.DeleteList(7, e);
    cout << "e="<<e << endl;
    dlink.DIsplay();

    return 0;
}

