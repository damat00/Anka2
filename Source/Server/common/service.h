/************************************************************
*                ANKA2 SYSTEM INFO GAME                     *
*-----------------------------------------------------------*
*   File Name : ../../common/service.h                      *
*   Author    : BestStudio                                  *
*   Version   : 3.1.0                                       *
*   Date      : 03-11-2025                                  *
*   Update    : 04-12-2025                                  *
*-----------------------------------------------------------*
*           Anka2Project Configuration Definition           *
************************************************************/

#ifndef __INC_SERVICE_H__
#define __INC_SERVICE_H__
#pragma once

enum eCommonDefines {
	//DEFINES						//VALUE				//AÇIKLAMA											// VARSAYILAN
	CONQUEROR_MAX_LEVEL				= 30,				// Maksimum şampiyon seviyesi							// 30		[ENABLE_YOHARA_SYSTEM]
	DROPABLE_GOLD_LIMIT				= 100000,			// Düşürülebilir altın limiti						// 1000
	SB_NEED_EXP						= 20000,			// Becerikitabı için gereken deneyim				// 20000
	SB_C_NEED_EXP					= 20000,			// 9. beceriler için gereken deneyim				// 20000
};

#define CLIENT_VERSION		"ext_180923"			// Client sürüm etiketidir; sunucu–client uyumluluğunu kontrol eder.

#define ENABLE_ANTI_EXP								// Anti exp sistemini etkinleştir;
#define ENABLE_LEVEL_INT							// Seviye byte'dan int'e taşındı (maksimum seviye 300+);
#define ENABLE_GOLD_LIMIT							// Altın limiti 20kkk'ya taşındı;
#define ENABLE_PET_SYSTEM							// Pet sistemini etkinleştir;
#define ENABLE_DICE_SYSTEM							// Zar sistemini etkinleştir: mob kral veya boss ise ve partideyseniz, düşen eşya rastgele zar ile belirlenir;
#define ENABLE_GLOBAL_CHAT							// Bayrak ile global sohbeti etkinleştir;
#define ENABLE_STACK_LIMIT							// Eşya yığın limiti 2000'e taşındı;
#define ENABLE_RENEWAL_CUBE							// Yenileme küp sistemini etkinleştir;
#define ENABLE_MOUNT_SYSTEM							// Binek sistemi etkinleştir;
#define ENABLE_MOUNT_PET_SKIN						// Binek ve pet için skin etkinleştir;
#define ENABLE_MOB_DROP_INFO						// Mob ve taş düşürme penceresini etkinleştir;
#define ENABLE_SHOW_MOB_INFO						// Mob seviyesi ve saldırganlık bilgisini etkinleştir;
#define ENABLE_RENEWAL_QUEST						// Resmi sunucularla aynı yeni görev sayfası;
#define ENABLE_CHANGE_CHANNEL						// Kanal değiştirme seçeneğini etkinleştir;
#define ENABLE_MESSENGER_TEAM						// Mesajlaşmada takım listesini etkinleştir;
#define ENABLE_PENDANT_SYSTEM						// Resmi pendant sistemini etkinleştir;
#define ENABLE_DESTROY_DIALOG						// Eşyaları düşürdüğünüzde yok etme seçeneğini etkinleştir;
#define ENABLE_SORT_INVENTORY						// Envanter ve özel envanterdeki eşyalar sıralanabilir;
#define ENABLE_PARTY_POSITION						// Parti üyeleri haritada görülebilir;
#define ENABLE_RENEWAL_SHOPEX						// Daha fazla sayfa ile yenileme shopex;
#define ENABLE_VIEW_CHEST_DROP						// Oyuncular sandığın içindekileri görebilir;
#define ENABLE_MESSENGER_BLOCK						// Oyuncu engellemeyi etkinleştir;
#define ENABLE_COINS_INVENTORY						// Envanterde yeni para birimi eklendi;
#define ENABLE_QUICK_SELL_ITEM						// Dükkanda eşyalar için hızlı satışı etkinleştir;
#define ENABLE_EXTENDED_SAFEBOX						// 3 yerine 6 kasa sayfası etkinleştir;
#define ENABLE_PARTY_BUFF_SYSTEM					// Parti buff sistemini etkinleştir;
#define ENABLE_IGNORE_LOW_POWER_BUFF				// Düşük buff sistemini etkinleştir;
#define ENABLE_BOSS_KILL_NOTICE						// Patron öldürme duyurusu etkinleştir;
#define ENABLE_ANNONUNCEMENT_LEVELUP				// Seviye duyuru (120) bilgilendirmeyi etkinleştir;
#define ENABLE_SKILL_MASTER_LEVEL					// Beceri master seviyesi 17' de  etkinleştir;
#define ENABLE_COORDINATES_COMMAND					// User komutunda koordinat'ı etkinleştir;
#define ENABLE_GOHOME_IFNOMAP						// Harita bulunamadığında köye ışınlanmayı etkinleştir;
#define ENABLE_CLEAR_GUILD_LANDS					// Kullanılmayan lonca arazilerini silmeyi etkinleştir;
#define ENABLE_RENEWAL_SWITCHBOT					// Switchbot sistemini etkinleştir;
#define ENABLE_RENEWAL_BOOK_NAME					// Oyuncular mob ve taşlardan düşen kitabın adını görebilir;
#define ENABLE_GUILD_RANK_SYSTEM					// Lonca sıralaması için pano etkinleştir;
#define ENABLE_RENEWAL_DEAD_PACKET					// Zamanlayıcı ile burada yeniden başlat ve kasabada yeniden başlat;
#define ENABLE_HIDE_COSTUME_SYSTEM					// Kostüm sistemi için gizleme etkinleştir;
#define ENABLE_ACCE_COSTUME_SYSTEM					// Acce kostüm sistemini etkinleştir;
#define ENABLE_TELEPORT_TO_A_FRIEND					// Arkadaşa ışınlanmayı etkinleştir;
#define ENABLE_WEAPON_COSTUME_SYSTEM				// Silah kostüm sistemini etkinleştir.
#define ENABLE_MULTI_LANGUAGE_SYSTEM				// Çoklu dil sistemi;
#define ENABLE_VIEW_TARGET_PLAYER_HP				// Hedef çubuğunda HP'yi etkinleştir;
#define ENABLE_RENEWAL_CLIENT_VERSION				// Yeni istemci sürüm kontrolünü etkinleştir;
#define ENABLE_VIEW_TARGET_DECIMAL_HP				// Ondalık HP'yi etkinleştir.
#define ENABLE_EXTENDED_WHISPER_DETAILS				// Genişletilmiş fısıldama hedef bilgisi çoklu dil ülke bayrağı;
#define ENABLE_EXTEND_TIME_COSTUME_SYSTEM			// Kostüm sistemi için süre uzatmayı etkinleştir;
#define ENABLE_IMPROVED_HANDSHAKE_PROCESS			// Owsap tarafından geliştirilmiş el sıkışma sürecini etkinleştir.
#define ENABLE_NEW_BONUS_SYSTEM						// Patronlara karşı bonusu etkinleştir;
#define ENABLE_AVG_PVM								// Yüksek ortalama zarar bonusu etkinleştir;
	#ifdef ENABLE_AVG_PVM
		#define ENABLE_AVG_PVM_DISABLE				// Yüksek ortalama zarar bonusu etkinleştir;
	#endif
