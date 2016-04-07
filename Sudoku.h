#include<iostream>
#include<string>
#define false 0
#include<cstdio>
using namespace std;

class Sudoku{
	public:
      void giveQuestion();
	  int  matrix_input[9][9];
	  void changeNum(int a,int b);
	  void changeRow(int a,int b);
	  void changeCol(int a,int b);
	  void rotate(int n);
	  void flip(int n);
	  void transform();
	  void readIn();
	  void solve();
	  void reset_the_table(int arr[9][9][9],int ans_s[9][9],int matrix_in[9][9],int,int,int);
	  void hidden_find(int arr[9][9][9],int ans_s[9][9],int matrix_in[9][9]);
	  void naked_find(int arr[9][9][9],int ans_s[9][9],int matrix_in[9][9]);
	  void pointing_pait_find(int pos_ans[9][9][9],int ans_s[9][9],int matrix_in[9][9]);
	  void naked_pair(int pos_ans[9][9][9],int ans_s[9][9],int matrix_in[9][9]);
	  void hidden_pair(int pos_ans[9][9][9],int ans_s[9][9],int matrix_in[9][9]);
	  int  no_solution(int matrix_in[9][9]);
	  int  no_solution2(int ans_s[9][9],int matrix_in[9][9]);
	  
	private:
	  
};