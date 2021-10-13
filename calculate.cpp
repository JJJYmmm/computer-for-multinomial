#include"calculate.h"
#include<qdebug.h>
#include<QMessageBox>
#include<qstring.h>
void List::CreatList()
{
	this->head = new Node(0,0);		//表头结点
	head->next = NULL;
	this->length = 0;
}
void List::AddNode(float a,int b)
{
    Node* p = new Node(a,b);
	Node* t = this->head;
	while (t->next != NULL && t->next->e > p->e)	//链表指数从大到小排列
	{
		t = t->next;
	}
	if (t->next != NULL && t->next->e == p->e)		//指数相同时合并同类项
	{
		t = t->next;
		t->coeff += p->coeff;
	}
	else                                            //一般情况 前大后小夹中间
	{
		p->next = t->next;
		t->next = p;
		length++;
	}
}

void List::PrintList()
{
	Node* t = this->head;
	if (t->next == NULL)		//空链表时不打印
	{
        QMessageBox::information(NULL, "NULL", "Empty linked list");
		return;
	}
	else
        t = t->next;
    QString str=nullptr;
	while (t!= NULL)			//遍历链表并打印
	{
		if (t->coeff < 0)
		{
            str=str+QString::number(t->coeff)+"x^"+QString::number(t->e);
		}
		else if( t->coeff > 0)
            str=str+"+"+QString::number(t->coeff)+ "x^"+QString::number(t->e);
		t = t->next;
	}
    QMessageBox::information(NULL, "answer", str);
}

