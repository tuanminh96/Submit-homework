#include <stdio.h>
#include <string.h>
#include <conio.h>
typedef struct TTTV
{
	char hoTen[50];
	int ID;
	int tuoi;
	int nhom;     
}TTTV;
void nhapTT(TTTV *tv)
{
	printf("Nhap vao ten thanh vien :");
	scanf("%s",&tv->hoTen);
	fflush(stdin);
	printf ("\nNhap vao ID:");
	scanf("%d",&tv->ID);
	printf ("\nNhap vao tuoi:");
	scanf("%d",&tv->tuoi);
	printf("\nThanh vien nhom:");
	scanf("%d",&tv->nhom);
	
}
int main()
{
	int luaChon,sl,i;
	TTTV tv[1000];
	printf("\nNhap vao so luong thanh vien:");
	scanf("%d",&sl);
	for (i=1;i<=sl;i++)
	{
		nhapTT(&tv[i]);
	}
	printf("\n***********MENU******************"
	"\n1.Them thanh vien\n2.Tim kiem thanh vien\3.Sua thong tin thanh vien\n4.Xoa thanh vien\n0.Thoat chuong trinh");
	scanf("%d", &luaChon);
	switch (luaChon) {
		case 0: break;
		case 1: {
	        sl++;
        	nhapTT(&tv[sl]);
			break;
		}
		case 2:{
	       int i,id;
           printf ("Nhap vao id thanh vien can tim:");
	       scanf("%d",&id);
	       for ( i=1;id==tv->ID;i++)
	       {
		        printf("Thanh vien do la:",tv[i]);
	       }
           printf("Thanh vien khong ton tai");   
		   break;
		}
		case 3:{
			int id,i;
			printf("Nhap vao id thanh vien can sua:");
        	scanf("%d",&id);
        	for ( i=1;id==tv->ID;i++)
	       {
		        printf("Thanh vien do la:",tv[i]);
	            nhapTT(&tv[i]);
	       }
			break;
		}
		case 4:{
			int id,i,j,sl;
	        printf("Nhap vao id thanh vien ban muon xoa:");
	        scanf("%d",&id);
	        for ( i=1;id==tv->ID;i++)
	       {
		        printf("Thanh vien do la:",tv[i]);
		        j=i;
	       }
        	for (; j<=sl;j++)
        	{
            	tv[j]=tv[j++];
            }
			break;
		}

	}
	
	return 0;	//Sua tam ty
}
