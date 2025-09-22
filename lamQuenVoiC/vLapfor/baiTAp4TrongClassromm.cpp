#include <stdio.h>
#include <math.h>
main(){
	int n;
	
	
// Nhap vao man hinh
	printf("Nhap n: ");
	scanf("%d", &n);
	int a[100];
	for(int i=0;i<n;i++){
		printf("Nhap a[%d]= ",i);
		scanf("%d",&a[i]);
	}


// In ra man hinh
	printf("Day so vua nhap la: \n");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
	
	
// Dem xem day so co bao nhieu so am
	int dem=0;
	for(int i=0;i<n;i++)
		if(a[i]<0){
		dem=dem+1;
		}
		if(dem==0){
			printf("Vay khong co so am nao trong mang");
		}
		if(dem>0){
			printf("Vay co %d so am trong mang",dem);
		}



// Dem xem trong day co bao nhieu so nguyen to lon hon 10
	int songuyento=0;
	int demsont=0;
	for(int i=0;i<n;i++){
		songuyento=1;
		if(a[i]<=10){
			songuyento=0;
		} else {
			for(int j=2;j<=sqrt(a[i]);j++){
				if(a[i]%j==0){
					songuyento=0;
	// break;
				}
			}
			if(songuyento) demsont=demsont+1;
		}
	}
	printf("\n\nVay so luong so nguyen to lon hon 10 trong mang la: %d",demsont);
	
	
	
// Dem xem trong day co bao nhieu cap so co tong bang x
	int demcapso=0;
	int dapan=0;
	int x;
	printf("\n\nNhap x: ");
	scanf("%d", &x);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			demcapso=1;
			if(a[j]+a[i]!=x){
				demcapso=0;
	// break;
			}
			if(demcapso) dapan=dapan+1;
		}
	}
	printf("\nVay co %d cap so co tong bang x",dapan);
	


// Kiem tra day so co tao thanh cap so nhan khong
	int q;
	int capsonhan=0;
	int flag=0;
	printf("\n\nNhap q: ");
	scanf("%d", &q);
	for(int i=0;i<n;i++){
		capsonhan=1;
		if(a[i+1]!=a[i]*q){
			capsonhan=0;
	// break;
		}
		if(capsonhan) flag=flag+1;
	}
	printf("\nVay co %d CSN trong mang",flag);
	
	
	
// Dem xem trong day co bao nhieu so hoan hao
	int demsohoanhao=0;
	for(int i=0;i<n;i++){
		int sohoanhao=0;
		if(a[i]>1){
			for(int j=1;j<=a[i]/2;j++){
				if(a[i]%j==0){
					sohoanhao=sohoanhao+j;
	// break;
				}
			}
			if(sohoanhao==a[i]) demsohoanhao=demsohoanhao+1;
		}
	}
	printf("\nVay co %d so hoan hao trong mang",demsohoanhao);
	
	
	
return 0;
}
