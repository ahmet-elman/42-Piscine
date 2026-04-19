# 🚀 42 Havuz (Piscine): Sistem Programlama ve Düşük Seviyeli Yazılım Mühendisliği

### ✍️ 📝 Kişisel Bir Not ve Teşekkür
Bu dokümanın hazırlanmasında yapay zeka desteği kullanılmıştır. Bunun temel sebebi, sadece kod yazmayı değil, yazdığım kodların ve kullandığım komutların arka planındaki mühendislik mantığını daha yapılandırılmış, profesyonel ve anlaşılır bir dille ifade etme isteğimdir.

Yapay zekayı bir "yerime iş yapan araç" olarak değil, öğrendiğim karmaşık konuları (pointer aritmetiği, bellek yönetimi, shell otomasyonu vb.) sentezlememe ve başkalarına daha iyi aktarmama yardımcı olan bir "akıl hocası" olarak konumlandırdım. Bu dokümandaki her bir açıklama, bizzat çözdüğüm ve üzerine kafa yorduğum projelerin bir özetidir.

Öğrenme sürecimi bu şekilde dökümante etmenin, hem benim için bir tekrar mekanizması oluşturduğuna hem de projelerimi inceleyen siz değerli arkadaşlarım için daha şeffaf bir rehber sunduğuna inanıyorum.

Eğer dökümandaki anlatımlarımda, teknik terimlerimde veya mantık yürütmelerimde bir hata ya da eksiklik fark ederseniz şimdiden affınıza sığınırım. Amacım, bu zorlu öğrenme sürecini en şeffaf ve anlaşılır haliyle dökümante etmektir. Hatalarım varsa, bunları birer öğrenme fırsatı olarak görüyor ve geri bildirimlerinizi bekliyorum.

> **⚠️ AKADEMİK DÜRÜSTLÜK VE KULLANIM KLAVUZU**
> Bu rehber, projelerin teknik mantığını kavramak için hazırlanmıştır. Buradaki içerikleri doğrudan kopyalayıp teslim etmek öğrenme sürecinizi baltalar. Gerçek başarı, yazdığınız fonksiyonun bellekte (RAM) yarattığı değişikliği adım adım savunabilmektir.

---

## 🐚 BÖLÜM 1: Shell & Sistem Yönetimi (Özet)
Sistemle kurulan ilk temas ve otomasyon becerileri.

* **Yetki ve Dosya Sistemi:** Unix hiyerarşisinde her şeyin bir dosya olduğu (`everything is a file`) felsefesi. `chmod` ile yetki yönetimi ve `ln` ile dosya bağlama (Hard/Symbolic) teknikleri.
* **Otomasyon (Scripting):** Tekrar eden görevleri `find`, `grep` ve `sed` gibi araçlarla otomatikleştirme. 
    * *Örnek:* `clean` betiği ile sistemdeki gereksiz `*~` ve `#*#` artıklarını tek komutla temizleme.
* **Magic & Versiyon Kontrolü:** Dosyaların gerçek kimliğini `magic bytes` üzerinden tanıma ve `git` ile görünmez dosyaları yönetme disiplini.

---

## 💻 BÖLÜM 2: C Dili ve Bellek Mimarisi (Teknik Detaylar)

C havuzu, donanım ve yazılım arasındaki köprüdür. Bu bölümde soyutlamalardan kurtulup belleğin içine iniyoruz.

### 🧠 2.1 Pointer Aritmetiği ve Bellek Adresleme (C00 - C01)
C dilinin en güçlü ve en tehlikeli özelliği olan pointerlar, bellekteki veri hücrelerinin fiziksel adreslerini tutar.
* **Adres Operatörü (&) ve Dereference (*):** Bir değişkenin bellekteki "ev adresine" gitmek ve o adresteki veriyi değiştirmek.
* **Pointer Zincirleri:** Bir adresi işaret eden başka bir adres (pointer to pointer). Bu yapı, veri yapılarının (Linked List, Trees) temelidir.
* **Pass-by-Reference:** Fonksiyonlara değerin kopyasını değil, kendisini (adresini) göndererek bellekten tasarruf etme ve doğrudan manipülasyon sağlama.

### 📋 2.2 Karakter Dizileri ve Null Terminating Mantığı (C02 - C03)
C'de "String" diye bir veri tipi yoktur; sadece yan yana dizilmiş karakterler (`char *`) vardır.
* **\0 (Null Terminator):** Bellekteki karakter dizisinin nerede bittiğini belirleyen hayati byte. Bu byte unutulduğunda programın belleğin rastgele yerlerini okumasına (Segfault) yol açar.
* **Bellek Güvenliği:** `ft_strcpy` ve `ft_strlcpy` arasındaki farkı anlayarak, hedef belleğin (buffer) boyutunu aşmadan veri taşıma (buffer overflow önleme).

### 🔢 2.3 Veri Dönüşümleri ve Algoritmik Verimlilik (C04 - C05)
* **ASCII ve Sayısal Dönüşüm:** Ekranda gördüğümüz '4' karakteri ile matematikteki 4 sayısı arasındaki farkı `ft_atoi` (ASCII to Integer) fonksiyonuyla yönetmek.
* **Recursion (Özyineleme) ve Stack Kullanımı:** Bir fonksiyon her kendi çağrıldığında belleğin **Stack** bölgesinde yeni bir çerçeve (frame) açılır. Rekürsiyonun derinliği, bellek yönetimiyle doğrudan ilişkilidir.
* **Base Sistemleri:** Veriyi 10'luk tabandan 2'lik (Binary) veya 16'lık (Hex) tabana dönüştürerek bilgisayarın ham veri dilini konuşma.

### 🏗️ 2.4 Dinamik Bellek Yönetimi: Heap ve Malloc (C07)
Bu aşama, sabit boyutlu dizilerden (Static Arrays) kurtulup, ihtiyaca göre şekillenen programlar yazma aşamasıdır.
* **Malloc (Memory Allocation):** İşletim sisteminden çalışma zamanında (runtime) bellek alanı kiralamak.
* **Bellek Sızıntıları (Memory Leaks):** Kiralanan her belleğin `free` fonksiyonu ile iade edilmemesi durumunda programın RAM'i tüketmesi.
* **Bellek Tahsisi Kontrolü:** `malloc`'un başarısız olma ihtimaline karşı (`NULL` kontrolü) kodun dayanıklılığını (robustness) artırma.

---

## 💡 Mühendislik Prensipleri ve Standartlar

1.  **Norminette:** 42'nin katı kural seti (25 satır sınırı, 5 fonksiyon sınırı vb.), kodun sadece çalışmasını değil, başkaları tarafından kolayca okunup geliştirilebilmesini (maintainability) sağlar.
2.  **Edge Case Analizi:** "Input boş gelirse ne olur?", "Bellek yetmezse ne olur?" gibi uç durumları yönetmek, amatör programcıyı mühendisten ayıran çizgidir.
3.  **Hata Ayıklama (Debugging):** `printf` ile adım adım bellek takibi yapmak ve hataları (bugs) sistematik olarak yok etmek.

---
*Bu rehber, 42 Piscine yolculuğunun teknik derinliğini ve bir öğrencinin sistemlere olan yaklaşımını temsil eder.*