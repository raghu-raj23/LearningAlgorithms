#include "iostream"
using namespace std;

/*
1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
*/

void floyd(int num){
    int count = 0;
    for(int i =0; i<= num; i++){
        for(int j = 1; j<= i;j++){
            count+= 1;
            cout<<count<<" ";
        }
        cout<<endl;
    }
}

/*
*      *
**    **
***  ***
********
********
***  ***
**    **
*      *
*/

void butterfly(int num){
    for(int i = 1; i<= num; i++){
        for(int j = 1; j<= i; j++){
            cout<<"*";
        }
        int space = 2*(num-i);
        for(int j = 1;j<=space;j++){
            cout<<" ";
        }
        for(int j = 1; j<= i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i = num; i>= 1; i--){
        for(int j = 1; j<= i; j++){
            cout<<"*";
        }
        int space = 2*(num-i);
        for(int j = 1;j<=space;j++){
            cout<<" ";
        }
        for(int j = 1; j<= i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}


/*
1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1 
*/
void zerOne(int num){

    for(int i =1; i<= num; i++){
        for(int j = 1; j<= i; j++){
            (i+j)%2==0?cout<<1<<" ":cout<<0<<" ";
        }
        cout<<endl;
    }
}
/*
    * * * * * 
   * * * * * 
  * * * * * 
 * * * * * 
* * * * * 
*/
void rhombus(int num){
    for(int i = 1; i<= num; i++){
        for(int j = 1; j<= num -i; j++){
            cout<<" ";
        }
        for(int j = 1; j<= num;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pyramid_(int num){
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= num-i; j++){
            cout<<" ";
        }
        for(int j = 1; j <= num; j++){

        }
    }
}
/*
    *       *     
  *   *   *   *   
*       *       * 
*/
void zigZag(int num){
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j<= num; j++){
            if((i+j)%4==0 ||(i==2 && j%4==0)){
                cout<<"* ";
            }
            else
            cout<<"  ";
        }
        cout<<endl;
    }
}


int fact(int num){
    int factorial = 1;
    for(int i=2; i<= num; i++){
        factorial *= i;
    }
    return factorial;
}

int main(){
    int n = 9;
    floyd(5);
    butterfly(4);
    zerOne(5);
    rhombus(5);
    pyramid_(5);
    zigZag(9);

    // Pascal triangle each element is iCj
/*
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
1 7 21 35 35 21 7 1 
1 8 28 56 70 56 28 8 1
*/

    for(int i=0; i< n; i++){
        for(int j = 0; j<=i;j++){
            cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
        }
        cout<<endl;
    }


    return 0;
}