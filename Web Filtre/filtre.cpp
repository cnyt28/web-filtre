#include "filtre.h"
#include<iostream>

using namespace std;

filtre::filtre(void)
{
}


filtre::~filtre(void)
{
}

void filtre::engelle(char* engellenecek)
{
	FILE *dosya;
	fopen_s(&dosya,"C:/Windows/System32/Drivers/etc/hosts","a");			//hosts dosyas�n�n sonuna
	fprintf(dosya,"127.0.0.1 %s\n",engellenecek);							//"127.0.0.1 www.xxx.com" ekler
	fclose(dosya);
	cout<<"SITE ENGELLENDI.\n"<<endl;


}

void filtre::izinver(char * engellenecek)
{
	filtre::geciciyeyaz(engellenecek);
	filtre::hostsayaz();
	filtre::gecicidosyay�sil();
	cout<<"SITEYE IZIN VERILDI.\n"<<endl;
}

void filtre::geciciyeyaz(char *engellenecek)
{
	FILE *hosts,*gecici;
	fopen_s(&hosts,"C:/Windows/System32/Drivers/etc/hosts","r");
	fopen_s(&gecici,"gecici","w");
	char satir[100],c;
	int x=0,y=0;


	while(!feof(hosts)){			//"\n" karakterini g�rene kadar(1 sat�r) karakterleri okur
		c=getc(hosts);
		satir[x]=c;
		x++;
		
		if(c=='\n'){
			for(int z=0;;z++){
				if(satir[z+10]!=engellenecek[z]){
					while(satir[y]!='\n'){						//sat�r� gecici dosyas�na yazar
						putc(satir[y],gecici);
						y++;
					}
					putc('\n',gecici);
					x=0;
					y=0;
					break;
				}
				else if(satir[z=='\n'] || satir[z+10]==NULL || engellenecek[z]==NULL){
					x=0;
					y=0;
					break;
				}
			}		
		}
	}

	fclose(gecici);
	fclose(hosts);

	//Buraya kadar olan k�s�mda hosts dosyas�ndan verileri okuduk,
	//engellenecek sat�r� aradan ��kar�p gecici dosyas�na yazd�k.
}

void filtre::hostsayaz(void)
{
	FILE *hosts,*gecici;
	fopen_s(&hosts,"C:/Windows/System32/Drivers/etc/hosts","w");
	fopen_s(&gecici,"gecici","r");
	char satir[100],c;
	int x=0,y=0;

	while(!feof(gecici)){			//"\n" karakterini g�rene kadar(1 sat�r) karakterleri okur
		c=getc(gecici);
		satir[x]=c;
		x++;
		
		if(c=='\n'){
			while(satir[y]!='\n'){						//sat�r� hosts dosyas�na yazar
				putc(satir[y],hosts);
				y++;
			}
			putc('\n',hosts);
			x=0;
			y=0;
		}
	}

	fclose(gecici);
	fclose(hosts);

}

void filtre::gecicidosyay�sil(void)
{
	remove("gecici");
}