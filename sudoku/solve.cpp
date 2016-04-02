#include<iostream>
#include<string>
#define false 0
#define true 1
#include<cstdio>
#include "Sudoku.h"
using namespace std;


	  int main(){
		  Sudoku ss;
		  ss.readIn();
		  ss.solve();
		  
		  return 0;
	  }
	 