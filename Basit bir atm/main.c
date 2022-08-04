#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *dosya,*dosya2;
    dosya = fopen("test.txt","r");//ISLEMDEN ONCEKI DOSYA
    dosya2 = fopen("test2.txt","w");//ISLEMDEN SONRAKI DOSYA
    char a[100];
    int n=0;//SAYIM ICIN
    int para,degis;//MUSTERININ PARASINI TUTMAK VE DEGISMEK ICIN
    int secim;//SWITCH CASE ICIN
    if(dosya == NULL){
        printf("Dosya acilmadi\n");
        return 0;
        }

    bilgiler_fonk(dosya);//BILGILERIN EKRANA YANSIDIGI FONK
    fseek(dosya,0, SEEK_SET);//IMLECI BASA ALMA
    while(! feof(dosya) ){
    fscanf(dosya,"%s",&a);
    if(strcmp(a,"bakiyesi:") == 0){//BAKIYESI KELIMESINE GELIP
    fscanf(dosya,"%s",&a);
    para=atoi(a);
    }
   }
    printf("\nYapacaginiz islemi seciniz...\n\n\n1-Para cekme\n\n\n2-Para yatirma\n\n\n");
    scanf("%d",&secim);
    switch(secim){
        case 1:
        printf("Kac para cekmek istiyorsunuz..\n");
        scanf("%d",&degis);
        while(degis>para){
            printf("Hesabinizda yeterli bakiye bulunmamaktadır. Tekrar deneyiniz.\n");
            scanf("%d",&degis);}
        para= para-degis;
        break;
case 2:
    printf("\n\nKac para eklemek istiyorsunuz..\n\n\n");
    scanf("%d",&degis);
    para= para+degis;
    break;

}
    fseek(dosya,0, SEEK_SET);
    printf("\n\hHesaptaki bakiye = %d",para);
while(n<3){ //DOSYAYA BILGI YAZMAK ICIN CUMLE CUMLE
    fgets(a,50,dosya);
    fprintf(dosya2,a);
    n++;
   }
while(! feof(dosya) ){ //DOSYAYA BAKIYEYİ YAZMAK ICIN KELIME KELIME
    fscanf(dosya,"%s",&a);
    if(strcmp(a,"bakiyesi:") == 0){
        fprintf(dosya2,a);
        fprintf(dosya2," ");
        itoa(para,a,10);
        fprintf(dosya2,a);
        break;
    }
    else{
    fprintf(dosya2,a);
    fprintf(dosya2," ");
    }
   }

printf("\n\n\n||||||KAYIT YAPILDI||||||\n\n\n");
    fclose(dosya);
}

void bilgiler_fonk(FILE *dosya){
char a[50];
printf("||||||MUSTERI BILGILERI||||||\n\n\n");
fgets(a,50,dosya);
    while(! feof(dosya) ){
    printf("%s\n",a);
    fgets(a,50,dosya);
   }

}
