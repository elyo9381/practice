#include <iostream>
#include <queue>
#include <string>

class EHProcess
{
	string pname; // ���α׷� �̸� 
	const int tjob; // ��ü �۾��� 
	const int cjob; // cpu ������ ���� ���� �۾��� 
	int ntjob; // ���� ��ü �۾��� 
	int ncjob; // ���� cpu ���డ�� �۾��� 
public:
	EHProcess(string pname, int tjob,int cjob); // process ������ 
	void IdleToReady(); //idle���� ready���̵�   
	int Running(); // ���μ��� ���� �Լ� 
	void EndProgram();  //���μ��� ���Լ� 
};

// ���μ����� �����ڸ� �̿��ؼ� �ʱ�ȭ ���ش�. 
EHProcess::EHProcess(string pname, int tjob, int cjob):tjob(tjob),cjob(cjob)
{
	// name�� �޾ƿ��� �����ڸ� ���ؼ� tjob�� cjob�� �Է°��� �޴´�. 
	this-> pname = pname;
}

// �����Լ��ε� �ʱ⿡�� tjob�� �Է¹޴´�. 
void EHProcess::IdleToReady()
{
	
	cout<<pname<<" start"<<endl;
	ntjob = tjob; 
}

// run�Ҷ��� ���� �ִ� ��ü �Ҵ緮�� ������ �۾��� �����Ѵ�. 
// cjob�� �����ؾ��� ������ �̹Ƿ� �Ź� �Է¹޴´�. 
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
	cout<<pname<<"����"<<endl; 
}

// process������ ���ؼ� Ŭ������ �̿��� ���͸� ����Ͽ���
// �����ٷ� ������ ���ؼ� queue�� �����
// iter�� ending���� ���μ��� �޸� ������ ���ؼ� ���  
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
	void Init(); // �����ٷ� ������  
	void Simulation(); // �����ٷ� ���� �Լ� 
	void Ending(); //���μ��� ���� �޸� �� 
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
	// ���͸� ���ؼ� ���μ����� �Է¹޴´�. 
	hard_disk.push_back(new EHProcess("A",30,5));
	hard_dist.push_back(new EHprocess("B",24,6));
	hard_disk.push_back(new EHProcess("C",25,4));
	
	// iter�� �̿��Ͽ� vertor�� ���μ����� ����������queue�� �Է��Ѵ�.  
	miter seek =  hard_disk.begin();
	miter end = hard_disk.end();
	EHProcess *pre=0;
	for(; seek !=end; ++seek)
	{
		pro = *seek;
		rq.push(pro);
		//�ʱ�ȭ �ܰ迡�� ready���·� ��ȯ 
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
		//front ���μ����� �������� 
		process = rq.front();
		rq.pop();//������ ���μ��� queue���� ����  
		
		//���μ����� run�� ����
		//�̶� ntjob�� �����ϰ� ntjob�� ���� ���� 
		job = process->Running();
		if(job)
		{
			//job �� ntjob�� �����ִٸ� �Է¹��� ���μ����� �״�� re-queue
			//vector�� �ε����μ� ���μ����� ����ntjob�� ����Ǿ��������̴�. 
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
