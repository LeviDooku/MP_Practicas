
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


void test1(){
     cout << "acceso fuera de rango" << endl;

    int *v1 = new int[5];
    cout << v1[8] << endl;
}


void test2(){
 cout << "Falta liberar memoria" << endl;

    int *v1 = new int[5];
    for(int i = 0; i < 5; i++)
        v1[i] = i;
    
    for(int i = 0; i < 5; i++)
        cout << v1[i] << ", ";
    
    cout << endl; 
}


void test3(){
 cout << "delete incorrecto" << endl;

    int *v1 = new int[5];
    for(int i = 0; i < 5; i++)
        v1[i] = i;
    
    for(int i = 0; i < 5; i++)
        cout << v1[i] << ", ";
    
    cout << endl; 
    delete v1;
}

void test4(){
  cout << "Sin memoria " << endl;
  int v[1000000000];
  v[4] = 9;
	
}

void test5(){
  cout << "valores sin asignar " << endl;
  int a = 6, b;
  
  if (a == b)
	  cout << " mal ";
  else
	  cout << " bien ";
  
  
}

int main(int argc, char *argv[])
{ 
   int opcion = atoi(argv[1]);
   switch (opcion){
	   case 1:{test1();break;}
	   case 2:{test2();break;}
	   case 3:{test3();break;}
	   case 4:{test4();break;}
	   case 5:{test5();break;}
	}

return 0;
}






