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
poitn * GT(node *DSBN){
	//1. Cac bien
	queue<point*> open,		//Luu tru danh sach chua duoc duyet 
				closed;		//Luu tru danh sach da duoc duyet
	point *root; //Diem goc
}
int main(){
	node *DS;
	DS = MakeNodeNull();
	DS = ReadListOfBottlesFromFile("DS_BinhNuoc2.txt");
	print(DS);
}