#define ENABLE_MAGIC_REDUCTION_SYSTEM				// Büyü direnci & bozma bonusu etkinleştir;
	#ifdef ENABLE_MAGIC_REDUCTION_SYSTEM
		//#define USE_MAGIC_REDUCTION_STONES			// Büyü bozma taşlarını etkinleştir;
	#endif
#define ENABLE_HUMAN_RESIST_PVP						// Yarı insanlara karşı bonusu etkinleştir;
#define ENABLE_RENEWAL_AFFECT						// Yenileme etkisini etkinleştir (1 yeni alt tip + etki simgesi);
#define ENABLE_OFFLINE_MESSAGE						// Oyuncu bağlı değilse çevrimdışı mesaj bırakma seçeneğini etkinleştir;
#define ENABLE_RESTART_INSTANT						// 500.000 Yang için anında yeniden başlatmayı etkinleştir;
#define ENABLE_NEW_DUNGEON_LIB						// Yeni zindan fonksiyonlarını etkinleştir;
#define ENABLE_RENEWAL_OX_EVENT						// Resmi gibi yenileme ox etkinliğini etkinleştir;
#define ENABLE_MULTI_FARM_BLOCK						// 2'den fazla istemci için çoklu farm'ı imkansız hale getir;
#define ENABLE_SPECIAL_INVENTORY					// Kitaplar, yükseltme vb. için özel envanter;
#define ENABLE_EXTEND_ITEM_AWARD                	// Genişletilmiş eşya ödül sistemini etkinleştir (çoğunlukla Item Shop ödülleri için)
	#ifdef ENABLE_EXTEND_ITEM_AWARD
		#define USE_ITEM_AWARD_CHECK_ATTRIBUTES    // Ödül verilirken eşyaların attribute/özellik kontrolünü kullan
	#endif
#define ENABLE_MAINTENANCE_SYSTEM					// Oyunda bakım bilgisini etkinleştir;
#define ENABLE_SKILL_COLOR_SYSTEM					// Yetenek renk sistemini etkinleştir;
#define ENABLE_PICKUP_ITEM_EFFECT					// Envanter / özel envanterde alınan eşyalar için efekti etkinleştir;
#define ENABLE_RENEWAL_OFFLINESHOP					// Yeni offlineshop sistemini etkinleştir;
#define ENABLE_RENEWAL_TEAM_AFFECT					// Yenileme takım etkisini etkinleştir (logo);
#define ENABLE_SLOT_MARKING_SYSTEM					// Resmi gibi slot işaretleme sistemini etkinleştir;
#define ENABLE_RENEWAL_SKILL_SELECT					// Yetenek seçmek için yeni bir pencere etkinleştir;
#define ENABLE_RENEWAL_SPECIAL_CHAT					// Yang, Eşyalar vb. için yenileme özel sohbeti etkinleştir;
#define ENABLE_LARGE_DYNAMIC_PACKET					// Büyük dinamik paket boyutunu etkinleştir;
#define ENABLE_CLIENT_LOCALE_STRING					// İstemciden yerel dize yüklemesini etkinleştir;
#define ENABLE_BONUS_COSTUME_SYSTEM					// Kostümlerde bonus ekleme ve değiştirmeyi etkinleştir;
#define ENABLE_GUILD_LEADER_TEXTAIL					// [Lider] ile lonca generali için metni etkinleştir;
#define ENABLE_CROSS_CHANNEL_REQUESTS				// Kanal arası istekleri etkinleştir (gelecekte genişletilecek);
#define ENABLE_AUTOMATIC_PICK_UP_SYSTEM				// Otomatik toplama sistemini etkinleştir;
#define ENABLE_OFFLINESHOP_SEARCH_SYSTEM			// Yenileme offlineshop için arama sistemini etkinleştir;
#define ENABLE_EMOTICONS_SYSTEM						// Sohbet ve fısıldamada emoji sistemi;
#define ENABLE_ANTI_EQUIP_FLOOD						// Ekipman için hızlı kontrolü etkinleştir;
#define ENABLE_HANDSHAKE_SESSION					// El sıkışma oturumu düzeltmesini etkinleştir;
#define ENABLE_GROWTH_PET_SYSTEM					// Resmi evcil pet sistemini etkinleştir;
#define ENABLE_CHANGE_LOOK_SYSTEM					// Görünüm değiştirme sistemini etkinleştir;
#define ENABLE_KILL_STATISTICS						// Resmi ile neredeyse aynı yeni bonus panosu;
#define ENABLE_AURA_COSTUME_SYSTEM					// Aura kostüm sistemini etkinleştir;
#define ENABLE_RENEWAL_TELEPORT_SYSTEM				// Yeni ışınlanma sistemini etkinleştir;
#define ENABLE_INVENTORY_EXPANSION_SYSTEM			// Resmi gibi envanter genişletme sistemini etkinleştir;
#define ENABLE_GM_INV_EFFECT         				// Resmi GM /inv efekt güncellemesi
#define ENABLE_RIDING_EXTENDED         				// Resmi At seviyesi genişletildi
#define ENABLE_BOT_PLAYER							// Sahte oyuncu sistemi
#define ENABLE_STANDING_MOUNT						// Ayakta kullanılan binek sistemini etkinleştir	
	#ifdef ENABLE_STANDING_MOUNT	
		#define STANDING_MOUNT_VNUM_1 40003 			// Turbo Sörf Tahtası
		#define STANDING_MOUNT_VNUM_2 40004 			// Wukong'un Fırtınası
		#define STANDING_MOUNT_VNUM_3 40005 			// Wukong'un Gürlemesi
		#define SURFBOARD STANDING_MOUNT_VNUM_1 		// Eski sistemlerle uyumluluk için alias
		#define IS_STANDING_MOUNT_VNUM(v) ((v)==STANDING_MOUNT_VNUM_1 || (v)==STANDING_MOUNT_VNUM_2 || (v)==STANDING_MOUNT_VNUM_3)
	#endif
