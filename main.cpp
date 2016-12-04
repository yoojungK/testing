//
//  main.cpp
//  NQueen
//
//  Created by KimYoojung on 2016. 11. 26..
//  Copyright © 2016년 KimYoojung. All rights reserved.
//

#include <iostream>

using namespace std;

#define MAX_NUMBER 11
#define MAX_STATE 1025
#define INITIAL 0

int n, final_sum;
int list[MAX_NUMBER];
int solution_vector[MAX_NUMBER];
int total_visit = 0;
int total_node = 0;

void Input();
void Backtrack();
void Getnext( int k );
void Print();
bool Bound( int k );

int main ( int argc, const char * argv[] ) {
    
    Input();
    
    Backtrack();
    
    int two_of = 1;
    for ( int i = 0; i <= n; i ++ ) {
        total_node += two_of;
        two_of *= 2;
    }
    
    cout << total_visit << " " << total_node << " " << (double) total_visit / (double) total_node << endl;
    return 0;
    
}
void Input() { cin >> n; }
void Backtrack() {
    
    int k = 1;
    
    for ( int i = 1; i <= n; i ++ )
        solution_vector[i] = INITIAL;
    
    while ( 0 < k && k <= n ) {
        
        Getnext(k);
        
        if ( solution_vector[k] == INITIAL )
            k -- ;
        
        else {
            
            if ( k == n )
                Print();
            
            else
                k ++ ;
        }
        
    }
}
void Getnext( int k ) {
    
    int current_value = solution_vector[k];
    
    while ( current_value < n ) {
        
        current_value ++ ;
        
        solution_vector[k] = current_value;
        
        if ( Bound(k) == true ){
            total_visit ++;
            return ;
        }
        
    }
    if ( current_value == n )
        solution_vector[k] = INITIAL;
    
}
bool Bound( int k ) {
    
    int i;
    
    for ( i = 1; i < k; i ++ ) {
        if ( solution_vector[k] > solution_vector[i] ) {
            if ( (solution_vector[i] == solution_vector[k]) || ( k - i ) == ( solution_vector[k] - solution_vector[i] )) {
                return false ;
            }
        }
        else {
            if ( (solution_vector[i] == solution_vector[k]) || ( k - i ) == ( solution_vector[i] - solution_vector[k] )) {
                return false ;
            }
        }
    }
    return true;
}
void Print() {
    
    for ( int i = 1; i <= n; i++ )
        cout << solution_vector[i] << " ";
    
    cout << endl;
}
