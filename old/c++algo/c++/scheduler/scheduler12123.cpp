#include <iostream>
#include <queue>
#include <string>

class EHProcess
{
	string pname; // 프로그램 이름 
	const int tjob; // 전체 작업량 
	const int cjob; // cpu 점유시 수행 가능 작업량 
	int ntjob; // 남은 전체 작업량 
	int ncjob; // 남은 cpu 수행가능 작업량 
public:
	EHProcess(string pname, int tjob,int cjob); // process 생성자 
	void IdleToReady(); //idle에서 ready로이동   
	int Running(); // 프로세스 실행 함수 
	void EndProgram();  //프로세스 끝함수 
};

// 프로세스를 생성자를 이용해서 초기화 해준다. 
EHProcess::EHProcess(string pname, int tjob, int cjob):tjob(tjob),cjob(cjob)
{
	// name을 받아오고 생성자를 통해서 tjob와 cjob의 입력값을 받는다. 
	this-> pname = pname;
}

// 이전함수인데 초기에만 tjob를 입력받는다. 
void EHProcess::IdleToReady()
{
	
	cout<<pname<<" start"<<endl;
	ntjob = tjob; 
}

// run할때는 남아 있는 전체 할당량만 가지고 작업을 수행한다. 
// cjob는 수행해야할 데이터 이므로 매번 입력받는다. 
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
	cout<<pname<<"종료"<<endl; 
}

// process구현을 위해서 클래스를 이용한 벡터를 사용하였음
// 스케줄러 구현을 위해서 queue를 사용함
// iter는 ending에서 프로세스 메모리 해제를 위해서 사용  
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
	void Init(); // 스케줄러 생성자  
	void Simulation(); // 스케줄러 동작 함수 
	void Ending(); //프로세스 백터 메모리 해 
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
	// 백터를 통해서 프로세스를 입력받는다. 
	hard_disk.push_back(new EHProcess("A",30,5));
	hard_dist.push_back(new EHprocess("B",24,6));
	hard_disk.push_back(new EHProcess("C",25,4));
	
	// iter를 이용하여 vertor에 프로세스를 순차적으로queue에 입력한다.  
	miter seek =  hard_disk.begin();
	miter end = hard_disk.end();
	EHProcess *pre=0;
	for(; seek !=end; ++seek)
	{
		pro = *seek;
		rq.push(pro);
		//초기화 단계에서 ready상태로 변환 
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
		//front 프로세스를 가져오고 
		process = rq.front();
		rq.pop();//가져온 프로세스 queue에서 제거  
		
		//프로세스의 run을 수행
		//이때 ntjob를 수행하고 ntjob의 값이 변경 
		job = process->Running();
		if(job)
		{
			//job 즉 ntjob가 남아있다면 입력받은 프로세스를 그대로 re-queue
			//vector의 인덱스로소 프로세스의 값중ntjob만 변경되어있을것이다. 
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
