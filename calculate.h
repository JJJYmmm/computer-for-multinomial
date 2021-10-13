#pragma once
#include<iostream>
using namespace std;
//节点类
class Node
{
public:
	//结点的构造函数
    Node(float a,int b)
	{
		this->coeff = a;
		this->e = b;
	}
    float coeff=0;	//系数
    int e=0;		//指数
	Node* next=NULL;	//指向下一结点
};


//链表类
class List
{
public:
    //创建链表
    void CreatList();
    //添加结点
    void AddNode(float a,int b);
    //打印链表
    void PrintList();
    //维护的头节点
    Node* head;
    //链表长度
    int length=0;
};

