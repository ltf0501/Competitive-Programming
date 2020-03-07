#include<bits/stdc++.h>
using namespace std;
main()
{
    bool bFirst=1;
    char szOrder[24];
    for(string str;getline(cin,str);bFirst=false)
    {
        strcpy(szOrder, str.c_str());
        int nLen=remove(szOrder,&szOrder[str.size()],' ')-szOrder;
        szOrder[nLen]='\0';
        getline(cin,str);
        str.erase(remove(str.begin(),str.end(),' '), str.end());
        //生成约束关系表，如果存在约束i > j，则aCompMat[i][j]为true
        bool aCompMat[26][26]={0};
        for (string::iterator i=str.begin();i!=str.end();i+=2)
        {
            aCompMat[*i-'a'][*(i+1)-'a']=true;
        }
        sort(&szOrder[0], &szOrder[nLen]);
        if(!bFirst)cout << endl;
        for(bool bFlag=1;bFlag;bFlag=next_permutation(&szOrder[0],&szOrder[nLen]))
        {
            for(int i=0;i<nLen-1 && bFlag;i++)
            {
                for(int j=i+1;j<nLen && bFlag;j++)
                {
                    bFlag &= !aCompMat[szOrder[j]-'a'][szOrder[i]-'a'];
                }
            }
            if(bFlag)
            {
                cout << szOrder << endl;
            }
        }
    }
    return 0;
}
