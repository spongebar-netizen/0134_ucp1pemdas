// 1.Bilangan Bulat (Integer)=tipe data numerik yang biasa digunakan apabila bertemu dengan bilangan bulat
//   Bilangan pecahan atau floating point=bilangan yang menangani bilangan desimal atau perhitungan secara detail.
//   Karakter (Char)=Tipe data karakter tunggal yang biasa didefinisikan dengan tanda petik(‘) di awal dan di akhir karakternya
// 
// 2.Program Judul_Program;
//Begin
//........
//........
//End;
//Begin
//.........
//.........
//End.
//
// 3.for (let i = 1; i <= 10; i++) {    console.log(i);}
// 4.if (condition) {
  // body of if statement
//}
// 5.char name[] = "Fatan";
//char address[] = "Sakra";
//int age = 22;

#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true)
	{
		cout << "Masukkan  element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}
	cout << "\n------------------" << endl;
	cout << "nNama Kota" << endl;
	cout << "--------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

void swap(int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
	mov_count++;


}
void q_short(int low, int high)
{
	int temp;
	int pivot, i, j;
	if (low > high) {
		return;
	}

	pivot = arr[low];
	i = low + 1;
	j = high;

	while (i <= j)
	{
		while ((arr[i] <= pivot) && (i <= high))
			j--;
		cmp_count++;
	}
	cmp_count++;
	while ((arr[i] > pivot) && (j >= low))
	{
		j--;
		cmp_count++;
	}
	cmp_count++;
	if (i < j)
	{
		swap(i, j);
	}
	if (low < j) {
		swap(low, j);
	}

	q_short(low, j - 1);
	q_short(j + 1, high);


}
void display() {
	cout << "\-----------" << endl;
	cout << "Status" << endl;
	cout << "------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\nSehat: " << cmp_count << endl;
	cout << "Tidak Sehat: " << mov_count << endl;

}
int main()
{
	char ch;


	do {
		input();
		q_short(0, n - 1);
		display();
		cout << "\nDo you want to continue? (y/n): ";
		cin >> ch;
		if (ch == 'n' || ch == 'N')
			break;

		system("pause");
		system("cls");


	} while (true);


	return 0;


}