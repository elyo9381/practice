//algorithm.h
#pragma once
namespace ehlib
{
    template <typename Iter,typename Fun>
    Iter find_if(Iter beg,Iter end,Fun fun)
    {
    	//find_if는 탐색 구간을 순차적으로 이동하면서
		//원하는 조건을 만족하는 위치를 찾는 알고리즘입니다. 
    	for(	; beg!=end; ++beg)
    	{
    		//세 번째 전달할 함수(혹은 함수 개체)에
			//탐색 구간에 있는 자료를  적용했을때 참인지 판별합니다.
			// 반복자는 간접연사으로 보관한 자료를 구할수 있으니 다음처럼 표현할수 있어요. 
    		if(fun(*beg))
    		{
    			break;
			}
		}
        return beg;
    }
}
