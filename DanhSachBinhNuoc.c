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
	return X== NULL;
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
	//Neu danh sach lien ket rong thi tra ve 0
	if(Empty(LL)){
		return 0;
	}else{
		//Cho Q tro den LL
		node *Q = LL;
		//Lap de tim tung binh nuoc trong danh sach lien ket co khong
		for(Q;Q->next != NULL; Q= Q->next){
			//Neu tim thay thi tra ve 1
			if(CompareTwoBottles(X,Q->data)){
				return 1;
			}
		}
		return 0;//Khong tim thay
	}
}
//11.So sanh hai cac binh nuoc trong hai danh sach co giong nhau khong
int CompareTwoLinkedList(node *A,node *B){
	//So sach do dai cua hai danh sach lien ket. NEu do dai cua hai danh sach khac nhau thi tra ve 0
	if(size(A) != size(B)){
		return 0;
	}else{
		//Cho nut X tro den A va cho nut Y tro den B
		node *X = A,
			 *Y = B;
		//Lap so sanh tung binh nuoc trong hai danh sach
		while(X->next != NULL && Y->next != NULL){
			//Neu ma ket qua so sanh khac 1 thi tra ve 0
			if(CompareTwoBottles(X->data, Y->data) != 1){
				return 0;
			}else{	//Nguoc lai thi tim hai binh khac de so sanh
				X = X->next;
				Y = Y->next;
			}
		}
		//Hai binh giong nhau
		return 1;
	}
}
//13. Copy danh sach lien ket khac
node * copyOtherLinkedList(node *root, node *other){
	//Cho nut T tro den other
	node *T = other;
	//Lam rong danh sach root
	root = MakeNodeNull();
	//Lap de sau chep
	while(T != NULL){
		root = pushTail(root,T->data);
		T = T->next;
	}
	return root;
}
//14.Kiem tra tat ca cac binh nuoc trong danh sach co dung mau chua(Trang thai goal cua danh sach binh nuoc)
int CheckTheTargetStateOfTheLinkedList(node *LL){
	//Cho Q tro toi LL
	node *Q = LL;
	//Lap de kiem tra tung binh nuoc co trong danh sach
	for(Q;Q!=NULL;Q=Q->next){
		//Neu ma cac binh nuoc trong danh sach khong co cac mau trung nhau thi tra ve 0
		if(CheckTheTargetStatusOfTheBottle(Q->data) == 0){
			return 0;
		}
	}
	return 1; //La trang thai dich
}
//15.Xoa dau phan tu dau trong danh sach lien ket
node * XoaPhanTuDauTienTrongDanhSachLienKet(node *head){
	//Neu danh sach rong thi tra ve 0
	if(Empty(head)){
		printf("\n----Danh sach rong khong the xoa----\n");
	}else{
		head = head->next;
	}
	return head;
}
//16.Xoa binh nuoc cuoi danh sach
node * XoaPhanCuoiCungTrongDanhSachLienKet(node *head){
	//Neu danh sach rong hoac next cua head la rong thi head
	if(Empty(head) || head->next == NULL){
		printf("\n----Danh sach rong khong the xoa----\n");
		head = XoaPhanTuDauTienTrongDanhSachLienKet(head);
		return head;
	}
	else{
		//1.Cho Q tro vao head va tap mot node temp
		node *Q = head;
		node *temp = MakeNodeNull();
		//2.Lap de tim phan tu cuoi
		while(Q->next!=NULL){
			temp = pushTail(temp,Q->data);
			Q = Q->next;
		}
		return temp;
	}
}
//17.Xoa binh rong trong danh sach
node * XoaBinhNuocRongTrongDanhSachLienKet()
//Xoa o vi tri bat ky
//Do nuoc trong binh nay sang tat cac binh khac trong danh sach lien ke
//In danh sach lien ket
void print(node *X){
	node *i;
	int dem = 1;
	printf("\nDanh sach binh nuoc:");
	for(i=X;i!=NULL;i=i->next){
		printf("\n  Binh nuoc [%d]:",dem);
		HienThiBinhNuoc(i->data);
		dem++;
	}
}
//Doc danh sach cac binh nuoc tu FILE
node *ReadListOfBottlesFromFile(char *S){
	//Tao mot nut
	node *temp;
	temp = MakeNodeNull();
	//Binh nuoc
	binhNuoc BN;
	//Cac bien
	int soLuongChai,
		mucNuoc,
		i,j,
		giaTri;
	//Doc du lieu
	FILE *F = fopen(S,"r");
	//doc so luong binh nuoc
	fscanf(F,"%d",&soLuongChai);
	//Vong lap doc tung chai nuoc
	for(i=1;i<=soLuongChai;i++){
		//Lam rong binh nuoc
		makeNull_bottle(&BN);
		//Doc muc nuoc ma binh co the chua
		fscanf(F,"%d",&mucNuoc);
		if(mucNuoc > 5){
			continue;
		}else{
			//Vong doc tung du lieu vao trong chai nuoc
			for(j=1;j<=mucNuoc;j++){
				fscanf(F,"%d",&giaTri);
				Add_AWaterLevel(&BN,giaTri);
			}
			//Them vao cuoi danh sach
			temp = pushTail(temp,BN);
		}
	}
	fclose(F);
	return temp;
}
int main(){
	node *X = ReadListOfBottlesFromFile("DS_BinhNuoc.txt");
	node *Y = copyOtherLinkedList(Y,X);
	printf("\n_______________Danh sach 1");
	print(X);
	printf("\n______________Danh sach 2");
	print(Y);
	printf("\nHai danh sach giong nhau: %d",CompareTwoLinkedList(X,Y));
	printf("\nCac binh nuoc trong danh sach 1 deu co mau trung nhau: %d",CheckTheTargetStateOfTheLinkedList(X));
	printf("\nSau khi xoa phan tu dau trong danh sach lien ket:");
	X = XoaPhanCuoiCungTrongDanhSachLienKet(X);
	print(X);
}
