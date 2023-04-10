#include<stdio.h>
#include<stdlib.h>
#define maxKichCoBinh 6
#define maxSoLuongBinh 1000
#define EMPTY 0
	/*Muc nuoc toi da cua moi binh deu la 5*/
//Bien mo ta mau
const char *mau[] = {"Brown","Red","Green","Blue","Black","White","Violet"};
//Cau truc binh nuoc. Moi binh co kich co khac nhau va gia tri muc nuoc cua moi binh la khac nhau
	typedef struct{
		int	data[maxKichCoBinh];	//Kich co hien tai cua mot binh
		int top;					//Muc nuoc dau tien	
	}binhNuoc;
	//1.Khoi tao binh nuoc rong
	void makeNull_Bottle(binhNuoc *B){
		B->top = 0;	//Nghia la muc nuoc cua no la 0
	}
	//2.Kiem tra binh nuoc rong
	int empty_bottle(binhNuoc B){
		return B.top == 0;	//Neu thuoc tinh top cua doi tuong la 0 thi la binh rong
	}
	//3.Kiem tra binh nuoc day
	int full_bottle(binhNuoc B){
		return B.top == maxKichCoBinh-1;	//Neu thuoc tinh top cua doi tuong la maxKichCoBinh thi la binh day
	}
	//4.Them 1 muc nuoc cho mot binh
	void Add_AWaterLevel(binhNuoc *B, int value){
		B->top++;
		B->data[B->top] = value;
	}
	//5.Nhap gia tri cho binh nuoc bang tay. Luu y la du lieu nay la vao truoc ra sau
	void EnterValueForBottle(binhNuoc *B,int mucnuoc){
		//Kiem tra xem muc nuoc co hop le khong
		if(mucnuoc > maxKichCoBinh-1){
			printf("\nMuc nuoc khong hop le");
		}else{
			int i,gtri;
			makeNull_Bottle(B); //lam rong binh nuoc cai da
			for(i=0;i<mucnuoc;i++){
				printf("Nhap muc mau nuoc[%d]: ",i); scanf("%d",&gtri);
				Add_AWaterLevel(B,gtri);
			}
		}
	}
	//6.Xoa 1 muc nuoc o dau
	void delete_AWaterLevel(binhNuoc *B){
		B->top--;
	}
	//6.2. Tra ve kich co binh nuoc
	int KichCoBinhNuoc(binhNuoc X){
		//Neu binh nuoc rong thi tra ve 0
		if(empty_bottle(X)){
			return 0;
		}else{
			int dem = 0;
			while(!empty_bottle(X)){
				dem++;
				delete_AWaterLevel(&X);
			}
			return dem;
		}
	}
	//7.Xem muc nuoc dau danh sach
	int MucNuocDau(binhNuoc B){
		return B.data[B.top];
	}
	//8.Hien thi trang thai binh nuoc
	void HienThiBinhNuoc(binhNuoc B){
		while(!empty_bottle(B)){
			printf("\n|\t%s\t|",mau[MucNuocDau(B)]);
			delete_AWaterLevel(&B);
		}
	}
	//9.Sao chep binh nuoc khac
	void copyBottle(binhNuoc *Result, binhNuoc current){
		//Vi la ngn xep, nen tui su dung tan 2 binh nuoc. De dung trong viec sau chep binh nuoc khac
		binhNuoc temp;	//Binh nuoc nay luu truu gia tri cua binh current. Nhung gia tri khi them binh nuoc nay gia tri cua no bi nguoc
		makeNull_Bottle(&temp);
		while(!empty_bottle(current)){
			Add_AWaterLevel(&temp,MucNuocDau(current));
			delete_AWaterLevel(&current);
		}
			//HienThiBinhNuoc(temp);
		//Sau do, tui se luu gia tri cua binh nuoc temp, nhug gia tri nay trung voi binh current
		makeNull_Bottle(Result);	//Lam rong binh nhan thi
		while(!empty_bottle(temp)){
			Add_AWaterLevel(Result,MucNuocDau(temp));
			delete_AWaterLevel(&temp);
		}
	}
	//10.So sanh 2 binh nuoc co giong nhau khong
	int CompareTwoBottles(binhNuoc A,binhNuoc B){
		//Neu binh A rong va binh B rong thi tra ve 1 
		if(empty_bottle(A) && empty_bottle(B)){
			return 1;
		}else if(A.top != B.top){	//Neu muc nuoc giua hai binh khac nhau thi tra ve khong
			return 0;
		}else{//So sanh tung gia tri giua 2 binh
			while(!empty_bottle(A)){
				if(MucNuocDau(A) != MucNuocDau(B)){	//Neu muc nuoc dau giua hai binh khac nhau thi tra ve khong
					return 0;
				}
				//Ta lay gia tri muc  nuoc dau cua 2 binh va tiep tuc so sanh
				delete_AWaterLevel(&A);
				delete_AWaterLevel(&B);
			}
		}
		return 1;
	}
	//11.Do binh nuoc A sang binh nuoc B
	int doBinhASangBinhB(binhNuoc *X,binhNuoc *Y){
		//1.Dieu kien dau neu binh X khong rong va binh Y chua day
		if(!empty_bottle(*X) && !full_bottle(*Y)){
			//2. Neu gia tri muc nuoc dau tien giua hai binh la giong nhau thi thuc hien viec do nuoc
			if(MucNuocDau(*X) == MucNuocDau(*Y)){
				int temp = MucNuocDau(*X); //Luu tru gia tri muc nuoc dau cua binh X. De so sanh voi phan tu dung sau no neu ma giong nhau thi thuc hien. Nguoc lai thi ngung
				//Neu binh X co top la 1(tuc chi co 1 muc nuoc) thi lam rong binh X va them muc nuoc o binh X sang binh Y
				if(KichCoBinhNuoc(*X) == 1){
					Add_AWaterLevel(Y,temp);
					makeNull_Bottle(X);
					return 1;
				}
				//2.1 Neu binh X chua rong thi do
				while(!empty_bottle(*X)){
					//2.2 Neu moi gia tri muc nuoc trong binh X lay ra ma trong voi bien temp thi thuc hien va Neu binh Y chua day thi thuc hien 
					if(MucNuocDau(*X) == temp && !full_bottle(*Y)){
						if(KichCoBinhNuoc(*X) == 1){
							Add_AWaterLevel(Y,temp);
							makeNull_Bottle(X);
							return 1;
						}else{
							Add_AWaterLevel(Y,temp);	//Binh Y nhan 1 muc nuoc
							delete_AWaterLevel(X);		//Binh X mat di mot muc nuoc
						}
					}else{	//Da thuc hien viec do thanh cong
						//printf("\nThanh cong!");
						return 1;
					}
				}
			}//Neu binh Y rong thi ta thuc hien viec do nuoc nhu binh thuong
			else if(empty_bottle(*Y)){
				Add_AWaterLevel(Y,MucNuocDau(*X));	//Them muc nuoc dau vao binh Y
				delete_AWaterLevel(X);				//Xoa muc nuoc dau o binh X
				return 1;
			}
		}
		//printf("\nThat bai!");
		return 0;//Khong thuc hien thanh cong
	}
	//12.Doc 1 binh nuoc tu file
	void readBottleFromFile(binhNuoc *B, char *tenTaiLieu){
		FILE *F;
		F = fopen(tenTaiLieu,"r"); //doc du lieu tu file nay
		int mucnuoc;
		//Doc so muc nuoc
		fscanf(F,"%d",&mucnuoc);
		//Kiem tra neu muc nuoc doc vao lon ho so voi quy dinh thi .Dung
		if(mucnuoc > maxKichCoBinh-1){
			printf("\nKich co binh nuoc vuot qua muc qui dinh.");
			return;	
		}
		makeNull_Bottle(B);
		int i,value;
		for(i=0;i<mucnuoc;i++){
			//Doc gia tri: Ma doc gia tri tu duoi len tren
			fscanf(F,"%d",&value);
			Add_AWaterLevel(B,value);
		}
	}
	//13.Kiem tra cac mau trong binh nuoc co trung nhau khong(Co the goi day la trang thai cuoi cua 1 binh nuoc)
	int CheckTheTargetStatusOfTheBottle(binhNuoc B){
		//Neu la binh nuoc rong thi tra ve 0
		if(empty_bottle(B)){
			return 0;
		}else{//Nguoc lai ta di kiem tra
			//1. Dau tien ta se lay muc nuoc dau cua binh nuoc de kiem tra
			int temp = MucNuocDau(B);
			//2.Dung vong lap de kiem tra
			while(!empty_bottle(B)){
				//Neu ma muc nuoc dau ma khac voi mau dau thi tra ve 0
				if(temp != MucNuocDau(B)){
					return 0;
				}else{						//Nguoc lai thi ta se Lay muc nuoc dau ra de kiem tra
					delete_AWaterLevel(&B);
				}
			}
			return 1;//Trang thai cuoi cua binh nuoc
		}
	} 
	//14. Ham kiem tra truoc ki do binh X sang binh Y
	int KiemTraDieuKienTruocKhiDoNuocTuBinhNaySangBinhKhac(binhNuoc X,binhNuoc Y){
		//Neu binh X khac rong va binh Y Chua day va hai muc nuoc dau cua hai binh deu giong nhau thi OK
		if(!empty_bottle(X) && !full_bottle(Y) && MucNuocDau(X) == MucNuocDau(Y)){
			return 1;
		}
		return 0;
	}
