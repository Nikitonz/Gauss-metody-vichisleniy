#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <windows.h>
#include <iostream>




int main(){
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);


	double mas[3][4];

	int i, j, deletedrows[2],deletedcolumns[2];


	

	//input + confirm
	printf("введите коэффицинты: \n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			cin >> mas[i][j];

		}
	}
	//--------------------------------------------------
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

			//--------------------------------------------------

			double max = 0;
	
			for (i=0; i<3; i++)
				for (j=0; j<3; j++)
				  if (max<mas[i][j]){
						  max=mas[i][j];
								deletedrows[0] = i;
								deletedcolumns[0] = j;
						}
		
		double koef[3];
		for (i=0; i<3; i++)
		  koef[i] = 0;

		for (i=0; i<3; i++) {
		  if (i!=deletedrows[0]) {
					 koef[i] = -1 * (mas[i][deletedcolumns[0]] / mas[deletedrows[0]][deletedcolumns[0]]);
				  for (j = 0; j < 4; j++) {
				    
								double mas_i_j_copy = mas[i][j];
						  mas[i][j]= mas[deletedrows[0]][j]*koef[i]+mas_i_j_copy;
				  }
				}
		}



		//2rows3col
		//max sredi 2*3
		max=0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (max < mas[i][j] && i!= deletedrows[0] && j!=deletedcolumns[0]) {
					max = mas[i][j];
					deletedrows[1] = i;
					deletedcolumns[1] = j;
				}
		

		for (i = 0; i < 3; i++) {
			if (i != deletedrows[0] && i != deletedrows[1]) {
				for (j = 0; j < 4; j++) {
					if (j!=deletedcolumns[0]){
					  koef[i] = -1 * (mas[i][deletedcolumns[1]] / mas[deletedrows[1]][deletedcolumns[1]]);
					  double mas_i_j_copy = mas[i][j];
					  mas[i][j] = mas[deletedrows[1]][j] * koef[i] + mas_i_j_copy;
					}
				}
			}
		}

		//==================================
		printf("\n\n");
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				printf("%.5f  ", mas[i][j]);
			}
			printf("\n");
		}
		//==================================

		double x[3];
		int ii,jj, iii, jjj;
		for (i=0; i<3;i++){
				for (j=0; j<3; j++){
						if (i!= deletedrows[0] && i != deletedrows[1] && j != deletedcolumns[0] && j != deletedcolumns[1]){
						  x[j]=mas[i][3]/mas[i][j];
								printf(" %.4f / %.4f \n", mas[i][3], mas[i][j]);
								printf("%d -> %.4f \n",j, x[j]);
								ii = i;
								jj = j;
								
						}
				}

		}

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (i != deletedrows[0] && j != deletedcolumns[0] && i!=ii && j!=jj) {
					x[j] = (mas[i][3]- mas[i][jj] * x[jj]) / mas[i][j];
					printf(" (%.4f - %.4f * x[%d])/ %.4f \n", mas[i][3], mas[i][jj],jj, mas[i][j]);
					printf("%d -> %.4f \n", j, x[j]);
					iii=i;
					jjj=j;
					
				}
			}

		}

		

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (i == deletedrows[0] && j!=jj &&j!=jjj) {
					x[j] = (mas[i][3]-mas[i][jjj]*x[jjj]-mas[i][jj]*x[jj]) / mas[deletedrows[0]][deletedcolumns[0]];
					printf(" (%.4f - %.4f * x[%d] - %.4f * x[%d])/ %.4f \n", mas[i][3], mas[i][jjj], jjj, mas[i][jj], jj, mas[i][j]);
					printf("%d -> %.4f \n", j, x[j]);
					
				}
			}

		}

		for (i=0; i<3; i++)
		  printf("x[%d] = %.5f\n", i+1, x[i]);

		double check =  (mas[0][0]*x[0])+(mas[0][1]*x[1])+(mas[0][2]*x[2]);
		printf("equals?\n %.3f ? %.3f", check, mas[0][3]);
		system("PAUSE");
		return 0;
}

