// '//α' oder '//ω' als Kommentar sind nur fuer die Verwendung dieses Programms als Programmvorlage wichtig
// sed -n '/\/\/α/,/\/\/ω/p;/\/\/ω/a\\' test
// sed -n '/\/\/α/,/\/\/ω/p' test
#include "kons.h" //α
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "autofax2.h"
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
	// T_konfcapi
	{"konfcapi()","confcapi()"},
	// T_Capisuite_ist_offenbar_noch_nicht_richtig_konfiguriert
	{"Capisuite ist offenbar noch nicht konfiguriert (","Capisuite seems not to be configured correcty ("},
	// T_ist_Apostroph,
	{" ist '"," is '"},
	// T_Die_Einstellungen_koennen_spaeter_in,
	{" Die Einstellungen koennen spaeter in '"," The settings can later be modified in '"},
	// T_geaendert_werden,
	{"' geaendert werden.","'"},
	// T_Faxnr_die_zum_Adressaten_gesandt_wird_bis_20_Zeichen_nur_plus_und_Ziffern,
	{"Faxnr., die zum Adressaten gesandt wird (bis 20 Zeichen, nur '+' und Ziffern)",
		"Fax number which is sent to the addressee (up to 20 characters, only '+' and numerals)"},
	// T_ausgehende_Multiple_Subscriber_Number_Faxnummer_ohne_Vorwahl,
	{"hinausgehende 'Multiple Subscriber Number' (Faxnummer ohne Vorwahl)","outgoing 'multiple subscriber number' (fax number without prefix)"},
	// T_Amtsholung_ueblicherweise_kk_oder_0,
	{"Amtsholung, ueblicherweise '' oder '0'","outside line access, typically '' or '0'"},
	// T_Faxueberschrift,
	{"Faxueberschrift","fax headline"},
	// T_Adressat_empfangener_Faxe_die_ueber_Email_verteilt_werden,
	{"Adressat empfangener Faxe, die ueber Email verteilt werden","addressee of received faxes which are distributed via email"},
	// T_Zahl_der_Sendeversuche,
	{"Zahl der Sendeversuche","Number of transmission tries"},
	// T_kommagetrennte_Liste_mit_Sekundenabstaenden_zwischen_Sendeversuchen,
	{"kommagetrennte Liste mit Sekundenabstaenden zwischen Sendeversuchen","comma separated list with distances between transmission tries"},
	// T_Geduld_bis_zum_Verbindungsaufbau_in_s,
	{"Geduld bis zum Verbindungsaufbau in s","timeout for connection establishment"},
	// T_komma_wert,
	{", wert: ",", value: "},
	// T_komma_Altwert,
	{", Altwert: ",", old value: "},
	// T_Verschiebe
	{"Verschiebe: '","Moving: '"},
	// T_Fehler_beim_Verschieben
	{"Fehler beim Verschieben ","Error while moving "},
	// T_FehlerbeimUmbenennenbei
	{" Fehler beim Umbenennen bei:"," Error while renaming:"},
	// T_Kopiere_Doppelpunkt
	{"Kopiere: '","Copying: "},
	// T_Fehler_beim_Kopieren
	{"Fehler beim Kopieren: ","Error while copying: "},
	// T_Dateiname,
	{"Dateiname ","File name "},
	// T_schlechtgeformt
	{" schlecht geformt!","malformed!"},
	// T_zielname_erstes_Ziel
	{" zielname:  erstes Ziel: '"," target name:  first target: '"},
	// T_zielname_Ausweichziel
	{" zielname: Ausweichziel: '"," target name:  alternate target: '"},
	// T_Quelle_und_Ziel_gleich
	{", Quelle und Ziel gleich",", source and target identical"},
	// T_entspricht
	{"' entspricht "," "},
	// T_entsprichtnicht
	{"nicht ","does not match to "},
	// T_entsprichtdoch
	{"","matches to "},
	// T_Muster_Doppelpunkt
	{"Muster: '","pattern: '"},
	// T_pruefcvz
	{"pruefcvz()","checkcdirs()"},
	// T_pruefcapi,
	{"pruefcapi()","checkcapi()"},
	// T_capilaeuft
	{"capilaeuft: ","capirunning: "},
	// T_Module_geladen
	{"Module geladen:","Modules loaded:"},
	// T_Lade_Capi_Module
	{", lade Capi-Module ...",", loading capi-modules ..."},
	// T_Kernelversion
	{"Kernelversion: ","Kernel version: "},
	// T_KannFcpciNInstVerwCapiNicht
	{"Kann Fritz-Modul fcpci nicht installieren, verwende capi nicht.\nZ.B.koennte mit ",
		"Cannot install module fcpci for the fritz card, not utilizing capi. For example, with "},
	// T_eine_neuere_Version_als_die_des_aktuellen_Kernels_installiert_worden_sein_dann_bitte_erneutes_Systemupdate
	{" eine neuere Version als die des aktuellen Kernels installiert worden sein, dann bitte erneutes Systemupdate",
		", a newer version than the current kernel could have been installed, in this case please do another system update"},
	// T_nichtgefFcpciMfdKinstallierwerden
	{"' nicht gefunden, fcpci muss fuer diesen Kernel installiert werden, versuche es:",
		"' not found, fcpci must be installed for this kernel, trying to:"},
	// T_Zur_Inbetriebnahme_der_Capisuite_muss_das_Modul_capi_geladen_werten,
	{"Zur Inbetriebnahme der Capisuite muss das Modul capi geladen werden. Zu dessen Erstellung musste der Befehl "
		"'sudo dnf -y install kernel-modules-extra' aufgerufen werden, der den Linux-Kernel aktualisiert hat (",
		"In order to use the capisuite, the module capi has to be loaded. In order to generate this, the command "
			"'sudo dnf -y install kernel-modules-extra' hat to be called, which updated the linux kernel ("},
	// T_Bitte_zu_dessen_Verwendung_den_Rechner_neu_starten
	{"Bitte zu dessen Verwendung den Rechner neu starten und dann nochmal ",
		"Please reboot and afterwords call "},
	// T_aufrufen,
	{" aufrufen!"," again!"},
	// T_Moment_muss_Kernel_herunterladen
	{"Moment, muss Kernel-rpm herunterladen ...","One moment, must download kernel-rpm ..."},
	// T_Der_Kernel_hat_sich_offenbar_seit_dem_Einloggen_von
	{"Der Kernel hat sich offenbar seit dem Einloggen von '","The kernel seems to have been updated sind logging in from '"},
	// T_nach_
	{"' nach '","' to '"},
	// T_verjuengt_Bitte_den_Rechner_neu_starten_und_dann_mich_nochmal_aufrufen
	{"' verjuengt. \nBitte den Rechner neu starten und dann mich nochmal aufrufen!","'. \nPlease restart the pc and then call me again!"},
	// T_Konnte
	{"Konnte '","Could not start '"},
	// T_nichtstarten
	{"' nicht starten",""},
	// T_StarteCapisuite
	{"Starte Capisuite ...","Starting Capisuite ..."},
	// T_Capisuite_gestartet
	{"Capisuite gestartet.","capisuite started."},
	// T_konntecapisuiteservice
	{"Konnte capisuite.service ","Could not start capisuite.service "},
	// T_malnichtstartenverwN
	{" mal nicht starten, verwende es nicht."," times, not utilizing it."},
	// T_pruefrules
	{"pruefrules()","checkrules()"},
	// T_pruefblack
	{"pruefblack()","checkblack()"},
	// T_haengean
	{"haenge an ","appending to "},
	// T_an_mdpp
	{" an: ",": "},
	// T_pruefsfftobmp
	{"pruefsfftobmp()","checksfftobmp()"},
	// T_clieskonf
	{"clieskonf()","creadconf()"},
	// T_pruefmodcron
	{"pruefmodcron()","checkmodcron()"},
	// T_Zahl_der_SQL_Befehle_fuer_die_Absenderermittlung,
	{"Zahl der SQL-Befehle fuer die Absenderermittlung","No.of the sql-commands for finding out senders"},
	// T_SQL_Befehl_Nr
	{"SQL-Befehl Nr. ","SQL-command no. "},
	// T_Zielmuster_Nr
	{"Zielmuster Nr. ","Target pattern no. "},
	// T_Ziel_Nr
	{"Ziel Nr. ","Target no. "},
	// T_Zahl_der_Muster_Verzeichnis_Paare_zum_Speichern_ankommender_Faxe
	{"Zahl der Muster/Verzeichnis-Paare zum Speichern ankommender Faxe","No of pairs of patterns/directories for saving received faxes"},
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;

using namespace std; //ω


// wird aufgerufen in: verschiebe (Version 1), verschiebe (Version 2), wegfaxen
// ziel kann Verzeichnis oder Datei sein; im ersten Fall wird eine Datei des Namens von quelle dort als *zielp verwendet
// wenn quelle und zielp identisch sind, tut dorename() nichts, ansonsten:
// verschiebt oder benennt um; prueft nicht auf etwa schon vorhandenes Ziel,
// aber wenn mit 'schonda' Vorhandensein und Gültigkeit des Ziels signalisiert wird, so wird statt dessen die Quelle gelöscht,
void dorename(const string& quelle, const string& ziel, const string& cuser/*=nix*/, uint *vfehlerp/*=0*/, uchar schonda/*=0*/,
		int obverb/*=0*/, int oblog/*=0*/, stringstream *ausgp/*=0*/)
{
	const string meld=Tx[T_Verschiebe]+tuerkiss+quelle+schwarz+"'\n         -> '"+gruen+ziel+schwarz+"'";
	unsigned fehler=0;
	if (ausgp&&obverb) *ausgp<<meld<<endl; else Log(meld,obverb,oblog);
	string *zielp=(string*)&ziel,ersatzziel;
	struct stat zstat={0};
	// wenn das Ziel ein Verzeichnis ist, Dateinamen anhaengen
	if (!lstat(ziel.c_str(),&zstat)&&S_ISDIR(zstat.st_mode)) {
		ersatzziel=ziel;
		kuerzevtz(&ersatzziel);	
		ersatzziel+=vtz;
		ersatzziel+=base_name(quelle);
		zielp=&ersatzziel;
	} // 	if (!lstat(ziel.c_str(),&zstat)&&S_ISDIR(zstat.st_mode))
	uchar obident=0;
	if (char* act1=realpath(quelle.c_str(),NULL)) {
		if (char* act2=realpath(zielp->c_str(),NULL)) {
			if (!strcmp(act1,act2))
				obident=1;
			free(act2);
		} // 		if (char* act2=realpath(ziel.c_str(),NULL))
		free(act1);
	} // 	if (char* act1=realpath(quelle.c_str(),NULL))
	if (!obident) {
		if (schonda) {
			if (int erg=tuloeschen(quelle.c_str(),cuser,obverb,oblog,ausgp)) {
				fehler+=erg;
			}
		} else {
			for(uchar iru=1;iru<3;iru++) {
				if (rename(quelle.c_str(),zielp->c_str())) {
					if(cuser.empty()) iru++;
					if(iru==1) {
						setfaclggf(dir_name(quelle),obverb>1?obverb-1:0,oblog,/*obunter=*/wahr,/*mod=*/7,/*obimmer=*/1,
								/*faclbak=*/1,/*user=*/nix,/*fake=*/0,ausgp);
					} else if (!schonda) {
						perror((Tx[T_Fehler_beim_Verschieben]+quelle+" -> "+ziel).c_str());
						const string cmd=sudc+"mv \""+quelle+"\" \""+*zielp+"\"";
						int erg=systemrueck(cmd,obverb,1);
						fehler+=erg;
					} // if(iru) else
				} // if (rename(quelle.c_str(),zielp->c_str())) 
				else break;
			} // for(uchar iru=1;iru>-1;iru--)
		} // 	if (schonda)
	} // 	if (!obident)
	if (fehler) {
		cerr<<rot<<fehler<<schwarz<<" = "<<Tx[T_FehlerbeimUmbenennenbei]<<endl<<blau<<quelle<<schwarz<<" ->\n"<<blau<<ziel<<schwarz<<endl;
	} // if (fehler)
	if (vfehlerp) *vfehlerp=fehler;
} // dorename

