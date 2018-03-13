#define DPROG "autofax2"
#include <sys/utsname.h> // utsname
// fuer verschiedene Sprachen //α
enum T_      
{
	T_virtVorgbAllg,
	T_pvirtVorgbSpeziell,
	T_virtMusterVorgb,
	T_pvirtvorrueckfragen,
	T_virtrueckfragen,
	T_Fehler_beim_Pruefen_von,
	T_Fuege_ein, //ω
	T_an_Fax,
	T_an_cFax,
	T_an_hFax,
	T_an_fFax,
	T_an,
	T_und,
	T_liescapiconf,
	T_MeiEinrichtung,
	T_Mei_FaxUeberschrift,
	T_Der_regulaere_Ausdruck,
	T_konnte_nicht_kompiliert_werden_Fehler,
	T_Zufaxen,
	T_zufaxen,
	T_Warteauffax,
	T_warteauffax,
	T_Nichtgefaxt,
	T_nichtgefaxt,
	T_empfvz,
	T_gesandt,
	T_zvz_k,
	T_zufaxenvz_l,
	T_faxt_die_Dateien_aus_pfad_anstatt_aus,
	T_wvz_k,
	T_wartevz_l,
	T_Dateien_warten_in_pfad_anstatt,
	T_ngvz_k,
	T_nichtgefaxtvz_l,
	T_Gescheiterte_Faxe_werden_hier_gesammelt_anstatt_in,
	T_evz_k,
	T_empfvz_l,
	T_Empfangsverzeichnis_fuer_Faxempfang,
	T_fbox_k,
	T_obfbox_l,
	T_Fritzbox_verwenden,
	T_fbankvz_k,
	T_fbankvz_l,
	T_Ankunftsverzeichnis_der_Fritzbox_ueber_CIFS,
	T_capi_k,
	T_obcapi_l,
	T_Capisuite_verwenden,
	T_hyla_k,
	T_obhyla_l,
	T_hylafax_verwenden,
	T_hz_k,
	T_hylazuerst_l,
	T_versuche_faxe_zuerst_ueber_Hylafax_wegzuschicken,
	T_mod_k,
	T_hmodem_l,
	T_Fuer_Hylafax_verwendetes_Modem,
	T_cz_k,
	T_capizuerst_l,
	T_versuche_faxe_zuerst_ueber_Capisuite_wegzuschicken,
	T_mc_k,
	T_maxcapiv_l,
	T_nach_zahl_Versuchen_Capisuite_wird_Hylafax_versucht,
	T_mh_k,
	T_maxhylav_l,
	T_nach_zahl_Versuchen_Hylafax_wird_Capisuite_verwendet,
	T_cuser_k,
	T_cuser_l,
	T_verwendet_fuer_Capisuite_Samba_den_Linux_Benutzer_string_anstatt,
	T_ckzl_k,
	T_cklingelzahl_l,
	T_Zahl_der_Klingeltoene_bis_Capisuite_den_Anruf_annimmt_anstatt,
	T_hkzl_k,
	T_hklingelzahl_l,
	T_Zahl_der_Klingeltoene_bis_Hylafax_den_Anruf_annimmt_anstatt,
	T_md_k,
	T_maxdials_l,
	T_Zahl_der_Wahlversuche_in_Hylafax,
	T_gz_k,
	T_gleichziel_l,
	T_Faxe_werden_auch_ohne_Faxerfolg_ins_Zielverzeichnis_kopiert,
	T_ocri_k,
	T_ocri_l,
	T_Text_aus_empfangenen_Faxen_wird_ermittelt,
	T_ocra_k,
	T_ocra_l,
	T_Text_aus_gesandten_Bildern_wird_ermittelt,
	T_afs_k,
	T_anfaxstr_l,
	T_faxnr_wird_hinter_string_erwartet_statt_hinter,
	T_acfs_k,
	T_ancfaxstr,
	T_faxnr_fuer_primaer_Capisuite_wird_hinter_string_erwartet_statt_hinter,
	T_ahfs_k,
	T_anhfaxstr_l,
	T_faxnr_fuer_primaer_hylafax_wird_hinter_string_erwartet_statt_hinter,
	T_as_k,
	T_anstr_l,
	T_Adressatenname_wird_hinter_string_erwartet_statt_hinter,
	T_us_k,
	T_undstr_l,
	T_Trennstring_string_fuer_mehrere_Adressaten_Telefonnummern_statt,
	T_find_k,
	T_find_l,
	T_Version_1_2_oder_3_Dateisuche_anstatt,
	T_loef,
	T_loeschefax_l,
	T_ein_Fax_nach_Rueckfrage_loeschen,
	T_loew,
	T_loeschewaise_l,
	T_Eintraege_aus,
	T_loeschen_zu_denen_kein_Datei_im_Wartevz_und_kein_Capi_oder_Hylafax_nachweisbar_ist,
	T_loea_k,
	T_loescheallew_l,
	T_alle_wartenden_Faxe_und_zugehoerige_Eintraege_aus,
	T_loeschen,
	T_erneut_k,
	T_erneutempf_l,
	T_empfangenes_Fax_erneut_bereitstellen,
	T_uml_k,
	T_umleiten_l,
	T_ausgehendes_Fax_vorzeitig_auf_zweitem_Weg_schicken,
	T_kez_k,
	T_korrerfolgszeichen_l,
	T_in_der_Datenbanktabelle,
	T_wird_das_Erfolgszeichen_korrigiert,
	T_bvz_k,
	T_bereinigevz_l,
	T_Dateien_aus_Warteverzeichnis_Gescheitertenvz_und_Gefaxtvz_gegen,
	T_pruefen_und_aufraeumen,
	T_st_k,
	T_stop_l,
	T_DPROG_anhalten,
	T_lista_k,
	T_listausg_l,
	T_listet_Datensaetze_aus,
	T_mit_Erfolgskennzeichen_auf,
	T_listf_k,
	T_listfailed_l,
	T_ohne_Erfolgskennzeichen_auf,
	T_listi_k,
	T_listinca_l,
	T__auf,
	T_listw_k,
	T_listwart_l,
	T_listet_wartende_Faxe_auf,
	T_s_k,
	T_suche_l,
	T_suche_in_verarbeiteten_Faxen_nach,
	T_n_k,
	T_dszahl_l,
	T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,
	T_vc_k,
	T_vc_l,
	T_Capisuite_Konfigurationdateien_bearbeiten,
	T_vh_k,
	T_vh_l,
	T_Hylafax_Modem_Konfigurationsdatei_bearbeiten,
	T_konfcapi,
	T_Capisuite_ist_offenbar_noch_nicht_richtig_konfiguriert,
	T_ist_Apostroph,
	T_Die_Einstellungen_koennen_spaeter_in,
	T_geaendert_werden,
	T_Faxnr_die_zum_Adressaten_gesandt_wird_bis_20_Zeichen_nur_plus_und_Ziffern,
	T_ausgehende_Multiple_Subscriber_Number_Faxnummer_ohne_Vorwahl,
	T_Amtsholung_ueblicherweise_kk_oder_0,
	T_Faxueberschrift,
	T_Adressat_empfangener_Faxe_die_ueber_Email_verteilt_werden,
	T_Zahl_der_Sendeversuche,
	T_kommagetrennte_Liste_mit_Sekundenabstaenden_zwischen_Sendeversuchen,
	T_Geduld_bis_zum_Verbindungsaufbau_in_s,
	T_komma_wert,
	T_komma_Altwert,
	T_Verschiebe,
	T_Fehler_beim_Verschieben,
	T_FehlerbeimUmbenennenbei,
	T_Kopiere_Doppelpunkt,
	T_Fehler_beim_Kopieren,
	T_Dateiname,
	T_schlechtgeformt,
	T_zielname_erstes_Ziel,
	T_zielname_Ausweichziel,
	T_Quelle_und_Ziel_gleich,
	T_entspricht,
	T_entsprichtnicht,
	T_entsprichtdoch,
	T_Muster_Doppelpunkt,
	T_pruefcvz,
	T_pruefcapi,
	T_capilaeuft,
	T_Module_geladen,
	T_Lade_Capi_Module,
	T_Kernelversion,
	T_KannFcpciNInstVerwCapiNicht,
	T_eine_neuere_Version_als_die_des_aktuellen_Kernels_installiert_worden_sein_dann_bitte_erneutes_Systemupdate,
	T_nichtgefFcpciMfdKinstallierwerden,
	T_Zur_Inbetriebnahme_der_Capisuite_muss_das_Modul_capi_geladen_werten,
	T_Bitte_zu_dessen_Verwendung_den_Rechner_neu_starten,
	T_aufrufen,
	T_Moment_muss_Kernel_herunterladen,
	T_Der_Kernel_hat_sich_offenbar_seit_dem_Einloggen_von,
	T_nach_,
	T_verjuengt_Bitte_den_Rechner_neu_starten_und_dann_mich_nochmal_aufrufen,
	T_Konnte,
	T_nichtstarten,
	T_StarteCapisuite,
	T_Capisuite_gestartet,
	T_konntecapisuiteservice,
	T_malnichtstartenverwN,
	T_pruefrules,
	T_pruefblack,
	T_haengean,
	T_an_mdpp,
	T_pruefsfftobmp,
	T_clieskonf,
	T_pruefmodcron,
	T_Zahl_der_SQL_Befehle_fuer_die_Absenderermittlung,
	T_SQL_Befehl_Nr,
	T_Zielmuster_Nr,
	T_Ziel_Nr,
	T_Zahl_der_Muster_Verzeichnis_Paare_zum_Speichern_ankommender_Faxe,
	T_MAX //α
}; // enum T_ //ω

