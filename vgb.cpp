#include "kons.h"
#include "DB.h"
#include "autofax2.h"

enum Txvg_ {
  T_VorgbSpeziell_Ueberlad,
  T_vgMAX,
};

/*
class Txvgcl: public TxB
{
  public:
    static const char *TextC[][SprachZahl];
    Txvgcl() {TCp=(const char* const * const * const *)&TextC;}
};
*/

// const char *Txvgcl::TextC[T_vgMAX+1][SprachZahl]={
const char *vgb_T[T_vgMAX+1][SprachZahl]={
      // T_VorgbSpeziell_Ueberlad
      {"VorgbSpeziell_Ueberlad()","specificprefs_overload()"},
      {"",""}
}; // const char *Txvgcl::TextC[T_vgMAX+1][SprachZahl]=

// class Txvgcl Txv;
class TxB Txv((const char* const* const* const*)vgb_T);

void hhcl::pvirtVorgbSpeziell()
{
  Log(violetts+Txv[T_VorgbSpeziell_Ueberlad]+schwarz);
  //  langu="d"; lgnzuw();
  dbq="faxeinp";
  citycode="8131";
  msn="616381";
  LocalIdentifier="DiabDachau";
  cFaxUeberschrift="Diabetologie Dachau";
	obfbox=1;
	fbankvz="/mnt/diabfb/Generic-FlashDisk-01/FRITZ/faxbox";
	obcapi=1;
	obhyla=1;
	hylazuerst=0;
	hmodem="ttyACM0";
	cuser="schade";
	gleichziel=1;
	obocri=1;
	obocra=0;
	findvers="3";
	muser="praxis";
	mpwd="sonne";

  // wird schon fuer systemrueck benoetigt
  const char *const hatab = "haerzte_neu",
        *officetab = "office",
        *quelltab = "quelle",
        *kvaetab  = "kvaerzte";
  sqlvz="7";
  sqlvzn=atol(sqlvz.c_str());
	sqlvp=new string[sqlvzn];
	for(size_t i=0;i<sqlvzn;) {
      switch (i) {
        case 0:
          sqlvp[i] = string("")+"select if(isnull(arzt),bsname,arzt) getName,bsname from (select bsname, FaxZahl, "
            "concat(group_concat(distinct Arzt separator ', '), ', ',ort,';') Arzt "
            "from (SELECT bs.name bsname, f.faxzahl, concat(if(instr(Titel,'.')<>0,concat(left(titel,instr(titel,'.')),' '),Titel), "
            "left(a.Vorname,1), '.', a.Nachname, if(count(a.nachname)>6,'',concat(' (',group_concat(distinct "
            "replace(replace(replace(replace(replace(replace(replace(replace(replace(replace(replace(replace(replace(replace(replace(replace(replace"
            "(replace(replace(replace(replace(replace(replace(replace(replace(replace(if(isnull(fachrichtung),'',fachrichtung),"
            "'Facharzt für ','FA f.'),'Fachärztin für ','FÄ f.'),'Schwerpunkt',''),'edizin','ed.'),'Allgemeinmed.','Allgm.'),"
            "'therapeutische','th.'),'ologie','ol.'),'therapeutin','th.'),'therapeut','th.'),'heilkunde','hk.'),'therapie','th.'),"
            "'irurgie','ir.'),'pädie','p.'),'Jugendlichen','Jugdl.'),'Innere ','In.'),'krankheiten','krht.'),'hilfe','h.'),"
            "'Praktischer Arzt','Prakt.A.'),'Praktische Ärztin','Prakt.Ä.'),'Diagnostische ','diagn.'),'ologe','ol.'),"
            "'Hals-Nasen-Ohrenhk.','HNO'),'ologische ','ol.'),'ologischer ','ol.'),'istische','ist.'),'und ','u.') separator ', '),')'))) Arzt, "
            "ort.Ort "
            "from `"+hatab+"`.fax f left join `"+hatab+"`.arzt_has_bs ahb on f.bs_id = ahb.bs_id "
            "left join `"+hatab+"`.bs on f.bs_id = bs.idbs "
            "left join `"+hatab+"`.arzt a on ahb.arzt_id = a.idarzt "
            "left join `"+hatab+"`.arzt_has_fachrichtung ahf on ahb.arzt_id = ahf.arzt_id "
            "left join `"+hatab+"`.fachrichtung fr on ahf.fachrichtung_id = fr.idfachrichtung "
            "left join `"+hatab+"`.ort on bs.ort_id = ort.idort "
            "left join `"+hatab+"`.titel t on a.titel_id = t.idtitel "
						"where concat(if(instr('12345678',mid(faxzahl,1,1)) and not (length(faxzahl)>8),'08131',''),"
            "replace(replace(replace(replace(faxzahl,' ',''),'-',''),'/',''),'\\'','')) = '&&faxnr&&' "
            "group by faxzahl, nachname, vorname) i) i group by FaxZahl";
          break;
        case 1:
          sqlvp[i] = string("")+"select concat(titel,if(titel='','',' '),vorname,' ',nvorsatz,if(nvorsatz='','',' '),nachname,', g.',"
            "date_format(gebdat,'%d.%m.%y'),', ',ort) name,concat('Pid ',pat_id) bsname from "+quelltab+".namen n where "
            "concat(if(instr('12345678',mid(privatfax,1,1)) and not (length(privatfax)>8),'08131',''),"
						"replace(replace(replace(replace(privatfax,' ',''),'-',''),'/',''),"
            "'\\'','')) = '&&faxnr&&'";;
          break;
        case 2:
          sqlvp[i] = string("")+"select concat(haname,', ',ort,', ',kvnu) name, zulg,fax1k from "+kvaetab+".hae where "
            "concat(if(instr('12345678',mid(fax1k,1,1)) and not (length(fax1k)>8),'08131',''),"
						"replace(replace(replace(replace(fax1k,' ',''),'-',''),'/',''),'\\'','')) = " 
            "'&&faxnr&&'";
          break;
        case 3:
          sqlvp[i] = string("")+"select concat(titel,if(titel='','',' '),vorname,' ',name,', ',ort) name, zusatzfeld5 from "+
            officetab+".adresse where concat(if(instr('12345678',mid(faxk,1,1)) and not (length(faxk)>8),'08131',''),"
						"replace(replace(replace(replace(faxk,' ',''),'-',''),'/',''),'\\'',''))"
            " = '&&faxnr&&' order by zusatzfeld5 desc";
          break;
        case 4:
          sqlvp[i] = string("")+"SELECT concat(if(isnull(name),'',concat(titel,if(titel='','',' '),vorname,' ',name,', ',ort, ', ')),"
            "if(isnull(i.firma),'',i.firma)) name, i.abteilung FROM "+officetab+".telefon t left join "+officetab+".kontakte k "
            "on t.knr  = k.knr left join "+officetab+".pers p on k.knr = p.knr left join "+officetab+".inst i on k.knr = i.knr left join "+
            officetab+".anschr a on a.knr = p.knr where concat(if(instr('12345678',mid(num,1,1)) and not (length(num)>8),'08131',''),"
            "replace(replace(replace(replace(num,' ',''),'-',''),'/',''),'\\'',''))  = '&&faxnr&&' and (not isnull(name) "
            "or not isnull(firma) or not isnull(vorname)) order by name desc, vorname desc, firma desc";
          break;
        case 5:
          sqlvp[i] = string("")+"select concat(titel,if(titel='','',' '),vorname,' ',nvorsatz,if(nvorsatz='','',' '),"
            "nachname,', g.',date_format(gebdat,'%d.%m.%y'),', ',ort) name,concat('Pid ',pat_id) bsname from "+quelltab+".namen n where "
            "concat(if(instr('12345678',mid(privattel,1,1)) and not (length(privattel)>8),'08131',''),"
						"replace(replace(replace(replace(privattel,' ',''),'-',''),'/',''),'\\'','')) = "
            "'&&faxnr&&'";
          break;
        case 6:
          sqlvp[i] = string("")+"select concat(titel,if(titel='','',' '),vorname,' ',name) name,fachgruppe from "+quelltab+
            ".listenausgabeuew where concat(if(instr('12345678',mid(fax,1,1)) and not (length(fax)>8),'08131',''),"
						"replace(replace(replace(replace(fax,' ',''),'-',''),'/',''),'\\'','')) "
            "= '&&faxnr&&'";
          break;
      }
		++i;
		stringstream soptname;
		soptname<<"SQL_"<<i;
		const string istr=ltoan(i);
		opvsql<<new optcl(/*pname*/soptname.str(),/*pptr*/&sqlvp[i-1],/*art*/pstri,-1,-1,/*TxBp*/&Tx,/*Txi*/T_SQL_Befehl_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/1);
	} // 	for(long i=0;i<sqlzn;)
  // cpt in virtVorgbAllg festgelegt
  if (strstr(cpt,"linux")){
//  host="localhost"; // 'localhost' schon Vorgabe bei Definition
    if (!strcmp(cpt,"linux2")) {
      zufaxenvz="/var/autofax/zufaxenvz"; 
      wvz="/var/autofax/warteauffax";
      ngvz="/var/autofax/nichtgefaxt";
      empfvz="/var/autofax";
    } else {
      zufaxenvz="/DATA/Patientendokumente/zufaxen";
      wvz="/DATA/Patientendokumente/warteauffax";
      ngvz="/DATA/Patientendokumente/nichtgefaxt";
      empfvz="/DATA/Patientendokumente";
    }
  } else {
  }
  if (strstr(cpt,"linux")){
    if (!strcmp(cpt,"linux2")) {
      static zielmustercl zmi[]={zielmustercl("[Aa]rztbrief","/vista/P"),zielmustercl("","/vista/P/gefaxt")};
      zmvp=zmi;
      zmvzn=sizeof zmi/sizeof *zmi;
    } else { // linux1
			static zielmustercl zmi[]={zielmustercl("[Aa]rztbrief","/DATA/Patientendokumente"),zielmustercl("","/DATA/Patientendokumente/gefaxt")};
			zmvp=zmi;
			zmvzn=sizeof zmi/sizeof *zmi;
		}
		for(size_t i=0;i<zmvzn;) {
			++i;
			stringstream zmmname,zmzname;
			zmmname<<"ZMMuster_"<<i;
			zmzname<<"ZMZiel_"<<i;
			const string istr=ltoan(i);
			opvzm<<new optcl(/*pname*/zmmname.str(),/*pptr*/&zmvp[i-1].muster,/*part*/pstri,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Zielmuster_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/1);
			opvzm<<new optcl(/*pname*/zmzname.str(),/*pptr*/&zmvp[i-1].ziel,/*part*/pstri,-1,-1,/*TxBp*/&Tx,/*Txi*/T_Ziel_Nr,/*wi*/0,/*Txi2*/-1,/*rottxt*/istr,/*wert*/-1,/*woher*/1);
		}
	} else {
	}
  Log(violetts+Txk[T_Ende]+Txv[T_VorgbSpeziell_Ueberlad]+schwarz);
} // void hhcl::VorgbSpeziell()

