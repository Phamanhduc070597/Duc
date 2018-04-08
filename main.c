#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_LENGTH 45;
#define DIEM_LAI 3;
#define TI_LE_DOT_BIEN 0.15;

int data[MAX_LENGTH][45];
float donXacSuat[MAX_LENGTH];
int soKy =0;
struct caThe{
float ChatLuong;
int Gen[6];
};
typedef struct caThe caThe;
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
float* tinhXSDon(){
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

/*
void show(int *mang, int length){
printf("\nXac suat 45 so:");
printf("\nso ***** xác suất");
for(int i = 1; i<=length; i++){
    printf("\n%d ***** %f ",i,mang[i-1]);
}
printf("---------------------");
};
*/
void chonLocBoMe(caThe quanThe[MAX_LENGTH]){
};
void laiGhep(caThe caTheMe, caThe caTheBo);
void dotBien(caThe caTheDotBien){

};
int chatLuong(caThe caTheDanhGia){
    caTheDanhGia.ChatLuong = 0;
    for(int i=0; i < 6; i++){
        caTheDanhGia.ChatLuong += donXacSuat[caTheDanhGia.Gen[i]];
    }
};

int main()
{
    printf("Hello world!\n");
    scanf("%f",&donXacSuat[0]);
    show(donXacSuat,MAX_LENGTH)
    return 0;
};