// aufgerufen in wegfaxen, main, kopiere (2), wandle, empfhyla, empfcapi
string kopiere(const string& qdatei, const string& zield, uint *kfehler, const uchar wieweiterzaehl, int obverb, int oblog)
{
	// wieweiterzaehl: 0: auf *_1_1 nach *_1, 1: auf *_2 nach *_1, 2: gar nicht
	int fehler=0;
	int efeh=0;	
	////	if (is_same<decltype(zield),const std::string&>::value) KLA
	const string dir=dir_name(zield);
	const string base=base_name(zield);
	string ziel;
	uchar obgleich=0;
	if (!base.empty() && !dir.empty()) {
		ziel=zielname(base,dir,wieweiterzaehl,/*zieldatei=*/0,&obgleich,obverb,oblog);
		Log(Tx[T_Kopiere_Doppelpunkt]+rots+qdatei+schwarz+"'\n         -> '"+rot+ziel+schwarz+"'",obverb,oblog);
		if ((efeh=kopier(qdatei,ziel,obverb,oblog))) {
			fehler+=efeh;
			Log(rots+Tx[T_Fehler_beim_Kopieren]+Tx[T_Dateiname]+blau+zield+schwarz,1,1);
		} // if (efeh=kopier(qdatei,ziel,obverb,oblog))
	} else {
		Log(rots+Tx[T_Fehler_beim_Kopieren]+Tx[T_Dateiname]+blau+zield+schwarz+Tx[T_schlechtgeformt],1,1);
	} // if (!base.empty() && !dir.empty())  else 
	if (kfehler) *kfehler=fehler;
	return ziel;
	////	KLZ
	////	return nix;
} // string kopiere

// ermittelt fuer eine in ein Zielverzeichnis zu kopierende Datei den dortigen Namen
// falls obgleichp, wird darin gespeichert, ob die Datei dort schon vorhanden und identisch ist (in diesem Fall wird kein anderer Name ermittelt)
// sonst wird, wenn wieweiterzaehl<2 ist, im Fall des Vorhandenseins im Zielverzeichnis ein neuer Name gefunden
// wird aufgerufen von verschiebe (Version 1) und kopiere (Version 1), neuerdateiname, zielname (Version 2)
string zielname(const string& qdatei, const string& rzielvz, uchar wieweiterzaehl/*=0*/, string* zieldatei/*=0*/, uchar *obgleichp/*=0*/,
		int obverb/*=0*/, int oblog/*=0*/, stringstream *ausgp/*=0*/)
{
	//  Log(violetts+Tx[T_zielname]+schwarz,obverb,oblog);
	// wieweiterzaehl: 0: auf *_1_1 nach *_1, 1: auf *_2 nach *_1, 2: gar nicht
	string dateiname=base_name(qdatei);
	struct stat st={0};
	string ziel,zielvz=rzielvz;
	if (lstat(zielvz.c_str(),&st)||!S_ISDIR(st.st_mode)) {
		ziel=zielvz;
		zielvz=dir_name(zielvz);
	} else {
		ziel=zielvz+(zielvz[zielvz.length()-1]==vtz?"":vtzs)+dateiname;
	}
	// auf Gleichheit testen
	if (obgleichp) *obgleichp=!dateivgl(qdatei,ziel);
	string meld=Tx[T_zielname_erstes_Ziel]+rots+ziel+schwarz+"'"+(obgleichp&&*obgleichp?Tx[T_Quelle_und_Ziel_gleich]:"");
	if (ausgp&&obverb) *ausgp<<meld<<endl; else Log(meld,obverb,oblog);
	if (!(obgleichp&&*obgleichp)) {
		if (wieweiterzaehl<2) {
			ulong ausweich=0;
			uchar ausgewichen=0;
			string stamm,exten;
			for(;1;) {
				struct stat entryziel={0};
				if (lstat(ziel.c_str(), &entryziel)) break;
				// in der Schleife nur beim ersten Mal aufrufen
				if (!ausgewichen) {
					getstammext(&dateiname,&stamm,&exten); // kommt hier außer bei obgleich immer vorbei
					// wenn von einer vorhandenen Ausweichnummerierung aus weitergezaehlt werden soll (anstatt dateiname_1_1 ...)
					if (wieweiterzaehl) {
						size_t pos = stamm.rfind('_');
						if (pos!=string::npos) {
							const string auswstr=stamm.substr(pos+1);
							if (isnumeric(auswstr)) { 
								ausweich=atol(auswstr.c_str());
								if (ausweich) if (stamm.length()>pos) stamm.erase(pos);
							}
						} // if (pos!=string::npos) 
					} // if (wieweiterzaehl) 
				}
				ausweich++;
				ausgewichen=1;
				dateiname=stamm+"_"+ltoan(ausweich)+"."+exten;
				ziel=zielvz + (zielvz[zielvz.length()-1]==vtz?"":vtzs) + dateiname;
			} // for(;1;) 
			if (ausgewichen) {
				meld=Tx[T_zielname_Ausweichziel]+rots+ziel+schwarz+"'";
				if (ausgp&&obverb) *ausgp<<meld<<endl; else Log(meld,obverb,oblog);
			}
		} // if (wieweiterzaehl<2) 
	} // 	if (obgleichp&&*obgleichp)
	if (zieldatei) *zieldatei=dateiname;
	return ziel;
} // zielname 

// wird aufgerufen in: verschiebe (Version 2), kopiere (Version 2), neuerdateiname, 
string zielname(const string& qdatei, const zielmustercl& zmp, uchar wieweiterzaehl/*=0*/, string* zieldatei/*=0*/, uchar *obgleichp/*=0*/, 
		int obverb/*=0*/, int oblog/*=0*/, stringstream *ausgp/*=0*/)
{
	//  Log(violetts+Tx[T_zielname]+schwarz,obverb,oblog);
	for(const zielmustercl *zmakt=&zmp;1;zmakt++){
		int reti=regexec(&(zmakt->regex),qdatei.c_str(),0,NULL,0);
		const string meld=Txk[T_datei]+rots+qdatei+schwarz+Tx[T_entspricht]+(reti?Tx[T_entsprichtnicht]:Tx[T_entsprichtdoch])+
			Tx[T_Muster_Doppelpunkt]+rot+zmakt->holmuster()+schwarz+"'";
		if (ausgp&&obverb) *ausgp<<meld<<endl; else Log(meld,obverb,oblog);
		if (!reti){
			return zielname(qdatei,zmakt->ziel,wieweiterzaehl,zieldatei,obgleichp,obverb,oblog,ausgp);
		} //     if (!reti)
		if (zmakt->obmusterleer()) break;
	} //   for(zielmustercl *zmakt=zmp;1;zmakt++)
	return {};
} // zielname

// von fkn-systems
const char * const rulesdt="/etc/udev/rules.d/46-FKN_isdn_capi.rules";
// wird aufgerufen in: hhcl::pruefcapi
void pruefrules(int obverb, int oblog) 
{
	Log(violetts+Tx[T_pruefrules]+schwarz,obverb?obverb-1:0,oblog);
	struct stat entrybuf={0};
	if (lstat(rulesdt, &entrybuf)) { 
		mdatei rules(rulesdt,ios::out);
		if (rules.is_open()) {
			rules<<"# Symlink (capi20 -> capi) zu"<<endl;
			rules<<"# Kompatibilitaetszwecken erstellen"<<endl;
			rules<<"KERNEL==\"capi\", SYMLINK=\"capi20\""<<endl;
		} //     if (rules.is_open())
	} //   if (lstat(rulesdt, &entrybuf))
} // void pruefrules() {

const string blackdt="/etc/modprobe.d/50-blacklist.conf";
// wird aufgerufen in: pruefcapi
void pruefblack(int obverb, int oblog) 
{
	Log(violetts+Tx[T_pruefblack]+schwarz,obverb?obverb-1:0,oblog);
	const char* vgl[]={"blacklist avmfritz", "blacklist mISDNipac"};
	uchar obda[]={0}, obeinsfehlt=0;
	mdatei blacki(blackdt,ios::in);
	if (blacki.is_open()) {
		string zeile;
		while(getline(blacki,zeile)) {
			for(unsigned i=0;i<sizeof vgl/sizeof *vgl;i++) {
				if (zeile.find(vgl[i])!=string::npos) obda[i]=1;
			}
		} //     while(getline(blacki,zeile))
		blacki.close();
		for(unsigned i=0;i<sizeof vgl/sizeof *vgl;i++) {
			if (!obda[i]) {obeinsfehlt=1;break;}
		} //     for(unsigned i=0;i<sizeof vgl/sizeof *vgl;i++)
		if (obeinsfehlt) {
			mdatei blacka(blackdt,ios::out|ios::app);
			if (blacka.is_open()) {
				for(unsigned i=0;i<sizeof vgl/sizeof *vgl;i++) {
					if (!obda[i]) {
						Log(Tx[T_haengean]+blaus+blackdt+schwarz+Tx[T_an_mdpp]+gruen+vgl[i]+schwarz,obverb,oblog);
						blacka<<vgl[i]<<endl;
					}
				} // for(unsigned i=0;i<sizeof vgl/sizeof *vgl;i++) 
			} // if (blacka.is_open()) 
		} // obeinsfehlt
	} else {
	} // if (blacki.is_open())  else
} // void pruefblack(int obverb, int oblog) 

// wird aufgerufen in pruefsfftobmp und empfcapi
void hhcl::instsfftobmp()
{
	uchar obboostda=!linstp->doggfinst("boost-devel",obverb,oblog);
	if (obboostda) {
		const string sff="sfftobmp_copy";
		holvomnetz(sff);
		const string vorcfg="sed -i.bak -e \"s/^[[:blank:]]*\\(char \\*shortopts.*\\)/const \\1/;"
			"s/m_vFiles.push_back( fs::path(m_argv\\[n\\].*/m_vFiles.push_back( fs::path(string(m_argv[n])\\/*, fs::native*\\/) );"
			"/\" src/cmdline.cpp"
			"&& sed -i.bak -e \"s/lboost_filesystem-mt/lboost_filesystem/g\" src/Makefile.in "
			////                      " && sed -i.bak -e 's/-${am__api_version}//g' aclocal.m4 "
			////                      " && sed -i.bak -e 's/-${am__api_version}//g' configure "
			"&& sed -i.bak -e \"s/\\(-lboost_filesystem\\)/-lboost_system \\1/g\" src/Makefile.in ";
		kompiliere(sff,s_gz,vorcfg);
	} // 	if (obboostda)
} // void instsfftobmp


zielmustercl::zielmustercl(const char * const vmuster,const char * const vziel):muster(vmuster),ziel(vziel)
{
	kompilier();
};  // zielmustercl

zielmustercl::zielmustercl(const char * const vmuster,const string& vziel):muster(vmuster),ziel(vziel)
{
	kompilier();
};  // zielmustercl

zielmustercl::zielmustercl(const string& vmuster,const string& vziel):muster(vmuster),ziel(vziel)
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
		cfcnfC<<new WPcl("spool_dir",&spoolcapivz,wstr);
		cfcnfC<<new WPcl("fax_user_dir",&cfaxuservz,wstr);
		cfcnfC<<new WPcl("send_tries",&maxcdials,wstr);
		cfcnfC<<new WPcl("send_delays",&send_delays,wstr);
		cfcnfC<<new WPcl("outgoing_MSN",&outgoing_MSN,wstr);
		cfcnfC<<new WPcl("dial_prefix",&dial_prefix,wstr);
		cfcnfC<<new WPcl("fax_stationID",&fax_stationID,wstr);
		cfcnfC<<new WPcl("fax_headline",&fax_headline,wstr);
		cfcnfC<<new WPcl("fax_email_from",&fax_email_from,wstr);
		cfcnfC<<new WPcl("outgoing_timeout",&outgoing_timeout,wstr);
		neu=0;
	} // 	if (neu)
} // void hhcl::cfcnfCfuell

