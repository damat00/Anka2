# ==============================================================================
# Metin2 TheCore Library - Clang 17 & C++20 Uyumlu Makefile
# ==============================================================================

CC	= clang++
BIN_DIR = ../lib
BIN     = $(BIN_DIR)/libthecore.a
INCLUDE = ../include

# --- Derleme Bayrakları ---
# -m32: 32-bit mimari uyumu
# -fno-strict-aliasing: Pointer islemlerinde bellek hatalarini onler
# -D_THREAD_SAFE: Sinyal ve loglama islemlerinin guvenligi icin
CFLAGS  = -m32 -Wall -O2 -pipe -g -I$(INCLUDE) -D_THREAD_SAFE
CFLAGS += -std=c++20 -fno-strict-aliasing -Wno-enum-constexpr-conversion

# Modern derleyici uyarilarini eski kodlar icin susturuyoruz
CFLAGS += -Wno-unused-variable -Wno-unused-function -Wno-deprecated-declarations

LIBS    = 

OBJFILES = socket.o fdwatch.o buffer.o signal.o log.o utils.o \
	kstbl.o hangul.o heart.o main.o tea.o des.o gost.o memcpy.o

# --- Kurallar ---
default:
	$(MAKE) $(BIN)

$(BIN): $(OBJFILES)
	@if [ ! -d $(BIN_DIR) ]; then mkdir -p $(BIN_DIR); fi
	@if [ -f $(BIN) ]; then rm -f $(BIN); fi
	ar cru $(BIN) $(OBJFILES) $(LIBS)
	ranlib $(BIN)
	chmod 700 $(BIN)
	@echo -e "\033[0;32m[libthecore] Derleme tamamlandi.\033[0m"

clean:
	rm -f *.o
	rm -f $(BIN)
	rm -f Depend

dep:
	@touch Depend
	$(CC) $(CFLAGS) -MM *.c > Depend

# Pattern rule for .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Memcpy test kurali (Opsiyonel)
memcpy: memcpy.o utils.o log.o
	$(CC) $(CFLAGS) -c -D__MAIN__ memcpy.c
	$(CC) $(CFLAGS) -o memcpy memcpy.o utils.o log.o

sinclude Depend