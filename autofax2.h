#define DPROG "autofax2"
#include <sys/utsname.h> // utsname

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
  private:
    string muster;
  public:
    string ziel;
    regex_t regex;
    // wird nur in Vorgaben gebraucht:
    zielmustercl(const char * const muster,const char * const ziel);
    zielmustercl(const char * const muster,const string& ziel);
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
    uchar hylazuerst;  // ob ein Fax zuerst ueber Hylafax versucht werden soll zu faxen
    //    string hmodemstr; // Erkennung des Faxgeraetes nach /dev/tty, Standard ACM
    string maxcapiv; // maximale Versuchnr in Capi, bis Hyla versucht wird
		void virttesterg();
    string maxhylav; // maixmale Versuchsnr in Hylafax, bis Capi versucht wird
    string maxhdials;     // Zahl der Wahlversuche in Hylafax
		string maxcdials;    // Zahl der Wahlversuche in Capisuite
    uchar gleichziel; // faxe auch ohne Fax-Erfolg auf Zielverzeichnis abspeichern
    uchar obocri; // empfangene Faxe OCR unterziehen
    uchar obocra; // gesandte Bilder OCR unterziehen
    string anfaxstr, ancfaxstr, anhfaxstr, anffaxstr; // 'an Fax', "an cFax", "an hFax", "an fFax"
    string anstr; // ' an '
    string undstr;  //  'und'

    uchar capizukonf=0; // capi zu konfigurieren
    uchar hylazukonf=0; // hyla zu konfigurieren
		string findvers; // find-Version (1=linux fund 2=intern mit readdir, 3=intern mit nftw 
		int ifindv; // integer-Variante der find-Version
    string dbq; // Datenbank
    string muser; // Benutzer fuer Mysql/MariaDB

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
    uchar obfbox=1; // ob ueberhaupt die Fritzbox verwendet werden soll, gesetzt in: pruefisdn(), lieskonfein(), rueckfragen(), getcommandline(), main()
    uchar obcapi=1; // ob ueberhaupt die Capisuite verwendet werden soll, gesetzt in: pruefisdn(), lieskonfein(), rueckfragen(), getcommandline(), main()
    uchar obhyla=1; // ob ueberhaupt hylafax verwendet werden soll
    uchar konfobfbox; // ob obfbox in der Konfigurationsdatei eingestellt ist
    uchar konfobcapi; // ob obcapi in der Konfigurationsdatei eingestellt ist
    uchar konfobhyla; // ob obhyla in der Konfigurationsdatei eingestellt ist
    //    string hmodemstr; // Erkennung des Faxgeraetes nach /dev/tty, Standard ACM
    string hmodem;    // erkanntes und laufendes Modem ttyACM0
    //    string hmodname;  // ttyACM0
		string cuser; // Linux-Benutzer fuer Capisuite, Samba
    string mpwd;  // Passwort fuer Mysql/MariaDB
    const string touta="outa"; // MariaDB-Tabelle fuer gesandte oder gescheiterte Faxe
    const string tudoc="udoc"; // MariaDB-Tabelle fuer gesandte oder gescheiterte Faxe
    const string tinca="inca"; // MariaDB-Tabelle fuer empfangene Faxe

//    string sqlz;  // Zahl der SQL-Befehle
//    size_t sqlzn=0; // Zahl der SQL-Befehle numerisch
    string sqlvz;  // Zahl der SQL-Befehle aus Vorgaben
    size_t sqlvzn=0; // Zahl der SQL-Befehle aus Vorgaben numerisch
    string zufaxenvz;
    string wvz; // Warteverzeichnis
    string ngvz; // Nichtgefaxt-Verzeichnis (Gescheiterte)
    string empfvz; // Empfangsverzeichnis
		string fbankvz;  // auf CIFS gemountetes NAS-Verzeichnis der Fritzbox mit ankommenden Faxen
    zielmustercl *zmvp; // Zielmusterzeiger aus Vorgaben
    size_t zmvzn=0; // Zielmusterzahl numerisch aus Vorgaben

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
	long sqlzn=0; // Zahl der SQL-Befehle numerisch
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
