# ==============================================================================
# Metin2 Lua Core & Lib Unified Makefile - Clang 17 Uyumlu
# ==============================================================================

CC = clang
AR = ar rcu
RANLIB = ranlib

# Cikti dizini (library/liblua/lib)
OUT_DIR = ../lib

# Clang 32-bit derleme bayraklari ve uyarilari susturma
CFLAGS = -m32 -O2 -Wall -pipe -fno-strict-aliasing -I../include -I.
CFLAGS += -Wno-deprecated-declarations -Wno-parentheses -Wno-format-security -Wno-tautological-compare

# 1. CORE (Cekirdek) Dosyalari -> liblua.a
CORE_SRCS = lapi.c lcode.c ldebug.c ldo.c ldump.c lfunc.c lgc.c llex.c lmem.c \
            lobject.c lopcodes.c lparser.c lstate.c lstring.c ltable.c \
            ltests.c ltm.c lundump.c lvm.c lzio.c
CORE_OBJS = $(CORE_SRCS:.c=.o)
TARGET_LUA = $(OUT_DIR)/liblua.a

# 2. LIB (Standart Kutuphaneler) Dosyalari -> liblualib.a
# Dosyalar src/lib altinda oldugu icin yollarini dogrudan belirtiyoruz
LIB_SRCS = lib/lauxlib.c lib/lbaselib.c lib/ldblib.c lib/liolib.c lib/lmathlib.c \
           lib/ltablib.c lib/lstrlib.c lib/loadlib.c
LIB_OBJS = $(LIB_SRCS:.c=.o)
TARGET_LUALIB = $(OUT_DIR)/liblualib.a

# Ana Hedef
all: $(OUT_DIR) $(TARGET_LUA) $(TARGET_LUALIB)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# liblua.a Derlemesi
$(TARGET_LUA): $(CORE_OBJS)
	@echo ">>> liblua.a Olusturuluyor..."
	$(AR) $@ $(CORE_OBJS)
	$(RANLIB) $@

# liblualib.a Derlemesi
$(TARGET_LUALIB): $(LIB_OBJS)
	@echo ">>> liblualib.a Olusturuluyor..."
	$(AR) $@ $(LIB_OBJS)
	$(RANLIB) $@

# .c dosyalarini .o objelerine donusturme
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Temizlik
clean:
	rm -f *.o lib/*.o $(TARGET_LUA) $(TARGET_LUALIB)

dep:
	$(CC) $(CFLAGS) -MM *.c lib/*.c > Depend

-include Depend