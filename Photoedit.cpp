// Program: Photoedit.cpp
// Purpose: program that can put a filter on a greyscale image
// Author:  John Ayman Naim Aziz
// Id:20210107
// Date:    4 April 2022
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include<vector>
#include<algorithm>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
void negativeimage ();
void rotateimage ();

int main()
{
    int filter;
  loadImage();
cout<<"Please choose the filter you want to apply on the image: \n (1)-Invert colors \n (2)-Rotate image \n";
cin>>filter;
switch(filter){
case 1:
    negativeimage();
    break;
case 2:
    rotateimage();
    break;
}
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the name of the image after edit: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
void negativeimage() {//This function inverts the color of greyscale images
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image[i][j] = 255-image[i][j];

    }
  }
}

void rotateimage(){//This function rotate the imagee by 90 degree clockwise direction
    for (int i=0;i<SIZE/2;i++) {
    for (int j=i;j<SIZE-i-1;j++)
    {
            int arr=image[i][j];
            image[i][j]=image[255-j][i];
            image[255-j][i]=image[255-i][255-j];
            image[255-i][255-j]=image[j][255-i];
            image[j][255-i]=arr;
    }
  }

}
