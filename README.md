<h3>Manual: 1) <a href="#english_E">english</a>, 2) <a href="#deutsch_D">deutsch (unten anschließend)</a></h3>

<h1 align="center">AUTOFAX2 (Version 0.1167) - english<a name="english_D"></a></h1>

<a href="#NAME_D">NAME</a><br>
<a href="#SYNOPSIS_D">SYNOPSIS</a><br>
<a href="#SHORT DESCRIPTION_D">SHORT DESCRIPTION</a><br>
<a href="#INSTALLATION_D">INSTALLATION</a><br>
<a href="#USAGE_D">USAGE</a><br>
<a href="#OPTIONS_D">OPTIONS</a><br>
<a href="#PRECONDITIONS_D">PRECONDITIONS</a><br>

<hr>


<h2>NAME
<a name="NAME_D"></a>
</h2>


<p style="margin-left:11%; margin-top: 1em"><b>autofax2
&minus; Fax server functionality</b>: induces automatic fax
transmission of files, naming of received faxes and logging
of all of them in a database <br>
(manpage-Hilfe in deutsch verf&uuml;gbar: &rsquo;man
autofax2&rsquo; oder &rsquo;man -Lde autofax2&rsquo;)</p>

<h2>SYNOPSIS
<a name="SYNOPSIS_D"></a>
</h2>


<p style="margin-left:11%; margin-top: 1em"><b>autofax2
[-&lt;shortopt&gt;|--&lt;longopt&gt; [&lt;supplement&gt;]]
...</b></p>

<h2>SHORT DESCRIPTION
<a name="SHORT DESCRIPTION_D"></a>
</h2>


<h2>INSTALLATION
<a name="INSTALLATION_D"></a>
</h2>


<h2>USAGE
<a name="USAGE_D"></a>
</h2>


<h2>OPTIONS
<a name="OPTIONS_D"></a>
</h2>


<h2>PRECONDITIONS
<a name="PRECONDITIONS_D"></a>
</h2>


