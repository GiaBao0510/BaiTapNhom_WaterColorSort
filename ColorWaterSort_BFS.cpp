#include<stdio.h>
#include<malloc.h>
using namespace std;
#include<queue>	//Su dung thu vien hang doi
#include"DanhSachBinhNuoc.h"
//Tao mot cau truc de luu truu duong di trong tro choi
	struct DuongDi{
		node * danhSach;	//Danh sach binh nuoc
		int binhCho,			//Bien nay mo ta binh cho nuoc
			binhNhan;			//Bien nay mo ta binh nhan nuoc
		struct DuongDi *next;
	};
	typedef struct DuongDi point;	//Day la mot diem. Dung de ket noi cac trang thai trong danh sahc binh nuoc
	//1.Lam rong 1 diem
	point * makeNullPoint(){
		return NULL;
	}
	//2. Gan gia tri vao trong 1 diem
	point * AssignValueInA_Point(node *data){
		point *temp = (point*)malloc(sizeof(point));	//Cap phat bi nho
		temp->danhSach = data;
		temp->next = NULL;
		return temp;
	}
	//3.Day 1 danh sach vao dau cua Diem
	point * PushHead(point *diem,node *data){
		//Tao mot diem temp de luu tru gia tri data
		point *temp = AssignValueInA_Point(data);
		//Neu diem nay la NULL thi gan diem = temp
		if(diem == NULL){
			diem = temp;
		}else{
			temp->next = diem;
			diem = temp;
		}
		return diem;
	}
	//4. Hien thi Diem
	void PrintPoin(point *X){
		printf("\nDiem:");
		print(X->danhSach);
		printf("\nBinh cho: %d",X->binhCho);
		printf("\nBinh nhan: %d",X->binhNhan);
	}
//1.Kiem tra 1 danh sach trang thai co ton tai trong hang doi khong
int IsTheListOfBottleInTheQueue(queue<point*> HangDoi, node *DS){
	while(!HangDoi.empty()){
		//Neu ma ton tai danh sach binh nuoc trong hang doi thi tra va 1
		if(CompareTwoLinkedList(HangDoi.front()->danhSach,DS) == 1){
			return 1;
		}else{
			HangDoi.pop();
		}
	}
	return 0;//Nghia la khong ton tai danh sach binh nuoc trong hang doi
}
const char *action[] = {"Trang thai dau","Do nuoc tu binh %d vao binh %d"};
//2. 
point * BFS(node *DSBN){
	//Tao danh sach open, closed
	queue<point*> open,closed;
	//Tao diem root
	point *root = (point*)malloc(sizeof(point));
	root->danhSach= DSBN;
	root->binhCho = root->binhNhan = -1;
	root->next = NULL;
	//Day root vao open
	open.push(root);
	//Lap den khi open rong thi dung lai
	int dem = 0;
	while(!open.empty()){
		//Lay diem dau ra khoi open va day diem dau nay vao closed
		point *Fpoint = open.front();
		open.pop();
		closed.push(Fpoint);
			printf("\n__________Xet [%d]:_________",dem);
			print(Fpoint->danhSach);
		//Kiem tra neu la trang thai dich thi dung lai
		if(CheckTheTargetStateOfTheLinkedList(Fpoint->danhSach) == 1){
				printf("\nDung lai(ZaQuaRuDo)");
				print(Fpoint->danhSach);
			return Fpoint;
		}
		int i,j,
			kichCo = size(DSBN);
		//Lap                   
		for(i=0;i<=kichCo;i++){
			//Cho Q tro den danh sach binh nuoc cua Fpoint
			node *Q = Fpoint->danhSach;
			for(j=0;j<=kichCo;j++){
				//Thuc hien do binh nuoc
				node *temp = DoBinhNuocO_viTriBatKySangMotBinhNuocKhac(Q,i,j);
					printf("\n>>>>> Chuan bi xet Trang thai: <<<<<");
					printf("\n//// Do nuoc tu binh %d sang binh %d /////",i,j);
					print(temp);
				//Neu trang thai nay co trong open va closed thi bo qua
				if(IsTheListOfBottleInTheQueue(open,temp) == 1 || IsTheListOfBottleInTheQueue(closed,temp) == 1){
					continue;
				}
					printf("\n#### Trang thai moi: ####");
					print(temp);
				//Nguoc lai thi ta day trang thai moi nay vao open
				point *Spoint = (point*)malloc(sizeof(point));
				Spoint->danhSach = temp;
				Spoint->binhCho = i;
				Spoint->binhNhan = j;
				Spoint->next = Fpoint;
				open.push(Spoint); 
			}
		}                                                                                                                                                                                                                                                                                                                                 
		dem++;
	}
	return NULL;
}
point * kiemTra(node *DSBN){
	queue<point*> open;
	point *root = (point*)malloc(sizeof(point));
	root->danhSach = DSBN;
	root->binhCho = -1;
	root->binhNhan=-1;
	root->next = NULL;
	printf("\n---------------Hien thi danh sach binh nuoc cua diem root:");
	//print(root->danhSach);
	open.push(root);
	print(open.front()->danhSach);
//	printf("\nDo nuoc tu binh nay sng 1 binh khac: do dai cua danh sach la: %d",size(root->danhSach));
//	int i,j;
//	node *Q = root->danhSach;
//	for(i=0;i<size(root->danhSach);i++){
//		printf("\n ----BInh thu [%d]:---- ",i);
//		for(j=0;j<size(root->danhSach);j++){
//			printf("\nDo nuoc tu binh %d sang binh %d.",i,j);
//			node *temp = DoBinhNuocO_viTriBatKySangMotBinhNuocKhac(Q,i,j);
//			point *Snode = (point*)malloc(sizeof(point));
//			root->danhSach = temp;
//			root->binhCho = i;
//			root->binhNhan=j;
//			root->next = NULL;
//			open.push(Snode);
//			print(temp);
//		}
//	}
//	int dem = 0;
//	printf("\nCac trang thai trong hang doi");
//	while(!open.empty()){
//		printf("\n____________________________Trang thai %d ___________________________",dem);
//		PrintPoin(open.front());
//		open.pop();
//		dem++;
//	}
	return root;
}
