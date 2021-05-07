#include <iostream>

void printfunc(int b[],int a)
{
    std::cout<<"Elements of arrays are: ";
    for(int i=0; i<a; i++)
    {
        std::cout<<b[i]<<" ";
    }
    std::cout<<std::endl;
}

void swaping(int c[],int a,int b)
{
    int temp=c[a];
    c[a]=c[b];
    c[b]=temp;
}

int parti(int c[],int a,int b)
{
    int pivot=c[0];//using 1st element as pivot in the array
    int left=a,right=a;
    while(right!=b)
    {
        if(c[right]<pivot)
        {
            left++;
            swaping(c,left,right);

        }
        right++;
    }
    swaping(c,0,left);
    return left;
}


int qsort(int c[],int a,int b)
{
    if(a==b)
    {
        return c[b];
    }
    else
    {
        int d=parti(c,a,b);
        qsort(c,a,d-1);
        qsort(c,d+1,b);
    }
}


int main()
{
    std::cout<<"\n\nEnter the number of elements you want in the array\n";
    int a;
    std::cin>>a;
    int b[a];
    for(int i=0; i<a; i++)
    {
        std::cout<<"Enter the element for the index "<<i<<std::endl;
        std::cin>>b[i];
    }
    printfunc(b,a);
    qsort(b,0,a-1);
    printfunc(b,a);

}