enum FaxTyp:uchar {capi=1,hyla};
enum FxStat:uchar {init/*0*/,gestrichen,schwebend,wartend/*3*/,blockiert/*4*/,bereit/*5*/,verarb/*6*/,gesandt/*7*/,gescheitert/*8*/,fehlend,woasined};
enum hyinst {keineh,hysrc,hypak,hyppk}; // hyla source, hyla Paket, hylaplus Paket
void dorename(const string& quelle, const string& ziel, const string& cuser=nix, uint *vfehlerp=0, uchar schonda=0, int obverb=0, int oblog=0,
                  stringstream *ausgp=0);
class zielmustercl; // fuer die Verteilung der erfolgreich gefaxten Dateien auf verschiedene Dateien
string kopiere(const string& qdatei, const string& zield, uint *kfehler, const uchar wieweiterzaehl, int obverb=0, int oblog=0);
string kopiere(const string& qdatei, const zielmustercl& zmp, uint *kfehler, const uchar wieweiterzaehl, int obverb=0, int oblog=0);
string zielname(const string& qdatei, const string& zielvz,uchar wieweiterzaehl=0, string* zieldatei=0, uchar* obgleichp=0, 
                int obverb=0, int oblog=0, stringstream *ausgp=0);
string zielname(const string& qdatei, const zielmustercl& zmp,uchar wieweiterzaehl=0, string* zieldatei=0, uchar* obgleichp=0, int obverb=0, 
                int oblog=0, stringstream *ausgp=0);
