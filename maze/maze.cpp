#include <iostream>
#include "maze_io.h"
using namespace std;

// Prototype for maze_search
int maze_search(char **, int, int);

int main(int argc, char *argv[])
{
  int rows, cols, result;

  if(argc < 3){
    cerr << "Usage: ./maze in_filename out_filename" << endl;
    return 1;
  }

  char** mymaze = read_maze(argv[1], &rows, &cols);
  result = maze_search(mymaze, rows, cols);

  if( result == 1 ){
    cout << "Path successfully found!" << endl;
    print_maze(mymaze,rows,cols);
    write_maze(argv[2],mymaze,rows,cols);
  }
  else if (result == 0) {
    cout << "No path could be found!" << endl;
  }
  else {
    cout << "Error occurred during search!" << endl;
  }

  delete [] mymaze;

  return 0;
}

int maze_search(char **maze, int rows, int cols)
{ 

int* bfsq_i=new int[rows*cols];
int* bfsq_j=new int[rows*cols];
int* predecessor=new int[rows*cols];
//predecessor=0;
int i,j;
bool tempmaze[rows][cols]; 
int head=0, tail=0;
bool found_start=false;
bool found_finish=false;
bool finish_exists=false, start_exists=false;
for (i=0;i<rows;i++){
	for (j=0;j<cols;j++){
		if (maze[i][j]=='F'){
		finish_exists=true;
		;	}//if maze=s
}

}




for (i=0;i<rows;i++){
	for (j=0;j<cols;j++){
      

	
	if (maze[i][j]=='S'){
		found_start=true;
		start_exists=true;
		break;	}//if maze=s

        

	
	}//for j
if (found_start==true)
	{break;
	}}
if (start_exists==false || finish_exists==false)
	{return -1;}
bfsq_i[head]=i;
bfsq_j[head]=j;
tail++;

    
    int current_i=0;
	int current_j=0;
   // cout << "headi,j" << i <<  " "  <<j ;
while (found_finish==false && head!=tail) {

    
	 current_i=bfsq_i[head];
	 current_j=bfsq_j[head];
//cout << current_i << " " << current_j << " " << endl;
  //cout << bfsq_i[head] << " " << bfsq_j[head]<< endl;

	tempmaze[bfsq_i[head]] [bfsq_j[head]]= true;  
 
if (maze[current_i][current_j]=='.'){
	//maze[current_i][current_j]='*';
}//if maze
else if(maze[current_i][current_j]=='F'){
	found_finish=true;
	break;
}//else if
else if(maze[current_i][current_j]=='#'){
	head++;

	continue;}//else if


	
if (current_j>0 && !tempmaze[current_i][current_j-1]){//west
	bfsq_i[tail]=current_i;
	bfsq_j[tail]=current_j-1;
	predecessor[tail]=head;
	//cout << predecessor[tail] << " " << maze[current_i][current_j-1] << endl;
	tail++;

}//if north
if (current_i<(rows-1) && !tempmaze[current_i + 1][current_j] ){//south
	bfsq_i[tail]=current_i+1;
	bfsq_j[tail]=current_j;
	predecessor[tail]=head;
	//cout << predecessor[tail] << " " << maze[current_i + 1][current_j]<< endl;

	tail++;

}//if east
if (current_j<(cols-1) && !tempmaze[current_i][current_j+1]) {//east
	bfsq_i[tail]=current_i;
	bfsq_j[tail]=current_j+1;
	predecessor[tail]=head;
	//cout << predecessor[tail] << " " << maze[current_i][current_j+1] << endl;
	tail++;

}//if south
if(current_i>0 && !tempmaze[current_i - 1][current_j]){//north
	bfsq_i[tail]=current_i-1;
	bfsq_j[tail]=current_j;
	predecessor[tail]=head;
	//cout << predecessor[tail] << " " << maze[current_i - 1][current_j]<< endl;
	tail++;


}//if west

        head++;


//cout << " " << current_i << " " << current_j << endl;

	//    cout << predecessor[tail] << endl;




}//while loop
//bool reached_start=false;
int previous_cell=0;
previous_cell=predecessor[head];
int maze_i=0;
int maze_j=0;

while (found_finish){



maze_i=bfsq_i[previous_cell];
//cout << "maze_i:" << maze_i << endl;
maze_j=bfsq_j[previous_cell];
//cout << "maze_j:" << maze_j << endl;
previous_cell=predecessor[previous_cell];
if (maze[maze_i][maze_j]=='S')
	{break;}
else if (maze[maze_i][maze_j]=='.'){
maze[maze_i][maze_j]='*';}
}//while


delete []bfsq_i;
delete []bfsq_j;
delete[]predecessor;


  // Change appropriately after Checkpoint 1 is working
if(found_finish){
	return 1;}
else {return 0;}
}//close function