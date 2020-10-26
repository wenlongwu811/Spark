#pragma once
using namespace std;
#include "Dnode.h"
class Dlink
{
	Dnode* head;
public:
	Dlink();
	Dlink(int a[], int n);
	bool InsertList(int i, int e);
	bool DeleteList(int i, int& e);
	void DIsplay();
	void Sort();
	void Reverse();
};

Dlink::Dlink() {
	head = (Dnode*)malloc(sizeof(Dnode));
	head->pre = NULL;
	head->next = NULL;
}

/// <summary>
/// 头插法
/// </summary>
/// <param name="a"></param>
/// <param name="n"></param>
Dlink::Dlink(int a[], int n) {
	head = (Dnode*)malloc(sizeof(Dnode));
	head->pre = NULL;
	head->next = NULL;
	Dnode* s;
	int i = 0;
	while (i<n)
	{
		s = (Dnode*)malloc(sizeof(Dnode));
		s->data = a[i]; i++;
		s->next = head->next;
		if (head->next!=NULL)
		{
			head->next->pre = s;
		}
		s->pre = head;
		head->next = s;
	}
}
/// <summary>
/// 尾插法
/// </summary>
/// <param name="a"></param>
/// <param name="n"></param>
/*Dlink::Dlink(int a[], int n) {
	head = (Dnode*)malloc(sizeof(Dnode));
	head->pre = NULL;
	head->next = NULL;
	Dnode* s,*r;
	r = head;
	int i = 0;
	while (i<n)
	{
		s = (Dnode*)malloc(sizeof(Dnode));
		s->data = a[i]; i++;
		s->next = r->next;
		s->pre = r;
		r->next = s;
		r = s;
	}
}
*/

bool Dlink::InsertList(int i, int e)
{
	Dnode* p;
	p = head;
	int n = 0;
	while (n<i-1&&p!=NULL)
	{
		n++;
		p = p->next;
	}
	if (p==NULL)
	{
		return false;
	}
	Dnode* s;
	s = (Dnode*)malloc(sizeof(Dnode));
	s->data = e;
	if (p->next!=NULL)
	{
		p->next->pre = s;
	}
	s->next = p->next;
	s->pre = p;
	p->next = s;
	return true;
}

bool Dlink::DeleteList(int i, int& e)
{
	Dnode* p; p = head;
	int n = 0;
	while (n<i&&p!=NULL)
	{
		n++;
		p = p->next;
	}
	if (p==NULL)
	{
		return false;
	}
	e = p->data;
	Dnode* q; q = p->pre;
	q->next = p->next;
	if (p->next!=NULL)
	{
		p->next->pre = q;
	}
	free(p);
	return true;
}

/// <summary>
/// 排序算法
/// </summary>
 void Dlink::Sort()
{
	Dnode* p, * q;
	if (head->next->next!=NULL)
	{
		p = head->next->next;
		q = p->next;
		head->next->next = NULL;
		while (p!=NULL)
		{
			Dnode* r; r = head->next;
			while (r!=NULL)
			{
				if (p->data<=r->data)
				{
					r->pre->next = p;
					p->pre = r->pre;
					r->pre = p;
					q = p->next;
					p->next = r;
					break;
				}
				if (r->next == NULL)
				{
					r->next = p;
					q = p->next;
					p->pre = r;
					p->next = NULL;
					break;
				}
				r = r->next;
			}
			p = q;
		}
	}
}


 void Dlink::DIsplay()
 {
	 Dnode* p; p = head;
	 while (p->next!=NULL)
	 {
		 cout << p->next->data << " ";
		 p = p->next;
	 }
	 cout << endl;
 }

/// <summary>
/// 逆序空间复杂度为o(1)
/// </summary>
inline void Dlink::Reverse()
{
	Dnode* p, * q; p = head->next;
	head->next = NULL;
	while (p!=NULL)
	{
		q = p->next;
		if (head->next!=NULL)
		{
			head->next->pre = p;
		}
		p->next = head->next;
		head->next = p;
		p->pre = head;
		p = q;
	}

}