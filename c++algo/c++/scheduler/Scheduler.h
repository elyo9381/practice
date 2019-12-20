//Scheduler.h
#pragma once
#include <vector>
#include <queue>
using namespace std;
#include "EHProcess.h"
 
typedef vector<EHProcess *> Memory;
typedef queue<EHProcess *> ReadyQueue;
typedef Memory::iterator miter;
 
class Scheduler  
{
    Memory hard_disk; // 하드디스크
    ReadyQueue  rq; //대기 큐
public:
    Scheduler();
    // 소멸자에 virtual을 사용하는 이유 
    // 소멸자를 virtual로 선언하지 않으면 소멸자는 호출되지 않으므로 
	// 사용했을때마다 소멸시키려면 virtual사용해야한다. 
    virtual ~Scheduler();
private:
    void Init(); //시뮬레이션 초기화- 프로그램 설치 및 실행 명령
    void Simulation();//시뮬레이션 시작
    void Ending();//시뮬레이션 종료
};
