#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ID;
    int MSSV;
    char hoTen[100];
    int Group_id;
}thanhvien;

//Ham nhap thong tin thanh vien
void Nhap(thanhvien *tv)
{
    printf("Nhap thong tin thanh vien\n");
    printf("Nhap ho ten thanh vien:\n");
    gets(tv->hoTen);
    fflush(stdin);
    printf("Nhap MSSV:\n");
    scanf("%d",&tv->MSSV);
    //fflush(stdin);
    printf("Nhap ID:\n");
    scanf("%d",&tv->ID);
    //fflush(stdin);
    printf("Nhap Group_id:\n");
    scanf("%d",&tv->Group_id);
    fflush(stdin);
}

//Ham in thong tin thanh vien
void In(thanhvien *tv)
{
    printf("Ten thanh vien %s\n",tv->hoTen);
    printf("ID: %d\n",tv->ID);
    printf("Ma so sinh vien:%d\n",tv->MSSV);
    printf("Group_id:%d\n",tv->Group_id);
}

//Ham tim kiem thong tin thanh vien
int Tim(thanhvien *tv,char hoten[],int size)
{
    int dem=0;
    while(strcmp(tv->hoTen,hoten)!=0)
    {
        tv=(tv+1);
        dem++;
        if(dem>=size)
        	return -1;
    }
    return dem;
}

//Ham xoa thanh vien
void deltv(thanhvien *tv,int dem,int *size)
{
    int i;
    thanhvien *p;
    if(dem==-1)
    	printf("Thanh vien nay khong co trong danh sach.\n");
    else
    {
		tv=tv+dem;
    	while(dem<(*size-1))
   		{
        	p=tv+1;
        	strcpy(tv->hoTen,p->hoTen);
        	tv->ID=p->ID;
        	tv->MSSV=p->MSSV;
        	tv->Group_id=p->Group_id;
        	tv=tv+1;
        	dem++;
    	}
    tv=tv-(*size-1);
    *size=*size-1;
	}
}

//Ham sua thanh vien
void Suatv(thanhvien *tv,int dem,int size)
{
    tv=tv+dem;
    printf("Nhap thong tin thanh vien\n");
    printf("Nhap ho ten thanh vien.\n");
    gets(tv->hoTen);
    printf("Nhap MSSV:\n");
    scanf("%d",&tv->MSSV);
    fflush(stdin);
    printf("Nhap ID:\n");
    scanf("%d",&tv->ID);
    fflush(stdin);
    printf("Nhap Group_id:\n");
    scanf("%d",&tv->Group_id);
    fflush(stdin);
}

//Ham them thanh vien
void Themtv(thanhvien *tv,int *size)
{
    Nhap(&tv[*size]);
    *size=*size+1;
}


int main()
{
    thanhvien tv[200];
    int size;
    int i=1;
    char hoten[100];
    printf("       Chuong trinh quan li thong tin thanh vien\n");
    printf("Doi tinh nguyen Vien cong nghe thong tin & truyen thong\n");
    printf("----------------------------------------------------------\n");
    printf("Cac chuc nang:\n");
    printf("\n1.Nhap thanh vien va thong tin thanh vien.\n");
    printf("\n2.In thong tin thanh vien.\n");
    printf("\n3.Tim va in thong tin thanh vien can tim.\n");
    printf("\n4.Them thanh vien.\n");
    printf("\n5.Sua thong tin thanh vien:\n");
    printf("\n6.Xoa thanh vien.\n");
	printf("\n7.Thoat chuong trinh.\n");
    while(i==1)
    {   printf("Nhap vao cac lua chon:\n");
        switch(getchar())
        {
        case '1':
            {
                printf("Nhap so thanh vien:\n");
                scanf("%d",&size);
                fflush(stdin);
                for(int i=0;i<size;i++)
                {
                    Nhap(&tv[i]);
                }
            };break;
        case '2':
            {
                printf("Thong tin thanh vien doi tinh nguyen Vit:\n");
                for(int j=0;j<size;j++)
                {
                    In(&tv[j]);
                }
            };break;
        case '3':
            {
                printf("Nhap vao ten thanh vien can tim thong tin:\n");
                fflush(stdin);
                gets(hoten);
                if(Tim(tv,hoten,size)==-1)
                	printf("Thanh vien khong co trong danh sach.\n");
                else	
                	In(&tv[Tim(tv,hoten,size)]);
            };break;
        case '4':
            {
                printf("Them thanh vien:\n");
                fflush(stdin);
                Themtv(tv,&size);
            };break;
        case '5':
            {
                printf("Nhap vao ten thanh vien can sua thong tin:\n");
                fflush(stdin);
                gets(hoten);
                if(Tim(tv,hoten,size)==-1)
                	printf("Thanh vien khong co trong danh sach.\n");
                else
                	Suatv(tv,Tim(tv,hoten,size),size);
            };break;
        case '6':
            {
                printf("Nhap vao ten thanh vien can xoa:\n");
                fflush(stdin);
                gets(hoten);
                deltv(tv,Tim(tv,hoten,size),&size);
            };break;
        case '7':
        	{		
				printf("Cam on cac ban da su dung chuong trinh.\n");
				exit(1);
        	}
		default:break;
        };
	}
}

