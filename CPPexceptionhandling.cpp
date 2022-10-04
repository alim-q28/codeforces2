

void process_input(int n) 
{
    try {
    if(n==0 || n==1)
    {
        throw (n);
    }
    else
    largest_proper_divisor(n);
    cout << "result=" << largest_proper_divisor(n)<< endl;
    } catch (int m) {
        cout<< "largest proper divisor is not defined for n="<<m<<endl;
    }
    cout<<"returning control flow to caller"<<endl;
    
}

