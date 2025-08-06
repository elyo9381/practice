#pragma once
#include <iostream>
#include <string>
using namespace std;
 
class EHProcess
{
    string pname; //프로그램 이름
    const int tjob; //전체 작업량
    const int cjob; //cpu 점유 시 수행가능 최대 작업량
    int ntjob; //현재 남은 작업량
    int ncjob; //현재 cpu 점유 시 수행가능 최대 작업량
public:
    EHProcess(string pname,int tjob,int cjob);
    void IdleToReady();//Idle 상태에서 Ready 상태로 전이
    int Running();//CPU를 점유하여 실행, 남은 작업량 반환
    void EndProgram(); //프로세스 종료
    void View();
};
