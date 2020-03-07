typedef complex<double> cp;
struct FFT
{
	int n,rev[maxn];
	cp omega[maxn],iomega[maxn];
	void init(int n)
	{
		this->n=n;
		for(int i=0;i<n;i++)
		{
			omega[i]=cp(cos(2*pi/n*i),sin(2*pi/n*i));
			iomega[i]=conj(omega[i]);
		}
		int k=log2(n);
		for(int i=0;i<n;i++)
		{
			int t=0;
			for(int j=0;j<k;j++)if(i&(1<<j))t|=(1<<(k-j-1));
			rev[i]=t;
		}
	}
	void transform(vector<cp>& a,cp* omega)
	{
		for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int len=2;len<=n;len<<=1)
		{
			int mid=len>>1;
			for(int j=0;j<n;j+=len)for(int i=0;i<mid;i++)
			{
				cp t=omega[n/len*i]*a[j+mid+i];
				a[j+mid+i]=a[j+i]-t;
				a[j+i]+=t;
			}
		}
	}
	void fft(vector<cp>& a)
	{
		transform(a,omega);
	}
	void ifft(vector<cp>& a)
	{
		transform(a,iomega);
		for(int i=0;i<n;i++)a[i]/=n;
	}
}
vector<ll> mul(vector<ll> a,vector<ll> b)
{
	int n=1;
	int n1=(int)a.size(),n2=(int)b.size();
	while(n<n1+n2)n<<=1;
}
