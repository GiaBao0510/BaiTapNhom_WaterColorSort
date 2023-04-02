#include<stdio.h>
#include"BinhNuoc.h"
#include"malloc.h"
struct tree{
	binhNuoc data;
	struct tree *next;
};
typedef struct tree node;
//1.Tao nut rong
node * MakeNodeNull(){
	return NULL;
}
//2.Kiem tra danh sach lien ket rong
int Empty(node *X){
	return X == NULL;
}
//3.Gan gia tri cho mot nut
node *AssignValue(binhNuoc data){
	node *temp;
	temp = (node*)malloc(sizeof(node));	//Cap phat bo nho
	temp->data = data;
	temp->next = NULL;
	return temp;
}
//4.Them vao gia tri dau danh sach
node * pushHead(node *head,binhNuoc data){
	node *temp;
	temp = (node*)malloc(sizeof(node));//Cap phat bo nho
	temp = AssignValue(data);			//Gan gia tri
	//Neu ma nut dau tien dang xet la null, chua co gia tri gi ca thi gan cho nut do la nut temp
	if(head == NULL){
		head = temp;
	}else{
		temp->next = head;	//Con tro cua temp se tro den head hien tai
		head = temp;		//Sau do dat head la temp .Vi luc nay temp la head
	}
	return head; 
}
//5.Them gia tri vao cuoi danh sach
node * pushTail(node *head,binhNuoc data){
	node *temp;
	temp = (node*)malloc(sizeof(node));	//Cap phat bo nho
	temp = AssignValue(data);			//Gan gia tri
	//Neu head la null thi ta dat head la temp
	if(head == NULL){
		head = temp;
	}else{//Nguoc la ta lam nhu sau
		node *Q = head;		//Khoi tao cho Q tro den head
		while(Q->next!=NULL){		//Lap khi nao den cuoi danh sach thi thoi
			Q = Q->next;
		}
		Q->next = temp;		//Den cuoi danh sach thi cho con tro next cua Q gan bang temp
	}
	return head;
}
//6.Them binh nuoc vao vi tri bat ky trong danh sach
node * AddToAnyPossitionInTheLinkedList(node *head,binhNuoc data,int possition){
	if(possition == 0 || head == NULL){		//.Vi tri bat dau luon la 0 ,neu vi tri can them la 0 hoac head bang NULL thi dat head la temp
		head = AssignValue(data);
	}else{
		int vtri = 0;	//Bat dau tim vi tri can chen.
		node *Q = head;//Cho Q tro toi head
		//Dat vong lap while de do tim vi tri can chen
		while(Q->next != NULL){
			Q=Q->next;
			vtri++;
			if(vtri == possition){	//Neu dung vi tri can tim thi dung vong lap
				break;
			}
		}
		//Neu vi tri so sanh thay khong trung khop thi ta se tu chen vao cuoi danh sach
		if(vtri != possition){
			head = pushTail(head,data); 
		}else{//Neu tim thay vi tri thi
			node *temp;
			temp = (node*)malloc(sizeof(node));
			temp->next = Q->next;
			Q->next = temp;
		}
	}
	return head;
}
//7. Lay kich co cua danh sach
int size(node *X){
	int kichco = 0;
	node *Q = X;
	while(Q->next!=NULL){
		kichco++;
		Q=Q->next;
	}
	return kichco;
}
//8.Trong danh sach co binh rong khong
int checkEmptyBottleInLinkedList(node *X){
	//Neu danh sach lien ket rong thi tra ve 0
	if(Empty(X)){
		return 0;
	}else{
		node *Q = X;
		//Lap de do tim
		while(Q->next != NULL){
			if(empty_bottle(Q->data) == 1){//Phat hien co binh nuoc rong trong danh sach lien ket
				return 1;
			}
			Q = Q->next; 
		}
		return 0; //Khong tim thay binh rong
	}
}
//9.Tim vi tri binh rong trong danh sach lien ket
int EmptyBottlePositionQuery(node *X){
	//Neu danh sach rong thi tra ve -1
	if(Empty(X)){
		return -1;
	}else{
		int vitri = 0;
		node *Q = X;
		//Lap de tim vi tri chai rong
		while(Q->next != NULL){
			if(empty_bottle(Q->data)){//Da tim thay vi tri chai rong trong danh sach lien ket
				return vitri;
			}
			vitri++;
			Q = Q->next;
		}
		return -1; //Khong tim thay
	}
}
//10.Kiem tra binh nuoc X nao do co trong danh sach lien ket khong
int IsTheJarXinTheLinkedList(binhNuoc X, node *LL){
	
}
//11.So sanh hai cac binh nuoc trong hai danh sach co giong nhau khong

//In danh sach lien ket
void print(node *X){
	node *i;
	printf("\nDanh sach binh nuoc:");
	for(i=X;i!=NULL;i=i->next){
		HienThiBinhNuoc(i->data);
		printf("\n\t------------------");
	}
}
int main(){
	int n,i,mucnuoc;
	printf("Nhap so luong phan tu: "); scanf("%d",&n);
	node *X;
	X=MakeNodeNull();
	binhNuoc gt;
	for(i=0;i<n;i++){
		//Tao binh nuoc rong
		makeNull_bottle(&gt);
		//Nhap muc nuoc
		printf("\nNhap muc nuoc: "); scanf("%d",&mucnuoc);
		EnterValueForBottle(&gt,mucnuoc);
		//Them vao danh sach
		X = pushTail(X,gt);
	}
	print(X);
	printf("\nKich co cua danh sach: %d",size(X));
	printf("\nTrong danh sach co binh rong ko: %d",checkEmptyBottleInLinkedList(X));
	printf("\nVi tri binh rong trong danh sach: %d",size(X));
}
