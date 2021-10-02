#include<iostream>
using namespace std;
int main()
{
	int num,loop,n;
	int sum;
		printf("::Perfect number between 1 to n:: ");
		cout<<endl;
		cout<<"Enter the value of n\n";
	//scanf("%d",&num);
  cin>>n;
	//sum=0;
	for(num=1; num<n;num++)
	{
		for(loop=1; loop<=num/2;loop++)
		//loop=1;
		//while(loop<=num/2)
		{
			if(num%loop==0)
			sum=sum+loop;
			//loop++;
			}
			
	
		//if(num%loop==0)
		//	sum+=loop;
	if(sum==num)
		printf("%d is a perfect number.\n",num);
		sum=0;
	//else
	//	printf("%d is not a perfect number.\n",num);

	}
	return 0;
	
}
