#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HASTA 100

// Hasta bilgileri icin struct
typedef struct {
    char id[10];
    char ad[50];
    int yas;
    char cinsiyet;
    char hastalik[100];
    int oncelik;  // 1 (yuksek) - 5 (dusuk)
} Hasta;

Hasta hastalar[MAX_HASTA];
int hastaSayisi = 0;

// Recete numarasi uretme fonksiyonu
void receteUret(char receteNo[]) {
    sprintf(receteNo, "RX-%d", rand() % 10000);
}

// Hasta kayit fonksiyonu
void hastaEkle() {
    if (hastaSayisi >= MAX_HASTA) {
        printf("Hasta kapasitesi doldu!\n");
        return;
    }

    Hasta yeni;
    printf("Hasta ID: ");
    scanf("%s", yeni.id);
    printf("Ad: ");
    scanf("%s", yeni.ad);
    printf("Yas: ");
    scanf("%d", &yeni.yas);
    printf("Cinsiyet (E/K): ");
    scanf(" %c", &yeni.cinsiyet);
    printf("Hastalik: ");
    scanf("%s", yeni.hastalik);
    printf("Oncelik (1-5): ");
    scanf("%d", &yeni.oncelik);

    hastalar[hastaSayisi++] = yeni;
    printf("Hasta kaydedildi!\n");
}

// Oncelik sirasina gore hastalari siralama (Bubble Sort)
void oncelikSirala() {
    int i, j;
    for (i = 0; i < hastaSayisi - 1; i++) {
        for (j = 0; j < hastaSayisi - i - 1; j++) {
            if (hastalar[j].oncelik > hastalar[j + 1].oncelik) {
                Hasta temp = hastalar[j];
                hastalar[j] = hastalar[j + 1];
                hastalar[j + 1] = temp;
            }
        }
    }
}

// HL7 formatinda hasta bilgilerini saklama
void hl7Kaydet() {
    FILE *dosya = fopen("hastalar.hl7", "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    fprintf(dosya, "MSH|^~\\&|HASTANE|ACIL SERVIS|SISTEM|20250315||ADT^A01|12345|P|2.5\n");
    for (int i = 0; i < hastaSayisi; i++) {
        fprintf(dosya, "PID|||%s^^^HASTANE^MR||%s||%d|%c|||%s\n",
                hastalar[i].id, hastalar[i].ad, hastalar[i].yas, hastalar[i].cinsiyet, hastalar[i].hastalik);
    }
    fclose(dosya);
    printf("Hasta kayitlari HL7 formatinda kaydedildi!\n");
}

// Hasta listesini gosterme
void hastaListele() {
    printf("\nHASTA LISTESI:\n");
    for (int i = 0; i < hastaSayisi; i++) {
        printf("ID: %s, Ad: %s, Yas: %d, Cinsiyet: %c, Hastalik: %s, Oncelik: %d\n",
               hastalar[i].id, hastalar[i].ad, hastalar[i].yas, hastalar[i].cinsiyet, hastalar[i].hastalik, hastalar[i].oncelik);
    }
}

// Ana fonksiyon
int main() {
    srand(time(NULL));
    int secim;
    while (1) {
        printf("\nHASTANE ACIL SERVIS SISTEMI\n");
        printf("1. Hasta Ekle\n");
        printf("2. Hastalari Listele\n");
        printf("3. Oncelige Gore Sirala\n");
        printf("4. HL7 Formatinda Kaydet\n");
        printf("5. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                hastaEkle();
                break;
            case 2:
                hastaListele();
                break;
            case 3:
                oncelikSirala();
                printf("Hastalar oncelik sirasina gore siralandi!\n");
                break;
            case 4:
                hl7Kaydet();
                break;
            case 5:
                printf("Cikis yapiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }
}
