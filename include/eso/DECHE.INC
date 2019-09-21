* segment deroulant le mcheml
       SEGMENT,DECHE
         INTEGER INDEC
         INTEGER  IMADEC, IELDEC, IFODEC
         CHARACTER*8 NOMDEC
         CHARACTER*16 TYPDEC
         LOGICAL TYPREE
         CHARACTER*(LCONMO) CONDEC
         INTEGER INFDEC(N3)
       ENDSEGMENT
       POINTEUR DEC1.DECHE,DEC2.DECHE
* INDEC : indice du MCHELM
* CONDEC : constituant
* PHADEC : phase (CONDEC(16:24))
* IMADEC : pointeur maillage
* IELDEC : pointeur melval
* IFODEC : CORRESPOND A IFOCHE (voir MCHAML)
* INFDEC : CORRESPOND A INFCHE (voir MCHAML)
* NOMDEC : nom de composante
* TYPDEC : type du champ
* TYPREE : Vrai si typdec real


* segment des types de composantes relatives a un champ physique
      SEGMENT NOTYPE
        CHARACTER*16 TYPE(NBTYPE)
      ENDSEGMENT

* segment des adresses des deche associes a un NOMID
      segment pilnec
       integer pilobl(mobl,mran),pilfac(mfac,mran)
      endsegment

* le contenu de l'ancien domdec: jnomid et jilnec est directement dans liluc
* segment des pointeurs sur nomid et pilnec
* (les indices se referent au DATA LISMOT ci-dessous)
      segment liluc(iiluc,2)
* pile des deche concernes par un modele elementaire
      segment lilcon(iilcon)
* pile de tous les deche correspondant aux melvals vus par l utilisateur
       segment lilmel(iimel)


C  liste de reference identifiant les champs
      PARAMETER (NMOT=25)
      CHARACTER*8 LISMOT(NMOT),MOT
      DATA LISMOT / 'NOEUD   ', 'GRAVITE ', 'RIGIDITE', 'MASSE   ',
     1              'STRESSES', 'DEPLACEM', 'FORCES  ', 'REACTUAL',
     1              'FVOLUMIQ', 'GRADIENT', 'CONTRAIN', 'DEFORMAT',
     1              'MATERIAU', 'CARACTER', 'TEMPERAT', 'PRINCIPA',
     1              'MAHOOKE ', 'HOTANGEN', 'DILATATI', 'VARINTER',
     1              'GRAFLEXI', 'VONMISES', 'VINMETAL', 'DEFINELA',
     1              'PARAMEXT'/

* segments pour passer les informations au point d integration

* donnees brutes en entree de COMP, completees par les valeurs calculees
      SEGMENT WRK52
* temps initial, final
        REAL*8 temp0, tempf
*
        REAL*8 scal0(nsca), scalf(nsca)
* deplacements
        REAL*8 depl0(ndep), deplf(ndep)
* forces
        REAL*8 forc0(nfor), forcf(nfor)
* gradients
        REAL*8 grad0(ngra), gradf(ngra)
* contraintes
        REAL*8 SIG0(NSTRS), SIGF(NSTRS),DSIGT(NSTRS)
* deformations totales
        REAL*8 epst0(NDEFO),DEPST(NDEFO),epstf(NDEFO)
* caracteristiques materiau
        REAL*8 xmat0(ncara),XMAT(NCARA),xmatf(NCARA),
     &   VALMAT(NCARA),valma0(ncara)
c type et nom de composantes relatifs a VALMAT et valma0
        CHARACTER tyval(ncara)*16, commat(ncara)*8
c pointeur sur les melval de caracteristiques materiau a l etat final
        INTEGER ivalma(ncara)
* caracteristiques geometriques
        REAL*8 xcar0(ncarb),XCARB(NCARB),xcarbf(NCARB),VALCAR(NCARB)
c type et nom de composantes pour les caracteristiques
        CHARACTER tycar(ncarb)*16,comcar(ncarb)*8
* temperatures
        REAL*8 ture0(ntur), turef(ntur)
* contraintes principales
        REAL*8 prin0(npri), prinf(npri)
* matrices de hook
        REAL*8 maho0(nmah), mahof(nmah)
* matrices hook tangent
        REAL*8 hota0(nhot), hotaf(nhot)
* variables internes
        REAL*8 VAR0(NVARI),VARF(NVARI)
* gradients flexion
        REAL*8 graf0(ngrf), graff(ngrf)
*
        REAL*8 rhas0(nrhi), rhasf(nrhi)
* deformations inelastiques
        REAL*8 DEFP(NDEIN),EPIN0(NDEIN),EPINF(NDEIN)
* parametres externes
        REAL*8 PAREX0(NPAREX),PAREXF(NPAREX)
* fourre tout pour les comp non prevues et/ou munies d un autre constituant
        CHARACTER*16 typexo(nexo)
        CHARACTER*8 nomexo(nexo)
        CHARACTER*(lconmo) conexo(nexo)
        REAL*8 exova0(nexo),exova1(nexo)
      ENDSEGMENT
      segment wrk522
