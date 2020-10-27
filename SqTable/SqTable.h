#pragma once
#include "HNode.h"
class SqTable
{
	HNode* head;
public:
	SqTable();
	SqTable(int row, int col, int a[]);
	~SqTable();
	int GetRow();
	int GetCol();
	bool GetElem(int i, int *&a);
	void Display();
	void LinkTable(SqTable sqtable,int m ,int n,int*s,int &row);
	SqTable(SqTable& st);
};

SqTable::SqTable()
{
	head = (HNode*)malloc(sizeof(HNode));
	head->next = NULL;
	head->Col = 0;
	head->Row = 0;
}

/*inline SqTable::SqTable(int row, int col, int a[])
{
	head = (HNode*)malloc(sizeof(HNode));
	head->next=NULL;
	head->Row = row;
	head->Col = col;
	Node* s;
	for (int i = 0; i < row; i++)
	{
		s = (Node*)malloc(sizeof(Node));
		for (int j = 0; j < col; j++)
		{
			s->data[j] = a[i * col + j];
			s->next = head->next;
			head->next = s;
		}
	}
}*/

SqTable::SqTable(int row, int col, int a[])
{
	head = (HNode*)malloc(sizeof(HNode));
	head->next = NULL;
	head->Row = row;
	head->Col = col;
	Node* s, * r; r = NULL;
	for (int i = 0; i < row; i++)
	{
		s = (Node*)malloc(sizeof(Node));
		for (int j = 0; j < col; j++)
		{
			s->data[j] = a[i * col + j];
		}
		head->next == NULL? head->next = s:r->next = s;
		r = s;
	}
	r->next = NULL;
}

SqTable::~SqTable()
{
	Node* p, * q;
	p = head->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(head);
}


int SqTable::GetRow()
{
	return head->Row;
}

inline int SqTable::GetCol()
{
	return head->Col;
}

void SqTable::Display()
{
	Node* p; p = head->next;
	cout << "表的行数,列数：" << head->Row<<" "<<head->Col<<endl;
	for (int i = 1; i <= head->Row; i++)
	{
		cout << "第" << i + 1 <<"行：" ;
		for (int j = 0; j < head->Col; j++)
		{
			cout << p->data[j] << " ";
		}
		cout << endl;
		p = p->next;
	}
}

bool SqTable::GetElem(int i, int*& a)
{
	Node* p; 
	if (head->next==NULL) return 0;
	p = head->next;
	int n = 1;
	while (n<i&&p!=NULL)
	{
		p = p->next;
		n++;
	}
	if (p==NULL) return 0;
	a = p->data;
	return 1;
}

void SqTable::LinkTable(SqTable sqtable,int m,int n,int s[],int &row)
{
	row = 0;
	int col = head->Col + sqtable.GetCol();
	int* b;
	Node* p;
	p = head->next;
	while (p!=NULL)
	{
		for (int i = 1; i <= sqtable.GetRow(); i++)
		{
			sqtable.GetElem(i, b);
			if (p->data[m-1]==b[n-1])
			{
				row++;
				for (int j = 0; j < head->Col; j++)
				{
					s[(row-1)*col+j] = p->data[j];
				}
				for (int j = head->Col; j < col; j++)
				{
					s[(row-1)*col+j] = b[j - head->Col];
				}
			}
		}
		p = p->next;
	}
}

SqTable::SqTable(SqTable& st)
{
	head = (HNode*)malloc(sizeof(Node));
	head->next = NULL;
	head->Row = st.GetRow();
	head->Col = st.GetCol();
	Node* s, * r; r = NULL;
	for (int i = 1; i < head->Row; i++)
	{
		int *a;
		st.GetElem(i, a);
		s = (Node*)malloc(sizeof(Node));
		for (int j = 0; j < head->Col; j++)
		{
			s->data[j] = a[j];
		}
		head->next == NULL ? head->next = s : r->next = s;
		r = s;
	}
	r->next = NULL;
}