#define ENABLE_HUNTING_SYSTEM						// Avcılık görev sistemini etkinleştir;
	#ifdef ENABLE_HUNTING_SYSTEM
		#define HUNTING_MISSION_COUNT 90        	// Aynı anda aktif olabilecek av görevi sayısı
		#define HUNTING_MONEY_TABLE_SIZE 9     		// Her görev seviyesi için yang ödül tablosu girişi sayısı
		#define HUNTING_EXP_TABLE_SIZE 9       		// Her görev seviyesi için EXP tablosu girişi sayısı
	#endif
#define ENABLE_SKILL_BOOK_READING					// Beceri Kitabı Okuma sistemi
#define ENABLE_SPIRIT_STONE_READING					// Ruh Taşı Okuma sistemi
#define __AUTO_HUNT__								// Otomatik Av sistemi
#define ENABLE_AUTO_SELL_SYSTEM						// Otomatik item satmayı sistemini etkinleştir;
	#ifdef ENABLE_AUTO_SELL_SYSTEM
		#define MAX_AUTO_SELL_ITEMS 100				// Listeye eklenecek maksimum item sayısı
	#endif
#define ENABLE_PLAYERS_ONLINE                  		// Çevrimiçi oyuncu /players_online komutunu  etkinleştir;
#define ENABLE_STYLE_ATTRIBUTE_SYSTEM      			// Seçmeli özel kadim efsunu sistemini  etkinleştir;
#define ENABLE_ITEM_MODIFIER_AVG_SKILL				// Ortalama ve Beceri efsun nesnesi sistemini etkinleştir;
#define ENABLE_RANDOM_STATUS_PER_LEVEL 				// Seviye atladıkça karaktere rastgele ek statüler kazandırır
#define ENABLE_PITTY_REFINE                    		// Yeni nesil yükseltme sistemi
#define ENABLE_NPC_LOCATION_TRACE  					// Belirtilen NPC veya mob'un harita üzerindeki konumunu tespit eder ve oyuncuya yönlendirme sağlar
#define ENABLE_ITEMSHOP								// Oyunda nesne market'i etkinleştir;		
	#ifdef ENABLE_ITEMSHOP	  
		#define USE_ITEMSHOP_RENEWED			   	// Oyunda nesne market yenilemeyi etkinleştir;
	#endif
#define ENABLE_BATTLE_PASS                      	// Yenileme savaş bileti sistemini etkinleştir;
	#ifdef ENABLE_BATTLE_PASS                      	// Yenileme savaş bileti sistemini etkinleştir;
		//#define ENABLE_BATTLE_PASS_MOUNTH_CLOSE
	#endif
#define ENABLE_BIOLOGIST_SYSTEM						// Biyolog sistemini etkinleştir
#define ENABLE_AFFECT_BUFF_REMOVE              		// Buff Etkilerini Kaldırma
#define RENEWAL_HWID_BLOCK    						// Geliştirilmiş HWID doğrulama ve engelleme sistemini etkinleştirir
#define __LEADERSHIP__BONUS__                  		// Liderlik Bonusu
#define ENABLE_NEWSTUFF    							// Yeni eklenen sistemleri, özellikleri veya geliştirmeleri toplu olarak aktif etmek için kullanılan genel kontrol bayrağı
#define ENABLE_DUNGEON_RENEWAL_SYSTEM      			// Zindan sistemini tümüyle etkinleştirir
	#ifdef ENABLE_DUNGEON_RENEWAL_SYSTEM
		#define ENABLE_DUNGEON_INFO           		// Zindanla ilgili detaylı bilgi (harita, süre, ödüller) gösterim desteğini sağlar
		#define __DUNGEON_INFO__             		// Yeni tip zindan bilgisi patron mekaniklerini aktif eder
		#define ENABLE_NEW_DUNGEON_LIB       		// Zindan işlevleri için yeni kütüphane/alt sistem kullanımına geçirir
		#define ENABLE_TRACK_WINDOW          		// Zindan takibi için özel UI/pencere (track window) desteğini etkinleştirir
		#define ENABLE_ULTIMATE_REGEN        		// Gelişmiş/alternatif "ultimate" regen algoritmasını devreye alır
	#endif
#define ENABLE_YOHARA_SYSTEM          				// Yohara kıtası ve SungMa tabanlı sistemleri etkinleştirir
	#ifdef ENABLE_YOHARA_SYSTEM
		#define ENABLE_CONQUEROR_LEVEL				// Şampiyon seviyesi sistemini etkinleştir;
		#define ENABLE_CONQUEROR_LEVEL_UPDATE		// Şampiyon seviyesi anında yenilemeyi etkinleştir;
		#define ENABLE_PASSIVE_SYSTEM				// Resmi Kalıntı Bonusu sistemi etkinleştirir;
		#define ENABLE_NINETH_SKILL					// 9. becerileri etkinleştir
		#define ENABLE_PVP_BALANCE					// Yeni skill animasyonları, resmi oyun gibi
	#endif
#define ENABLE_DUNGEON_MAPS_SYSTEM        			// Tüm yeni/yenilenmiş zindan ve harita altyapısını etkinleştirir
	#ifdef ENABLE_DUNGEON_MAPS_SYSTEM
		// Yohara Zindanları Start
		#define ENABLE_SUNG_MAHI_TOWER    			// SungMa İstilası zindanı
		#define ENABLE_WHITE_DRAGON       			// Alastor (Kuzey Rüzgarı Derinlikleri)
			#ifdef ENABLE_WHITE_DRAGON
				//#define ENABLE_WHITE_DRAGON_EX 	// Alastor canavar / event uzantıları
			#endif
		#define ENABLE_QUEEN_NETHIS       			// Yılan Tapınağı (Queen Nethis)
		// Yohara Zindanları End

		#define ENABLE_MELEY_LAIR_DUNGEON     			// Meley'in İni haritasını etkinleştir
		#define ENABLE_ZODIAC_MISSION     				// Zodyak Tapınağı görev sistemi
		#define ENABLE_DRAGON_LAIR            			// Mavi Ejderha Odası'nı etkinleştir
		#define ENABLE_DEFENSAWE_SHIP         			// Resmi sürümdeki Gemi Savunma Zindanı’nı etkinleştir
		#define ENABLE_OCHAO_TEMPLE_SYSTEM              // Ochao Tapınağı ve Büyülü Orman zindanını etkinleştirir
			#ifdef ENABLE_OCHAO_TEMPLE_SYSTEM		
				#define OCHAO_HEALING_SKILL_VNUM 265    // 1.62 sürümü için Ochao heal skill vnum tanımı
			#endif
	#endif
#define __DOJANG_SRC_FUNCTIONS__      				// Turnuva (PvE/PvP arena) kaynak fonksiyonlarını açar
	#ifdef __DOJANG_SRC_FUNCTIONS__
		#define DOJANG_MAPINDEX 92        			// Turnuva harita index değeri
	#endif
