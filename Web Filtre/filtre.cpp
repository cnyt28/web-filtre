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
	fopen_s(&dosya,"C:/Windows/System32/Drivers/etc/hosts","a");			//hosts dosyasýnýn sonuna
	fprintf(dosya,"127.0.0.1 %s\n",engellenecek);							//"127.0.0.1 www.xxx.com" ekler
	fclose(dosya);
	cout<<"SITE ENGELLENDI.\n"<<endl;


}

void filtre::izinver(char * engellenecek)
{
	filtre::geciciyeyaz(engellenecek);
	filtre::hostsayaz();
	filtre::gecicidosyayýsil();
	cout<<"SITEYE IZIN VERILDI.\n"<<endl;
}

void filtre::geciciyeyaz(char *engellenecek)
{
	FILE *hosts,*gecici;
	fopen_s(&hosts,"C:/Windows/System32/Drivers/etc/hosts","r");
	fopen_s(&gecici,"gecici","w");
	char satir[100],c;
	int x=0,y=0;


	while(!feof(hosts)){			//"\n" karakterini görene kadar(1 satýr) karakterleri okur
		c=getc(hosts);
		satir[x]=c;
		x++;
		
		if(c=='\n'){
			for(int z=0;;z++){
				if(satir[z+10]!=engellenecek[z]){
					while(satir[y]!='\n'){						//satýrý gecici dosyasýna yazar
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

	//Buraya kadar olan kýsýmda hosts dosyasýndan verileri okuduk,
	//engellenecek satýrý aradan çýkarýp gecici dosyasýna yazdýk.
}

void filtre::hostsayaz(void)
{
	FILE *hosts,*gecici;
	fopen_s(&hosts,"C:/Windows/System32/Drivers/etc/hosts","w");
	fopen_s(&gecici,"gecici","r");
	char satir[100],c;
	int x=0,y=0;

	while(!feof(gecici)){			//"\n" karakterini görene kadar(1 satýr) karakterleri okur
		c=getc(gecici);
		satir[x]=c;
		x++;
		
		if(c=='\n'){
			while(satir[y]!='\n'){						//satýrý hosts dosyasýna yazar
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

void filtre::gecicidosyayýsil(void)
{
	remove("gecici");
}