void pruefrules(int obverb, int oblog);


// Steuerung der Abspeicherung gesendeter Faxe je nach Muster
class zielmustercl 
{
  // beim letzten Element muss ziel leer sein!
  public:
    string muster;
    string ziel;
    regex_t regex;
    // wird nur in Vorgaben gebraucht:
    zielmustercl(const char * const muster,const char * const ziel);
    zielmustercl(const char * const muster,const string& ziel);
    zielmustercl(const string& muster,const string& ziel);
    zielmustercl();
    int kompilier(const uchar obext=1);
    int setzemuster(const string& vmuster,const uchar obext=1);
    const string& holmuster() const;
    int obmusterleer() const;
}; // class zielmustercl

//α
class hhcl:public dhcl
{
 private: //ω
    int hylazuerst=-1;  // ob ein Fax zuerst ueber Hylafax versucht werden soll zu faxen
    //    string hmodemstr; // Erkennung des Faxgeraetes nach /dev/tty, Standard ACM
    string maxcapiv; // maximale Versuchnr in Capi, bis Hyla versucht wird
		void virttesterg();
    string maxhylav; // maixmale Versuchsnr in Hylafax, bis Capi versucht wird
    string maxhdials;     // Zahl der Wahlversuche in Hylafax
		string maxcdials;    // Zahl der Wahlversuche in Capisuite
    int gleichziel=-1; // faxe auch ohne Fax-Erfolg auf Zielverzeichnis abspeichern
    int obocri=-1; // empfangene Faxe OCR unterziehen
    int obocra=-1; // gesandte Bilder OCR unterziehen
    string anfaxstr, ancfaxstr, anhfaxstr, anffaxstr; // 'an Fax', "an cFax", "an hFax", "an fFax"
    string anstr; // ' an '
    string undstr;  //  'und'

