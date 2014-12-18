#include <iostream>
#include <fstream>

using namespace std;

void sort(int *, int);

int binsearch(int, int *, int, int);

void sort_recursive(int*, int , int );
int main(int argc, char *argv[]){
  int target;
  if(argc < 2){
    cout << "Provide a filename of the data to be searched" << endl;
    return 1;
  }
  ifstream datfile(argv[1], ios::in);
  if( datfile.fail() ){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  int count = 0;
  // Count how many integers are in the file
  while(! datfile.fail()){
    int temp;
    datfile >> temp;
    if(!datfile.fail()){
      count++;
    }
  }
  // When we reach the end of the file, the EOF flag is set
  // To be able to read through the file again we need to clear that flag
  datfile.clear();
  //  We also need to set our internal position in the file back to 0
  datfile.seekg(0,ios::beg);

  // Now allocate an array to store the file data and read in the data
  int *data = new int[count];
  for(int i=0; i < count; i++){
    datfile >> data[i];
  }

  datfile.close();

  cout << "Read " << count << " integers from the data file.\n" << endl;
  cout << "Enter the target positive integer to search for: ";
  cin >> target;
//copying data in order to find index of target in unsorted data as well as sorted data
/*int copy_data[count];
for (int i=0;i<count;i++){
	copy_data[i]=data[i];}
*/
  // Uncomment the line below for part 2
//   sort(data, count);
sort_recursive(data,count, 0);
  // Call binary search
  int retval = binsearch(target,data,0,count);

		
		
	


  // Interpret and print the results
  if(retval == -1){
    cout << target << " does not appear in the data." << endl;
  }




else {
/*
int i=0;
    for (i=0;i<count;i++){
	if (copy_data[i]==target){
		break;}

       */
cout << target << " appears at index " << retval << " in the sorted data" <<endl;
}
// and index " << i << " in the unsorted data." << endl;

  // Deallocate the data array
  delete [] data;
  return 0;
}


// Returns the index in the data array where target is located
//  or -1 if the target value is not in the list
int binsearch(int target, int *data, int start, int end){
int middle=((start+end)/2);

if (start+1==end){
	if (target==data[start]){
	return start;}
	else{
	return -1;}
}

if (target<data[middle]){
	return binsearch(target,data,start,middle);
}

else {
	return binsearch(target,data,middle,end);
}


}//close function
 
// implements a selection sort algorithm to sort
//  the integer values in the 'data' array of size 'len'
void sort(int *data, int len)
{	
for (int i=0;i<len;i++){
	for (int j=i+1;j<len;j++){
	
	if (data[i]>data[j]){
		int temp=data[i];
		data[i]=data[j];
		data[j]=temp;
	}
	
	}
}
}


void sort_recursive(int*data, int len, int start)
{   int min = start;
    if ( start >= len-1 )
        return;

    for ( int i = start + 1; i<len; i++ )
    {
        if (data[i] < data[min] )
            min = i;
    }
    int temp = data[start];
    data[start] = data[min];
    data[min] = temp;
    sort_recursive(data, len, start + 1);
}
