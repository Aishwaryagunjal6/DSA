#include <iostream>
#include <string.h>
using namespace std;


struct Student
{
	int rollno;
	string name;
	float sgpa;
	
};
class SEIT
{
	struct Student S[3];
	
	public:

	void input()
	{
		for(int i=0; i<3; i++)
		{
			cout<<"\nEnter the name = ";
			cin>>S[i].name;
			for(int j=i; j>0; j--)
			{
				if(S[i].name == S[j-1].name)
				{
					cout<<"\nName is repeted enter valid name ";
					cout<<"\nEnter the name = ";
					cin>>S[i].name;
				}
			}
	
			cout<<"\nEnter the roll no = ";
			cin>>S[i].rollno;
			for(int j=i; j>0; j--)
			{
				if(S[i].rollno == S[j-1].rollno)
				{
					cout<<"\nrollno is repeted enter valid rollno ";
					cout<<"\nEnter the roll = ";
					cin>>S[i].rollno;
				}
			}
			
			cout<<"\nEnter the sgpa = ";
			cin>>S[i].sgpa;
			
			if(S[i].sgpa <0 && S[i].sgpa>10)
			{
				cout<<"\nsgpa is repeted enter valid sgpa ";
				cout<<"\nEnter the sgpa = ";			
				cin>>S[i].sgpa;
			}
		
			cout<<"\n";
			
		}
	}
	void display(int i)
	{
		cout<<"\n\nName = "<<S[i].name;
		cout<<"\nRoll no = "<<S[i].rollno;
		cout<<"\nSGPA = "<<S[i].sgpa;
		cout<<endl;
			
	}	
	void display2()
	{
		for(int i=0; i<3; i++)
		{
			cout<<"\n\nName = "<<S[i].name;
			cout<<"\nRoll no = "<<S[i].rollno;
			cout<<"\nSGPA = "<<S[i].sgpa;
			cout<<endl;
			
		}	
			
	}
	
	void search()
	{
		float data;
		int i;
		cout<<"\nEnter the sgpa to search a data = ";
		cin>>data;
		for(i=0; i<5; i++)
		{
			if(S[i].sgpa==data)
			{
				display(i);
				break;
			}
		}
		if(i==5)
		{
			cout<<"\ndata not found"<<endl;
		}
		
	}
	void bubble_sort()
	{
		int temp1;
		float temp3;
		string temp2;
		
		for(int i=1; i<5; i++)
		{
			for(int j=0; j<5; j++)
			{
				if(S[i].rollno < S[j].rollno)
				{
					temp1=S[i].rollno;
					S[i].rollno=S[j].rollno;
					S[j].rollno=temp1;
					
					temp2=S[i].name;
					S[i].name=S[j].name;
					S[j].name=temp2;
					
					temp3=S[i].sgpa;
					S[i].sgpa=S[j].sgpa;
					S[j].sgpa=temp3;
				}
			}
		}
		display2();
	}

	void insertion()
	{
    	for (int i=1; i<5; i++) 
		{
        	int j = i;
        	int x;
        	float y;
        	while (j > 0) 
			{
                if(S[j - 1].name.compare(S[j].name)>0)
                {
                    string temp;
                	temp=S[j - 1].name;
                    S[j - 1].name=S[j].name;
                    S[j].name=temp;
                	
                	x=S[j-1].rollno;
					S[j-1].rollno=S[j].rollno;
					S[j].rollno=x;                	
                	
                	y=S[j-1].sgpa;
					S[j-1].sgpa=S[j].sgpa;
					S[j].sgpa=y;
                }
                j--;
        	}
    	}
	}

    void binary_search()
    {
        int up=2;
        int low=0;
        int mid,x;
        cout<<"\nEnter roll no to search = ";
        cin>>x;
        
        while(low<=up)
        {
	    mid=(up+low)/2;
            if(S[mid].rollno==x)
            {
                cout<<"found";
                break;
            }
            else if(x<S[mid].rollno)
            {
                up=mid-1;          
            }
            else if(x>S[mid].rollno)
            {
                low=mid+1;
            }

        }
        if(low>up)
        {
            cout<<"not found";
        }
    }
    
	int partition(int low,int up)
	{
    	int pivot,p,q,Temp3,Temp5;
    	float Temp2,Temp;
    	string Temp4,Temp6;
    	pivot=S[low].sgpa;
    	q=up;
    	p=low+1;
    	while(p<=q)
    	{
    		
    		while(S[p].sgpa < pivot)
    		{
    			p++;
    		}
    		
    		while(S[q].sgpa > pivot)
    		{
    			q--;
    			
    		}
    		
    		if(p<q)
    		{
    			Temp=S[p].sgpa;
    			S[p].sgpa=S[q].sgpa;
    			S[q].sgpa=Temp;
    			
    			Temp3=S[p].rollno;
				S[p].rollno=S[q].rollno;
				S[q].rollno=Temp3;
					
				Temp4=S[p].name;
				S[p].name=S[q].name;
				S[q].name=Temp4;
				p++;
				q--;
    		}
    		else
    		{
    			break;
    		}
    		
    		
    	} 
    	Temp2=S[low].sgpa;
    	S[low].sgpa=S[q].sgpa;
    	S[q].sgpa=Temp2;
    	
    	Temp5=S[low].rollno;
		S[low].rollno=S[q].rollno;
		S[q].rollno=Temp5;
					
		Temp6=S[low].name;
		S[low].name=S[q].name;
		S[q].name=Temp6;

    	return q;
    		
	}
    
	void quick_sort(int low,int up)
	{
    	int k;
    	if(low<=up)
    	{
    		k = partition(low,up);
    		quick_sort(low,k-1);
    		quick_sort(k+1,up);
    	}		
	}
	
};

int main()
{
	SEIT obj;
	obj.input();
	int choice;
	int x;
	do
	{
		cout<<"\n1:Display data\n2:search data\n3:sort data\n4:New input\n5:sort names\n6:binary search\n7:sort by sgpa\nEnter your choise = ";
		cin>>choice;
		//Student S;
		switch(choice)
		{
			case 1:obj.display2();
				break;
				
			case 2:obj.search();
				break;
				
			case 3:obj.bubble_sort();
				break;
				
			case 4:obj.input();
				break;
				
			case 5:obj.insertion();
			       obj.display2();
               		break;

            case 6:obj.binary_search();
					break;
				
			case 7:obj.quick_sort(0,2);
					obj.display2();
					break;
			
			default : cout<<"\nInvalid input";
		}
		cout<<"\nIf u want to repeat then press 1 = ";
		cin>>x;	
	}while(x==1);
	
	return 0;
}

	


