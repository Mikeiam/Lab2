ub/*4. Определить класс «Квадратная матрица» – Matrix.
Класс должен содержать несколько конструкторов, в том числе конструктор копирования.
Реализовать методы для сложения, вычитания, умножения матриц; вычисления нормы матрицы.
Перегрузить операции сложения, вычитания, умножения и присваивания для данного класса.
Создать массив объектов класса Matrix и передать его в функцию, которая изменяет  i-ю матрицу путем возведения ее в квадрат.
В головной программе вывести результат.*/

#include <iostream>
#include <conio.h>
#include <math.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

class matrix{
int k;
int** matr;
public:
matrix();
matrix(int);
matrix(const matrix &A);
matrix&operator=(const matrix &A);
matrix operator+(matrix &A);
matrix operator-(matrix &A);
matrix operator*(matrix &A);
~matrix();
void show();
matrix sum(matrix &);
matrix razn(matrix &);
matrix mult(matrix &);
void norma();
matrix power_two();
};


matrix::matrix(){
k=0;
matr=0;
}

matrix::matrix(int n){
 k=n;
 srand(time(NULL));
 matr=new int*[k];
 for(int i=0;i<k;i++)
  matr[i]=new int[k];
 for(int i=0;i<k;i++)
  for(int j=0;j<k;j++)
   matr[i][j]=rand()%20;
}

matrix::matrix(const matrix &A){
 srand(time(NULL));
 k=A.k;
 matr=new int*[k];
 for(int i=0;i<k;i++)
  matr[i]=new int[k];
 for(int i=0;i<k;i++)
  for(int j=0;j<k;j++)
   matr[i][j]=A.matr[i][j];
}

matrix&matrix::operator=(const matrix &A){
 if(this!=&A){
  for(int i=0;i<k;i++)
   delete[]matr[i];
  delete[]matr;
  k=A.k;
  matr=new int*[k];
  for(int i=0;i<k;i++)
   matr[i]=new int[k];
  for(int i=0;i<k;i++)
   for(int j=0;j<k;j++)
    matr[i][j]=A.matr[i][j];
 }
 return*this;
}

matrix::~matrix(){
 for(int i=0;i<k;i++)
  delete[]matr[i];
 delete[]matr;
 matr=0;
 k=0;
}

void matrix::show(){
 for(int i=0;i<k;i++){
  for(int j=0;j<k;j++){
   cout.width(3);
   cout<<matr[i][j]<<" ";
  }
  cout<<endl;
 }
}

matrix matrix::sum(matrix &A){
 matrix m1(k);
 for(int i=0;i<k;i++)
  for(int j=0;j<k;j++)
   m1.matr[i][j]=matr[i][j]+A.matr[i][j];
 return m1;
}

matrix matrix::razn(matrix &A){
 matrix m1(k);
 for(int i=0;i<k;i++)
  for(int j=0;j<k;j++)
   m1.matr[i][j]=matr[i][j]-A.matr[i][j];
 return m1;
}

matrix matrix::mult(matrix &A){
 matrix m1(k);
 for(int i=0;i<k;i++){
  for(int j=0;j<k;j++){
   m1.matr[i][j]=0;
   for(int l=0;l<k;l++)
    m1.matr[i][j]+=matr[i][l]*(A.matr[l][j]);
  }
  cout<<endl;
 }
 return m1;
}

void matrix::norma(){
int n1=0,n2=0;
double n3;
 for(int i=0;i<k;i++){
  for(int j=0;j<k;j++)
    n1=n1+matr[i][j];
  if(n1>n2)
   n2=n1;
  n1=0;
 }
 cout<<"Norma po strokam - "<<n2<<endl<<endl;
 n2=0;
 for(int i=0;i<k;i++){
  for(int j=0;j<k;j++)
   n1=n1+matr[j][i];
  if(n1>n2)
   n2=n1;
  n1=0;
}
cout<<"Norma po stolbcam - "<<n2<<endl<<endl;
 for(int i=0;i<k;i++)
  for(int j=0;j<k;j++)
   n1=n1+matr[i][j]*matr[i][j];
 n3=sqrt(n1);
 cout<<"Evklidova Norma - "<<n3<<endl;
}

