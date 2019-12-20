//Scheduler.cpp
#include "Scheduler.h"
 
Scheduler::Scheduler()
{
    Init();
    Simulation();
}
void Scheduler::Init()
{
    //�ϵ��ũ�� ���α׷� ��ġ�� ǥ��
    hard_disk.push_back(new EHProcess("A",30,5));
    hard_disk.push_back(new EHProcess("B",24,6));
    hard_disk.push_back(new EHProcess("C",25,4));
 
    miter seek = hard_disk.begin();
    miter end = hard_disk.end();
    EHProcess *pro=0;
    //�ϵ��ũ�� ��ġ�� ���α׷��� ���� ����� ǥ��
    for( ; seek != end ; ++seek)
    {
        pro = *seek;
        rq.push(pro); //��� ť���� ��ٸ�
        pro->IdleToReady();//Idle ���¿��� Ready���·� ����
    }
}
 
Scheduler::~Scheduler()
{
    Ending();
}
void Scheduler::Ending()
{
    miter seek = hard_disk.begin();
    for(   ; seek != hard_disk.end(); ++seek)
    {
        delete (*seek); 
    }
}
 
void Scheduler::Simulation()
{
    EHProcess *process = 0;
    int job=0;
    while( !rq.empty() ) //��� ť�� ������� ���� ��
    {        
        process = rq.front();//���� ���� ����� ���μ����� ����
        rq.pop();
 
        job = process->Running();//���� ���μ����� ����
        if(job) //���� �۾��� �ִٸ�
        {
            rq.push(process); //���ť���� ��ٸ�
            process->View();
            
        }
        else
        {
            process->EndProgram();//���μ��� ����
        }
    }
}