    uchar capizukonf=0; // capi zu konfigurieren
    uchar hylazukonf=0; // hyla zu konfigurieren
		string findvers; // find-Version (1=linux find, 2=intern mit readdir, 3=intern mit nftw 
		int ifindv; // integer-Variante der find-Version
    string dbq; // Datenbank

    servc *sfaxq=0, *shfaxd=0, *shylafaxd=0, *sfaxgetty=0, *scapis=0;
    confdcl *cfaxcp=0; // Zeiger auf ausgelesene /etc/capisuite/fax.conf
		const string s1="mv -n ";
		//		const string s2="/2200/* ";
		//schlArr hylcnfA; // fuer q1234 o.ae.
		uchar hgelesen=0; // Protokolldatei war auslesbar
		static constexpr const char *moeglhvz[2]={"/var/spool/fax","var/spool/hylafax"};
		string huser="uucp"; // "uucp" oder "fax"
    uchar obfcard=1;    // ob Fritzcard eingesteckt
    uchar obfcgeprueft=0; // ob schon geprueft, ob Fritzcard eingesteckt
    uchar obmodem=1;    // ob Modem angeschlossen
    uchar obmdgeprueft=0; // ob schon geprueft, ob Modem verfuegbar
    uchar obocrgeprueft=0; // ob ocrmypdf installiert ist
    const string spooltab="spool";
    const string altspool="altspool"; // Historie der Spooltabelle
    const string udoctab="udoc";
    uchar obvi=0;   // ob Konfigurationsdatei editiert werden soll
    uchar obvc=0;   // ob Capisuite-Konfigurationsdateien betrachtet werden sollen
		uchar obvh=0;   // ob Hylafax-Konfigurations- und Logdateindatei betrachtet werden sollen
		uchar obvs=0;   // ob Quelldateien bearbeitet werden sollen
    uchar loef=0;   // loesche eine Fax-Datei
    uchar loew=0;  // loeschewaise in der Datenbank, aber nicht mehr real nachweisbare Dateien in der Datenbank loeschen
    uchar loea=0; // loesche alle wartenden Faxe und zugehoerige Dateieintraege
    uchar loee=0; // empfangene Dateien loeschen, die nicht verarbeitet werden koennen
		uchar erneut=0;  // empfangenes Fax erneut bereitstellen
		uchar uml=0; // umleiten: vorzeitig den zweiten Weg aktivieren
    uchar kez=0;    // korrigiere Erfolgskennzeichen
    uchar bvz=0;    // bereinige Gescheitertenverzeichnis, letztes Gefaxtverzeichnis und Warteverzeichnis
    uchar anhl=0;    // <DPROG> anhalten
    uchar lista=0;   // liste Archiv auf
    uchar listf=0;   // liste gescheiterte auf
    uchar listi=0;   // liste Eingegangene auf
    uchar listw=0;   // liste wartende auf
    string suchstr;  // Wortteil, nach dem in alten Faxen gesucht werden soll
    string dszahl="30"; // Datensatzzahl fuer Tabellenausgaben
		size_t faxord=0; // Ordinalzahl des Faxes unter allen anstehenden Faxen
		ulong geszahl=0;
    ulong ankzahl=0; // Zahl der angekommenen Faxe
    ulong dbzahl=0; // Zahl der ueberprueften Datenbankeintraege
    ulong wzahl=0;
    ulong ezahl=0; // Zahl der Erfolgreichen
    ulong gzahl=0;
    ulong fzahl=0;
    ulong weizahl=0; // Zahl der weiteren wartenden Faxe, die nicht in der Spooltabelle dieses Programms eingetragen sind
    int obfbox=-1; // ob ueberhaupt die Fritzbox verwendet werden soll, gesetzt in: pruefisdn(), lieskonfein(), rueckfragen(), getcommandline(), main()
    int obcapi=-1; // ob ueberhaupt die Capisuite verwendet werden soll, gesetzt in: pruefisdn(), lieskonfein(), rueckfragen(), getcommandline(), main()
    int obhyla=-1; // ob ueberhaupt hylafax verwendet werden soll
    uchar konfobfbox; // ob obfbox in der Konfigurationsdatei eingestellt ist
    uchar konfobcapi; // ob obcapi in der Konfigurationsdatei eingestellt ist
    uchar konfobhyla; // ob obhyla in der Konfigurationsdatei eingestellt ist
    //    string hmodemstr; // Erkennung des Faxgeraetes nach /dev/tty, Standard ACM
    string hmodem;    // erkanntes und laufendes Modem ttyACM0
    //    string hmodname;  // ttyACM0
		string cuser; // Linux-Benutzer fuer Capisuite, Samba
    const string touta="outa"; // MariaDB-Tabelle fuer gesandte oder gescheiterte Faxe
    const string tudoc="udoc"; // MariaDB-Tabelle fuer gesandte oder gescheiterte Faxe
    const string tinca="inca"; // MariaDB-Tabelle fuer empfangene Faxe

