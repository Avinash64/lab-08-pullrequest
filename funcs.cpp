#include <iostream>
#include "imagehelpers.h"

int invert2(int val){
    int min = 0;
    int max = 255;
    if(val==max){
        return min;
    }
    if(val==min){
        return max;
    }
    int flip = val-((max-min)/2);
    return val - 2*flip; 
}

void invert(int array[MAX_H][MAX_W],int h, int w){
    int arr2[MAX_H][MAX_W];
      for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      arr2[row][col] = invert2(array[row][col]);
    }
       writeImage("taskA.pgm",arr2, h, w);
}}
void inverthalf(int array[MAX_H][MAX_W],int h, int w){
    int arr2[MAX_H][MAX_W];
      for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      if (col> w/2){
          arr2[row][col] = invert2(array[row][col]);
    }
        else{
            arr2[row][col] = array[row][col];
        }
        }
       writeImage("taskB.pgm",arr2, h, w);
}}
void box(int array[MAX_H][MAX_W],int h, int w){
    int arr2[MAX_H][MAX_W];
      for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      if (col> w/4 and col <3*w/4 and row > h/4 and row <3*h/4){
          arr2[row][col] = 255;//invert2(array[row][col]);
    }
        else{
            arr2[row][col] = array[row][col];
        }
        }
       writeImage("taskC.pgm",arr2, h, w);
}}

void frame(int array[MAX_H][MAX_W],int h, int w){
    int arr2[MAX_H][MAX_W];
      for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      if ((col== w/4 or col == 3*w/4 or row == h/4 or row == 3*h/4)and (col>= w/4 and col <=3*w/4 and row >= h/4 and row <=3*h/4)){
          arr2[row][col] = 255;//invert2(array[row][col]);
    }
        else{
            arr2[row][col] = array[row][col];
        }
        }
       writeImage("taskD.pgm",arr2, h, w);
}}

void big(int array[MAX_H][MAX_W],int h, int w){
    int arr2[MAX_H][MAX_W];
      for(int row = 0; row < 2*h; row++) {
    for(int col = 0; col < 2*w; col++) {
      
            arr2[row][col] = array[row/2][col/2];
        }
        }
       writeImage("taskE.pgm",arr2, 2*h, 2*w);
}

void pix(int array[MAX_H][MAX_W],int h, int w){
    int arr2[MAX_H][MAX_W];
    int arr3[MAX_H][MAX_W];
    int avg=0;
      for(int row = 0; row < h; row+=2) {
    for(int col = 0; col < w; col+=2) {
      avg = (array[row][col] + array[row][col+1] + array[row+1][col] + array[row+1][col+1])/4;
            arr2[row][col] = avg;
            arr2[row+1][col] = avg;
            arr2[row][col+1] = avg;
            arr2[row+1][col+1] = avg;
    }}
       writeImage("taskF.pgm",arr2, h, w);
}