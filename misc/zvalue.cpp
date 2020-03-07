void z_function(int *z,string s)
{
    int L=0,R=0;
    int n=s.size();
    for(int i=1;i<n;i++)
    {
        if(i>R)
        {
            L=R=i;
            while(R<n && s[R-L]==s[R])R++;
            z[i]=(R--)-L;
        }
        else
        {
            int ii=i-L;
            if(i+z[ii]<R+1)z[i]=z[ii];
            else
            {
                L=i;
                while(R<n && s[R-L]==s[R])R++;
                z[i]=(R--)-L;
            }
        }
    }
}
