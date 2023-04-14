#include<stdio.h>
#include<time.h>	//Su dung thu vien time de hien thi thoi gian thuc thi
#include"WaterColorSort_BFS.cpp"
int main(){
	node *DSBN = ReadListOfBottlesFromFile("DS_BinhNuoc2.txt");
	print(DSBN);
	//Luu thoi diem bat dau
	clock_t startTime = clock();
	//Kiem tra neu danh sach binh nuoc hop le thi thuc hien giai thuat
	if(CheckTheListOfBottlesIsValid(DSBN)){
			printf(COLOR_RESET "\nDanh sach cua cac binh nuoc dau vao la hop le.");
			printf(COLOR_RESET "\n\t.... Dang Tai ....");
			point *diem;
			diem = BFS(DSBN);
			//Ket qua
			th(diem);
	}else{
		printf(COLOR_RESET "\nDanh sach cua cac binh nuoc khong hop le.");
	}
	//Luu thoi diem ket thuc
	clock_t endTime = clock();
	//Tinh toan thoi gian thuc thi
	double time = (double)(endTime - startTime)/ CLOCKS_PER_SEC;	//CLOCKS_PER_SEC la 1 hang so co gia tri la 1000
	printf("\n\n------------> Thoi gian thuc thi la: %.3f giay.",time);
}
