#pragma once
#include <iostream>
#include <string>
using namespace std;
 
class EHProcess
{
    string pname; //���α׷� �̸�
    const int tjob; //��ü �۾���
    const int cjob; //cpu ���� �� ���డ�� �ִ� �۾���
    int ntjob; //���� ���� �۾���
    int ncjob; //���� cpu ���� �� ���డ�� �ִ� �۾���
public:
    EHProcess(string pname,int tjob,int cjob);
    void IdleToReady();//Idle ���¿��� Ready ���·� ����
    int Running();//CPU�� �����Ͽ� ����, ���� �۾��� ��ȯ
    void EndProgram(); //���μ��� ����
    void View();
};
