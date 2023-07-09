#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int **a, int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("\nNhap vao a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	// Cách 2.
	/*for(int i = 0; i < dong * cot; i++)
	{
		printf("\nNhap vao a[%d][%d] = ", i / cot, i % cot);
		scanf("%d", &a[i / cot][i % cot]);
	}*/
}

void XuatMang(int **a, int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}

	// Cách 2.
	/*for(int i = 0; i < dong * cot; i++)
	{
		if((i + 1) % cot == 0)
		{
			printf("\n");
		}
		printf("%4d", a[i][j]);
	}*/
}

void HoanVi(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

// Hoán vị dòng d1 & dòng d2.
void HoanVi2Dong(int **a, int cot, int d1, int d2)
{
	for(int i = 0; i < cot; i++)
	{
		HoanVi(a[d1][i], a[d2][i]);
	}
}

// k là chỉ số của dòng cần xóa.
void XoaDong(int **&a, int &dong, int cot, int k)
{
	for(int i = k; i < dong - 1; i++)
	{
		HoanVi2Dong(a, cot, i, i + 1);
	}

	realloc(a[dong - 1], 0); // Xóa hết dòng cuối.

	dong--; // Cập nhật lại số dòng sau khi xóa.
}

// Hoán vị cột c1 & c2.
void HoanVi2Cot(int **a, int dong, int c1, int c2)
{
	for(int i = 0; i < dong; i++)
	{
		HoanVi(a[i][c1], a[i][c2]);
	}
}

// k là vị trí cột cần xóa.
void XoaCot(int **&a, int dong, int &cot, int k)
{
	for(int i = k; i < cot - 1; i++)
	{
		HoanVi2Cot(a, dong, i, i + 1);
	}

	// Xóa cột cuối cùng trên ô nhớ.
	for(int i = 0; i < dong; i++)
	{
		realloc(a[i], (cot - 1) * sizeof(int *));
	}

	cot--;
}

int main()
{
	int **a, dong = 3, cot = 3;

	/* ================ cấp phát ==================== */

	a = (int **)malloc(dong * sizeof(int *));
	for(int i = 0; i < dong; i++)
	{
		a[i] = (int *)malloc(cot * sizeof(int *));
	}

	/* =================== xử lý =================== */

	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);

	/*int k = 1; 
	printf("\nMa tran sau khi xoa dong %d la\n", k);
	XoaDong(a, dong, cot, k);
	XuatMang(a, dong, cot);*/

	int k = 0;
	printf("\nMa tran sau khi xoa cot %d la\n", k);
	XoaCot(a, dong, cot, k);
	XuatMang(a, dong, cot);


	/* ============= giải phóng ============= */

	for(int i = 0; i < dong; i++)
	{
		free(a[i]);
	}
	free(a);

	getch();
	return 0;
}