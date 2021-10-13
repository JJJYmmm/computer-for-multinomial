#include"calculate.h"
#include<qdebug.h>
#include<QMessageBox>
#include<qstring.h>
void List::CreatList()
{
	this->head = new Node(0,0);		//��ͷ���
	head->next = NULL;
	this->length = 0;
}
void List::AddNode(float a,int b)
{
    Node* p = new Node(a,b);
	Node* t = this->head;
	while (t->next != NULL && t->next->e > p->e)	//����ָ���Ӵ�С����
	{
		t = t->next;
	}
	if (t->next != NULL && t->next->e == p->e)		//ָ����ͬʱ�ϲ�ͬ����
	{
		t = t->next;
		t->coeff += p->coeff;
	}
	else                                            //һ����� ǰ���С���м�
	{
		p->next = t->next;
		t->next = p;
		length++;
	}
}

void List::PrintList()
{
	Node* t = this->head;
	if (t->next == NULL)		//������ʱ����ӡ
	{
        QMessageBox::information(NULL, "NULL", "Empty linked list");
		return;
	}
	else
        t = t->next;
    QString str=nullptr;
	while (t!= NULL)			//����������ӡ
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

