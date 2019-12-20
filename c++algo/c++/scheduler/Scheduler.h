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
    Memory hard_disk; // �ϵ��ũ
    ReadyQueue  rq; //��� ť
public:
    Scheduler();
    // �Ҹ��ڿ� virtual�� ����ϴ� ���� 
    // �Ҹ��ڸ� virtual�� �������� ������ �Ҹ��ڴ� ȣ����� �����Ƿ� 
	// ������������� �Ҹ��Ű���� virtual����ؾ��Ѵ�. 
    virtual ~Scheduler();
private:
    void Init(); //�ùķ��̼� �ʱ�ȭ- ���α׷� ��ġ �� ���� ���
    void Simulation();//�ùķ��̼� ����
    void Ending();//�ùķ��̼� ����
};