    string zufaxenvz;
    string wvz; // Warteverzeichnis
    string ngvz; // Nichtgefaxt-Verzeichnis (Gescheiterte)
    string empfvz; // Empfangsverzeichnis
		string fbankvz;  // auf CIFS gemountetes NAS-Verzeichnis der Fritzbox mit ankommenden Faxen

    string countrycode; // Landesvorwahl
    string LongDistancePrefix; // Vorsatz fuer ausserorts
    string InternationalPrefix; // Vorsatz fuer ausserlandes
    string cklingelzahl; // Zahl der Klingeltoene, bis Capisuite einen Anruf annnimmt
    string hklingelzahl; // Zahl der Klingeltoene, bis Hylafax einen Anruf annnimmt
    string cfaxconfdt; // /etc/capisuite/fax.conf oder /usr/local/etc/capisuite/fax.conf laut Handbuch
		string cfaxconfeigdt; // ~/autofax/cfaxconfdt
    string spoolcapivz; // Verzeichnis der Capi-Spool-Dateien /var/spool/capisuite/
    string ccapiconfdt; // /etc/capisuite/capisuite.conf oder /usr/local/etc/capisuite/capisuite.conf laut Handbuch
		string cempfavz; //  /var/spool/capisuite/" DPROG "arch/
    string cfaxuservz;    // /var/spool/capisuite/users/
    string nextdatei;  // /var/spool/capisuite/users/<user>/sendq/fax-nextnr
    string cfaxusersqvz;    // /var/spool/capisuite/users/<user>/sendq
    string cfaxuserrcvz;    // /var/spool/capisuite/users/<user>/received
		string cfaxuserrcfalschevz;  // /var/spool/capisuite/users/<user>/received/falsche
    string cdonevz; // Capisuite-Archiv: /var/spool/capisuite/done
    string cfailedvz; // Capisuite-Archiv der gescheiterten /var/spool/capisuite/failed
		string /*spool_dir(spoolcapivz),*/fax_user_dir,/*send_tries(maxcdials),*/send_delays,outgoing_MSN, dial_prefix,fax_stationID,fax_headline,fax_email_from,outgoing_timeout; // capisuite: fax.conf
		string cdn[4]; // in capisuite.conf genannte Dateien: incoming_script, log_file, log_error, idle_script
    string citycode;    // Ortsvorwahl
    string msn;         // MSN fuer Fax
    string LocalIdentifier; // eigener Namen fuer Hylafax bis 10 Buchstaben
    string cFaxUeberschrift; // eigener Namen fuer Capisuite bis 20 Buchstaben
		schAcl<optcl> opsql,opzm,opvsql,opvzm; // Optionen

#ifdef _WIN32
    char cpt[255];
    DWORD dcpt;
#elif linux // _WIN32
    char cpt[MAXHOSTNAMELEN]; 
    size_t cptlen;
#endif // _WIN32 else
    string host="localhost";  // fuer MySQL/MariaDB