* temps initial, final
        integer  mkktp0, mkktpf
*
         integer  mkkal0(nsca), mkklaf(nsca),mkkalz
* deplacements
        integer  mkkpl0(ndep), mkkplf(ndep),mkkplz
* forces
         integer  mkkrc0(nfor), mkkrcf(nfor),mkkrcz
* gradients
         integer  mkkad0(ngra), mkkadf(ngra),mkkadz
* contraintes
          integer  mkkIG0(NSTRS), mkkIGF(NSTRS),mkkIGT(NSTRS),mkkigz
* deformations totales
         integer  mkkst0(NDEFO),mkkPST(NDEFO),mkkstf(NDEFO),mkkstz
* caracteristiques materiau
         integer  mkkat0(ncara),mkkMAT(NCARA),mkkatf(NCARA),
     &   mkkVAT(NCARA),mkkva0(ncara),mkkatz
c pointeur sur les melval de caracteristiques materiau a l etat final
        INTEGER mkklma(ncara)
* caracteristiques geometriques
        integer  mkkar0(ncarb),mkkARB(NCARB),mkkrbf(NCARB),mkkVCR(NCARB)
        integer mblcar,mkkarz
* temperatures
        integer  mkkre0(ntur), mkkref(ntur),mkkrez
* contraintes principales
        integer mkkin0(npri), mkkinf(npri),mkkinz
* matrices de hook
        integer  mkkho0(nmah), mkkhof(nmah),mkkhoz
* matrices hook tangent
        integer mkkta0(nhot), mkktaf(nhot),mkktaz
* variables internes
        integer  mkkVR0(NVARI),mkkVRF(NVARI),mkkvrz
* gradients flexion
        integer  mkkaf0(ngrf), mkkaff(ngrf),mkkafz
*
        integer  mkkas0(nrhi), mkkasf(nrhi),mkkasz
* deformations inelastiques
        integer mkkEFP(NDEIN),mkkPN0(NDEIN),mkkPNF(NDEIN),mkkpnz
* parametres externes
        integer  mkkEX0(NPAREX),mkkEXF(NPAREX),mkkexz
* fourre tout pour les comp non prevues et/ou munies d un autre constituant
        integer mkkvx0(nexo),mkkvx1(nexo),mkkvxz
      ENDSEGMENT
*
* quelques donnees pratiques
      SEGMENT WRK53
        INTEGER MATE,INPLAS,MELE,IPMAIL,NPINT,NBNN2,NBELEM2
        INTEGER NFOR,NMAT,NUMAT,NUCAR,NMATR,NCARF
        INTEGER MFR,NBG,NBGS,NSTRS,LRE,LW,LW2,LHOOK,LHOO2,IPORE,NBNO
        INTEGER NVART,NMATT,NCARR,JECHER,ISTEP,NBINT,JNOID
        INTEGER NBPTEL,NEL,N2PTEL,N2EL,KERRE
        INTEGER ITHHER
        CHARACTER*8  CMATE
        CHARACTER*(lconmo) CONM
        LOGICAL LOGSUC,LOGVIS,LUNI1,LUNI2,LOGRE,LOGIN
        REAL*8 PRECIS,SECT,COB,XMOB,EPAIST
        REAL*8 BID(6),BID2(6)
        REAL*8 COORGA(3),LCARAC
      ENDSEGMENT
* MATE : numero de materiau
* INPLAS : numero loi de comportement
* MELE : numero element fini
* IPMAIL : pointeur maillage
* NPINT : nombre points d integration coque
* NBNN2 : nombre de noeuds
* NBELEM2 : nombre d elements
* MFR : numero formulation
* NBPTEL : nombre de points d integrations
* NEL : nombre d elements
* KERRE : indicateur d erreur
* CMATE : description comportement
* CONM : constituant du modele
* PRECIS : precision
* SECT : section
* EPAIST : epaisseur
* COORGA(3) : coordonnees cartesiennes du point d'integration courant
* LCARAC : longueur caracteristique de l'element courant

* tableaux intermediaires
       SEGMENT WRK54
        REAL*8 DDHOOK(LHOOK,LHOOK)
        REAL*8 DDAUX(LHOOK,LHOOK)
        REAL*8 TXR(IDIM,IDIM),DDHOMU(LHOOK,LHOOK)
        REAL*8 XLOC(3,3),XGLOB(3,3)
        REAL*8 D1HOOK(LHOOK,LHOOK),ROTHOO(LHOOK,LHOOK)
        CHARACTER*16 TYMAT(NCXMAT)
        REAL*8 XMAT1(NCXMAT),XMAT2(NCXMAT)
      ENDSEGMENT
*
*Pour la metallurgie (par T.LINDECKER en mai 2018)
      SEGMENT WRKMET
        CHARACTER*4 PHASES(NBPHAS)
        CHARACTER*4 REACTI(NBREAC)
        CHARACTER*4 PRODUI(NBREAC)
        CHARACTER*4 TYPES(NBREAC)
      ENDSEGMENT







