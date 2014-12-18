#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "bmplib.h"
#include <iomanip>
using namespace std;

void method1(unsigned char inImage[][SIZE][RGB],bool mask[][SIZE], double threshold){

double red_sum=0,blue_sum=0, green_sum=0,red_average=0, blue_average=0, green_average=0, counter=0;;

for (int i=0;i<255;i++){

red_sum+=inImage[i][0][0];

green_sum+=inImage[i][0][1];
blue_sum+=inImage[i][0][2];
counter++;

}
for (int i=0;i<255;i++){
red_sum+=inImage[i][255][0];
green_sum+=inImage[i][255][1];
blue_sum+=inImage[i][255][2];
counter++;
 }
for (int j=0;j<255;j++){
red_sum+=inImage[0][j][0];
green_sum+=inImage[0][j][1];
blue_sum+=inImage[0][j][2];
counter++;
}
for (int j=0;j<255;j++){
red_sum+=inImage[255][j][0];
 green_sum+=inImage[255][j][1];
blue_sum+=inImage[255][j][2];
counter++;
}

red_average=red_sum/counter;
green_average=green_sum/counter;
blue_average=blue_sum/counter;


for (int i=0;i<255;i++){
	for (int j=0;j<255;j++){
		if (sqrt(pow((inImage[i][j][0]-red_average),2)+pow((inImage[i][j][1]-green_average),2)+pow((inImage[i][j][2]-blue_average),2))<threshold)
		{mask[i][j]=0;
}

		
		else {
		mask[i][j]=1;}
	 

	}
}		
	cout << (int)inputImage[0][0][0] << endl;
	
}

void method2(unsigned char inImage[][SIZE][RGB], 
	     bool mask[][SIZE]){
//find average of red,blue,green of all pixels in picture
double total_green, total_red, total_blue=0, totalavg_green, totalavg_red, totalavg_blue,counter_total;
for (int i=0;i<255;i++){
	for (int j=0;j<255;j++){
	total_red+=inImage[i][j][0];
	total_green+=inImage[i][j][1];
	total_blue+=inImage[i][j][2];
	counter_total++;
	}
}

totalavg_green=total_green/counter_total;
totalavg_red=total_red/counter_total;
totalavg_blue=total_blue/counter_total;

//find standard deviation 
double red_variance=0, green_variance=0, blue_variance=0, stdev_red=0, stdev_green=0,stdev_blue=0;
//variance
for (int i=0;i<255;i++){
	for (int j=0;j<255;j++){
	red_variance+=(pow((inImage[i][j][0]-totalavg_red),2))/(255*255-1);
	green_variance+=(pow((inImage[i][j][1]-totalavg_green),2))/(255*255-1);
	blue_variance+=(pow((inImage[i][j][2]-totalavg_blue),2))/(255*255-1);
	}
}
//standard deviation
stdev_red=sqrt(red_variance);
stdev_green=sqrt(green_variance);
stdev_blue=sqrt(blue_variance);
//define threshold as the average of the standard deviations
int threshold=(stdev_red+stdev_green+stdev_blue)/3;

//call method1, sending the threshold as two standard deviations from the mean  instead of the user input threshold

method1(inImage, mask, threshold*2);

}

void replace(bool mask[][SIZE],
	     unsigned char inImage[][SIZE][RGB],
	     unsigned char bgImage[][SIZE][RGB],
	     unsigned char outImage[][SIZE][RGB]){
for (int i=0;i<255;i++){
	for (int j=0;j<255;j++){
	for (int k=0;k<=2;k++){
		if (mask[i][j]==0){
		outImage[i][j][k]=bgImage[i][j][k];}
		else if(mask[i][j]==1){
		outImage[i][j][k]=inImage[i][j][k];}
}
}
}}
	


int main(int argc, char *argv[])
{
  // Image data array
  // Note:  DON'T use the static keyword except where we expressly say so.
  //        It puts the large array in a separate, fixed, area of memory. 
  //        It is bad practice. But useful until we have dynamic allocation.
  static unsigned char inputImage[SIZE][SIZE][RGB];
  static unsigned char bgrndImage[SIZE][SIZE][RGB];
  static unsigned char outputImage[SIZE][SIZE][RGB];
  static bool chromaMask[SIZE][SIZE];

  double threshold;

  if (argc < 6) {
    cerr << "usage: program_name in.bmp background.bmp dist_threshold " 
         << "out1.bmp out2.bmp" << endl;
    return 0;
  }
	
  if (readRGBBMP(argv[1], inputImage)) {
    cerr << "Error reading file: " << argv[1] << endl;
    return 1;
  }

  if (readRGBBMP(argv[2], bgrndImage)) {
    cout << "Error reading file: " << argv[2] << endl;
    return 1;
  }
  
  // Write code to convert the threshold (argv[3])
  //  from string format to a double and assign the 'threshold'

threshold=atof(argv[3]);

  // Call Method 1 Function
 method1(inputImage,chromaMask, threshold);

  // Produce the output by calling replace()
replace(chromaMask, inputImage, bgrndImage, outputImage);


  if (writeRGBBMP(argv[4], outputImage)) {
    cout << "Error writing file: " << argv[4] << endl;
    exit(1);
  }	

  // Call Method 2 Function
 method2(inputImage,chromaMask);

  // Produce the output by calling replace()
replace(chromaMask, inputImage, bgrndImage, outputImage);

  // Write the output image to a file using the filename argv[5]
  if (writeRGBBMP(argv[5], outputImage)) {
    cout << "Error writing file: " << argv[5] << endl;
    exit(1);
  }	

  return 0;
}
