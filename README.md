<!-- Proje Başlığı ve Açıklama -->
<h1 align="center">42 - Minishell ⌨️</h1>

<p align="center">
Bu proje, temel bir komut satırı kabuğu (shell) oluşturmayı amaçlar. Kabuk, kullanıcı girdilerini işleyerek komutları çalıştırır, dosya yönlendirmesi ve boru (pipe) işlemleri yapar. Minishell, temel kabuk işlevlerini yerine getirerek kabuğun nasıl çalıştığını anlamak için harika bir araçtır.
</p>

<!-- Proje Logosu veya Görseli -->
<p align="center">
  <a target="blank"><img src="https://i.hizliresim.com/sx4d620.png" height="150" width="150" /></a>
</p>

## Projenin Amacı 🎯

Minishell projesi, basit bir UNIX benzeri kabuk oluşturmayı hedefler. Kullanıcı girdilerini alma ve analiz etme, komutları çalıştırma, dosya yönlendirmesi ve boru işlemleri gibi temel kabuk işlevlerini içerir. Bu proje, C dilinde sistem çağrıları, bellek yönetimi ve dize işlemleri gibi konularda derinlemesine bilgi edinmeyi amaçlar.

## Kullanım Senaryoları 🖥️

Minishell, standart kabuğa benzer şekilde çalışır ve çeşitli işlevleri destekler. Bazı kullanım örnekleri şunlardır:

- **Komut Çalıştırma**: Basit komutları çalıştırmak için yazın ve Enter tuşuna basın.
  - Örnek: `ls -l`
- **Dosya Yönlendirmesi**: Çıktıyı bir dosyaya yönlendirmek için '>' veya '>>', girdiyi bir dosyadan almak için '<' kullanın.
  - Örnek: `echo "Merhaba Dünya" > output.txt`
- **Boru (Pipe) İşlemleri**: Bir komuttan gelen çıktıyı başka bir komuta yönlendirmek için '|' kullanın.
  - Örnek: `ls -l | grep minishell`
- **Komut Sonuçlarını Kontrol Etme**: '$?' ifadesi, son çalıştırılan komutun çıkış durumunu gösterir.
  - Örnek: `ls -l; echo $?` (Bu, son komutun başarılı olup olmadığını kontrol eder.)
- **Arka Plan İşlemleri**: Bir komutu arka planda çalıştırmak için '&' kullanın.
  - Örnek: `./script.sh &`

## Gereksinimler 📋

Minishell projesini çalıştırmak ve geliştirmek için aşağıdaki gereksinimlerin sağlanması gerekir:

- **Unix tabanlı bir işletim sistemi** (Linux, macOS) veya bir terminal emülatörü.
- **GCC derleyici**: Projeyi derlemek için GNU C Compiler kullanmanız gerekmektedir.
- **Bash veya benzeri bir kabuk**: Projenin test edilmesi ve komutların çalıştırılması için kullanılacaktır.
- **C Kütüphaneleri**: Projenin işleyişi için gerekli olan standart C kütüphaneleri ve sistem çağrılarına erişim.
- **Make aracı**: Projeyi derlemek ve yönetmek için Makefile kullanılacaktır.

## Proje İçeriği 📁

Proje, ana minishell işlevinin yanı sıra çeşitli yardımcı fonksiyonlar ve yapıları içerir. İşte ana bileşenler:

- **Makefile**: Projeyi derlemek için kullanılan derleme dosyası.
- **minishell.h**: Proje için başlık dosyası, çeşitli yapı tanımları ve fonksiyon prototiplerini içerir.
- **minishell.c**: Ana kabuk işlevinin bulunduğu dosya.
- **executor.c**: Komutların yürütülmesi ve yönlendirme işlemlerini ele alan dosya.
- **parser.c**: Kullanıcı girdisini analiz eden ve komutları işleyen dosya.
- **signals.c**: Sinyal işleme ve kontrol işlemlerini yöneten dosya.
- **utils.c**: Yardımcı fonksiyonları içeren dosya, dize işlemleri ve bellek yönetimi gibi konuları kapsar.

## Katkıda Bulunma ve Geri Bildirim 🤝

Projeye katkıda bulunmak veya geri bildirim sağlamak isterseniz, aşağıdaki adımları takip edin:

1. Proje deposunu forklayın.
2. Değişikliklerinizi yapın ve bir "pull request" gönderin.
3. Geri bildirim için GitHub üzerinden bir "issue" açın veya tartışmalara katılın.

## Lisans 📜

Bu proje MIT Lisansı ile lisanslanmıştır. Proje kodunu özgürce kullanabilir, değiştirebilir ve dağıtabilirsiniz. Lisans şartları hakkında daha fazla bilgi için `LICENSE` dosyasını inceleyin.

---

Bu README dosyası Derya ACAR tarafından hazırlanmıştır.
