// '//α' oder '//ω' als Kommentar sind nur für die Verwendung dieses Programms als Programmvorlage wichtig
// sed -n '/\/\/α/,/\/\/ω/p;/\/\/ω/a\\' test
// sed -n '/\/\/α/,/\/\/ω/p' test
#include "kons.h" //α
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "autofax2.h"
// für verschiedene Sprachen //α
enum T_      
{
	T_virtVorgbAllg,
	T_virtVorgbSpeziell,
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
	T_MAX //α
}; // enum T_ //ω
// für verschiedene Sprachen //α
char const *DPROG_T[T_MAX+1][SprachZahl]={
	// T_virtVorgbAllg
	{"virtVorgbAllg()","virtgeneralprefs()"},
	// T_virtVorgbSpeziell
	{"pvirtVorgbSpeziell()","pvirtspecialprefs()"},
	// T_virtMusterVorgb
	{"virtMusterVorgb()","virtsampleprefs"},
	// T_pvirtvorrueckfragen
	{"pvirtvorrueckfragen()","pvirtbeforecallbacks()"},
	// T_virtrueckfragen
	{"virtrueckfragen()","virtcallbacks()"},
	//	T_Fehler_beim_Pruefen_von
	{"Fehler beim Pruefen von: ","Error while examining: "},
	// T_Fuege_ein
	{"Fuege ein: ","Inserting: "}, //ω
	// T_an_Fax
	{"an Fax","to fax"},
	// T_an_cFax,
	{"an cFax","to cfax"},
	// T_an_hFax
	{"an hFax","to hfax"},
	// T_an_fFax
	{"an fFax","to ffax"},
	// T_an,
	{" an "," to "},
	// T_und
	{"und","and"},
	// T_liescapiconf
	{"liescapiconf()","readcapiconf()"},
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;

using namespace std; //ω
hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG) //α
{
 // mitcron=0; //ω
} // hhcl::hhcl //α

// aufgerufen in liescapiconf
void hhcl::zcnfCfuell()
{
	static uchar neu=1;
	if (neu) {	
		zcnfA<<WPcl("spool_dir",&spool_dir,wstr);
		zcnfA<<WPcl("fax_user_dir",&fax_user_dir,wstr);
		zcnfA<<WPcl("send_tries",&send_tries,wstr);
		zcnfA<<WPcl("send_delays",&send_delays,wstr);
		zcnfA<<WPcl("outgoing_MSN",&outgoing_MSN,wstr);
		zcnfA<<WPcl("dial_prefix",&dial_prefix,wstr);
		zcnfA<<WPcl("fax_stationID",&fax_stationID,wstr);
		zcnfA<<WPcl("fax_headline",&fax_headline,wstr);
		zcnfA<<WPcl("fax_email_from",&fax_email_from,wstr);
		zcnfA<<WPcl("outgoing_timeout",&outgoing_timeout,wstr);
		neu=0;
	} // 	if (neu)
} // void hhcl::zcnfCfuell

