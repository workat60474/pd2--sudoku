#include<iostream>
#include<string>
#define false 0
#define true 1
#include<cstdio>
#include "Sudoku.h"
using namespace std;

void Sudoku::solve(){
    
	int possible_ans[9][9][9],ansewer_sets[9][9];
	int blank_num=0,the_number_appear=0;
	int one_to_nine[9];
	
	for(int i=0;i<9;i++){
		one_to_nine[i]=false;
		for(int j=0;j<9;j++)
		{
			for(int k=0;k<9;k++ ) possible_ans[i][j][k]=true;
		}
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
		{
		    ansewer_sets[i][j]=0;
			if(matrix_input[i][j]!=0) {
				one_to_nine[matrix_input[i][j]-1]=true;
				blank_num++;
				for(int k=0;k<9;k++ ) possible_ans[i][j][k]=false;
			}
		}
	}
	for(int i=0;i<9;i++) {if(one_to_nine[i]==true) the_number_appear++;}
	if(no_solution(matrix_input)) {cout<<"0"<<endl; return;}
	if(blank_num<17||the_number_appear<8) {cout<<"2"<<endl; return;} //the numbers of nonzero terms are less than 17 >>more than 2 solution
	
	blank_num=81-blank_num;
	if(blank_num==0) {
			cout<<"1"<<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++){
		cout<<matrix_input[i][j]<<" ";
	}
	cout<<"\n";
	}
	return;
	}
	//check for everyrows to determind which number are possible_ans
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(matrix_input[i][j]!=0) {
				for(int k=0;k<9;k++ ) possible_ans[i][k][matrix_input[i][j]-1]=false;
			}
		}
	}
	//check for everycols to determind which number are possible_ans
	for(int j=0;j<9;j++){
		for(int i=0;i<9;i++) {
			if(matrix_input[i][j]!=0) {
				for(int k=0;k<9;k++ ) possible_ans[k][j][matrix_input[i][j]-1]=false;
			}
		}
	}
	//check for every subgrid
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(matrix_input[i][j]!=0) {
				for( int m=0;m<3;m++){
					for(int n=0;n<3;n++) possible_ans[m][n][matrix_input[i][j]-1]=false;
				}
			}
		}
	}
	for(int i=3;i<6;i++){
		for(int j=0;j<3;j++){
			if(matrix_input[i][j]!=0) {
				for( int m=3;m<6;m++){
					for(int n=0;n<3;n++) possible_ans[m][n][matrix_input[i][j]-1]=false;
				}
			}
		}
	}
	for(int i=6;i<9;i++){
		for(int j=0;j<3;j++){
			if(matrix_input[i][j]!=0) {
				for( int m=6;m<9;m++){
					for(int n=0;n<3;n++) possible_ans[m][n][matrix_input[i][j]-1]=false;
				}
			}
		}
	}
	for(int i=0;i<3;i++){
		for(int j=3;j<6;j++){
			if(matrix_input[i][j]!=0) {
				for( int m=0;m<3;m++){
					for(int n=3;n<6;n++) possible_ans[m][n][matrix_input[i][j]-1]=false;
				}
			}
		}
	}
	for(int i=3;i<6;i++){
		for(int j=3;j<6;j++){
			if(matrix_input[i][j]!=0) {
				for( int m=3;m<6;m++){
					for(int n=3;n<6;n++) possible_ans[m][n][matrix_input[i][j]-1]=false;
				}
			}
		}
	}
	for(int i=6;i<9;i++){
		for(int j=3;j<6;j++){
			if(matrix_input[i][j]!=0) {
				for( int m=6;m<9;m++){
					for(int n=3;n<6;n++) possible_ans[m][n][matrix_input[i][j]-1]=false;
				}
			}
		}
	}
	for(int i=0;i<3;i++){
		for(int j=6;j<9;j++){
			if(matrix_input[i][j]!=0) {
				for( int m=0;m<3;m++){
					for(int n=6;n<9;n++) possible_ans[m][n][matrix_input[i][j]-1]=false;
				}
			}
		}
	}
	for(int i=3;i<6;i++){
		for(int j=6;j<9;j++){
			if(matrix_input[i][j]!=0) {
				for( int m=3;m<6;m++){
					for(int n=6;n<9;n++) possible_ans[m][n][matrix_input[i][j]-1]=false;
				}
			}
		}
	}
	for(int i=6;i<9;i++){
		for(int j=6;j<9;j++){
			if(matrix_input[i][j]!=0) {
				for( int m=6;m<9;m++){
					for(int n=6;n<9;n++) possible_ans[m][n][matrix_input[i][j]-1]=false;
				}
			}
		}
	}
	//set ansewer_sets
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			for(int k=0;k<9;k++) if(possible_ans[i][j][k]==true && matrix_input[i][j]==0) {ansewer_sets[i][j]++;}
		}
	}
	int sol=0;
	int count=0,en=0;
	int canfind_nake=0;
	while(blank_num>0  && en<150){
		pointing_pait_find(possible_ans,ansewer_sets,matrix_input);
		naked_pair(possible_ans,ansewer_sets,matrix_input);
		for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(ansewer_sets[i][j]==1) {
			    canfind_nake=1;
				blank_num--;
				for(int k=0;k<9;k++) {
					if(possible_ans[i][j][k]==true)
					{   
						sol=k+1;
					    matrix_input[i][j]=sol;
						ansewer_sets[i][j]=0;
					    reset_the_table(possible_ans,ansewer_sets,matrix_input,i,j,sol);
						
					}
					}
			}
			
		}}
        if(canfind_nake==0) {	hidden_find(possible_ans,ansewer_sets,matrix_input);
		                        pointing_pait_find(possible_ans,ansewer_sets,matrix_input);
								naked_pair(possible_ans,ansewer_sets,matrix_input);
		}	
        canfind_nake=0;		
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++){
				if(ansewer_sets[i][j]==0) count++;
			}
		}
		if(count==81) blank_num=0;
		count=0;en++;
	}
	int solution_exist;
	if(blank_num!=0 ){
		solution_exist=no_solution2(ansewer_sets,matrix_input);
		if(solution_exist==1) {cout<<"0"<<endl;return;}
		}
		if(en>=150) {cout<<"2"<<endl;return;}
		cout<<"1"<<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++){
		cout<<matrix_input[i][j]<<" ";
	}
	cout<<"\n";
	}
    
	}//end of solve


	void Sudoku::pointing_pait_find(int pos_ans[9][9][9],int ans_s[9][9],int matrix_in[9][9]){
		int digits[9],judge=0,j,p;
		//search block1
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=0;i<3;i++)
		{
			for(j=0;j<3;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=0;l<3;l++){
						   for(int h=0;h<3;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=3;p<9;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
						 } judge=0;
					   } //check block1's row part
				        for(int h=0;h<3;h++){
							for(int l=0;l<3;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=3;p<9;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
						 }	 judge=0;
						}//check block1's col part   
				   }
			   } 
	   // end of search block1
		//search block2
		judge=0;
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=0;i<3;i++)
		{
			for(j=3;j<6;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=0;l<3;l++){
						   for(int h=3;h<6;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=0;p<3;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
							for(p=6;p<9;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }					 
						 } judge=0;
					   } //check block2's row part
				        for(int h=3;h<6;h++){
							for(int l=0;l<3;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=3;p<9;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
						 }	 judge=0;
						}//check block2's col part   
				   }
			   } 
	   // end of search block2
	   //search block3
		judge=0;
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=0;i<3;i++)
		{
			for(j=6;j<9;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=0;l<3;l++){
						   for(int h=6;h<9;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=0;p<6;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
											 
						 } judge=0;
					   } //check block3's row part
				        for(int h=6;h<9;h++){
							for(int l=0;l<3;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=3;p<9;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
						 }	 judge=0;
						}//check block3's col part   
				   }
			   } 
	   // end of search block3
	   //search block4
		judge=0;
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=3;i<6;i++)
		{
			for(j=0;j<3;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=3;l<6;l++){
						   for(int h=0;h<3;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=3;p<9;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
											 
						 } judge=0;
					   } //check block4's row part
				        for(int h=0;h<3;h++){
							for(int l=3;l<6;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=0;p<3;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
							for(p=6;p<9;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }				   
						 }	 judge=0;
						}//check block4's col part   
				   }
			   } 
	   // end of search block4
	    //search block5
		judge=0;
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=3;i<6;i++)
		{
			for(j=3;j<6;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=3;l<6;l++){
						   for(int h=3;h<6;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=0;p<3;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
							for(p=6;p<9;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }				 
						 } judge=0;
					   } //check block5's row part
				        for(int h=3;h<6;h++){
							for(int l=3;l<6;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=0;p<3;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
							for(p=6;p<9;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }				   
						 }	 judge=0;
						}//check block5's col part   
				   }
			   } 
	   // end of search block5
	   //search block6
		judge=0;
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=3;i<6;i++)
		{
			for(j=6;j<9;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=3;l<6;l++){
						   for(int h=6;h<9;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=0;p<6;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
							
						 } judge=0;
					   } //check block6's row part
				        for(int h=6;h<9;h++){
							for(int l=3;l<6;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=0;p<3;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
							for(p=6;p<9;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }				   
						 }	 judge=0;
						}//check block6's col part   
				   }
			   } 
	   // end of search block6
	   //search block7
		judge=0;
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=6;i<9;i++)
		{
			for(j=0;j<3;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=6;l<9;l++){
						   for(int h=0;h<3;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=3;p<9;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
											 
						 } judge=0;
					   } //check block7's row part
				        for(int h=0;h<3;h++){
							for(int l=6;l<9;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=0;p<6;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
										   
						 }	 judge=0;
						}//check block7's col part   
				   }
			   } 
	   // end of search block7
	   //search block7
		judge=0;
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=6;i<9;i++)
		{
			for(j=0;j<3;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=6;l<9;l++){
						   for(int h=0;h<3;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=3;p<9;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
											 
						 } judge=0;
					   } //check block7's row part
				        for(int h=0;h<3;h++){
							for(int l=6;l<9;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=0;p<6;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
										   
						 }	 judge=0;
						}//check block7's col part   
				   }
			   } 
	   // end of search block7
	   
	   //search block8
		judge=0;
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=6;i<9;i++)
		{
			for(j=3;j<6;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=6;l<9;l++){
						   for(int h=3;h<6;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=0;p<3;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
							for(p=6;p<9;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }					 
											 
						 } judge=0;
					   } //check block8's row part
				        for(int h=3;h<6;h++){
							for(int l=6;l<9;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=0;p<6;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
										   
						 }	 judge=0;
						}//check block8's col part   
				   }
			   } 
	   // end of search block8
	   //search block9
		judge=0;
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=6;i<9;i++)
		{
			for(j=6;j<9;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
		} 
		for(int k=0;k<9;k++)
			   {
				   if(digits[k]==2) {
					   for(int l=6;l<9;l++){
						   for(int h=6;h<9;h++){
							 if(  pos_ans[l][h][k]==true ) judge++;
						   }
						 if(judge==2)  { //the pointingpair happend in row L,we delete all the other candicate in other block
							for(p=0;p<6;p++) { if(pos_ans[l][p][k]==true && matrix_in[l][p]==0)
								                    {ans_s[l][p]--;}	
								                 pos_ans[l][p][k]=false; }
										 
											 
						 } judge=0;
					   } //check block9's row part
				        for(int h=6;h<9;h++){
							for(int l=6;l<9;l++){
							 if(  pos_ans[l][h][k]==true ) judge++;
							}
						 if(judge==2){ //the pointingpair happend in col h,we delete all the other candicate in other block
							for(p=0;p<6;p++) {if(pos_ans[p][h][k]==true && matrix_in[p][h]==0) 
								                    {ans_s[p][h]--; }
							                   pos_ans[p][h][k]=false;  }
										   
						 }	 judge=0;
						}//check block9's col part   
				   }
			   } 
	   // end of search block9
	   //start searching for pointing pair in box
	   //for box1
	   
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=0;i<3;i++)
		{
			for(j=0;j<3;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box1裡面row i具有兩個相同的candicate
				{                //現在check在整個table的第i列是否只有唯一存在2個
				 for(int l=3;l<9;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=0;s<3;s++){
						if(s!=i){
							for(int m=0;m<3;m++){
							if(pos_ans[s][m][k]==true && matrix_in[s][m]==0) {ans_s[s][m]--;}	
							pos_ans[s][m][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for row of box1
		for(int x=0;x<9;x++) digits[x]=0;
		for(j=0;j<3;j++)
		{
			for(int i=0;i<3;i++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box1裡面col j具有兩個相同的candicate
				{                //現在check在整個table的第j行是否只有唯一存在2個
				 for(int l=3;l<9;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=0;s<3;s++){
						if(s!=j){
							for(int m=0;m<3;m++){
							if(pos_ans[m][s][k]==true && matrix_in[m][s]==0) {ans_s[m][s]--;}	
							pos_ans[m][s][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for col of box1
		//end of search for box1
		
		 //for box2
	   
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=0;i<3;i++)
		{
			for(j=3;j<6;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box2裡面row i具有兩個相同的candicate
				{                //現在check在整個table的第i列是否只有唯一存在2個
				 for(int l=0;l<3;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				 for(int l=6;l<9;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=0;s<3;s++){
						if(s!=i){
							for(int m=3;m<6;m++){
							if(pos_ans[s][m][k]==true && matrix_in[s][m]==0) {ans_s[s][m]--;}	
							pos_ans[s][m][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for row of box2
		for(int x=0;x<9;x++) digits[x]=0;
		for(j=3;j<6;j++)
		{
			for(int i=0;i<3;i++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box2裡面col j具有兩個相同的candicate
				{                //現在check在整個table的第j行是否只有唯一存在2個
				 for(int l=3;l<9;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=3;s<6;s++){
						if(s!=j){
							for(int m=0;m<3;m++){
							if(pos_ans[m][s][k]==true && matrix_in[m][s]==0) {ans_s[m][s]--;}	
							pos_ans[m][s][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for col of box2
		//end of search for box2
		//for box3
	   
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=0;i<3;i++)
		{
			for(j=6;j<9;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box3裡面row i具有兩個相同的candicate
				{                //現在check在整個table的第i列是否只有唯一存在2個
				 for(int l=0;l<6;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				 
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=0;s<3;s++){
						if(s!=i){
							for(int m=6;m<9;m++){
							if(pos_ans[s][m][k]==true && matrix_in[s][m]==0) {ans_s[s][m]--;}	
							pos_ans[s][m][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for row of box3
		for(int x=0;x<9;x++) digits[x]=0;
		for(j=6;j<9;j++)
		{
			for(int i=0;i<3;i++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box3裡面col j具有兩個相同的candicate
				{                //現在check在整個table的第j行是否只有唯一存在2個
				 for(int l=3;l<9;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=6;s<9;s++){
						if(s!=j){
							for(int m=0;m<3;m++){
							if(pos_ans[m][s][k]==true && matrix_in[m][s]==0) {ans_s[m][s]--;}	
							pos_ans[m][s][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for col of box3
		//end of search for box3
		//for box4
	   
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=3;i<6;i++)
		{
			for(j=0;j<3;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box4裡面row i具有兩個相同的candicate
				{                //現在check在整個table的第i列是否只有唯一存在2個
				 for(int l=3;l<9;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				 
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=3;s<6;s++){
						if(s!=i){
							for(int m=0;m<3;m++){
							if(pos_ans[s][m][k]==true && matrix_in[s][m]==0) {ans_s[s][m]--;}	
							pos_ans[s][m][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for row of box4
		for(int x=0;x<9;x++) digits[x]=0;
		for(j=0;j<3;j++)
		{
			for(int i=3;i<6;i++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box4裡面col j具有兩個相同的candicate
				{                //現在check在整個table的第j行是否只有唯一存在2個
				 for(int l=0;l<3;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				 for(int l=6;l<9;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=0;s<3;s++){
						if(s!=j){
							for(int m=3;m<6;m++){
							if(pos_ans[m][s][k]==true && matrix_in[m][s]==0) {ans_s[m][s]--;}	
							pos_ans[m][s][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for col of box4
		//end of search for box4
		//for box5
	   
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=3;i<6;i++)
		{
			for(j=3;j<6;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box5裡面row i具有兩個相同的candicate
				{                //現在check在整個table的第i列是否只有唯一存在2個
				 for(int l=0;l<3;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				  for(int l=6;l<9;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=3;s<6;s++){
						if(s!=i){
							for(int m=3;m<6;m++){
							if(pos_ans[s][m][k]==true && matrix_in[s][m]==0) {ans_s[s][m]--;}	
							pos_ans[s][m][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for row of box5
		for(int x=0;x<9;x++) digits[x]=0;
		for(j=3;j<6;j++)
		{
			for(int i=3;i<6;i++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box5裡面col j具有兩個相同的candicate
				{                //現在check在整個table的第j行是否只有唯一存在2個
				 for(int l=0;l<3;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				 for(int l=6;l<9;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=3;s<6;s++){
						if(s!=j){
							for(int m=3;m<6;m++){
							if(pos_ans[m][s][k]==true && matrix_in[m][s]==0) {ans_s[m][s]--;}	
							pos_ans[m][s][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for col of box5
		//end of search for box5
		//for box6
	   
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=3;i<6;i++)
		{
			for(j=6;j<9;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box6裡面row i具有兩個相同的candicate
				{                //現在check在整個table的第i列是否只有唯一存在2個
				 for(int l=0;l<6;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=3;s<6;s++){
						if(s!=i){
							for(int m=6;m<9;m++){
							if(pos_ans[s][m][k]==true && matrix_in[s][m]==0) {ans_s[s][m]--;}	
							pos_ans[s][m][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for row of box6
		for(int x=0;x<9;x++) digits[x]=0;
		for(j=6;j<9;j++)
		{
			for(int i=3;i<6;i++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box6裡面col j具有兩個相同的candicate
				{                //現在check在整個table的第j行是否只有唯一存在2個
				 for(int l=0;l<3;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				 for(int l=6;l<9;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=6;s<9;s++){
						if(s!=j){
							for(int m=3;m<6;m++){
							if(pos_ans[m][s][k]==true && matrix_in[m][s]==0) {ans_s[m][s]--;}	
							pos_ans[m][s][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for col of box6
		//end of search for box6
		//for box7
	   
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=6;i<9;i++)
		{
			for(j=0;j<3;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box7裡面row i具有兩個相同的candicate
				{                //現在check在整個table的第i列是否只有唯一存在2個
				 for(int l=3;l<9;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=6;s<9;s++){
						if(s!=i){
							for(int m=0;m<3;m++){
							if(pos_ans[s][m][k]==true && matrix_in[s][m]==0) {ans_s[s][m]--;}	
							pos_ans[s][m][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for row of box7
		for(int x=0;x<9;x++) digits[x]=0;
		for(j=0;j<3;j++)
		{
			for(int i=6;i<9;i++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box7裡面col j具有兩個相同的candicate
				{                //現在check在整個table的第j行是否只有唯一存在2個
				 for(int l=0;l<6;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=0;s<3;s++){
						if(s!=j){
							for(int m=6;m<9;m++){
							if(pos_ans[m][s][k]==true && matrix_in[m][s]==0) {ans_s[m][s]--;}	
							pos_ans[m][s][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for col of box7
		//end of search for box7
		//for box8
	   
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=6;i<9;i++)
		{
			for(j=3;j<6;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box8裡面row i具有兩個相同的candicate
				{                //現在check在整個table的第i列是否只有唯一存在2個
				 for(int l=0;l<3;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				for(int l=6;l<9;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=6;s<9;s++){
						if(s!=i){
							for(int m=3;m<6;m++){
							if(pos_ans[s][m][k]==true && matrix_in[s][m]==0) {ans_s[s][m]--;}	
							pos_ans[s][m][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for row of box8
		for(int x=0;x<9;x++) digits[x]=0;
		for(j=3;j<6;j++)
		{
			for(int i=6;i<9;i++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box8裡面col j具有兩個相同的candicate
				{                //現在check在整個table的第j行是否只有唯一存在2個
				 for(int l=0;l<6;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=3;s<6;s++){
						if(s!=j){
							for(int m=6;m<9;m++){
							if(pos_ans[m][s][k]==true && matrix_in[m][s]==0) {ans_s[m][s]--;}	
							pos_ans[m][s][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for col of box8
		//end of search for box8
		//for box9
	   
		for(int x=0;x<9;x++) digits[x]=0;
		for(int i=6;i<9;i++)
		{
			for(j=6;j<9;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box9裡面row i具有兩個相同的candicate
				{                //現在check在整個table的第i列是否只有唯一存在2個
				 for(int l=0;l<6;l++) {
					 if(pos_ans[i][l][k]==1) digits[k]++;
				 }
				
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=6;s<9;s++){
						if(s!=i){
							for(int m=6;m<9;m++){
							if(pos_ans[s][m][k]==true && matrix_in[s][m]==0) {ans_s[s][m]--;}	
							pos_ans[s][m][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for row of box9
		for(int x=0;x<9;x++) digits[x]=0;
		for(j=6;j<9;j++)
		{
			for(int i=6;i<9;i++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==1) digits[k]++;
				}
			}
			for(int k=0;k<9;k++){
				if(digits[k]==2) //代表在box9裡面col j具有兩個相同的candicate
				{                //現在check在整個table的第j行是否只有唯一存在2個
				 for(int l=0;l<6;l++) {
					 if(pos_ans[l][j][k]==1) digits[k]++;
				 }
				
				 if(digits[k]==2)  	{  //仍為2代表此兩格確實構成pointing pair
					for(int s=6;s<9;s++){
						if(s!=j){
							for(int m=6;m<9;m++){
							if(pos_ans[m][s][k]==true && matrix_in[m][s]==0) {ans_s[m][s]--;}	
							pos_ans[m][s][k]=false;
						}
						}
					} 
				 }
				}
			}
			for(int x=0;x<9;x++) digits[x]=0;
		} //search for col of box9
		//end of search for box9
	}//end of pointing_pait_find
	 void Sudoku::hidden_find(int pos_ans[9][9][9],int ans_s[9][9],int matrix_in[9][9]){
		 //check row
		 int digits[9],key=0;
		 
		 for(int i=0;i<9;i++) digits[i]=0;
		 //use digits to store and find which candicate numbers appear only once
		 for(int i=0;i<9;i++)
		 {
			 
			 for(int j=0;j<9;j++)
			 { if(matrix_in[i][j]==0 ){
						 for(int k=0;k<9;k++) 
							 if(pos_ans[i][j][k]==true){
							digits[k]++;		 } 
					 }		 
				 
			 }
			 for(int m=0;m<9;m++) {
				 if(digits[m]==1) 
				 {
					 key=m;
				 for(int l=0;l<9;l++) {
					 if(pos_ans[i][l][key]==true) {
						 matrix_in[i][l]=key+1;
						 ans_s[i][l]=0;
						 reset_the_table(pos_ans,ans_s,matrix_in,i,l,key+1);
						 break;
					 }
				 }
				 }
			 }
			 for(int x=0;x<9;x++) digits[x]=0;
			 
		 } //end of row hidden_find
		 for(int x=0;x<9;x++) digits[x]=0;
		 //check col
		 for(int j=0;j<9;j++)
		 {
			 for(int i=0;i<9;i++)
			 {
				 if(matrix_in[i][j]==0){
					 for(int k=0;k<9;k++) 
						 if(pos_ans[i][j][k]==true){
							 digits[k]++;
						 }
				 }
			 }
			 for(int m=0;m<9;m++){
				 if(digits[m]==1)
				 {
					 key=m;
					 for(int l=0;l<9;l++){
						 if(pos_ans[l][j][key]==true){
							 matrix_in[l][j]=key+1;
							 ans_s[l][j]=0;
							 reset_the_table(pos_ans,ans_s,matrix_in,l,j,key+1);
							 break;
						 }
					 }
				 }
				 
			 } for(int x=0;x<9;x++) digits[x]=0;//換下一row/col更新digits
		 } //end of col checking
		 //hidden check for block1
		 for(int x=0;x<9;x++) digits[x]=0;
		   for(int i=0;i<3;i++)
		   {
			   for(int j=0;j<3;j++){
				   for(int k=0;k<9;k++) {
					   if(pos_ans[i][j][k]==1) digits[k]++;
				   }
			   } //confirm does it exist the only number hidden in the block1

		   }
		   for(int k=0;k<9;k++)
			   {
				   if(digits[k]==1) {
					   for(int l=0;l<3;l++){
						   for(int h=0;h<3;h++)
						   {
							   if(pos_ans[l][h][k]==1) {
								  //找到只具有唯一的hidden 可能
								  matrix_in[l][h]=k+1;
								  ans_s[l][h]=0;
								  reset_the_table(pos_ans,ans_s,matrix_in,l,h,k+1);
							   }
						   }
					   }
				   }
			   }
			//___________end of hidden check for block1
			//hidden check for block2
		 for(int x=0;x<9;x++) digits[x]=0;
		   for(int i=3;i<6;i++)
		   {
			   for(int j=0;j<3;j++){
				   for(int k=0;k<9;k++) {
					   if(pos_ans[i][j][k]==1) digits[k]++;
				   }
			   } //confirm does it exist the only number hidden in the block2

		   }
		   for(int k=0;k<9;k++)
			   {
				   if(digits[k]==1) {
					   for(int l=3;l<6;l++){
						   for(int h=0;h<3;h++)
						   {
							   if(pos_ans[l][h][k]==1) {
								  //找到只具有唯一的hidden 可能
								  matrix_in[l][h]=k+1;
								  ans_s[l][h]=0;
								  reset_the_table(pos_ans,ans_s,matrix_in,l,h,k+1);
							   }
						   }
					   }
				   }
			   }
			//___________end of hidden check for block2
			//hidden check for block3
		 for(int x=0;x<9;x++) digits[x]=0;
		   for(int i=6;i<9;i++)
		   {
			   for(int j=0;j<3;j++){
				   for(int k=0;k<9;k++) {
					   if(pos_ans[i][j][k]==1) digits[k]++;
				   }
			   } //confirm does it exist the only number hidden in the block3

		   }
		   for(int k=0;k<9;k++)
			   {
				   if(digits[k]==1) {
					   for(int l=6;l<9;l++){
						   for(int h=0;h<3;h++)
						   {
							   if(pos_ans[l][h][k]==1) {
								  //找到只具有唯一的hidden 可能
								  matrix_in[l][h]=k+1;
								  ans_s[l][h]=0;
								  reset_the_table(pos_ans,ans_s,matrix_in,l,h,k+1);
							   }
						   }
					   }
				   }
			   }
			//___________end of hidden check for block3
			//hidden check for block4
		 for(int x=0;x<9;x++) digits[x]=0;
		   for(int i=0;i<3;i++)
		   {
			   for(int j=3;j<6;j++){
				   for(int k=0;k<9;k++) {
					   if(pos_ans[i][j][k]==1) digits[k]++;
				   }
			   } //confirm does it exist the only number hidden in the block4

		   }
		   for(int k=0;k<9;k++)
			   {
				   if(digits[k]==1) {
					   for(int l=0;l<3;l++){
						   for(int h=3;h<6;h++)
						   {
							   if(pos_ans[l][h][k]==1) {
								  //找到只具有唯一的hidden 可能
								  matrix_in[l][h]=k+1;
								  ans_s[l][h]=0;
								  reset_the_table(pos_ans,ans_s,matrix_in,l,h,k+1);
							   }
						   }
					   }
				   }
			   }
			//___________end of hidden check for block4
			//hidden check for block5
		 for(int x=0;x<9;x++) digits[x]=0;
		   for(int i=3;i<6;i++)
		   {
			   for(int j=3;j<6;j++){
				   for(int k=0;k<9;k++) {
					   if(pos_ans[i][j][k]==1) digits[k]++;
				   }
			   } //confirm does it exist the only number hidden in the block5

		   }
		   for(int k=0;k<9;k++)
			   {
				   if(digits[k]==1) {
					   for(int l=3;l<6;l++){
						   for(int h=3;h<6;h++)
						   {
							   if(pos_ans[l][h][k]==1) {
								  //找到只具有唯一的hidden 可能
								  matrix_in[l][h]=k+1;
								  ans_s[l][h]=0;
								  reset_the_table(pos_ans,ans_s,matrix_in,l,h,k+1);
							   }
						   }
					   }
				   }
			   }
			//___________end of hidden check for block5
			//hidden check for block6
		 for(int x=0;x<9;x++) digits[x]=0;
		   for(int i=6;i<9;i++)
		   {
			   for(int j=3;j<6;j++){
				   for(int k=0;k<9;k++) {
					   if(pos_ans[i][j][k]==1) digits[k]++;
				   }
			   } //confirm does it exist the only number hidden in the block6

		   }
		   for(int k=0;k<9;k++)
			   {
				   if(digits[k]==1) {
					   for(int l=6;l<9;l++){
						   for(int h=3;h<6;h++)
						   {
							   if(pos_ans[l][h][k]==1) {
								  //找到只具有唯一的hidden 可能
								  matrix_in[l][h]=k+1;
								  ans_s[l][h]=0;
								  reset_the_table(pos_ans,ans_s,matrix_in,l,h,k+1);
							   }
						   }
					   }
				   }
			   }
			//___________end of hidden check for block6
			//hidden check for block7
		 for(int x=0;x<9;x++) digits[x]=0;
		   for(int i=0;i<3;i++)
		   {
			   for(int j=6;j<9;j++){
				   for(int k=0;k<9;k++) {
					   if(pos_ans[i][j][k]==1) digits[k]++;
				   }
			   } //confirm does it exist the only number hidden in the block7

		   }
		   for(int k=0;k<9;k++)
			   {
				   if(digits[k]==1) {
					   for(int l=0;l<3;l++){
						   for(int h=6;h<9;h++)
						   {
							   if(pos_ans[l][h][k]==1) {
								  //找到只具有唯一的hidden 可能
								  matrix_in[l][h]=k+1;
								  ans_s[l][h]=0;
								  reset_the_table(pos_ans,ans_s,matrix_in,l,h,k+1);
							   }
						   }
					   }
				   }
			   }
			//___________end of hidden check for block7
			//hidden check for block8
		 for(int x=0;x<9;x++) digits[x]=0;
		   for(int i=3;i<6;i++)
		   {
			   for(int j=6;j<9;j++){
				   for(int k=0;k<9;k++) {
					   if(pos_ans[i][j][k]==1) digits[k]++;
				   }
			   } //confirm does it exist the only number hidden in the block8

		   }
		   for(int k=0;k<9;k++)
			   {
				   if(digits[k]==1) {
					   for(int l=3;l<6;l++){
						   for(int h=6;h<9;h++)
						   {
							   if(pos_ans[l][h][k]==1) {
								  //找到只具有唯一的hidden 可能
								  matrix_in[l][h]=k+1;
								  ans_s[l][h]=0;
								  reset_the_table(pos_ans,ans_s,matrix_in,l,h,k+1);
							   }
						   }
					   }
				   }
			   }
			//___________end of hidden check for block8
			//hidden check for block9
		 for(int x=0;x<9;x++) digits[x]=0;
		   for(int i=6;i<9;i++)
		   {
			   for(int j=6;j<9;j++){
				   for(int k=0;k<9;k++) {
					   if(pos_ans[i][j][k]==1) digits[k]++;
				   }
			   } //confirm does it exist the only number hidden in the block9

		   }
		   for(int k=0;k<9;k++)
			   {
				   if(digits[k]==1) {
					   for(int l=6;l<9;l++){
						   for(int h=6;h<9;h++)
						   {
							   if(pos_ans[l][h][k]==1) {
								  //找到只具有唯一的hidden 可能
								  matrix_in[l][h]=k+1;
								  ans_s[l][h]=0;
								  reset_the_table(pos_ans,ans_s,matrix_in,l,h,k+1);
							   }
						   }
					   }
				   }
			   }
			//___________end of hidden check for block9
	 }
	 void Sudoku::reset_the_table(int pos_ans[9][9][9],int ans_s[9][9],int matrix_in[9][9],int m,int n,int solution){
		for(int i=0;i<9;i++) pos_ans[m][n][i]=false;  
		for(int i=0;i<9;i++) pos_ans[m][i][solution-1]=false;
		for(int i=0;i<9;i++) pos_ans[i][n][solution-1]=false;
		 if(m>=0 && m <3 ){
			if(n>=0 && n<3){
				for( int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						pos_ans[i][j][solution-1]=false;
					}
				}
			}
			else if(n>=3 && n<6){
				for( int i=0;i<3;i++){
					for(int j=3;j<6;j++){
						pos_ans[i][j][solution-1]=false;
					}
				}
			}
			else if(n>=6 && n<9){
				for( int i=0;i<3;i++){
					for(int j=6;j<9;j++){
						pos_ans[i][j][solution-1]=false;
					}
				}
			}
		}
		else if(m>=3 && m<6){
			if(n>=0 && n<3){
				for( int i=3;i<6;i++){
					for(int j=0;j<3;j++){
						pos_ans[i][j][solution-1]=false;
					}
				}
			}
			else if(n>=3 && n<6){
				for( int i=3;i<6;i++){
					for(int j=3;j<6;j++){
						pos_ans[i][j][solution-1]=false;
					}
				}
			}
			else if(n>=6 && n<9){
				for( int i=3;i<6;i++){
					for(int j=6;j<9;j++){
						pos_ans[i][j][solution-1]=false;
					}
				}
			}
		}
		else if(m>=6 && m<9){
			if(n>=0 && n<3){
				for( int i=6;i<9;i++){
					for(int j=0;j<3;j++){
						pos_ans[i][j][solution-1]=false;
					}
				}
			}
			else if(n>=3 && n<6){
				for( int i=6;i<9;i++){
					for(int j=3;j<6;j++){
						pos_ans[i][j][solution-1]=false;
					}
				}
			}
			else if(n>=6 && n<9){
				for( int i=6;i<9;i++){
					for(int j=6;j<9;j++){
						pos_ans[i][j][solution-1]=false;
					}
				}
			}
		}
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++) 
			if(matrix_in[i][j]==0)	ans_s[i][j]=0;
		
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				for(int k=0;k<9;k++){
					if(pos_ans[i][j][k]==true && matrix_in[i][j]==0) ans_s[i][j]++;
					if(matrix_in[i][j]!=0) ans_s[i][j]=0;
				}
			}
		}
		//把已經輸入的通通設為０

	 }
	 void Sudoku::naked_pair(int pos_ans[9][9][9],int ans_s[9][9],int matrix_in[9][9]){
		 int naked[2],cadicate=0,naked_num1=0,naked_num2=0,bpt=0;
		 int len=0,judge=0;
		 int possible[9]; for(int x=0;x<9;x++) {possible[x]=0;}
		 for(int x=0;x<2;x++) naked[x]=0;
		for(int i=0;i<9;i++)
		{ 
	      len=0;  naked_num1=-1;naked_num2=-1;bpt=0;//初始化
		  for(int j=0;j<9;j++)
		  {
			   if(ans_s[i][j]==2) 
		         {possible[j]=true;//代表第i列第j行的格子具兩個candicate
			     //先找出該列cadicate為2的
	              cadicate++;
		         }
		  }
		  if(cadicate>=2){
			for(int k=0;k<9;k++) {
				len=0;
				if(possible[k]==1) {  //代表該格只有兩個candicate
				naked_num1=k;
				for(int l=0;l<9;l++)
				{   
					if(pos_ans[i][k][l]==1) naked[len++]=l;//找到只有兩個candicate的格子其可能
					
				}
				} //end of if
				for(int s=k+1;s<9;s++)
				{   naked_num2=-1;len=0;judge=0;
			        if(possible[s]==1)
					{   len=0;
						for(int m=0;m<9;m++) {
							if(pos_ans[i][s][m]==1 && m==naked[len])
							{
								len++;judge++;
							}
							if(judge==2) {judge=0;len=0;naked_num2=s;bpt=1;break;}
							
						}
					}
					if(bpt==1 && naked_num1!=-1 && naked_num2!=-1) break;
				}
				if(bpt==1 && naked_num1!=-1 && naked_num2!=-1) break;//已經找到naked_pair,下一步執行將其他非naked_pair的candicate刪除
			}
		  }
		 if(bpt==1 && naked_num1!=-1 && naked_num2!=-1){ //刪除該列其他的candicate
			 for(int j=0;j<9;j++)
			 {
				  if(j!=naked_num1 && j!=naked_num2)
			  {  for(int l=0;l<9;l++) 
			    { 
			      if(pos_ans[i][j][naked[0]]==1 && matrix_in[i][j]==0) ans_s[i][j]--;
				 if(pos_ans[i][j][naked[1]]==1  && matrix_in[i][j]==0) ans_s[i][j]--;
				  pos_ans[i][j][naked[0]]=false;
				  pos_ans[i][j][naked[1]]=false;
			    }
				   
			  }
			 }
		 }
	     else {naked_num2=-1;naked_num1=-1;bpt=0;}
		  cadicate=0;
		  for(int x=0;x<9;x++) {possible[x]=0;}//該列已做完,to the next row
		}
        //search for col naked_pair
       for(int x=0;x<9;x++) {possible[x]=0;}
		 for(int x=0;x<2;x++) naked[x]=0;
		for(int j=0;j<9;j++)
		{ 
	      len=0;  naked_num1=-1;naked_num2=-1;bpt=0;//初始化
		  for(int i=0;i<9;i++)
		  {
			   if(ans_s[i][j]==2) 
		         {possible[i]=true;//代表第i列第j行的格子具兩個candicate
			     //先找出該列cadicate為2的
	              cadicate++;
		         }
		  }
		  if(cadicate>=2){
			for(int k=0;k<9;k++) {
				len=0;
				if(possible[k]==1) {  //代表該格只有兩個candicate
				naked_num1=k;
				for(int l=0;l<9;l++)
				{   
					if(pos_ans[k][j][l]==1) naked[len++]=l;//找到只有兩個candicate的格子其可能
					
				}
				} //end of if
				for(int s=k+1;s<9;s++)
				{   naked_num2=-1;len=0;judge=0;
			        if(possible[s]==1)
					{   len=0;
						for(int m=0;m<9;m++) {
							if(pos_ans[s][j][m]==1 && m==naked[len])
							{
								len++;judge++;
							}
							if(judge==2) {judge=0;len=0;naked_num2=s;bpt=1;break;}
							
						}
					}
					if(bpt==1 && naked_num1!=-1 && naked_num2!=-1) break;
				}
				if(bpt==1 && naked_num1!=-1 && naked_num2!=-1) break;//已經找到naked_pair,下一步執行將其他非naked_pair的candicate刪除
			}
		  }
		 if(bpt==1 && naked_num1!=-1 && naked_num2!=-1){ //刪除該列其他的candicate
			 for(int i=0;i<9;i++)
			 {
				  if(i!=naked_num1 && i!=naked_num2)
			  {  for(int l=0;l<9;l++) 
			    { 
			      if(pos_ans[i][j][naked[0]]==1 && matrix_in[i][j]==0) ans_s[i][j]--;
				 if(pos_ans[i][j][naked[1]]==1  && matrix_in[i][j]==0) ans_s[i][j]--;
				  pos_ans[i][j][naked[0]]=false;
				  pos_ans[i][j][naked[1]]=false;
			    }
				   
			  }
			 }
		 }
	     else {naked_num2=-1;naked_num1=-1;bpt=0;}
		  cadicate=0;
		  for(int x=0;x<9;x++) {possible[x]=0;}//該行已做完,to the next col
		  //BOX1
		  for(int i=0;i<3;i++){
			  for(int j=0;j<3;j++){
				
			  }
		  }
		}
	 }//endof naked_pair
	

	 int Sudoku::no_solution(int matrix_in[9][9]){
		 int digits[9];
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=0;i<9;i++){
			 for(int j=0;j<9;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
			 for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
			 for(int x=0;x<9;x++) {digits[x]=0;}
		 }
		 for(int j=0;j<9;j++){
			 for(int i=0;i<9;i++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
			 for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
			 for(int x=0;x<9;x++) {digits[x]=0;}
		 }
		 //check block1
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=0;i<3;i++){
			 for(int j=0;j<3;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
		 }
		  for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
		 //check for block2
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=0;i<3;i++){
			 for(int j=3;j<6;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
		 }
		  for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
		   //check for block3
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=0;i<3;i++){
			 for(int j=6;j<9;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
		 }
		  for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
		   //check for block4
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=3;i<6;i++){
			 for(int j=0;j<3;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
		 }
		  for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
		   //check for block5
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=3;i<6;i++){
			 for(int j=3;j<6;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
		 }
		  for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
		   //check for block6
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=3;i<6;i++){
			 for(int j=6;j<9;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
		 }
		  for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
		   //check for block7
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=6;i<9;i++){
			 for(int j=0;j<3;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
		 }
		  for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
		  //check for block8
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=6;i<9;i++){
			 for(int j=6;j<9;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
		 }
		  for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
		  //check for block9
		 for(int x=0;x<9;x++) {digits[x]=0;}
		 for(int i=6;i<9;i++){
			 for(int j=0;j<3;j++)
			 {
			   if(matrix_in[i][j]!=0) digits[matrix_in[i][j]-1]++;
			 }
		 }
		  for(int x=0;x<9;x++) if(digits[x]>=2) return 1;
		  
		  return 0;
	 }
	  int Sudoku::no_solution2(int ans_s[9][9],int matrix_in[9][9]){
		  for(int i=0;i<9;i++){
			  for(int j=0;j<9;j++){
				  if(ans_s[i][j]==0 && matrix_in[i][j]==0) return 1;
			  }
		  }
		  return 0;
	  }
	 
	 
void Sudoku::changeNum(int a,int b){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(matrix_input[i][j]==a) matrix_input[i][j]=b;
		else if(matrix_input[i][j]==b) matrix_input[i][j]=a;
		}
	}
	
}
void Sudoku::readIn(){

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
		{
			scanf("%d",&matrix_input[i][j]);
		}
	}
	
	
}
void Sudoku::giveQuestion(){
	//set sdk matrix
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++)
		{
			matrix_input[i][j]=0;
		}
	}
	matrix_input[0][1]=4;matrix_input[0][2]=7;matrix_input[0][7]=2;
	matrix_input[1][3]=9;
	matrix_input[2][1]=2;matrix_input[2][7]=6;
	matrix_input[3][3]=8;matrix_input[3][7]=4;matrix_input[3][8]=1;
	matrix_input[4][0]=1;matrix_input[4][1]=7;matrix_input[4][3]=3;matrix_input[4][8]=2;
	matrix_input[5][0]=8;matrix_input[5][3]=5;matrix_input[5][5]=2;matrix_input[5][8]=9;
	matrix_input[6][6]=1;matrix_input[6][7]=8;matrix_input[6][8]=6;
	matrix_input[7][5]=9;
	matrix_input[8][0]=5;matrix_input[8][2]=8;matrix_input[8][3]=2;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<matrix_input[i][j]<<" ";
		}
		printf("\n");
	}
}  //end of giveQuestion
void Sudoku::changeRow(int a,int b){
int tmp1[3][9];
	int tmp2[3][9];
	if(a==2 && b==1){a=1;b=2;}
    if(a==2 && b==0){a=0;b=2;}
    if(a==b) return;	
if(a==0){
	if(b==1) { //row0換成row3 row 1>>row 4 row 2>>row5
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				tmp1[i][j]=matrix_input[i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				tmp2[i][j]=matrix_input[3+i][j];
			}
		}
			for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				matrix_input[i][j]=tmp2[i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				matrix_input[3+i][j]=tmp1[i][j];
			}
		}
	}
	else if(b==2){
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				tmp1[i][j]=matrix_input[i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				tmp2[i][j]=matrix_input[6+i][j];
			}
		}
			for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				matrix_input[6+i][j]=tmp1[i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				matrix_input[i][j]=tmp2[i][j];
			}
		}
	}
	else if(b==0);
}
else if(a==1){
	if(b==0){
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				tmp1[i][j]=matrix_input[i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				tmp2[i][j]=matrix_input[3+i][j];
			}
		}
			for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				matrix_input[i][j]=tmp2[i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				matrix_input[3+i][j]=tmp1[i][j];
			}
		}
	}
	else if(b==2){
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				tmp1[i][j]=matrix_input[3+i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				tmp2[i][j]=matrix_input[6+i][j];
			}
		}
			for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				matrix_input[6+i][j]=tmp1[i][j];
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<9;j++){
				matrix_input[3+i][j]=tmp2[i][j];
			}
		}
	}
	else if(b==1);
}

}
void Sudoku::changeCol(int a,int b){
int tmp1[9][3];
	int tmp2[9][3];
	if(a==2 && b==1){a=1;b=2;}
    if(a==2 && b==0){a=0;b=2;}
    if(a==b) return;	
if(a==0){
	if(b==1) { 
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				tmp1[i][j]=matrix_input[i][j];
			}
		}
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				tmp2[i][j]=matrix_input[i][j+3];
			}
		}
			for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				matrix_input[i][j]=tmp2[i][j];
			}
		}
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				matrix_input[i][j+3]=tmp1[i][j];
			}
		}
	}
	else if(b==2){
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				tmp1[i][j]=matrix_input[i][j];
			}
		}
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				tmp2[i][j]=matrix_input[i][j+6];
			}
		}
			for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				matrix_input[i][j]=tmp2[i][j];
			}
		}
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				matrix_input[i][j+6]=tmp1[i][j];
			}
		}
	}
	else if(b==0);
}
else if(a==1){
	if(b==0){
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				tmp1[i][j]=matrix_input[i][j];
			}
		}
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				tmp2[i][j]=matrix_input[i][j+3];
			}
		}
			for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				matrix_input[i][j]=tmp2[i][j];
			}
		}
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				matrix_input[i][j+3]=tmp1[i][j];
			}
		}
	}
	else if(b==2){
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				tmp1[i][j]=matrix_input[i][j+3];
			}
		}
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				tmp2[i][j]=matrix_input[i][j+6];
			}
		}
			for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				matrix_input[i][j+3]=tmp2[i][j];
			}
		}
		for(int j=0;j<3;j++){
			for(int i=0;i<9;i++){
				matrix_input[i][j+6]=tmp1[i][j];
			}
		}
	}
	else if(b==1);
}

}
void Sudoku::rotate(int n){
	int tmp[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			tmp[i][j]=matrix_input[i][j];
	}}
	if(n%4==0) return;
	if(n%4==1) { //轉90度
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			matrix_input[j][8-i]=tmp[i][j];
		}
	}
	}
	if(n%4==2) {
		for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			matrix_input[8-i][8-j]=tmp[i][j];
		}
	}
	
	}
	if(n%4==3){
			for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			matrix_input[8-j][i]=tmp[i][j];
		}
	}
	
	}
}
void Sudoku::flip(int n){
	int tmp[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			tmp[i][j]=matrix_input[i][j];
	}}
	
	if(n==0) {
		for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			matrix_input[i][j]=tmp[8-i][j];
	}}
	}
	else if(n==1){
		for(int j=0;j<9;j++){
		for(int i=0;i<9;i++){
			matrix_input[i][j]=tmp[i][8-j];
	}}
	}
}
void Sudoku::transform(){
	readIn();
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<matrix_input[i][j]<<" ";
		}
		printf("\n");
	}
}

