#include <iostream>
using namespace std;

template <class T>
void NhapMang(T **a, int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			cout << "\nNhap vao a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}

	// Cách 2.
	/*for(int i = 0; i < dong * cot; i++)
	{
		printf("\nNhap vao a[%d][%d] = ", i / cot, i % cot);
		scanf("%d", &a[i / cot][i % cot]);
	}*/
}

template <class T>
void XuatMang(T **a, int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
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

template <class T>
void HoanVi(T &a, T &b)
{
	T Temp = a;
	a = b;
	b = Temp;
}

template <class T>
// Hoán vị dòng d1 & dòng d2.
void HoanVi2Dong(T **a, int cot, int d1, int d2)
{
	for(int i = 0; i < cot; i++)
	{
		HoanVi<T>(a[d1][i], a[d2][i]);
	}
}

template <class T>
// k là chỉ số của dòng cần xóa.
void XoaDong(T **&a, int &dong, int cot, int k)
{
	for(int i = k; i < dong - 1; i++)
	{
		HoanVi2Dong<T>(a, cot, i, i + 1);
	}

	realloc(a[dong - 1], 0); // Xóa hết dòng cuối.

	dong--; // Cập nhật lại số dòng sau khi xóa.
}

template <class T>
// Hoán vị cột c1 & c2.
void HoanVi2Cot(T **a, int dong, int c1, int c2)
{
	for(int i = 0; i < dong; i++)
	{
		HoanVi<T>(a[i][c1], a[i][c2]);
	}
}

template <class T>
// k là vị trí cột cần xóa.
void XoaCot(T **&a, int dong, int &cot, int k)
{
	for(int i = k; i < cot - 1; i++)
	{
		HoanVi2Cot<T>(a, dong, i, i + 1);
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
	float **a;
	int dong = 3, cot = 3;

	/* ================ cấp phát ==================== */

	a = new float*[dong];
	for(int i = 0; i < dong; i++)
	{
		a[i] = new float[cot];
	}

	/* =================== xử lý =================== */

	NhapMang<float>(a, dong, cot);
	XuatMang<float>(a, dong, cot);

	/*int k = 1; 
	printf("\nMa tran sau khi xoa dong %d la\n", k);
	XoaDong(a, dong, cot, k);
	XuatMang(a, dong, cot);*/

	int k = 0;
	printf("\nMa tran sau khi xoa cot %d la\n", k);
	XoaCot<float>(a, dong, cot, k);
	XuatMang<float>(a, dong, cot);


	/* ============= giải phóng ============= */

	for(int i = 0; i < dong; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	system("pause");
	return 0;
}