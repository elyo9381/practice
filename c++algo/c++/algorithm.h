//algorithm.h
#pragma once
namespace ehlib
{
    template <typename Iter,typename Fun>
    Iter find_if(Iter beg,Iter end,Fun fun)
    {
    	//find_if�� Ž�� ������ ���������� �̵��ϸ鼭
		//���ϴ� ������ �����ϴ� ��ġ�� ã�� �˰����Դϴ�. 
    	for(	; beg!=end; ++beg)
    	{
    		//�� ��° ������ �Լ�(Ȥ�� �Լ� ��ü)��
			//Ž�� ������ �ִ� �ڷḦ  ���������� ������ �Ǻ��մϴ�.
			// �ݺ��ڴ� ������������ ������ �ڷḦ ���Ҽ� ������ ����ó�� ǥ���Ҽ� �־��. 
    		if(fun(*beg))
    		{
    			break;
			}
		}
        return beg;
    }
}
