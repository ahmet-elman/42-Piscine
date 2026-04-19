# 🧩 Rush00

Rush00, 42 Piscine sürecinde yapılan ilk grup projelerinden biridir.  
Amaç, verilen ölçülere göre karakterlerden oluşan bir dikdörtgen çizmek ve takım çalışmasıyla temel C mantığını uygulamaktır.

---

## 📌 Projenin Amacı

- Fonksiyon kullanımı öğrenmek  
- Parametre ile kontrol edilen çıktı üretmek  
- Ekip içinde görev paylaşımı yapmak  
- Basit ama düzenli kod yazmak  

---

## ⚙️ Nasıl Çalışır?

Program `rush(x, y)` fonksiyonu ile çalışır:

- `x` → genişlik  
- `y` → yükseklik  

Fonksiyon, bu değerlere göre bir dikdörtgen çizer.

---

## 🧠 Mantık

Dikdörtgen 3 temel parçadan oluşur:

1. Üst satır  
2. Orta satırlar  
3. Alt satır  

Her satırda:
- köşeler farklı karakter  
- kenarlar farklı karakter  
- iç kısım boşluk (`' '`)  

---

## 🔤 Örnek Çıktı

```text
rush(5, 3)

o---o
|   |
o---o

🧪 Test Etme
gcc *.c && ./a.out
```
