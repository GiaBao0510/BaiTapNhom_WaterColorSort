#include<stdio.h>
#include"WaterColorSort_BFS.cpp"
int main(){
	node *DSBN = ReadListOfBottlesFromFile("DS_BinhNuoc2.txt");
	print(DSBN);
	//Kiem tra neu danh sach binh nuoc hop le thi thuc hien giai thuat
	if(CheckTheListOfBottlesIsValid(DSBN)){
			printf("\nDanh sach cua cac binh nuoc hop le.");
			printf("\n\t.... Dang Tai ....");
			point *diem;
			diem = BFS(DSBN);
	}else{
		printf("\nDanh sach cua cac binh nuoc khong hop le.");
	}
//--------------
//	printf("\nSau khi thuc hien do nuoc.");
//	node *temp = DoBinhNuocO_viTriBatKySangMotBinhNuocKhac(DSBN,0,3);
//	print(temp);
//------------
//	binhNuoc X,Y;
//	makeNull_Bottle(&X);
//	makeNull_Bottle(&Y);
//	readBottleFromFile(&X,"taiLieuBinhNuoc2.txt");
//	readBottleFromFile(&Y,"taiLieuBinhNuoc.txt");
//	printf("\nBinh X");
//	HienThiBinhNuoc(X);
//	printf("\nBinh Y");
//	HienThiBinhNuoc(Y);
//	printf("\n---SAu khi thuc hien do nuoc tu X-Top: %d sang Y-Top: %d",KichCoBinhNuoc(X),KichCoBinhNuoc(Y));
//	if(doBinhASangBinhB(&X,&Y) == 1){
//		printf("\nBinh X");
//		HienThiBinhNuoc(X);
//		printf("\nBinh Y");
//		HienThiBinhNuoc(Y);
//	}else{
//		printf("\nThat bai");
//	}
//-----------

}
