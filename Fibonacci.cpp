#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct broj{
	int vrijednost;
	int puta;
	
	
};
int fibo(int pozicija,broj* koliko)
{   
	if (pozicija<=2)
	{
		koliko[pozicija-1].puta++;
			return 1;
	}

	if (pozicija>2)
	{	
		koliko[pozicija-1].puta++;
	return fibo(pozicija-1,koliko)+fibo(pozicija-2,koliko);
	}
}

int main()
{
	broj koliko[50];
	long int zbroj=0;
	ofstream pisanje("Brojevi1.txt");
	if (!pisanje)
	{
		cout<< "Greska...\n";
		return 1;
	}
	
	for(int i=0;i<50;i++)
	{
		koliko[i].puta=0;
		koliko[i].vrijednost=0;
	}
	int pozicija=1;
	int najveci;
	do{	
		int n=fibo(pozicija,koliko);
		if (n>400000000) break;
		koliko[pozicija-1].vrijednost=n;
		if (n%2==0)pisanje<<n<<"\n";
		zbroj+=n;
		najveci=n;
		pozicija++;
	}while (true);
	pisanje.close();

	cout << "Zbroj svih generiranih brojeva je "<< zbroj<<endl;
	cout << "Najveci generirani broj je "<< najveci<<endl;
	for(int i=0;i<pozicija-1;i++){
		cout<<"Broj " <<koliko[i].vrijednost<<" se pojavljuje "<<koliko[i].puta<<endl;
	}
	
	return 0;
}