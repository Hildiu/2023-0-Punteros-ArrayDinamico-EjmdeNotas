/*-------------------------------------------------------
 * Dato de entrada:  nAlumnos (unsigned int), nAlumnos>15
 * Dato de Salida:  notas por encima del promedio
 *                  la mayor nota
 ---------------------------------------------------------*/
#include <iostream>
using namespace std;

void imprimirArreglo(double  *pArreglo, unsigned int n);
double hallaPromedio(double *pA, unsigned int n);
double hallaMayor(double *pNotas, unsigned int n);


int main()
{
  unsigned int nAlumnos=0;

  srand(time(nullptr));
  do{
    cout << "Numero de alumnos : ";
    cin >> nAlumnos;
  }while(nAlumnos<=15);

  //--- dimensinando el arreglo dinamico
  double *pANotas = new double[nAlumnos];

  //---- generamos los valores al azar
  for(int i=0; i<nAlumnos; i++)
    pANotas[i] = rand() % 21;
  imprimirArreglo(pANotas,nAlumnos);
  double promedio = hallaPromedio(pANotas,nAlumnos);
  //--- se imprimen las notas que estan por encima del promedio
  cout << "El promedio es : "  << promedio << "\n";
  cout << "Notas por encima del promedio \n";
  for(int i=0; i<nAlumnos; i++)
    if(pANotas[i]>promedio)
      cout << "pANotas["<< i << "]=" << pANotas[i] << "\n";

  cout << "\n\nLa mayor nota es: " << hallaMayor(pANotas, nAlumnos);
  //--- liberamos memoria
  delete []pANotas;
  pANotas=nullptr;
  return 0;
}


double hallaMayor(double *pNotas, unsigned int n)
{
  double mayor = pNotas[0];
  for(int i =1; i<n; i++)
    if(pNotas[i]> mayor)
      mayor=pNotas[i];
  return mayor;
}

double hallaPromedio(double *pA, unsigned int n)
{
  double suma=0;
  for(int i=0; i<n; i++)
    suma += pA[i];
  return (suma/n);
}



void imprimirArreglo(double  *pArreglo, unsigned int n)
{
  cout << "\n";
  for(int i=0; i<n; i++)
    cout << "pANotas[" << i << "]= " << pArreglo[i] << "\n";
}