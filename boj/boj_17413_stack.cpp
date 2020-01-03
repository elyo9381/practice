#include <iostream>
#include <stack>
using namespace std;

/*출력을 할때 bool 변수를 통해서 출력을했는지
안했는지 확인하여 <>안의 데이터를 출력한다. 
<>안의 데이터는 역순이 아니므로  */

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> st;

        string str;
        getline(cin, str);
        bool print = false;
        str +="\n";
        for(char ch :str)
        {
            if(print && ch!='<'&& ch!='>')
            {
                cout<<ch;
            }
            else if(!print && ch =='<')
            {
                while(!st.empty())
                {
                    cout<<st.top();
                    st.pop();
                }
                cout<<'<';
                print = true;
            }
            else if(print && ch=='>')
            {
                cout<<'>';
                print=false;
            }
            else if(!print&& ch!='<'&&ch!='>'&&(ch == ' '||ch=='\n'))
            {
                while(!st.empty()) {
                cout << st.top();
                st.pop();
                }
                cout<<' ';
            }
            else if(!print && ch =='<'&& ch!= '>'&& ch!=' '&& ch!='\n')       
            {                if(!st.empty())
                {
                    st.push(ch);
                }

            }
            else
            {
                st.push(ch);
            }
        }
    
        return 0;
}