#define ENABLE_REMOTE_SHOP_SYSTEM                   // Uzaktan Market sistemini etkinleştirir;
#define __SYSTEM_SEARCH_ITEM_MOB__  				// Mob kodu girildiğinde o mobdan düşen item’leri panel üzerinden listelemeyi sağlar.
#define ENABLE_REFINE_SUCCESS_NOTICE				// İtem son refine seviyesine (+9) ulaştığında global duyuru gönderir.
	#ifdef ENABLE_REFINE_SUCCESS_NOTICE
		#define REFINE_SUCCESS_NOTICE_LEVEL 9		// Global duyuru gönderilecek minimum refine seviyesi.
	#endif
#define ENABLE_EQUIPMENT_HAND_EFFECT				// Karakterin sağ ve sol eline takılan ekipmanlar için özel efekt desteği sağlar.
#define ENABLE_RESP_SYSTEM							// Patron ve Metin ışınlanma sistemini etkinleştirir
#define ENABLE_REAL_TIME_REGEN						// Karakterlerin HP/SP yenilenmesinin gerçek zamanlı (online) olarak çalışmasını sağlar
#define ENABLE_COLLECT_WINDOW                 		// Koleksiyon sistemine ait GUI (pencere) arayüzünü aktif eder
#define __ENABLE_COLLECTIONS_SYSTEM__         		// Koleksiyon (Collections) sisteminin tamamını aktif eder
#define ENABLE_NEW_ITEM_TYPE_GACHA          		// Gacha sistemi için yeni sandık / item tipini aktif eder
#define ENABLE_RANKING          					// Rank sıralama sistemi
#define ENABLE_MOB_FOLLOW_SYSTEM          			// Canavar (Mob) takip sistemi
#define ENABLE_ITEM_UPGRADE_NOTICE          		// Belirlenen seviye ve üzerindeki eşya geliştirmelerini global olarak duyurur.
	#ifdef ENABLE_ITEM_UPGRADE_NOTICE
		#define ITEM_UPGRADE_NOTICE_MIN_LEVEL 9 	// Duyuru yapılacak minimum geliştirme seviyesi (örn: +9 ve üzeri).
	#endif
#define ENABLE_GAYA_SYSTEM                         	// Gaya sistemini (Gaya para birimi, NPC ve takas mekanikleri) aktif eder
	#ifdef ENABLE_GAYA_SYSTEM
		#define ENABLE_GAYA_SHOP_SYSTEM             // Gaya para birimi ile çalışan market / alışveriş sistemini aktif eder
		#define ENABLE_GAYA_TICKET_SYSTEM           // Gaya sistemi için kupon (bilet) kullanımı ve dönüşüm mekanizmasını aktif eder
	#endif
#define ENABLE_EVENT_SYSTEM                         // Etkinlik yöneticisini (otomatik ve zamanlı etkinlikler) aktif eder
	#ifdef ENABLE_EVENT_SYSTEM
		#define ENABLE_EVENT_BANNER_FLAG            // Etkinlikler için oyun içi banner / bayrak gösterim sistemini aktif eder
		#define ENABLE_SOUL_ROULETTE_SYSTEM         // Kan Ritüeli (Soul Roulette) mini oyun / etkinlik sistemini aktif eder
		#define ENABLE_ATTENDANCE_EVENT             // Canavar Avı (Attendance) etkinliğini ve ödül mekanizmasını aktif eder
		#define ENABLE_FISH_EVENT                   // Resmi yeni balık tutma mini oyununu aktif eder
		#define ENABLE_MINI_GAME_CATCH_KING         // Kralı Yakala (Catch the King) kart mini oyununu aktif eder
		#define ENABLE_MINIGAME_RUMI_EVENT          // Rumi (Okey kartları) mini oyun sistemini aktif eder
		#define ENABLE_HALLOWEEN_EVENT_SYSTEM       // Cadılar Bayramı (Halloween) etkinlik sistemini aktif eder
		#define ENABLE_STONE_EVENT_SYSTEM           // Metin Taşı kesme / sıralama etkinlik sistemini aktif eder
		#define ENABLE_SOCCER_BALL_EVENT            // Futbol Topu etkinliğini ve ilgili oyun mekaniklerini aktif eder
		#define ENABLE_WORD_GAME_EVENT              // Kelime oyunu etkinliğini aktif eder
		#define ENABLE_EVENT_DROPS                  // Etkinliklere özel item düşürme (drop) ayarlarını aktif eder
	#endif
#define ENABLE_DROP_GOLD							// Kapatınca DropGold fonksiyonu tamamen devre dışı bırakılır, oyuncuya "Yere yang atamazsiniz!" mesajı gösterilir
#define ENABLE_GOLD_MULTIPLIER						// Yang çarpan sistemi
#define ENABLE_GOLD10_PCT							// Yang %10 çarpanı
#define ENABLE_STATUS_UP_RENEWAL					// Hızlı statü sistemi etkinleştir;
#define ENABLE_TITLE_SYSTEM							// Resmi Ünvan Sistemi etkinleştirir;

