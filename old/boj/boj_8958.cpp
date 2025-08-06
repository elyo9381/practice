void Input()
{
    cin >> t;
}

void Solution()
{
    cin.ignore();
    while(t--){
        getline(cin,str);
        int num =0,sum = 0;
        for(int i = 0 ; i<str.size(); i++)
        {
            if(str[i] == 'O'){
                num += 1;
                sum += num;
            }else
            {
                num = 0;
            }
        }
        cout<< sum <<endl;

    }

} 