// in virtVorgbAllg, pruefcapi
void hhcl::liescapiconf()
{
	Log(violetts+Tx[T_liescapiconf]+schwarz);
	svec qrueck;
	const string wo="/etc/capisuite /usr/local/etc/capisuite";
	const string moegl="find "+wo+" -type f -name ";
	if (findv==1) {
		systemrueck(moegl+"fax.conf",obverb-2,oblog,&qrueck,/*obsudc=*/0);
	} else findfile(&qrueck,findv,obverb,oblog,0,wo,/*muster=*/"/fax\\.conf$");
	if (qrueck.size()) cfaxconfdt=qrueck[0];
	zcnfCfuell();

	if (!cfaxconfdt.empty()) {
		pruefverz(dir_name(cfaxconfdt),obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0);
		confdcl capc;
		capc.lies(cfaxconfdt,obverb);
		////<<"azaehlerdt: "<<blau<<azaehlerdt<<schwarz<<endl;
		capc.auswert(&zcnfC);
		caus<<"spool_dir: "<<spool_dir<<endl;
		caus<<"fax_user_dir: "<<fax_user_dir<<endl;
	}
#ifdef false
	cfcnfA.init(10,"spool_dir","fax_user_dir","send_tries","send_delays","outgoing_MSN",
			"dial_prefix","fax_stationID","fax_headline","fax_email_from","outgoing_timeout");
	if (!cfaxconfdt.empty()) {
		pruefverz(dir_name(cfaxconfdt),obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0);
		static confdat cfaxcd(cfaxconfdt,&cfcnfA,obverb);
		cfaxcdtp=&cfaxcd;
		cfaxcdtp->Abschn_auswert(obverb);
		// wenn sich cuser in cfaxcd findet, dann so lassen
		// wenn nicht, dann:
		//   wenn cuser leer, dann den ersten besten user nehmen
		//   sonst cuser setzen
		////    cuser="";
		string ncuser;
		for(size_t i=cfaxcd.zn.size();i>0;) {
			char buf[250]={0};
			if ((sscanf(cfaxcd.zn[--i].c_str(),"[%[^]]]",buf))>0) 
				if (strcasecmp(buf,"global")) {
					if (!cuser.empty()) {
						if (cuser==buf) {
							ncuser.clear();
							break;
						} //            if (cuser==buf)
					} //           if (!cuser.empty())
					if (ncuser.empty()) ncuser=buf; // nehme den letzten besten user
				} //         if (strcasecmp(buf,"global"))
		} //     for(size_t i=cfaxcd.zn.size();i>0;)
		if (cuser.empty()) 
			cuser=ncuser;
		if (cuser.empty()) {
			if (cus.cuid)
				cuser=cus.cusstr;
			hylazuerst=1;
		} //     if (cuser.empty())
	} //   if (!cfaxconfdt.empty())
	maxcdials=cfcnfA[2].wert; // 14.10.16
	if (cfcnfA[0].wert.empty()) {
		spoolcapivz="/var/spool/capisuite";
	}  else {           
		spoolcapivz=cfcnfA[0].wert;
		kuerzevtz(&spoolcapivz);
		cfaxuservz=cfcnfA[1].wert;
	} // if (cfcnfA[0].wert.empty()) else
	cempfavz=spoolcapivz+"/" DPROG "arch";
	if (cfaxuservz.empty())
		cfaxuservz=spoolcapivz+"/users";
	//// <<rot<<"cfaxuservz in Vorgallg: "<<cfaxuservz<<schwarz<<endl;
	qrueck.clear();
	if (findv==1) {
		systemrueck(moegl+"capisuite.conf",obverb-2,oblog,&qrueck,/*obsudc=*/0);
	} else findfile(&qrueck,findv,obverb,oblog,0,wo,/*muster=*/"/capisuite\\.conf$");
	if (qrueck.size()) {
		ccapiconfdt=qrueck[0];
	} //   if (qrueck.size())
	if (!ccapiconfdt.empty()) {
		uchar obneuer=0;
		struct stat cstat={0};
		static time_t lgelzeit=0; // Aenderungszeitpunkt der evtl. zuletzt eingelesenen ccapiconfdt
		time_t aktgelzeit;
		if (!lstat(ccapiconfdt.c_str(),&cstat)) { //// <<rot<<ccapiconfdt<<" existiert!"<<schwarz<<endl;
			aktgelzeit=cstat.st_mtime;
			if (aktgelzeit>lgelzeit) {
				lgelzeit=aktgelzeit;
				obneuer=1;
			} //       if (aktgelzeit>lgelzeit)
		} // if (!lstat(ccapiconfdt.c_str(),&cstat)) 
		if (obneuer || !cccnfA.zahl) {
			if (!cccnfA.zahl) {
				cccnfA.init(4,"incoming_script","log_file","log_error","idle_script");
			} else {
				cccnfA.reset();
			} //       if (!cccnfA.zahl) else
			confdat ccapicd(ccapiconfdt,&cccnfA,obverb);
			if (!cuser.empty()) {
				for(size_t j=0;j<cccnfA.zahl;j++) {
					if (!cccnfA[j].wert.empty()) {
						struct stat statdat={0};
						if (!lstat(cccnfA[j].wert.c_str(),&statdat)) {
							setfaclggf(cccnfA[j].wert,obverb>1?obverb-1:0,oblog,/*obunter=*/falsch,/*mod=*/6);
						} //             if (!lstat(cccnfA[j].wert.c_str(),&statdat))
					} // if (!cccnfA[j].wert.empty()) 
				} // for(size_t j=1;j<3;j++) 
			} // if (!cuser.empty()) 
		} // if (obneuer || !cccnfA.zahl) 
	} // if (!ccapiconfdt.empty())

	if (!spoolcapivz.empty()) {
		cdonevz = mitvtz(spoolcapivz)+"done";
		cfailedvz = mitvtz(spoolcapivz)+"failed";
	} //   if (!spoolcapivz.empty())
#endif
} // void hhcl::liescapiconf()