/*** KRİTİK HATA, ÇÖKME VE AÇIK DÜZELTMELERİ (CRASH / CORE / BUG / EXPLOIT / LEAK) ***/
#define __FIX_TIMER_EVENT__ 						// Timer event (zamanlayıcı) gecikme ve tetiklenme hatalarını düzeltir
#define __FIX_SECONDARY_SKILL__ 					// İkincil skill (secondary skill) kullanım ve hesaplama hatalarını düzeltir
#define ENABLE_COUNT_MONSTER_FIX 					// Canavar sayacı (kill count) hatasını düzeltir
#define FLUSH_AT_SHUTDOWN							// Sunucu kapanırken verileri zorla diske yazar (veri kaybını önler)
#define __FIX_INFO_REFINE_DRAGONSOUL__ 				// Ejderha taşı simyası refine bilgi/tooltip hatasını düzeltir
#define __FIX_COSTUM_NUNTA_PESTE_COSTUM_NORMAL__ 	// Kostüm slot çakışmasını düzeltir (smokin & gelinlik kostüm normal kostümü etkilemez)
#define FIX_BLOCK_MOB_SAFEZONE 						// Güvenli bölgede mob saldırısını engeller
#define DISABLE_STOP_RIDING_WHEN_DIE				// Karakter öldüğünde binek ve sürüş durumunu temizler.
#define ENABLE_STONES_STACKFIX   					// Taş itemlerinde stack (birikme) işlemlerindeki hataları düzeltmek için özel split ve ekleme mantığını aktif eder.
#define ENABLE_TELEPORT_SKILL						// Her ışınlanmada becerilerin tekrar sönme sorununu giderir.
#define ENABLE_BOSS_METIN_POISON_DISABLE    		// Boss ve Metin taşlarına karşı zehir etkisini devre dışı bırakır.
#define DISABLE_STAMINA    							// Stamina (ST) sistemini devre dışı bırakır; karakter yorulmaz ve ST tüketimi gerçekleşmez.
#define ENABLE_FIX_SWAP_ITEM						// Slot uyuşmazlığı nedeniyle ekipman değiştirilememesi sorununu giderir.
#define ENABLE_RELOAD_COMMAND_ALL_CORES  			// Reload komutunun tüm core’lara P2P üzerinden senkron şekilde iletilmesini sağlar.
#define ENABLE_ITEM_DUPE_FIX 						// Eşya işlemlerinde oluşan senkronizasyon ve zamanlama hatalarından kaynaklı çoğaltma açıklarını düzeltir.
#define ENABLE_FIX_EXP_DROP_STONES 					// Metin (Stone) yaratıklarından EXP düşme hesaplamalarında oluşan hataları giderir.
#define ENABLE_MULTI_AFFIX_APPLY_SYSTEM 			// Tek işlemde birden fazla efsun (bonus) eklenmesini sağlar.
#define ENABLE_REGEN_RENEWAL 						// Regen event’lerinin başlatılma zamanını sabitleyerek rastgele gecikmeleri ortadan kaldırır ve daha tutarlı spawn döngüsü sağlar.
#define STONE_REGEN_FIX 							// Metin (Stone) yaratıklarının yeniden doğma sırasında oluşan animasyon, konum ve stabilite problemlerini giderir.
#define FIX_SyncPosition                       		// Pozisyon senkronizasyon sorunlarını düzeltir
#define ENABLE_PROXY_IP								// Proxy/VPN tespiti ve reverse-proxy arkasındaki gerçek istemci IP'sinin doğru okunmasını sağlayarak IP algılama hatalarını düzeltir
#define ENABLE_UDP_BLOCK							// UDP port engellemeyi etkinleştir;
#define ENABLE_PORT_SECURITY						// db_port, p2p_port ve uzak admin sayfası açıklarını engelle;
#define MULTIPLE_DAMAGE_DISPLAY_SYSTEM				// Çoklu damage gösterimi  düzeltir
#define ENABLE_DBMANAGER_SQL_INJECT_FIX				// Veritabanı tarafında SQL Injection açıklarını engeller
#define ENABLE_LOG_SQL_INJECTION_FIX				// Log tablosu üzerinden yapılabilecek SQL injection açıklığını kapatır
#define ENABLE_LOCALHOST_IP_FIX						// Localhost / 127.0.0.1 IP kullanımından kaynaklı bağlantı sorunlarını düzeltir
#define ENABLE_INTERNAL_IP_FIX						// Dahili (internal) IP algılama / yönlendirme ile ilgili sorunları düzeltir
#define ENABLE_POINT_EXP_FIX						// EXP ve karakter puanı hesaplama hatalarını düzeltir
#define ENABLE_MINING_DISTANCE_FIX					// Kazı (mining) mesafe kontrol hatalarını düzeltir
#define ENABLE_STOP_FUNCTION_FIX					// Hareket/aksiyon durdurma fonksiyonundaki bugları giderir
#define ENABLE_STR_NEW_NAME_FIX						// Yeni isimlendirme (string) hatalarını düzeltir
#define ENABLE_LAST_ATTACK_TIME_FIX					// Son saldırı zaman hesaplamasını doğru şekilde düzenler
#define ENABLE_COMPUTE_POINT_FIX					// Karakter stat/point hesaplama hatalarını giderir
#define ENABLE_DAMAGE_EFFECT_ACCUMULATION_FIX		// Damage efekt birikme sorunu düzeltmesi
#define ENABLE_QUEST_PC_GETFLAG_CRASH_FIX			// Quest pc.getf/pc.getflag kullanıldığında oluşan olası crash sorununu düzeltir
#define ENABLE_FRIEND_LIST_REMOVE_FIX				// Arkadaş listesinden oyuncu silememe / hatalı silme problemini düzeltir
#define ENABLE_MOUNT_LEVEL_BUG_FIX					// Binek level alma / level gösterimi ile ilgili hataları düzeltir
#define ENABLE_MOUNT_FIRE_SPIRIT_ATTACK_FIX			// Binek üzerindeyken Ateş Hayaleti saldırısının çalışmama sorununu giderir
#define DEFAULT_REMOVE_ALL_BOOKSS					// Beceri kitaplarının tek seferde yanlışlıkla toplu silinmesini engeller
#define ENABLE_MOUNT_PUSHBACK_FIX					// Bineklerin geriye atma / geriye sarma bug’ını düzeltir
#define ENABLE_BOSS_WALL_CLIP_FIX					// Bossların duvar içine sıkıştırılması / duvar içinden vurulması exploitini engeller
#define ENABLE_MAGIC_WEAPON_BUG_FIX					// Büyülü silah / hava kılıcı benzeri skilllerdeki hasar veya görünüm bug’larını düzeltir
#define ENABLE_CUBE_GAME_CORE_FIX					// Cube (dönüştürme) işlemi sırasında oluşan core hatalarını düzeltir
#define ENABLE_CUBE_REQUEST_LIST_FIX				// Cube request / result list verilerinin yanlış veya eksik gelmesi problemini düzeltir
#define ENABLE_TRANSFORMATION_SKILL_CLOSE_FIX		// Dönüşüm halindeyken kapanması gereken skilllerin açık kalma sorununu giderir
#define ENABLE_DUNGEON_CORE_CRASH_FIX				// Zindan giriş/çıkışlarında oluşan core crash problemlerini düzeltir
#define ENABLE_ETC_ITEM_DROP_FIX					// ETC (çeşitli) itemlerin yanlış veya hatalı drop olma sorununu düzeltir
#define ENABLE_GUARDIAN_MOB_AGGRO_FIX				// Köy gardiyanının mob gördüğünde yanlış veya tepkisiz davranma problemini düzeltir
#define ENABLE_WEDDING_COSTUME_EQUIP_FIX			// Gelinlik/smokın giyiliyken kostüm giyememe veya çakışma sorununu giderir
#define ENABLE_EQUIPPED_ITEM_STORAGE_FIX			// Takılı (equipli) itemlerin depoya konabilmesiyle oluşan bug’ı engeller
#define ENABLE_QUEST_PC_SELECT_FIX					// Quest komutu pc.select ile ilgili seçim / hedefleme sorunlarını düzeltir
#define ENABLE_PARTY_DUNGEON_CORE_FIX				// Grup halinde zindanda oluşan core crash / senkron sorunlarını giderir
#define ENABLE_PARTY_FLAG_CHANGE_FIX				// Gruptayken bayrak (empire) değiştirme hatasını / kısıtını düzeltir
#define ENABLE_HORSE_SPAWN_EXPLOIT_FIX				// At çağırma / horse spawn ile yapılan exploit ve kötüye kullanımları engeller
#define ENABLE_HP_SP_ABSORB_ORB_FIX					// HP-SP absorb orb eşyalarının yanlış çalışması veya değer bug’ını düzeltir
#define ENABLE_HP_SP_STEAL_FIX						// HP-SP çalma (lifesteal / manasteal) hesaplama ve uygulama hatalarını giderir
#define ENABLE_SOCKET_STONE_MASS_DELETE_FIX			// İstiflenmiş taşların tek seferde yanlışlıkla toplu silinmesini engeller
#define ENABLE_WARP_HP_LOSS_FIX						// Işınlanınca (warp) HP düşmesi / can kaybı yaşanması sorununu düzeltir
#define ENABLE_ITEM_SWAP_FIX						// İki item arasında slot değiştirirken oluşan item swap bug’ını düzeltir
#define ENABLE_CHARACTER_NAME_HACK_FIX				// Karakter ismi üzerinden yapılan hile / exploit girişimlerini engeller
#define ENABLE_COSTUME_GENDER_CHANGE_FIX			// Kostüm giyiliyken cinsiyet değiştirme ile oluşan görünüm/slot bug’ını giderir
#define ENABLE_GUILD_EMPIRE_BUG_FIX             	// Lonca-İmparatorluk (empire/ownership) devretme / miras hatasını düzeltir
#define ENABLE_GUILD_YANG_ACCOUNTING_FIX        	// Lonca işlemlerinde yanlış yang hesaplamalarını giderir
#define ENABLE_LUA_ESC_BEHAVIOR_FIX             	// Lua scriptlerinde ESC/exit davranışından kaynaklı hataları düzeltir
#define ENABLE_MESSENGER_MANAGER_FIX            	// Mesajlaşma / messenger yöneticisi ile ilgili hataları düzeltir
#define ENABLE_QUICK_SLOT_FIX                   	// Hızlı slot (quickslot) atama / değiştirme sorunlarını giderir
#define ENABLE_WARRIOR_SKILL_RESET_FIX          	// Savaşçı (warrior) skill reset / sıfırlama hatalarını düzeltir
#define ENABLE_BERSERKER_MODE_FIX               	// Berserker / sersemlik ile ilgili bilinen oyun içi hataları giderir
#define ENABLE_DEMON_TOWER_SMALL_FIX            	// Şeytan Kulesi gibi küçük edge-case hatalarını düzeltir
#define ENABLE_STONE_ITEM_BUG_FIX               	// Taş/soket itemleriyle ilgili kullanım/istif/bellek hatalarını giderir
#define ENABLE_WAR_CRASHER_PROTECTION_FIX       	// Savaş (war) sırasında crash/exploit korumaları ekler
#define HORSE_FIX									// At/binek sistemindeki spawn, hareket, saldırı ve pozisyon hatalarını giderir; exploit risklerini azaltır
#define SYS_ERR_SOURCE_TRACKING    					// Hata tetiklendiğinde log çıktısına kaynak dosya ve satır bilgisi ekler
#define ENABLE_SKILL_PAERYONG_PROCESSING   			// SKILL_PAERYONG (Ejderha Kükresi) için ComputeSkill çağrısını ekleyerek hasar/efekt işlenmesini sağlar
#define ENABLE_HORSE_SKILL_DAMAGE					// At üzerinde Sura beceri vurma düzeltmesini etkinleştirir
#define ENABLE_ANALYZE_CLOSE_FIX 					// Analiz/inceleme arayüzünün beklenmedik şekilde kapanmasına neden olan hataları düzeltir.
#define ENABLE_CRASH_CORE_ARROW_FIX 				// Okçu sınıfının Core (çekirdek) kaynaklı çökme (crash) hatasını giderir.
#define ENABLE_DUNGEON_MUSIC_FIX  					// Zindanlarda müziğin çalmaması veya hatalı çalması sorununu düzeltir.
#define ENABLE_FLY_FIX 								// Fly senkronizasyonunu milisaniye bazlı kontrol ederek exploit ve desync riskini azaltır.
#define ENABLE_CHANGE_SKILL_VISUAL_BUG_FIX  		// Skill değişiminde oluşan görsel buff/efekt hatalarını düzeltir.
#define ENABLE_CHANGE_SEX_WITHOUT_RELOG_FIX  		// Karakter cinsiyeti değiştirildiğinde relog gerektiren senkronizasyon hatasını düzeltir.
#define ENABLE_CH_CRASH_CORE_FIX  					// Quest fonksiyonlarında geçersiz karakter pointer’ı nedeniyle oluşan crash hatasını önler.
#define ENABLE_KILL_EVENT_FIX  						// Öldürme etkinlik'lerinde hasara göre doğru oyuncunun seçilmesini sağlar.
#define ENABLE_CUBE_RELOAD_FIX  					// Craft tariflerinin server restart olmadan güvenli şekilde yeniden yüklenmesini sağlar.
#define ENABLE_EXP_GROUP_FIX  						// Grup EXP dağıtımının yalnızca parti lideri tarafından yapılmasını sağlar.
#define ENABLE_FISHING_TIME_INC  					// Balıkçılık bekleme süresini düşürerek daha hızlı balık tutmayı sağlar.
#define ENABLE_DISABLE_EMPIRE_DAMAGE_BONUS			// Başka bir imparatorluktan geliyorsanız, hasar %10 azalır.
#define ENABLE_STONES_STACKFIX  					// İstiflenen taşların refine sırasında yanlış silinmesini ve dupe oluşmasını önler.
#define ENABLE_ITEM_AWARD_FIX  						// Ödül öğesi işlemlerinde veri kalıntılarından kaynaklı hataları önler.
#define ENABLE_SKILL_COOLDOWN_CHECK  				// Skill kullanımında server-side cooldown ve spam kontrolü sağlar.
#define ENABLE_SAFE_LEVEL_CHANGE_FIX  				// Seviye değişiminde PointChange senkronizasyon hatalarını ve exploit riskini önler.
#define MARTYSAMA0134_FIXLERI_TOPLU					// Martysama0134 tarafından bildirilen ve düzeltilen çeşitli hata düzeltmeleri
#ifdef MARTYSAMA0134_FIXLERI_TOPLU
	#define MARTYSAMA0134_FIXLERI_04				// Oyuncu partideyken bayrak (empire) değiştirebiliyordu.
	#define MARTYSAMA0134_FIXLERI_11				// Bu kontrol eklenince oyuncular pazar NPC'lerine saldıramaz
	#define MARTYSAMA0134_FIXLERI_12				// Lonca savaşı sırasında lonca dağıtma engel
	#define MARTYSAMA0134_FIXLERI_14				// Okçu ve şaman için saldırı mesafesi 1.5 kat arttırıldı
