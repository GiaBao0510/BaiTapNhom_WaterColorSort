#include<stdio.h>
#include"ColorWaterSort_BFS.cpp"
int main(){
	node *DSBN = ReadListOfBottlesFromFile("DS_BinhNuoc2.txt");
	print(DSBN);
	//Kiem tra neu danh sach binh nuoc hop le thi thuc hien giai thuat
//	if(CheckTheListOfBottlesIsValid(DSBN)){
//		
//	}else{
//		printf("\nDanh sach cua cac binh nuoc khong hop le.");
//	}
	point *diem;
	diem = BFS(DSBN);
}
