#include<stdio.h>
#include"WaterColorSort_BFS.cpp"
int main(){
	node *DSBN = ReadListOfBottlesFromFile("DS_BinhNuoc2.txt");
	print(DSBN);
	//Kiem tra neu danh sach binh nuoc hop le thi thuc hien giai thuat
	
	if(CheckTheListOfBottlesIsValid(DSBN)){
			printf("\nDanh sach cua cac binh nuoc dau vao la hop le.");
			printf("\n\t.... Dang Tai ....");
			point *diem;
			diem = BFS(DSBN);
			//Ket qua
			th(diem);
	}else{
		printf("\nDanh sach cua cac binh nuoc khong hop le.");
	}
}