// wird aufgerufen in lauf
void hhcl::virtVorgbAllg()
{
	Log(violetts+Tx[T_virtVorgbAllg]+schwarz); //ω
	liescapiconf();
	hylazuerst=0;
	//// hmodemstr="ACM";
	maxcapiv="3";
	maxhylav="3";
	maxhdials="11";
	gleichziel=1;
	obocri=1;
	obocra=0;
	anfaxstr=Tx[T_an_Fax];
	ancfaxstr=Tx[T_an_cFax];
	anhfaxstr=Tx[T_an_hFax];
	anffaxstr=Tx[T_an_fFax];
	anstr=Tx[T_an];
	undstr=Tx[T_und];
	countrycode="49";
	LongDistancePrefix="0";
	InternationalPrefix="00";
	cklingelzahl="1";
	hklingelzahl="2"; // muss mindestens 2 sein, um die Nr. des anrufenden zu uebertragen
	// um z.B. spezielle Vorgaben (s. VorgbSpeziell) vom Server abhaengig machen zu koennen
#ifdef _WIN32
	//// char lpszUsername[255]; DWORD dUsername = sizeof(lpszUsername); GetUserName(lpszUsername, &dUsername);
	dcpt = sizeof(cpt);
	GetComputerName(cpt,&dcpt);
#elif linux // WIN32
	//// uid_t userId = getuid(); passwd* pw = getpwuid(userId); pw->pw_name<<endl;
	cptlen = MAXHOSTNAMELEN;
	gethostname(cpt, cptlen);
#endif // WIN32 else
	dhcl::virtVorgbAllg(); //α
} // void hhcl::virtVorgbAllg

// wird aufgerufen in lauf
void hhcl::pvirtVorgbSpeziell()
{
	Log(violetts+Tx[T_virtVorgbSpeziell]+schwarz); //ω
	dhcl::pvirtVorgbSpeziell(); //α
	virtMusterVorgb();
} // void hhcl::pvirtVorgbSpeziell

// wird aufgerufen in lauf
void hhcl::virtinitopt()
{ //ω
	dhcl::virtinitopt(); //α
} // void hhcl::virtinitopt

// wird aufgerufen in lauf
void hhcl::pvirtmacherkl()
{
	erkl<<blau<<Txk[T_Program]<<violett<<DPROG //ω
		<<blau<<" ist etwas ganz Spezielles"<<schwarz; //α
} // void hhcl::pvirtmacherkl

// wird aufgerufen in lauf
void hhcl::virtMusterVorgb()
{
	Log(violetts+Tx[T_virtMusterVorgb]+schwarz); //ω
	dhcl::virtMusterVorgb(); //α
} // void hhcl::MusterVorgb

// wird aufgerufen in lauf
void hhcl::virtzeigversion(const string& ltiffv/*=nix*/)
{ //ω
	dhcl::virtzeigversion(ltiffv); //α
} // void hhcl::virtzeigversion

// wird aufgerufen in lauf
void hhcl::pvirtvorrueckfragen()
{
	Log(violetts+Tx[T_pvirtvorrueckfragen]+schwarz);
	if (rzf) { //ω
  } //α
} // void hhcl::pvirtvorrueckfragen

// wird aufgerufen in lauf
void hhcl::virtrueckfragen()
{
	Log(violetts+Tx[T_virtrueckfragen]+schwarz);
	if (rzf) { //ω
  } //α
	dhcl::virtrueckfragen();
} // void hhcl::virtrueckfragen()

// wird aufgerufen in lauf
void hhcl::virtpruefweiteres()
{ //ω
	hcl::virtpruefweiteres(); // z.Zt. leer //α
} // void hhcl::virtpruefweiteres

// wird aufgerufen in lauf
void hhcl::virtzeigueberschrift()
{ //ω
  // hier ggf. noch etwas an 'uebers' anhaengen //α
	hcl::virtzeigueberschrift();
} // void hhcl::virtzeigueberschrift

// wird aufgerufen in lauf
void hhcl::pvirtfuehraus()
{ //ω
} // void hhcl::pvirtfuehraus  //α

// wird aufgerufen in lauf
void hhcl::virtschlussanzeige()
{   //ω
	dhcl::virtschlussanzeige(); //α
} // void hhcl::virtschlussanzeige
 //ω
int main(int argc,char** argv) //α
{
	if (argc>1) { //ω
	} //α
	hhcl hhi(argc,argv); // hiesige Hauptinstanz, mit lngzuw, setzlog und pruefplatte
	hhi.lauf(); // Einleitungsteil mit virtuellen Funktionen, 
	// mit virtVorgbAllg,pvirtVorgbSpeziell,initopt,parsecl,pvirtmacherkl,zeighilfe,lieskonfein,verarbeitkonf,lieszaehlerein,MusterVorgb,dovi,dovs,virtzeigversion
	// autokonfschreib,update,
} // int main //ω
