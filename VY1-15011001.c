#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
    struct	n * next;
}node;

void yazdir(node *);                // linkli listenin basini alip sonuna kadar yazdiran fonksiyon
node * ekle(node * , int);          // linkli listenin sonuna eleman ekleyen fonksiyon
node * kesisim(node * , node * );   // 2 dizinin kesisimini bulan fonksiyon
node * birlesim(node * ,node * );   // 2 dizinin birlesimini bulan fonksiyon


int main(){
    node *dizi = NULL;          // A Dizisi için
    node *dizi2 = NULL;         // B Dizisi için
    node *dizi3 = NULL;         // C Dizisi için
    node *dizi4 = NULL;         // D Dizisi için
    int i;                      // for döngüsü için
    int n;                      // dizilerin eleman sayisi için
    int x;                      // dizilere elaman eklemek için
    printf("1.Dizinin eleman sayisini giriniz = ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("1.Dizinin %d. elemanini girin = ",i);
        scanf("%d",&x);
        dizi = ekle(dizi,x);
    }
    printf("2.Dizinin eleman sayisini giriniz = ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("2.Dizinin %d. elemanini girin  = ",i);
        scanf("%d",&x);
        dizi2 = ekle(dizi2,x);
    }
    printf("A Dizisi = ");
    yazdir(dizi);

    printf("B Dizisi = ");
    yazdir(dizi2);

    dizi3 = kesisim(dizi,dizi2);
    printf("C Dizisi = ");
    yazdir(dizi3);

    dizi4 = birlesim(dizi,dizi2);
    printf("D Dizisi = ");
    yazdir(dizi4);


return 0;
}

void yazdir(node * dizi){
	while(dizi!=NULL){
		printf("%d ",dizi->x);
		dizi = dizi->next;
	}
	printf("\n");
}

node * ekle(node * A , int x){



    if(A==NULL){
                                       // sadece ilk durum için link list bossa
		A = (node *) malloc (sizeof(node));
		A->next = NULL;
		A->x = x;
		return A;
	}

    node * tmp =  A;                        // Linkli listenin basini saklamam gerek onu döndürecek
                                            // o yüzden tmp ile geliyorum listenin sonuna
    while(tmp->next!=NULL){

        tmp = tmp->next;
    }

    tmp->next = (node*)malloc(sizeof(node));
	tmp->next->x = x;
	tmp->next->next = NULL;

    return A;

}

node * kesisim(node * headA, node * headB){
    node * headC = NULL;
    while(headA!=NULL && headB!=NULL){ // herhangi bir dizi bitene kadar dönecek
        if(headA->x==headB->x){        // degerleri esit oldugunda
            headC = ekle(headC,headA->x); // C dizisine ekledim
            headB = headB->next;          // Diger dizilerde ilerledim
            headA = headA->next;
        }
        else if(headA->x > headB->x){     // A dizisinin elemani büyükse B dizisinde ilerlemem gerek
            headB = headB->next;
        }
        else {
            headA = headA->next;
        }
    }
    return headC;
}

node * birlesim(node * headA,node * headB){

    node * headD = NULL;



    while(headA!=NULL && headB!=NULL){   // herhangi bir dizi bitene kadar dönüyorum

        if(headA->x==headB->x){          // esitlik durumunda 2 diziden de ilerlemem gerek o yüzden ayri if
            headD = ekle(headD,headA->x);
            headB = headB->next;
            headA = headA->next;
        }

        else if(headA->x>headB->x){        // küçük olanin elemanini ekliyorum ve ilerletiyorum
            headD = ekle(headD,headB->x);
            headB = headB->next;
        }
        else {
            headD = ekle(headD,headA->x);
            headA = headA->next;
        }
    }

    if(headA==NULL){                      // ilk hangi dizi bitmis ise diðer diziyi sirasiyla ekliyorum
        while(headB!=NULL){
          headD  = ekle(headD,headB->x);
            headB = headB->next;
        }
    }
     else
     {

         while(headA!=NULL){

           headD = ekle(headD,headA->x);
            headA = headA->next;
        }
     }
    return headD;
}
