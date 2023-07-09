#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct SinhVien
{
	char MaSo[10];
	char HoTen[30];
	float Diem;
};
typedef struct SinhVien SINHVIEN;

void NhapThongTinSinhVien(SINHVIEN &sv)
{
	fflush(stdin);
	printf("\nNhap vao ma so: ");
	gets(sv.MaSo);

	fflush(stdin);
	printf("\nNhap vao ho ten: ");
	gets(sv.HoTen);

	printf("\nNhap vao diem: ");
	scanf("%f", &sv.Diem);
}

void NhapDanhSachLop(SINHVIEN *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap thong tin sinh vien thu %d\n", i + 1);
		NhapThongTinSinhVien(arr[i]);
	}
}

void GhiFile(FILE *&FileOut, SINHVIEN *arr, int n)
{
	FileOut = fopen("DanhSachLop.DOC", "wb");

	if(FileOut != NULL)
	{
		fwrite(arr, sizeof(SINHVIEN), n, FileOut);
	}

	fclose(FileOut);
}

int main()
{
	int n = 3;
	SINHVIEN *arr = (SINHVIEN *)malloc(n * sizeof(SINHVIEN));

	NhapDanhSachLop(arr, n);
	FILE *FileOut;
	GhiFile(FileOut, arr, n);

	free(arr);

	getch();
	return 0;
}





