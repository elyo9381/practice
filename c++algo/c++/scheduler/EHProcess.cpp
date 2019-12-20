//EHProcess.h
#include "EHProcess.h"
 
EHProcess::EHProcess(string pname,int tjob,int cjob):tjob(tjob),cjob(cjob)
{
    this->pname = pname;
}
void EHProcess::IdleToReady()//Idle ���¿��� Ready ���·� ����
{
    cout<<pname<<" ����"<<endl;
    ntjob = tjob; //���α׷� �̹��� �޸𸮿� �ε��� ǥ��
}
int EHProcess::Running()//CPU�� �����Ͽ� ����, ���� �۾��� ��ȯ
{
	//	cout<< cjob<<" cjob\n";
	// cjob�� tjob�� �����ٸ��� �ϱ����ؼ� �޴� ���� ���̰� 
	// ���������� ���� ������ �ִ� ���� ntjob,ncjob�̴�.  
    ncjob = cjob; //ncjob�� CPU ����� �� �ִ� �ð� ����
 
    //���� �۾���(ntjob)�� CPU ����� �� �ִ� �ð�(ncjob)�� �ִٸ�
    for(  ; ntjob && ncjob ; ntjob--, ncjob--)
    {
        cout<<pname<<" ";//���� �ð� �۾� ������ ǥ��
    }
 
    cout<<endl; //CPU�� �ݳ����� ǥ��
    return ntjob; //���� �۾��� ��ȯ
}
void EHProcess::View(){
	 cout<< pname +"�� "<< " nt-"<<ntjob  << " nc-" <<ncjob << endl;
}
void EHProcess::EndProgram() //���μ��� ����
{
    cout<<pname<<"����"<<endl; //���μ��� ���Ḧ ǥ��
}
