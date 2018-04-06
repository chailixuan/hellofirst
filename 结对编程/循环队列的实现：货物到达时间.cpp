#include"stdio.h"
#include<iostream>
#include"string.h"
#define Maxsize 16
#define OK 1
#define True 1
#define False 0
#define OverFlow -1
#define UnderFlow -2
using namespace std;
typedef struct
{
    char number[7];
    char id[10];
    char name[10];
    char addr[20];
    char time[9];
}ElemType;
typedef struct
{
    ElemType Element[Maxsize];
    int Rear,Front;
}SeqQueue;
void Init_SeqQueue(SeqQueue *Sq_pointer)
{
    Sq_pointer->Front=-1;
    Sq_pointer->Rear=-1;
}
int Full_SeqQueue(SeqQueue *Sq_pointer)
{
    if((Sq_pointer->Rear+1)%Maxsize ==Sq_pointer->Front)
        return True;
    else return False;
}
int Empty_SeqQueue(SeqQueue *Sq_pointer)
{
    if(Sq_pointer->Front ==Sq_pointer->Rear)
        return True;
    else
        return False;
}
int In_SeqQueue(SeqQueue *Sq_pointer,ElemType x)
{
    if(Full_SeqQueue(Sq_pointer)==True)
        return OverFlow;
    else
    {
        Sq_pointer->Rear=(Sq_pointer->Rear+1)%Maxsize;

        strcpy(Sq_pointer->Element[Sq_pointer->Rear].number,x.number);
        strcpy(Sq_pointer->Element[Sq_pointer->Rear].id,x.id);
        strcpy(Sq_pointer->Element[Sq_pointer->Rear].name,x.name);
        strcpy(Sq_pointer->Element[Sq_pointer->Rear].addr,x.addr);
        strcpy(Sq_pointer->Element[Sq_pointer->Rear].time,x.time);
        return OK;
    }
}
int Out_SeqQueue(SeqQueue *Sq_pointer,ElemType *x_pointer)
{
    if(Empty_SeqQueue(Sq_pointer)==True)
        return UnderFlow;
    else
    {
        strcpy(x_pointer->number,(Sq_pointer->Element[(Sq_pointer->Front+1)%Maxsize]).number);
        strcpy(x_pointer->id,(Sq_pointer->Element[(Sq_pointer->Front+1)%Maxsize]).id);
        strcpy(x_pointer->name,(Sq_pointer->Element[(Sq_pointer->Front+1)%Maxsize]).name);
        strcpy(x_pointer->addr,(Sq_pointer->Element[(Sq_pointer->Front+1)%Maxsize]).addr);
        strcpy(x_pointer->time,(Sq_pointer->Element[(Sq_pointer->Front+1)%Maxsize]).time);
        return OK;
    }
}
void SetNull_SeqQueue(SeqQueue *Sq_pointer)
{
    Sq_pointer->Front=Sq_pointer->Rear=-1;
}
int main()
{
    int i;
    ElemType x;
    SeqQueue ListQueue;
    Init_SeqQueue(&ListQueue);
    do
    {
        cout<<endl;
        cout<<"1---按货物的到达时间提交送货任务，插入配送队列Insert"<<endl
        <<"2---从配送对列出对一个配送单，送货给收货人Delete"<<endl
        <<"3---退出"<<endl;
        cin>>i;
        switch(i)
        {
            case 1 :cout<<"Please enter number:";
            cin>>x.number;
            cout<<"Please enter id:";
            cin>>x.id;
            cout<<"Please enter name:";
            cin>>x.name;
            cout<<"Please enter addr";
            cin>>x.addr;
            cout<<"Please enter time:";
            cin>>x.time;
            if(In_SeqQueue(&ListQueue,x)!=OK)
                cout<<"队列满插入失败，等待！"<<endl;
            break;
            case 2:
                cout<<"从配送队列中出对一个送货任务，准备输出配送单print"<<endl;
                if(Empty_SeqQueue(&ListQueue)==OK)
                {
                    cout<<"配送队列空，无送货任务，等待！wait！"<<endl;
                    break;
                }
                Out_SeqQueue(&ListQueue,&x);
                cout<<endl<<"当前送货任务：number="<<x.number<<"id="<<x.id<<"addr:"<<
                x.addr<<"time:"<<x.time;
                break;
                case 3:break;
                default:cout<<"错误选择！Error 请重选！";break;

        }

    }while(i!=3);
    SetNull_SeqQueue(&ListQueue);
}
