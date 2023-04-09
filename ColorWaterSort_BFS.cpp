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
point * GT(node *DSBN){
	//1. Cac bien
	queue<point*> open,		//Luu tru danh sach chua duoc duyet 
				closed;		//Luu tru danh sach da duoc duyet
	point *root; //Diem goc
	//2.Khoi tao diem root
	root = makeNullPoint();
	root = AssignValueInA_Point(DSBN);	//Gan du lieu danh sach binh nuoc cho diem root
	//3. Day diem root dau tien vao hang doi open
	open.push(root);
	//4.Lap voi dieu khien la hang doi khong rong
	int lap = 0;
	while(!open.empty()){
		//4.1 Lay diem dau ra khoi hang doi
		point *Fpoint = open.front();
			printf("\n-------------------[%d]Xet danh sach binh nuoc nay:--------------------",lap);
			print(Fpoint->danhSach);
		//4.2 Day diem vua duoc lay vao hang doi closed
		closed.push(Fpoint);
		//4.3 Xoa diem o dau hang doi open
		open.pop();
		//4.4 Kiem tra co phai trang thai dich khong
		if(CheckTheTargetStateOfTheLinkedList(Fpoint->danhSach) == 1){
				printf("\nTrang thai dich ket thuc.");
			return Fpoint;
		}
		//Tao bien
		int kichCoBinh = size(Fpoint->danhSach),	//Lay kich co binh nuoc
			i,j;
		//4.4 Lap de do nuoc tu binh duoc chon sang cac binh khac
		for(i=1;i<=kichCoBinh;i++){
			//Tao 1 node Q tro den gia tri node cua Diem Fpoint
			node *Q = Fpoint->danhSach;
			for(j=1;j<=kichCoBinh;j++){
				//Tao mot nut luu ket qua sao khi thuc hien do nuoc tu binh nay sang binh khac
				node *temp = DoBinhNuocO_viTriBatKySangMotBinhNuocKhac(Q,i,j);
				//Kiem tra xem trang thai cua danh sach binh nuoc nay no da ton tai trong hang doi open hoac closed. Thi bo qua
				if(CompareTwoLinkedList(temp,open.front()->danhSach) == 1 || CompareTwoLinkedList(temp,closed.front()->danhSach)){
					continue;
				}
				//Neu day la 1 trang thai moi thi cho no vao hang doi open
				//Tao 1 diem moi
				point *Spoint = (point*)malloc(sizeof(point));
				Spoint->danhSach = temp;
				Spoint->binhCho = i;
				Spoint->binhNhan = j;
				Spoint->next = Fpoint;
				open.push(Spoint);
			}
		}
		lap++;
	}
	return NULL; //Khong tim thay ket qua
}


