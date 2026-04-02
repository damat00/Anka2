# ==============================================================================
# Metin2 Lua Hierarchy Makefile
# ==============================================================================

LUA= .

# Ana hedefler
all clean co klean: dirs
	@echo -e "\033[0;34m[liblua] Kaynak dosyalar derleniyor...\033[0m"
	@cd src && $(MAKE) $@

# Kütüphane klasörünü oluştur
dirs:
	@mkdir -p lib

# Temizlik
clean:
	@cd src && $(MAKE) clean
	@rm -rf lib/*.a