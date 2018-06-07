// '//α' oder '//ω' als Kommentar sind nur fuer die Verwendung dieses Programms als Programmvorlage wichtig
// sed -n '/\/\/α/,/\/\/ω/p;/\/\/ω/a\\' test
// sed -n '/\/\/α/,/\/\/ω/p' test
// aktuelle Programmversion
const double& versnr= //α
#include "versdt"
;
#include "kons.h"
#include "DB.h" 
#include <tiffio.h>
#define VOMHAUPTCODE // um Funktionsdefinition manchmal mit "__attribute__((weak)) " versehen zu können //ω
#include "autofax2.h"
#include <fcntl.h> // fuer fd_reopen, O_RDONLY usw.
#include <termios.h> // fuer tcgetattr, termios
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
	// T_Verzeichnis_mit_zu_faxenden_Dateien
	{"Verzeichnis mit zu faxenden Dateien","Directory with files to fax"},
	// T_Verzeichnis_mit_wartenden_Dateien
	{"Verzeichnis mit wartenden Dateien","Directory with waiting files"},
	// T_Verzeichnis_mit_gescheiterten_Dateien
	{"Verzeichnis mit gescheiterten Dateien","Directory with failed files"},
	// T_Verzeichnis_fuer_empfangene_Faxe
	{"Verzeichnis fuer empfangene Faxe","Directory for received faxes"},
	// T_Soll_die_FritzBox_verwendet_werden
	{"Soll die Fritzbox verwendet werden","Shall the fritzbox be used"},
	// T_Mit_CIFS_gemountetes_Verzeichnis_mit_ankommenden_Faxen_der_Fritzbox
	{"Mit CIFS gemountetes Verzeichnis mit ankommenden Faxen der Fritzbox", "Via CIFS mounted directory with received faxes at the fritzbox"},
	// T_Soll_die_Capisuite_verwendet_werden
	{"Soll die Capisuite verwendet werden","Shall Capisuite be used"},
	// 	T_pruefisdn
	{"T_pruefisdn()","checkisdn()"},
	// T_ISDN_Karte_gefunden
	{"ISDN-Karte gefunden: ","ISDN-Card found: "},
	// T_Keine_ISDN_Karte_gefunden
	{"Keine ISDN-Karte gefunden. Setze ","No ISDN-Card found. Setting "},
	// T_mitCapi
	{"mitCapi","withCapi"},
	// T_aauf
	{" auf "," to "},
	// T_Setze
	{". Setze ",". Setting "},
	// T_ob_eine_Fritzcard_drinstak
	{"ob eine Fritzcard drinstak, als die Konfigurationsdatei geschrieben wurde","if a fritzcard was present when the configuration file was written"},
	// T_Faxt_Dateien_aus_Verzeichnis_pfad_die
	{"Faxt Dateien aus Verzeichns <pfad>, die '","Faxes files from directory <path>, which contain '"},
	// T_faxnr_enthalten_und_durch_soffice_in_pdf_konvertierbar_sind_und_traegt_sie
	{" <faxnr>' enthalten und durch soffice in pdf konvertierbar sind \nund traegt sie in MariaDB-Datenbank '",
		" <faxno>' and are convertible into pdf, \nand logs this in the the mariadb database '"}, 
	// T_Tabellen,
	{"' (Tabellen: `","' (tables: `"},
	// T_aein
	{"`) ein.","`)."},
	// T_virtmacherkl_Tx_lgn
	{"pvirtmacherkl, Tx.lgn: ","pvirtmakeexpl, Tx.lgn: "},
	// T_Zustand_der_Dienste
	{"Zustand der Dienste: ","State of the services: "},
	// T_pruefmodem
	{"pruefmodem()","checkmodem()"},
	// T_gibts
	{" gibts"," exists"},
	// T_nicht
	{" nicht"," not"},
	// T_Kein_Modem_gefunden
	{"Kein Modem gefunden.","No modem found."},
	// T_Soll_Hylafax_verwendet_werden
	{"Soll hylafax verwendet werden","Shall hylafax be used"},
	// T_Soll_vorrangig_capisuite_statt_hylafax_gewaehlt_werden
	{"Soll vorrangig die Capisuite statt hylafax gewaehlt werden","Shall capisuite instead of hylafax bei chosen preferentially"},
	// T_Zahl_der_Versuche_in_Capisuite_bis_hylafax_eingeschaltet_wird
	{"Zahl der Versuche in Capisuite, bis hylafax eingeschaltet wird","Number of tries in Capisuite, until hylafax is started"},
	// T_Zahl_der_Versuche_in_hylafax_bis_Capisuite_eingeschaltet_wird
	{"Zahl der Versuche in hylafax, bis Capisuite eingeschaltet wird","Number of tries in hylafax, until Capisuite is started"},
	// T_Zahl_der_Klingeltoene_bis_Hylafax_den_Anruf_annimmt
	{"Zahl der Klingeltoene, bis Hylafax den Anruf annimmt","Number of ring bells, until hylafax accepts call"},
	// T_Sollen_die_Dateien_unabhaengig_vom_Faxerfolg_im_Zielverzeichnis_gespeichert_werden
	{"Sollen die Dateien unabhaengig vom Faxerfolg im Zielverzeichnis gespeichert werden",
		"Shall files be stored in target directory irrespective of fax success"},
	// T_soll_Text_in_empfangenen_Faxen_mit_OCR_gesucht_werden
	{"Soll Text in empfangenen Faxen (mit \"OCR\") gesucht werden?",
		"Shall text from received faxes be searched (with \"ocr\")?"},
	// T_soll_Text_in_gesandten_Bildern_mit_OCR_gesucht_werden
	{"Soll Text in gesandten Bildern (mit \"OCR\") gesucht werden?",
		"Shall text from sent pictures be searched (with \"ocr\")?"},
	// T_Buchstabenfolge_vor_erster_Faxnummer
	{"Buchstabenfolge vor erster Fax-Nummer","Letter-sequence before the first fax number"},
	// T_Buchstabenfolge_vor_erster_Fax_Nummer_primaer_fuer_Capisuite
	{"Buchstabenfolge vor erster Fax-Nummer primaer fuer Capisuite","Letter-sequence before the first fax number primarily for Capisuite"},
	// T_Buchstabenfolge_vor_erster_Fax_Nummer_primaer_fuer_Hylafax
	{"Buchstabenfolge vor erster Fax-Nummer fuer Hylafax","Letter-sequence before the first fax number primarily for hylafax"},
	// T_Buchstabenfolge_vor_erstem_Adressaten
	{"Buchstabenfolge vor erstem Adressaten","Letter-sequence before the first addressee"},
	// T_Buchstabenfolge_vor_weiterem_Adressaten_sowie_weiterer_Faxnummer,
	{"Buchstabenfolge vor weiterem Adressaten sowie weiterer Faxnummer","Letter-sequence before further addressee or fax number"},
	// T_faxnr_wird_ersetzt_mit_der_Faxnr
	{" (bitte ggf. SQL-Befehl mit 2 Ergebnisfeldern, '&&faxnr&&' wird ersetzt mit der Faxnr)",
		" (if wanted type sql-command with 2 result fields, '&&faxnr&&' will be replaces with the fax-no.)"},
	// T_Strich_ist_SQL_Befehl_loeschen_faxnr_wird_ersetzt_mit_der_Faxnr
	{" ('-'=SQL-Befehl loeschen, 2 Ergebnisfelder, '&&faxnr&&' wird ersetzt mit der Faxnr, s.man -Lde " DPROG ")",
		" ('-'=delete this sql command, 2 result fields, '&&faxnr&&' will be replaces with the fax-no., see man " DPROG ")"},
	// T_In
	{"In '","In '"},
	// T_keine_Datenbank_gefunden_Wollen_Sie_den_SQL_Befehl_neu_eingeben
	{"' keine Datenbank gefunden. Wollen Sie den SQL-Befehl neu eingeben?",
		"' no database found. Do You want to reenter the sql command?"},
	// T_Datenbank
	{"Datenbank '","Database '"},
	// T_nicht_ermittelbar_Wollen_Sie_den_SQL_Befehl_neu_eingeben
	{"' nicht ermittelbar. Wollen Sie den SQL-Befehl neu eingeben?","' not found. Do You want to reenter the sql command?"},
	// T_keinmal_faxnr_gefunden_Wollen_Sie_den_SQL_Befehl_neu_eingeben
	{"' keinmal '&&faxnr&&' gefunden. Wollen Sie den SQL-Befehl neu eingeben?",
		"' no occurance of '&&faxnr&&' found. Do You want to reenter the sql command?"},
	// T_koennte_ein_SQL_Fehler_sein_Wollen_Sie_den_SQL_Befehl_neu_eingeben
	{"' koennte ein SQL-Fehler sein. Wollen Sie den SQL-Befehl neu eingeben?",
		"' could be an sql error. Do You want to reenter the sql command?"},
	// T_Wolle_Sie_noch_einen_SQL_Befehl_eingeben,
	{"Wollen Sie noch einen SQL-Befehl eingeben?","Do You want to enter another sql command?"},
	// T_zum_Streichen_Strich_eingeben
	{" (zum Streichen '-' eingeben)"," (to delete enter '-')"},
// T_beim_letzten_fuer_alle_Uebrigen_nichts_eingeben
	{" (beim letzten fuer alle Uebrigen nichts eingeben)"," (for the last for all the rest enter nothing)"},
	// T_Zielverzeichnis_Nr
	{"Zielverzeichnis Nr. ","Target directory no. "},
	// T_setzhylavz
	{"setzhylavz()","sethyladir()"},
	// T_aus_systemd_fax_service_Datei_ermittelt
	{" aus systemd-fax-service-Datei ermittelt"," determined from systemd fax service file"},
	// T_aus_etc_init_d_hylafax_ermittelt,
	{" aus /etc/init.d/hylafax ermittelt"," determined from /etc/init.d/hylafax"},
	// T_aus_seiner_ausschliesslichen_Existenz_ermittelt
	{" aus seiner ausschliesslichen Existenz ermittelt"," determined from its exclusive existence"},
	// T_aus_seinem_geringen_Alter_ermittelt
	{" aus seinem geringeren Alter ermittelt"," determined from its lower age"},
	// T_aus_mangelnder_Alternative_ermittelt
	{" aus mangelnder Alternative ermittelt"," determined from missing alternative"},
	// T_aus_Existenz_von,
	{" aus Existenz von "," determined from the existence of "},
	// T_ermittelt
	{" ermittelt.","."},
	// T_hylafax_Verzeichnis
	{"hylafax-Verzeichnis: ","hylafax-directory: "},
	// T_pruefhyla
	{"pruefhyla()","checkhyla()"},
	// T_Konfiguration_von_hylafax_durch
	{"# Konfiguration von hylafax durch ","# Configuration of hylafax by "},
	// T_muss_mindestens_2_sein_zur_Uebergabe_der_Nr_des_Anrufenden
	{" #muss mindestens 2 sein zur Uebergabe der Nummer des Anrufenden"," #must be at least 2 to transfer the no of the caller"},
	// T_vom
	{" vom "," at "},
	// T_nichtbeschreibbar
	{" nicht beschreibbar!","not to open for writing!"},
	// T_Baudratevon
	{"Baudrate von '","Baud rate of '"},
	// T_mit_af
	{"' mit ","' with "},
	// T_zugeringVerwendeHylafaxnicht
	{" zu gering. Verwende Hylafax nicht."," too small. Not utilizing hylafax."},
	// T_mit_Baudrate,
	{"' mit Baudrate ","' with baud rate "},
	// T_wird_verwendet
	{" wird verwendet."," being used."},
	// T_Pruefe_ob_Hylafax_gestartet
	{"Pruefe, ob Hylafax gestartet ...","Checking if hylafax is running ..."},
	// T_Hylafax_ohne_plus_entdeckt_muss_ich_loeschen
	{"Hylafax ohne + entdeckt, muss ich loeschen ...","hylafax without plus found, must delete it ..."},
	// T_Hylafaxplus_entdeckt_muss_ich_loeschen
	{"Hylafax+ entdeckt, muss ich loeschen ...","Hylafax+ found, having to delete it ..."},
	// T_Hylafax_laeuft
	{"Hylafax laeuft!","Hylafax is running!"},
	// T_Fehler_in_pruefhyla
	{"Fehler in pruefhyla()!","Error in checkhyla()!"},
	// T_Muss_Hylafax_installieren
	{"Muss Hylafax installieren ...","Have to install hylafax ..."},
	// T_ueber_den_Quellcode
	{"... ueber den Quellcode","... with the source code"},
	// T_Ergebnis_nach
	{"Ergebnis nach sed","result after sed"},
	// T_ueber_das_Installationspaket
	{"... ueber das Installationspaket","... with the installation package"},
	// T_hylafehlt
	{"hylafehlt: ","hylamissing: "},
	// T_Muss_falsches_hylafax_loeschen
	{"Muss falsches hylafax loeschen!!!","Have to delete the wrong hylafax!!!"},
	// T_Fuehre_aus_Dp
	{"Fuehre aus: ","Executing: "},
	// T_falls_es_hier_haengt_bitte_erneut_aufrufen
	{" (falls es hier haengt, insbes. laenger als 3 Wochen, dann bitte erneut aufrufen)",
		" (if it hangs, especially more than 3 weeks, please invoke again)"},
	// T_hylafaxspringtnichtan
	{"hylafax.service springt nicht an. Verwende Hylafax nicht.","hylafax.service does not start up. Not utilizing hylafax."},
	{"",""} //α
}; // char const *DPROG_T[T_MAX+1][SprachZahl]=

class TxB Tx((const char* const* const* const*)DPROG_T);
const char *logdt="/var/log/" DPROG "vorgabe.log";//darauf wird in kons.h verwiesen;

using namespace std; //ω


const string cSQL_{"SQL_"}, cZMMuster_{"ZMMuster_"}, cZMZiel_{"ZMZiel_"};

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
	if (ausgp&&obverb) *ausgp<<meld<<endl; else fLog(meld,obverb,oblog);
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
		fLog(Tx[T_Kopiere_Doppelpunkt]+rots+qdatei+schwarz+"'\n         -> '"+rot+ziel+schwarz+"'",obverb,oblog);
		if ((efeh=kopier(qdatei,ziel,obverb,oblog))) {
			fehler+=efeh;
			fLog(rots+Tx[T_Fehler_beim_Kopieren]+Tx[T_Dateiname]+blau+zield+schwarz,1,1);
		} // if (efeh=kopier(qdatei,ziel,obverb,oblog))
	} else {
		fLog(rots+Tx[T_Fehler_beim_Kopieren]+Tx[T_Dateiname]+blau+zield+schwarz+Tx[T_schlechtgeformt],1,1);
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
	if (ausgp&&obverb) *ausgp<<meld<<endl; else fLog(meld,obverb,oblog);
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
				if (ausgp&&obverb) *ausgp<<meld<<endl; else fLog(meld,obverb,oblog);
			}
		} // if (wieweiterzaehl<2) 
	} // 	if (obgleichp&&*obgleichp)
	if (zieldatei) *zieldatei=dateiname;
	return ziel;
} // zielname 

// wird aufgerufen in: verschiebe (Version 2), kopiere (Version 2), neuerdateiname, 
string zielname(const string& qdatei, const zielmustercl& zmup, uchar wieweiterzaehl/*=0*/, string* zieldatei/*=0*/, uchar *obgleichp/*=0*/, 
		int obverb/*=0*/, int oblog/*=0*/, stringstream *ausgp/*=0*/)
{
	//  Log(violetts+Tx[T_zielname]+schwarz,obverb,oblog);
	for(const zielmustercl *zmakt=&zmup;1;zmakt++){
		int reti=regexec(&(zmakt->regex),qdatei.c_str(),0,NULL,0);
		const string meld=Txk[T_datei]+rots+qdatei+schwarz+Tx[T_entspricht]+(reti?Tx[T_entsprichtnicht]:Tx[T_entsprichtdoch])+
			Tx[T_Muster_Doppelpunkt]+rot+zmakt->holmuster()+schwarz+"'";
		if (ausgp&&obverb) *ausgp<<meld<<endl; else fLog(meld,obverb,oblog);
		if (!reti){
			return zielname(qdatei,zmakt->holziel(),wieweiterzaehl,zieldatei,obgleichp,obverb,oblog,ausgp);
		} //     if (!reti)
		if (zmakt->obmusterleer()) break;
	} //   for(zielmustercl *zmakt=zmup;1;zmakt++)
	return {};
} // zielname

// von fkn-systems
const char * const rulesdt="/etc/udev/rules.d/46-FKN_isdn_capi.rules";
// wird aufgerufen in: hhcl::pruefcapi
void pruefrules(int obverb, int oblog) 
{
	fLog(violetts+Tx[T_pruefrules]+schwarz,obverb?obverb-1:0,oblog);
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
	fLog(violetts+Tx[T_pruefblack]+schwarz,obverb?obverb-1:0,oblog);
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
						fLog(Tx[T_haengean]+blaus+blackdt+schwarz+Tx[T_an_mdpp]+gruen+vgl[i]+schwarz,obverb,oblog);
						blacka<<vgl[i]<<endl;
					}
				} // for(unsigned i=0;i<sizeof vgl/sizeof *vgl;i++) 
			} // if (blacka.is_open()) 
		} // obeinsfehlt
	} else {
	} // if (blacki.is_open())  else
} // void pruefblack(int obverb, int oblog) 

constexpr const char *hhcl::moeglhvz[2];
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
		fLog(Tx[T_Der_regulaere_Ausdruck]+drots+muster+schwarz+Tx[T_konnte_nicht_kompiliert_werden_Fehler]+error_message,1,0);
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

