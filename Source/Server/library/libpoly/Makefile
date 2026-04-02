# ==============================================================================
# Metin2 Poly Library - Clang 17 & C++20 Uyumlu Makefile
# ==============================================================================

CXX	= clang++
BIN = ./libpoly.a

# --- Derleme Bayrakları ---
# -m32: 32-bit mimari uyumu
# -fno-strict-aliasing: Bellek optimizasyon hatalarını önler
CFLAGS  = -m32 -Wall -O2 -pipe -fno-exceptions -fno-rtti
CFLAGS += -std=c++20 -fno-strict-aliasing -Wno-enum-constexpr-conversion

# Gereksiz uyarıları sustur
CFLAGS += -Wno-unused-variable -Wno-unused-function

LIBS =
OBJFILES = Base.o Poly.o SymTable.o Symbol.o

# --- Kurallar ---
default:
	$(MAKE) $(BIN)

$(BIN): $(OBJFILES)
	@if [ -f $(BIN) ]; then rm -f $(BIN); fi
	ar cru $(BIN) $(OBJFILES) $(LIBS)
	ranlib $(BIN)
	chmod 700 $(BIN)
	@echo -e "\033[0;32m[libpoly] Derleme tamamlandi.\033[0m"

clean:
	rm -f *.o
	rm -f $(BIN)
	rm -f Depend

dep:
	@touch Depend
	$(CXX) $(CFLAGS) -MM *.cc > Depend

# .cc dosyalarını objeye dönüştürme kuralı
%.o: %.cc
	$(CXX) $(CFLAGS) -c $< -o $@

sinclude Depend