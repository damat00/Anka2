import json
from pathlib import Path
import datetime

MEMORY_FILE = Path(r"E:\Anka2\OpenCodeMemory.json")

with open(MEMORY_FILE, "r", encoding="utf-8") as f:
    mem = json.load(f)

mem.setdefault("knowledge_base", {})

mem["knowledge_base"]["terminology"] = {
    "Binding": "İki farklı dili veya kütüphaneyi birbirine bağlayan köprü (Örn: C++ fonksiyonlarını Lua veya Python'da kullanılabilir hale getiren questlua_*.cpp dosyaları).",
    "Wrapper": "Mevcut karmaşık bir kodu sarmalayarak ona daha basit ve standart bir arayüz kazandıran yapı (Örn: DBManager'ın AsyncSQL'i sarmalaması).",
    "Boilerplate": "İş mantığına doğrudan katkısı olmayan ama yapının çalışması için sürekli tekrar yazılması gereken kalıp kodlar.",
    "Refactoring": "Kodun dışarıya verdiği çıktıyı değiştirmeden, iç yapısını daha temiz, okunabilir ve performanslı hale getirmek.",
    "Middleware": "İki farklı sistem (örn: Game Server ile DB Server) arasında köprü veya tercüman görevi gören ara katman yazılımları.",
    "Mocking": "Özellikle test aşamalarında gerçek sistemlerin (veritabanı veya ağ) yerini alan sahte/taklit objeler oluşturmak.",
    "Overhead": "Bir işlemin asıl amacı dışında tükettiği ekstra sistem kaynağı (Örn: LZO şifrelemesinin CPU'ya bindirdiği ek yük)."
}

log = mem.get("update_log", [])
log.append({"date": datetime.datetime.now().strftime("%Y-%m-%d"), "action": "Added software engineering terminology and their project-specific mappings to knowledge_base."})
mem["update_log"] = log

with open(MEMORY_FILE, "w", encoding="utf-8") as f:
    json.dump(mem, f, indent=2, ensure_ascii=False)
    
print("Terminology added to memory.")
