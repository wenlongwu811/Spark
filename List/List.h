#pragma once
#include "Node.h"
using namespace std;
class List
{
	Node* head;
public:
	List() {
		head = (Node*)malloc(sizeof(Node));
		head->next = NULL;
	}

	/*List(int a[], int n) {//头插法
		head = (Node*)malloc(sizeof(Node));
		head->next = NULL;
		Node* s;
		for (int i = 0; i < n; i++)
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = a[i];
			s->next = head->next;
			head->next = s;
		}
	}*/

	List(int a[], int n) {//尾插法，保证次序
		head = (Node*)malloc(sizeof(Node));
		head->next = NULL;
		Node* s, * r;
		r= head;
		for (int i = 0; i < n; i++)
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = a[i];
			r->next = s;
			r = s;
		}
		r->next = NULL;
	}

	List(List &L) {
		head = (Node*)malloc(sizeof(Node));
		head->next = NULL;
		Node* s, * r; r = head;
		int n = L.LengthList();
		int e;
		for (int i = 0; i < n; i++)
		{
			L.GetElem(i + 1, e);
			s = (Node*)malloc(sizeof(Node));
			s->data = e;
			s->next = r->next;
			r->next = s;
			r = s;
		}
	}


	~List() {
		Node* p,*q;
		p = head;
		while (p != NULL)
		{
			q = p;
			p = p->next;
			free(q);
		}
	}

	bool EmptyList() {
		int flag = 0;
		head->next == NULL ? flag = 1 : flag = 0;
		return flag;
	}

	int LengthList() {
		int len = 0;
		Node* p;
		p = head->next;
		while (p!=NULL)
		{
			len++;
			p = p->next;
		}
		return len;
	}

	void DispList() {
		Node* p;
		p = head->next;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	bool GetElem(int i,int& e) {
		Node* p;
		p = head->next;
		int n = 1;
		while (p!=NULL&&n<i)
		{
			n++;
			p = p->next;
		}
		if (p!=NULL)
		{
			e = p->data;
			return 1;
		}
		else return 0;
	}

	int LocateList(int e) {
		Node* p;
		p = head->next;
		int k = 1;
		while (p->next!=NULL&&p->data!=e) {
			k++;
			p = p->next;
		}
		if (p != NULL)
		{
			return k;
		}
		else return 0;
	}

	bool InsertList(int i, int e) {
		if (i<1)
		{
			return 0;
		}
		Node* p;
		p = head;
		int n = 0;
		while (n<i-1&&p!=NULL)
		{
			n++;
			p = p->next;
		}
		if (p != NULL) {
			Node* s;
			s = (Node*)malloc(sizeof(Node));
			s->data = e;
			s->next = p->next;
			p->next = s;
			return 1;
		}
		else return 0;
	}

	bool DeleteList(int i, int& e) {
		if (i<0)return false;
		int n = 0;
		Node* p;
		p = head;
		while (n<i-1&&p!=NULL)
		{
			n++;
			p = p->next;
		}
		if (p->next != NULL) { 
			Node* q; 
			q = p->next;
			p->next = q->next;
			e = q->data;
			free(q);
			return 1; 
		}
		else return 0;
	}

	bool Split(List &list){
		int e;
		int k = 2;
		int len = LengthList();
		if (len / 2 == 1) return 0;
		while (k-2!=len/2)
		{
			DeleteList(k, e);//没delete一次，原链表长度减一，因此k是+1，不是+2，判断条件不是Len；
			list.InsertList(1,e);//头插
			k++;
		}
		return 1;
	}

	bool DelMax(int &max) {
		Node* p,*q,*s;
		p = head->next;
		if (head->next==NULL)
		{
			return 0;
		}
		max = p->data;
		q = head;
		s = q;
		while (p!=NULL)
		{
			if (p->data>=max)
			{
				max = p->data;
				s = q;//s记录max前一个位置
			}
			q = p;
			p = p->next;
		}
		Node* r;
		r = s->next;
		s->next = r->next;
		free(r);
		return 1;
	}

	void Sort() {
		Node* p,*r;
		p = head->next->next;
		r = p;
		head->next->next = NULL;
		while (p!=NULL)
		{
			Node* pre,*q;
			pre = head;
			q = head->next;
			while (true) {
				if (q == NULL||q->data >= p->data) {
					r = p->next;
					p->next = pre->next;
					pre->next = p;
					p = r;
					break;
				}
				else{
					pre = q;
					q = q->next;
				}
			}
		}
	}

	void Union(List A, List B) {//并集
		int e, n; n = A.LengthList();
		Node* s;
		for (int i = 0; i < n; i++)
		{
			A.GetElem(i + 1, e);
			s = (Node*)malloc(sizeof(Node));
			s->data = e;
			Node* p; p = head;
			while (p!=NULL)
			{
				if (p->next == NULL||s->data<p->next->data)
				{
					s->next = p->next;
					p->next = s;
					break;
				}
				if (s->data == p->next->data)
				{
					free(s);
					break;
				}
				p = p->next;
			}
		}
		n = B.LengthList();
		for (int i = 0; i < n; i++)
		{
			B.GetElem(i + 1, e);
			s = (Node*)malloc(sizeof(Node));
			s->data = e;
			Node* p; p = head;
			while (p != NULL)
			{
				if (p->next == NULL || s->data < p->next->data)
				{
					s->next = p->next;
					p->next = s;
					break;
				}
				if (s->data==p->next->data)
				{
					free(s);
					break;
				}
				p = p->next;
			}
		}
	}

	void Intersection(List A, List B) {//交集
		int n = A.LengthList();
		int m = B.LengthList();
		int e,h;
		for (int i = 0; i < n; i++)
		{
			A.GetElem(i + 1, e);
			for (int j = 0; j < m; j++)
			{
				B.GetElem(j + 1, h);
				if (e==h)
				{
					Node* s,*p;
					s = (Node*)malloc(sizeof(Node));
					s->data = e;
					p = head;
					while (p!=NULL)
					{
						if (p->next==NULL||s->data<p->next->data)
						{
							s->next = p->next;
							p->next = s;
							break;
						}
						if (s->data==p->next->data)
						{
							free(s);
							break;
						}
						p = p->next;
					}
				}

			}
		}
	}

	void Complementary(List A, List B) {//差集
		int e, h;
		int m = A.LengthList();
		int n = B.LengthList();
		Node* s, * p; p = head;
		for (int i = 0; i < m; i++)
		{	
			A.GetElem(i + 1, e);
			int flag = 0;
			for (int j = 0; j < n; j++)
			{
				B.GetElem(j + 1, h);
				if (e==h)
				{
					flag = 1;
					break;
				}
			}
			if (flag==0)
			{
				s = (Node*)malloc(sizeof(Node));
				s->data = e; p = head;
				while (p!=NULL)
				{
					if (p->next == NULL || p->next->data > s->data)
					{
						s->next = p->next;
						p->next = s;
						break;
					}
					p = p->next;
				}
			}
		}

	}

	/// <summary>
/// 二路归并
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
	void UnionList(List A, List B) {
		Node* p, * r; r = head;
		int m = A.LengthList();
		int n = B.LengthList();
		int e, h;
		int i = 1;
		for (i; i <= m&&i<=n; i++)
		{
			A.GetElem(i, e);
			B.GetElem(i, h);
			p = (Node*)malloc(sizeof(Node));
			p->data = e + h;
			p->next = r->next;
			r->next = p;
			r = p;
		}
		if (i-1==n)
		{
			for (i; i <= m; i++)
			{
				A.GetElem(i, e);
				p = (Node*)malloc(sizeof(Node));
				p->data = e;
				p->next = r->next;
				r->next = p;
				r = p;
			}
		}
		else
		{
			for (i;i <= n; i++)
			{
				B.GetElem(i, h);
				p = (Node*)malloc(sizeof(Node));
				p->data = h;
				p->next = r->next;
				r->next = p;
				r = p;
			}
		}
	}

	void MultiList(List A, List B) {
		int m = A.LengthList();
		int n = B.LengthList();
		int e,h;
		Node* s, * p; p = head;
		for (int count = 0; count <=m + n - 2; count++)
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = 0;
			for (int i = 0; i <= count; i++)
			{
				e = h = 0;
				A.GetElem(i + 1, e);
				B.GetElem(count - i + 1, h);
				s->data += e * h;
			}
			s->next = p->next;
			p->next = s;
			p = s;
		}
	}

	bool OutFile() {
		errno_t err;
		FILE* stream;
		Node* p; p = head;
		err = fopen_s(&stream,"List.txt", "w+");
		if (err!=0)
		{
			cout << "Fail!" << endl;
			return 0;
		}
		while (p->next!=NULL)
		{
			fprintf(stream, "%d", p->next->data);
			p = p->next;
		}
		fclose(stream);
	}
};

