// '//α' oder '//ω' als Kommentar sind nur fuer die Verwendung dieses Programms als Programmvorlage wichtig
// sed -n '/\/\/α/,/\/\/ω/p;/\/\/ω/a\\' test
// sed -n '/\/\/α/,/\/\/ω/p' test
#include "kons.h" //α
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "autofax2.h"
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
	T_MAX //α
}; // enum T_ //ω
// fuer verschiedene Sprachen //α
char const *DPROG_T[T_MAX+1][SprachZahl]={
	// T_virtVorgbAllg
	{"virtVorgbAllg()","virtgeneralprefs()"},
	// T_pvirtVorgbSpeziell
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
	// T_MeiEinrichtung
	{"MeiEinrichtung","MyInstitution"},
	// T_Mei_FaxUeberschrift
	{"Mei FaxUeberschrift","My fax headline"},
	// T_Der_regulaere_Ausdruck
	{"Der regulaere Ausdruck '","The regular expression '"},
	// T_konnte_nicht_kompiliert_werden_Fehler
	{"' konnte nicht kompiliert werden, Fehler: ","could not be compiled, error: "},
	// T_Zufaxen
	{"Zufaxen","TobeFaxed"},
	// T_zufaxen
	{"zufaxen","tobefaxed"},
	// T_Warteauffax
	{"Warteauffax","WaitingFaxes"},
	// T_warteauffax,
	{"warteauffax","waitingfaxes"},
	// T_Nichtgefaxt
	{"Nichtgefaxt","NotFaxed"},
	// T_nichtgefaxt,
	{"nichtgefaxt","notfaxed"},
	// T_empfvz
	{"empfvz","recvdir"},
	// T_gesandt
	{"gesandt","sent"},
	// T_zvz_k
	{"zvz","tdr"},
	// T_zufaxenvz_l
	{"zufaxenvz","tofaxdir"},
	// T_faxt_die_Dateien_aus_pfad_anstatt_aus
	{"faxt die Dateien aus <pfad> anstatt aus","faxes the files from <path> instead of"},
	// T_wvz_k
	{"wvz","wdr"},
	// T_wartevz_l
	{"wartevz","waitdir"},
	// T_Dateien_warten_in_pfad_anstatt
	{"Dateien warten in <pfad> anstatt","files are waiting in <path> instead of"},
	// T_ngvz_k
	{"ngvz","ndr"},
	// T_nichtgefaxtvz_l
	{"nichtgefaxtvz","notfaxeddir"},
	// T_Gescheiterte_Faxe_werden_hier_gesammelt_anstatt_in
	{"Gescheiterte Faxe werden hier gesammelt anstatt in","Failed Faxes are collected here and not in"}, 
	// T_evz_k
	{"evz","rdr"},
	// T_empfvz_l
	{"empfvz","receiveddir"},
	// T_Empfangsverzeichnis_fuer_Faxempfang
	{"Empfangsverzeichnis fuer Faxempfang","directory for recieved faxes"},
	// T_fbox_k
	{"fbox","fbox"},
	// T_obfbox_l
	{"obfbox","takefbox"},
	// T_Fritzbox_verwenden
	{"Fritzbox verwenden","use fritzbox"},
	// T_fbankvz_k
	{"fbvz","fbdr"},
	// T_fbankvz_l
	{"fritzboxvz","fritzboxdir"},
	// T_Ankunftsverzeichnis_der_Fritzbox_ueber_CIFS
	{"Ankunftsverzeichnis der Fritzbox (ueber CIFS)","receiving directory of the fritzbox (via CIFS)"},
	// T_capi_k
	{"capi","capi"},
	// T_obcapi_l
	{"obcapi","takecapi"},
	// T_Capisuite_verwenden 
	{"Capisuite verwenden","use capisuite"},
	// T_hyla_k
	{"hyla","hyla"},
	// T_obhyla_l
	{"obhyla","takehyla"},
	// T_hylafax_verwenden
	{"Hylafax verwenden","use hylafax"},
	// T_hz_k,
	{"hz","hf"},
	// T_hylazuerst_l,
	{"hylazuerst","hylafirst"},
	// T_versuche_faxe_zuerst_ueber_Hylafax_wegzuschicken,
	{"versuche faxe zuerst ueber Hylafax wegzuschicken","trying to send faxes first via hylafax"},
	// T_mod_k
	{"mod","mod"},
	// T_hmodem_l
	{"hmodem","hmodem"},
	// T_Fuer_Hylafax_verwendetes_Modem
	{"Fuer Hylafax verwendetes Modem, anstatt ","Modem used for hylafax, instead of "},
	// T_cz_k
	{"cz","fc"},
	// T_capizuerst_l
	{"capizuerst","firstcapi"},
	// T_versuche_faxe_zuerst_ueber_Capisuite_wegzuschicken
	{"versuche faxe zuerst ueber Capisuite wegzuschicken","try to send faxes primarily via capisuite"},
	// T_mc_k
	{"mc","mc"},
	// T_maxcapiv_l
	{"maxcapiv","maxcapitries"},
	// T_nach_zahl_Versuchen_Capisuite_wird_Hylafax_versucht
	{"nach <zahl> Versuchen Capisuite wird Hylafax versucht, anstatt nach","try Hylafax after <no> tries of Capisuite instead of"}, 
	// T_mh_k
	{"mh","mh"},
	// T_maxhylav_l
	{"maxhylav","maxhylatries"},
	// T_nach_zahl_Versuchen_Hylafax_wird_Capisuite_verwendet
	{"nach <zahl> Versuchen Hylafax wird Capisuite versucht, anstatt nach","try Capisuite after <no> tries of Hylafax instead of"},
	// T_cuser_k
	{"cuser","cuser"},
	// T_cuser_l
	{"cuser","cuser"},
	// T_verwendet_fuer_Capisuite_Samba_den_Linux_Benutzer_string_anstatt
	{"verwendet fuer Capisuite und/oder Samba den Linux-Benutzer <string> anstatt", "takes the linux user <string> for capisuite and/or samba instead of"},
	// T_ckzl_k
	{"ckzl","crct"},
	// T_cklingelzahl_l
	{"cklingelzahl","cringcount"},
	// T_Zahl_der_Klingeltoene_bis_Capisuite_den_Anruf_annimmt_anstatt
	{"Zahl der Klingeltoene, bis Capisuite den Anruf annimmt, anstatt","No. of bell rings until Capisuite accepts the call, instead of"},
	// T_hkzl_k
	{"hkzl","hrct"},
	// T_hklingelzahl_l
	{"hklingelzahl","hringcount"},
	// T_Zahl_der_Klingeltoene_bis_Hylafax_den_Anruf_annimmt_anstatt
	{"Zahl der Klingeltoene, bis Hylafax den Anruf annimmt, anstatt","No. of bell rings until hylafaxs accepts the call, instead of"},
	// T_md_k
	{"hmw","hmd"},
	// T_maxdials_l
	{"hmaxwahlvers","hmaxdials"},
	// T_Zahl_der_Wahlversuche_in_Hylafax
	{"Zahl der Wahlversuche in Hylafax, anstatt ","No of dialing retries in hylafax, instead of  "},
	// T_gz_k
	{"gz","it"},
	// T_gleichziel_l
	{"gleichziel","immediatelytarget"},
	// T_Faxe_werden_auch_ohne_Faxerfolg_ins_Zielverzeichnis_kopiert
	{"Faxe werden auch ohne Faxerfolg ins Zielverzeichnis kopiert","copy faxes into target directory irrespective of faxing success"},
	// T_ocri_k
	{"ocre","ocri"},
	// T_ocri_l
	{"ocre","ocri"},
	// T_Text_aus_empfangenen_Faxen_wird_ermittelt
	{"Text aus empfangenen Faxen wird ermittelt","Text from received faxes will be filtered"},
	// T_ocra_k
	{"ocra","ocro"},
	// T_ocra_l
	{"ocra","ocro"},
	// T_Text_aus_gesandten_Bildern_wird_ermittelt
	{"Text aus gesandten Bildern wird ermittelt","Text from sent pictures will be filtered"},
	// T_afs_k
	{"afs","tfs"},
	// T_anfaxstr_l
	{"anfaxstr","tofaxstr"},
	// T_faxnr_wird_hinter_string_erwartet_statt_hinter
	{"faxnr wird hinter <string> erwartet statt hinter","the fax number will be expected after <string> instead of"},
	// T_acfs_k
	{"acfs","tcfs"},
	// T_ancfaxstr
	{"ancfaxstr","tocfaxstr"},
	// T_faxnr_fuer_primaer_Capisuite_wird_hinter_string_erwartet_statt_hinter
	{"faxnr fuer primaer Capisuite wird hinter <string> erwartet statt hinter", "fax no.for fax with preference to capisuite is expected after <string> instead of"},
	// T_ahfs_k
	{"ahfs","thfs"},
	// T_anhfaxstr_l
	{"anhfaxstr","tohfaxstr"},
	// T_faxnr_fuer_primaer_hylafax_wird_hinter_string_erwartet_statt_hinter
	{"faxnr fuer primaer hylafax wird hinter <string> erwartet statt hinter", "fax no.for fax with preference to hylafax is expected after <string> instead of"},
	// T_as_k
	{"as","ts"},
	// T_anstr_l
	{"anstr","tostr"},
	// T_Adressatenname_wird_hinter_string_erwartet_statt_hinter
	{"Adressatenname wird hinter <string> erwartet statt hinter","name of addressee is expected after <string> instead of"},
	// T_us_k
	{"us","ands"},
	// T_undstr_l,
	{"undstr","andstr"},
	// T_Trennstring_string_fuer_mehrere_Adressaten_Telefonnummern_statt
	{"Trennstring <string> fuer mehrere Adressaten/Telefonnummern statt", "separating string <string> for multiple addressees/tel'numbers, instead of"},
	// 	T_find_k,
	{"fd","fd"},
	// T_find_l,
	{"finde","find"},
	// T_Version_1_2_oder_3_Dateisuche_anstatt
	{"Version 1,2 oder 3 -Dateisuche (variable Performanceunterschiede) anstatt", "version 1,2 or 3 of filefind (variable performance differences instead of"},
	// T_loef
	{"loef","delf"},
	// T_loeschefax_l
	{"loeschefax","deletefax"},
	// T_ein_Fax_nach_Rueckfrage_loeschen
	{"ein Fax nach Rueckfrage loeschen","delete a fax with query"},
	// T_loew
	{"loew","delo"},
	// T_loeschewaise_l
	{"loeschewaise","deleteorphans"},
	// T_Eintraege_aus
	{"Eintraege aus `","delete entries from `"},
	// T_loeschen_zu_denen_kein_Datei_im_Wartevz_und_kein_Capi_oder_Hylafax_nachweisbar_ist
	{"` loeschen, zu denen keine Datei im Wartevz.und kein Capi- oder Hylafax nachweisbar ist", "` without detection of file in waiting directory or capisuite fax or hylafax"},
	// T_loea_k
	{"loea","dela"},
	// T_loescheallew_l
	{"loescheallew","deleteallwaiting"},
	// T_alle_wartenden_Faxe_und_zugehoerige_Eintraege_aus
	{"alle wartenden Faxe und zugehoerige Eintraege aus `","delete all waiting faxes and associated entries from `"},
	// T_loeschen
	{"` loeschen","`"},
	// T_erneut_k
	{"erneut","again"},
	// T_erneutempf_l
	{"erneutempf","receiveagain"},
	// T_empfangenes_Fax_erneut_bereitstellen
	{"empfangenes Fax erneut bereitstellen","present a received fax again"},
	// T_uml_k
	{"uml","red"},
	// T_umleiten_l
	{"umleiten","redirect"},
	// T_ausgehendes_Fax_vorzeitig_auf_zweitem_Weg_schicken
	{"ausgehendes Fax vorzeitig auf zweitem Weg schicken","redirect outgoing fax ahead by the other channel"},
	// T_kez_k
	{"kez","csf"},
	// T_korrerfolgszeichen_l
	{"korrerfolgszeichen","correctsuccessflag"},
	// T_in_der_Datenbanktabelle
	{"in der Datenbanktabelle `","in the database table `"},
	// T_wird_das_Erfolgszeichen_korrigiert
	{"` wird das Erfolgszeichen korrigiert","` the success flag is being corrected"},
	// T_bvz_k
	{"bvz","rod"},
	// T_bereinigevz_l
	{"bereinigevz","reorderdir"},
	// T_Dateien_aus_Warteverzeichnis_Gescheitertenvz_und_Gefaxtvz_gegen
	{"Dateien aus Wartevz.,Gescheitertenvz.u.Gefaxtvz.gegen `","Examine files in waiting,failed a.faxed directory against the tables `"},
	// T_pruefen_und_aufraeumen
	{"` pruefen und ggf. aufraeumen","` and put them to order"},
	// T_st_k
	{"st","st"},
	// T_stop_l
	{"stop","stop"},
	// T_DPROG_anhalten
	{DPROG " anhalten","stop " DPROG},
	// T_lista_k
	{"lista","listo"},
	// T_listausg_l
	{"listausg","listoutg"},
	// T_listet_Datensaetze_aus
	{"listet Datensaetze aus `","lists entries from `"},
	// T_mit_Erfolgskennzeichen_auf
	{"` mit Erfolgskennzeichen auf","` with success flag"},
	// T_listf_k
	{"listf","listf"},
	// T_listfailed_l
	{"listfehlgeschl","listfailed"},
	// T_ohne_Erfolgskennzeichen_auf
	{"` ohne Erfolgskennzeichen auf","` without success flag"},
	// T_listi_k
	{"liste","listi"},
	// T_listinca_l
	{"listeing","listinca"},
	// T__auf
	{"` auf","`"},
	// T_listw_k,
	{"listw","listw"},
	// T_listwart_l
	{"listwartende","listwaiting"},
	// T_listet_wartende_Faxe_auf
	{"listet wartende Faxe auf","lists waiting faxes"},
	// T_s_k
	{"s","s"},
	// T_suche_l
	{"suche","search"},
	// T_suche_in_verarbeiteten_Faxen_nach
	{"Suche in verarbeiteten Faxen nach <string>: ","Look in processed faxes for <string>: "},
	// T_n_k
	{"n","n"},
	// T_dszahl_l
	{"dszahl","reccount"},
	// T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt
	{"Zahl der aufzulistenden Datensaetze = <zahl> statt","No. of listed entries = <no> instead of"},
	// T_vc_k
	{"vc","vc"},
	// T_vc_l
	{"vc","vc"},
	// T_Capisuite_Konfigurationdateien_bearbeiten
	{"Capisuite-Konfigurationsdateien bearbeiten (beenden mit ':qa')","edit capisuite log files (finish with ':qa')"},
	// T_vh_k
	{"vh","vh"},
	// T_vh_l
	{"vh","vh"},
	// T_Hylafax_Modem_Konfigurationsdatei_bearbeiten
	{"Hylafax-Modem-Konfigurationsdatei bearbeiten (beenden mit ':qa')","edit hylafax modem configuration file (finish with ':qa')"},
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;

using namespace std; //ω

zielmustercl::zielmustercl(const char * const vmuster,const char * const vziel):muster(vmuster),ziel(vziel)
{
	kompilier();
};  // zielmustercl

zielmustercl::zielmustercl(const char * const vmuster,const string& vziel):muster(vmuster),ziel(vziel)
{
	kompilier();
};  // zielmustercl

zielmustercl::zielmustercl() 
{
}

int zielmustercl::kompilier(const uchar obext/*=1*/) 
{
	int reti=regcomp(&regex, muster.c_str(),obext?REG_EXTENDED|REG_ICASE:RE_SYNTAX_ED|REG_ICASE); 
	if (reti) {
		const int MAX_ERROR_MSG=0x1000;
		char error_message[MAX_ERROR_MSG];
		regerror (reti, &regex, error_message, MAX_ERROR_MSG);
		Log(Tx[T_Der_regulaere_Ausdruck]+drots+muster+schwarz+Tx[T_konnte_nicht_kompiliert_werden_Fehler]+error_message,1,0);
		return 1;
	} //   if (reti)
	return 0;
} // zielmustercl::zielmustercl

int zielmustercl::setzemuster(const string& vmuster,const uchar obext/*=1*/)
{
	muster=vmuster;
	return kompilier(obext);
} // int zielmustercl::setzemuster(const string& vmuster)

int zielmustercl::obmusterleer() const
{
	return muster.empty();
} // int zielmustercl::obmusterleer() 

const string& zielmustercl::holmuster () const
{
	return muster;
} // const string& zielmustercl::holmuster()


hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG) //α
{
 // mitcron=0; //ω
} // hhcl::hhcl //α
//ω