<p style="margin-left:11%; margin-top: 1em">Programm:
<b>/root/autofax2/autofax2</b>, V: <b>0.11670</b> Verwende:
<b>Fritzbox</b>, <b>Capisuite</b>, <b>Hylafax <br>
Options which are not saved (current value in parentheses):
<br>
-delf, --deletefax</b>: delete a fax with query (<b>0</b>)
<b><br>
-delo, --deleteorphans</b>: delete entries from
&lsquo;<b>spool</b>&lsquo; without detection of file in
waiting directory or capisuite fax or hylafax (<b>0</b>)
<b><br>
-dela, --deleteallwaiting</b>: delete all waiting faxes and
associated entries from &lsquo;<b>spool</b>&lsquo;
(<b>0</b>) <b><br>
-again, --receiveagain</b>: present a received fax again
(<b>0</b>) <b><br>
-red, --redirect</b>: redirect outgoing fax ahead by the
other channel (<b>0</b>) <b><br>
-csf, --correctsuccessflag</b>: in the database table
&lsquo;<b>outa</b>&lsquo; the success flag is being
corrected (<b>0</b>) <b><br>
-rod, --reorderdir</b>: Examine files in waiting,failed
a.faxed directory against the tables
&lsquo;<b>outa</b>&lsquo; and put them to order (<b>0</b>)
<b><br>
-st, --stop</b>: stop autofax2 (<b>0</b>) <b><br>
-listo, --listoutg</b>: lists entries from
&lsquo;<b>outa</b>&lsquo; with success flag (<b>0</b>)
<b><br>
-listf, --listfailed</b>: lists entries from
&lsquo;<b>outa</b>&lsquo; without success flag (<b>0</b>)
<b><br>
-listi, --listinca</b>: lists entries from
&lsquo;<b>inca</b>&lsquo; (<b>0</b>) <b><br>
-listw, --listwaiting</b>: lists waiting faxes (<b>0</b>)
<b><br>
-s, --search &lt;string&gt;</b>: Look in processed faxes for
&lt;string&gt;: (&rsquo;&rsquo;) <b><br>
-n, --reccount &lt;string&gt;</b>: No. of listed entries =
&lt;no&gt; instead of (&rsquo;<b>30</b>&rsquo;) <b><br>
-vc, --vc</b>: edit capisuite log files (finish with
&rsquo;:qa&rsquo;) (<b>0</b>) <b><br>
-vh, --vh</b>: edit hylafax modem configuration file (finish
with &rsquo;:qa&rsquo;) (<b>0</b>) <b><br>
-sqlv, --sql-verbose</b>: screen output with SQL commands
(<b>0</b>) <b><br>
-v, --verbose</b>: screen output more verbose (<b>0</b>)
<b><br>
-lfn, --logfilenew</b>: delete log file afore (<b>0</b>)
<b><br>
-cf, --conffile &lt;string&gt;</b>: uses configuration file
&lt;string&gt; instead of (&rsquo;&rsquo;) <b><br>
-h, --help</b>: Explanation of frequent options (<b>3</b>)
<b><br>
-lh, --longhelp</b>: Explanation of all options (<b>3</b>)
<b><br>
-vi, --vi</b>: edit/view configuration file , log file etc.
(finish with &rsquo;:qa&rsquo;) (<b>0</b>) <b><br>
-vs, --vs</b>: edit/view source files in
<b>/home/schade/autofax2</b>(finish with &rsquo;:qa&rsquo;)
(<b>0</b>) <b><br>
-ia, --interactive</b>: all parameters will be prompted
(some of them not shown here) (<b>0</b>) <b><br>
-noia, --nointeraction</b>: no questions, e.g. for a call
from within cron (<b>0</b>) <b><br>
-info, --version</b>: shows the program version (<b>0</b>)
<b><br>
Options to be saved in the configuration file: (preced.
&rsquo;1&rsquo;=don&rsquo;t save, &rsquo;no&rsquo;=contrary,
e.g. &rsquo;-noocra&rsquo;,&rsquo;-1noocri&rsquo;): <br>
-tdr, --tofaxdir &lt;path&gt;</b>: faxes the files from
&lt;path&gt; instead of
(&rsquo;<b>/var/autofax2/tobefaxed</b>&rsquo;) <b><br>
-wdr, --waitdir &lt;path&gt;</b>: files are waiting in
&lt;path&gt; instead of
(&rsquo;<b>/var/autofax2/waitingfaxes</b>&rsquo;) <b><br>
-ndr, --notfaxeddir &lt;path&gt;</b>: Failed Faxes are
collected here and not in
(&rsquo;<b>/var/autofax2/notfaxed</b>&rsquo;) <b><br>
-rdr, --receiveddir &lt;path&gt;</b>: directory for recieved
faxes (&rsquo;<b>/var/autofax2/recvdir</b>&rsquo;) <b><br>
-fbox, --takefbox &lt;zahl&gt;</b>: use fritzbox <b>or
not</b> (<b>1</b>) <b><br>
-fbdr, --fritzboxdir &lt;path&gt;</b>: receiving directory
of the fritzbox (via CIFS)
(&rsquo;<b>/mnt/diabfb/Generic-FlashDisk-01/FRITZ/faxbox</b>&rsquo;)
<b><br>
-capi, --takecapi &lt;zahl&gt;</b>: use capisuite <b>or
not</b> (<b>1</b>) <b><br>
-hyla, --takehyla &lt;zahl&gt;</b>: use hylafax <b>or
not</b> (<b>1</b>) <b><br>
-hf, --hylafirst &lt;zahl&gt;</b>: trying to send faxes
first via hylafax (<b>0</b>) <b><br>
-fc, --firstcapi &lt;zahl&gt;</b>: try to send faxes
primarily via capisuite (<b>0</b>) <b><br>
-mod, --hmodem &lt;string&gt;</b>: Modem used for hylafax,
instead of (&rsquo;<b>ttyACM0</b>&rsquo;) <b><br>
-mc, --maxcapitries &lt;string&gt;</b>: try Hylafax after
&lt;no&gt; tries of Capisuite instead of
(&rsquo;<b>3</b>&rsquo;) <b><br>
-mh, --maxhylatries &lt;string&gt;</b>: try Capisuite after
&lt;no&gt; tries of Hylafax instead of
(&rsquo;<b>3</b>&rsquo;) <b><br>
-cuser, --cuser &lt;string&gt;</b>: takes the linux user
&lt;string&gt; for capisuite and/or samba instead of
(&rsquo;<b>schade</b>&rsquo;) <b><br>
-crct, --cringcount &lt;string&gt;</b>: No. of bell rings
until Capisuite accepts the call, instead of
(&rsquo;<b>1</b>&rsquo;) <b><br>
-hrct, --hringcount &lt;string&gt;</b>: No. of bell rings
until hylafaxs accepts the call, instead of
(&rsquo;<b>2</b>&rsquo;) <b><br>
-hmd, --hmaxdials &lt;string&gt;</b>: No of dialing retries
in hylafax, instead of (&rsquo;<b>11</b>&rsquo;) <b><br>
-it, --immediatelytarget &lt;zahl&gt;</b>: copy faxes into
target directory irrespective of faxing success (<b>1</b>)
<b><br>
-ocri, --ocri &lt;zahl&gt;</b>: Text from received faxes
will be filtered (<b>1</b>) <b><br>
-ocro, --ocro &lt;zahl&gt;</b>: Text from sent pictures will
be filtered (<b>0</b>) <b><br>
-tfs, --tofaxstr &lt;string&gt;</b>: the fax number will be
expected after &lt;string&gt; instead of (&rsquo;<b>an
Fax</b>&rsquo;) <b><br>
-tcfs, --tocfaxstr &lt;string&gt;</b>: fax no.for fax with
preference to capisuite is expected after &lt;string&gt;
instead of (&rsquo;<b>an cFax</b>&rsquo;) <b><br>
-thfs, --tohfaxstr &lt;string&gt;</b>: fax no.for fax with
preference to hylafax is expected after &lt;string&gt;
instead of (&rsquo;<b>an hFax</b>&rsquo;) <b><br>
-ts, --tostr &lt;string&gt;</b>: name of addressee is
expected after &lt;string&gt; instead of (&rsquo; <b>an</b>
&rsquo;) <b><br>
-ands, --andstr &lt;string&gt;</b>: separating string
&lt;string&gt; for multiple addressees/tel&rsquo;numbers,
instead of (&rsquo;<b>und</b>&rsquo;) <b><br>
-fd, --find &lt;string&gt;</b>: version 1,2 or 3 of filefind
(variable performance differences instead of
(&rsquo;<b>3</b>&rsquo;) <b><br>
-host, --host &lt;string&gt;</b>: takes the database on host
&lt;string&gt; instead of (&rsquo;<b>localhost</b>&rsquo;)
<b><br>
-muser, --muser &lt;string&gt;</b>: takes the user
&lt;string&gt; for MySQL/MariaDB instead of
(&rsquo;<b>user</b>&rsquo;) <b><br>
-mpwd, --mpwd &lt;string&gt;</b>: takes the password
&lt;string&gt; for MySQL/MariaDB <b><br>
-db, --database &lt;string&gt;</b>: uses the database
&lt;string&gt; instead of (&rsquo;<b>autofax2</b>&rsquo;)
<b><br>
-lg, --language &lt;string&gt;</b>:
Language/Sprache/Lingue/Lingua
[<b>d</b>eutsch,<b>e</b>nglisch] (&rsquo;<b>e</b>&rsquo;)
<b><br>
-ldr, --logdir &lt;path&gt;</b>: choses &lt;path&gt; as log
directory, currently (&rsquo;<b>/var/log</b>&rsquo;) <b><br>
-lf, --logfilename &lt;string&gt;</b>: log file
&lt;string&gt; (in path &rsquo;<b>/var/log</b>&rsquo;) will
be used instead of (&rsquo;<b>autofax2.log</b>&rsquo;)
<b><br>
-l, --log &lt;zahl&gt;</b>: put detailed logs in file
&rsquo;<b>/var/log/autofax2.log</b>&rsquo; (otherwise
shorter) (<b>0</b>) <b><br>
-cm, --cronminutes &lt;string&gt;</b>: every how many
minutes shall <b>autofax2</b> be called in crontab (0=not at
all), instead of (&rsquo;<b>0</b>&rsquo;) <b><br>
-autoupd, --autoupdate &lt;zahl&gt;</b>: Update program
automatically (<b>1</b>)</p>
<hr>
</body>
</html>

<h1 align="center">AUTOFAX2 (Version 0.1167) - deutsch<a name="deutsch_D"></a></h1>

<a href="#NAME_D">NAME</a><br>
<a href="#SYNOPSIS_D">SYNOPSIS</a><br>
<a href="#KURZBESCHREIBUNG_D">KURZBESCHREIBUNG</a><br>
<a href="#INSTALLATION_D">INSTALLATION</a><br>
<a href="#GEBRAUCH_D">GEBRAUCH</a><br>
<a href="#OPTIONEN_D">OPTIONEN</a><br>
<a href="#VORAUSSETZUNGEN_D">VORAUSSETZUNGEN</a><br>

<hr>


<h2>NAME
<a name="NAME_D"></a>
</h2>


<p style="margin-left:11%; margin-top: 1em"><b>autofax2
&minus; FaxServer-Funktionalit&auml;t</b>: veranlasst
automatischen Faxversand von Dateien, Benennung empfangener
Faxe und Protokollierung aller Faxe in einer Datenbank <br>
(manpage available in english: &rsquo;man autofax2&rsquo; or
&rsquo;man -Len autofax2&rsquo;)</p>

<h2>SYNOPSIS
<a name="SYNOPSIS_D"></a>
</h2>


<p style="margin-left:11%; margin-top: 1em"><b>autofax2
[-&lt;kurzopt&gt;|--&lt;langopt&gt;
[&lt;erg&auml;nzung&gt;]] ...</b></p>

<h2>KURZBESCHREIBUNG
<a name="KURZBESCHREIBUNG_D"></a>
</h2>


<h2>INSTALLATION
<a name="INSTALLATION_D"></a>
</h2>


<h2>GEBRAUCH
<a name="GEBRAUCH_D"></a>
</h2>


<h2>OPTIONEN
<a name="OPTIONEN_D"></a>
</h2>


<h2>VORAUSSETZUNGEN
<a name="VORAUSSETZUNGEN_D"></a>
</h2>


<p style="margin-left:11%; margin-top: 1em">Programm:
<b>/root/autofax2/autofax2</b>, V: <b>0.11670</b> Verwende:
<b>Fritzbox</b>, <b>Capisuite</b>, <b>Hylafax <br>
Optionen, die nicht gespeichert werden (aktueller Wert in
Klammern): <br>
-loef, --loeschefax</b>: ein Fax nach Rueckfrage loeschen
(<b>0</b>) <b><br>
-loew, --loeschewaise</b>: Eintraege aus
&lsquo;<b>spool</b>&lsquo; loeschen, zu denen keine Datei im
Wartevz.und kein Capi- oder Hylafax nachweisbar ist
(<b>0</b>) <b><br>
-loea, --loescheallew</b>: alle wartenden Faxe und
zugehoerige Eintraege aus &lsquo;<b>spool</b>&lsquo;
loeschen (<b>0</b>) <b><br>
-erneut, --erneutempf</b>: empfangenes Fax erneut
bereitstellen (<b>0</b>) <b><br>
-uml, --umleiten</b>: ausgehendes Fax vorzeitig auf zweitem
Weg schicken (<b>0</b>) <b><br>
-kez, --korrerfolgszeichen</b>: in der Datenbanktabelle
&lsquo;<b>outa</b>&lsquo; wird das Erfolgszeichen korrigiert
(<b>0</b>) <b><br>
-bvz, --bereinigevz</b>: Dateien aus
Wartevz.,Gescheitertenvz.u.Gefaxtvz.gegen
&lsquo;<b>outa</b>&lsquo; pruefen und ggf. aufraeumen
(<b>0</b>) <b><br>
-st, --stop</b>: autofax2 anhalten (<b>0</b>) <b><br>
-lista, --listausg</b>: listet Datensaetze aus
&lsquo;<b>outa</b>&lsquo; mit Erfolgskennzeichen auf
(<b>0</b>) <b><br>
-listf, --listfehlgeschl</b>: listet Datensaetze aus
&lsquo;<b>outa</b>&lsquo; ohne Erfolgskennzeichen auf
(<b>0</b>) <b><br>
-liste, --listeing</b>: listet Datensaetze aus
&lsquo;<b>inca</b>&lsquo; auf (<b>0</b>) <b><br>
-listw, --listwartende</b>: listet wartende Faxe auf
(<b>0</b>) <b><br>
-s, --suche &lt;string&gt;</b>: Suche in verarbeiteten Faxen
nach &lt;string&gt;: (&rsquo;&rsquo;) <b><br>
-n, --dszahl &lt;string&gt;</b>: Zahl der aufzulistenden
Datensaetze = &lt;zahl&gt; statt (&rsquo;<b>30</b>&rsquo;)
<b><br>
-vc, --vc</b>: Capisuite-Konfigurationsdateien bearbeiten
(beenden mit &rsquo;:qa&rsquo;) (<b>0</b>) <b><br>
-vh, --vh</b>: Hylafax-Modem-Konfigurationsdatei bearbeiten
(beenden mit &rsquo;:qa&rsquo;) (<b>0</b>) <b><br>
-sqlw, --sql-wortreich</b>: Bildschirmausgabe mit
SQL-Befehlen (<b>0</b>) <b><br>
-w, --wortreich</b>: Bildschirmausgabe gespraechiger
(<b>0</b>) <b><br>
-ldn, --logdateineu</b>: logdatei vorher loeschen (<b>0</b>)
<b><br>
-kd, --konfdatei &lt;string&gt;</b>: verwendet
Konfigurationsdatei &lt;string&gt; anstatt (&rsquo;&rsquo;)
<b><br>
-h, --hilfe</b>: Erklaerung haeufiger Optionen (<b>3</b>)
<b><br>
-lh, --langhilfe</b>: Erklaerung aller Optionen (<b>3</b>)
<b><br>
-vi, --vi</b>: Konfigurationsdatei , Logdatei usw.
bearbeiten/sehen (beenden mit &rsquo;:qa&rsquo;) (<b>0</b>)
<b><br>
-vs, --vs</b>: Quelldateien in <b>/home/schade/autofax2</b>
bearbeiten/sehen (beenden mit &rsquo;:qa&rsquo;) (<b>0</b>)
<b><br>
-rf, --rueckfragen</b>: alle Parameter werden abgefragt
(darunter einige hier nicht gezeigte) (<b>0</b>) <b><br>
-krf, --keinerueckfragen</b>: keine Rueckfragen, z.B. fuer
Aufruf aus cron (<b>0</b>) <b><br>
-info, --version</b>: Zeigt die Programmversion an
(<b>0</b>) <b><br>
Optionen z.Speich. i.Konfigur&rsquo;datei (vorausg.
&rsquo;1&rsquo;=doch nicht speichern,
&rsquo;no&rsquo;=Gegenteil, z.B.
&rsquo;-noocra&rsquo;,&rsquo;-1noocri&rsquo;): <br>
-zvz, --zufaxenvz &lt;pfad&gt;</b>: faxt die Dateien aus
&lt;pfad&gt; anstatt aus
(&rsquo;<b>/var/autofax2/zufaxen</b>&rsquo;) <b><br>
-wvz, --wartevz &lt;pfad&gt;</b>: Dateien warten in
&lt;pfad&gt; anstatt
(&rsquo;<b>/var/autofax2/warteauffax</b>&rsquo;) <b><br>
-ngvz, --nichtgefaxtvz &lt;pfad&gt;</b>: Gescheiterte Faxe
werden hier gesammelt anstatt in
(&rsquo;<b>/var/autofax2/nichtgefaxt</b>&rsquo;) <b><br>
-evz, --empfvz &lt;pfad&gt;</b>: Empfangsverzeichnis fuer
Faxempfang (&rsquo;<b>/var/autofax2/empfvz</b>&rsquo;)
<b><br>
-fbox, --obfbox &lt;zahl&gt;</b>: Fritzbox verwenden <b>oder
nicht</b> (<b>1</b>) <b><br>
-fbvz, --fritzboxvz &lt;pfad&gt;</b>: Ankunftsverzeichnis
der Fritzbox (ueber CIFS)
(&rsquo;<b>/mnt/diabfb/Generic-FlashDisk-01/FRITZ/faxbox</b>&rsquo;)
<b><br>
-capi, --obcapi &lt;zahl&gt;</b>: Capisuite verwenden
<b>oder nicht</b> (<b>1</b>) <b><br>
-hyla, --obhyla &lt;zahl&gt;</b>: Hylafax verwenden <b>oder
nicht</b> (<b>1</b>) <b><br>
-hz, --hylazuerst &lt;zahl&gt;</b>: versuche faxe zuerst
ueber Hylafax wegzuschicken (<b>0</b>) <b><br>
-cz, --capizuerst &lt;zahl&gt;</b>: versuche faxe zuerst
ueber Capisuite wegzuschicken (<b>0</b>) <b><br>
-mod, --hmodem &lt;string&gt;</b>: Fuer Hylafax verwendetes
Modem, anstatt (&rsquo;<b>ttyACM0</b>&rsquo;) <b><br>
-mc, --maxcapiv &lt;string&gt;</b>: nach &lt;zahl&gt;
Versuchen Capisuite wird Hylafax versucht, anstatt nach
(&rsquo;<b>3</b>&rsquo;) <b><br>
-mh, --maxhylav &lt;string&gt;</b>: nach &lt;zahl&gt;
Versuchen Hylafax wird Capisuite versucht, anstatt nach
(&rsquo;<b>3</b>&rsquo;) <b><br>
-cuser, --cuser &lt;string&gt;</b>: verwendet fuer Capisuite
und/oder Samba den Linux-Benutzer &lt;string&gt; anstatt
(&rsquo;<b>schade</b>&rsquo;) <b><br>
-ckzl, --cklingelzahl &lt;string&gt;</b>: Zahl der
Klingeltoene, bis Capisuite den Anruf annimmt, anstatt
(&rsquo;<b>1</b>&rsquo;) <b><br>
-hkzl, --hklingelzahl &lt;string&gt;</b>: Zahl der
Klingeltoene, bis Hylafax den Anruf annimmt, anstatt
(&rsquo;<b>2</b>&rsquo;) <b><br>
-hmw, --hmaxwahlvers &lt;string&gt;</b>: Zahl der
Wahlversuche in Hylafax, anstatt (&rsquo;<b>11</b>&rsquo;)
<b><br>
-gz, --gleichziel &lt;zahl&gt;</b>: Faxe werden auch ohne
Faxerfolg ins Zielverzeichnis kopiert (<b>1</b>) <b><br>
-ocre, --ocre &lt;zahl&gt;</b>: Text aus empfangenen Faxen
wird ermittelt (<b>1</b>) <b><br>
-ocra, --ocra &lt;zahl&gt;</b>: Text aus gesandten Bildern
wird ermittelt (<b>0</b>) <b><br>
-afs, --anfaxstr &lt;string&gt;</b>: faxnr wird hinter
&lt;string&gt; erwartet statt hinter (&rsquo;<b>an
Fax</b>&rsquo;) <b><br>
-acfs, --ancfaxstr &lt;string&gt;</b>: faxnr fuer primaer
Capisuite wird hinter &lt;string&gt; erwartet statt hinter
(&rsquo;<b>an cFax</b>&rsquo;) <b><br>
-ahfs, --anhfaxstr &lt;string&gt;</b>: faxnr fuer primaer
hylafax wird hinter &lt;string&gt; erwartet statt hinter
(&rsquo;<b>an hFax</b>&rsquo;) <b><br>
-as, --anstr &lt;string&gt;</b>: Adressatenname wird hinter
&lt;string&gt; erwartet statt hinter (&rsquo; <b>an</b>
&rsquo;) <b><br>
-us, --undstr &lt;string&gt;</b>: Trennstring &lt;string&gt;
fuer mehrere Adressaten/Telefonnummern statt
(&rsquo;<b>und</b>&rsquo;) <b><br>
-fd, --finde &lt;string&gt;</b>: Version 1,2 oder 3
-Dateisuche (variable Performanceunterschiede) anstatt
(&rsquo;<b>3</b>&rsquo;) <b><br>
-host, --host &lt;string&gt;</b>: verwendet die Datenbank
auf Host &lt;string&gt; anstatt auf
(&rsquo;<b>localhost</b>&rsquo;) <b><br>
-muser, --muser &lt;string&gt;</b>: verwendet fuer
MySQL/MariaDB den Benutzer &lt;string&gt; anstatt
(&rsquo;<b>user</b>&rsquo;) <b><br>
-mpwd, --mpwd &lt;string&gt;</b>: verwendet fuer
MySQL/MariaDB das Passwort &lt;string&gt; <b><br>
-db, --datenbank &lt;string&gt;</b>: verwendet die Datenbank
&lt;string&gt; anstatt (&rsquo;<b>autofax2</b>&rsquo;)
<b><br>
-sp, --sprache &lt;string&gt;</b>:
Language/Sprache/Lingue/Lingua
[<b>d</b>eutsch,<b>e</b>nglisch] (&rsquo;<b>d</b>&rsquo;)
<b><br>
-lvz, --logvz &lt;pfad&gt;</b>: waehlt als Logverzeichnis
&lt;pfad&gt;, derzeit (&rsquo;<b>/var/log</b>&rsquo;)
<b><br>
-ld, --logdname &lt;string&gt;</b>: logdatei &lt;string&gt;
(im Pfad &rsquo;<b>/var/log</b>&rsquo;) wird verwendet
anstatt (&rsquo;<b>autofax2.log</b>&rsquo;) <b><br>
-l, --log &lt;zahl&gt;</b>: protokolliert ausfuehrlich in
Datei &rsquo;<b>/var/log/autofax2.log</b>&rsquo; (sonst
knapper) (<b>0</b>) <b><br>
-cm, --cronminuten &lt;string&gt;</b>: alle wieviel Minuten
soll <b>autofax2</b> ueber crontab aufgerufen werden (0=gar
nicht), anstatt (&rsquo;<b>0</b>&rsquo;) <b><br>
-autoakt, --autoaktual &lt;zahl&gt;</b>: Programm
automatisch aktualisieren (<b>1</b>)</p>
<hr>
</body>
</html>
