*      -INC CCOPTIO
*
*		04/04/14: Modif GF: Declaration explicite des variables
*
*   PLACE LIBRE A RESPECTER
      COMMON/COPTIO/IPLLB
      integer       IPLLB
*
*    ERREUR       AUTORISEE, MAX    ,EFFECTIVE
      COMMON/COPTIO/IERPER,  IERMAX, IERR
      integer       IERPER,  IERMAX, IERR
*
*    COMMUNICATION AVEC ERREUR
      REAL*8 REAERR
      integer       INTERR
      COMMON/COPTIO/INTERR(10),REAERR(10)

*    UNITES ENTREE-SORTIE
*                    TERMINAL LECTEUR IMPRESSION LIRE    ACQUERIR
      COMMON /COPTIO/IOTER,   IOLEC,  IOIMP,     IOCAR,  IOACQ
      integer        IOTER,   IOLEC,  IOIMP,     IOCAR,  IOACQ
*                    SORTIR   epsilon   TRAC       SAUVER  RESTITUER
      COMMON /COPTIO/IOPER,   MEPSIL,  IOGRA,     IOSAU,  IORES
      integer        IOPER,   MEPSIL,  IOGRA,     IOSAU,  IORES
*
*                   ECHO     NIVEAU D'IMPRESSION   TRACE DES OP{RATEURS
      COMMON/COPTIO/IECHO,   IIMPI,                IOSPI
      integer       IECHO,   IIMPI,                IOSPI
*
*                   DIMENSION,COORDONNEES
      COMMON/COPTIO/IDIM,     MCOORD
      integer       IDIM
*
*
*           - 1 PLAN 0 AXIS 1 FOUR 2 TRID
      COMMON/COPTIO/IFOMOD
      integer       IFOMOD
*             HARMONIQUE DE FOURIER
      COMMON/COPTIO/NIFOUR
      integer       NIFOUR
*
*             OPTION DE CALCUL
*  -3 DEFORMATION PLANE GENERALISEE  -2 CONTRAINTES PLANES
*  -1 DEFORMATION PLANE               0 AXISYMETRIQUE
*   1 SERIE DE FOURIER                2 TRIDIMENSIONNEL
      COMMON/COPTIO/IFOUR
      integer       IFOUR
*
*   PLUS GRAND  NOEUD SUPPORT DE LA DEFO PLANE GENE
      COMMON/COPTIO/NSDPGE
      integer       NSDPGE
*
*  TAILLE DU CADRE  (TRACE BENSON)
      REAL*8 DIOCAD
      COMMON/COPTID/DIOCAD
*    ZHORIZ
*     .true.  --> paysage
*     .false. --> portrait
*    ZINIPS
*     .true.  --> la sortie ps pas encore initialisee
*     .false. --> deja initialisee
      LOGICAL ZHORIZ , ZINIPS
      COMMON/COPTIO/ZHORIZ , ZINIPS
*
*  NIVEAU DE SORTIE  2 STANDARD  1 ANCIEN
      COMMON/COPTIO/IONIVE
      INTEGER       IONIVE
*
*  TAILLE DE TRAVAIL ALLOUEE A LA MATRICE POUR L'INVERSION
      COMMON/COPTIO/NGMAXY
      integer       NGMAXY
*
*  NOMBRE DE ZERO CONSECUTIFS A UTILISER DANS LA RESOLUTION
      COMMON/COPTIO/IZROSF
      integer       IZROSF
*
*  TYPE DE TRACE D'ISOVALEURS
      COMMON/COPTIO/ISOTYP
      integer       ISOTYP
*
*  EPAISSEUR DU TRAIT LORS DE L'ECRITURE DANS UN FICHIER POST-SCRIPT
      COMMON/COPTIO/IEPTR
      integer       IEPTR
*
*
*  FULL-SCREEN
      COMMON/COPTIO/IOSCR,LTEXLU
      integer       IOSCR,LTEXLU
*
*  normalisation des variables
      COMMON/COPTIO/NORINC,NORVAL,NORIND,NORVAD
      integer       NORINC,NORVAL,NORIND,NORVAD
*
*  type de renumérotation
      COMMON/COPTIO/NUCROU
      integer       NUCROU
*
*
*  structure de sauvegarde
      COMMON/COPTIO/IPSAUV
      integer       IPSAUV

*
*
*  bande sauve si premiere,restituer si premiere, tailemax,tailreelle
      COMMON/COPTIO/IPREFI,IFICLE
      integer       IPREFI,IFICLE
      COMMON/COPTID/      DIMATT,DIMFIC
      REAL*8 DIMATT,DIMFIC

*     format de la restitution  et de la sauvegarde
*
      COMMON/COPTIO/IREFOR,ISAFOR
      integer       IREFOR,ISAFOR
*  faut-il faire tenter d'utiliser les assistants lecture parallele
      COMMON/COPTIO/LUPARA
      integer       LUPARA
* est-on en option debug pour les procedures
      COMMON/COPTIO/MISAUP
      integer       MISAUP
* conserve-t-on les variables locales creees dans les procedures ?
      LOGICAL ZLOPRO
      COMMON/COPTIO/ZLOPRO
* tableau de logiques pour messages d'erreur. A remettre en tete
      LOGICAL BOOERR
      COMMON/COPTIO/BOOERR(10)
* Valeur de pointeur a surveiller
      COMMON/COPTIO/MSURVE

      CHARACTER*40 MOTERR
      CHARACTER*72 TITREE
      CHARACTER*4 LOCERR
      COMMON/COPTIC/MOTERR,TITREE,LOCERR
*  DATE DE LA VERSION
      CHARACTER*72 DATVER
      COMMON/COPTIC/DATVER
      CHARACTER*500 TEXLU
      COMMON/COPTIC/TEXLU
* bande sauver  son nom
      CHARACTER*72 NOMFIC,NOMRES
      COMMON/COPTIC/NOMFIC,NOMRES
*  segment index des notices
      integer LISNOTI
      integer UTIFI3
      COMMON/COPTIC/LISNOTI
      COMMON/COPTIC/UTIFI3(7)
*  langage de la notice
      integer LISPROC
      COMMON/COPTIC/LISPROC
*  langage de la notice
      CHARACTER*4 LANGUE
      COMMON/COPTIC/LANGUE
*