const string& zielmustercl::holmuster() const
{
	return muster;
} // const string& zielmustercl::holmuster()

const string& zielmustercl::holziel() const
{
	return ziel;
} // const string& zielmustercl::holziel()


hhcl::hhcl(const int argc, const char *const *const argv):dhcl(argc,argv,DPROG,/*mitcron*/1) //α
{
 // mitcron=0; //ω
} // hhcl::hhcl //α
// Hier neue Funktionen speichern: //ω

// in virtVorgbAllg, pruefcapi
void hhcl::liescapiconf()
{
	hLog(violetts+Tx[T_liescapiconf]+schwarz);
	svec qrueck;
	const string wo="/etc/capisuite /usr/local/etc/capisuite";
	const string moegl="find "+wo+" -type f -name ";
	if (findv==1) {
		systemrueck(moegl+"fax.conf",obverb-2,oblog,&qrueck,/*obsudc=*/0);
	} else findfile(&qrueck,findv,obverb,oblog,0,wo,/*muster=*/"/fax\\.conf$");
	if (qrueck.size()) cfaxconfdt=qrueck[0];
	if (!cfaxconfdt.empty()) {
		if (!cfcnfCp) {
			cfcnfCp=new schAcl<WPcl>("cfcnfC", new vector<aScl>{
					{"spool_dir",&spoolcapivz},
					{"fax_user_dir",&cfaxuservz},
					{"send_tries",&maxcdials},
					{"send_delays",&send_delays},
					{"outgoing_MSN",&outgoing_MSN},
					{"dial_prefix",&dial_prefix},
					{"fax_stationID",&fax_stationID},
					{"fax_headline",&fax_headline},
					{"fax_email_from",&fax_email_from},
					{"outgoing_timeout",&outgoing_timeout}
					});
		}
		pruefverz(dir_name(cfaxconfdt),obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0);
		if (cfaxcp) delete cfaxcp;
		cfaxcp = new confdcl(cfaxconfdt,obverb);
		cfaxcp->kauswert(cfcnfCp);
		//		cfaxcp->Abschn_auswert(obverb);
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
			char buf[250]{0};
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
			if (!cccnfCp) {
				cccnfCp=new schAcl<WPcl>("cccnfC", new vector<aScl>{
						{"incoming_script",&cdn[0]},
						{"log_file",&cdn[1]},
						{"log_error",&cdn[2]},
						{"idle_script",&cdn[3]}
						});
			}
			pruefverz(dir_name(ccapiconfdt),obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0);
			confdcl ccapc(ccapiconfdt,obverb);
			////<<"azaehlerdt: "<<blau<<azaehlerdt<<schwarz<<endl;
			ccapc.kauswert(cccnfCp);
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
	hLog(violetts+Tx[T_konfcapi]+schwarz+", ccapiconfdt: "+violett+ccapiconfdt+schwarz);
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
		::fLog(Tx[T_Capisuite_ist_offenbar_noch_nicht_richtig_konfiguriert]+blaus+"'fax_stationID'"+schwarz+Tx[T_ist_Apostroph]+blau+
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
			for(unsigned snr=0;snr<cfcnfCp->size();snr++) {
				hLog("snr: "+blaus+ltoan(snr)+schwarz+" "+(*cfcnfCp)[snr]->pname+", "+(*cfcnfCp)[snr]->virtholstr());
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
							for(unsigned snr=0;snr<cfcnfCp->size();snr++) {
								if (lzeile.find((*cfcnfCp)[snr]->pname)!=string::npos) {
									//// _out<<"snr: "<<snr<<", lzeile: "<<tuerkis<<lzeile<<schwarz<<", rzeile: "<<blau<<rzeile<<schwarz<<endl;
									string altwert=rzeile;
									gtrim(&altwert);
									anfzweg(altwert); // Anfuehrungszeichen entfernen
									if (snr==0 || snr==1) (*cfcnfCp)[snr]->setzstr(altwert); // spool_dir und fax_user_dir hier nicht konfigurierbar
									fLog(string("cfcnfC[")+ltoan(snr)+"].name: "+tuerkis+(*cfcnfCp)[snr]->pname+schwarz+Tx[T_komma_wert]+
											((*cfcnfCp)[snr]->virtholstr()==altwert?blau:rot)+(*cfcnfCp)[snr]->virtholstr()+schwarz+Tx[T_komma_Altwert]+
											blau+altwert+schwarz,obverb+iru,oblog+iru);
									if ((*cfcnfCp)[snr]->virtholstr()!=altwert) {
										if (!iru) {
											neuschreiben=1;
											paramdiff=1;
										} else {
											string zschr=(*cfcnfCp)[snr]->pname+" = \""+(*cfcnfCp)[snr]->virtholstr()+"\"";
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
	hLog(violetts+Txk[T_Ende]+Tx[T_konfcapi]+schwarz+"ccapiconfdt: "+violett+ccapiconfdt+schwarz);
} // void hhcl::konfcapi

// wird aufgerufen in: konfcapi, verzeichnisse
void hhcl::pruefcvz()
{
	//// <<rot<<"cfaxuservz in pruefcvz: "<<cfaxuservz<<schwarz<<endl;
	hLog(violetts+Tx[T_pruefcvz]+schwarz+" ccfaxuservz: "+violett+cfaxuservz+schwarz);
	kuerzevtz(&cfaxuservz);
	pruefverz(cfaxuservz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0,/*besitzer=*/"",/*benutzer=*/cuser,/*obmachen=*/0);
	cfaxusersqvz=cfaxuservz+vtz+cuser+"/sendq"; //  "/var/spool/capisuite/users/<user>/sendq";
	pruefverz(cfaxusersqvz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0,/*besitzer=*/"",/*benutzer=*/cuser,/*obmachen=*/0);
	cfaxuserrcvz=cfaxuservz+vtz+cuser+"/received";
	cfaxuserrcfalschevz=cfaxuserrcvz+"/falsche";
	//// <<violett<<"cfaxuserrcvz: "<<cfaxuserrcvz<<schwarz<<endl;
	pruefverz(cfaxuserrcvz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0,/*besitzer=*/"",/*benutzer=*/cuser,/*obmachen=*/0);
} // hhcl::pruefcvz

// in empfcapi und pruefcapi, virtrueckfragen
void hhcl::pruefsfftobmp()
{
	hLog(violetts+Tx[T_pruefsfftobmp]+schwarz);
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
	hLog(violetts+Txk[T_Ende]+Tx[T_pruefsfftobmp]+schwarz);
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
	hLog(violetts+"cservice()"+schwarz);
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
		if (obverb) hLog("csfehler: "+gruens+ltoan(csfehler)+schwarz);
		////    return csfehler;
	} // if (obprogda("capisuite",obverb,oblog,&cspfad)) 
	return erg;
} // int hhcl::cservice()

// in pruefcapi
void hhcl::clieskonf()
{
	hLog(violetts+Tx[T_clieskonf]+schwarz+", cfaxcp->name: "+violett+(cfaxcp?cfaxcp->fname:"0")+schwarz);
	if (fax_stationID!="+"+countrycode+" "+citycode+" "+msn  
			|| outgoing_MSN!=msn  
			|| fax_headline!=cFaxUeberschrift  
		 ) {
		capizukonf=1;
	}
	int richtige=0;
	if (cfaxcp) {
//		cfaxcp->Abschn_auswert(obverb);
		for(size_t i=0;i<cfaxcp->abschv.size();i++) {
			if (cfaxcp->abschv[i].aname==cuser) {
				richtige=0;
				//// <<"abschv["<<i<<"].av.size() "<<cfaxcp->abschv[i].av.size()<<endl;
				for(size_t j=0;j<cfaxcp->abschv[i].av.size();j++) {
					if (cfaxcp->abschv[i].av[j].name=="fax_numbers") {if (*cfaxcp->abschv[i].av[j].wertp==outgoing_MSN) richtige++;}
					else if (cfaxcp->abschv[i].av[j].name=="fax_stationID") {if (*cfaxcp->abschv[i].av[j].wertp==fax_stationID) richtige++;}
					else if (cfaxcp->abschv[i].av[j].name=="fax_headline") {if (*cfaxcp->abschv[i].av[j].wertp==fax_headline) richtige++;}
					else if (cfaxcp->abschv[i].av[j].name=="fax_email_from") {if (*cfaxcp->abschv[i].av[j].wertp==fax_email_from) richtige++;}
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
	hLog(violetts+Tx[T_pruefmodcron]+schwarz);
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
	hLog(violetts+Tx[T_pruefcapi]+schwarz+" obcapi: "+(obcapi?"1":"0"));
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
			hLog(violetts+Tx[T_capilaeuft]+schwarz+ltoan(capilaeuft)+schwarz);
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
					::fLog(blaus+Tx[T_Module_geladen]+schwarz+" fcpci: "+blau+(fcpcida?"1":"0")+schwarz+", capi: "+blau+(capida?"1":"0")+schwarz+
							", capidrv: "+blau+(capidrvda?"1":"0")+schwarz+Tx[T_Lade_Capi_Module],obverb,0);
					systemrueck("modprobe -rf avmfritz mISDNipac hisax_fcpcipnp hisax_isac hisax",obverb,oblog,/*rueck=*/0,/*obsudc=*/1,1);
					utsname unbuf;
					if (!fcpcida) {
						uname(&unbuf);
						hLog(Tx[T_Kernelversion]+blaus+unbuf.release+schwarz);
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
										fLog(rots+Tx[T_KannFcpciNInstVerwCapiNicht]+blau+linstp->ersetzeprog("kernel-source")+rots+
												Tx[T_eine_neuere_Version_als_die_des_aktuellen_Kernels_installiert_worden_sein_dann_bitte_erneutes_Systemupdate]+schwarz,1,1);
										erg=1;
										goto schluss;
								} // 								switch (ivers)
								struct stat entryfc{0};
								if (lstat(fcpciko.c_str(), &entryfc)) {
									fLog(Txk[T_datei]+blaus+fcpciko+schwarz+Tx[T_nichtgefFcpciMfdKinstallierwerden],obverb,1);
									const int altobverb=obverb;
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
									exit(99);
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
								::fLog(blaus+Tx[T_Zur_Inbetriebnahme_der_Capisuite_muss_das_Modul_capi_geladen_werten]+schwarz+v1+blau+" -> "
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
								::fLog(Tx[T_Moment_muss_Kernel_herunterladen],-1,oblog);
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
									::fLog(Tx[T_Der_Kernel_hat_sich_offenbar_seit_dem_Einloggen_von]+blaus+relev+schwarz+Tx[T_nach_]+blau+kernel+schwarz+
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
					fLog(Tx[T_Konnte]+blaus+"capisuite"+schwarz+Tx[T_nichtstarten],1,oblog);
					linstp->doinst("ghostscript",obverb+1,oblog,"gs");
					//// if (systemrueck("which zypper",-1,-1)) KLA
					////        if (linstp->checkinst(-1,-1)!=zyp) KLA
					/*//
						if (linstp->ipr!=zypper) {
						::fLog(rots+Tx[T_Kann_Capisuite_nicht_installieren_verwende_Capi_nicht],1,1);
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
					::fLog(Tx[T_StarteCapisuite],-1,oblog);
					scapis->stop(-1,oblog);
					capilaeuft=scapis->startundenable(-1,oblog);
					if (capilaeuft) {
						fLog(Tx[T_Capisuite_gestartet],1,oblog);
						break;
					} else {
						////       ::fLog("Capisuite konnte nicht gestartet werden.",1,1);
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
			::fLog(rots+Tx[T_konntecapisuiteservice]+gruen+ltoan(versuch)+rot+Tx[T_malnichtstartenverwN]+schwarz,1,1);
			erg=1;
		} //   if (capilaeuft)
		//// if (obcapi)
	} else {
		if (scapis) scapis->stopdis(obverb,oblog);
		erg=1;
	} // 	if (obcapi) else
schluss: // sonst eine sonst sinnlose for-Schleife mehr oder return mitten aus der Funktion ...
	hLog(violetts+Txk[T_Ende]+Tx[T_pruefcapi]+schwarz+" obcapi: "+(obcapi?"1":"0"));
	return erg;
} // pruefcapi()

// wird aufgerufen in: virtrueckfragen, main
void hhcl::pruefisdn()
{
	hLog(violetts+Tx[T_pruefisdn]+schwarz);
	svec rueck;
////	cmd="{ lspci 2>/dev/null || "+sudc+"lspci 2>/dev/null;}|grep -i 'isdn'"; systemrueck(cmd, obverb,oblog,&rueck);
	for(int iru=0;iru<2;iru++) {
		if (systemrueck("lspci 2>/dev/null|grep -i 'isdn'",obverb,oblog,&rueck,/*obsudc=*/iru)) break;
	}
	if (rueck.size()) {
		hLog(blaus+Tx[T_ISDN_Karte_gefunden]+schwarz+rueck[0]+blau+Tx[T_Setze]+Tx[T_mitCapi]+schwarz+Tx[T_aauf]+blau+"1.");
	// wenn zum Konfigurationszeitpunkt keine Fritzcard drinstak, aber jetzt, dann rueckfragen
		if (!obfcard) {
			fLog(Txk[T_rueckzufragen_wegen]+rots+"!obfcard"+schwarz,1,0);
			rzf=1;
			obfcard=1;
		} // 		if (!obfcard)
	} else {
		hLog(rots+Tx[T_Keine_ISDN_Karte_gefunden]+schwarz+Tx[T_mitCapi]+rot+Tx[T_aauf]+schwarz+"0.");
		obcapi=obfcard=0;
	} // 	if (rueck.size())
	if (obverb) hLog("obfcard: "+blaus+ltoan(obfcard)+schwarz);
	obfcgeprueft=1;
} // void hhcl::pruefisdn()


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
	hLog(violetts+Tx[T_virtVorgbAllg]+schwarz); //ω
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
	hLog(violetts+Tx[T_pvirtVorgbSpeziell]+schwarz);
	virtMusterVorgb(); //ω
	dhcl::pvirtVorgbSpeziell(); //α
} // void hhcl::pvirtVorgbSpeziell

// wird aufgerufen in lauf
void hhcl::virtinitopt()
{ //ω
	opn<<new optcl(/*pname*/"zufaxenvz",/*pptr*/&zufaxenvz,/*art*/pverz,T_zvz_k,T_zufaxenvz_l,/*TxBp*/&Tx,/*Txi*/T_faxt_die_Dateien_aus_pfad_anstatt_aus,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!zufaxenvz.empty());
	opn<<new optcl(/*pname*/"wartevz",/*pptr*/&wvz,/*art*/pverz,T_wvz_k,T_wartevz_l,/*TxBp*/&Tx,/*Txi*/T_Dateien_warten_in_pfad_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!wvz.empty());
	opn<<new optcl(/*pname*/"nichtgefaxtvz",/*pptr*/&ngvz,/*art*/pverz,T_ngvz_k,T_nichtgefaxtvz_l,/*TxBp*/&Tx,/*Txi*/T_Gescheiterte_Faxe_werden_hier_gesammelt_anstatt_in,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!ngvz.empty());
	opn<<new optcl(/*pname*/"empfvz",/*pptr*/&empfvz,/*art*/pverz,T_evz_k,T_empfvz_l,/*TxBp*/&Tx,/*Txi*/T_Empfangsverzeichnis_fuer_Faxempfang,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!empfvz.empty());
	opn<<new optcl(/*pname*/"obfbox",/*pptr*/&obfbox,/*art*/pint,T_fbox_k,T_obfbox_l,/*TxBp*/&Tx,/*Txi*/T_Fritzbox_verwenden,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obfbox!=-1,/*obno*/1);
	opn<<new optcl(/*pname*/"fbankvz",/*pptr*/&fbankvz,/*art*/pverz,T_fbankvz_k,T_fbankvz_l,/*TxBp*/&Tx,/*Txi*/T_Ankunftsverzeichnis_der_Fritzbox_ueber_CIFS,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!fbankvz.empty());
	opn<<new optcl(/*pname*/"obcapi",/*pptr*/&obcapi,/*art*/pint,T_capi_k,T_obcapi_l,/*TxBp*/&Tx,/*Txi*/T_Capisuite_verwenden ,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obcapi!=-1,/*obno*/1);
	opn<<new optcl(/*pname*/"obhyla",/*pptr*/&obhyla,/*art*/pint,T_hyla_k,T_obhyla_l,/*TxBp*/&Tx,/*Txi*/T_hylafax_verwenden ,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obhyla!=-1,/*obno*/1);
	opn<<new optcl(/*pname*/"hylazuerst",/*pptr*/&hylazuerst,/*art*/pint,T_hz_k,T_hylazuerst_l,/*TxBp*/&Tx,/*Txi*/T_versuche_faxe_zuerst_ueber_Hylafax_wegzuschicken,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/hylazuerst!=-1);
	opn<<new optcl(/*pname*/"hylazuerst",/*pptr*/&hylazuerst,/*art*/pint,T_cz_k,T_capizuerst_l,/*TxBp*/&Tx,/*Txi*/T_versuche_faxe_zuerst_ueber_Capisuite_wegzuschicken,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/0,/*woher*/hylazuerst!=-1);
	opn<<new optcl(/*pname*/"hmodem",/*pptr*/&hmodem,/*art*/pstri,T_mod_k,T_hmodem_l,/*TxBp*/&Tx,/*Txi*/T_Fuer_Hylafax_verwendetes_Modem,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!hmodem.empty());
	opn<<new optcl(/*pname*/"maxcapiv",/*pptr*/&maxcapiv,/*art*/pdez,T_mc_k,T_maxcapiv_l,/*TxBp*/&Tx,/*Txi*/T_nach_zahl_Versuchen_Capisuite_wird_Hylafax_versucht,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!maxcapiv.empty());
	opn<<new optcl(/*pname*/"maxhylav",/*pptr*/&maxhylav,/*art*/pdez,T_mh_k,T_maxhylav_l,/*TxBp*/&Tx,/*Txi*/T_nach_zahl_Versuchen_Hylafax_wird_Capisuite_verwendet,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,!maxhylav.empty());
	opn<<new optcl(/*pname*/"cuser",/*pptr*/&cuser,/*art*/pstri,T_cuser_k,T_cuser_l,/*TxBp*/&Tx,/*Txi*/T_verwendet_fuer_Capisuite_Samba_den_Linux_Benutzer_string_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!cuser.empty());
	opn<<new optcl(/*pname*/"cklingelzahl",/*pptr*/&cklingelzahl,/*art*/pdez,T_ckzl_k,T_cklingelzahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Klingeltoene_bis_Capisuite_den_Anruf_annimmt_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!cklingelzahl.empty());
	opn<<new optcl(/*pname*/"hklingelzahl",/*pptr*/&hklingelzahl,/*art*/pdez,T_hkzl_k,T_hklingelzahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Klingeltoene_bis_Hylafax_den_Anruf_annimmt_anstatt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!hklingelzahl.empty());
	opn<<new optcl(/*pname*/"maxdials",/*pptr*/&maxhdials,/*art*/pdez,T_md_k,T_maxdials_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Wahlversuche_in_Hylafax,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!maxhdials.empty());
	opn<<new optcl(/*pname*/"gleichziel",/*pptr*/&gleichziel,/*art*/pint,T_gz_k,T_gleichziel_l,/*TxBp*/&Tx,/*Txi*/T_Faxe_werden_auch_ohne_Faxerfolg_ins_Zielverzeichnis_kopiert,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/gleichziel!=-1);
	opn<<new optcl(/*pname*/"ocri",/*pptr*/&obocri,/*art*/pint,T_ocri_k,T_ocri_l,/*TxBp*/&Tx,/*Txi*/T_Text_aus_empfangenen_Faxen_wird_ermittelt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obocri!=-1);
	opn<<new optcl(/*pname*/"ocra",/*pptr*/&obocra,/*art*/pint,T_ocra_k,T_ocra_l,/*TxBp*/&Tx,/*Txi*/T_Text_aus_gesandten_Bildern_wird_ermittelt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/obocra!=-1);
	opn<<new optcl(/*pname*/"anfaxstr",/*pptr*/&anfaxstr,/*art*/pstri,T_afs_k,T_anfaxstr_l,/*TxBp*/&Tx,/*Txi*/T_faxnr_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!anfaxstr.empty());
	opn<<new optcl(/*pname*/"ancfaxstr",/*pptr*/&ancfaxstr,/*art*/pstri,T_acfs_k,T_ancfaxstr,/*TxBp*/&Tx,/*Txi*/T_faxnr_fuer_primaer_Capisuite_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!ancfaxstr.empty());
	opn<<new optcl(/*pname*/"anhfaxstr",/*pptr*/&anhfaxstr,/*art*/pstri,T_ahfs_k,T_anhfaxstr_l,/*TxBp*/&Tx,/*Txi*/T_faxnr_fuer_primaer_hylafax_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!anhfaxstr.empty());
	opn<<new optcl(/*pname*/"anstr",/*pptr*/&anstr,/*art*/pstri,T_as_k,T_anstr_l,/*TxBp*/&Tx,/*Txi*/T_Adressatenname_wird_hinter_string_erwartet_statt_hinter,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!anstr.empty());
	opn<<new optcl(/*pname*/"undstr",/*pptr*/&undstr,/*art*/pstri,T_us_k,T_undstr_l,/*TxBp*/&Tx,/*Txi*/T_Trennstring_string_fuer_mehrere_Adressaten_Telefonnummern_statt,/*wi*/0,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/!undstr.empty());
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
	opn<<new optcl(/*pname*/"",/*pptr*/&suchstr,/*art*/pstri,T_s_k,T_suche_l,/*TxBp*/&Tx,/*Txi*/T_suche_in_verarbeiteten_Faxen_nach,/*wi*/1,/*Txi2*/T_MAX,/*rottxt*/nix,/*wert*/-1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&dszahl,/*art*/pdez,T_n_k,T_dszahl_l,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_aufzulistenden_Datensaetze_ist_zahl_statt,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&obvc,/*art*/puchar,T_vc_k,T_vc_l,/*TxBp*/&Tx,/*Txi*/T_Capisuite_Konfigurationdateien_bearbeiten,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1);
	opn<<new optcl(/*pname*/"",/*pptr*/&obvh,/*art*/puchar,T_vh_k,T_vh_l,/*TxBp*/&Tx,/*Txi*/T_Hylafax_Modem_Konfigurationsdatei_bearbeiten,/*wi*/1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/1,/*woher*/1);
//	opn<<new optcl(/*pname*/"sqlz",/*pptr*/&sqlzn,/*art*/plong,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_SQL_Befehle_fuer_die_Absenderermittlung,/*wi*/-1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/sqlzn>0);
//	opn<<new optcl(/*pname*/"musterzahl",/*pptr*/&zmzn,/*art*/plong,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Zahl_der_Muster_Verzeichnis_Paare_zum_Speichern_ankommender_Faxe,/*wi*/-1,/*Txi2*/-1,/*rottxt*/nix,/*wert*/-1,/*woher*/(zmzn>0));
	dhcl::virtinitopt(); //α
} // void hhcl::virtinitopt

// wird aufgerufen in lauf
void hhcl::pvirtmacherkl()
{
	hLog(violetts+Tx[T_virtmacherkl_Tx_lgn]+schwarz+ltoan(Tx.lgn));
//	erkl<<violett<<DPROG<<blau<<Txk[T_tut_dieses_und_jenes]<<schwarz; //ω 
	erkl<<blau<<Tx[T_Faxt_Dateien_aus_Verzeichnis_pfad_die]<<anfaxstr<<
		Tx[T_faxnr_enthalten_und_durch_soffice_in_pdf_konvertierbar_sind_und_traegt_sie]
		<<drot<<dbq<<blau<<Tx[T_Tabellen]<<drot<<touta<<blau<<"`,`"<<drot<<spooltab<<blau<<Tx[T_aein]<<schwarz;
} // void hhcl::pvirtmacherkl //α

// wird aufgerufen in lauf
void hhcl::virtMusterVorgb()
{
	hLog(violetts+Tx[T_virtMusterVorgb]+schwarz); //ω
	dbq=DPROG;
	findvers="3";
	ifindv=findv=atol(findvers.c_str());
	muser="user";
	citycode="8131";
	msn="999999";
	LocalIdentifier=Tx[T_MeiEinrichtung];
	cFaxUeberschrift=Tx[T_Mei_FaxUeberschrift];
	sqlvzn=0;
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
void hhcl::pvirtvorzaehler()
{ //ω
	if (obvc) dovc();
} // void hhcl::virtvorzaehler() //α
//ω

void hhcl::zeigdienste()
{
	cout<<Tx[T_Zustand_der_Dienste]<<endl;
	servc *svp[4]={scapis,sfaxq,shfaxd,sfaxgetty};
	for(int i=0;i<4;i++) {
		if (svp[i]) {
			svp[i]->obsvfeh();
			cout<<" "<<setw(25)<<svp[i]->sname<<": "<<blau<<Txk[sfeh[svp[i]->svfeh]]<<schwarz<<endl;
		} // 		if (svp[i])
	} // 	for(int i=0;i<4;i++)
} // void hhcl::zeigdienste()

// augerufen in: pruefhyla, zeigkonf, loeschehyla, anhalten
void hhcl::hylasv1()
{
	if (!this->sfaxgetty) this->sfaxgetty=new servc("hylafax-faxgetty-"+this->hmodem,"faxgetty");
} // void hhcl::hylasv1()

// augerufen in: pruefhyla, zeigkonf, loeschehyla, anhalten
void hhcl::hylasv2(hyinst hyinstart)
{
	if (hyinstart==hysrc || hyinstart==hyppk) {
		if (!sfaxq) sfaxq=new servc("hylafax-faxq","faxq");
		if (!shfaxd) shfaxd=new servc("hylafax-hfaxd","hfaxd");
		// => hyinstart==hypak
	} else {
		if (!sfaxq) sfaxq=new servc("","faxq");
		if (!shfaxd) shfaxd=new servc("","hfaxd");
	} // if (hyinstart==hysrc || hyinstart==hyppk) else
	if (!shylafaxd) shylafaxd=new servc("hylafax","faxq hfaxd");
} // void hhcl::hylasv2()

// wird aufgerufen in lauf //α
void hhcl::virtzeigversion(const string& ltiffv/*=nix*/)
{
	dhcl::virtzeigversion(ltiffv);  //ω
	zeigkonf();
	capisv();
	hylasv1();
	hylasv2(hysrc);
	zeigdienste();
} // void hhcl::virtzeigversion //α
//ω

// aus: coreutils
int fd_reopen(int desired_fd, char const *file, int flags, mode_t mode)
{
	int fd = open (file, flags, mode);
	if (fd==desired_fd||fd<0) {
		return fd;
	} else {
		int fd2 = dup2 (fd, desired_fd);
		int saved_errno = errno;
		close (fd);
		errno = saved_errno;
		return fd2;
	} // 	if (fd == desired_fd || fd < 0) else
} // fd_reopen (int desired_fd, char const *file, int flags, mode_t mode)

// mit strace usw. aus coreutils; in pruefmodem
int ttytest(const string& tty)
{
	int fd,erg=0,fdflags=0;
	int defin;
	if ((defin=dup(STDIN_FILENO))>=0) {
		static struct termios mode{0};
		if ((fd=fd_reopen (STDIN_FILENO, ("/dev/"+tty).c_str(), O_RDONLY | O_NONBLOCK, 0))>=0) {
			if ((fdflags = fcntl (STDIN_FILENO, F_GETFL)) != -1 && fcntl (STDIN_FILENO, F_SETFL, fdflags & ~O_NONBLOCK) >= 0) {
				if (!tcgetattr (STDIN_FILENO, &mode)) {
					erg=1;
				} // 				if (!tcgetattr (STDIN_FILENO, &mode))
			} // 			if ((fdflags = fcntl (STDIN_FILENO, F_GETFL)) != -1 && fcntl (STDIN_FILENO, F_SETFL, fdflags & ~O_NONBLOCK) >= 0)
			close(fd);
		} // 		if ((fd=fd_reopen (STDIN_FILENO, ("/dev/"+tty).c_str(), O_RDONLY | O_NONBLOCK, 0))>=0)
		dup2(defin,STDIN_FILENO);
		close(defin);
	} // 	if ((defin=dup(STDIN_FILENO))>=0)
	return erg;
} // int ttytest(const string& tty)

// wird aufgerufen in: main, virtrueckfragen
void hhcl::pruefmodem()
{
	hLog(violetts+Tx[T_pruefmodem]+schwarz);
	obmodem=0;
	string althmodem(hmodem);
	const string svz="/sys/class/tty/";
	svec qrueck;
	//// <<"pruefmodem 1 nach obcapi: "<<(int)obcapi<<endl;
	// 19.2.17: evtl. besser mit: dmesg|grep '[^t]*tty[^] 0\t:.$]'|sed 's/[^t]*\(tty[^] \t:.$]*\).*/\1/'
	// 25.2.17: geht leider nicht nach "<DPROG> -nohyla"
	// #define mitdmesg
#ifdef mitdmesg
	systemrueck("dmesg|grep tty",obverb,oblog,&qrueck,/*obsudc=*/0);
#else // mitdmesg
	if (findv==1) {
		systemrueck("cd "+svz+";find */device/driver", obverb,oblog,&qrueck,/*obsudc=*/0);
	} else {
		findfile(&qrueck,findv,obverb,oblog,0,svz,/*muster=*/"",1,127,0);
		for(size_t i=qrueck.size();i;) {
			i--;
			struct stat st={0};
			if (lstat((qrueck[i]+"/device/driver").c_str(),&st)) {
				qrueck.erase(qrueck.begin()+i);
			} // 				if (lstat((qrueck[i]+"/device/driver").c_str(),&st))
		} // 			for(size_t i=qrueck.size();i;)
	} // 		if (findv==1)
#endif // mitdmesg else
	for(size_t i=0;i<qrueck.size();i++) {
#ifdef mitdmesg
		size_t pos=qrueck[i].find("tty");
		if (pos==string::npos) continue;
		size_t p2=qrueck[i].find_first_of("] \t:.,;-",pos);
		if (p2==string::npos) continue;
		const string tty=qrueck[i].substr(pos,p2-pos);
		if (tty=="tty"||tty=="tty0") continue;
		////	modem=svz+modem;
		//// <<rot<<svz+modem<<schwarz<<endl;
#else // mitdmesg
		const string tty=findv==1?qrueck[i].substr(0,qrueck[i].find('/')):base_name(qrueck[i]);
		////			struct stat entrydriv=KLA 0 KLZ;
		////			if (!lstat((modem+"/device/driver").c_str(),&entrydriv)) KLA
		////				const string tty=base_name(modem);
#endif // mitdmesg else
		// ttyS0 erscheint auf Opensuse und Ubuntu konfiguriert, auch wenn kein Modem da ist
		if (tty!="ttyS0") {
			int terg;
			if (cus.cuid) {
				svec rue2;
				vector<errmsgcl> errv;
				const string f0=schwarzs+"Modem "+blau+tty+schwarz+Tx[T_gibts];
				const string f1=f0+Tx[T_nicht];
				errv.push_back(errmsgcl(0,f0));
				errv.push_back(errmsgcl(1,f1));
				//// aus coreutils; ' time 10 ' geht nicht, '{ { sudo stty -F /dev/ttyS1 1>&3;kill 0;}|{ sleep 10;kill 0;} } 3>&1' auch nicht
				// stty auch aus crontab aufrufbar (Pfad: /usr/bin:/bin)
				terg=!systemrueck("timeout 10 "+sudc+"stty -F /dev/"+tty/*//+" time 10" wirkt nicht*/,
						              obverb,oblog,&rue2,/*obsudc=*/0,/*verbergen=*/2,/*obergebnisanzeig=*/wahr,/*ueberschr=*/"",/*errm=*/&errv);
			} else {
				terg=ttytest(tty);
			} // 				if (cus.cuid) else
			if (terg) {
				obmodem=1;
				modems<<tty;
				hLog("Modem: "+blaus+tty+schwarz+Txk[T_gefunden]);
			} // if (terg)
		} // if (tty!="ttyS0") 
		// KLA // if (!lstat(((qrueck[i])+"/device/driver").c_str(),&entrydriv)) 
	} // for(size_t i=0;i<qrueck.size();i++) 
	////  uchar modemsumgesteckt=0;
	uchar schonda=0;
	if (!hmodem.empty()) {
		for(size_t j=0;j<modems.size();j++) {
			if (modems[j]==hmodem) {
				schonda=1;
				break;
			}
		} // for(size_t j=0;j<modems.size();j++) 
		if (!schonda) hmodem.clear();
	} // if (!hmodem.empty()) 
	if (hmodem.empty()) {
		if (modems.size()) if (!modems[0].empty()) {
			if (obverb>1) {
				hLog("modems[0]: "+blaus+modems[0]+schwarz);
			} // 				if (obverb)
			hmodem=modems[0];/*//modemsumgesteckt=1;*/ 
			modemgeaendert=1;
		} //   if (modems.size()) if (!modems[0].empty()) if (modems[0]!=hmodem) 
	} // if (hmodem.empty()) 
	obmdgeprueft=1;
	if (!obmodem) {
		fLog(rots+Tx[T_Kein_Modem_gefunden]+schwarz,obhyla?1:obverb,oblog);
		obhyla=0;
	}
	// wenn zum Konfigurationszeitpunkt kein Modem drinstak, aber jetzt, dann rueckfragen
	if (!schonda /*//obmodem && agcnfA.hole("obmodem")=="0"*/) {
		fLog(Txk[T_rueckzufragen_wegen]+rots+"!schonda"+schwarz+" (Modem)",1,0);
		rzf=1;
	}
	// wenn nur obzuschreib, dann noch nicht auf neu eingestecktes Modem reagieren
////	if (rzf) agcnfA.setze("obmodem",obmodem?"1":"0");
#if false
	agcnfA.setzbemv("obmodem",&Tx,T_ob_ein_Modem_drinstak);
#endif
	hLog(violetts+Txk[T_Ende]+Tx[T_pruefmodem]+schwarz);
	// wvdialconf oder schneller: setserial -a /dev/tty*, mit baud_base: <!=0>  als Kriterium
} // void hhcl::pruefmodem()

//α
// wird aufgerufen in lauf
void hhcl::pvirtvorrueckfragen()
{
	hLog(violetts+Tx[T_pvirtvorrueckfragen]+schwarz); //ω
		if (obhyla) pruefmodem();
		if (obcapi) pruefisdn();
} // void hhcl::pvirtvorrueckfragen //α


// wird aufgerufen in lauf
void hhcl::virtrueckfragen()
{
	const size_t aktc{0};
	hLog(violetts+Tx[T_virtrueckfragen]+schwarz);
	if (rzf) { //ω
		// Rueckfragen koennen auftauchen in: virtrueckfragen, konfcapi (<- pruefcapi), aenderefax, rufpruefsamba
		zufaxenvz=Tippverz(Tx[T_Verzeichnis_mit_zu_faxenden_Dateien],&zufaxenvz);
		wvz=Tippverz(Tx[T_Verzeichnis_mit_wartenden_Dateien],&wvz);
		ngvz=Tippverz(Tx[T_Verzeichnis_mit_gescheiterten_Dateien],&ngvz);
		empfvz=Tippverz(Tx[T_Verzeichnis_fuer_empfangene_Faxe],&empfvz);
		svec fbip;
		const uchar fbfehlt=systemrueck("ping fritz.box -c1",obverb,oblog,&fbip);
		// PING fritz.box (192.168.178.1) 56(84) bytes of data.
		if (fbfehlt) {
			obfbox=0;
		} else {
			if (rzf) {
				if (obfcard) {
					obfbox=Tippob(Tx[T_Soll_die_FritzBox_verwendet_werden],obfbox?Txk[T_j_af]:"n");
				} else {
					obfbox=0;
				}
			} //     if (agcnfA[++lfd].wert.empty() || rzf)
		} // 		if (fbfehlt) else
		if (obfbox) {
			if (rzf) {
				if (fbip.size()) {
					const string *const ipp=&fbip[0];
					if (const size_t p1=ipp->find("(")+1) {
						const size_t p2=ipp->find(")",p1);
						// 192.168.178.1
						svec mounts;
						if (!systemrueck("mount|grep '"+ipp->substr(p1,p2-p1)+"'",obverb,oblog,&mounts)&&mounts.size()) {
							// //192.168.178.1/DiabFB on /mnt/diabfb type cifs (rw,relatime,vers=1.0,cache=strict,username=ftpuser,domain=DIABFB,uid=0,noforceuid,gid=0,noforcegid,addr=192.168.178.1,unix,posixpaths,mapposix,acl,rsize=61440,wsize=65536,actimeo=1)
							vector<string> tok;
							aufSplit(&tok,mounts[0],' ');
							if (tok.size()>2) {
								svec datei;
								// die jüngste pdf-Datei auf dem CIFS-Verzeichnis suchen
								systemrueck("find '"+tok[2]+"' -type f -iname '*pdf' -print0|/usr/bin/xargs -0 -r ls -l --time-style=full-iso|sort -nrk 6,7", obverb,oblog,&datei);
								if (datei.size()) {
									// -rwxrwxrwx 1 root root   10061 2017-11-01 10:03:52.000000000 +0100 /mnt/diabfb/Generic-FlashDisk-01/FRITZ/faxbox/01.11.17_10.03_Telefax.081316150166.pdf
									if (const size_t p1=datei[0].find(" "+tok[2])+1) {
										fbankvz=dir_name(datei[0].substr(p1));
									} // 									if (const size_t p1=datei[0].find(" "+tok[2])+1)
								} // 								if (datei.size())
							} // 							if (tok.size()>2)
						} // 						if (!systemrueck("mount|grep "+ipp->substr(p1,p2-p1),obverb,oblog,&mounts)&&mounts.size())
					} // 					if (const size_t p1=ipp->find("(")+1)
				} // 				if (fbip.size())
				fbankvz=Tippstr(Tx[T_Mit_CIFS_gemountetes_Verzeichnis_mit_ankommenden_Faxen_der_Fritzbox],&fbankvz);
			} // 		if (agcnfA[++lfd].wert.empty() || rzf)
		} // 		if (obfbox)
		if (!obfcgeprueft) pruefisdn();
		if (obfcard) {
			obcapi=Tippob(Tx[T_Soll_die_Capisuite_verwendet_werden],obcapi?Txk[T_j_af]:"n");
		} else {
			obcapi=0;
		}
		if (!obmdgeprueft) pruefmodem();
		if (obmodem) {
			obhyla=Tippob(Tx[T_Soll_Hylafax_verwendet_werden],obhyla?Txk[T_j_af]:"n");
		} else {
			obhyla=0;
		}
		if (obcapi) {
			if (obhyla) {
				hylazuerst=!Tippob(Tx[T_Soll_vorrangig_capisuite_statt_hylafax_gewaehlt_werden],hylazuerst?"n":Txk[T_j_af]);
				maxcapiv=Tippzahl(Tx[T_Zahl_der_Versuche_in_Capisuite_bis_hylafax_eingeschaltet_wird],maxcapiv.c_str());
				maxhylav=Tippzahl(Tx[T_Zahl_der_Versuche_in_hylafax_bis_Capisuite_eingeschaltet_wird],maxhylav.c_str());
				// also: obcapi, aber nicht obhyla
			} else {
				hylazuerst=0;
			} // 			if (obhyla) else
		} else {
			hylazuerst=1;
		} // if (obcapi) else
		if (obhyla) {
			if (hmodem.empty()) hmodem=modems[0];
			hmodem=Tippstrs(Tx[T_Fuer_Hylafax_verwendetes_Modem],&modems,&hmodem);
			hklingelzahl=Tippzahl(Tx[T_Zahl_der_Klingeltoene_bis_Hylafax_den_Anruf_annimmt],hklingelzahl.c_str());
			maxhdials=Tippzahl(Tx[T_Zahl_der_Wahlversuche_in_Hylafax],maxhdials.c_str());
		}
		gleichziel=Tippob(Tx[T_Sollen_die_Dateien_unabhaengig_vom_Faxerfolg_im_Zielverzeichnis_gespeichert_werden],gleichziel?Txk[T_j_af]:"n");
		obocri=Tippob(Tx[T_soll_Text_in_empfangenen_Faxen_mit_OCR_gesucht_werden],obocri?Txk[T_j_af]:"j");
		obocra=Tippob(Tx[T_soll_Text_in_gesandten_Bildern_mit_OCR_gesucht_werden],obocra?Txk[T_j_af]:"n");
		anfaxstr=Tippstr(Tx[T_Buchstabenfolge_vor_erster_Faxnummer],&anfaxstr);
		if (obcapi && obhyla) {
			ancfaxstr=Tippstr(Tx[T_Buchstabenfolge_vor_erster_Fax_Nummer_primaer_fuer_Capisuite],&ancfaxstr);
			anhfaxstr=Tippstr(Tx[T_Buchstabenfolge_vor_erster_Fax_Nummer_primaer_fuer_Hylafax],&anhfaxstr);
		}
		anstr=Tippstr(Tx[T_Buchstabenfolge_vor_erstem_Adressaten],&anstr);
		undstr=Tippstr(Tx[T_Buchstabenfolge_vor_weiterem_Adressaten_sowie_weiterer_Faxnummer],&undstr);
		// sql abfragen, eintragen, sql aus opn loeschen, maps loeschen, maps neu erstellen
		schAcl<optcl> oprsql=schAcl<optcl>("oprsql"); // Optionen
		////		opn.oausgeb(rot);
		sqlrp.clear();
		unsigned neunr{1}; // Nr. des SQL-Befehles nach neuer Zaehlung
		for(size_t akt=0;/*akt<sqlzn*/1;) {
			//// caus<<"akt: "<<akt<<" "<<sqlp[akt]<<endl;
			const string *const vorgabe=(akt<sqlzn?(string*)opn[akt+sqlz0]->pptr/*sqlp[akt]*/:&nix);
			//// <<"vorgabe: "<<*vorgabe<<", sqlvp["<<akt<<"]: "<<sqlvp[akt]<<endl;
			akt++;
			string zwi;
			while (1) {
				zwi=Tippstr(string(Tx[T_SQL_Befehl_Nr])+ltoan(akt)+(vorgabe->empty()?
							Tx[T_faxnr_wird_ersetzt_mit_der_Faxnr]:
							Tx[T_Strich_ist_SQL_Befehl_loeschen_faxnr_wird_ersetzt_mit_der_Faxnr]),
						vorgabe,/*obnichtleer=*/0);
				if (zwi=="-") zwi.clear();
				if (zwi.empty()) {
					break;
				} else {
					svec dben=holdbaussql(zwi);
					//// <<"dben.size(): "<<(int)dben.size()<<endl;
					uchar dbda=1;
					if (!dben.size()) {
						if (Tippob(Tx[T_In]+rots+zwi+blau+Tx[T_keine_Datenbank_gefunden_Wollen_Sie_den_SQL_Befehl_neu_eingeben])) continue;
						dbda=0;
					} else { // if (!dben.size()) 
						uchar nochmal=0;
						for(size_t i=0;i<dben.size();i++) {
							//// <<"i: "<<blau<<i<<rot<<": "<<dben[i]<<schwarz<<endl;
							if (pruefDB(dben[i])) {
								dbda=0;
								if (Tippob(Tx[T_Datenbank]+rots+dben[i]+blau+Tx[T_nicht_ermittelbar_Wollen_Sie_den_SQL_Befehl_neu_eingeben])) {
									nochmal=1;
									break;
								} // if (strchr("jyJYoOsS",(int)erg)) 
							} // if (pruefDB(dben[i])) 
						} // for(size_t i=0;i<dben.size();i++) 
						if (nochmal) continue;     
					} // if (!dben.size()) 
					if (dbda) {
						if (zwi.find("&&faxnr&&")==string::npos) {
							if (Tippob(Tx[T_In]+rots+zwi+blau+Tx[T_keinmal_faxnr_gefunden_Wollen_Sie_den_SQL_Befehl_neu_eingeben])) continue;
						} else {
							RS rtest(this->My,ersetzAllezu(zwi,"&&faxnr&&","9999"),aktc,ZDB); //// (const char*)trimfaxnr));
							if (rtest.obfehl) {
								if (Tippob(Tx[T_In]+rots+zwi+blau+Tx[T_koennte_ein_SQL_Fehler_sein_Wollen_Sie_den_SQL_Befehl_neu_eingeben])) continue;
							} // if (rtest.obfehl)
						} // if (zwi.find("&&faxnr&&")==string::npos) 
					} // if (dbda)
				} // if (zwi.empty()) else
				break;
			} // while (1)
			if (zwi.empty()) {
			} else {
				// hier Sql-Dateien pruefen
				/*
					 cppSchluess* neuS=new cppSchluess;
					 neuS->name=string(cSQL_)+ltoan(++aktsp);
					 neuS->wert=zwi;
					 sqlv.push_back(neuS);
					 nsqlzn++;
				 */
				sqlrp.push_back(shared_ptr<string>(new string(zwi)));
				string istr=ltoan(neunr);
				stringstream soptname;
				soptname<<cSQL_<<(neunr++);
				//// caus<<"akt: "<<(akt)<<" "<<*(string*)opn.omap[soptname.str()]->pptr<<endl;
				//			opn.omap[soptname.str()]->virtoausgeb();
				optcl *opp=new optcl(/*pname*/soptname.str(),/*pptr*/sqlrp[sqlrp.size()-1].get(),/*art*/pstri,-1,-1,/*TxBp*/&Tx,/*Txi*/T_SQL_Befehl_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/1);
				oprsql<<opp;
			} // if (zwi.empty()) else
			if (akt>sqlzn-1) {
				if (!Tippob(Tx[T_Wolle_Sie_noch_einen_SQL_Befehl_eingeben],Txk[T_j_af])) { 
					break;
				}
			}
			//			map<const char* const,optcl const*>::iterator omit;
			//			shared_ptr<optcl> omit;
		} // 		for(size_t akt=0;1;)
		sqlzn=neunr-1;
		// vorherige SQL-Abfragen loeschen
		for(auto omit=opn.schl.end();omit!=opn.schl.begin();) {
			omit--;
			if (!(*omit)->pname.find(cSQL_)) {
				(*omit)->virtloeschomaps(&opn);
				opn.schl.erase(omit);
			}
		}
		// aktuelle SQL-Abfragen eintragen
		for(auto omit=oprsql.schl.begin();omit!=oprsql.schl.end();omit++) {
			opn<<(*omit);
		}
		schAcl<optcl> oprzm=schAcl<optcl>("oprzm"); // Optionen
		zmmrp.clear();
		zmzrp.clear();
		neunr=1; // Nr. des Zielmusterpaares nach neuer Zaehlung
		zmmrp.clear();
		zmzrp.clear();
		////opn.oausgeb(blau);
		for(size_t akt=0;/*akt<zmzn*/1;) {
			const string *const vgbm=(akt<zmzn?&zmsp[akt]->holmuster():&nix),
									 *const vgbz=(akt<zmzn?&zmsp[akt]->holziel():&nix);
			akt++;
			string zwim,zwiz;
			while (1) {
				zwim=Tippstr(string(Tx[T_Zielmuster_Nr])+ltoan(akt)+Tx[(akt<zmzn?T_zum_Streichen_Strich_eingeben:T_beim_letzten_fuer_alle_Uebrigen_nichts_eingeben)],vgbm,/*obnichtleer=*/0);
				if (zwim=="-") break;
				zwiz=Tippverz(string(Tx[T_Zielverzeichnis_Nr])+ltoan(akt),vgbz);
				if (!zwiz.empty()) break;
			} // while (1)
			if (zwim=="-") {
			} else {
				zmmrp.push_back(shared_ptr<string>(new string(zwim)));
				zmzrp.push_back(shared_ptr<string>(new string(zwiz)));
				string istr=ltoan(neunr);
				stringstream zmmname,zmzname;
				zmmname<<cZMMuster_<<neunr;
				zmzname<<cZMZiel_<<neunr;
				//// caus<<"akt: "<<(akt)<<" "<<*(string*)opn.omap[soptname.str()]->pptr<<endl;
				//			opn.omap[soptname.str()]->virtoausgeb();
				optcl *opmp=new optcl(/*pname*/zmmname.str(),/*pptr*/zmmrp[neunr-1].get(),/*art*/pstri,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Zielmuster_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/2);
				oprzm<<opmp;
				optcl *opzp=new optcl(/*pname*/zmzname.str(),/*pptr*/zmzrp[neunr-1].get(),/*art*/pstri,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Ziel_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/2);
				oprzm<<opzp;
				neunr++;
			} // 			if (zwim=="-")
			if (zwim.empty())
				break;
		} // 		for(size_t akt=0;/*akt<zmzn*/1;akt++)
		zmzn=neunr-1;
		// vorherige Zielmusterpaare loeschen
		for(auto omit=opn.schl.end();omit!=opn.schl.begin();) {
			omit--;
			if (!(*omit)->pname.find(cZMMuster_)||!(*omit)->pname.find(cZMZiel_)) {
				(*omit)->virtloeschomaps(&opn);
				opn.schl.erase(omit);
			}
		}
		// aktuelle Zielmusterpaare eintragen
		for(auto omit=oprzm.schl.begin();omit!=oprzm.schl.end();omit++) {
			opn<<(*omit);
		}
	} // if (rzf) //α
	dhcl::virtrueckfragen();
	//// opn.oausgeb(rot);
} // void hhcl::virtrueckfragen()

const string hhcl::initdhyladt="/etc/init.d/hylafax";
// wird aufgerufen in: pruefhyla, main
int hhcl::setzhylavz()
{
	// koennte auch im Fall eines entfernten Modems oder hylafax-Programms benoetigt werden
	// sucht das Hylaverzeichnis und setzt varsphylavz darauf, return 0, wenn nicht gefunden dann varsphylavz="", return 1
	// varsphylavz und hsendqvz festlegen
	fLog(violetts+Tx[T_setzhylavz]+schwarz,obverb,oblog);
	// wird fruehestens in korrigierecapi benoetigt
	// varsphylavz wird benoetigt in: korrigierecapi, untersuchespool, hfaxsetup(pruefhyla), pruefhyla, hylaausgeb(untersuchespool,zeigweitere)
	// hsendqvz wird benoetigt in: loescheallewartenden, loeschewaise, zeigweitere, inDBh(faxemitH)
	const char* testcmd="/bin/faxrcvd";
	int fundart=0;
	uchar weiterpruefen=0; 
	// 28.3.16: Die Datei /etc/init.d/hylafax+ taugt nicht fuer die Fallunterscheidung, da sie selbst eine Fallunterscheidung enthaelt

	svec hrueck;
	// 1) hylafax-Dienst im systemd suchen, dort steht z.B. ConditionPathExists=/var/spool/hylafax/etc/setup.cache ...
	systemrueck("grep /var $(dirname $(dirname $(which systemctl)))/lib/systemd/system/*fax*.service 2>/dev/null | "
			"head -n 1 | cut -d'=' -f2 | awk -F'/etc' '{print $1}'", obverb,oblog,&hrueck,/*obsudc=*/0);
	if (hrueck.size()) {
		varsphylavz=hrueck[0];
		fundart=1;
	} else {
		// 2) ... ansonsten steht vielleicht in /etc/init.d/hylafax das Verzeichnis:
		// in der OpenSuse-Datei bekam das Verzeichnis den Namen "SPOOL",
		// in Ubuntu "HYLAFAX_HOME"; dort bekam die Variable "SPOOL" einen anderen Inhalt

		////    cppSchluess hylaconf[]={{"SPOOL"},{"HYLAFAX_HOME"}};
		////    size_t cs=sizeof hylaconf/sizeof*hylaconf;
		if (!hfcnfCp) {
			hfcnfCp=new schAcl<WPcl>("hfcnfC", new vector<aScl>{
					{"SPOOL",&spoolvz},
					{"HYLAFAX_HOME",&hylafax_homevz}
					});
		}
		struct stat hstat{0};
		if (!lstat(initdhyladt.c_str(),&hstat)) {
			initdhyladt_gibts=1;
			if (hfaxcp) delete hfaxcp;
			hfaxcp = new confdcl(initdhyladt,obverb);
			hfaxcp->kauswert(hfcnfCp);
		} //     if (!lstat(initdhyladt.c_str(),&hstat))
		if (!hylafax_homevz.empty()) {
			//  if (cpplies(initdhyladt,hylaconf,cs)) KLA
			varsphylavz=hylafax_homevz;
			fundart=2;
		} else if (!spoolvz.empty()) {
			varsphylavz=spoolvz;
			fundart=2;
		} else {
			// 3) ... ansonsten schauen, welches Verzeichnis es gibt ...
			struct stat hstat{0},fstat{0};
			const char *const hfax{"/var/spool/hylafax"}, *const ffax{"/var/spool/fax"};
			int hgibts=!lstat(hfax,&hstat), fgibts=!lstat(ffax,&hstat);
			if (hgibts && !fgibts) {
				varsphylavz=hfax; 
				fundart=3;
			} else if (!hgibts && fgibts) {
				varsphylavz=ffax;
				fundart=3;
			}  else if (hgibts && fgibts) {
				// 4) ... falls beide, dann das juengere nehmen
				if (hstat.st_mtime>fstat.st_mtime) {
					varsphylavz=hfax;
				} else {
					varsphylavz=ffax;
				}
				fundart=4;
			} else {
				// 5) ... falls beide nicht, dann /var/spool/hylafax
				varsphylavz=hfax;
				fundart=5;
			} //       if (hgibts && !fgibts) else else
		} //     if (!hycnfA[1].wert.empty())  else else 
		weiterpruefen=1;
	} // if (hrueck.size()) else 

	// falls nicht im systemd-Dienst gefunden, dann zuerst im praeferierten, dann in anderen Verzeichnissen pruefen, wo es ./bin/faxrecvd gibt 
	if (weiterpruefen) {
		////  if (lsys.getsys(obverb,oblog)==sus) varsphylavz="/var/spool/fax";
		////  else if (lsys.getsys(obverb,oblog)==deb) varsphylavz="/var/spool/hylafax";
		string testvz=varsphylavz;
		for(unsigned iru=0;iru<(sizeof moeglhvz/sizeof *moeglhvz)+1;iru++) {
			struct stat entryhyla{0};
			if (!lstat((testvz+testcmd).c_str(),&entryhyla)) {
				varsphylavz=testvz; 
				if (iru) fundart=6;
				break;
			} else if (iru==sizeof moeglhvz/sizeof *moeglhvz) {
				// obhyla=0 hier noch nicht, da setzhylavz auch einmal vor der Installation schon aufgerufen wird
				break; // kein Verzeichnis gefunden
			} //   else if (iru==sizeof moeglhvz/sizeof *moeglhvz)
			testvz=moeglhvz[iru];
		} //     for(unsigned iru=0;iru<(sizeof moeglhvz/sizeof *moeglhvz)+1;iru++)
	} //   if (weiterpruefen)
	if (obverb) {
		string grund;
		switch (fundart) {
			case 1: grund=Tx[T_aus_systemd_fax_service_Datei_ermittelt];break;
			case 2: grund=Tx[T_aus_etc_init_d_hylafax_ermittelt];break;
			case 3: grund=Tx[T_aus_seiner_ausschliesslichen_Existenz_ermittelt];break;
			case 4: grund=Tx[T_aus_seinem_geringen_Alter_ermittelt];break;
			case 5: grund=Tx[T_aus_mangelnder_Alternative_ermittelt];break;
			case 6: grund=Tx[T_aus_Existenz_von]+blaus+testcmd+schwarz+Tx[T_ermittelt];break;
		} //     switch (fundart)
		fLog(Tx[T_hylafax_Verzeichnis]+blaus+varsphylavz+schwarz+grund);
	} // if (obverb)
	kuerzevtz(&varsphylavz);
	hsendqvz=varsphylavz+"/sendq";
	pruefverz(hsendqvz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0,/*besitzer=*/huser,/*benutzer=*/cuser,/*obmachen=*/0);
	hdoneqvz=varsphylavz+"/doneq";
	pruefverz(hdoneqvz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0,/*besitzer=*/huser,/*benutzer=*/cuser,/*obmachen=*/0);
	harchivevz=varsphylavz+"/archive";
	pruefverz(harchivevz,obverb,oblog,/*obmitfacl=*/1,/*obmitcon=*/0,/*besitzer=*/huser,/*benutzer=*/cuser,/*obmachen=*/0);
	xferfaxlog=varsphylavz+"/etc/xferfaxlog"; 
	hempfavz=varsphylavz+"/" DPROG "arch";
	return 0;
} // int hhcl::setzhylavz()

// in hliesconf() und hconfigtty()
void hhcl::setzmodconfd()
{
	modconfdt=this->varsphylavz+"/etc/config"+"."+this->hmodem; 
} // void hhcl::setzmodconfd()


// wird aufgerufen in: pruefhyla (2x)
// Modem konfigurieren
int hhcl::hconfigtty()
{
	hLog(violetts+"hconfigtty()"+schwarz);
	int ret=0;
	setzmodconfd();
	struct stat bakstat={0};
	if (lstat((modconfdt+".bak").c_str(),&bakstat)) {
		kopier(modconfdt,modconfdt+".bak",obverb,oblog);
	}
	////systemrueck("test -f '"+modconfdt+"' && test -f '"+modconfdt+".bak' ||"+sudc+"cp -a '"+modconfdt+"' '"+modconfdt+".bak'",obverb,oblog);
	//// <<rot<<modconfdt<<schwarz<<endl;
	// z.B. /var/spool/hylafax/etc/config.ttyACM0
	mdatei hci(modconfdt,ios::out);
	if (hci.is_open()) {
		//// <<rot<<" ist offen"<<schwarz<<endl;
		time_t jetzt=time(0);
		hci<<Tx[T_Konfiguration_von_hylafax_durch]+meinname+Tx[T_vom]<<ztacl(jetzt,"%d.%m.%y %T")<<endl;
		//// pthread_mutex_lock(&timemutex);
		//// struct tm *tm=localtime(&&jetzt);
		//// char buf[80];
		//// strftime(buf, sizeof(buf), "%d.%m.%y %T", tm);
		//// pthread_mutex_unlock(&timemutex);
		hci<<"CountryCode:    "<<this->countrycode<<endl;
		hci<<"AreaCode:   "<<this->citycode<<endl;
		hci<<"FAXNumber:    \""<<this->countrycode<<"."<<this->citycode<<"."<<this->msn<<"\""<<endl;
		hci<<"LongDistancePrefix: "<<this->LongDistancePrefix<<endl;
		hci<<"InternationalPrefix:  "<<this->InternationalPrefix<<endl;
		hci<<"DialStringRules:  \"etc/dialrules\""<<endl;
		hci<<"ServerTracing:    0xFFFFF"<<endl;
		hci<<"SessionTracing:   0xFFFFF"<<endl;
		hci<<"RecvFileMode:   0600"<<endl;
		hci<<"LogFileMode:    0600"<<endl;
		hci<<"DeviceMode:   0600"<<endl;
		hci<<"RingsBeforeAnswer:  "<<this->hklingelzahl<<Tx[T_muss_mindestens_2_sein_zur_Uebergabe_der_Nr_des_Anrufenden]<<endl;
		hci<<"MaxDials: "<<this->maxhdials<<endl;
		hci<<"MaxTries: "<<this->maxhdials<<endl;
		hci<<"CIDNumber: NMBR="<<endl;
		hci<<"CIDName:   NAME="<<endl;
		hci<<"SpeakerVolume:    off"<<endl;
		hci<<"GettyArgs:    \"-h %l dx_%s\""<<endl;
		hci<<"LocalIdentifier:  "<<this->LocalIdentifier<<endl;
		hci<<"LogFacility:    daemon"<<endl;
		//// #ifdef obhp
		struct stat Lstat={0};
		if (!lstat((this->varsphylavz+"/etc/LiberationSans-25.pcf").c_str(),&Lstat)) {
			hci<<"TagLineFont:    etc/LiberationSans-25.pcf"<<endl;
		} else {
			//// #else
			hci<<"TagLineFont:    etc/lutRS18.pcf"<<endl;
			//// #endif
		}
		hci<<"TagLineFormat:    \"Von %%l|%c|Seite %%P of %%T\""<<endl;
		hci<<"AdaptiveAnswer:   yes"<<endl;
		hci<<"AnswerRotary:   \"voice fax data\""<<endl;
		hci<<"MaxRecvPages:   100"<<endl;
		hci<<"JobReqBusy:   120"<<endl;
		hci<<"# Modem-related stuff: should reflect modem command interface"<<endl;
		hci<<"# and hardware connection/cabling (e.g. flow control)."<<endl;
		hci<<"ModemType:    Class1    # use class 1 interface"<<endl;
		hci<<"ModemRate:    38400   # rate for DCE-DTE communication"<<endl;
		hci<<"ModemFlowControl:  rtscts # hardware flow control # xonxoff   # software flow control"<<endl;
		hci<<"ModemSetupDTRCmd: ATS13=1&D3 # ATS13=1&D2 # setup so DTR drop resets modem"<<endl;
		hci<<"ModemSetupDCDCmd: AT&C1   # setup so DCD reflects carrier (or not)"<<endl;
		hci<<"ModemNoFlowCmd:   AT&H0 # AT&H0&I0&R1 # setup modem for no flow control"<<endl;
		hci<<"ModemHardFlowCmd: AT&H1 # AT&H1&I0&R2 # setup modem for hardware flow control"<<endl;
		hci<<"ModemSoftFlowCmd: AT&H2 # AT&H2&I2&R1 # setup modem for software flow control"<<endl;

		hci<<"ModemResultCodesCmd:  ATQ0X4 #CID=1    # enable result codes"<<endl;
		hci<<"ModemMfrQueryCmd: !USR5637 # !USR"<<endl;
		hci<<"ModemModelQueryCmd: ATI3"<<endl;
		hci<<"ModemRevQueryCmd: ATI7    # XXX returns a multi-line result"<<endl;
		hci<<"# When AT+FCLASS=1 is issued the modem automatically switches"<<endl;
		hci<<"# to software flow control; these parameters let the fax software"<<endl;
		hci<<"# reset flow control as needed after entering Class 1."<<endl;
		hci<<"Class1NFLOCmd:    AT+FLO=0 # AT&H0&I0&R1  # setup modem for no flow control"<<endl;
		hci<<"Class1HFLOCmd:    AT+FLO=2 # AT&H1&I0&R2  # setup modem for hardware flow control"<<endl;
		hci<<"Class1SFLOCmd:    AT+FLO=1 # ""   # modem does this automatically"<<endl;
		hci<<"# This should resolve \"DIS/DTC received 3 times\" errors:"<<endl;
		hci<<"Class1ResponseWaitCmd:  AT+FRS=1  # wait after sending TCF for response"<<endl;
		hci<<"# The remainder of this configuration is included so that the"<<endl;
		hci<<"# modem \"idles\" in Class 0 while not sending or receiving facsimile."<<endl;
		hci<<"ModemSetupAACmd:  AT+FCLASS=0 # leave modem idling in class 0"<<endl;
		hci<<"ModemAnswerCmd:   AT+FCLASS=1A  # answer in Class 1"<<endl;
		hci<<"# die folgenden sind aus dem Internet"<<endl;
		hci<<"ModemResetCmds:   ATS19=255"<<endl;
		hci<<"ModemAnswerFaxCmd:  ATS27=8S56=0+FCLASS=1;A"<<endl;
		hci<<"ModemAnswerDataCmd: ATS27=1S56=16+FCLASS=0;A"<<endl;
		hci<<"Class1RecvIdentTimer: 10000"<<endl;
		hci<<""<<endl;
		hci<<"# When using AT+FRS=n we see USR modems reset themselves in the middle of sessions"<<endl;
		hci<<"# this is not good.  So, we seem to work-around that problem by not using the"<<endl;
		hci<<"# command.  Unfortunately, this isn't an ideal thing."<<endl;
		hci<<"Class1SwitchingCmd: \"<delay\0727>\""<<endl;
		hci<<"# FaxRcvdCmd: ./schreibe.sh"<<endl;
	} else {
		cerr<<Txk[T_datei]<<modconfdt<<Tx[T_nichtbeschreibbar]<<endl;
		// <<rot<<" nicht offen"<<schwarz<<endl;
		ret=1;
	} // 	if (hci.is_open())
	hLog(violetts+Txk[T_Ende]+"hconfigtty()"+schwarz);
	return ret;
} // void hhcl::hconfigtty()

// aufgerufen in faxemitH, pruefhyla
void useruucp(const string& huser, const int obverb, const int oblog)
{
	if (systemrueck("getent passwd "+huser,obverb,oblog,/*rueck=*/0,/*obsudc=*/1)) {
		const string bef="useradd -b /etc -c \"Unix-to-Unix CoPy\" -U -r "+huser;
		systemrueck(bef,obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
		anfgg(unindt,sudc+"userdel "+huser,bef,obverb,oblog);
	} // 	if (systemrueck
} // void useruucp

// aufgerufen in: hservice_faxq_hfaxd und hfaxsetup
void hhcl::setzfaxgtpfad()
{
	struct stat entryfaxgt{0};
	if (lstat(faxgtpfad.c_str(),&entryfaxgt)) {
		faxgtpfad.clear();
		//  faxgtpfad="/usr/lib/fax/faxgetty";
		//    faxgtpfad="/usr/sbin/faxgetty";
		obprogda("faxgetty",obverb,oblog,&faxgtpfad);
		if (faxgtpfad.empty() || lstat(faxgtpfad.c_str(),&entryfaxgt)) {
			faxgtpfad.clear();
			svec qrueck;
			const string wo{"/usr/lib/fax /usr/sbin /usr/bin /root/bin /sbin /usr/local/sbin /usr/local/bin"};
			if (findv==1) {
				systemrueck(sudc+"find "+wo+" -perm /111 -name faxgetty", obverb-1,oblog,&qrueck);
			} else findfile(&qrueck,findv,obverb,oblog,0,wo,/*muster=*/"faxgetty$",-1,1,Fol_Dat,0,0,0,1);
			if (qrueck.size()) 
				faxgtpfad=qrueck[0];
		} // 		if (faxgtpfad.empty() || lstat(faxgtpfad.c_str(),&entryfaxgt))
	} // 	if (lstat(faxgtpfad.c_str(),&entryfaxgt))
	// violett<<"faxgtpfad 4: "<<faxgtpfad<<schwarz<<endl;
} // void hhcl::setzfaxgtpfad()

// wird aufgerufen in: pruefhyla
// Dienste erstellen
int hhcl::hservice_faxq_hfaxd()
{
	int hylafehler=0;
	hLog(violetts+"hservice_faxq_hfaxd()"+schwarz);
	struct stat hstat={0}, fstat={0};
	if (hfaxdpfad.empty()||lstat(hfaxdpfad.c_str(),&hstat)) { obprogda("hfaxd",obverb,oblog,&hfaxdpfad); }
	hylafehler+=!shfaxd->spruef("HFaxd",0/*1*/,meinname,hfaxdpfad+" -d -i hylafax"/* -s 444*/, varsphylavz+"/etc/setup.cache", "",linstp,obverb,oblog);
	this->shfaxd->machfit(obverb,oblog);
	if (faxqpfad.empty()||lstat(faxqpfad.c_str(),&fstat)) { obprogda("faxq",obverb,oblog,&faxqpfad); }
	hylafehler+=!sfaxq->spruef("Faxq",0/*1*/,meinname,faxqpfad+" -D", varsphylavz+"/etc/setup.cache", shfaxd->sname+".service",linstp,obverb,oblog);
	setzfaxgtpfad();
	hylafehler+=!this->sfaxgetty->spruef("HylaFAX faxgetty for "+this->hmodem,0,meinname,faxgtpfad+" "+this->hmodem,"","",linstp,obverb,oblog,0);
	return hylafehler;
} // void hservice_faxq_hfaxd()

// wird aufgerufen in: pruefhyla
int hhcl::hconfig() const
{
	hLog(violetts+"hconfig()"+schwarz);
	int erg=0;
	const string confd=this->varsphylavz+"/etc/config";
	mdatei conf(confd,ios::out);
	if (conf.is_open()) {
		conf<<"LogFacility:    daemon"<<endl;
		conf<<"CountryCode:    "<<this->countrycode<<endl;
		conf<<"AreaCode:   "<<this->citycode<<endl;
		conf<<"LongDistancePrefix: "<<this->LongDistancePrefix<<endl;
		conf<<"InternationalPrefix:  "<<this->InternationalPrefix<<endl;
		conf<<"DialStringRules:  \"etc/dialrules\""<<endl;
		conf<<"ServerTracing:    1"<<endl;
		conf<<"SessionTracing:   0xffffffff"<<endl;
		struct stat entryfaxsd={0};
		svec qrueck;
		string faxsdpfad=this->varsphylavz+"/bin/faxsend";
		if (lstat(faxsdpfad.c_str(),&entryfaxsd)) {
			faxsdpfad="/usr/sbin/faxsend";
			if (lstat(faxsdpfad.c_str(),&entryfaxsd)) {
				faxsdpfad.clear();
				const string wo="/usr /root/bin /sbin";
				if (findv==1) {
					systemrueck(sudc+"find "+wo+" -perm /111 -name faxsend",obverb-1,oblog,&qrueck);
				} else findfile(&qrueck,findv,obverb,oblog,0,wo,/*muster=*/"faxsend$",-1,1,Fol_Dat,0,0,0,1);
				if (qrueck.size()) 
					faxsdpfad=qrueck[0];
			} // 			if (lstat(faxsdpfad.c_str(),&entryfaxsd))
		} // 		if (lstat(faxsdpfad.c_str(),&entryfaxsd))
		if (!faxsdpfad.empty())
			conf<<"SendFaxCmd:   "<<faxsdpfad<<endl;
		conf<<"Use2D:      \"no\""<<endl;
	} else {
		cerr<<"hconfig(): "<<Txk[T_datei]<<confd<<Tx[T_nichtbeschreibbar]<<endl;
		erg=1;
	} //   if (conf.is_open())
	hLog(violetts+Txk[T_Ende]+"hconfig()"+schwarz);
	return erg;
} // void hconfig(hhcl *hhip,int obverb, int oblog)

// wird aufgerufen in pruefhyla
// hylafax konfigurieren 
void hhcl::hfaxsetup()
{
	hLog(violetts+"hfaxsetup()"+schwarz);
	string faxsu;
	////  const char *faxsu="/usr/sbin/faxsetup";
	if (obprogda("faxsetup",obverb,oblog,&faxsu)) {
#ifdef DPROGsetup
		// das Skript faxsetup soll leicht veraendert als '" <DPROG> "setup' abgespeichert und dann aufgerufen werden
		const char *afaxsu="/usr/local/sbin/" DPROG "setup";
		mdatei alt(faxsu,ios::in);
		if (alt.is_open()) {
			mdatei neu(afaxsu,ios::out);
			if (neu.is_open()) {
				string zeile, ergzeile;
				size_t znr=0,promptz=0;
				string vorgabe;
				while(getline(alt,zeile)) {
					size_t p0,p1,kla,klz,einr=0;
					uchar zukomm=0;
					if (zeile.find("INTERACTIVE=yes")!=string::npos) {
						zeile="INTERACTIVE=no" # Aenderung G.Schade 25.5.16;
					} else if (zeile.find("ok=prompt")!=string::npos) {
						// Interaktivitaet streichen
						zeile="     ok=skip    # prompt for parameters # Aenderung G.Schade 1.1.16";
					} else if (!zeile.find("PATH_EGETTY=")) {
						// suche das aktuelle Fax-Empfangsprogramm; 'which faxgetty' geht nicht immer, da z.B. /usr/lib/fax/ nicht im Standard-Befehlssuchpfad,
						// aber unter Opensuse 42.1 der Vorgabeort fuer faxgetty
						zeile="PATH_EGETTY=$("+sudc+"find /usr/lib/fax /usr/sbin /usr/bin /root/bin /sbin -perm /111 -name faxgetty 2>/dev/null) "
							"# /bin/egetty # pathname for external getty program # Aenderung G.Schade 29.2./ 23.3.16";
					} else if (zeile.find("$MV $DIR_LIBDATA/hyla.conf.tmp $DIR_LIBDATA/hyla.conf")!=string::npos) {
						// wenn zuvor keine der Veraenderungen von hyla.conf erfolgt, dann gibt es auch hyla.conf.tmp nicht;
						// dies soll ohne Fehlermeldung gehen
						zeile=" test -f \"$DIR_LIBDATA/hyla.conf.tmp\" && "+zeile;
					} else {
						if (zeile[0]!='#' && (p0=zeile.find("prompt "))!=string::npos) {
							einr=p0+2;
							if ((kla=zeile.find('[',p0))!=string::npos) if ((klz=zeile.find(']',kla))!=string::npos) {
								// faxaddmodem soll hier nicht aufgerufen werden
								promptz=znr; 
								if (zeile.find("run faxaddmodem")==string::npos) 
									vorgabe=zeile.substr(kla+1,klz-kla-1);
								else
									vorgabe="no";
							}
							zukomm=1;
						} //             if (zeile[0]!='#' && (p0=zeile.find("prompt "))!=string::npos)
						// wenn in der oder der naechsten Zeile read steht
						// (z.B. in den Funktionen promptFor...parameter()), dann soll ohne Rueckfrage die Vorgabe verwendet werden
						if ((znr==promptz || znr==promptz+1) && zeile[0]!='#' && (p1=zeile.find("read "))!=string::npos) {
							ergzeile=string(einr,' ')+zeile.substr(p1+5);
							if ((p1=ergzeile.find(' ',einr))!=string::npos) ergzeile=ergzeile.substr(0,p1);
							ergzeile=ergzeile+"=\""+vorgabe+"\" # G.Schade 1.1.16";
							zukomm=1;
						}
						if (zukomm) zeile="# "+zeile+" # Kommentar G.Schade 1.1.16";
					} // if (zeile.find("INTERACTIVE=yes")!=string::npos) else else else else
					neu<<zeile<<endl;
					if (!ergzeile.empty()) {
						neu<<ergzeile<<endl;
						ergzeile.clear();
					}
					znr++;
				} // while(getline(alt,zeile)) 
				neu.close();
				if (chmod(afaxsu.c_str(),S_IRWXU|S_IRWXG))
					systemrueck(sudc+"chmod 770 '"+afaxsu+"'",0,1);
				this->sfaxgetty->stop(obverb,oblog);
				this->shfaxd->stop(obverb,oblog);
				this->sfaxq->stop(obverb,oblog);
				/*//
					systemrueck(sudc+"systemctl stop "+this->sfaxgetty->sname+" "+this->shfaxd->sname+" "+this->sfaxq->sname,obverb,oblog);
					systemrueck(sudc+"pkill "+this->sfaxgetty->ename+" "+this->shfaxd->ename+" "+this->sfaxq->ename,obverb,oblog);
				 */
				fLog(blaus+Tx[T_Fuehre_aus_Dp]+schwarz+afaxsu+blau+Tx[T_falls_es_hier_haengt_bitte_erneut_aufrufen]+schwarz,1,oblog);
				obverb=0; // dann haengt's immer
				system((sudc+"pkill hfaxd;"+shpf+" "+afaxsu+(obverb?" -verbose":"")+" >/dev/null 2>&1").c_str());  
				this->sfaxgetty->restart(obverb,oblog);
				this->shfaxd->restart(obverb,oblog);
				this->sfaxq->restart(obverb,oblog);
				//// systemrueck(". "+afaxsu+(obverb?" -verbose":""),obverb,oblog,0,falsch); // haengt am Schluss, geht nicht mit unbuffer, unbuffer /usr/local/sbin/" DPROG "setup -verbose, loeschen von exit 0 am schluss, exec, stty -echo -onlcr usw., nohup,
				::Log(blaus+Txk[T_Fertig_mit]+schwarz+afaxsu,1,oblog);
				servc::daemon_reload();
				////        systemrueck("rm "+afaxsu,1,1);
			} // if (neu.is_open()) 
		} // if (alt.is_open()) 
#else
		this->sfaxgetty->stop(obverb,oblog,1);
		this->shfaxd->stop(obverb,oblog,1);
		this->sfaxq->stop(obverb,oblog,1);
		/*//
			systemrueck(sudc+"systemctl stop "+this->sfaxgetty->sname+" "+this->shfaxd->sname+" "+this->sfaxq->sname,obverb,oblog);
			systemrueck(sudc+"pkill "+this->sfaxgetty->ename+" "+this->shfaxd->ename+" "+this->sfaxq->ename,obverb,oblog);
		 */
		fLog(blaus+Tx[T_Fuehre_aus_Dp]+schwarz+sudc+faxsu+" -nointeractive"+blau+Tx[T_falls_es_hier_haengt_bitte_erneut_aufrufen]+schwarz,1,oblog);
		pruefplatte();
		// Stehenbleiben konnte ich nur durch pkill verhindern, Prozess des Bash-Gabelprogramms nicht gefunden
		if (!systemrueck("( (sleep 20; pkill " DPROG ") & exec "+faxsu+" -nointeractive"+(obverb?" -verbose":"")+" )",obverb,oblog,0,1)) {
			this->shfaxd->stop(obverb,oblog,1);
			this->sfaxq->stop(obverb,oblog,1);
			servc::daemon_reload();
		} // if (!systemrueck(sudc+faxsu+" -nointeractive"+(obverb?" -verbose":""),obverb,oblog,0,2)) 
		/*//
			int erg __attribute__((unused));
			erg=system((sudc+"$(which sh) $("+sudc+"env \"PATH=$PATH\" which faxsetup) -nointeractive"+string(obverb?" -verbose":"")+
			"&&"+sudc+"pkill hfaxd faxq >/dev/null 2>&1"
			"&&"+sudc+"systemctl daemon-reload").c_str()); 
		 */
		this->sfaxgetty->start(obverb,oblog);
		this->shfaxd->start(obverb,oblog);
		this->sfaxq->start(obverb,oblog);
		pruefplatte();
		// systemrueck(". "+faxsu+(obverb?" -verbose":""),obverb,oblog,0,falsch); // haengt am Schluss, geht nicht 
		// mit unbuffer, unbuffer /usr/local/sbin/" DPROG "setup -verbose, loeschen von exit 0 am schluss, exec, stty -echo -onlcr usw., nohup,
		fLog(blaus+Txk[T_Fertig_mit]+schwarz+faxsu,1,oblog);
		////    systemrueck(sudc+"systemctl daemon-reload",0,1);
#endif
	} //   if (!lstat(faxsu, &entrybuf)) KLA
	this->setzfaxgtpfad();
} // hfaxsetup

void hhcl::hliesconf()
{
#ifdef false
	const char* const sarr[]{"CountryCode","AreaCode","FAXNumber","LongDistancePrefix","InternationalPrefix","RingsBeforeAnswer","LocalIdentifier","MaxDials"};
	schlArr hyaltcnfA(sarr,sizeof sarr/sizeof *sarr);
#endif
	setzmodconfd();
	struct stat mstat{0};
	if (lstat(modconfdt.c_str(),&mstat)) {
		hylazukonf=1;
	} else {
#ifdef false
		confdat haltcd(modconfdt,&hyaltcnfA,obverb,':');
		if (countrycode_dt!=countrycode || citycode_dt!=citycode || faxnumber_dt=countrycode+"."+citycode+"."+msn 
				|| longdistanceprefix_dt!=LongDistancePrefix || internationalprefix_dt!=InternationalPrefix 
				|| ringsbeforeanswer_dt!=hklingelzahl || localidentifier_dt!=LocalIdentifier|| maxdials_dt!=maxhdials /*|| hyaltcnfA.schl[7].wert!=maxdials */
			 ) {
			hylazukonf=1;
		} // if (hyaltcnfA.shl[0].wert ...
#else
		if (!hyaltcnfCp) {
			hyaltcnfCp=new schAcl<WPcl>("hyaltcnfC", new vector<aScl>{
					{"CountryCode",&countrycode_dt},
					{"AreaCode",&areacode_dt},
					{"FAXNumber",&faxnumber_dt},
					{"LongDistancePrefix",&longdistanceprefix_dt},
					{"InternationalPrefix",&internationalprefix_dt},
					{"RingsBeforeAnswer",&ringsbeforeanswer_dt},
					{"LocalIdentifier",&localidentifier_dt},
					{"MaxDials",&maxdials_dt}
					});
		}
		confdcl hyaltcp(modconfdt,obverb);
		hyaltcp.kauswert(hyaltcnfCp);
#endif
	} //   if (lstat(modconfdt.c_str(),&mstat)) else
	// hyaltcnfA.ausgeb();
} // void hhcl::hliesconf()


// wird aufgerufen in main
int hhcl::pruefhyla()
{
	hLog(violetts+Tx[T_pruefhyla]+schwarz);
	int ret=0;
	hylasv1();
	do { // fuer break
		if (hmodem.empty()) {
			fLog(blaus+Tx[T_Kein_Modem_gefunden]+schwarz,obhyla?1:obverb,oblog);
			this->obhyla=0;
		} else {
			lsysen system=lsys.getsys(obverb,oblog);
			hyinst hyinstart; // hyla source, hyla Paket, hylaplus Paket
			if (system==deb /*// || system==fed*/) {
				hyinstart=hysrc;
			} else {
				hyinstart=hyppk;
			} 
			hylasv2(hyinstart);
			if (obhyla) {
				long br=0; // baud rate
				string brs; // Baud-Rate-String
				int hylalaeuftnicht=0;
				static uchar hylafehlt=1;
				uchar falscheshyla=0;
				uchar modemlaeuftnicht=1;
				uchar frischkonfiguriert=0;

				if (modemgeaendert) {
					if (hconfigtty()) {
						ret=1;
						break;
					}
					hccd.obzuschreib=1;
				} //   if (modemgeaendert)

				// Baud rate ermitteln ...
				svec ruecki;
				systemrueck(("stty -F /dev/")+this->hmodem+"| head -n 1 | cut -f2 -d' '",obverb,oblog,&ruecki,/*obsudc=*/1);
				if (ruecki.size()) {
					brs=ruecki[0];
					br=atol(brs.c_str());
				} // 				if (ruecki.size())
				// .. und anzeigen
				if (br<=0) {
					fLog(Tx[T_Baudratevon]+blaus+"/dev/"+this->hmodem+schwarz+Tx[T_mit_af]+rot+brs+schwarz+Tx[T_zugeringVerwendeHylafaxnicht],1,1);
					////    return 1;
				} else {
					hLog("Modem '"+blaus+"/dev/"+this->hmodem+schwarz+Tx[T_mit_Baudrate]+gruen+brs+schwarz+Tx[T_wird_verwendet]);
				} //   if (br<=0) else
				// ein Fehler in der Version 4.0.7 von libtiff verhindert die Zusammenarbeit mit hylafax
				/*//
					const string befehl="sh -c \"NACHWEIS="+lsys.getlib64()+"/sclibtiff;! test -f /usr/include/tiff.h ||! test -f \\$NACHWEIS"
					"&&{ "+linstp->schau+" cmake||"+linstp->instyp+" cmake;true"
					"&& P=tiff_copy; T=\\$P.tar.gz; Z=tiff-4.0.7"
					"; wget https://github.com/libelle17/\\$P/archive/master.tar.gz -O \\$T"
					"&& tar xpvf \\$T && mv \\${P}-master \\$Z && cd \\$Z"
					"&& rm -f CMakeCache.txt"
					"&& sed -i.bak s'/uint16 Param;/uint32 Param;/' libtiff/tif_fax3.h"
					"&& cmake -DCMAKE_INSTALL_PREFIX=/usr -DLIBTIFF_ALPHA_VERSION=1 . "
					"&& make"
					"&& "+sudc+"make install"
					"&&{ grep -q \\\"cd \\\"\\$(pwd)\\\" \\\""+unindt+"\\\""
					"|| printf \\\"cd \\\"\\$(pwd)\\\" && make uninstall; cd \\\""+instvz+"\\\"\\n\\\" >> \\\""+unindt+"\\\";} "
					"&& "+sudc+"touch \\$NACHWEIS;};:\"";
				 */
				/*//
					systemrueck("sh -c 'cd \""+instvz+"\";T="+datei+".tar.gz; wget https://github.com/libelle17/"+datei+"/archive/master.tar.gz -O $T'", 
					return systemrueck("sh -c 'P="+was+";T=$P.tar."+endg+";M=$P-master;cd \""+instvz+"\" && tar xpvf $T"
					"&& rm -rf $P 2>/dev/null||"+sudc+"rm -rf $P&& mv $M $P'",obverb,oblog);
					return systemrueck("sh -c 'cd \""+instvz+vtz+was+"\"&&"+vorcfg+"&&./configure "+cfgbismake+" make &&"+sudc+"make install "
					"&&{ grep -q \"cd \"$(pwd)\" \""+unindt+"\""
					"|| printf \"cd \"$(pwd)\" && make uninstall; cd \""+instvz+"\"\\n\" >> \""+unindt+"\";} "
					"'"
				 */
				prueftif(TIFFGetVersion());

				for(unsigned versuch=0;versuch<3;versuch++) {
					// 1) Dienst(e) hylafax, (hylafax-)hfaxd, (hylafax-)faxq identifizieren
					// pruefen, ob hylafax.service laeuft
					hLog(Tx[T_Pruefe_ob_Hylafax_gestartet]);
					const char* const c_hfs="hylafax";
					const char* const c_hfc="hylafax-client";
					const char* const c_hfps="hylafax+";
					const char* const c_hfpc="hylafax+-client";
					char *hfr, *hfcr, *hff, *hfcf; // hylafax richtig, hylafax client richtig, hylafax falsch, hylafax client falsch
					string hfftext;
					hylalaeuftnicht=1;
					hylafehlt=1;
					if (hyinstart==hysrc || hyinstart==hyppk) {
						hfr=(char*)c_hfps; hfcr=(char*)c_hfpc; hff=(char*)c_hfs; hfcf=(char*)c_hfc;
						hfftext=Tx[T_Hylafax_ohne_plus_entdeckt_muss_ich_loeschen];
						// => hyinstart==hypak
					} else {
						hfr=(char*)c_hfs; hfcr=(char*)c_hfc; hff=(char*)c_hfps; hfcf=(char*)c_hfpc;
						hfftext=Tx[T_Hylafaxplus_entdeckt_muss_ich_loeschen];
						huser="fax";
					} // if (hyinstart==hysrc || hyinstart==hyppk) else
					// 2) deren Existenz, Betrieb und ggf. Startbarkeit pruefen
					// wenn die richtigen Dienste laufen, dann nichts weiter ueberpruefen ..
					//// <<violett<<"pruefhyla 1"<<schwarz<<endl;
					if ((!sfaxq->obsvfeh(obverb-1,oblog) && !shfaxd->obsvfeh(obverb-1,oblog)) /*|| this->shylafaxd->obslaeuft(obverb-1,oblog)*/) {
						hLog(Tx[T_Hylafax_laeuft]);
						hylalaeuftnicht=0;
						hylafehlt=0;
					} else if (versuch>1) {
						fLog(rots+Tx[T_Fehler_in_pruefhyla]+schwarz,1,oblog);
						ret=2;
						break;
					} //     if ((this->sfaxq->obslaeuft(obverb-1,oblog) && this->shfaxd->obslaeuft(obverb-1,oblog))  else
					if (hylafehlt) {
						// falls nein, dann schauen, ob startbar
						if (sfaxq->machfit(obverb?obverb-1:0,oblog) && shfaxd->machfit(obverb?obverb-1:0,oblog) && sfaxgetty->machfit(obverb?obverb-1:0,oblog)) {
							hylafehlt=0;
							hylalaeuftnicht=0;
						}
						//// <<"hylafehlt: "<<(int)hylafehlt<<endl;
					} else {
						//// <<"hylafehlt nicht!"<<endl;
					} //     if (hylafehlt) else
					int nochmal;
					for(int aru=0;aru<2;aru++) {
						nochmal=0;
						//// <<violett <<"Versuch: "<<(int)versuch<<" hylafehlt: "<<(int)hylafehlt<<" hylalaeuftnicht: "<<(int)hylalaeuftnicht<<schwarz<<endl;
						if (hylafehlt) {
							// 3) ggf. neu installieren
							fLog(violetts+Tx[T_Muss_Hylafax_installieren]+schwarz,1,1);
							// a) von der source
							linstp->doinst("ghostscript",obverb+1,oblog,nochmal?nix:"gs");
              if (!obsotiff) {
							 linstp->doinst("tiff",obverb+1,oblog,"tiff2ps");
							 linstp->doinst("tiff",obverb+1,oblog,"fax2ps");
							} //               if (!obsotiff)
							prueftif(TIFFGetVersion());
							linstp->doinst("sendmail",obverb+1,oblog,"sendmail");
							if (obverb) fLog(violetts+"hyinstart: "+schwarz+ltoan(hyinstart),1,1);
							hyinstart=hysrc; // spaeter zu loeschen
							if (hyinstart==hysrc) {
								fLog(violetts+Tx[T_ueber_den_Quellcode]+schwarz,1,1);
								string was;
								for(int iru=0;iru<2;iru++) {
									if (!holvomnetz("hylafax","https://sourceforge.net/projects/","/files/latest")) {
										svec hrueck;
										if (systemrueck("cd \""+instvz+"\"&& tar xvf hylafax.tar.gz",obverb,oblog,&hrueck,/*obsudc=*/1)) {
											tuloeschen("hylafax.tar.gz",cuser,obverb,oblog);
											continue;
										} else {
											if (hrueck.size()) {
												was=hrueck[0].substr(0,hrueck[0].length()-1);
											} // 							if (hrueck.size())
											break;
										} //			if (!systemrueck("sh -c 'cd \""+instvz+"\"&&"+sudc+"tar xvf hylafax.tar.gz'",obverb,oblog,&hrueck))
									} // 		if (!holvomnetz("hylafax","https://sourceforge.net/projects/","/files/latest"))
								} // 								for(int iru=0;iru<2;iru++)
								if (!was.empty()) {
									useruucp(huser,obverb,oblog);
									// Fehlermeldung faxgetty nicht gefunden verbergen
									const string vorcfg="sed -i.bak 's_\\(ls -lL \\$1$\\)_\\1 2>/dev/null_g' configure";
									const string cfgbismake=nix+" --nointeractive && echo $? = Ergebnis nach configure && "
										"sed -i.bak \"s.PAGESIZE='North American Letter'.PAGESIZE='ISO A4'.g;"
										"s.PATH_GETTY='\\.*'.PATH_GETTY='"
										"$(grep LIBEXEC defs | cut -d'=' -f2 | sed 's/^[[:space:]]*//;s/[[:space:]]*$//')/faxgetty'.g\" config.cache"
										"&& echo $? = "+Tx[T_Ergebnis_nach]+" sed"
										"&&"+sudc;
									if (!kompilfort(was,vorcfg,cfgbismake)) {
										const string nachcfg=
											"systemctl daemon-reload && systemctl stop hylafax 2>/dev/null"
											"&& test -f /etc/init.d/hylafax &&{  mkdir -p /etc/ausrangiert"
											"&& mv -f /etc/init.d/hylafax /etc/ausrangiert;}"
											"&& pkill hfaxd faxq >/dev/null 2>&1 && faxsetup -nointeractive >/dev/null 2>&1 "
											"&& echo $? = Ergebnis nach faxsetup -nointeractive"
											"&& pkill hfaxd faxq >/dev/null 2>&1"//wird von faxset -nointeractive gestartet + kollidiert mit dem service
											"&& systemctl daemon-reload &&echo $? = Ergebnis nach systemctl daemon-reload;:;";
										systemrueck(nachcfg,obverb<1?obverb:1,oblog,/*rueck=*/0,/*obsudc=*/1);
										mdatei confc(instvz+vtz+was+vtz+"config.cache");
										if (confc.is_open()) {
											string zeile;
											while(getline(confc,zeile)) {
												if (zeile.find("DIR_LIBEXEC")!=string::npos) {
													string rechts=zeile.substr(zeile.find("=")+1);
													anfzweg(rechts);
													faxgtpfad=rechts+vtz+"faxgetty";
													faxqpfad=rechts+vtz+"faxq";
													hfaxdpfad=rechts+vtz+"hfaxd";
													break;
												} // 									if (zeile.find("DIR_LIBEXEC")!=string::npos)
											} // 								while(getline(confc,zeile))
											confc.close();
										} // 							if (confc.is_open())
									} // 						if (!kompilfort(was,"",cfgbismake))
								} // !was.empty()
								// 2>/dev/null wegen tar:Schreibfehler (=> Schreibversuch durch von head geschlossene pipe)
								////					systemrueck("sh -c 'cd $("+sudc+"tar --list -f hylafax+ 2>/dev/null | head -n 1) && "
								//// hservice_faxgetty();
								//// hservice_faxq_hfaxd();
							} else {
								fLog(violetts+Tx[T_ueber_das_Installationspaket]+schwarz,1,1);
								// b) mit dem Installationspaket
								if (!linstp->obfehlt(hff) || !linstp->obfehlt(hfcf)) {
									fLog(hfftext,-1,1);
									linstp->douninst(string(hff)+" "+hfcf,obverb,oblog);
									falscheshyla=1;
								}
								//// <<"hfr: "<<violett<<hfr<<schwarz<<" hfcr: "<<violett<<hfcr<<schwarz<<" obverb: "<<(int)obverb<<endl;
								hylafehlt=linstp->obfehlt(hfr,obverb,oblog) || linstp->obfehlt(hfcr,obverb,oblog) || 
									!obprogda("faxq",obverb,oblog) || !obprogda("hfaxd",obverb,oblog) || !obprogda("faxgetty",obverb,oblog);
								yLog(obverb,oblog,0,0,"%s%s%s%d%s%s%s%d",gruen,Tx[T_hylafehlt],schwarz,hylafehlt,gruen,Txk[T_Versuch],schwarz,versuch);
								// b1) falsches Hylafax loeschen
								if (hylafehlt) {
									if (falscheshyla) {
										fLog(rots+Tx[T_Muss_falsches_hylafax_loeschen]+schwarz,1,1);
										if (0) {
											systemrueck("cd /etc/init.d"
													" && [ $(find . -maxdepth 1 -name \"*faxq*\" -or -name \"*hfaxd*\" -or -name \"hylafax*\" 2>/dev/null | wc -l) -ne 0 ]"
													" && { mkdir -p /etc/ausrangiert && mv -f *faxq* *hfaxd* hylafax* /etc/ausrangiert;}||:",-2,oblog,/*rueck=*/0,/*obsudc=*/1);
											systemrueck("cd $(dirname $(dirname $(which systemctl)))/lib/systemd/system && "
													"rm -f faxq.service hfaxd.service faxgetty*.service hylafax*.service;",-2,oblog,/*rueck=*/0,/*obsudc=*/1);
											systemrueck("cd /etc/systemd/system && rm -f faxq.service hfaxd.service faxgetty*.service;",-2,oblog,/*rueck=*/0,/*obsudc=*/1);
											for(int iru=0;iru<2;iru++) {
												string local;
												if (iru) local="local/"; else local.clear();
												systemrueck("cd /usr/"+local+"bin 2>/dev/null && "
														"rm -f faxalter faxcover faxmail faxrm faxstat sendfax sendpage;",-2,oblog,/*rueck=*/0,/*obsudc=*/1);
												systemrueck("cd /usr/"+local+"sbin 2>/dev/null && "
														"rm -f choptest cqtest dialtest edit-faxcover faxabort faxaddmodem "
														"faxadduser faxanswer faxconfig faxcron faxdeluser faxinfo faxlock faxmodem faxmsg faxq faxqclean faxquit faxsetup "
														"faxsetup.linux faxstate faxwatch probemodem rchylafax* recvstats tagtest tiffcheck tsitest typetest xferfaxstats "
														"faxsetup.bsdi faxsetup.iri faxgetty faxsend hfaxd hylafax lockname ondelay pagesend textfmt;",
														-2,oblog,/*rueck=*/0,/*obsudc=*/1);
												systemrueck("rm -rf /usr/"+local+"/lib/fax",-2,oblog,/*rueck=*/0,/*obsudc=*/1,1);
												systemrueck("rm -rf /usr/"+local+"/share/hylafax",-2,oblog,/*rueck=*/0,/*obsudc=*/1,1);
												systemrueck("rm -rf /usr/"+local+"/lib/fax",-2,oblog,/*rueck=*/0,/*obsudc=*/1,1);
												systemrueck("rm -rf /usr/"+local+"/lib/hylafax",-2,oblog,/*rueck=*/0,/*obsudc=*/1,1);
												systemrueck("rm -rf /usr/"+local+"/lib/libfax*",-2,oblog,/*rueck=*/0,/*obsudc=*/1,1);
												systemrueck("rm -rf /usr/"+local+"/lib/libhylafax*",-2,oblog,/*rueck=*/0,/*obsudc=*/1,1);
											} //                 for(int iru=0;iru<2;iru++)
											systemrueck("rm -rf /etc/hylafax",-2,oblog,/*rueck=*/0,/*obsudc=*/1,1);
											// es bleiben noch /var/log/hylafax und /var/spool/fax oder /var/spool/hylafax
										} // if (0)
									} // if falscheshyla
									// b2) richtiges Hylafax installieren
									hylafehlt=linstp->doinst(string(hfr)+" "+string(hfcr),obverb,oblog);
								} // if (hylafehlt)
							} // if (hyinstart==hysrc)  else

							// wenn sich faxsend findet ...
							if (obprogda("faxsend",obverb,oblog)) {
								// und ein hylafax-Verzeichnis da ist ...
								if (this->setzhylavz()) {
									this->obhyla=0;
									ret=1;
									break;
								} else {
									// falls oben hylafax neu installiert wurde und zuvor eine hylafax-Installation nach Gebrauch geloescht worden war,
									// dann die alten Eintraege (xferfaxlog.rpmsave) wieder aktivieren
									struct stat entryxfer={0}, entryxfer0={0};
									const string d0=xferfaxlog+".rpmsave";
									if (!lstat(xferfaxlog.c_str(),&entryxfer)) {
										if (entryxfer.st_size<10) { // wenn neu
											if (!lstat(d0.c_str(),&entryxfer0) && entryxfer0.st_size>10) {
												kopier(d0,xferfaxlog,obverb,oblog);
												////                systemrueck(sudc+"cp -a "+d0+" "+xferfaxlog,obverb,oblog);
											} else {
												if (falscheshyla)  {
													char* fspoolvz=0;
													for(unsigned iru=0;iru<sizeof this->moeglhvz/sizeof this->moeglhvz;iru++) {
														if (this->moeglhvz[iru]!=this->varsphylavz) {
															fspoolvz=(char*)this->moeglhvz[iru];
															break;
														} // if (this->moeglhvz[iru]
													} // for(unsigned iru=0
													if (fspoolvz) {
														/*
															 wenn /var/spool/hylafax/etc/xferfaxlog 1 Byte hat und /var/spool/fax/etc/xferfaxlog mehr dann kopieren:
															 etc/xferfaxlog sendq recvq log doneq docq archive
														 */
														/*// // muss noch getestet werden
															systemrueck(("cp ")+fspoolvz+"/etc/xferfaxlog "+this->varsphylavz+"/etc/",obverb,oblog);
															systemrueck(("cp ")+fspoolvz+"/sendq "+this->varsphylavz+"/",obverb,oblog);
															systemrueck(("cp ")+fspoolvz+"/recvq "+this->varsphylavz+"/",obverb,oblog);
															systemrueck(("cp ")+fspoolvz+"/log "+this->varsphylavz+"/",obverb,oblog);
															systemrueck(("cp ")+fspoolvz+"/doneq "+this->varsphylavz+"/",obverb,oblog);
															systemrueck(("cp ")+fspoolvz+"/docq "+this->varsphylavz+"/",obverb,oblog);
															systemrueck(("cp ")+fspoolvz+"/archive "+this->varsphylavz+"/",obverb,oblog);
														 */
													}
												} // if (falscheshyla)
											} // !lstat(d0.c_str()
										} // if (entryfer.st_size<10

									} // if (!lstat(xferfaxlog.c_str(),&entryxfer)) 
									// bei hysrc ist das Folgende wohl eigentlich nicht noetig
									// Berechtigungen korrigieren
									useruucp(huser,obverb,oblog);
									systemrueck("chown "+huser+":uucp -R "+this->varsphylavz,obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
								} // 							if (this->setzhylavz())
							} // if (obprogda("faxsend",obverb,oblog))
							/*//
								fLog(string(Tx[T_StarteHylafax]),1,oblog);
							//      if (hyinstart==hypak) hylalaeuftnicht=hservice_faxq_hfaxd();
							<<"hylafehlt: "<<(int)hylafehlt<<endl;
							if (0) {
							if (hylafehlt || versuch) {
							//        fLog(string(Tx[(T_)T_Installation_von_Hylafax_nicht_feststellbar_versuche_es_zu_installieren]),-2,1);

							//        string cmd("which zypper 2>/dev/null && zypper -n in hylafax hylafax-client || "
							//        "KLA which apt-get 2>/dev/null && apt-get -y install hylafax-server hylafax-client; KLZ; systemctl daemon-reload; ");
							//        hylafehlt=systemrueck(cmd,1+obverb,oblog,0,wahr,wahr,Tx[T_hylafax_faxmodem_nicht_gefunden_Versuche_es_zu_installieren_mit]); 

							}
							// falls ja, dann starten (falls erst installiert werden muss, dann bei versuch==1
							} // if (0)
							 */
						} // if (hylafehlt)
						int fglaeuftnicht=0;
						for (uchar iru=0;iru<3;iru++) {
							//// <<violett<<"pruefhyla 2"<<schwarz<<endl;
							if ((fglaeuftnicht=sfaxgetty->obsvfeh(obverb,oblog))) {
								// falls nein, dann schauen, ob startbar
								if (sfaxgetty->machfit(obverb,oblog)) fglaeuftnicht=0;
							}
							//// <<rot<<" fglaueftnicht: "<<fglaeuftnicht<<", hmodem: "<<hmodem<<schwarz<<endl;
							string pfad;
							if (obprogda("faxstat",obverb,oblog,&pfad)) {
								modemlaeuftnicht=1+fglaeuftnicht;
								svec rueck;
								systemrueck(pfad+" 2>&1",obverb,oblog,&rueck,/*obsudc=*/1);
								for(size_t ruei=0;ruei<rueck.size();ruei++) {
									if (!aru) {
										if (!ruei && rueck[0].find("no version information")!=string::npos) {
											nochmal=1;
											//// <<violett<<rueck[0]<<schwarz<<endl;
											reduzierlibtiff();
											hylafehlt=1;
											break;
										}
									} // 									if (!aru)
									if (rueck[ruei].find(this->hmodem)!=string::npos) {
										modemlaeuftnicht--;
										break;
									}
////								modemlaeuftnicht=systemrueck(pfad+"|grep "+this->hmodem+" 2>&1",obverb,oblog,/*rueck=*/0,/*obsudc=*/1)+fglaeuftnicht;
								} // 								for(size_t ruei=0;ruei<rueck.size();ruei++)
								if (nochmal) break;
							} // 							if (obprogda("faxstat",obverb,oblog,&pfad))
							////        if (!modemlaeuftnicht) break;
							////  <<rot<<" hyinstart: "<<(int)hyinstart<<", modemlaeuftnicht: "<<(int)modemlaeuftnicht<<schwarz<<endl;
							////  <<rot<<" hylalaueftnicht: "<<(int)hylalaeuftnicht<<schwarz<<endl;
							if (hyinstart==hypak || hyinstart==hysrc || hyinstart==hyppk) {
								//// if (0)
								hylalaeuftnicht=hservice_faxq_hfaxd()+fglaeuftnicht;
							}
							////  <<rot<<" hylalaueftnicht: "<<(int)hylalaeuftnicht<<schwarz<<endl;
							if (!hylalaeuftnicht && !modemlaeuftnicht) break;
							if (iru>1) {
								systemrueck("chmod 660 "+this->varsphylavz+"/FIFO*",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
								if (hconfig()) continue;
								hconfigtty();
								frischkonfiguriert=1;
							}
							if (!iru) {
								//// <<rot<<"hier faxsetup!"<<endl;
								hfaxsetup();
								//// if (0)
								//// hservice_faxgetty();
							}
						} // for (uchar iru=0;iru<3;iru++)
						if (nochmal) continue;
						break;
					}
					if (ret) break;
					// wenn !hylazukonf, dann auslesen, mit den Werten vergleichen und ggf. zu 1 setzen
					if (!hylazukonf) {
						hliesconf();
					}
					//// <<rot<<"fglaeuftincht: "<<(int)fglaeuftnicht<<", modemlaeuftnicht: "<<(int)modemlaeuftnicht<<", hylalaeuftnicht: "<<(int)hylalaeuftnicht<<schwarz<<endl;
					//// if (!hylalaeuftnicht && !modemlaeuftnicht) break;
					////          cmd=string("zypper -n in uucp"); // fuer cu
					////          systemrueck(cmd,1,1,0,wahr,wahr,"installiere cu"); 
					////          cmd=string("usermod -a -G dialout root");
					////          systemrueck(cmd,1,1,0,wahr,wahr,"berechtige mich"); 
					////          cmd=string("chmod 666 ")+this->hmodem;
					////          systemrueck(cmd,1,1,0,wahr,wahr,"berechtige mich"); 
					if (this->hylazukonf && !frischkonfiguriert) {
						////    hconfig(this,obverb,oblog); // countrycode, citycode/areacode, longdistancepraefix, internationalprefix
						if (!frischkonfiguriert) {
							// dieser Aufruf geschieht z.B. nach Parameter -hkzl 7
							hconfigtty();
						}
						if (sfaxgetty) sfaxgetty->stopdis(obverb,oblog,1);
						if (shfaxd) shfaxd->stop(obverb,oblog,1);
						if (sfaxq) sfaxq->stop(obverb,oblog,1);
						if (shylafaxd) shylafaxd->stopdis(obverb>1?obverb:0,oblog,1);
						/*//
							if (!systemrueck(sudc+"systemctl stop '"+this->sfaxgetty->sname+"' '"+this->shfaxd->sname+"' '"+this->sfaxq->sname+"' 2>/dev/null",
							obverb,oblog)) KLA
							systemrueck(sudc+"systemctl stop hylafax 2>/dev/null",obverb-2,oblog);
							systemrueck(sudc+"systemctl disable hylafax 2>/dev/null",obverb-2,oblog);
							systemrueck(string(sudc+"pkill ")+sfaxgetty->ename+" "+shfaxd->ename+" "+sfaxq->ename+" >/dev/null 2>&1",obverb-2,oblog);
							KLZ 
						// if (!systemrueck(string(sudc+"systemctl stop ")+this->sfaxgetty->sname+" "+this->shfaxd->sname+" "+this->sfaxq->sname,obverb,oblog)) 
						 */
						if (sfaxgetty->startundenable(obverb,oblog) &&  shfaxd->startundenable(obverb,oblog) && sfaxq->startundenable(obverb,oblog)) {
							this->hylazukonf=0;
						} // if (!systemrueck(string(sudc+"systemctl start ")+this->sfaxgetty->sname+" "+this->shfaxd->sname+" "+this->sfaxq->sname,obverb,oblog)) 
					} // if (this->hylazukonf && !frischkonfiguriert) 
					//// systemrueck("grep -rl 'faxcron\\|faxqclean' /etc/cron* | /usr/bin/xargs ls -l;",obverb,oblog); 
					// // in hylafax: /etc/cron.daily/suse.de-faxcron, 
					////     break; // zu Testzwecken
					if (hylalaeuftnicht || modemlaeuftnicht) {
						// hier Fehler: nach einem Versuch darf 
						if (versuch) {
							if (this->konfobhyla) this->hylazukonf=1;
						}
						if (versuch>1) {
							fLog(Tx[T_hylafaxspringtnichtan],1,1);
							this->obhyla=0;
							ret=1;
							break;
						} //         if (versuch>1) 
					} else {
						break;
					} // if (hylalaeuftnicht || modemlaeuftnicht) 
				} // for(unsigned versuch=0;versuch<2;versuch++)
				if (ret) break;
				// Empfangsberechtigungen sicherstellen
				////		char *uvz[2]={(char*)"/log/",(char*)"/recvq/"};
				const string uvz[2]{"/log/","/recvq/"};
				for (unsigned i=0;i<2;i++) {
					const string dt=varsphylavz+uvz[i]+"seqf";
					struct stat dstat={0};
					if (lstat(dt.c_str(),&dstat)) {
						useruucp(huser,obverb,oblog);
						systemrueck("touch "+dt+" && chown "+huser+":uucp "+dt,obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
					} // 		 if (lstat(dt.c_str(),&dstat))
				} // 		for (unsigned i=0;i<2;i++)
////				systemrueck("V="+varsphylavz+";L=\\$V/log;R=\\$V/recvq;chmod 774 \\$L \\$R;chmod 660 \\$L/seqf \\$R/seqf", obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
				systemrueck("V="+varsphylavz+";L=$V/log;R=$V/recvq;chmod 774 $L $R;chmod 660 $L/seqf $R/seqf", obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
				// Archivierung ggf. aktivieren
				if (!hylalaeuftnicht) {
					const string hour="/etc/cron.hourly", fc="faxqclean";
					//// das Folgende fuehrt zu einer Bildschirmmeldung mit *, wenn Verzeichnis leer 
					////struct stat hfstat={0};
					////if (!lstat(hour.c_str(),&hfstat)) {
					////systemrueck(sudc+"sh -c \"for D in "+hour+"/*;do grep -q '"+fc+" *$' \\$D&&sed -i 's/"+fc+" *$/"+fc+" -a -A/g' \\$D||true;done\"",obverb,oblog);
					////} // 			if (!lstat(hour.c_str(),&hfstat))
					svec qrueck;
					if (findv==1) {
						systemrueck("find "+hour+" -type f -exec grep -l \""+fc+" *$\" {} \\; 2>/dev/null", obverb,oblog,&qrueck,/*obsudc=*/1);
					} else {
						findfile(&qrueck,findv,obverb,oblog,0,hour,/*muster=*/"",-1,33,7);
						regex_t reg;
						uchar noreg=0;
						if (regcomp(&reg, (fc+" *$").c_str(), REG_EXTENDED | REG_NOSUB)) noreg=1;
						for(size_t i=qrueck.size();i;) {
							i--;
							uchar gef=0;
							mdatei qr(qrueck[i],ios::in);
							if (qr.is_open()) {
								string zeile;
								while(getline(qr,zeile)) {
									if (noreg) {
										if (zeile.find(fc+"\\n")!=string::npos){gef=1;break;}
									} else {
										if (!regexec(&reg, zeile.c_str(), 0, 0, 0)) {gef=1;break;}
									}
								} // 								while(getline(qr,zeile))
								qr.close();
								if (!gef) qrueck.erase(qrueck.begin()+i);
							} // 							if (qr.is_open())
						} // 						for(size_t i=qrueck.size();i;)
					} // 					if (findv==1) else
					for(size_t i=0;i<qrueck.size();i++) {
						systemrueck("sed -i 's/"+fc+" *$/"+fc+" -a -A/g' "+qrueck[i]+"||:;",obverb,oblog,/*rueck=*/0,/*obsudc=*/1);
					}
					/*//
						if (!lstat("/etc/cron.hourly/hylafax",&hfstat)) KLA
						systemrueck("!"+sudc+"grep -q 'faxqclean *$' /etc/cron.hourly/hylafax || "sudc+"sed -i 's/faxqclean *$/faxqclean -a -A/g' /etc/cron.hourly/hylafax", obverb,oblog); // keine Sicherungskopie, sonst ausgefuehrt
						KLZ // 			if (!lstat("/etc/cron.hourly/hylafax",&hfstat))
					 */
				} //     if (!hylalaeuftnicht)
			} else {
				if (sfaxgetty) sfaxgetty->stopdis(obverb,oblog);
				if (shfaxd) shfaxd->stopdis(obverb,oblog);
				if (sfaxq) sfaxq->stopdis(obverb,oblog);
				if (shylafaxd) shylafaxd->stopdis(obverb>1?obverb:0,oblog);
				ret=1;
			} // (obhyla) else
			hLog(violetts+Txk[T_Ende]+Tx[T_pruefhyla]+schwarz);
		} // 	if (hmodem.empty()) else
	} while (0); // fuer break
	return ret;
} // int hhcl::pruefhyla()


// augerufen in: main
void hhcl::dovh()
{
	// muss nach setzhylavz kommen
	pruefhyla();
	string zeig;
	cmd=edit;
	viadd(&cmd,&zeig,modconfdt);
	viadd(&cmd,&zeig,varsphylavz+"/etc/config");
	if (sfaxgetty) viadd(&cmd,&zeig,sfaxgetty->systemd);
	if (shfaxd) viadd(&cmd,&zeig,shfaxd->systemd);
	if (sfaxq) viadd(&cmd,&zeig,sfaxq->systemd);
	if (shylafaxd) viadd(&cmd,&zeig,shylafaxd->systemd);
	if (initdhyladt_gibts) viadd(&cmd,&zeig,initdhyladt);
	string erg;
	viadd(&erg,&zeig,xferfaxlog,1,0,1);
	vischluss(erg,zeig);
} // void hhcl::dovh()


// wird aufgerufen in lauf
void hhcl::virtpruefweiteres()
{ //ω
	setzhylavz();
	if (obvh) dovh();
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
 
// wird aufgerufen in: main
void hhcl::virtautokonfschreib()
{
// const int altobverb=obverb;
// obverb=1;
	hLog(violetts+Txk[T_autokonfschreib]+schwarz+", "+Txk[T_zu_schreiben]+((rzf||hccd.obzuschreib)?Txk[T_ja]:Txk[T_nein]));
	/*//
		capizukonf und hylazukonf hier immer 0
		char buf[200];
		sprintf(buf,"rzf: %d, capizukonf: %d, hylazukonf: %d, obzuschreib: %d",(int)rzf, (int)capizukonf, (int)hylazukonf, (int)obzuschreib);
		hLog(blaus+buf+schwarz);
	 */
	struct stat kstat={0};
	if (lstat(akonfdt.c_str(),&kstat))
		hccd.obzuschreib=1;
	if (rzf||hccd.obzuschreib) {
		fLog(gruens+Tx[T_schreibe_Konfiguration]+schwarz,obverb);
		// restliche Erklaerungen festlegen
		////    agcnfA.setzbem("language",sprachstr);
		hcl::virtautokonfschreib(); //ω
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
	} // if (rzf||hccd.obzuschreib) //α
// obverb=altobverb;
} // void hhcl::virtautokonfschreib

hhcl::~hhcl() 
{ //ω
	if (cfaxcp) { 
		delete cfaxcp; 
		cfaxcp=0; 
	}
} //α

// wird nur im Fall obhilfe==3 nicht aufgerufen
void hhcl::virtlieskonfein()
{
	const int altobverb=obverb;
	//	obverb=1;
	hLog(violetts+Txk[T_virtlieskonfein]+schwarz);
	hcl::virtlieskonfein(); //ω
	// sqlzn und zmzn aus den Konfigurationsdateien ermitteln (um sie nicht dort speichern zu muessen)
	sqlzn=0;
	zmzn=0;
	for(size_t nr=0;nr<hccd.paare.size();nr++) {
		if  (!hccd.paare[nr].name.find(cSQL_)) {
			unsigned long neusqlzn=atol(hccd.paare[nr].name.substr(cSQL_.length()).c_str());
			if (neusqlzn>sqlzn) sqlzn=neusqlzn;
		} else if  (!hccd.paare[nr].name.find(cZMMuster_)) {
			unsigned long neuzmzn=atol(hccd.paare[nr].name.substr(cZMMuster_.length()).c_str());
			if (neuzmzn>zmzn) zmzn=neuzmzn;
		} else if  (!hccd.paare[nr].name.find(cZMZiel_)) {
			unsigned long neuzmzn=atol(hccd.paare[nr].name.substr(cZMZiel_.length()).c_str());
			if (neuzmzn>zmzn) zmzn=neuzmzn;
		}
////		caus<<"Nr."<<nr<<", Name: "<<blau<<hccd.paare[nr].name<<schwarz<<", Wert: "<<violett<<hccd.paare[nr].wert<<schwarz<<endl;
	}
	sqlz0=opn.size();
	if (sqlzn) {
		// wenn SQL-Befehle aus Konfigurkationsdatei geholt
		delete[] sqlp;
		sqlp=new string[sqlzn]{string()};
		schAcl<optcl> opsql=schAcl<optcl>("opsql");
		for(size_t i=0;i<sqlzn;) {
			++i;
			stringstream soptname;
			soptname<<cSQL_<<i;
			opsql<<new optcl(/*pname*/soptname.str(),/*pptr*/&sqlp[i-1],/*art*/pstri,-1,-1,/*TxBp*/&Tx,/*Txi*/T_SQL_Befehl_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/ltoan(i),/*wert*/-1,/*woher*/2);
			//// folgendes wuerde zum Absturz fuehren (der shared_ptr muss derselbe sein, damit er und sein Inhalt nur einmal versucht wird zu destruieren):
			////		shared_ptr<optcl> kop2{opsql[opsql.size()-1]};
			////		opn<<kop2;
		} // 	for(long i=0;i<sqlzn;)
		// ggf. die Zahlenreichenfolgen neu festlegen, z.B. durch direkte Bearbeitung der Konfigurationsdatei entstandene Luecken schliessen
		hccd.kauswert(&opsql,obverb,/*mitclear*/0);
		sqlzn=0;
		for(auto aktopsql:opsql.schl) {
			if (!((string*)aktopsql->pptr)->empty()) {
				stringstream soptname;
				soptname<<cSQL_<<++sqlzn;
				aktopsql->pname=soptname.str();
				opn<<aktopsql;
			}
		} // 		for(auto aktopsql:opsql.schl)
		//// opn.oausgeb(rot);
	} // if (sqlzn)
	// wenn in der Konfigurationsdatei keine sql-Befehle stehen, dann die aus den Vorgaben nehmen
	if (!sqlzn) {
		sqlzn=sqlvzn;
		delete[] sqlp;
		sqlp=new string[sqlzn];
//		opn.omap["sqlz"]->woher=1;
		for(size_t i=0;i<sqlzn;i++) {
			sqlp[i]=*(string*)opvsql[i]->pptr;
			//// <<"opvsql["<<i<<"]: "<<*(string*)opvsql[i]->pptr<<endl;
			opn<<opvsql[i];
		}
	} // 	if (!sqlzn)

	zmsp.clear();
	if (zmzn) {
////		caus<<blau<<"opzm.size(): "<<violett<<opzm.size()<<schwarz<<endl;
//		opn.omap["musterzahl"]->woher=2;
		schAcl<optcl> opzm=schAcl<optcl>("opzm");
		delete[] zmmp;
		zmmp=new string[zmzn];
		delete[] zmzp;
		zmzp=new string[zmzn];
		for(size_t i=0;i<zmzn;) {
			++i;
			stringstream zmmname,zmzname;
			zmmname<<cZMMuster_<<i;
			zmzname<<cZMZiel_<<i;
			////	  const string *const istrp=new string(ltoan(i));	
			string istr=ltoan(i);
			opzm<<new optcl(/*pname*/zmmname.str(),/*pptr*/&zmmp[i-1],/*art*/pstri,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Zielmuster_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/2);
			opzm<<new optcl(/*pname*/zmzname.str(),/*pptr*/&zmzp[i-1],/*art*/pstri,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Ziel_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/2);
			//// caus<<"opn.schl.size(): "<<opn.schl.size()<<", omap.size(): "<<opn.omap.size()<<endl;
		} // 	for(long i=0;i<zmzn;)
		////		caus<<blau<<"opzm.size(): "<<violett<<opzm.size()<<schwarz<<endl;
		////		caus<<blau<<"opn.size(): "<<violett<<opn.size()<<schwarz<<endl;
		hccd.kauswert(&opzm,obverb,/*mitclear*/0);
////		opzm.oausgeb(rot);
		zmz0=opn.size();
		zmzn=0;
		shared_ptr<optcl> laktopzm=0;
		for(auto aktopzm:opzm.schl) {
			if (laktopzm) {
				// jeden 2. Durchgang auswerten: aktopzm=Ziel, laktopzm=Muster
				if (!((string*)aktopzm->pptr)->empty()) {
					stringstream zmmname,zmzname;
					zmmname<<cZMMuster_<<++zmzn;
					laktopzm->pname=zmmname.str();
					opn<<laktopzm;
					zmzname<<cZMZiel_<<zmzn;
					aktopzm->pname=zmzname.str();
					opn<<aktopzm;
					zmsp.push_back(shared_ptr<zielmustercl>(new zielmustercl(*(string*)laktopzm->pptr,*(string*)aktopzm->pptr)));
				}
				laktopzm=0;
			} else {
				laktopzm=aktopzm;
			}
		} // 		for(auto aktopzm:opzm.schl)
		//		opn.gibaus(1);
		//		opzm.~schAcl();
////		caus<<"zmznneu: "<<zmznneu<<endl;
////		for(size_t i=0;i<zmznneu;i++) caus<<"i: "<<i<<", zmsp[i].muster: "<<zmsp[i]->holmuster()<<", zmsp[i].ziel: "<<zmsp[i]->holziel()<<endl;

	} // 	if (zmzn)
	if (!zmzn) {
		// wenn in der Konfigurationsdatei keine Zielmuster stehen
		zmzn=zmvzn;
		//		opn.omap["musterzahl"]->woher=1;
		for(size_t i=0;i<zmvzn+zmvzn;i++) {
			opn<<opvzm[i];
      if (i%2==1) {
				zmsp.push_back(shared_ptr<zielmustercl>(new zielmustercl(*(string*)opvzm[i-1]->pptr,*(string*)opvzm[i]->pptr)));
			}
		} // 		for(long i=0;i<zmzn;i++) 
	} // 	if (!zmzn)
	////	opn.oausgeb(rot);
	////	opn.gibomapaus();
	hLog(violetts+Txk[T_Ende]+Txk[T_virtlieskonfein]+schwarz); //α
	obverb=altobverb;
} // void hhcl::virtlieskonfein()

int main(int argc,char** argv)
{
	if (argc>1) { //ω
	} //α
	hhcl hhi(argc,argv); // hiesige Hauptinstanz, mit lngzuw, setzlog und pruefplatte
	hhi.lauf(); // Einleitungsteil mit virtuellen Funktionen, 
	// mit virtVorgbAllg,pvirtVorgbSpeziell,initopt,parsecl,pvirtmacherkl,zeighilfe,virtlieskonfein,verarbeitkonf,lieszaehlerein,MusterVorgb,dovi,dovs,virtzeigversion
	// virtautokonfschreib,update,
} // int main 

void hhcl::virttesterg()
{
} //ω

