#pragma once
#include<iostream>
using namespace std;
//�ڵ���
class Node
{
public:
	//���Ĺ��캯��
    Node(float a,int b)
	{
		this->coeff = a;
		this->e = b;
	}
    float coeff=0;	//ϵ��
    int e=0;		//ָ��
	Node* next=NULL;	//ָ����һ���
};


//������
class List
{
public:
    //��������
    void CreatList();
    //��ӽ��
    void AddNode(float a,int b);
    //��ӡ����
    void PrintList();
    //ά����ͷ�ڵ�
    Node* head;
    //������
    int length=0;
};

