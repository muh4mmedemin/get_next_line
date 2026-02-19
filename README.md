# 📖 get_next_line

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" />
  <img src="https://img.shields.io/badge/School-42%20Istanbul-darkblue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/BUFFER__SIZE-42-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Grade-✓-brightgreen?style=for-the-badge" />
</p>

---

## 🇬🇧 English

### 📖 About

**get_next_line** is a 42 School project that implements a function to read a file descriptor **line by line**. Each call to `get_next_line()` returns the next line from the file (including the `\n` character), making it extremely useful for parsing files, reading user input, or processing data streams in C.

The function uses a **static variable** to preserve the leftover buffer between successive calls, ensuring no data is lost between reads.

### 🧠 How It Works

```
┌──────────────────────────────────────────────────┐
│                  get_next_line(fd)                │
│                                                  │
│  1. Check if there's leftover data in 'temp'     │
│  2. Read BUFFER_SIZE bytes from fd into 'buf'    │
│  3. Append buf to 'line' using ft_strjoin        │
│  4. If '\n' found → split line & save remainder  │
│  5. Return the line (with '\n')                  │
│  6. If EOF reached → return remaining data       │
│  7. Next call → start from saved remainder       │
└──────────────────────────────────────────────────┘
```

### 📂 Files

| File | Description |
|------|-------------|
| `get_next_line.c` | Main function: `get_next_line()`, `read_file()`, `create_line()`, `save_after_n()` |
| `get_next_line_utils.c` | Helper functions: `ft_strlen()`, `ft_strchr()`, `ft_strjoin()`, `ft_strdup()` |
| `get_next_line.h` | Header file with prototypes and `BUFFER_SIZE` definition |

### 📦 Function Prototypes

```c
// Main function — returns the next line from fd (including '\n')
char    *get_next_line(int fd);
```

#### Internal Functions

| Function | Description |
|----------|-------------|
| `read_file(fd, temp)` | Reads from fd and builds the full line buffer |
| `create_line(line)` | Extracts the line up to `\n` and frees the original |
| `save_after_n(line, temp)` | Saves the remaining data after `\n` into the static buffer |

#### Utility Functions

| Function | Description |
|----------|-------------|
| `ft_strlen(s)` | Returns the length of a string |
| `ft_strchr(s, c)` | Locates the first occurrence of `c` in `s` |
| `ft_strjoin(s1, s2)` | Concatenates `s1` and `s2` into a new string (frees `s1`) |
| `ft_strdup(s)` | Duplicates a string up to `\n` or `\0` |

### ⚙️ Usage

#### Compile

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

> 💡 You can change `BUFFER_SIZE` at compile time. Default is **42**.

#### Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

#### Output

```
$ echo -e "Hello\nWorld\n42 Istanbul" > test.txt
$ ./gnl
Hello
World
42 Istanbul
```

### 🔑 Key Concepts

| Concept | Explanation |
|---------|-------------|
| **Static Variable** | `static char temp[BUFFER_SIZE + 1]` preserves leftover data between function calls |
| **BUFFER_SIZE** | The number of bytes read in each `read()` call — configurable at compile time |
| **Dynamic Memory** | Lines are allocated with `malloc()` — caller must `free()` them |
| **File Descriptor** | Works with any valid fd (files, stdin, pipes, sockets) |

### ⚠️ Return Values

| Return | Condition |
|--------|-----------|
| `char *` (line with `\n`) | A line was successfully read |
| `char *` (line without `\n`) | Last line of file (no trailing newline) |
| `NULL` | EOF reached or error (invalid fd, BUFFER_SIZE ≤ 0) |

---

## 🇹🇷 Türkçe

### 📖 Hakkında

**get_next_line**, 42 Okulu'nun projelerinden biri olup bir dosya tanımlayıcısından (file descriptor) **satır satır** okuma yapan bir fonksiyon implementasyonudur. Her `get_next_line()` çağrısı dosyadan bir sonraki satırı (`\n` karakteri dahil) döndürür. Bu fonksiyon, dosya ayrıştırma, kullanıcı girdisi okuma veya C'de veri akışlarını işleme için son derece kullanışlıdır.