#ifdef MARTYSAMA0134_FIXLERI_14
		#define MARTYSAMA0134_FIXLERI_14_GENEL_ORAN 250			// fHitRange genel vuruş menzili
		#define MARTYSAMA0134_FIXLERI_14_SAMAN_NINJA_ORAN 500	// şaman ve ninjanın vuruş menzili
#endif
	#define MARTYSAMA0134_FIXLERI_19				// Max levele ulaşan oyuncunun Beceri Kitabı okuyamama sorunu fixlemesi
	#define MARTYSAMA0134_FIXLERI_23				// Oyuncunun envanterinde 50 tane metin taşı varsa, hepsi siliniyor.
	#define MARTYSAMA0134_FIXLERI_42				// ch NULL kontrolü yok.
	#define MARTYSAMA0134_FIXLERI_46				// Anti-equip flood koruması sadece gerçek oyuncular için çalışır, GM'ler zaten hariç, ek olarak non-PC karakterler de hariç tutulur
	#define MARTYSAMA0134_FIXLERI_55				// {100, 100, 100, 100, 100, 0, 0} -> Tüm 5 efsun slotu %100 şansla geçer
		#ifdef MARTYSAMA0134_FIXLERI_55
		#define MARTYSAMA0134_FIXLERI_55_ORAN 100	// Yazılan oran ilk 5 efsunun eklenme şansı olarak işlenir
		#endif
	#define MARTYSAMA0134_FIXLERI_56				// IsHorseRiding() true ise → doğrudan StopRiding() çağrılır (temiz inme),false ise → StartRiding() çağrılır (temiz binme)
	#define MARTYSAMA0134_FIXLERI_57				// Her pot case'inin başına if (FindAffect(AFFECT_ITEM_BLOCK)) return false; kontrolü ekle
		#ifdef MARTYSAMA0134_FIXLERI_57
		#define MARTYSAMA0134_FIXLERI_57_ORAN 3		// Pot başarılı şekilde kullanıldığında AddAffect(AFFECT_ITEM_BLOCK, ...) ile 3 saniyelik cooldown ekle
		#endif
	#define MARTYSAMA0134_FIXLERI_83				// Oyuncu çıkış zamanının 10sn sürmesi fixi
		#ifdef MARTYSAMA0134_FIXLERI_83
		#define MARTYSAMA0134_FIXLERI_83_ORAN 3		// Yazılan oranda oyuncu oyundan çıkış yapar
		#endif
	#define MARTYSAMA0134_FIXLERI_84				// POS_FIGHTING Respawn Bekleme süreleri
		#ifdef MARTYSAMA0134_FIXLERI_84
		#define MARTYSAMA0134_FIXLERI_84_ORAN 3		// Yazılan oranda oyuncu POS_FIGHTING Respawn süresi aktif olur
		#endif
	#define MARTYSAMA0134_FIXLERI_100				// ACMD(do_stat_minus) HT (Vitality) azalınca HP'yi, IQ (Intelligence) azalınca SP'yi güncelle:
	#define MARTYSAMA0134_FIXLERI_125				// Karakter güvenli alan sınırlarına yaklaştığında GetSectree() NULL dönebilir. Bu durumda sectree metodları çağrıldığında core crash oluşur.
	#define MARTYSAMA0134_FIXLERI_128				// Bu, saldırı anında oyuncunun eşya/pazar işlemlerini geçici olarak bloklar, dupe exploit'ini engeller.
