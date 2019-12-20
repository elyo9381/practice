#include <iostream>
#include <queue>
#include <string>

class EHProcess
{
	string pname;
	const int tjob;
	const int cjob;
	int ntjob;
	int ncjob;
public:
	EHProcess(string pname, int tjob,int cjob);
	void IdleToReady();
	int Running();
	void EndProgram(); 
};

EHProcess::EHProcess(string pname, int tjob, int cjob):tjob(tjob),cjob(cjob)
{
	this-> pname = pname;
}

void EHProcess::IdleToReady()
{
	cout<<pname<<" start"<<endl;
	ntjob = tjob; 
}

int EHProcess::Running()
{
	ncjob = cjob;
	for(;ntjob &&ncjob; ntjob--, ncjob--)
	{
		cout<<pname<<" ";
	}
	cout<<endl;
	return ntjob;
}

void EHProcess::EndProgram()
{
	cout<<pname<<"Á¾·á"<<endl; 
}

typedef vector<EHProcess *> Memory;
typedef queue<EHprocess *> ReadyQueue;
typedef Memory::iterator miter;

class Scheduler
{
	Memory hard_disk;
	ReadyQueue rq;
public:
	Scheduler();
	virual ~ Scheduler();
private:
	void Init();
	void Simulation();
	void Ending();
};

Scheduler::Scheduler()
{
	Init();
	Simulation();
}

Scheduler::~Scheduler()
{
	Ending();
}

void Scheduler::Init()
{
	hard_disk.push_back(new EHProcess("A",30,5));
	hard_dist.push_back(new EHprocess("B",24,6));
	hard_disk.push_back(new EHProcess("C",25,4));
	
	miter seek =  hard_disk.begin();
	miter end = hard_disk.end();
	EHProcess *pre=0;
	for(; seek !=end; ++seek)
	{
		pro = *seek;
		rq.push(pro);
		pro->IdleToReady();
	}
}

void Scheduler::Ending(){
	miter seek = hard_disk.begin();
	for(; seek!= hard_disk.end();++ seek)
	{
		delete(*seek);
	}
}

void Scheduler::Simulation()
{
	EHProcess *process = 0;
	int job;
	
	while(!rq.empty())
	{
		process = rq.front();
		rq.pop();
		
		job = process->Running();
		if(job)
		{
			rq.push(process);
		}
		else
		{
			process->EndProgram(); 
		}
	}
}

int main(){
	Scheduler *pro = new Scheduler;
	delete pro;
	return 0;
}
