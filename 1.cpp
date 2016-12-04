//
//  main.cpp
//  SumOfSubset
//
//  Created by KimYoojung on 2016. 11. 26..
//  Copyright © 2016년 KimYoojung. All rights reserved.
//

#include <iostream>

using namespace std;

#define MAX_NUMBER 11
#define MAX_STATE 1025
#define INITIAL -1

int n, final_sum;
int list[MAX_NUMBER];
int solution_vector[MAX_NUMBER];
int total_visit = 0;
int total_node = 0;

void Input();
void Backtrack();
void Getnext( int k );
void PrintSolution();
void PrintCount();
bool Bound( int k );

int main ( int argc, const char * argv[] ) {
    
    Input();
    
    Backtrack();
    
    PrintCount();
    
    return 0;
    
}
void Input(){
    
    cin >> n;
    
    for( int i=1; i<=n; i++ )
        cin >> list[i];
    
    cin >> final_sum;
    
}
void Backtrack(){
    
    int k = 1;
    
    for ( int i = 1; i <= n; i ++ )
        solution_vector[i] = INITIAL;
    
    while ( 0 < k && k <= n ) {
        
        Getnext(k);
        
        if ( solution_vector[k] == INITIAL )
            k -- ;
        
        else {
            
            if ( k == n )
                PrintSolution();
            
            else
                k ++ ;
        }
        
    }
}
void Getnext( int k ) {
    
    int current_value = solution_vector[k];
    
    while ( current_value < 1 ) {
        
        current_value ++ ;
        
        solution_vector[k] = current_value;
        total_visit ++ ;
        
        if ( Bound(k) == true ){
            return ;
        }
        
    }
    if ( current_value == 1 )
        solution_vector[k] = INITIAL;
    
}
bool Bound( int k ) {
    
    int i, sum = 0, after_sum = 0;
    int stop_point1 = 0, stop_point2 = 0;
    
    for ( i = 1; i <= k; i ++ ) {
        
        sum += solution_vector[i] * list[i];
        
        if ( sum > final_sum ){
            stop_point1 = 1;
            break;
        }
    }
    
    if ( i == k + 1 ) {
        for ( i = k+1 ; i <= n; i ++ )
            after_sum += list[i];
        
        if ( (sum + after_sum) < final_sum )
            stop_point2 = 1;
        
    }
    
    if ( stop_point1 == 0 && stop_point2 == 0 ) return true;
    else return false;
}
void PrintSolution() {
    
    for ( int i = 1; i <= n; i++ )
        cout << solution_vector[i] << " ";
    
    cout << endl;
}
void PrintCount(){
    
    int i, two_of = 1;
    
    for ( i = 0 ; i <= n; i ++ ){
        total_node += two_of;
        two_of *= 2;
    }
    cout << total_visit << " " << total_node <<" " << ((double)(total_visit) / (double)(total_node)) << endl;
    

}
