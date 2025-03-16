# Hastane Acil Servis Sistemi

Bu proje, bir hastanenin acil servis sistemini yönetmek için geliştirilmiştir. C dili kullanılarak yazılmıştır ve hasta kayıtlarını HL7 formatında saklamaktadır.

## Özellikler
- Hasta ekleme
- Hastaları listeleme
- Öncelik sırasına göre hastaları sıralama
- HL7 formatında hasta kayıtlarını dosyaya kaydetme
- Menü tabanlı kullanıcı arayüzü

## Kullanılan Teknolojiler
- C Programlama Dili
- Standart Kütüphaneler: `stdio.h`, `stdlib.h`, `string.h`, `time.h`

## Kurulum ve Çalıştırma
1. **Kaynak kodu klonlayın:**
   ```sh
   git clone <repo-link>
   cd <repo-folder>
   ```
2. **Derleme:**
   ```sh
   gcc hospital_emergency.c -o hospital_emergency
   ```
3. **Çalıştırma:**
   ```sh
   ./hospital_emergency
   ```

## Kullanım
Program çalıştırıldığında aşağıdaki menü görüntülenecektir:
```
HASTANE ACİL SERVİS SİSTEMİ
1. Hasta Ekle
2. Hastaları Listele
3. Önceliğe Göre Sırala
4. HL7 Formatında Kaydet
5. Çıkış
```
Kullanıcı bir seçenek girerek ilgili işlemi gerçekleştirebilir.

## HL7 Formatı
Hasta kayıtları `hastalar.hl7` dosyasına HL7 standardında kaydedilmektedir.
Dosya içeriği örnek:
```
MSH|^~\&|HASTANE|ACIL SERVIS|SISTEM|20250315||ADT^A01|12345|P|2.5
PID|||12345^^^HASTANE^MR||Ali Veli||25|E|||Grip
```

## Katkıda Bulunma
- Projeye katkıda bulunmak için pull request gönderebilirsiniz.
- Sorunlar için GitHub Issues bölümünü kullanabilirsiniz.

## Lisans
Bu proje açık kaynak olup MIT lisansı ile sunulmaktadır.

