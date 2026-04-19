# 🛠️ 42 Shell Projeleri: Sistem Mühendisliği ve Otomasyon Rehberi

> **⚠️ ÖNEMLİ AKADEMİK DÜRÜSTLÜK NOTU:**
> Bu çalışma, 42 Havuz (Piscine) sürecindeki Shell projelerinin mantığını anlamanız için bir **rehber ve farklı bir bakış açısı** sunmak amacıyla hazırlanmıştır. 
> 
> **Lütfen Dikkat:** Buradaki açıklamaları veya kod yapılarını doğrudan kopyalayıp kendi projenizmiş gibi sunmak, 42'nin temel eğitim felsefesine aykırıdır ve gerçek bir mühendis olma yolundaki öğrenme sürecinizi baltalar. Bu dokümanı bir "kopya kağıdı" olarak değil, konuyu kavramanızı sağlayacak bir "yol haritası" olarak kullanın. Unutmayın, asıl başarı projeyi geçmek değil, projenin arkasındaki mantığı savunabilmektir.

### 📝 Kişisel Bir Not ve Teşekkür
Bu dokümanın hazırlanmasında yapay zeka desteği kullanılmıştır. Bunun temel sebebi, sadece kod yazmayı değil, yazdığım kodların ve kullandığım komutların arka planındaki mühendislik mantığını daha yapılandırılmış, profesyonel ve anlaşılır bir dille ifade etme isteğimdir.

Yapay zekayı bir "yerime iş yapan araç" olarak değil, öğrendiğim karmaşık konuları (pointer aritmetiği, bellek yönetimi, shell otomasyonu vb.) sentezlememe ve başkalarına daha iyi aktarmama yardımcı olan bir "akıl hocası" olarak konumlandırdım. Bu dokümandaki her bir açıklama, bizzat çözdüğüm ve üzerine kafa yorduğum projelerin bir özetidir.

Öğrenme sürecimi bu şekilde dökümante etmenin, hem benim için bir tekrar mekanizması oluşturduğuna hem de projelerimi inceleyen siz değerli arkadaşlarım için daha şeffaf bir rehber sunduğuna inanıyorum.

Eğer dökümandaki anlatımlarımda, teknik terimlerimde veya mantık yürütmelerimde bir hata ya da eksiklik fark ederseniz şimdiden affınıza sığınırım. Amacım, bu zorlu öğrenme sürecini en şeffaf ve anlaşılır haliyle dökümante etmektir. Hatalarım varsa, bunları birer öğrenme fırsatı olarak görüyor ve geri bildirimlerinizi bekliyorum.

---

## 🤖 Yapay Zeka Özet Notu
Bu rehber, Shell 00'dan Shell 09'a kadar olan süreçteki temel Unix yetkinliklerini birleştirmek için yapay zeka ile aldığım notları özetleyrek oluşturulmuştur. Teknik detaylar, sistem mimarisi ve otomasyon prensipleri üzerine odaklanmıştır.

---

## 📂 Shell 00: Dosya Sisteminin Anatomisi
Sistemde sadece "var olmak" yetmez, sistemi "yönetmek" gerekir.
* **İzinler (chmod):** `rwx` (Read, Write, Execute) kavramı. Bir dosyanın kimin tarafından çalıştırılabileceğini belirlemek sistem güvenliğinin temelidir.
* **Zaman Damgaları (touch):** Dosyaların oluşturulma ve erişim tarihlerini manipüle etmek, sistem logları ve otomatik yedekleme sistemleri için kritiktir.
* **Bağlantılar (Links):** Hard link (dosyanın kendisi) ve Symbolic link (dosyaya giden kısa yol) arasındaki farkı anlamak, disk alanını yönetmek için şarttır.

---

## 🔍 Shell 01: Çevre Yönetimi ve Filtreleme
Sistemin sizi nasıl tanıdığını ve komutları nerede aradığını keşfedersiniz.
* **Env & Export:** `PATH` gibi çevre değişkenleri, terminalin bir komutu yazdığınızda hangi klasörlere bakacağını belirler.
* **Kullanıcı Grupları:** Bir kullanıcının hangi yetki gruplarına (`groups`) ait olduğunu sorgulamak, kurumsal sistem yönetiminin temelidir.

---

## 🧹 Shell 02 - 04: Otomasyon ve Veri Temizliği
Büyük projelerde "gürültüyü" (noise) yok etmek bir mühendislik disiplinidir.
* **Akıllı Temizlik:** Gereksiz geçici dosyaları ayıklamak için `find` kullanılır.
* **Uygulama Örneği (`clean` dosyası):** `find . -type f \( -name '*~' -o -name '#*#' \) -print -delete` 
  * **Mühendislik Analizi:** Bu komut, dizin içindeki geçici editör yedeklerini (`*~`) ve çakışma dosyalarını (`#*#`) bulur, listeler ve kalıcı olarak siler. 

---

## 📜 Shell 05 - 08: Metin Manipülasyonu ve Boru Hatları (Pipes)
Unix felsefesinin kalbi: *"Küçük araçları birleştirerek devasa işler yap."*
* **Boru Hattı (Pipes):** `|` sembolü, bir komutun çıktısını diğerinin girdisi yaparak veri akışını yönetir.
* **Veri Düzenleme:** Dosya içindeki hatalı verileri (Örn: "A NEW H0PE" metnindeki karakter hataları) toplu halde düzeltme yeteneği.
* **Git İzleme (`git_ignore.sh` dosyası):** `git ls-files --exclude-standard --ignored --others`
  * **Mühendislik Analizi:** Projenin temiz kalmasını sağlar; standart dışı, görmezden gelinen veya henüz Git'e eklenmemiş dosyaları saniyeler içinde listeler.

---

## 🎩 Shell 09: Dosya İmzaları (The Magic Module)
Bir dosyanın gerçek kimliğini "uzantısına" bakarak değil, "içeriğine" bakarak anlarız.
* **Magic Veritabanı:** İşletim sistemi, bir dosyanın ilk byte'larına bakarak onun bir resim mi, metin mi yoksa çalıştırılabilir bir dosya mı olduğunu anlar.
* **Özel Dosya Tanımlama (`ft_magic` dosyası):** `41 string 42 42 file`
  * **Mühendislik Analizi:** Bu kural, dosyanın 41. karakterinden (offset) itibaren "42" değerini arar.Eğer bulursa, bu dosyayı sistem için özel bir tip olarak tanımlar. 

---

## 💡 Mühendislik İlkeleri ve Altın Kurallar
1.  **Önce Anla, Sonra Uygula:** Bir komutu kopyalamadan önce her bir parametresinin (`-type f`, `-name` vb.) ne işe yaradığını `man` (manual) sayfalarından okuyun.
2.  **Yıkıcı Komutlara Dikkat:** `delete` gibi komutları kullanmadan önce her zaman çıktıları `ls` veya `print` ile test edin.
3.  **Norm Kuralları:** Yazdığınız her script, 42 standartlarına (Norm) uygun olmalıdır. Okunabilirlik, çalışabilirlik kadar önemlidir.

---
*Bu rehber, 42 eğitim modelinin "Peer-to-Peer" ruhuna uygun olarak, öğrenme sürecini desteklemek amacıyla hazırlanmıştır.*