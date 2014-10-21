#include"filtre.h"
#include<iostream>

using namespace std;

void main(){

	filtre filtre;

	char x='0';
	char site[60];

	while(x!='c'){
		cout<<"Site engellemek icin e'ye\n"
			"Engelli siteye izin vermek icin i'ye\n"
			"Programdan cikmak icin c'ye basiniz.\n"<<endl;
		cin>>x;

		if(x=='e'){
			cout<<"Engellemek istediginiz siteyi giriniz...:";
			cin>>site;
			filtre.engelle(site);
		}

		if(x=='i'){
			cout<<"Engelini kaldirmak istediginiz siteyi giriniz...:";
			cin>>site;
			filtre.izinver(site);
		}

	}


	system("exit");
}
