using namespace std;
int main()
{
  int n,m,i;
  cout<<"Enter size of array 1\n";
  cin>>n;
  cout<<"Enter size of array 2\n";
  cin>>m;
  int a[n],b[m],c[n+m];
  cout<<"Enter elements of array 1\n";
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"Enter elements of array 2\n";
  for(i=0;i<m;i++)
  {
    cin>>b[i];
  }
  i=0;
  int j=0,k=0;
  while(i!=n && j!=m)
  {
    if(a[i]<b[j])
    {
      c[k]=a[i];
      k++;
      i++;
    }
    else if(b[j]<a[i])
    {
      c[k]=b[j];
      k++;
      j++;
    }
    else if(b[j]==a[i])
    {
      c[k]=a[i];
      i++;
      k++;
      c[k]=b[j];
      k++;
      j++;
    }
  }
  if(i == n)
  {
    while(j!=m)
    {
      c[k]=b[j];
      k++;
      j++;
    }
  }
  if(j == m)
  {
    while(i!=n)
    {
      c[k]=a[i];
      k++;
      i++;
    }
  }
cout<<"Your sorted array is\n";
for(i=0;i<n+m;i++)
{
  cout<<c[i]<<endl;
}
return 0;
}
