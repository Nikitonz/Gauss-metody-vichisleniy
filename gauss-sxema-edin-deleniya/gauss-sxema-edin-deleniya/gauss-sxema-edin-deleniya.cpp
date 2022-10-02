// gauss-sxema-edin-deleniya.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

double** obrbyGauss(double(*mas)[3], int index) {
	double table[3][4];
	int i, j;
	for (i = 0; i < 3; i++)
		 for (j = 0; j < 3; j++)
			 table[i][j] = mas[i][j];
	for (i = 0; i < 3; i++)
		table[i][3] = 0;

	table[index][3] = 1;
//2
	 double d = table[1][0]/table[0][0];

	 for (j = 0; j < 4; j++)
		 table[1][j] -= d * table[0][j];
	//3-0 
	 d = table[2][0] / table[0][0];

	 for (j = 0; j < 4; j++)
		 table[2][j] -= d * table[0][j];
		//3-1
	 d = table[2][1] / table[1][1];
	 for (j=1;j<4;j++)
	 table[2][j] -= d * table[1][j];
	 
		
		 double x1, x2, x3;
		 x1 = table[2][3] / table[2][2];
		 x2 = (table[1][3] - table[1][2] * x1) / table[1][1];
		 x3 = (table[0][3] - table[0][2] * x1 - table[0][1] * x2) / table[0][0];
		 double** row = new double*[3];
		 for (i = 0; i < 3; i++)
			 row[i] = new double[1];
		 row[2][0] = x1;
		 row[1][0] = x2;
		 row[0][0] = x3;
 	return row;
}

void freeMasRew(double** table) {
	if (table) {
		for (int i = 0; i < 3; i++) {
			 if (table[i]) { 
				  delete[] table[i]; 
			 } 
		}
		delete[] table;
	}
}

	

int main() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		double mas[3][4], prom;
		int i, j;

		//===================IN===========================================<<<<<<<<<<<<<<
		printf("введите коэффицинты: \n");
		for (i = 0; i < 3; i++) {
				for (j = 0; j < 4; j++) {
						cin >> mas[i][j];

				}
		}

		//===================IN_end=======================================<<<<<<<<<<<<<<

		//===================OUT==========================================<<<<<<<<<<<<<<
		cout << "\n\ndata confirmation: \n\n";
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
		//===================OUT_end======================================<<<<<<<<<<<<<
					//input end
				 //перекомпановка матрицы. цель - треугольный вид
					//нулевые к-ты вниз!

		//==================DETERMINANT, REV_MATRIX=======================<<<<<<<<<<<<<
		double determinant = 0;
		double masc[3][3];

		for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
						masc[i][j] = mas[i][j];



		determinant = mas[0][0] * mas[1][1] * mas[2][2];
		cout << "determinant = " << determinant << "\n\n";


		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		double mas_obr[3][3];
		for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
						mas_obr[i][j] = 0;

		double** promt = new double* [3];
		for (i = 0; i < 3; i++)
				promt[i] = new double[1];
		for (int index = 0; index < 3; index++) {
				promt = obrbyGauss(masc, index);
				for (int index1 = 0; index1 < 3; index1++) {

						mas_obr[index1][index] = promt[index1][0];
				}
		}
		int k;
		double C[3][3];
		//check edi
		for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
						C[i][j] = 0;
						for (k = 0; k < 3; k++)
								C[i][j] += mas[i][k] * mas_obr[k][j];
				}
		}
			//check on edi out




		cout << "\nresult of multiply matrix * rev_matrix\n\n";
			for (i = 0; i < 3; i++) {
					for (j = 0; j < 3; j++) {
							if (C[i][j] < 0.000'000'1) {
									C[i][j] = 0;
							}
									
							printf("%.2f ", C[i][j]);
					}
					printf("\n");
			}
		 //end check edi
//==================END===========================================<<<<<<<<<<<<<
			
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
			double koef= 0;
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
			//mas[1][0]=0;mas[2][0]=0;mas[2][1]=0;


			/*
			 1.32 -0.58  3.17
				0.42 -0.45 -2.16
				0.71  1.27  1.76
				*/

		



			//==========================
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
	freeMasRew(promt);

	system("pause");
	return 0;
}