// aufgerufen in liescapiconf
void hhcl::cfcnfCfuell()
{
	static uchar neu=1;
	if (neu) {	
		cfcnfC<<WPcl("spool_dir",&spoolcapivz,wstr);
		cfcnfC<<WPcl("fax_user_dir",&cfaxuservz,wstr);
		cfcnfC<<WPcl("send_tries",&maxcdials,wstr);
		cfcnfC<<WPcl("send_delays",&send_delays,wstr);
		cfcnfC<<WPcl("outgoing_MSN",&outgoing_MSN,wstr);
		cfcnfC<<WPcl("dial_prefix",&dial_prefix,wstr);
		cfcnfC<<WPcl("fax_stationID",&fax_stationID,wstr);
		cfcnfC<<WPcl("fax_headline",&fax_headline,wstr);
		cfcnfC<<WPcl("fax_email_from",&fax_email_from,wstr);
		cfcnfC<<WPcl("outgoing_timeout",&outgoing_timeout,wstr);
		neu=0;
	} // 	if (neu)
} // void hhcl::cfcnfCfuell

// aufgerufen in liescapiconf
void hhcl::cccnfCfuell()
{
	static uchar neu=1;
	if (neu) {	
		cccnfC<<WPcl("incoming_script",&cdn[0],wstr);
		cccnfC<<WPcl("log_file",&cdn[1],wstr);
		cccnfC<<WPcl("log_error",&cdn[2],wstr);
		cccnfC<<WPcl("idle_script",&cdn[3],wstr);
		neu=0;
	} // 	if (neu)
} // void hhcl::cccnfCfuell

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
	if (!cfaxconfdt.empty()) {
		cfcnfCfuell();
		pruefverz(dir_name(cfaxconfdt),obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0);
		confdcl cfaxc(cfaxconfdt,obverb);
		cfaxc.auswert(&cfcnfC);
		cfaxc.Abschn_auswert(obverb);
#ifdef false
		cfcnfA.init(10,"spool_dir","fax_user_dir","send_tries","send_delays","outgoing_MSN",
				"dial_prefix","fax_stationID","fax_headline","fax_email_from","outgoing_timeout");
		if (!cfaxconfdt.empty()) {
			pruefverz(dir_name(cfaxconfdt),obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0);
			static confdat cfaxcd(cfaxconfdt,&cfcnfA,obverb);
			cfaxcdtp=&cfaxcd;
			cfaxcdtp->Abschn_auswert(obverb);
		}
#endif
			// wenn sich cuser in cfaxcd findet, dann so lassen
			// wenn nicht, dann:
			//   wenn cuser leer, dann den ersten besten user nehmen
			//   sonst cuser setzen
			////    cuser="";
		string ncuser;
		for(size_t i=cfaxc.zn.size();i>0;) {
			char buf[250]={0};
			if ((sscanf(cfaxc.zn[--i].c_str(),"[%[^]]]",buf))>0) 
				if (strcasecmp(buf,"global")) {
					if (!cuser.empty()) {
						if (cuser==buf) {
							ncuser.clear();
							break;
						} //            if (cuser==buf)
					} //           if (!cuser.empty())
					if (ncuser.empty()) ncuser=buf; // nehme den letzten besten user
				} //         if (strcasecmp(buf,"global"))
		} //     for(size_t i=cfaxc.zn.size();i>0;)
		if (cuser.empty()) 
			cuser=ncuser;
		if (cuser.empty()) {
			if (cus.cuid)
				cuser=cus.cusstr;
			hylazuerst=1;
		} //     if (cuser.empty())
	} //   if (!cfaxconfdt.empty())
	if (spoolcapivz.empty()) {
		spoolcapivz="/var/spool/capisuite";
	} else {
		kuerzevtz(&spoolcapivz);
	}
	cempfavz=spoolcapivz+"/" DPROG "arch";
	if (cfaxuservz.empty()) {
		cfaxuservz=spoolcapivz+"/users";
	} else {
		kuerzevtz(&cfaxuservz);
	}
	//// <<rot<<"cfaxuservz in Vorgallg: "<<cfaxuservz<<schwarz<<endl;
	qrueck.clear();
	if (findv==1) {
		systemrueck(moegl+"capisuite.conf",obverb-2,oblog,&qrueck,/*obsudc=*/0);
	} else findfile(&qrueck,findv,obverb,oblog,0,wo,/*muster=*/"/capisuite\\.conf$");
	if (qrueck.size()) {
		ccapiconfdt=qrueck[0];
	} //   if (qrueck.size())
	if (!ccapiconfdt.empty()) {
		static uchar cczulesen=1;
		struct stat cstat={0};
		static time_t lgelzeit=0; // Aenderungszeitpunkt der evtl. zuletzt eingelesenen ccapiconfdt
		time_t aktgelzeit;
		if (!lstat(ccapiconfdt.c_str(),&cstat)) { //// <<rot<<ccapiconfdt<<" existiert!"<<schwarz<<endl;
			aktgelzeit=cstat.st_mtime;
			if (aktgelzeit>lgelzeit) {
				lgelzeit=aktgelzeit;
				cczulesen=1;
			} //       if (aktgelzeit>lgelzeit)
		} // if (!lstat(ccapiconfdt.c_str(),&cstat)) 
		if (cczulesen) {
			cccnfCfuell();
			pruefverz(dir_name(ccapiconfdt),obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0);
			confdcl ccapc(ccapiconfdt,obverb);
			////<<"azaehlerdt: "<<blau<<azaehlerdt<<schwarz<<endl;
			ccapc.auswert(&cccnfC);
			cczulesen=0;
			if (!cuser.empty()) {
				for(size_t j=0;j<sizeof cdn/sizeof *cdn;j++) {
					if (!cdn[j].empty()) {
						caus<<"cdn["<<j<<"]: "<<cdn[j]<<endl;
						struct stat statdat={0};
						if (!lstat(cdn[j].c_str(),&statdat)) {
							setfaclggf(cdn[j],obverb>1?obverb-1:0,oblog,/*obunter=*/falsch,/*mod=*/6);
						} //             if (!lstat(cccnfA[j].wert.c_str(),&statdat))
					} // if (!cccnfA[j].wert.empty()) 
				} // for(size_t j=1;j<3;j++) 
			} // if (!cuser.empty()) 
#ifdef false
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
#endif
		} // if (cczulesen)
	} // if (!ccapiconfdt.empty())

	if (!spoolcapivz.empty()) {
		cdonevz = mitvtz(spoolcapivz)+"done";
		cfailedvz = mitvtz(spoolcapivz)+"failed";
	} //   if (!spoolcapivz.empty())
} // void hhcl::liescapiconf

