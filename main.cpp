

#include <iostream>


using namespace std;

bool ispossible( int cook[] , int n  ,int  mid , int p  ){

    int countp =0;

    for(int i=0 ; i < n ; i++){
        int sum =0 ;

        for(int j=1 ; j<=p ;j++){

            sum += cook[i]*j ;

            if(sum <=mid){

                if(countp >= p)
                    return true ;
                countp ++;
            }

            else
                break ;
        }
    }
    return false ;
}

int bs( int p , int cook[]  , int n ){

    int ans=-1 ;
    int high = 1e8;
    int low = 0 ;

    while(high >=low){
        int mid = low  + ( high - low )/2 ;

        if( ispossible( cook,n , mid , p) ){
            ans = mid ;
            high = mid-1;
        }

        else{
            low = mid +1 ;
        }
    }

    return ans ;
}



int main()
{
        int p;
        cin>>p;
        int n;
        cin>>n;
        int cook[n];
        for(int i=0;i<n;i++)
            cin>>cook[i];

        cout<<bs(p,cook,n)<<endl;


    return 0;
}

