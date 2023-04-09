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
		while(Q != NULL){
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
node * XoaBinhNuocRongTrongDanhSachLienKet(node *head){
	//Neu danh sach rong khong the xoa
	if(Empty(head)){
		printf("\n----Danh sach rong khong the xoa----\n");
		return head;
	}else{
		//1. Cho Q tro vao head
		node *Q = head;
		node *temp = MakeNodeNull(); 
		//2.Lap de tim binh rong
		while(Q!=NULL){
			//Neu tim thay binh rong thi cho Q tro den next
			if(empty_bottle(Q->data)){
				Q = Q->next;
			}else{//Nguoc lai thi ta them vao temp
				temp = pushTail(temp,Q->data);
				Q = Q->next;
			}
		}
		return temp;
	}
}
//18.Tra ve gia tri cua phan tu trong danh sach tai vi tri bat ky
binhNuoc ReturnThePositionOfTheBottle(node *X, int vitri){
	//Neu vi tri khong hop le thi tra ve binh nuoc rong
	if(vitri > size(X) || vitri < 0){
		binhNuoc BN;
		makeNull_Bottle(&BN);
		printf("\n\tVi tri khong hop le.\n");
		return BN;
	}else{
		int dem = 0;
		//Cho Q tro vao X
		node *Q = X;
		while(Q != NULL){
			//Neu tim thay vi tri thi tra ve binh nuoc
			if(dem == vitri){
				return Q->data;
			}else{//Nguoc lai thi tiep tuc tim
				dem++;
				Q = Q->next;
			}
		}
		printf("\nDem: %d",dem);
	}
}
//19.Do binh nuoc o vi tri bat ky sang tat ca binh nuoc khac trong danh sach (Ngoai tru no)
node * DoBinhNuocO_viTriBatKySangMotBinhNuocKhac(node * DS, int vtBinh1, int vtBinh2){
	//Neu vi tri binh 1 va vi tri binh 2 ma lon hon kich co cua danh sah hoac la so am thi ko thuc hien hoac vi tri binh 1 va binh 2 giong nhau thi cung khong thuc hien
	if(vtBinh1 > size(DS) || vtBinh1 < 0 || vtBinh2 > size(DS) || vtBinh2 < 0 || vtBinh1 == vtBinh2){
		//	printf("\nThuc hien that bai.");
		return DS;
	}else{
		//Cho Q1, Q2, Q3 tro den DS
		node *Q1, *Q2, *Q3;
		Q1 = Q2 = Q3 = DS;
		//Tao 1 nut temp dung de luu ket qua sau khi thuc hien thanh cong
		node *temp = MakeNodeNull();
		//Cho 2 binh nuoc de bieu dien
		binhNuoc B1, B2;
		makeNull_Bottle(&B1);
		makeNull_Bottle(&B2);
		int dem = 0;
		//Lap de tim va luu gia tri tai vi tri binh 1
		while(Q1 != NULL){
			if(dem == vtBinh1){		//Da tim thay gia tri binh thu 1 trong danh sach
				copyBottle(&B1,Q1->data);
				break;
			}else{
				dem++;
				Q1 = Q1->next;
			}
		}
		dem = 0;//Dat lai bien dem = 0
		//Lap de tim va luu gia tri tai vi tri binh 2
		while(Q2 != NULL){
			if(dem == vtBinh2){		//Da tim thay gia tri binh thu 2 trong danh sach
				copyBottle(&B2,Q2->data);
				break;
			}else{
				dem++;
				Q2 = Q2->next;
			}
		}
		//Neu hanh dong thuc hien do nuoc tu binh 1 sagn binh 2 la thanh cong thi ta thuc hien cong viec sau
		if(doBinhASangBinhB(&B1,&B2) == 1){
			//1.Dat lai bien dem = 0
			dem = 0;
			//Vong lap de luu gia tri binh vao temp
			while(Q3 != NULL){
				//Neu gia tri cua bien dem ma bang voi vi tri binh 1 thi luu B1 vao temp
				if(dem == vtBinh1){
					temp = pushTail(temp,B1);
					//	printf("\n Vi tri binh 1: %d",vtBinh1);
					//	HienThiBinhNuoc(B1);
				}
				//Neu gia tri cua bien dem ma bang voi vi tri binh 2 thi luu B2 vao temp
				else if(dem == vtBinh2){
					//	printf("\n Vi tri binh 2: %d",vtBinh2);
					//	HienThiBinhNuoc(B2);
					temp = pushTail(temp,B2);
				}
				else{
					//Luu gia tri nhung binh nuoc khac khong bi thay doi vao temp
					temp = pushTail(temp,Q3->data);
				}
				dem++;
				Q3 = Q3->next;
			}
			//	printf("\nThuc hien thanh cong.");
			return temp;
		}else{
			//	printf("\nThuc hien that bai.");
			return DS; //that bai khong tuc hien thanh cong
		}
	}
}
//20. Kiem tra danh sach chua cac binh nuoc dau vao co hop le khong (Hop le: So luong mau nuoc < so luong binh, moi muc cua mau deu == 5, phai co 1 binh rong va khong phai la danh sach rong)
	//1.Tao 1 cau truc la luu tru thong tin mau
	typedef struct{
		int mau,
			sl;
	}ColorInformation;
	//2.Cau truc danh sach luu tru cac thong tin mau sac
	typedef struct{
		ColorInformation data[1000];
		int doDai;
	}DanhSachThongTinMauSac;
		//2.1.Khoi tao danh sach thong tin mau sac
	void LamRongDanhSachThongTinMauSac(DanhSachThongTinMauSac *DS){
		DS->doDai = 0;
	}
		//2.2. Tim ben trong danh sach thong tin mau sac nay co mau nao da ton tai hay chua. Neu mau nay da ton tai thi tra ve vi tri cua mau do ben trong danh sach
	int TimMauSacTrungTrongDanhSach(DanhSachThongTinMauSac DS,ColorInformation MauX){
		int r = DS.doDai,	//Bat dau tu ben phai
			l = 1;			//Bat dau tu ben trai
		//Lap de do tim co mau nao da bi trung khong
		while(r >= l){
			int m = (r+l)/2;
			if(DS.data[r].mau == MauX.mau){
				return r;					//Vay da co mau nay trong danh sach
			}
			if(DS.data[l].mau == MauX.mau){
				return l;					//Vay da co mau nay trong danh sach
			}
			if(DS.data[m].mau == MauX.mau){
				return m;					//Vay da co mau nay trong danh sach
			}
			r--;
			l++;
		}
		return 0;	//Khong ton tai mau nay trong danh sach
	}
	//2.Them 1 thong tin ve mac sac cho danh sach thong tin mau sac
	void ThemThongTinMauSacVaoCuoi(DanhSachThongTinMauSac *DS,ColorInformation X){
		//Neu mau nay duoc them vao danh sach ma ben trong danh sach nay da ton tai ma do thi tang so luong mau do
		if(TimMauSacTrungTrongDanhSach(*DS,X) != 0){
			int vitri = TimMauSacTrungTrongDanhSach(*DS,X);
			DS->data[vitri].sl++;
		}else{//Nguoc lai ta them mau do cao trong danh sach mau
			DS->doDai++;
			DS->data[DS->doDai].mau = X.mau;
			DS->data[DS->doDai].sl = 1;
		}
	}
	//Tim mau sac co trong mang mau sac khong
	int CheckTheListOfBottlesIsValid(node *X){
		//1.Neu danh sach binh nuoc ma khong co 1 binnh rong thi tra ve 0
		if(!checkEmptyBottleInLinkedList(X)){
			//printf("\nDanh sach khong co binh rong");
			return 0;
		}
		//2. Neu danh sach binh nuoc la 1 danh sach rong thi tra ve 0
		if(Empty(X)){
			//printf("\nDanh sach rong");
			return 0;
		}
		//Cac doi tuong ho tro
		ColorInformation CL;
		DanhSachThongTinMauSac DS;
		LamRongDanhSachThongTinMauSac(&DS);
		//Doc mau sach trong binh
		//Cho Q tro den X
		node *Q = X;
		//Lap danh sach cac binh
		while(Q!=NULL){
			//Lap cac mau ben trong binh
			while(!empty_bottle(Q->data)){
				CL.mau = MucNuocDau(Q->data);
				//Day mau vao danh sach
				ThemThongTinMauSacVaoCuoi(&DS,CL);
				delete_AWaterLevel(&Q->data);
			}
			Q = Q->next;
		}
//			printf("\nCo %d mau.",DS.doDai);
//			int i;
//			for(i=1;i<=DS.doDai;i++){
//				printf("\n----------------");
//				printf("\nMau %d xuat hien %d lan.",DS.data[i].mau,DS.data[i].sl);
//			}
		//3. Neu so luong mau xuat hien ma so hon so luong binh nuoc -1 thi tra ve 0
		if(DS.doDai > size(X)){
			//printf("\nSo luong mau sau: %d - so luong binh nuoc: %d", DS.doDai,size(X));
			return 0;
		}
		//4.Kiem tra tat cac ca so lan xuat hien mau nuoc phai bang 5
		int i;
		for(i=1;i<DS.doDai;i++){
			//Neu so lan xuat hien cua 1 mau nao do ma != 5 thi tra ve 0
			if(DS.data[i].sl != 5){
				//printf("\nSo mau: %d - so lan xuat hien: %d",DS.data[i].mau,DS.data[i].sl);
				return 0;
			}
		}
		return 1;//Hop le
	}
//In danh sach lien ket
void print(node *X){
	node *i;
	int dem = 0;
	printf("\nDanh sach binh nuoc:");
	for(i=X;i!=NULL;i=i->next){
		printf("\n  So thu tu [%d]:",dem);
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
		makeNull_Bottle(&BN);
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
