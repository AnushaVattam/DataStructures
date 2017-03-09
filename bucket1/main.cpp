# include<iostream>
# include<fstream>
#include<string>
#include "Stack_3358.h"
using namespace std;
struct pixel{
    int x;
    int y;

};
void bucketfill(char pic[][25],pixel p,char newcolor){
    //push.pixel(x, y);//
char old_color = pic[p.x][p.y];
Stack_3358<pixel> s1;
s1.push(p);
while(!s1.isEmpty()){
   p = s1.pop()
   pic[p.x][p.y] = newcolor;

   if(pic[p.x+1][p.y] == old_color && p.x>=0 && p.y>=0)
   {
   s1.push(p);
   //s1.pop(p);
   pic[p.x+1][p.y]=newcolor;

   s1.pop(p);
   pic[p.x][p.y]=oldcolor;
   }
    if(pic[p.x][p.y+1]== old_color && p.x>=0 && p.y>=0){}
}

if (old_color == color)
{
    pixel(x,y,colo)
}
}
int main ()
{

ifstream inputFile;
inputFile.open("bucketfill.txt");
char a[25][25]; //creates a  2d array.
pixel p1;
char color;

for(int i=0; i<7; i++)
{
for(int j=0; j<17; j++)
{
inputFile>>a[i][j];
//cout<< a[i][j]<<" ";

}

}
//cout << a[i][j] << " ";b
for(int i=0; i<7; i++) //This loops on the rows.
{

for(int j=0; j<17; j++) //This loops on the columns
{
cout << a[i][j] << " ";
}
cout << endl;
}
cout<< "enter a row :"<< endl;
cin>> p1.x;
cout<< "enter a column:"<< endl;
cin>> p1.y;
cout<< "enter a color:"<<endl;
cin>> color;
bucketfill(a,p1,color);

return 0;
//system("pause");
}


