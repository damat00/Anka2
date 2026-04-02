# ==============================================================================
# Metin2 SQL Library - Clang 17 & C++20 Uyumlu Makefile
# ==============================================================================

CXX	= clang++
BIN = ./libsql.a

# --- Dizin ve Kutuphane Yapilandirmasi ---
# MySQL/MariaDB baslik dosyalarinin yerini dogrulayin
IFLAGS = -I/usr/local/include -I/usr/local/include/mysql

# --- Derleme Bayrakları ---
# -m32: 32-bit mimari uyumu
# -D_THREAD_SAFE: SQL sorgularinin thread guvenligi icin sart
CFLAGS  = $(IFLAGS) -m32 -Wall -O2 -pipe -D_THREAD_SAFE -fno-exceptions
CFLAGS += -std=c++20 -fno-strict-aliasing -Wno-enum-constexpr-conversion

# Gereksiz uyarilari sustur (SQL sorgu yapilarindaki eski kodlar icin)
CFLAGS += -Wno-unused-variable -Wno-unused-function -Wno-parentheses

LIBS =
OBJFILES = AsyncSQL.o Semaphore.o Tellwait.o Statement.o

# --- Kurallar ---
default:
	$(MAKE) $(BIN)

$(BIN): $(OBJFILES)
	@if [ -f $(BIN) ]; then rm -f $(BIN); fi
	ar cru $(BIN) $(OBJFILES) $(LIBS)
	ranlib $(BIN)
	chmod 700 $(BIN)
	@echo -e "\033[0;32m[libsql] Derleme tamamlandi.\033[0m"

clean:
	rm -f *.o
	rm -f $(BIN)
	rm -f Depend

dep:
	@touch Depend
	$(CXX) $(CFLAGS) -MM *.cpp > Depend

# .cpp dosyalarini objeye donusturme kuralı
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

sinclude Depend