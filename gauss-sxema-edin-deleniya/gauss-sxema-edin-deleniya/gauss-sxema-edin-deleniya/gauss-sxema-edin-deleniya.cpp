// gauss-sxema-edin-deleniya.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double mas[4][4];
	int i, j;

	//input + confirm
	printf("введите коэффицинты: \n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			cin >> mas[i][j];

		}
	}
	//determinanty, obratnaya matrica
	double determinant=0;
	determinant = 
	  mas[0][0] * mas[1][1] * mas[2][2] 
	+ mas[0][1] * mas[1][2] * mas[2][0]
	+ mas[1][0] * mas[2][1] * mas[0][2] 
	- mas[2][0] * mas[1][1] * mas[0][2] 
	- mas[2][1] * mas[1][2] * mas[0][0] 
	- mas[1][0] * mas[0][1] * mas[2][2];
	cout<< "determinant = "<< determinant<< "\n\n";
	//copy
	double ac[3][3];
	for (i=0; i<3; i++)
	 for (j=0; j<3; j++)
		ac[i][j]=mas[i][j];
	//transpose
	int t;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			t = ac[i][j];
			ac[i][j] = ac[j][i];
			ac[j][i] = t;
		}
	}

	cout << "transposed matrix\n\n";
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {

			cout << ac[i][j] << ' ';
		}
		cout << '\n';
	}
	//союзная матрица писдец
	/*00 01 02
	  10 11 12
	  20 21 22
	*/
	float souz[3][3];
	souz[0][0] = pow(-1, 1 + 1) * (ac[1][1] * ac[2][2] - ac[1][2] * ac[2][1]);
	souz[0][1] = pow(-1, 1 + 2) * (ac[1][0] * ac[2][2] - ac[2][0] * ac[1][2]);
	souz[0][2] = pow(-1, 1 + 3) * (ac[1][0] * ac[2][1] - ac[1][1] * ac[2][0]);
	souz[1][0] = pow(-1, 2 + 1) * (ac[0][1] * ac[2][2] - ac[0][2] * ac[2][1]);
	souz[1][1] = pow(-1, 2 + 2) * (ac[0][0] * ac[2][2] - ac[0][2] * ac[2][0]);
	souz[1][2] = pow(-1, 2 + 3) * (ac[0][0] * ac[2][1] - ac[0][1] * ac[2][0]);
	souz[2][0] = pow(-1, 3 + 1) * (ac[0][1] * ac[1][2] - ac[1][1] * ac[0][2]);
	souz[2][1] = pow(-1, 3 + 2) * (ac[0][0] * ac[1][2] - ac[0][2] * ac[1][0]);
	souz[2][2] = pow(-1, 3 + 3) * (ac[1][1] * ac[0][0] - ac[1][0] * ac[0][1]);
	cout << "\nsouz matrix\n\n";
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {

			cout << souz[i][j] << ' ';
		}
		cout << '\n';
	}
	//-------------------------------------------------------------
	// обратная матрица
	cout<<"\nobratnaya matrix\n\n";
 for(i=0; i<3; i++){
	  for (j=0;j<3;j++){
					
			  souz[i][j]/=determinant;
					cout<<souz[i][j]<<' ';
			}
			cout<<'\n';
	}

	//=============================================================
			cout<<"\n\ndata confirmation: \n\n";
			cout<<" / ";
			for (j=0; j<3; j++)
				cout << "+ (" << mas[0][j] << ")*x_" << j+1 << " ";
			cout << "     " << mas[0][j]<< '\n';

		 cout << "{  ";
			for (j = 0; j < 3; j++)
				cout << "+ (" << mas[1][j] << ")*x_" << j + 1 << " ";
			cout << "  =  " << mas[1][j] << '\n';

			cout << ' ' << char(92) << ' ';
			for (j = 0; j < 3; j++)
				cout << "+ (" << mas[2][j] << ")*x_" << j + 1 << " ";
			cout << "     " << mas[2][j] << '\n';

			//input end
		 //перекомпановка матрицы. цель - треугольный вид
			//нулевые к-ты вниз!
			double prom;
			if (mas[0][0] == 0) {
				for (j=0; j<4;j++){
				  prom=mas[2][j];
						mas[2][j]=mas[0][j];
						mas[0][j]=prom;

				}
			}
			else if(mas[1][0] == 0) {
				for (j = 0; j < 4; j++) {
					prom = mas[2][j];
					mas[2][j] = mas[1][j];
					mas[1][j] = prom;

				}
			}
			//перекомпановка всё
			//вычисления
			float koef= 0;
			//делаю mas[2][0] нулевым. для этого делю mas[2][0] на mas[0][0], получая koef. затем mas[2][j]=mas[0][j]*koef-mas[2][j]. т.о. в mas[2][0] будет 0. 
			//примечание. если koef 0, решение будет опускаться
			//счёт 3й строки
			koef= mas[2][0]/mas[0][0];
			if (koef!=0){
				for (j=0;j<4; j++)
				  mas[2][j] = mas[0][j] * koef - mas[2][j];
			}
			//счёт 2й строки
			koef = mas[1][0] / mas[0][0];
			if (koef != 0) {
				for (j = 0; j < 4; j++){
					mas[1][j] = mas[0][j] * koef - mas[1][j];
				}
			}

			//счёт 3й строки, 2й к-т
			koef = mas[2][1] / mas[0][0];
			if (koef != 0) {
				for (j = 1; j < 4; j++)
					mas[2][j] = mas[0][j] * koef - mas[2][j];
			}

		
			mas[1][0]=0;mas[2][0]=0;mas[2][1]=0;

			cout << " \n\n";
			cout << " / ";
			for (j = 0; j < 3; j++)
				cout << "+ (" << mas[0][j] << ")*x_" << j + 1 << " ";
			cout << "     " << mas[0][j] << '\n';

			cout << "{  ";
			for (j = 0; j < 3; j++)
				cout << "+ (" << mas[1][j] << ")*x_" << j + 1 << " ";
			cout << "  =  " << mas[1][j] << '\n';

			cout << ' ' << char(92) << ' ';
			for (j = 0; j < 3; j++)
				cout << "+ (" << mas[2][j] << ")*x_" << j + 1 << " ";
			cout << "     " << mas[2][j] << '\n';
			double x_1=0, x_2= 0, x_3=0;
  //сматрица имеет треугольный вид. считаем к-ты.

		x_3=mas[2][3]/mas[2][2];
		x_2=(mas[1][3]-(mas[1][2]*x_3))/mas[1][1];
		x_1=(mas[0][3]-(mas[0][2]*x_3)-(mas[0][1]*x_2))/mas[0][0];

		cout << "\nx1 = " << round(x_1 * 1000) / 1000;
		cout << "\nx2 = " << round(x_2 * 1000) / 1000;
		cout << "\nx3 = " << round(x_3 * 1000) / 1000;
  //проверка подстановкой
		double checkin;
		checkin= mas[0][0]*x_1+ mas[0][1] * x_2+ mas[0][2] * x_3;
		cout<<"\n\nОНИ РАВНЫ?\n\n" << checkin <<" ? "<< mas[0][3]<< "\ny/n?";
		char answer;

		cin>>answer;
		if (answer == 'n'){
			system("cls");
			cout<<"\n\n\n:'-(";
		} else cout<< "ok, fine then";
		  
	cout<<"\n\n\n\n";
	system("pause");
	return 0;
}