Fonksiyon, ardışık çağrılar arasında artan tampon verilerini korumak için **statik değişken** kullanır ve okumalar arasında hiçbir verinin kaybolmamasını sağlar.

### 🧠 Nasıl Çalışır

```
┌──────────────────────────────────────────────────────┐
│                  get_next_line(fd)                    │
│                                                      │
│  1. 'temp' içinde kalan veri var mı kontrol et       │
│  2. fd'den BUFFER_SIZE bayt oku ve 'buf'a yaz        │
│  3. buf'ı ft_strjoin ile 'line'a ekle                │
│  4. '\n' bulunursa → satırı böl & kalanı kaydet      │
│  5. Satırı döndür ('\n' ile birlikte)                │
│  6. EOF'a ulaşılırsa → kalan veriyi döndür           │
│  7. Sonraki çağrı → kaydedilen kalandan başla        │
└──────────────────────────────────────────────────────┘
```

### 📂 Dosyalar

| Dosya | Açıklama |
|-------|----------|
| `get_next_line.c` | Ana fonksiyon: `get_next_line()`, `read_file()`, `create_line()`, `save_after_n()` |
| `get_next_line_utils.c` | Yardımcı fonksiyonlar: `ft_strlen()`, `ft_strchr()`, `ft_strjoin()`, `ft_strdup()` |
| `get_next_line.h` | Prototiplerin ve `BUFFER_SIZE` tanımının bulunduğu başlık dosyası |

### 📦 Fonksiyon Prototipleri

```c
// Ana fonksiyon — fd'den bir sonraki satırı döndürür ('\n' dahil)
char    *get_next_line(int fd);
```

#### Dahili Fonksiyonlar

| Fonksiyon | Açıklama |
|-----------|----------|
| `read_file(fd, temp)` | fd'den okur ve tam satır tamponunu oluşturur |
| `create_line(line)` | `\n`'e kadar olan satırı çıkarır ve orijinali serbest bırakır |
| `save_after_n(line, temp)` | `\n`'den sonraki kalan veriyi statik tampona kaydeder |

#### Yardımcı Fonksiyonlar

| Fonksiyon | Açıklama |
|-----------|----------|
| `ft_strlen(s)` | Bir stringin uzunluğunu döndürür |
| `ft_strchr(s, c)` | `s` içinde `c`'nin ilk geçtiği yeri bulur |
| `ft_strjoin(s1, s2)` | `s1` ve `s2`'yi yeni bir stringe birleştirir (`s1`'i serbest bırakır) |
| `ft_strdup(s)` | Bir stringi `\n` veya `\0`'a kadar kopyalar |

### ⚙️ Kullanım

#### Derleme

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

> 💡 `BUFFER_SIZE` derleme zamanında değiştirilebilir. Varsayılan değer **42**'dir.

#### Örnek

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

#### Çıktı

```
$ echo -e "Merhaba\nDünya\n42 Istanbul" > test.txt
$ ./gnl
Merhaba
Dünya
42 Istanbul
```

### 🔑 Temel Kavramlar

| Kavram | Açıklama |
|--------|----------|
| **Statik Değişken** | `static char temp[BUFFER_SIZE + 1]` fonksiyon çağrıları arasında kalan veriyi korur |
| **BUFFER_SIZE** | Her `read()` çağrısında okunan bayt sayısı — derleme zamanında ayarlanabilir |
| **Dinamik Bellek** | Satırlar `malloc()` ile ayrılır — çağıran taraf `free()` ile serbest bırakmalıdır |
| **Dosya Tanımlayıcı** | Herhangi bir geçerli fd ile çalışır (dosyalar, stdin, pipe'lar, soketler) |

### ⚠️ Dönüş Değerleri

| Dönüş | Durum |
|-------|-------|
| `char *` (`\n` ile satır) | Bir satır başarıyla okundu |
| `char *` (`\n` olmadan satır) | Dosyanın son satırı (sonda newline yok) |
| `NULL` | EOF'a ulaşıldı veya hata (geçersiz fd, BUFFER_SIZE ≤ 0) |

---

## 👤 Author / Yazar

---

## 📝 License / Lisans

This project is part of the 42 School curriculum.

Bu proje 42 Okulu müfredatının bir parçasıdır.