//	#define MARTYSAMA0134_FIXLERI_141				// Düello (PVP) başladığında, Ateş Hayaleti(SKILL_MUYEONG), Büyülü Silah(SKILL_GWIGEOM) ve Hava Kılıcı(SKILL_GEOMKYUNG) gibi bufflar temizlenir
	#define MARTYSAMA0134_FIXLERI_159				// Bu değişken olmadan oyuncular stat reset yapıp hemen Won/Kim kullanarak kopyalama yapabilir.
	#define MARTYSAMA0134_FIXLERI_161				// SKILL_GEOMKYUNG (4): Güçlü Beden, SKILL_GWIGEOM (63): Hava Kılıcı, SKILL_MUYEONG (78): Ateş Hayaleti Bu affect'ler temizlenmezse karakter skill'i sıfırlansa bile buff'lar devam eder ve stat/exploit bug'ı oluşur
	#define MARTYSAMA0134_FIXLERI_174				// Aynı pointType affect'i zaten varsa, eski değer ile yeni değer toplanır, eski affect silinir ve yeni toplam değerle eklenir. Bu, biyolog görevlerinde aynı bonusun üst üste binmesini önler.
	#define MARTYSAMA0134_FIXLERI_175				// Oyuncuyu öldüren oyuncunun HP'si fullenir.	
	#define MARTYSAMA0134_FIXLERI_176				// grid.h include'u olmadan CGrid sınıfı char.cpp'de tanınsız kalır.
	#define MARTYSAMA0134_FIXLERI_180				// Şaman'ın Grup Kutsama skill'i (vnum 109) başka bir oyuncuya kullanıldığında, hedef oyuncuda özel bir iyileşme efekti gösterilir. Sadece görsel bir iyileştirme.
	#define MARTYSAMA0134_FIXLERI_186				// Aksesuar Socket İçine Cevher Koyma (PUT_INTO_ACCESSORY_SOCKET)
		#ifdef MARTYSAMA0134_FIXLERI_186
		#define MARTYSAMA0134_FIXLERI_186_ORAN 100	// Yazılan oran Aksesuar Socket İçine Cevher Koyma şansı olarak işlenir
		#endif
	#define MARTYSAMA0134_FIXLERI_191				// Bağlantı kurulduktan sonra kısa bir sleep(1) ile DB'nin stabilize olması beklenir
	#define MARTYSAMA0134_FIXLERI_197				// RemoveAttributeType(BYTE) → RemoveAttributeType(int) çağırıyor Sonsuz döngü → Stack overflow → Core crash!
#endif


/*** KRİTİK HATA, ÇÖKME VE AÇIK DÜZELTMELERİ (CRASH / CORE / BUG / EXPLOIT / LEAK) ***/