		schAcl<WPcl> cfcnfC; // Capikonfiguration aus fax.conf
		schAcl<WPcl> cccnfC; // Capikonfiguration aus capisuite.conf
 protected: //α
	string p1;
	int p2;
	string p3;
	uchar oblista=0;
	long listz=30; //ω

	size_t sqlzn=0; // Zahl der SQL-Befehle numerisch
	string* sqlp; // Array der SQL-Befehle
	//    string sqlz;  // Zahl der SQL-Befehle
	//    size_t sqlzn=0; // Zahl der SQL-Befehle numerisch
	string sqlvz;  // Zahl der SQL-Befehle aus Vorgaben
	size_t sqlvzn=0; // Zahl der SQL-Befehle aus Vorgaben numerisch
	string* sqlvp; // Array der Vorgabe-SQL-Befehle

	size_t zmzn=0; // Zahl der Zielmusterpaare numerisch
	string *zmmp; // Array der Zielmuster
	string *zmzp; // Array der Ziele
	zielmustercl *zmp; // Zielmusterzeiger
	size_t zmvzn=0; // Zielmusterzahl numerisch aus Vorgaben
	zielmustercl *zmvp; // Zielmusterzeiger aus Vorgaben

 public: //α //ω
 private: //α //ω
	void cfcnfCfuell();
	void cccnfCfuell();
	void liescapiconf();
	void konfcapi(); // aufgerufen in pruefcapi
	void capisv();
	int pruefcapi();
	int cservice();
	void clieskonf();
	void pruefcvz();
	void pruefsfftobmp();
	void instsfftobmp();
	void nextnum();
	void pruefmodcron();
	void dovc();
	void virtlieskonfein();
	void virtautokonfschreib();
 protected: //α
	// void virtlgnzuw(); // wird aufgerufen in: virtrueckfragen, parsecl, lieskonfein, hcl::hcl nach holsystemsprache
	void virtVorgbAllg();
	void pvirtVorgbSpeziell()
#ifdef VOMHAUPTCODE
		__attribute__((weak)) // implementationsspezifische Vorgaben, Modul vgb.cpp)
#endif
		;
	void virtinitopt(); // (programm-)spezifische Optionen
	void pvirtmacherkl();
	void virtMusterVorgb();
	void virtzeigversion(const string& ltiffv=nix);
	void pvirtvorrueckfragen();
	void virtrueckfragen();
	void virtpruefweiteres();
	void virtzeigueberschrift();
	void pvirtfuehraus();
	void virtschlussanzeige(); //ω
 public: //α
  hhcl(const int argc, const char *const *const argv);
	~hhcl();
}; // class hhcl //ω