// wird  aufgerufen in: pruefcapi
void hhcl::konfcapi()
{
	Log(violetts+Tx[T_konfcapi]+schwarz+", ccapiconfdt: "+violett+ccapiconfdt+schwarz);
	// Zahl der Klingeltoene in capisuite einstellen
	/*//
		cppSchluess cccnfA[]={{"incoming_script"}};
		size_t cs=sizeof cccnfA/sizeof*cccnfA;
	 */
	//// <<"cccnfA[0].wert: "<<cccnfA[0].wert<<endl;
	if (!cccnfA[0].wert.empty()) {
		systemrueck("sed -i$(test -f "+cdn[0]+".orig||echo '.orig') "
				"'s/\\(^.*connect_faxG3.*headline\\).*\\().*$\\)/\\1,"+cklingelzahl+"\\2/' "+cdn[0],obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
	}
	////    if (cpplies(ccapiconfdt,cccnfA,cs)) KLA
	/*//
		mdatei f(cccnfA[0].wert,ios::in); // /usr/lib64/capisuite/incoming.py
		if (f.is_open()) KLA
		string zeile;
		const char* searchstr="connect_faxG3(";
	// <<rot<<"Lese: "<<cccnfA[0].wert<<schwarz<<endl;
	while(getline(f,zeile)) KLA
	size_t nk=zeile.find(searchstr);
	if (nk!=string::npos) KLA
	nk+=strlen(searchstr);
	const char* headline="headline";
	size_t nkh=zeile.find(headline,nk);
	if (nkh!=string::npos) KLA
	nkh+=strlen(headline);
	size_t klap=zeile.find(')',nkh-1);
	if (klap!=string::npos) KLA
	string nkz=zeile.substr(nkh+1,klap-nkh); // das , nach headline
	if (nkz!=cklingelzahl) KLA
	string neuzeile=zeile.substr(0,nkh)+","+cklingelzahl+zeile.substr(klap);
	string neudatei=string(cccnfA[0].wert)+"_neu";
	f.close();
	mdatei fneu(neudatei,ios::out);
	mdatei falt(cccnfA[0].wert,ios::in);
	if (falt.is_open()) if (fneu.is_open()) KLA
	while(getline(falt,zeile)) KLA
	nk=zeile.find(searchstr);
	if (nk!=string::npos) KLA
	fneu<<neuzeile<<endl;
	KLZ else KLA
	fneu<<zeile<<endl;
	KLZ 

	KLZ // while(getline(falt,zeile)) 
	struct stat entryorig={0};
	string origdatei=string(cccnfA[0].wert)+"_orig";
	if (lstat(origdatei.c_str(),&entryorig)) KLA
	dorename(cccnfA[0].wert,origdatei,cuser,0,obverb,oblog);
	KLZ else KLA
	tuloeschen(cccnfA[0].wert,cuser,obverb,oblog);
	KLZ            
	dorename(neudatei,cccnfA[0].wert,cuser,0,obverb,oblog); 
	KLZ  // if (falt.is_open()) if (fneu.is_open()) 
	break;
	KLZ // if (nkz!=cklingelzahl) 
	KLZ // if (klap!=string::npos) 
	KLZ //           if (nkh!=string::npos) KLA
	KLZ // if ((nkz=strstr(zeile,searchstr))) 
	KLZ // while(getline(f,zeile)) 
	KLZ // if (f.is_open()) 
	KLZ // if (cpplies(ccapiconfdt,cccnfA,cs)) 
	 */
	////  static cppSchluess cfcnfA[]=KLA KLA"spool_dir"KLZ,KLA"fax_user_dir"KLZ,KLA"send_tries"KLZ,KLA"send_delays"KLZ,
	////         KLA"outgoing_MSN"KLZ,KLA"dial_prefix"KLZ,KLA"fax_stationID"KLZ,KLA"fax_headline"KLZ,KLA"fax_email_from"KLZ KLZ;
	//// fax_stationID
	uchar capicffehlt=0;
	// //<<rot<<"fax_stationID: '"<<fax_stationID<<"'"<<schwarz<<endl;
	if (fax_stationID.find("000 0000")!=string::npos || fax_stationID.empty()) {
		////    if (cfax_stationID.find("000 0000")!=string::npos) 
		////    ::Log(string("Capisuite ist offenbar noch nicht konfiguriert(")+blau+"fax_stationID"+schwarz+" enthaelt '000 0000').\n"
		////        "Die Einstellung koennen spaeter in "+blau+cfaxconfdt+schwarz+" geaendert werden.",1,0);
		::Log(Tx[T_Capisuite_ist_offenbar_noch_nicht_richtig_konfiguriert]+blaus+"'fax_stationID'"+schwarz+Tx[T_ist_Apostroph]+blau+
				fax_stationID+schwarz+"')."+ Tx[T_Die_Einstellungen_koennen_spaeter_in]+blau+cfaxconfdt+schwarz+Tx[T_geaendert_werden],1,1);
		// fax_stationID
		capicffehlt=1;
	} // if (fax_stationID.find("000 0000")!=string::npos || fax_stationID.empty()) 
	if (rzf || (capicffehlt && !nrzf)) {
		while (fax_stationID.find("000 0000")!=string::npos || !istelnr(fax_stationID)) {
			fax_stationID="+"+countrycode+" "+citycode+" "+msn;
			fax_stationID=Tippstr(string("fax_stationID: ")+Tx[T_Faxnr_die_zum_Adressaten_gesandt_wird_bis_20_Zeichen_nur_plus_und_Ziffern],
					&fax_stationID);
		}
		vector<string> tok;
		aufSplit(&tok,fax_stationID,' ');
		// outgoing_MSN
		outgoing_MSN=msn;
		if (outgoing_MSN.empty() || isneun(outgoing_MSN)) outgoing_MSN=tok[tok.size()-1].c_str();
		do {
			outgoing_MSN=Tippstr(string("outgoing_MSN: ")+
					Tx[T_ausgehende_Multiple_Subscriber_Number_Faxnummer_ohne_Vorwahl],&outgoing_MSN);
		} while (!isnumeric(outgoing_MSN) || isneun(outgoing_MSN));
		// dial_prefix
		dial_prefix=Tippstr(string("dial_prefix: ")+Tx[T_Amtsholung_ueblicherweise_kk_oder_0],&dial_prefix,/*obnichtleer=*/0);
		// fax_headline
		fax_headline=cFaxUeberschrift;
		fax_headline=Tippstr(string("fax_headline: ")+Tx[T_Faxueberschrift],&fax_headline);
		// fax_email_from
		fax_email_from=Tippstr(string("fax_email_from: ")+
				Tx[T_Adressat_empfangener_Faxe_die_ueber_Email_verteilt_werden],&fax_email_from);
		// send_tries
		if (!isnumeric(maxcdials)) maxcdials="15";
		do {
			maxcdials=Tippstr(string("send_tries: ")+Tx[T_Zahl_der_Sendeversuche],&maxcdials);
		} while (!isnumeric(maxcdials));
		// send_delays
		send_delays="60,60,60,300,300,300,300,300,3600,3600,3600,3600,18000,36000";
		do {
			send_delays=Tippstr(string("send_delays: ")+Tx[T_kommagetrennte_Liste_mit_Sekundenabstaenden_zwischen_Sendeversuchen],
					&send_delays);
		} while (!isnumeric(send_delays));
		// outgoing_timeout
		outgoing_timeout="60";
		outgoing_timeout=Tippstr(string("outgoing_timeout: ")+Tx[T_Geduld_bis_zum_Verbindungsaufbau_in_s],&outgoing_timeout);
		if (obverb>0) {
			for(unsigned snr=0;snr<cfcnfA.zahl;snr++) {
				Log("snr: "+blaus+ltoan(snr)+schwarz+" "+cfcnfA[snr].name+", "+cfcnfA[snr].wert);
			}
		} // if (obverb>0)
	} // if (rzf || (capicffehlt && !nrzf))
	const string suchcuser="["+cuser+"]";
	// es gibt zwei moegliche Gruende zum Neuschreiben der Datei: 1) Parameter diffierieren, 2) noch kein User angelegt
	uchar cuserda=0, paramdiff=0, neuschreiben=0;
	setfaclggf(cfaxconfdt,obverb>1?obverb-1:0,oblog,/*obunter=*/falsch,/*mod=*/6);
	string zeile;
	// iru=0 => pruefen, ob Datei geaendert werden muss; iru=1 => aendern
	uchar tuumben=0;
	for(uchar iru=0;iru<2;iru++) {
		mdatei *fneu=0;
		mdatei f(cfaxconfdt,ios::in); // /etc/capisuite/fax.conf
		if (f.is_open()) {
			if (iru) {
				cfaxconfeigdt=instvz+vtz+"cfaxconfdt_neu";
				fneu=new mdatei(cfaxconfeigdt,ios::out,0);
				if (!fneu->is_open()) break;
			} // if (iru)
			if (f.is_open()) {
				while(getline(f,zeile)) {
					size_t kommpos=zeile.find('#');
					uchar geschrieben=0;
					////          if (kommpos!=string::npos) zeile.erase(kommpos);
					////          if (!zeile.length()) continue;
					if (!cuserda) 
						if (zeile.find(suchcuser)!=string::npos) 
							cuserda=1;
					//// <<rot<<"iru: "<<(int)iru<<", paramdiff: "<<(int)paramdiff<<schwarz<<endl;
					if (iru || !paramdiff) {
						size_t nkz=zeile.find('=');
						string lzeile,rzeile;
						if (nkz<kommpos) {
							lzeile=zeile.substr(0,nkz); 
							rzeile=zeile.substr(nkz+1);
							for(unsigned snr=0;snr<cfcnfA.zahl;snr++) {
								if (lzeile.find(cfcnfA[snr].name)!=string::npos) {
									//// _out<<"snr: "<<snr<<", lzeile: "<<tuerkis<<lzeile<<schwarz<<", rzeile: "<<blau<<rzeile<<schwarz<<endl;
									string altwert=rzeile;
									gtrim(&altwert);
									anfzweg(altwert); // Anfuehrungszeichen entfernen
									if (snr==0 || snr==1) cfcnfA[snr].wert=altwert; // spool_dir und fax_user_dir hier nicht konfigurierbar
									Log(string("cfcnfA[")+ltoan(snr)+"].name: "+tuerkis+cfcnfA[snr].name+schwarz+Tx[T_komma_wert]+
											(cfcnfA[snr].wert==altwert?blau:rot)+cfcnfA[snr].wert+schwarz+Tx[T_komma_Altwert]+
											blau+altwert+schwarz,obverb+iru,oblog+iru);
									if (cfcnfA[snr].wert!=altwert) {
										if (!iru) {
											neuschreiben=1;
											paramdiff=1;
										} else {
											string zschr=cfcnfA[snr].name+" = \""+cfcnfA[snr].wert+"\"";
											*fneu<<zschr<<endl;
											geschrieben=1;
										} //                   if (!iru) else
									} //                 if (cfcnfA[snr].wert!=altwert)
									break; // wenn richtige Zeile gefunden, nicht mehr weitersuchen, unabhaengig vom Ergebnis
								} // if ((nkz=strstr(zeile,cfcnfA[snr].name))) 
							} // if ((nkz=zeile.find(cfcnfA[snr].wert))!=string::npos) 
						} // 						if (nkz<kommpos)
					} // if (!paramdiff) 
					if (iru)
						if (!geschrieben) 
							*fneu<<zeile<<endl;
				} // while( fgets(p=zeile,sizeof zeile,f) ) 
			} // if (f.is_open)
			if (!iru) {
				if (!cuserda) neuschreiben=1;
				if (!neuschreiben) break; // dann fertig
			} else { // if (iru)
				if (!cuserda)  {
					// schreibe Konfiguration fuer Benutzer in fax.conf
					*fneu<<suchcuser<<endl;
					*fneu<<"fax_numbers=\""<<outgoing_MSN<<"\""<<endl;
					*fneu<<"fax_stationID=\""<<fax_stationID<<"\""<<endl;
					*fneu<<"fax_headline=\""<<fax_headline<<"\""<<endl;
					*fneu<<"fax_email_from=\""<<fax_email_from<<"\""<<endl;
					*fneu<<"fax_action=\"MailAndSave\""<<endl;
				} // if (!cuserda)
				if (fneu) {
					fneu->close();
					delete fneu;
					fneu=0;
				} // 				if (fneu)
				tuumben=1;
			} // if (iru)
			if (!cfaxuservz.empty()) cfaxuservz=cfaxuservz;
			//// <<rot<<"cfaxuservz konfcapi: "<<cfaxuservz<<schwarz<<endl;
		} // if (f.is_open())
	} // for(uchar iru=0;iru<2;iru++) 
	if (tuumben) {
		const string origdatei=cfaxconfdt+"_orig";
		struct stat entryorig={0};
		if (lstat(origdatei.c_str(),&entryorig)) {
			dorename(cfaxconfdt,origdatei,cuser,/*vfehlerp=*/0,/*schonda=*/0,obverb,oblog);
		} else {
			tuloeschen(cfaxconfdt,cuser,obverb,oblog);
		} // 				if (lstat(origdatei.c_str(),&entryorig)) else
		uint vfehler=0;
		kopiere(cfaxconfeigdt,cfaxconfdt,&vfehler,/*wieweiterzaehl=*/2);
	} // 	if (tuumben)
	pruefcvz();
	nextnum();
	Log(violetts+Txk[T_Ende]+Tx[T_konfcapi]+schwarz+"ccapiconfdt: "+violett+ccapiconfdt+schwarz);
} // void hhcl::konfcapi

void hhcl::dovc()
{
	pruefcapi();
	cmd=edit;
	viadd(&cmd,cfaxconfdt);
	viadd(&cmd,ccapiconfdt);
	viadd(&cmd,rulesdt);
	viadd(&cmd,blackdt);
	if (scapis) viadd(&cmd,scapis->systemd);
	if (!cdn[0].empty()) viadd(&cmd,cdn[0]); // incoming_script
	if (!cdn[3].empty()) viadd(&cmd,cdn[3]); // idle_script
	string erg;
	if (!cdn[1].empty()) viadd(&cmd,cdn[1],1,1,1); // log_file
	if (!cdn[2].empty()) viadd(&cmd,cdn[2],1,1,1); // log_error
	vischluss(erg);
} // void hhcl::dovc()


//α
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
	Log(violetts+Tx[T_pvirtVorgbSpeziell]+schwarz); //ω
	dhcl::pvirtVorgbSpeziell(); //α
	virtMusterVorgb();
} // void hhcl::pvirtVorgbSpeziell