// aufgerufen in liescapiconf
void hhcl::cccnfCfuell()
{
	static uchar neu=1;
	if (neu) {	
		cccnfC<<new WPcl("incoming_script",&cdn[0],wstr);
		cccnfC<<new WPcl("log_file",&cdn[1],wstr);
		cccnfC<<new WPcl("log_error",&cdn[2],wstr);
		cccnfC<<new WPcl("idle_script",&cdn[3],wstr);
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
		if (cfaxcp) delete cfaxcp;
		cfaxcp = new confdcl(cfaxconfdt,obverb);
			caus<<"vor causwert 6"<<endl;
		cfaxcp->causwert(&cfcnfC);
		cfaxcp->Abschn_auswert(obverb);
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
		for(size_t i=cfaxcp->zn.size();i>0;) {
			char buf[250]={0};
			if ((sscanf(cfaxcp->zn[--i].c_str(),"[%[^]]]",buf))>0) 
				if (strcasecmp(buf,"global")) {
					if (!cuser.empty()) {
						if (cuser==buf) {
							ncuser.clear();
							break;
						} //            if (cuser==buf)
					} //           if (!cuser.empty())
					if (ncuser.empty()) ncuser=buf; // nehme den letzten besten user
				} //         if (strcasecmp(buf,"global"))
		} //     for(size_t i=cfaxcp->zn.size();i>0;)
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
			caus<<"vor causwert 7"<<endl;
			ccapc.causwert(&cccnfC);
			cczulesen=0;
			if (!cuser.empty()) {
				for(size_t j=0;j<sizeof cdn/sizeof *cdn;j++) {
					if (!cdn[j].empty()) {
						//// caus<<"cdn["<<j<<"]: "<<cdn[j]<<endl;
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
	if (!cdn[0].empty()) {
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
			for(unsigned snr=0;snr<cfcnfC.size();snr++) {
				Log("snr: "+blaus+ltoan(snr)+schwarz+" "+cfcnfC[snr]->pname+", "+cfcnfC[snr]->holstr());
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
							for(unsigned snr=0;snr<cfcnfC.size();snr++) {
								if (lzeile.find(cfcnfC[snr]->pname)!=string::npos) {
									//// _out<<"snr: "<<snr<<", lzeile: "<<tuerkis<<lzeile<<schwarz<<", rzeile: "<<blau<<rzeile<<schwarz<<endl;
									string altwert=rzeile;
									gtrim(&altwert);
									anfzweg(altwert); // Anfuehrungszeichen entfernen
									if (snr==0 || snr==1) cfcnfC[snr]->setzstr(altwert); // spool_dir und fax_user_dir hier nicht konfigurierbar
									Log(string("cfcnfC[")+ltoan(snr)+"].name: "+tuerkis+cfcnfC[snr]->pname+schwarz+Tx[T_komma_wert]+
											(cfcnfC[snr]->holstr()==altwert?blau:rot)+cfcnfC[snr]->holstr()+schwarz+Tx[T_komma_Altwert]+
											blau+altwert+schwarz,obverb+iru,oblog+iru);
									if (cfcnfC[snr]->holstr()!=altwert) {
										if (!iru) {
											neuschreiben=1;
											paramdiff=1;
										} else {
											string zschr=cfcnfC[snr]->pname+" = \""+cfcnfC[snr]->holstr()+"\"";
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

// wird aufgerufen in: konfcapi, verzeichnisse
void hhcl::pruefcvz()
{
	//// <<rot<<"cfaxuservz in pruefcvz: "<<cfaxuservz<<schwarz<<endl;
	Log(violetts+Tx[T_pruefcvz]+schwarz+" ccfaxuservz: "+violett+cfaxuservz+schwarz);
	kuerzevtz(&cfaxuservz);
	pruefverz(cfaxuservz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0,/*besitzer=*/"",/*benutzer=*/cuser,/*obmachen=*/0);
	cfaxusersqvz=cfaxuservz+vtz+cuser+"/sendq"; //  "/var/spool/capisuite/users/<user>/sendq";
	pruefverz(cfaxusersqvz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0,/*besitzer=*/"",/*benutzer=*/cuser,/*obmachen=*/0);
	cfaxuserrcvz=cfaxuservz+vtz+cuser+"/received";
	cfaxuserrcfalschevz=cfaxuserrcvz+"/falsche";
	//// <<violett<<"cfaxuserrcvz: "<<cfaxuserrcvz<<schwarz<<endl;
	pruefverz(cfaxuserrcvz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0,/*besitzer=*/"",/*benutzer=*/cuser,/*obmachen=*/0);
} // hhcl::pruefcvz

// in empfcapi() und pruefcapi(), rueckfragen()
void hhcl::pruefsfftobmp()
{
	Log(violetts+Tx[T_pruefsfftobmp]+schwarz);
	lsysen system=lsys.getsys(obverb,oblog);
	if (system==fed) {
		//// P=hylafax_copy; T=$P.tar.gz; wget https://github.com/libelle17/$P/archive/master.tar.gz -O $T && tar xpvf $T && rm -f $T && mv ${P}-master/* . && rmdir ${P}-master
		uchar obboostda=!linstp->doggfinst("boost-devel",obverb,oblog);
		if (!obprogda("sfftobmp",obverb,oblog) || systemrueck("sfftobmp --version 2>/dev/null")) {
			uchar obfrei= obprogda("jpegtran",obverb,oblog) && obprogda("cjpeg",obverb,oblog) && obprogda("djpeg",obverb,oblog);
			if (!obfrei) {
				const string jpeg="jpegsrc_copy";
				holvomnetz(jpeg);
				obfrei=!kompiliere(jpeg,s_gz);
			}
			if (obfrei) {
				/*//
					svec brueck;
				// rpm -q boost-devel / dpkg -s libboost-dev -> evtl. besser
				systemrueck(sudc+"find "+lsys.getlib64()+" /usr/lib /usr/local/lib /usr/local/lib64 /lib -name libboost_python.so -print -quit",
				obverb,oblog,&brueck);
				uchar obboostda=brueck.size();
				if (!obboostda) KLA
				obboostda = !linstp->doggfinst("boost",obverb,oblog) && !linstp->doggfinst("boost-devel",obverb,oblog);
				KLZ
				 */
				if (obboostda) {
					int serg=0;
					if (systemrueck("grep '/usr/local/lib' /etc/ld.so.conf",obverb,oblog,/*rueck=*/0,/*obsudc=*/1)) {
            systemrueck("echo '/usr/local/lib' >> /etc/ld.so.conf",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
						serg=systemrueck("ldconfig",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
					}
					if (!serg) {
						instsfftobmp();
					} // if (!systemrueck(sudc+"grep
				} // if (!linstp->doggfinst("boost",obverb,oblog) && !linstp->doggfinst("boost-devel",obverb,oblog)) 
			} // if (!systemrueck(befehl,obverb,oblog)) 
		} // if (!obprogda("sfftobmp",obverb,oblog)) 
	} else {
		linstp->doggfinst("sfftobmp",obverb,oblog);
	} // if (system==fed) else
	Log(violetts+Txk[T_Ende]+Tx[T_pruefsfftobmp]+schwarz);
} // pruefsfftobmp


// in konfcapi und faxemitC (da konfacpi aus pruefcapi nicht unbedingt aufgerufen wird)
// Datei /fax-nextnr ggf. richtigstellen
void hhcl::nextnum()
{
	//// dieser Abschnitt war zuvor richtcapiher
	ulong nextnr=0;
	struct stat entrynextnr={0};
	//// <<"cfaxusersqvz: "<<cfaxusersqvz<<endl;
	nextdatei=cfaxusersqvz+"/fax-nextnr";
	//// <<ndatei<<endl;
	if (!lstat(cfaxusersqvz.c_str(),&entrynextnr)) {
		mdatei nextstr(nextdatei,ios::in);
		if (nextstr.is_open()) {
			string zeile;
			if (getline(nextstr,zeile)) {
				nextnr=atol(zeile.c_str());
			}
		} // if (nextstr.is_open()) 
	} // if (!lstat(cfaxusersqvz.c_str(),&entrynextnr))
	if (!nextnr) {
		pruefverz(cfaxuservz,obverb,oblog,/*obmitfacl=*/2,/*obmitcon=*/0,/*besitzer=*/"",/*benutzer=*/cuser);
		setfaclggf(spoolcapivz,obverb>1?obverb-1:0,oblog,/*obunter=*/wahr,/*mod=*/7,/*obimmer=*/wahr);
		if (findv==1) {
			cmd=sudc+"echo $(( `find "+spoolcapivz+ " -type f -name '*-fax-*.sff' 2>/dev/null "
				"| cut -d '-' -f3 | cut -d '.' -f1 | sort -rn | head -n1` + 1 )) > '"+nextdatei+"'";
			systemrueck(cmd,obverb,oblog,/*rueck=*/0,/*obsudc=*/0);
		} else {
			svec qrueck;
			findfile(&qrueck,findv,obverb,oblog,0,spoolcapivz,/*muster=*/"-fax-.*\\.sff$");
			size_t maxzahl=0;
			for(size_t i=0;i<qrueck.size();i++) {
				string q=qrueck[i];
				string zahls;
				for(size_t j=0;j<qrueck[i].length();j++){char buch=qrueck[i][j];if (buch>='0'&&buch<='9') zahls+=buch;}
				size_t zahl=atol(zahls.c_str());
				if (zahl>maxzahl) maxzahl=zahl;
			} // 			for(size_t i=0;i<qrueck.size();i++)
			maxzahl++;
			mdatei nextstr(nextdatei,ios::out);
			if (nextstr.is_open()) {
				nextstr<<maxzahl<<endl;
			} // 			if (nextstr.is_open())
		} // 		if (findv==1) else
	} // 	if (!nextnr)
	setfaclggf(nextdatei,obverb>1?obverb-1:0,oblog,/*obunter=*/falsch,/*mod=*/6);
} // void hhcl::nextnum()

// wird aufgerufen in: pruefcapi(), anhalten()
void hhcl::capisv()
{
	if (!scapis) scapis=new servc("","capisuite");
} // void hhcl::capisv(obverb,oblog)

// wird aufgerufen in: pruefcapi
// lieftert 0, wenn die Dienstdatei da (erg)
// setzt csfehler, wenn Dienst nicht laeuft
int hhcl::cservice()
{
	Log(violetts+"cservice()"+schwarz);
	int csfehler=0;
	int erg=-1;
	string cspfad;
	if (obprogda("capisuite",obverb,oblog,&cspfad)) {
		erg=0;
		scapis->stopggf(obverb,oblog,1); 
		const string vz="/etc/init.d",datei="/capisuite",ziel="/etc/ausrangiert";
		if (findv==1) {
			erg=systemrueck(/*//sudc+"sh -c 'systemctl stop capisuite; pkill capisuite >/dev/null 2>&1; pkill -9 capisuite >/dev/null 2>&1; "*/
					"cd "+vz+
					" && [ $(find . -maxdepth 1 -name \"capisuite\" 2>/dev/null | wc -l) -ne 0 ]"
					" &&{ "+sudc+"mkdir -p "+ziel+"&&"+sudc+"mv -f "+vz+datei+" "+ziel+"; }||:"/*//'*/,obverb,oblog,/*rueck=*/0,/*obsudc=*/0);
		} else {
			svec qrueck;
			findfile(&qrueck,findv,obverb,oblog,0,vz,/*muster=*/datei+"$",1,1,Fol_Dat);
			if (qrueck.size()) {
				pruefverz(ziel,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/1,/*besitzer=*/"",/*benutzer=*/cuser);
				systemrueck("mv -f "+vz+datei+" "+ziel,obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
			} // 			if (qrueck.size())
		} // 		if (findv==1)
		// entweder Type=forking oder Parameter -d weglassen; was besser ist, weiss ich nicht
		csfehler+=!scapis->spruef("Capisuite",0,meinname,cspfad/*+" -d"*/,"","",linstp,obverb,oblog);
		if (obverb) Log("csfehler: "+gruens+ltoan(csfehler)+schwarz);
		////    return csfehler;
	} // if (obprogda("capisuite",obverb,oblog,&cspfad)) 
	return erg;
} // int hhcl::cservice()

// in pruefcapi
void hhcl::clieskonf()
{
	Log(violetts+Tx[T_clieskonf]+schwarz+", cfaxcp->name: "+violett+(cfaxcp?cfaxcp->fname:"0")+schwarz);
	if (fax_stationID!="+"+countrycode+" "+citycode+" "+msn  
			|| outgoing_MSN!=msn  
			|| fax_headline!=cFaxUeberschrift  
		 ) {
		capizukonf=1;
	}
	int richtige=0;
	if (cfaxcp) {
		cfaxcp->Abschn_auswert(obverb);
		for(size_t i=0;i<cfaxcp->abschv.size();i++) {
			if (cfaxcp->abschv[i].aname==cuser) {
				richtige=0;
				//// <<"abschv["<<i<<"].av.size() "<<cfaxcp->abschv[i].av.size()<<endl;
				for(size_t j=0;j<cfaxcp->abschv[i].av.size();j++) {
					if (cfaxcp->abschv[i].av[j].pname=="fax_numbers") {if (cfaxcp->abschv[i].av[j].wert==outgoing_MSN) richtige++;}
					else if (cfaxcp->abschv[i].av[j].pname=="fax_stationID") {if (cfaxcp->abschv[i].av[j].wert==fax_stationID) richtige++;}
					else if (cfaxcp->abschv[i].av[j].pname=="fax_headline") {if (cfaxcp->abschv[i].av[j].wert==fax_headline) richtige++;}
					else if (cfaxcp->abschv[i].av[j].pname=="fax_email_from") {if (cfaxcp->abschv[i].av[j].wert==fax_email_from) richtige++;}
				} //         for(size_t j=0;j<cfaxcp->abschv[i].av.size();j++)
				break;
			} //       if (cfaxcp->abschv[i].aname==cuser)
		} //     for(size_t i=0;i<cfaxcp->abschv.size();i++)
		if (richtige!=4) {
			capizukonf=1;
		} //     if (richtige!=4)
	} //   if (cfaxcp)
	svec ckzlrueck;
	systemrueck("grep connect_faxG3 `grep incoming_script= "+ccapiconfdt+" 2>/dev/null|cut -d'\"' -f2 2>/dev/null`"
			"|sed 's/.*headline//;s/^,//;s/).*//'",obverb,oblog,&ckzlrueck,/*obsudc=*/0,/*verbergen=*/1);
	if (ckzlrueck.size()) {
		if (cklingelzahl!=ckzlrueck[0]) {
			//// <<", ckzlrueck[0]: '"<<ckzlrueck[0]<<"', cklingelzahl: '"<<cklingelzahl<<"'"<<endl;
			capizukonf=1;
		}
	} else {
		capizukonf=1;
	} // 	if (ckzlrueck.size()) else
} // void hhcl::clieskonf()

// wird aufgerufen in: pruefcapi
void hhcl::pruefmodcron()
{
	//  ::Log(violetts+Tx[T_pruefmodcron]+schwarz,obverb?obverb-1:0,oblog);
	Log(violetts+Tx[T_pruefmodcron]+schwarz);
	const string mp="@reboot /sbin/modprobe ";
	const string mps[]={mp+"capi",mp+"fcpci"};
	setztmpcron();
	for(uchar ru=0;ru<sizeof mps/sizeof *mps;ru++) {
		if (systemrueck("bash -c 'grep \""+mps[ru]+"\" -q <("+sudc+"crontab -l 2>/dev/null)'",obverb,oblog,/*rueck=*/0,/*obsudc=*/0)) {
			svec rueck;
			const string bef="crontab -l 2>/dev/null >"+tmpcron+";echo \""+mps[ru]+"\">>"+tmpcron+";crontab "+tmpcron;
			if (!systemrueck(bef,obverb,oblog,&rueck,/*obsudc=*/1)) {
				////    for(size_t znr=0;znr<rueck.size();znr++) { ::Log(rueck[znr],1+obverb,oblog); } //     for(size_t znr=0;znr<rueck.size();znr++)
				const string befehl=sudc+"bash -c 'grep \""+mps[ru]+"\" -q <(crontab -l 2>/dev/null)&&"
					"{ crontab -l 2>/dev/null|sed \"/"+ersetzAllezu(mps[ru],"/","\\/")+"/d\">"+tmpcron+";crontab "+tmpcron+";};:'";
				anfgg(unindt,befehl,bef,obverb,oblog);
			} //if (!systemrueck("("+sudc+"crontab -l 2>/dev/null >"+tmpcron+";echo \""+mps[ru]+"\">>"+tmpcron+";"+sudc+"crontab "+tmpcron+")",obverb,oblog,&rueck))
		} // 		if (systemrueck("bash -c 'grep \""+mps[ru]+"\" -q <("+sudc+"crontab -l 2>/dev/null)'",obverb,oblog))
	} //   for(uchar ru=0;ru<sizeof mps/sizeof *mps;ru++)
} // void pruefmodcron(int obverb, int oblog)


// wird aufgerufen in: untersuchespool, main
// rueckgabe: wie obcapi eingestellt sein sollte
int hhcl::pruefcapi()
{
	Log(violetts+Tx[T_pruefcapi]+schwarz+" obcapi: "+(obcapi?"1":"0"));
	static uchar capiloggekuerzt=0;
	static uchar capischonerfolgreichinstalliert=0;
	int capilaeuft=0;
	int erg=0;
	unsigned versuch=0;
	uchar schonkonfiguriert=0;
	capisv();
	if (obcapi) {
		for(;versuch<2;versuch++) {
			// capi4linux muss zum Laufen der Capisuite installiert sein
			// fuer fcpci muss in driver.c eingefuegt werden:
			//// #if !defined(IRQF_DISABLED)
			//// #  define IRQF_DISABLED 0x00
			//// #endif
			////    capilaeuft=(PIDausName("capisuite")>=0);
			capilaeuft=this->scapis->machfit(obverb?obverb-1:0,oblog,wahr)&&!ccapiconfdt.empty()&&!cfaxconfdt.empty();
			Log(violetts+Tx[T_capilaeuft]+schwarz+ltoan(capilaeuft)+schwarz);
			if (capilaeuft) {
				capischonerfolgreichinstalliert=1;
			} else {
				////      pid_t pid = GetPIDbyName("capisuite") ; // If -1 = not found, if -2 = proc fs access error
				uchar fcpcida=0, capida=0, capidrvda=0;
				vector<string> rueck;
				systemrueck("lsmod",obverb,oblog,&rueck,/*obsudc=*/0);
				for(size_t i=0;i<rueck.size();i++){
					if (!fcpcida) {if (!rueck[i].find("fcpci ")) {fcpcida=1;continue;}}
					if (!capidrvda) {if (!rueck[i].find("capidrv ")) {capidrvda=1;continue;}}
					if (!capida) {if (!rueck[i].find("capi ")) {capida=1;continue;}}
					if (fcpcida && capida && capidrvda) break;
				} // for(size_t i=0;i<rueck.size();i++)
				lsysen system=lsys.getsys(obverb,oblog);
				if (!fcpcida || !capida || !capidrvda) {
					::Log(blaus+Tx[T_Module_geladen]+schwarz+" fcpci: "+blau+(fcpcida?"1":"0")+schwarz+", capi: "+blau+(capida?"1":"0")+schwarz+
							", capidrv: "+blau+(capidrvda?"1":"0")+schwarz+Tx[T_Lade_Capi_Module],obverb,0);
					systemrueck("modprobe -rf avmfritz mISDNipac hisax_fcpcipnp hisax_isac hisax",obverb,oblog,/*rueck=*/0,/*obsudc=*/1,1);
					utsname unbuf;
					if (!fcpcida) {
						uname(&unbuf);
						Log(Tx[T_Kernelversion]+blaus+unbuf.release+schwarz);
					}
					for(uchar ivers=0;ivers<3;ivers++) {
						if (!fcpcida)
							if (systemrueck("modprobe -v fcpci 2>/dev/null",obverb-1+ivers,oblog,/*rueck=*/0,/*obsudc=*/1)) {
								const string fcpciko=string("/lib/modules/")+unbuf.release+"/kernel/extras/fcpci.ko";
								switch (ivers) {
									case 1:
										tuloeschen(fcpciko,cuser,obverb,oblog);
										break;
									case 2:
										::Log(rots+Tx[T_KannFcpciNInstVerwCapiNicht]+blau+linstp->ersetzeprog("kernel-source")+rots+
												Tx[T_eine_neuere_Version_als_die_des_aktuellen_Kernels_installiert_worden_sein_dann_bitte_erneutes_Systemupdate]+schwarz,1,1);
										erg=1;
										goto schluss;
								} // 								switch (ivers)
								struct stat entryfc={0};
								if (lstat(fcpciko.c_str(), &entryfc)) {
									::Log(Txk[T_datei]+blaus+fcpciko+schwarz+Tx[T_nichtgefFcpciMfdKinstallierwerden],obverb,1);
									int altobverb=obverb;
									obverb=obverb<2?2:obverb;
									linstp->doinst("kernel-source",1+obverb,oblog);
									/*// 
										const string qvz="/usr/src";
										const string versi="fcpci-3.10.0";
										const string srcf=string("fritz-")+versi+".tar.bz2";
										pruefverz(qvz,obverb,oblog,0);
										struct stat entrysrc={0};
										if (lstat((qvz+vtz+srcf).c_str(),&entrysrc)) KLA
										systemrueck(string("cd ")+qvz+";"+sudc+"wget https://belug.de/~lutz/pub/fcpci/"+srcf+
										" --no-check-certificate",1+obverb,oblog);
										KLZ
										string srcvz=qvz+vtz+versi+"/src";
										if (lstat(srcvz.c_str(),&entrysrc)) KLA
										systemrueck(string("cd ")+qvz+";"+sudc+"tar xjf "+srcf,obverb,oblog);
									//sed -e '/#include <linux\/isdn\/capilli.h>/ a\#include <linux\/utsname.h>' -e '/NOTE("(%s built on %s at %s)\\n", TARGET, __DATE__, __TIME__);/ c    NOTE("(%s built on release %s, version %s)\\n", TARGET, utsname()->release, utsname()->version);' main.c >main_neu.c
									// fuer Kernel 4.3.3-3-default und gcc muss jetzt noch 1) , __DATE__ und __TIME__ aus main.c Zeile 365 entfernt werden,
									// 2) in driver.c Zeile 373 IRQF_DISABLED durch 0x00 ersetzt werden, dann kompilier- und installierbar
									KLZ
									systemrueck("cd "+srcvz+";"+sudc+"test -f driver.c.bak || sed -i.bak '/request_irq/i#if !defined(IRQF_DISABLED)\\n"
									"# define IRQF_DISABLED 0x00\\n#endif' driver.c;"
									sudc+"sed -e '/#include <linux\\/isdn\\/capilli.h>/a #include <linux\\/utsname.h>' "
									"-e '/NOTE(\"(%s built on %s at %s)\\\\n\", TARGET, __DATE__, __TIME__);/"
									"c NOTE(\"(%s built on release %s, version %s)\\\\n\", TARGET, utsname()->release, utsname()->version);' "
									"main.c >main_neu.c;mv -n main.c main.c.bak;mv -n main_neu.c main.c;"
									sudc+"make clean",1+obverb,oblog);
									svec rueck;
									systemrueck(sudc+"rm -f /root/bin/xargs",1+obverb,oblog);
									systemrueck("cd "+srcvz+";"+sudc+"make all ",1+obverb,oblog); 
									// || { "+sudc+"dnf clean all;"+sudc+"dnf update;"+sudc+"make all; }
									systemrueck("cd "+srcvz+";"+sudc+"make install",1+obverb,oblog);
									 */
									// in Mint musste man gcc downgraden, um fcpci installieren zu koennen
									uchar obdown=0;
									string gccpfad,gpppfad;
									struct utsname unameD={0};
									uname(&unameD);
									const string rel=unameD.release;
									size_t p1=rel.find('.');
									if (p1!=string::npos) {
										size_t p2=rel.find('.',p1+1);
										if (p2!=string::npos) {
											float vers=atof(rel.substr(0,p2).c_str());
											if (vers>0 && vers<3.14) {
												if (obprogda("gcc",obverb,oblog,&gccpfad) && obprogda("g++",obverb,oblog,&gpppfad)) {
													obdown=1;
													//// systemrueck(sudc+"cp \""+gccpfad+"\" \""+gccpfad+".bak\" && " sudc+"cp \""+gpppfad+"\" \""+gpppfad+".bak\"",obverb,oblog);
													if (!kopier(gccpfad,gccpfad+".bak",obverb,oblog)) kopier(gpppfad,gpppfad+".bak",obverb,oblog);
													linstp->doinst("gcc-4.8",1+obverb,oblog);
													linstp->doinst("g++-4.8",1+obverb,oblog);
													systemrueck("ln -sf \""+gccpfad+"-4.8\" \""+gccpfad+"\" && "+
															"ln -sf \""+gpppfad+"-4.8\" \""+gpppfad+"\"",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
												} // if (!obprogda("gcc",obverb,oblog,&gccpfad) && !obprogda("g++",obverb,oblog,&gpppfad)) 
											} // if (vers>0 && vers<3.14) 
										} // if (p2!=string::npos) 
									} // if (p1!=string::npos) 
									if (systemrueck("ls /lib/modules/$(uname -r)/build",obverb,oblog,/*rueck=*/0,/*obsudc=*/0)) {
										if (system==deb) {
											systemrueck("apt -y install linux-headers-$(uname -r)",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
										}
									} // 									if (systemrueck("ls /lib/modules/$(uname -r)/build",obverb,oblog))
									systemrueck("ls -l /lib/modules/$(uname -r)/build 2>/dev/null || "
											"{ NEU=$(find /lib/modules -type l -name build -print0|"+linstp->xargspf+" -0 -r ls -l --time-style=full-iso|"
											"sort -nk6,7|head -n1|cut -d' ' -f9); test -h $NEU &&"+sudc+"cp -a $NEU /lib/modules/$(uname -r)/build; }",
											obverb,oblog,/*rueck=*/0,/*obsudc=*/0);
									const string proj="fcpci_copy";
									const string srcvz=instvz+vtz+proj+".tar.gz";
									holvomnetz(proj);
									const string vorcfg=sudc+"test -f driver.c.bak || sed -i.bak \"/request_irq/i#if \\!defined(IRQF_DISABLED)\\n"
										"# define IRQF_DISABLED 0x00\\n#endif\" driver.c;"+
										sudc+"sed -e '/#include <linux\\/isdn\\/capilli.h>/a #include <linux\\/utsname.h>' "
										"-e '/NOTE(\"(%s built on %s at %s)\\\\n\", TARGET, __DATE__, __TIME__);/"
										"c NOTE(\"(%s built on release %s, version %s)\\\\n\", TARGET, utsname()->release, utsname()->version);' "
										"main.c >main_neu.c;mv -n main.c main.c.bak;mv -n main_neu.c main.c;"+
										sudc+"sed -i.bak \"/install: / i .PHONY: uninstall\\nuninstall:\\n\\t\\t"+
										sudc+"modprobe -r \\$\\(CARD\\).ko\\n\\t\\tsudo rm \\$\\(TARGETDIR\\)/\\$\\(CARD\\)\\n\" Makefile;"+
										sudc+"make clean";
									const string cfgbismake=" 2>/dev/null;"+sudc;
									kompiliere(proj,s_gz,vorcfg,cfgbismake);
									systemrueck("depmod",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
									if (obdown) {
										systemrueck("mv -f \""+gccpfad+".bak\" \""+gccpfad+"\" &&"+
												"mv -f \""+gpppfad+".bak\" \""+gpppfad+"\"",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
									} // 									if (obdown)
									obverb=altobverb;
								} // if (lstat(fcpciko.c_str(), &entryfc)) 
							} // if (systemrueck
					} // for(uchar ivers=0;ivers<2;ivers++) 

					// Fedora:
					// dnf install ncurses-devel
					// cd /usr/src/kernels/4.7.3-200.fc24.x86_64
					// make olddefconfig
					// dnf install elfutils-libelf-devel
					if (systemrueck("modprobe capi 2>/dev/null",obverb,oblog,/*rueck=*/0,/*obsudc=*/1)) {
						if (system==fed) {
							svec vrueck1,vrueck2;
							string v1,v2;
							const string getvmvers=sudc+"ls /boot/vmlinuz-* -r|head -n 1|cut -d- -f2,3,4,5";
							systemrueck(getvmvers,obverb,oblog,&vrueck1,/*obsudc=*/1);
							if (vrueck1.size()) v1=vrueck1[0];
							systemrueck("dnf -y install kernel-modules-extra-$(uname -r) && "
									"{ lsmod | grep capidrv ||modprobe capidrv 2>/dev/null; "
									"lsmod | grep kernelcapi ||modprobe kernelcapi 2>/dev/null;}",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
							systemrueck(getvmvers,obverb,oblog,&vrueck2,/*obsudc=*/1);
							if (vrueck2.size()) v2=vrueck2[0];
							////            <<"vi: "<<v1<<"\n"<<"v2: "<<v2<<endl;
							// sollte nach Korrektur von kernel-modules-extra zu kernel-modules-extra-$(uname -r) kaum mehr vorkommen
							if (v1!=v2) {
								virtautokonfschreib();
								::Log(blaus+Tx[T_Zur_Inbetriebnahme_der_Capisuite_muss_das_Modul_capi_geladen_werten]+schwarz+v1+blau+" -> "
										+schwarz+v2+blau+").\n"+blau+Tx[T_Bitte_zu_dessen_Verwendung_den_Rechner_neu_starten]+schwarz+mpfad+blau+Tx[T_aufrufen]
										+schwarz,1,1);
								exit(9);
							} // if (v1!=v2) 
#ifdef brauchtsaano // am 19.3.17 braucht's es ned
							//// nach kdpeter.blogspot.de/2013/10/fedora-compile-single-module-directory.html
							////         systemrueck(sudc+"dnf -y install @\"Development Tools\" rpmdevtools yum-utils ncurses-devel",obverb,oblog);
							linstp->doggfinst("fedpkg",obverb+1,oblog);
							linstp->doinst("fedora-packager",obverb+1,oblog,"fedora-cert");
							linstp->doinst("rpmdevtools",obverb+1,oblog,"rpmdev-setuptree");
							struct stat nstat={0};
							if (lstat("/usr/include/numa.h",&nstat))
								linstp->doinst("numactl-devel",obverb+1,oblog);
							if (lstat("/usr/include/curses.h",&nstat))
								linstp->doinst("ncurses-devel",obverb+1,oblog);
							linstp->doggfinst("pesign",obverb+1,oblog);
							systemrueck("rpmdev-setuptree",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
							svec krue;
							systemrueck("find "+instvz+" -name kernel-$(uname -r|rev|cut -d. -f2-|rev).src.rpm",obverb,oblog,&krue,/*obsudc=*/1);
							if (!krue.size()) {
								::Log(Tx[T_Moment_muss_Kernel_herunterladen],-1,oblog);
								systemrueck("cd "+instvz+" && dnf download --source kernel-$(uname -r)",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
							} // 							if (!krue.size())
							svec rueck;
							string kstring; // kernel-4.8.4-200.fc24.src.rpm
							systemrueck("cd "+instvz+" && ls -t kernel*.rpm|head -n 1",obverb,oblog,&rueck,/*obsudc=*/0);
							if (rueck.size()) {
								kstring=rueck[0]; // "kernel-4.8.4-200.fc24.src.rpm"
								string kernel=kstring.substr(kstring.find('-')+1);
								kernel.erase(kernel.rfind('.'));
								kernel.erase(kernel.rfind('.'));
								utsname unbuf;
								uname(&unbuf);
								const string release=unbuf.release;
								const string relev=release.substr(0,release.find(unbuf.machine)-1);
								if (kernel.find(relev)) {
									::Log(Tx[T_Der_Kernel_hat_sich_offenbar_seit_dem_Einloggen_von]+blaus+relev+schwarz+Tx[T_nach_]+blau+kernel+schwarz+
											Tx[T_verjuengt_Bitte_den_Rechner_neu_starten_und_dann_mich_nochmal_aufrufen],1,1);
									exit(10);
								} // 							if (kernel.find(relev))
								systemrueck("cd "+instvz+" && dnf -y builddep "+kstring,obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
								systemrueck("cd "+instvz+" && rpm -ivh "+kstring,obverb,oblog,/*rueck=*/0,/*obsudc=*/0);// mit sudo wird kernel.spec nicht erstellt
								// warning: group/user mockbuild does not exist - using root
								const string grund=gethome()+"/rpmbuild",specs=grund+"/SPECS",build=grund+"/BUILD";
								pruefverz(specs,obverb,oblog);
								pruefverz(build,obverb,oblog);
								for(unsigned iru=0;iru<2;iru++) {
									if (!systemrueck("cd '"+gethome()+"/rpmbuild/SPECS' && rpmbuild -bp --target=$(uname -m) kernel.spec",
												obverb,oblog,/*rueck=*/0,/*obsudc=*/1)) {
										systemrueck("dnf -y install kernel-devel-$(uname -r)",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
										systemrueck("KSTRING="+kstring+" && cd "+gethome()+"/rpmbuild/BUILD/$(echo $KSTRING|cut -d. -f1,2,4)/linux-`uname -r` && "
												"make -C /lib/modules/`uname -r`/build M=`pwd`/drivers/isdn/capi modules",obverb,oblog,/*rueck=*/0,/*obsudc=*/0);
										break;
									} // 									if (!systemrueck
									if (iru) break;
									systemrueck("dnf -y install $(cd '"+gethome()+"/rpmbuild/SPECS' && "
											sudc+"rpmbuild -bp --target=$(uname -m) kernel.spec 2>&1 >/dev/null"
											"| sed '/is needed by/!d;s/^[[:blank:]]*\\(.*\\) is needed by.*/\\1/')",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
									// dnf install audit-libs-devel binutils-devel bison elfutils-devel flex hmaccalc newt-devel numactl-devel 
									//     pciutils-devel "perl(ExtUtils::Embed)" perl-devel xz-devel
									// dann nochmal
								} // for(unsigned iru=0;iru<2;iru++) 
								// dann nach Anleitung: dnf -y install kernel-devel
								// cd ~/rpmbuild/BUILD/kernel<version>/linux<version>
								// make -C /lib/modules/`uname -r`/build M=`pwd`/drivers/isdn/capi modules
							} // if (rueck.size()) 
#endif					
						} // if (system==fed) 
					} // if (systemrueck(sudc+"modprobe capi",obverb,oblog))
					systemrueck("modprobe capidrv 2>/dev/null",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
				} // if (!fcpcida || !capida || !capidrvda) 
				pruefrules(obverb,oblog);
				pruefblack(obverb,oblog);
				capischonerfolgreichinstalliert=!linstp->obfehlt("capisuite capi4linux i4l-isdnlog");
				//// <<violett<<"capischonerfolgreichinstalliert: "<<schwarz<<(int)capischonerfolgreichinstalliert<<endl;
				if (capischonerfolgreichinstalliert) {
					struct stat d1={0}, d2={0};
					if (lstat("/etc/capisuite",&d1) && lstat("/usr/local/etc/capisuite",&d2))
						capischonerfolgreichinstalliert=0;
				}
				//// <<rot<<"capischonerfolgreichinstalliert 0: "<<(int)capischonerfolgreichinstalliert<<schwarz<<endl;
				if (!capischonerfolgreichinstalliert) {
					::Log(Tx[T_Konnte]+blaus+"capisuite"+schwarz+Tx[T_nichtstarten],1,oblog);
					linstp->doinst("ghostscript",obverb+1,oblog,"gs");
					//// if (systemrueck("which zypper",-1,-1)) KLA
					////        if (linstp->checkinst(-1,-1)!=zyp) KLA
					/*//
						if (linstp->ipr!=zypper) {
						::Log(rots+Tx[T_Kann_Capisuite_nicht_installieren_verwende_Capi_nicht],1,1);
						this->obcapi=0;
						erg=1;
						goto schluss;
						}
					 */
					if (system!=sus)
						linstp->doggfinst("capiutils",obverb+1,oblog);
					pruefsfftobmp();
					linstp->doggfinst("libcapi20-2",obverb+1,oblog);
					linstp->doggfinst("libcapi20-3",obverb+1,oblog);
					linstp->doggfinst("python-devel",obverb+1,oblog);
					linstp->doinst("libxslt-tools",obverb+1,oblog,"xsltproc");
					uchar mitcservice=0;
					// 25.11.16 nicht mehr auf Repo
					/*
						 if (system==sus) {
						 linstp->doggfinst("capi4linux i4l-isdnlog",obverb+1,oblog);
						 systemrueck("zypper lr | grep 'kkeil factory development project' || "
						 sudc+"zypper ar -f http://download.opensuse.org/repositories/home:/kkeil:/Factory/openSUSE_Factory/home:kkeil:Factory.repo",
						 1,1);
					// i4l-isdnlog scheint nicht wirklich noetig zu sein
					//   capischonerfolgreichinstalliert=!systemrueck("zypper -n --gpg-auto-import-keys in capisuite capi4linux i4l-isdnlog", 1+obverb,oblog); 
					// i4l-base geloescht
					capischonerfolgreichinstalliert=!linstp->doinst("-f capisuite capi4linux i4l-isdnlog",obverb+1,oblog);
					} // if (lsys.getsys(obverb,oblog)==sus) 
					 */
					if (!capischonerfolgreichinstalliert) {
						holvomnetz("capisuite_copy");
						svec csrueck;
						systemrueck("find /usr/lib*/python* -type f -name Makefile -printf '%h\\n' "+string(obverb?"":"2>/dev/null")+"| sort -r",
								obverb,oblog,&csrueck,/*obsudc=*/0);
						if (csrueck.size()) {
							struct stat c20stat={0},c20hstat={0};
							if (lstat((lsys.getlib64()+"/libcapi20.so").c_str(),&c20stat)||
									lstat("/usr/include/capi20.h",&c20hstat)) {
								holvomnetz("capi20_copy");
								kompiliere("capi20_copy",s_gz,"make clean");
								// ln sollte er in crontab finden
								systemrueck("cd "+instvz+" && L="+lsys.getlib64()+"/libcapi20.so && L3=${L}.3 && test -f $L3 && ! test -f $L && "+
										sudc+"ln -s $L3 $L; test -f $L;",obverb,oblog,/*rueck=*/0,/*obsudc=*/0);
							} // 							if (lstat((lsys.getlib64()+"/libcapi20.so").c_str(),&c20stat)||
							/*//
							//            systemrueck("sh -c 'P=capi20_copy;T=$P.tar.bz2;M=$P-master;cd "+instvz+" && tar xpvf $T && rm -rf $P; mv $M $P && cd $P "
							//                        " && ./configure && make &&"+sudc+"make install '",obverb,oblog);
							//            svec rueck;
							//            systemrueck("find /usr -name capi20.h 2>/dev/null",obverb,oblog,&rueck); 
							 */
							systemrueck("cd "+instvz+" &&{ cd capisuite 2>/dev/null &&{ test -f Makefile && make clean;};}",obverb-1,oblog,/*rueck=*/0,/*obsudc=*/0);
							obverb++;
							svec rueck;
							string pyvz;
							systemrueck("python -c \"import os; print os.path.dirname(os.__file__)\"",obverb,oblog,&rueck,/*obsudc=*/0);
							if (rueck.size()) {
								pyvz=*sersetze(&rueck[0],"/","\\/");
							} else {
								pyvz=ersetzAllezu(lsys.getlib64(),"/","\\/")+"\\/python2.7";
							} // 							if (rueck.size()) else
							if (!kompiliere("capisuite_copy",s_gz,
										"sed -i.bak \""
										// 20.11.16 diese Zeile scheint jetzt wieder in Fedora 24 unnoetig
										//													 "s/python_configdir=.*/python_configdir="+*sersetze(&csrueck[0],"/","\\/")+"/;"
										// 20.11.16 pyexecdir und pythondir mussten in Fedora 24 so gesetzt werden
										// 23.11.16: für openSUSE müsste man wohl --datarootdir=/usr/local/lib64 versuchen, 
										//           so wie es in capisuite.conf hier auch schon steht
										"s/\\( pyexecdir=\\).*/\\1\\`\\${PYTHON} -c \\\"import site;"
										"print site.getsitepackages()[0]\\\"\\`/;"
										"s/\\( pythondir=\\).*/\\1\\`\\${PYTHON} -c \\\"import site;"
										"print site.getsitepackages()[0]\\\"\\`/;"
										////													 "s/\\( *pyexecdir=\\).*/\\1"+pyvz+"\\/site-packages\\/capisuite/;"
										////													 "s/\\( *pythondir=\\).*/\\1"+pyvz+"\\/site-packages\\/capisuite/;"
										"s/\\( *python_configdir=\\).*/\\1\\`\\${PYTHON} -c \\\"import distutils.sysconfig;"
										"print distutils.sysconfig.get_config_var('\\''LIBPL'\\'')\\\"\\`/;"
										"s/\\( *python_moduledir=\\).*/\\1\\`\\${PYTHON} -c \\\"import site;"
										"print site.getsitepackages()[0]\\\"\\`/;"
										"s/\\( *python_moduleexecdir=\\).*/\\1\\`\\${PYTHON} -c \\\"import site;"
										"print site.getsitepackages()[0]\\\"\\`/;"
										"\" configure"
										////                           " && { test -f /usr/lib64/libcapi20.so.3 && ! test -f /usr/lib64/libcapi20.so && "
										////                           "ln -s /usr/lib64/libcapi20.so.3 /usr/lib64/libcapi20.so; true; }"
										,"HAVE_NEW_CAPI4LINUX=0 --libdir=/usr/local/lib64 --datarootdir=/usr/local/lib64 --sysconfdir=/etc --localstatedir=/var && "
										"sed -i \"s/PyErr_NewException(\\\"/PyErr_NewException((char*)\\\"/g\" src/application/capisuitemodule.cpp && ")) {
											mitcservice=1;
											// die durch konfcapi erstellte Datei cfaxconfdt wird durch Obiges überschrieben
											struct stat st={0};
											if (!lstat(cfaxconfeigdt.c_str(),&st)) {
												kopier(/*quel=*/cfaxconfeigdt,/*ziel=*/cfaxconfdt,obverb,oblog);
											}
										}
							/*//
							//            string befehl="sh -c 'P=capisuite; T=$P.tar.gz; M=$P-master; cd "+instvz+""
							//                  " && tar xpvf $T && rm -rf $P ; mv $M $P && cd $P"
							//                  " && sed -i.bak \"s_python_configdir=.*_python_configdir="+*sersetze(&csrueck[0],"/","\\/")+"_\" configure"
							//                  " && { test -f /usr/lib64/libcapi20.so.3 && ! test -f /usr/lib64/libcapi20.so && "
							//                        "ln -s /usr/lib64/libcapi20.so.3 /usr/lib64/libcapi20.so; true; } "
							//                  " && ./configure HAVE_NEW_CAPI4LINUX=0 --datarootdir=/usr/local/lib --sysconfdir=/etc --localstatedir=/var"
							//                  " && sed -i \"s/PyErr_NewException(\\\"/PyErr_NewException((char*)\\\"/g\" src/application/capisuitemodule.cpp"
							////                  " && sed -i.bak 's/<capi20.h>/\\\""+*sersetze(&rueck[0],"/","\\\"\\/")+"/' src/backend/capi.h"
							////                  " && sed -i.bak 's/<capi20.h>/\\\""+*sersetze(&rueck[0],"/","\\\"\\/")+"/' src/backend/connection.h"
							//                  " && make"
							//                  " && "+sudc+"make install"
							//                  " && "+sudc+"systemctl daemon-reload; "
							//                  "'";
							//            if (!systemrueck(befehl,obverb,oblog)) {
							//              //        pruefverz("/etc/capisuite",obverb,oblog,1,0);
							//              //        systemrueck("ls /etc/capisuite/capisuite.conf "
							//              //                    "|| cp -a "+instvz+"/capisuite/src/capisuite.conf /etc/capisuite");
							//              //        systemrueck("ls /etc/capisuite/fax.conf || cp -a "+instvz+"/capisuite/scripts/fax.conf /etc/capisuite");
							////              pruefverz("/usr/local/var/log",obverb,oblog,1,0);
							//              //         pruefverz("/usr/local/var/log",obverb,oblog,1,0);
							//              mitcservice=1;
							//            } // if (!systemrueck(sh -c ...
							 */
							obverb--;
						} // if (csrueck.size()) 
						// aktuelles Verzeichnis
					} // if (!capischonerfolgreichinstalliert) 
					liescapiconf();
					if (mitcservice) {
						capischonerfolgreichinstalliert=!cservice() && !ccapiconfdt.empty() && !cfaxconfdt.empty();
					}
					/*//
					// capisuite unter Kernel 4: 
					// zypper in sfftobmp libcapi20-2
					//        // scp linux2:/usr/include/capiutils.h /usr/include
					//        // scp linux2:/usr/include/capicmd.h /usr/include
					// zypper in libcapi20-3 python-devel capi4linux capi4linux-devel
					// in ubuntu: sfftobmp, (libcapi20-3)?, libcapi20-dev, python-dev, xsltproc

					// git clone https://github.com/larsimmisch/capisuite.git
					// wget https://github.com/larsimmisch/capisuite/archive/master.tar.gz -O capisuite.tar.gz
					// tar xpvf capisuite.tar.gz
					// mv capisuite-master capisuite
					// cd capisuite
					// bei mehreren Installationen wird hier unsortiert die erste Zeile genommen:
					// sed -i.bak 's_python_configdir=.*_python_configdir=`find \/usr\/lib*\/python* -type f -name Makefile -printf "%h\\\\n"`_' configure
					// bei mehreren Installationen koennte hier die richtigen genommen werden:
					// sed -i.bak 's_python_configdir=.*_python_configdir=`cat $(which python-config) | head -n 1| sed "s\/#\\!\\(.*\\)\/\\1\\\/config\/"`_' configure
					// auf Fedora funzt aber nur die Original-configure
					// in ubuntu: ./configure HAVE_NEW_CAPI4LINUX 0
					//            make
					//            "+sudc+"make install
					// "+sudc+"cp -ai "+instvz+"/capisuite/src/capisuite.conf /etc/capisuite/
					// "+sudc+"cp -ai "+instvz+"/capisuite/scripts/fax.conf /etc/capisuite/
					// "+sudc+"chmod 777 /usr/local/var/log
					// ln -s /usr/lib64/libcapi20.so.3.0.6 libcapi20.so
					// in ./src/application/pythonscript.cpp Zeile 104: (Py_ssize_t*)&length statt &length
					// in /usr/include/capiutils.h eine dritte Zeile einfuegen: #define CAPI_LIBRARY_V2
					// in src/backend/connection.cpp eine Zeile 26 einfuegen: #include <cstring>
					 */
				} // if (!capischonerfolgreichinstalliert)
				servc::daemon_reload();
			} // if (capilaeuft) else
			//// <<rot<<"capischonerfolgreichinstalliert: "<<schwarz<<(int)capischonerfolgreichinstalliert<<endl;
			//// <<rot<<"capizukonf: "<<schwarz<<(int)capizukonf<<endl;
			//// <<rot<<"versuch: "<<schwarz<<versuch<<endl;
			if (capischonerfolgreichinstalliert) {
				if (!capizukonf) {
					clieskonf();
				}
				if (/*//obcapi && */!schonkonfiguriert && (versuch>0 || this->capizukonf || rzf)) {
					this->konfcapi();
					scapis->restart(obverb-1,oblog);
					capizukonf=0;
					schonkonfiguriert=1;
				} //     if (versuch>0) KLA
				// das Folgende verhindert zwar den Programmabbruch bei active (exit), das nuetzt aber nichts. In dem Fall fcpci aktualisieren! 23.5.14
				//    capilaeuft = !systemrueck("systemctl status capisuite | grep ' active (running)' >/dev/null 2>&1",0,obverb,oblog);
				//     capilaeuft  = !systemrueck("systemctl is-active capisuite",0,obverb,oblog);
				capilaeuft=!scapis->obsvfeh(obverb-1,oblog);
				if (capilaeuft) {
					break;
				} else {
					servc::daemon_reload();
					systemrueck("systemctl stop isdn",obverb>0?obverb:-1,oblog,0,/*obsudc=*/1,1);
					////      systemrueck(sudc+"systemctl start isdn",obverb,oblog);
					::Log(Tx[T_StarteCapisuite],-1,oblog);
					scapis->stop(-1,oblog);
					capilaeuft=scapis->startundenable(-1,oblog);
					if (capilaeuft) {
						::Log(Tx[T_Capisuite_gestartet],1,oblog);
						break;
					} else {
						////       ::Log("Capisuite konnte nicht gestartet werden.",1,1);
					} // 					if (capilaeuft)
				} //       if (capilaeuft) else
			} // if (capischonerfolgreichinstalliert) 
		} //  for(unsigned versuch=0;1;versuch++) (3.)
		if (capilaeuft) {
			if (!capiloggekuerzt) {
				kuerzelogdatei("/var/log/capisuite.log",obverb); // screen
				capiloggekuerzt=1;
			} // 			if (!capiloggekuerzt) 
			if (!kez&& !bvz && !anhl && !lista && !listi && !listw && suchstr.empty())
				/*//if (this->obcapi) */pruefmodcron();
		} else {
			::Log(rots+Tx[T_konntecapisuiteservice]+gruen+ltoan(versuch)+rot+Tx[T_malnichtstartenverwN]+schwarz,1,1);
			erg=1;
		} //   if (capilaeuft)
		//// if (obcapi)
	} else {
		if (scapis) scapis->stopdis(obverb,oblog);
		erg=1;
	} // 	if (obcapi) else
schluss: // sonst eine sonst sinnlose for-Schleife mehr oder return mitten aus der Funktion ...
	Log(violetts+Txk[T_Ende]+Tx[T_pruefcapi]+schwarz+" obcapi: "+(obcapi?"1":"0"));
	return erg;
} // pruefcapi()

void hhcl::dovc()
{
	pruefcapi();
	string zeig;
	cmd=edit;
	viadd(&cmd,&zeig,cfaxconfdt);
	viadd(&cmd,&zeig,ccapiconfdt);
	viadd(&cmd,&zeig,rulesdt);
	viadd(&cmd,&zeig,blackdt);
	if (scapis) viadd(&cmd,&zeig,scapis->systemd);
	if (!cdn[0].empty()) viadd(&cmd,&zeig,cdn[0]); // incoming_script
	if (!cdn[3].empty()) viadd(&cmd,&zeig,cdn[3]); // idle_script
	string erg;
	if (!cdn[1].empty()) viadd(&erg,&zeig,cdn[1],1,1,1); // log_file
	if (!cdn[2].empty()) viadd(&erg,&zeig,cdn[2],1,1,1); // log_error
	vischluss(erg,zeig);
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
	opn<<new optcl(/*pname*/"zufaxenvz",/*pptr*/&zufaxenvz,/*art*/pverz,T_zvz_k,T_zufaxenvz_l,/*TxBp*/&Tx,/*Txi*/T_faxt_die_Dateien_aus_pfad_anstatt_aus,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!zufaxenvz.empty());
	opn<<new optcl(/*pname*/"wartevz",/*pptr*/&wvz,/*art*/pverz,T_wvz_k,T_wartevz_l,/*TxBp*/&Tx,/*Txi*/T_Dateien_warten_in_pfad_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!wvz.empty());
	opn<<new optcl(/*pname*/"nichtgefaxtvz",/*pptr*/&ngvz,/*art*/pverz,T_ngvz_k,T_nichtgefaxtvz_l,/*TxBp*/&Tx,/*Txi*/T_Gescheiterte_Faxe_werden_hier_gesammelt_anstatt_in,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!ngvz.empty());
	opn<<new optcl(/*pname*/"empfvz",/*pptr*/&empfvz,/*art*/pverz,T_evz_k,T_empfvz_l,/*TxBp*/&Tx,/*Txi*/T_Empfangsverzeichnis_fuer_Faxempfang,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!empfvz.empty());
	opn<<new optcl(/*pname*/"obfbox",/*pptr*/&obfbox,/*art*/pint,T_fbox_k,T_obfbox_l,/*TxBp*/&Tx,/*Txi*/T_Fritzbox_verwenden,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obfbox!=-1);
	opn<<new optcl(/*pname*/"fbankvz",/*pptr*/&fbankvz,/*art*/pverz,T_fbankvz_k,T_fbankvz_l,/*TxBp*/&Tx,/*Txi*/T_Ankunftsverzeichnis_der_Fritzbox_ueber_CIFS,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!fbankvz.empty());
	opn<<new optcl(/*pname*/"obcapi",/*pptr*/&obcapi,/*art*/pint,T_capi_k,T_obcapi_l,/*TxBp*/&Tx,/*Txi*/T_Capisuite_verwenden ,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obcapi!=-1);
	opn<<new optcl(/*pname*/"obhyla",/*pptr*/&obhyla,/*art*/pint,T_hyla_k,T_obhyla_l,/*TxBp*/&Tx,/*Txi*/T_hylafax_verwenden ,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obhyla!=-1);
	opn<<new optcl(/*pname*/"hylazuerst",/*pptr*/&hylazuerst,/*art*/pint,T_hz_k,T_hylazuerst_l,/*TxBp*/&Tx,/*Txi*/T_versuche_faxe_zuerst_ueber_Hylafax_wegzuschicken,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/hylazuerst!=-1);
	opn<<new optcl(/*pname*/"hylazuerst",/*pptr*/&hylazuerst,/*art*/pint,T_cz_k,T_capizuerst_l,/*TxBp*/&Tx,/*Txi*/T_versuche_faxe_zuerst_ueber_Capisuite_wegzuschicken,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/0,/*woher*/hylazuerst!=-1);
	opn<<new optcl(/*pname*/"hmodem",/*pptr*/&hmodem,/*art*/psons,T_mod_k,T_hmodem_l,/*TxBp*/&Tx,/*Txi*/T_Fuer_Hylafax_verwendetes_Modem,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!hmodem.empty());
	opn<<new optcl(/*pname*/"maxcapiv",/*pptr*/&maxcapiv,/*art*/pdez,T_mc_k,T_maxcapiv_l,/*TxBp*/&Tx,/*Txi*/T_nach_zahl_Versuchen_Capisuite_wird_Hylafax_versucht,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!maxcapiv.empty());
	opn<<new optcl(/*pname*/"maxhylav",/*pptr*/&maxhylav,/*art*/pdez,T_mh_k,T_maxhylav_l,/*TxBp*/&Tx,/*Txi*/T_nach_zahl_Versuchen_Hylafax_wird_Capisuite_verwendet,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,!maxhylav.empty());
	opn<<new optcl(/*pname*/"cuser",/*pptr*/&cuser,/*art*/psons,T_cuser_k,T_cuser_l,/*TxBp*/&Tx,/*Txi*/T_verwendet_fuer_Capisuite_Samba_den_Linux_Benutzer_string_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!cuser.empty());
	opn<<new optcl(/*pname*/"cklingelzahl",/*pptr*/&cklingelzahl,/*art*/pdez,T_ckzl_k,T_cklingelzahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Klingeltoene_bis_Capisuite_den_Anruf_annimmt_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!cklingelzahl.empty());
	opn<<new optcl(/*pname*/"hklingelzahl",/*pptr*/&hklingelzahl,/*art*/pdez,T_hkzl_k,T_hklingelzahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Klingeltoene_bis_Hylafax_den_Anruf_annimmt_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!hklingelzahl.empty());
	opn<<new optcl(/*pname*/"maxdials",/*pptr*/&maxhdials,/*art*/pdez,T_md_k,T_maxdials_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Wahlversuche_in_Hylafax,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!maxhdials.empty());
	opn<<new optcl(/*pname*/"gleichziel",/*pptr*/&gleichziel,/*art*/pint,T_gz_k,T_gleichziel_l,/*TxBp*/&Tx,/*Txi*/T_Faxe_werden_auch_ohne_Faxerfolg_ins_Zielverzeichnis_kopiert,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/gleichziel!=-1);
	opn<<new optcl(/*pname*/"ocri",/*pptr*/&obocri,/*art*/pint,T_ocri_k,T_ocri_l,/*TxBp*/&Tx,/*Txi*/T_Text_aus_empfangenen_Faxen_wird_ermittelt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obocri!=-1);
	opn<<new optcl(/*pname*/"ocra",/*pptr*/&obocra,/*art*/pint,T_ocra_k,T_ocra_l,/*TxBp*/&Tx,/*Txi*/T_Text_aus_gesandten_Bildern_wird_ermittelt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obocra!=-1);
	opn<<new optcl(/*pname*/"anfaxstr",/*pptr*/&anfaxstr,/*art*/psons,T_afs_k,T_anfaxstr_l,/*TxBp*/&Tx,/*Txi*/T_faxnr_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!anfaxstr.empty());
	opn<<new optcl(/*pname*/"ancfaxstr",/*pptr*/&ancfaxstr,/*art*/psons,T_acfs_k,T_ancfaxstr,/*TxBp*/&Tx,/*Txi*/T_faxnr_fuer_primaer_Capisuite_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!ancfaxstr.empty());
	opn<<new optcl(/*pname*/"anhfaxstr",/*pptr*/&anhfaxstr,/*art*/psons,T_ahfs_k,T_anhfaxstr_l,/*TxBp*/&Tx,/*Txi*/T_faxnr_fuer_primaer_hylafax_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!anhfaxstr.empty());
	opn<<new optcl(/*pname*/"anstr",/*pptr*/&anstr,/*art*/psons,T_as_k,T_anstr_l,/*TxBp*/&Tx,/*Txi*/T_Adressatenname_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!anstr.empty());
	opn<<new optcl(/*pname*/"undstr",/*pptr*/&undstr,/*art*/psons,T_us_k,T_undstr_l,/*TxBp*/&Tx,/*Txi*/T_Trennstring_string_fuer_mehrere_Adressaten_Telefonnummern_statt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!undstr.empty());
	opn<<new optcl(/*pname*/"findvers",/*pptr*/&findvers,/*art*/pdez,T_find_k,T_find_l,/*TxBp*/&Tx,/*Txi*/T_Version_1_2_oder_3_Dateisuche_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!findvers.empty());
	opn<<new optcl(/*pname*/"",/*pptr*/&loef,/*art*/puchar,T_loef,T_loeschefax_l,/*TxBp*/&Tx,/*Txi*/T_ein_Fax_nach_Rueckfrage_loeschen,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&loew,/*art*/puchar,T_loew,T_loeschewaise_l,/*TxBp*/&Tx,/*Txi*/T_Eintraege_aus,/*wi*/1,/*Txi2*/T_loeschen_zu_denen_kein_Datei_im_Wartevz_und_kein_Capi_oder_Hylafax_nachweisbar_ist,/*rottxt*/spooltab,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&loea,/*art*/puchar,T_loea_k,T_loescheallew_l,/*TxBp*/&Tx,/*Txi*/T_alle_wartenden_Faxe_und_zugehoerige_Eintraege_aus,/*wi*/1,/*Txi2*/T_loeschen,/*rottxt*/spooltab,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&erneut,/*art*/puchar,T_erneut_k,T_erneutempf_l,/*TxBp*/&Tx,/*Txi*/T_empfangenes_Fax_erneut_bereitstellen,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&uml,/*art*/puchar,T_uml_k,T_umleiten_l,/*TxBp*/&Tx,/*Txi*/T_ausgehendes_Fax_vorzeitig_auf_zweitem_Weg_schicken,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&kez,/*art*/puchar,T_kez_k,T_korrerfolgszeichen_l,/*TxBp*/&Tx,/*Txi*/T_in_der_Datenbanktabelle,/*wi*/0,/*Txi2*/T_wird_das_Erfolgszeichen_korrigiert,/*rottxt*/touta,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&bvz,/*art*/puchar,T_bvz_k,T_bereinigevz_l,/*TxBp*/&Tx,/*Txi*/T_Dateien_aus_Warteverzeichnis_Gescheitertenvz_und_Gefaxtvz_gegen,/*wi*/0,/*Txi2*/T_pruefen_und_aufraeumen,/*rottxt*/touta,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&anhl,/*art*/puchar,T_st_k,T_stop_l,/*TxBp*/&Tx,/*Txi*/T_DPROG_anhalten,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&lista,/*art*/puchar,T_lista_k,T_listausg_l,/*TxBp*/&Tx,/*Txi*/T_listet_Datensaetze_aus,/*wi*/1,/*Txi2*/T_mit_Erfolgskennzeichen_auf,/*rottxt*/touta,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&listf,/*art*/puchar,T_listf_k,T_listfailed_l,/*TxBp*/&Tx,/*Txi*/T_listet_Datensaetze_aus,/*wi*/1,/*Txi2*/T_ohne_Erfolgskennzeichen_auf,/*rottxt*/touta,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&listi,/*art*/puchar,T_listi_k,T_listinca_l,/*TxBp*/&Tx,/*Txi*/T_listet_Datensaetze_aus,/*wi*/1,/*Txi2*/T__auf,/*rottxt*/tinca,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&listw,/*art*/puchar,T_listw_k,T_listwart_l,/*TxBp*/&Tx,/*Txi*/T_listet_wartende_Faxe_auf,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&suchstr,/*art*/psons,T_s_k,T_suche_l,/*TxBp*/&Tx,/*Txi*/T_suche_in_verarbeiteten_Faxen_nach,/*wi*/1,/*Txi2*/T_MAX,/*rottxt*/nix,/*wert*/-1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&dszahl,/*art*/pdez,T_n_k,T_dszahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&obvc,/*art*/puchar,T_vc_k,T_vc_l,/*TxBp*/&Tx,/*Txi*/T_Capisuite_Konfigurationdateien_bearbeiten,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&obvh,/*art*/puchar,T_vh_k,T_vh_l,/*TxBp*/&Tx,/*Txi*/T_Hylafax_Modem_Konfigurationsdatei_bearbeiten,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"sqlz",/*pptr*/&sqlzn,/*art*/plong,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_SQL_Befehle_fuer_die_Absenderermittlung,/*wi*/-1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/sqlzn>0);
	opn<<new optcl(/*pname*/"musterzahl",/*pptr*/&zmzn,/*art*/plong,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Muster_Verzeichnis_Paare_zum_Speichern_ankommender_Faxe,/*wi*/-1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/(zmzn>0));
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
	/*//sqlz=*/sqlvz="0";
	sqlvzn=atol(sqlvz.c_str());
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
// wird aufgerufen in: main
void hhcl::virtautokonfschreib()
{
// int altobverb=obverb;
// obverb=1;
	Log(violetts+Txk[T_autokonfschreib]+schwarz+", "+Txk[T_zu_schreiben]+((rzf||hccd.obzuschreib)?Txk[T_ja]:Txk[T_nein]));
	/*//
		capizukonf und hylazukonf hier immer 0
		char buf[200];
		sprintf(buf,"rzf: %d, capizukonf: %d, hylazukonf: %d, obkschreib: %d",(int)rzf, (int)capizukonf, (int)hylazukonf, (int)obkschreib);
		Log(blaus+buf+schwarz);
	 */
	struct stat kstat={0};
	if (lstat(akonfdt.c_str(),&kstat))
		hccd.obzuschreib=1;
	if (rzf||hccd.obzuschreib) {
		Log(gruens+Tx[T_schreibe_Konfiguration]+schwarz,obverb);
		// restliche Erklaerungen festlegen
		////    agcnfA.setzbem("language",sprachstr);
		hcl::virtautokonfschreib();
// falsch:		cfcnfC.confschreib(cfaxconfdt,ios::out,mpfad,/*faclbak=*/0);
		/*
		cfcnfC.confschreib(akonfdt,ios::out,mpfad);
		*/
#if false
		agcnfA.setzbemv("countrycode",&Tx,T_Eigene_Landesvorwahl_ohne_plus_oder_00);
		agcnfA.setzbemv("citycode",&Tx,T_Eigene_Ortsvorwahl_ohne_0);
		agcnfA.setzbemv("msn",&Tx,T_Eigene_MSN_Faxnummer_ohne_Vorwahl);
		agcnfA.setzbemv("LongDistancePrefix",&Tx,T_Praefix_fuer_ausserorts_zB_0);
		agcnfA.setzbemv("InternationalPrefix",&Tx,T_Praefix_fuer_das_Ausland_zB_00);
		agcnfA.setzbemv("LocalIdentifier",&Tx,T_Hylafax_bis_10_Buchstabe_fuer_eigenen_Namen);
		agcnfA.setzbemv("cFaxUeberschrift",&Tx,T_Capisuite_bis_20_Buchstaben_fuer_eigenen_Namen);
		agcnfA.setzbemv("sqlz",&Tx,T_Zahl_der_angegebenen_sql_Befehle_zur_Suche_nach_Absendern);
		agcnfA.setzbemv("musterzahl",&Tx,T_Zahl_der_Muster_Verzeichnis_Paare_zum_Speichern_ankommender_Faxe);
		for (size_t i=0;i<agcnfA.zahl;i++) {
			if (agcnfA[i].name=="obhyla") agcnfA[i].setze(&obhyla);
			else if (agcnfA[i].name=="obcapi") agcnfA[i].setze(&obcapi);
			else if (agcnfA[i].name=="obfbox") agcnfA[i].setze(&obfbox);
		} //     for (size_t i=0;i<agcnfA.zahl;i++)
		schlArr *ggcnfAp[3]={&agcnfA,&sqlcnfA,&zmcnfA};
		multischlschreib(akonfdt, ggcnfAp, sizeof ggcnfAp/sizeof *ggcnfAp, mpfad);
#endif
	} // if (rzf||obkschreib) 
// obverb=altobverb;
} // void hhcl::virtautokonfschreib()

hhcl::~hhcl() //α
{ //ω
	if (cfaxcp) { 
		delete cfaxcp; 
		cfaxcp=0; 
	}
} //α

void hhcl::virtlieskonfein()
{
	const int altobverb=obverb;
//	obverb=1;
	Log(violetts+Txk[T_virtlieskonfein]+schwarz);
	hcl::virtlieskonfein(); //ω
	//// caus<<"sqlzn: "<<sqlzn<<endl;
	sqlp=new string[sqlzn];
	for(size_t i=0;i<sqlzn;) {
		++i;
		stringstream soptname;
		soptname<<"SQL_"<<i;
		opsql<<new optcl(/*pname*/soptname.str(),/*pptr*/&sqlp[i-1],/*art*/psons,-1,-1,/*TxBp*/&Tx,/*Txi*/T_SQL_Befehl_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/ltoan(i),/*wert*/-1,/*woher*/1);
//		shared_ptr<optcl> sptr{opsql[opsql.size()-1]};
		shared_ptr<optcl> kop2{opsql[opsql.size()-1]};
		opn<<kop2;
	} // 	for(long i=0;i<sqlzn;)
			caus<<violett<<"vor causwert 4"<<schwarz<<endl;
	hccd.causwert(&opsql,obverb,'=',0);
	// wenn in der Konfigurationsdatei keine sql-Befehle stehen, dann die aus den Vorgaben nehmen
	for(size_t i=0;i<sqlzn;i++) {
		//// caus<<"sqlp["<<i+1<<"]: "<<sqlp[i]<<endl;
	} // 	for(long i=0;i<sqlzn;i++)
	if (!sqlzn) {
		sqlzn=sqlvzn;
		opn.omap["sqlz"]->woher=1;
		for(size_t i=0;i<sqlzn;i++) {
	//// caus<<"sqlzn: "<<sqlzn<<", sqlvzn: "<<sqlvzn<<endl;
////			caus<<rot<<"i: "<<violett<<i<<schwarz<<endl;
////			opn.gibomapaus();
		//// caus<<"opn.schl.size(): "<<opn.schl.size()<<", omap.size(): "<<opn.omap.size()<<endl;
      //// opsql<<opvsql[i];
		//// caus<<"opn.schl.size(): "<<opn.schl.size()<<", omap.size(): "<<opn.omap.size()<<endl;
////			caus<<"opvsql.size(): "<<opvsql.size()<<endl;
////			caus<<"opsql.size(): "<<opsql.size()<<endl;
////opsql.schl.push_back(opvsql.schl[i]); 
////			opn.gibomapaus();
////opsql[opsql.size()-1]->weisomapzu(&opsql); 
////			caus<<"opsql.size(): "<<opsql.size()<<endl;
////opn.schl.push_back(opvsql.schl[i]); 
////opn[opn.size()-1]->weisomapzu(&opn); 
////			caus<<"opn.size(): "<<opn.size()<<endl;
			shared_ptr<optcl> kop2{opvsql[i]};
			opsql<<kop2;
			shared_ptr<optcl> kop3{opvsql[i]};
			opn<<kop3;
//			opn.gibomapaus();
//			opn<<opvsql[i];
		}
	} // 	if (!sqlzn)
	if (!zmzn) {
		zmzn=zmvzn;
		opn.omap["musterzahl"]->woher=1;
		for(size_t i=0;i<zmvzn+zmvzn;i++) {
			shared_ptr<optcl> kop2{opvzm[i]};
			opzm<<kop2;
			shared_ptr<optcl> kop3{opvzm[i]};
			opn<<kop3;
		} // 		for(long i=0;i<zmzn;i++) 
		zmp=zmvp;
	} else {
		caus<<blau<<"opzm.size(): "<<violett<<opzm.size()<<schwarz<<endl;
		zmmp=new string[zmzn];
		zmzp=new string[zmzn];
		for(size_t i=0;i<zmzn;) {
			++i;
			stringstream zmmname,zmzname;
			zmmname<<"ZMMuster_"<<i;
			zmzname<<"ZMZiel_"<<i;
			////	  const string *const istrp=new string(ltoan(i));	
			string istr=ltoan(i);
			opzm<<new optcl(/*pname*/zmmname.str(),/*pptr*/&zmmp[i-1],/*art*/psons,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Zielmuster_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/1);
			opn<<opzm.schl[opzm.size()-1];
			opzm<<new optcl(/*pname*/zmzname.str(),/*pptr*/&zmzp[i-1],/*art*/psons,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Ziel_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/1);
			opn<<opzm.schl[opzm.size()-1];
			//// caus<<"opn.schl.size(): "<<opn.schl.size()<<", omap.size(): "<<opn.omap.size()<<endl;
		} // 	for(long i=0;i<zmzn;)
		caus<<blau<<"opzm.size(): "<<violett<<opzm.size()<<schwarz<<endl;
		caus<<blau<<"opn.size(): "<<violett<<opn.size()<<schwarz<<endl;
		caus<<violett<<"vor causwert 5"<<schwarz<<endl;
		hccd.causwert(&opzm,obverb,/*tz*/'=',/*mitclear*/0);
//		opn.gibaus(1);
//		opzm.~schAcl();
		opsql.~schAcl();
		opn.~schAcl();
		for(size_t i=0;i<zmzn;i++) {
			//// caus<<"zmmp["<<i+1<<"]: "<<zmmp[i]<<endl;
			//// caus<<"zmzp["<<i+1<<"]: "<<zmzp[i]<<endl;
		} // 	for(long i=0;i<zmzn;i++)
		zmp=new zielmustercl[zmzn];
		for(size_t i=0;i<zmzn;i++) {
			zmp[i]=zielmustercl(zmmp[i],zmzp[i]);
		}
	} // 	if (!zmzn)
////	optausg(rot);
////	opn.gibomapaus();
	Log(violetts+Txk[T_Ende]+Txk[T_virtlieskonfein]+schwarz);
	obverb=altobverb;
	caus<<"vor Abbruch"<<endl;
	exit(30);
} // void hhcl::virtlieskonfein() //α

int main(int argc,char** argv) //α
{
		if (argc>1) { //ω
		} //α
		hhcl hhi(argc,argv); // hiesige Hauptinstanz, mit lngzuw, setzlog und pruefplatte
		hhi.lauf(); // Einleitungsteil mit virtuellen Funktionen, 
		// mit virtVorgbAllg,pvirtVorgbSpeziell,initopt,parsecl,pvirtmacherkl,zeighilfe,virtlieskonfein,verarbeitkonf,lieszaehlerein,MusterVorgb,dovi,dovs,virtzeigversion
		// virtautokonfschreib,update,
} // int main //ω

void hhcl::virttesterg()
{
}
