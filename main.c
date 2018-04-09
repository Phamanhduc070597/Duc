#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_LENGTH 300;
#define TI_LE_DOT_BIEN 0.15;

int data[MAX_LENGTH][45];
float* donXacSuat;
int soKy = 0;

void readDatabase(FILE * file);
float* tinhDonXS();
void swap(int a, int b);
void show(int *mang, int length);

int quanTheChon[100];
void chonLocBoMe(int quanThe[100]);
void laiGhep(int* caTheMe, int* caTheBo, int* caTheCon1, int* caTheCon2);
void dotBien(int* caTheDotBien);
int danhGiaChatLuong(int* caTheDanhGia);

int main()
{

    FILE *file = fopen("ky-1-250.txt", "r");
	readDatabase(file);
	*donXacSuat = tinhDonXS();
    show(*donXacSuat,45);
    return 0;
};

void swap(int a, int b){
   int temp =a;
   a=b;
   b=temp;
    }
}

void readDatabase(FILE * file) {
	char ch;
	while (!feof(file)) {
		for (int i = 0; i < 45; i++)data[soKy][i] = 0;
		for (int i = 1; i <= 4; i++)fscanf(file, "%c", &ch);
		for (int i = 0; i < 6; i++) {
			fscanf(file, "%c", &ch);
			int temp = ch - 48;
			fscanf(file, "%c", &ch);
			data[soKy][temp * 10 + ch - 48 - 1] = 1;
			fscanf(file, "%c", &ch);
		}
		soKy++;
	}
	fclose(file);
}
float* tinhDonXS(){
	float *ketQua=malloc(45*sizeof(float));
	for(int i=0;i<45;i++)ketQua[i]=0;
	for(int i=0;i<soKy;i++){
		for(int j=0;j<45;j++){
			ketQua[j]+=data[i][j];
		}
	}
	for(int i=0;i<45;i++)ketQua[i]/=soKy;
	return ketQua;
}

void show(int* mang, int length){
printf("\nXac suat 45 so:");
printf("\nso ***** xác suất");
for(int i = 1; i<=length; i++){
    printf("\n%d ***** %f ",i,mang[i-1]);
}
printf("---------------------");
}

void chonLocBoMe(int quanThe[100]);

void laiGhep(int* caTheMe, int* caTheBo, int* caTheCon1, int* caTheCon2){
    int diemLai = rank()%5;
    for(int i = 0 ; i <= diemLai ; i++){
        caTheCon1[i]=caTheMe[i];
        caTheCon2[i]=caTheBo[i];
        caTheCon1[5-i]=caTheBo[5-i];
        caTheCon2[5-i]=caTheMe[5-i];
    }
    for(int i=5;i>=0;i--){
            for(int j=1; j<=i;j++){
                if(caTheCon1[j-1]>caTheCon1[j]){
                    swap(caTheCon1[j-1],caTheCon1[j]);
                }
                if(caTheCon1[j-1]>caTheCon1[j]){
                    swap(caTheCon2[j-1],caTheCon2[j]);
                }
        }
    }
}

void dotBien(int* caTheDotBien){
for(int i=0; i<6;i++){
       if(caTheDotBien[i+1]<=caTheDotBien[i]){
        caTheDotBien[i+1]+=1;
    }
 }
}

int danhGiaChatLuong(int* caTheDanhGia){
    int chatLuong = 0;
    for(int i=0; i < 6; i++){
        chatLuong += donXacSuat[caTheDanhGia[i]];    }
}