// wird aufgerufen in lauf
void hhcl::virtinitopt()
{ //ω
	opn<<optcl(/*pname*/"zufaxenvz",/*pptr*/&zufaxenvz,/*art*/pverz,T_zvz_k,T_zufaxenvz_l,/*TxBp*/&Tx,/*Txi*/T_faxt_die_Dateien_aus_pfad_anstatt_aus,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"wartevz",/*pptr*/&wvz,/*art*/pverz,T_wvz_k,T_wartevz_l,/*TxBp*/&Tx,/*Txi*/T_Dateien_warten_in_pfad_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"nichtgefaxtvz",/*pptr*/&ngvz,/*art*/pverz,T_ngvz_k,T_nichtgefaxtvz_l,/*TxBp*/&Tx,/*Txi*/T_Gescheiterte_Faxe_werden_hier_gesammelt_anstatt_in,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"empfvz",/*pptr*/&empfvz,/*art*/pverz,T_evz_k,T_empfvz_l,/*TxBp*/&Tx,/*Txi*/T_Empfangsverzeichnis_fuer_Faxempfang,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"obfbox",/*pptr*/&obfbox,/*art*/puchar,T_fbox_k,T_obfbox_l,/*TxBp*/&Tx,/*Txi*/T_Fritzbox_verwenden,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"fbankvz",/*pptr*/&fbankvz,/*art*/pverz,T_fbankvz_k,T_fbankvz_l,/*TxBp*/&Tx,/*Txi*/T_Ankunftsverzeichnis_der_Fritzbox_ueber_CIFS,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"obcapi",/*pptr*/&obcapi,/*art*/puchar,T_capi_k,T_obcapi_l,/*TxBp*/&Tx,/*Txi*/T_Capisuite_verwenden ,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"obhyla",/*pptr*/&obhyla,/*art*/puchar,T_hyla_k,T_obhyla_l,/*TxBp*/&Tx,/*Txi*/T_hylafax_verwenden ,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"hylazuerst",/*pptr*/&hylazuerst,/*art*/puchar,T_hz_k,T_hylazuerst_l,/*TxBp*/&Tx,/*Txi*/T_versuche_faxe_zuerst_ueber_Hylafax_wegzuschicken,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"hylazuerst",/*pptr*/&hylazuerst,/*art*/puchar,T_cz_k,T_capizuerst_l,/*TxBp*/&Tx,/*Txi*/T_versuche_faxe_zuerst_ueber_Capisuite_wegzuschicken,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/0);
	opn<<optcl(/*pname*/"hmodem",/*pptr*/&hmodem,/*art*/psons,T_mod_k,T_hmodem_l,/*TxBp*/&Tx,/*Txi*/T_Fuer_Hylafax_verwendetes_Modem,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"maxcapiv",/*pptr*/&maxcapiv,/*art*/pdez,T_mc_k,T_maxcapiv_l,/*TxBp*/&Tx,/*Txi*/T_nach_zahl_Versuchen_Capisuite_wird_Hylafax_versucht,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"maxhylav",/*pptr*/&maxhylav,/*art*/pdez,T_mh_k,T_maxhylav_l,/*TxBp*/&Tx,/*Txi*/T_nach_zahl_Versuchen_Hylafax_wird_Capisuite_verwendet,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"cuser",/*pptr*/&cuser,/*art*/psons,T_cuser_k,T_cuser_l,/*TxBp*/&Tx,/*Txi*/T_verwendet_fuer_Capisuite_Samba_den_Linux_Benutzer_string_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"cklingelzahl",/*pptr*/&cklingelzahl,/*art*/pdez,T_ckzl_k,T_cklingelzahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Klingeltoene_bis_Capisuite_den_Anruf_annimmt_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"hklingelzahl",/*pptr*/&hklingelzahl,/*art*/pdez,T_hkzl_k,T_hklingelzahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Klingeltoene_bis_Hylafax_den_Anruf_annimmt_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"maxdials",/*pptr*/&maxhdials,/*art*/pdez,T_md_k,T_maxdials_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Wahlversuche_in_Hylafax,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"gleichziel",/*pptr*/&gleichziel,/*art*/puchar,T_gz_k,T_gleichziel_l,/*TxBp*/&Tx,/*Txi*/T_Faxe_werden_auch_ohne_Faxerfolg_ins_Zielverzeichnis_kopiert,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"ocri",/*pptr*/&obocri,/*art*/puchar,T_ocri_k,T_ocri_l,/*TxBp*/&Tx,/*Txi*/T_Text_aus_empfangenen_Faxen_wird_ermittelt,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"ocra",/*pptr*/&obocra,/*art*/puchar,T_ocra_k,T_ocra_l,/*TxBp*/&Tx,/*Txi*/T_Text_aus_gesandten_Bildern_wird_ermittelt,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"anfaxstr",/*pptr*/&anfaxstr,/*art*/psons,T_afs_k,T_anfaxstr_l,/*TxBp*/&Tx,/*Txi*/T_faxnr_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"ancfaxstr",/*pptr*/&ancfaxstr,/*art*/psons,T_acfs_k,T_ancfaxstr,/*TxBp*/&Tx,/*Txi*/T_faxnr_fuer_primaer_Capisuite_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"anhfaxstr",/*pptr*/&anhfaxstr,/*art*/psons,T_ahfs_k,T_anhfaxstr_l,/*TxBp*/&Tx,/*Txi*/T_faxnr_fuer_primaer_hylafax_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"anstr",/*pptr*/&anstr,/*art*/psons,T_as_k,T_anstr_l,/*TxBp*/&Tx,/*Txi*/T_Adressatenname_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"undstr",/*pptr*/&undstr,/*art*/psons,T_us_k,T_undstr_l,/*TxBp*/&Tx,/*Txi*/T_Trennstring_string_fuer_mehrere_Adressaten_Telefonnummern_statt,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"findvers",/*pptr*/&findvers,/*art*/pdez,T_find_k,T_find_l,/*TxBp*/&Tx,/*Txi*/T_Version_1_2_oder_3_Dateisuche_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"",/*pptr*/&loef,/*art*/puchar,T_loef,T_loeschefax_l,/*TxBp*/&Tx,/*Txi*/T_ein_Fax_nach_Rueckfrage_loeschen,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&loew,/*art*/puchar,T_loew,T_loeschewaise_l,/*TxBp*/&Tx,/*Txi*/T_Eintraege_aus,/*wi*/1,/*Txi2*/T_loeschen_zu_denen_kein_Datei_im_Wartevz_und_kein_Capi_oder_Hylafax_nachweisbar_ist,/*rottxt*/&spooltab,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&loea,/*art*/puchar,T_loea_k,T_loescheallew_l,/*TxBp*/&Tx,/*Txi*/T_alle_wartenden_Faxe_und_zugehoerige_Eintraege_aus,/*wi*/1,/*Txi2*/T_loeschen,/*rottxt*/&spooltab,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&erneut,/*art*/puchar,T_erneut_k,T_erneutempf_l,/*TxBp*/&Tx,/*Txi*/T_empfangenes_Fax_erneut_bereitstellen,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&uml,/*art*/puchar,T_uml_k,T_umleiten_l,/*TxBp*/&Tx,/*Txi*/T_ausgehendes_Fax_vorzeitig_auf_zweitem_Weg_schicken,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&kez,/*art*/puchar,T_kez_k,T_korrerfolgszeichen_l,/*TxBp*/&Tx,/*Txi*/T_in_der_Datenbanktabelle,/*wi*/0,/*Txi2*/T_wird_das_Erfolgszeichen_korrigiert,/*rottxt*/&touta,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&bvz,/*art*/puchar,T_bvz_k,T_bereinigevz_l,/*TxBp*/&Tx,/*Txi*/T_Dateien_aus_Warteverzeichnis_Gescheitertenvz_und_Gefaxtvz_gegen,/*wi*/0,/*Txi2*/T_pruefen_und_aufraeumen,/*rottxt*/&touta,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&anhl,/*art*/puchar,T_st_k,T_stop_l,/*TxBp*/&Tx,/*Txi*/T_DPROG_anhalten,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&lista,/*art*/puchar,T_lista_k,T_listausg_l,/*TxBp*/&Tx,/*Txi*/T_listet_Datensaetze_aus,/*wi*/1,/*Txi2*/T_mit_Erfolgskennzeichen_auf,/*rottxt*/&touta,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&listf,/*art*/puchar,T_listf_k,T_listfailed_l,/*TxBp*/&Tx,/*Txi*/T_listet_Datensaetze_aus,/*wi*/1,/*Txi2*/T_ohne_Erfolgskennzeichen_auf,/*rottxt*/&touta,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&listi,/*art*/puchar,T_listi_k,T_listinca_l,/*TxBp*/&Tx,/*Txi*/T_listet_Datensaetze_aus,/*wi*/1,/*Txi2*/T__auf,/*rottxt*/&tinca,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&listw,/*art*/puchar,T_listw_k,T_listwart_l,/*TxBp*/&Tx,/*Txi*/T_listet_wartende_Faxe_auf,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&suchstr,/*art*/psons,T_s_k,T_suche_l,/*TxBp*/&Tx,/*Txi*/T_suche_in_verarbeiteten_Faxen_nach,/*wi*/1,/*Txi2*/T_MAX,/*rottxt*/&nix,/*wert*/-1);
	opn<<optcl(/*pname*/"",/*pptr*/&dszahl,/*art*/pdez,T_n_k,T_dszahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/-1);
	opn<<optcl(/*pname*/"",/*pptr*/&obvc,/*art*/puchar,T_vc_k,T_vc_l,/*TxBp*/&Tx,/*Txi*/T_Capisuite_Konfigurationdateien_bearbeiten,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
	opn<<optcl(/*pname*/"",/*pptr*/&obvh,/*art*/puchar,T_vh_k,T_vh_l,/*TxBp*/&Tx,/*Txi*/T_Hylafax_Modem_Konfigurationsdatei_bearbeiten,/*wi*/1,/*Txi2*/-1,/*rottxt*/0,/*wert*/1);
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
	dbq=DPROG;
	findvers="3";
	ifindv=findv=atol(findvers.c_str());
	muser="user";
	citycode="8131";
	msn="999999";
	LocalIdentifier=Tx[T_MeiEinrichtung];
	cFaxUeberschrift=Tx[T_Mei_FaxUeberschrift];
	sqlz=sqlvz="0";
	////  host="localhost"; // 'localhost' schon Vorgabe bei Definition
	zufaxenvz="/var/"+meinname+vtz+Tx[T_zufaxen];
	wvz="/var/"+meinname+vtz+Tx[T_warteauffax];
	ngvz="/var/"+meinname+vtz+Tx[T_nichtgefaxt];
	empfvz="/var/"+meinname+vtz+Tx[T_empfvz];
	static zielmustercl zmi[]={zielmustercl("[Ss]pamfax","/var/"+meinname+"/spam"),zielmustercl("","/var/"+meinname+vtz+Tx[T_gesandt])};//= nur Beispiel
	// wird nur vor dem ersten fork bearbeitet
	zmvp=zmi;
	zmvzn=sizeof zmi/sizeof *zmi;
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

void hhcl::testerg()
{
}