/*** TAMAMLANMAMIŞ SİSTEMLER (YAKINDA) ***/
#define ENABLE_GUILDRENEWAL_SYSTEM					// Gelişmiş resmi gibi lonca altyapısı için çekirdek yenileme sistemi
	#ifdef ENABLE_GUILDRENEWAL_SYSTEM
		#define ENABLE_USE_MONEY_FROM_GUILD			// Lonca Parası ile ödeme yapmayı etkinleştirir
		#define ENABLE_NEW_WAR_OPTIONS				// Tur, puan ve süre bazlı modern lonca savaşı seçenekleri
		#define ENABLE_EXTENDED_GUILD_LEVEL			// Lonca seviye kapasitesinin 30'a çıkarılması
		//#define ENABLE_MEDAL_OF_HONOR				// Lonca ekonomisi için yeni para birimi (Onur Madalyası)
		#define ENABLE_GUILD_DONATE_ATTENDANCE		// Günlük lonca bağışı ve katılım takip sistemi
		#define ENABLE_GUILD_WAR_SCORE				// Lonca savaş istatistiklerinin detaylı skor ekranı
		#define ENABLE_GUILD_LAND_INFO				// Lonca arazilerine ait detaylı bilgi arayüzü
		#define ENABLE_GUILDBANK_LOG				// Lonca banka ve işlem kayıtlarının günlük sistemi
		#define ENABLE_GUILDBANK_EXTENDED_LOGS		// Genişletilmiş günlükler için Log.cpp bağlantısı
		#define ENABLE_EXTENDED_RENEWAL_FEATURES	// Lonca lideri devri ve arazi silme yönetimi gibi ek yenileme özellikleri
		#define ENABLE_COLEADER_WAR_PRIVILEGES		// Lider çevrimdışı olduğunda, Yardımcı Lider lider ile aynı yetkilere sahip olur
		#define ENABLE_GUILDWAR_BUTTON				// Arayüzde Lonca Savaşı erişim düğmesini aktif eder
		//#define ENABLE_GUILD_RANKING				// Loncalar arası sıralama sistemi (tam entegre edilmediği için kapalı)
		//#define ENABLE_GUILDSTORAGE_SYSTEM        // Loncanın ortak deposu: üyelerin paylaşımlı eşya deposu sistemi
	#endif
/*** TAMAMLANMAMIŞ SİSTEMLER (YAKINDA) ***/

/*
#@GENEL

#@common
@fixme301: tables.h üzerinde; TPlayerTable hp/mp int16_t'den int'e değiştirildi (hp/mp >32767 olmalı)

#@db/src
@fixme201: ProtoReader.cpp üzerinde; 'SAMLL' 'SMALL' olarak değiştirildi
@fixme202: ClientManagerGuild.cpp üzerinde; eğer oyuncu çevrimdışı ise lonca üyesi çıkarma zamanı sorunu düzeltildi 
			(withdraw_time -> new_withdraw_time)
@fixme203: ClientManagerPlayer.cpp üzerinde; "command" için boşta kalan gösterici (dangling pointer)
@fixme203: ClientManagerPlayer.cpp üzerinde; "command" için boşta kalan gösterici (dangling pointer)
@fixme204: Cache.cpp üzerinde; kişisel dükkanda aynı vnum’a sahip çok fazla eşya varsa, myshop_pricelist birincil anahtar çoğaltma hatası

#@game/src
@fixme102: cmd_general.cpp üzerinde ACMD(do_war) içinde unsigned hatası düzeltildi.
@fixme103: config, input_login, input_main.cpp dosyalarında clientcheckversion (sürüm > tarih) ifadesi (sürüm != tarih) ve gecikme süresi 10’dan 0’a olarak değiştirildi.
@fixme104: char.cpp, questlua_pc.cpp dosyalarında lv90'dan sonra statü puanı alma düzeltildi; 90 değeri gPlayerMaxLevel ile değiştirildi.
@fixme106: input_main.cpp dosyasında, yüksek hızdaki bir oyuncu binekteyken (örneğin, aslan) mesafe sınırı nedeniyle geri getirilecektir.
@fixme108: char.cpp dosyasında, mevcut binek 0 değilken bineği değiştirdiğinizde, yalnızca oyuncunun ekranındaki tüm nesneler (npc vb.) kaybolur.
@fixme109: questmanager.cpp dosyasında, bir oyuncu öldürüldüğünde (savaş m), `when kill begin` iki kez tetiklenir.
@fixme110: char_affect.cpp dosyasında, yarı saydamken (yeniden canlanmış, ninja yeteneği veya beyaz bayrak) saldırı yaptığınızda hala yarı saydam kalırsınız.
@fixme112: char_item.cpp dosyasında, tekrar giriş yapılana kadar ekipman üzerindeki bonuslar değiştirilebilir.
@fixme113: char_item.cpp dosyasında taşları çıkarırken, bonus kaybı olmadan çıkarılabilir.
@fixme114: char_item.cpp dosyasında, #111, #112 ve diğer birkaç hata bir araya getirildi.
@fixme115: char_item.cpp dosyasında, partideyseniz ve eşyaların sahibi siz değilse, yerdeki tüm eşyalar alınabilir.
@fixme116: char_skill.cpp dosyasında, normal at binme yetenekleri hasar veremez.
@fixme117: char_item.cpp dosyasında, envanter doluyken ekipman değiştirilemez ve boş olmadığında gereksiz kemer değişimleri engellenir.
@fixme118: char.cpp dosyasında ComputePoints çağrıldığında, ekipman bonusları kadar hp/mp kazanırsınız.
@fixme119: input_main.cpp dosyasında, kasadaki/alışveriş merkezindeki eşyalar kemer envanterine tür kontrolü olmadan yerleştirilebilir.
@fixme423: char_battle.cpp dosyasında, silahsızken bufflar devre dışı bırakıldı (VZK, AURA).
@fixme433: char_affect.cpp dosyasında, Bedensel Savaşçı'nın Hamle becerisi kullandığında HP düşmesi, Büyülü Silah Sura’nın Çözme ve İyileştirici Şaman’ın şifa gecikmesi hatası düzeltildi.
@fixme435: char_battle.cpp dosyasında, zehir canavarları artık agresifleştirmeyecek.
@fixme463: input_main.cpp dosyasında, 40. seviyenin altında lonca kurulamıyor.
@fixme469: char_battle.cpp dosyasında, arena haritasında hiçbir şey bırakılamaz.
@fixme499: battle.cpp dosyasında saldırı mesafesi düzeltildi.
@fixme502: char_item.cpp dosyasında kamp ateşi düzeltmesi.
@fixme503: battle.cpp ve pvp.cpp dosyalarında bekleme hack düzeltmesi.
@fixme504: char_battle.cpp dosyasında düzeltme yapıldı.
@fixme522: char_battle.cpp ve char_item.cpp dosyalarında farklı haritalarda Grup Exp/Yang/Düşüş Paylaşımı düzeltildi.
@fixme541: Performans düzenlemesi [Önek ++/-- operatörleri, ilkel olmayan türler için tercih edilmelidir.]
*/
#endif