matrix matrix::operator+(matrix &A){
 matrix m2(k);
 for(int i=0;i<k;i++)
  for(int j=0;j<k;j++)
   m2.matr[i][j]=matr[i][j]+A.matr[i][j];
 return m2;
}

matrix matrix::operator-(matrix &A){
matrix m2(k);
 for(int i=0;i<k;i++)
  for(int j=0;j<k;j++)
   m2.matr[i][j]=matr[i][j]-A.matr[i][j];
 return m2;
}

matrix matrix::operator*(matrix &A){
matrix m2(k);
 for(int i=0;i<k;i++){
  for(int j=0;j<k;j++){
   m2.matr[i][j]=0;
   for(int l=0;l<k;l++)
    m2.matr[i][j]+=matr[i][l]*(A.matr[l][j]);
  }
  cout<<endl;
 }
 return m2;
}

matrix matrix::power_two(){
 matrix m1(k);
 for(int i=0;i<k;i++)
  for(int j=0;j<k;j++)
   m1.matr[i][j]=matr[i][j];
 matrix m2(k);
 m2=m1*m1;
 return m2;
}




int main(){
 int n,kol,i1,i2,z;
 cout<<"Vvedite kolichestvo matric: ";cin>>kol;
 cout<<endl;
 cout<<"Vvedite razmer matric:"; cin>>n;
 cout<<endl;
 matrix *list[n];
 for(int i=0;i<kol;i++)
  list[i]=new matrix(n);
 system("cls");
 while(1){
  cout<<"Select an action: "<<endl;
  cout<<"__________________"<<endl;
  cout<<"1.Pokazat' matrici: "<<endl;
  cout<<"2.Slozenie matric: "<<endl;
  cout<<"3.Raznost' matric: "<<endl;
  cout<<"4.Umnozenie matric: "<<endl;
  cout<<"5.Nahozdenie norm matrici: "<<endl;
  cout<<"6.Vozvedenie matrici v kvadrat: "<<endl;
  cout<<"7.Exit:"<<endl;
  cin>>z;
  switch(z){
       case 1:
       system("cls");
       for(int i=0;i<kol;i++){
        cout<<"Matrix "<<i+1<<":"<<endl;
        list[i]->show();
        cout<<endl;
       }
       break;
       case 2:{
        cout<<"Vvedite nomer 1i matrici: ";cin>>i1;
        cout<<"Vvedite nomer 2i matrici: ";cin>>i2;
        matrix sum1(n);
        sum1=list[i1-1]->sum(*list[i2-1]);
        sum1.show();
        cout<<endl;
        break;
       }
       case 3:{
        cout<<"Vvedite nomer 1i matrici: ";cin>>i1;
        cout<<"Vvedite nomer 2i matrici: ";cin>>i2;
        matrix razn1(n);
        razn1=list[i1-1]->razn(*list[i2-1]);
        razn1.show();
        cout<<endl;
        break;
       }
       case 4:{
         cout<<"Vvedite nomer 1i matrici: ";cin>>i1;
         cout<<"Vvedite nomer 2i matrici: ";cin>>i2;
         matrix mult1(n);
         mult1=list[i1-1]->mult(*list[i2-1]);
         mult1.show();
         cout<<endl;
        break;
       }
       case 5:{
        cout<<"Vvedite nomer matrici: ";cin>>i1;
        list[i1-1]->norma();
        cout<<endl;
        break;
       }
       case 6:{
        cout<<"Vvedite nomer matrici: ";cin>>i1;
        matrix power(n);
        power=list[i1-1]->power_two();
        power.show();
        cout<<endl;
        break;
       }
      }
 }
 delete [] list;
}
