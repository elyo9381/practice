//EHProcess.h
#include "EHProcess.h"
 
EHProcess::EHProcess(string pname,int tjob,int cjob):tjob(tjob),cjob(cjob)
{
    this->pname = pname;
}
void EHProcess::IdleToReady()//Idle 상태에서 Ready 상태로 전이
{
    cout<<pname<<" 시작"<<endl;
    ntjob = tjob; //프로그램 이미지 메모리에 로딩을 표현
}
int EHProcess::Running()//CPU를 점유하여 실행, 남은 작업량 반환
{
	//	cout<< cjob<<" cjob\n";
	// cjob와 tjob는 스케줄링을 하기위해서 받는 값의 수이고 
	// 실질적으로 값에 변동이 있는 수는 ntjob,ncjob이다.  
    ncjob = cjob; //ncjob에 CPU 사용할 수 있는 시간 대입
 
    //남은 작업량(ntjob)과 CPU 사용할 수 있는 시간(ncjob)이 있다면
    for(  ; ntjob && ncjob ; ntjob--, ncjob--)
    {
        cout<<pname<<" ";//단위 시간 작업 수행을 표현
    }
 
    cout<<endl; //CPU를 반납함을 표현
    return ntjob; //남은 작업량 반환
}
void EHProcess::View(){
	 cout<< pname +"의 "<< " nt-"<<ntjob  << " nc-" <<ncjob << endl;
}
void EHProcess::EndProgram() //프로세스 종료
{
    cout<<pname<<"종료"<<endl; //프로세스 종료를 표현
}
