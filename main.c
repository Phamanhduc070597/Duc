#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_LENGTH 300
#define TI_LE_DOT_BIEN 0.15


int data[MAX_LENGTH][45];
int caThe[MAX_LENGTH][6];
float chatLuongCaThe[MAX_LENGTH][2];
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
float danhGiaChatLuong(int* caTheDanhGia);


int main(){
     int i,j;
    printf("so ky: %d",soKy);
    FILE *file = fopen("ky-1-250.txt", "r");
    readDatabase(file);
    for(i =0;i < MAX_LENGTH; i++){
            printf("\nky %d co kq: ",i);
        for ( j = 0;j<45;j++){
            printf("%d ",data[i][j]);
        }
    }
    donXacSuat = tinhDonXS();
    for(i =0;i<46;i++){
        printf("\n %d don xac suat: %f",i,donXacSuat[i]);
    }
    int a[6] = {5,6,7,8,9,43};
    int b[6] = {2,3,4,5,6,20};
    float giatri=danhGiaChatLuong(a);
    printf("\ngia tri cua ca the a: %f",giatri);

    // bang ca the
    for(i = 0;i< soKy;i++){
        int k =0;
        for(j = 0;j<45;j++){
            if (data[i][j]==1){
                caThe[i][k]= j+1;
                k++;
            }
        }
    }
    for(i = 0;i<soKy;i++){
	printf("\nky %d :",i);
	for(j=0;j<6;j++){
		printf("%d ",caThe[i][j]);
		}
	}
	// bang chat Luong ca the
	/*danhGiaQuanThe(chatLuongCaThe);
	for(i = 0;i<soKy;i++){
		printf("\nky %3.0f co do tot:%f",chatLuongCaThe[i][0],chatLuongCaThe[i][1]);
	}*/

    /*
	// test lai
	int con[2][6];

 	laiGhep(a,b,con[0],con[1]);
 	printf("\ncon 1:");
 	for(i=0;i<6;i++){
 		printf("%d ",con[0][i]);
	 }
	 printf("\ncon 2:");
 	for(i=0;i<6;i++){
 		printf("%d ",con[1][i]);
	 }
	// test dot bien
	int c[6]={1,1,2,2,3,3};
	dotBien(c);

	printf("\ncon c:");
	for(i=0;i<6;i++){
 		printf("%d ",c[i]);
	 }*/
	// main
	//tao lap quan the
	// vong lap
	for(i=0;i<10;i++){
     // danh gia
      danhGiaQuanThe(chatLuongCaThe);
	 // lai ghep
       for(j=0;j<50;j++){
            int k = (int)chatLuongCaThe[j][0];
            int h = (int)chatLuongCaThe[249-j][0];
            laiGhep( caThe[k],caThe[h],caThe[h],caThe[h-1]);
       }
	 // dot bien
        for(j=249;j>149;j++){
        dotBien(caThe[j]);
	 }
	 // in ket qua
        int toiUu = (int)chatLuongCaThe[0][0];
        for(j=0;j<6;j++){
        printf("\nKet qua tot nhat: %d",caThe[toiUu][j]);
	}
	}
    return 0;
}

void swap(int a, int b)
{
    int temp =a;    a=b;
    b=temp;
}


void readDatabase(FILE * file)
{
    char ch;int i;
    while (!feof(file))
    {
        for ( i = 0; i < 45; i++)
            data[soKy][i] = 0;
        for ( i = 1; i <= 4; i++)
            fscanf(file, "%c", &ch);
        for ( i = 0; i < 6; i++)
        {
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
float* tinhDonXS()
{
    int i,j;
    float *ketQua=malloc(46*sizeof(float));
    for( i=0; i<46; i++){
        ketQua[i]=0;}
    for( i=0; i<soKy; i++)
    {
        for( j=0; j<45; j++)
        {
            ketQua[j+1]+=data[i][j];//printf("\n so %d co sx %f ",i,ketQua[i]);
        }
    }
    for( i=0; i<45; i++)
       {
           ketQua[i+1]/=soKy;
       }
    return ketQua;
}

void show(int* mang, int length)
{
    int i;
    printf("\nXac suat 45 so:");
    printf("\nso ***** xac suat");
    for( i = 1; i<=length; i++)
    {
        printf("\n%d ***** %f ",i,mang[i-1]);
    }
    printf("---------------------");
}

void danhGiaQuanThe(float chatLuong[MAX_LENGTH][2]){
    int i,j;
    for(i=0; i< soKy;i++ ){
    chatLuong[i][0] = (float)i;
    chatLuong[i][1] = danhGiaChatLuong(caThe[i]);
    }
    for(i =soKy-1;i>=0;i--){
        for(j=1;j<=i;j++){
            if(chatLuong[j-1][1]<chatLuong[j][1]){
            float temp1 = chatLuong[j-1][0];
            chatLuong[j-1][0]=chatLuong[j][0];
            chatLuong[j][0]= temp1;
            float temp2=chatLuong[j-1][1];
            chatLuong[j-1][1]=chatLuong[j][1];
            chatLuong[j][1]= temp2;
            }
        }
    }
};

void laiGhep(int* caTheMe, int* caTheBo, int* caTheCon1, int* caTheCon2)
{
    int i,j;
    int diemLai = rand()%5;
    for( i = 0 ; i <= diemLai ; i++)
    {
        caTheCon1[i]=caTheMe[i];
        caTheCon2[i]=caTheBo[i];
    }
    for(i = 5 ; i > diemLai;i--)
	{
        caTheCon1[i]=caTheBo[i];
        caTheCon2[i]=caTheMe[i];
    }
    for( i=5; i>=0; i--)
    {
        for( j=1; j<=i; j++)
        {
            if(caTheCon1[j-1]>caTheCon1[j])
            {
                swap(caTheCon1[j-1],caTheCon1[j]);
            }
            if(caTheCon2[j-1]>caTheCon2[j])
            {
                swap(caTheCon2[j-1],caTheCon2[j]);
            }
        }
    }
}

void dotBien(int* caTheDotBien)
{
    int i;
    for( i=1; i<=6; i++)
    {
        if(caTheDotBien[i]<=caTheDotBien[i-1])
        {
            caTheDotBien[i]+=1;
            i=i-1;
        }
    }
};

float danhGiaChatLuong(int* caTheDanhGia)
{   int i ;
    float chatLuong = 0;
    for(i = 0; i < 6; i++)
    {   int k = 0;
        k = caTheDanhGia[i];
        chatLuong += donXacSuat[k];
    }
    return chatLuong;
};

