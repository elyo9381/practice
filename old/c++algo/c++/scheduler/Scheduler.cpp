//Scheduler.cpp
#include "Scheduler.h"
 
Scheduler::Scheduler()
{
    Init();
    Simulation();
}
void Scheduler::Init()
{
    //하드디스크에 프로그램 설치를 표현
    hard_disk.push_back(new EHProcess("A",30,5));
    hard_disk.push_back(new EHProcess("B",24,6));
    hard_disk.push_back(new EHProcess("C",25,4));
 
    miter seek = hard_disk.begin();
    miter end = hard_disk.end();
    EHProcess *pro=0;
    //하드디스크에 설치한 프로그램을 실행 명령을 표현
    for( ; seek != end ; ++seek)
    {
        pro = *seek;
        rq.push(pro); //대기 큐에서 기다림
        pro->IdleToReady();//Idle 상태에서 Ready상태로 전이
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
    while( !rq.empty() ) //대기 큐가 비어있지 않을 때
    {        
        process = rq.front();//가장 먼저 대기한 프로세스를 꺼냄
        rq.pop();
 
        job = process->Running();//꺼낸 프로세스를 실행
        if(job) //남은 작업이 있다면
        {
            rq.push(process); //대기큐에서 기다림
            process->View();
            
        }
        else
        {
            process->EndProgram();//프로세스 종료
        }
    }
}
