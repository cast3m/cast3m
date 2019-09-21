C*******************************************************************
C
C    REPERAGE ET STOKAGE DES MATRICES ELEMENTAIRES  puis assemblees
C    (description par sous-zone associees a un operateur)
C
C   COEMTK(I)     : Flottant , coefficient multiplicateur de la matrice
C
C   IRIGEL(1,I)   : POINTEUR SUR L'OBJET GEOMETRIE (Inconnues primales)
C   IRIGEL(2,I)   : POINTEUR SUR L'OBJET GEOMETRIE (Inconnues duales)
C   IRIGEL(3,I)   : Non utilise (POINTEUR SUR LE SEGMENT DESCRIPTIF D'UNE
C                                MATRICE ELEMENTAIRE.(SEGMENT DESCR)
C   IRIGEL(4,I)   : POINTEUR SUR LE SEGMENT CONTENANT LES POINTEURS
C                        DES MATRICES DE MRIGIDITE DE CHAQUE ELEMENTS.
C                        (SEGMENT IMATRI)
C   IRIGEL(5,I)   : Non utilise
C   IRIGEL(6,I)   : Non utilise
C   IRIGEL(7,1)   : 0   LA MATRICE EST SYMETRIQUE
C                 : 1   LA MATRICE EST ANTISYMETRIQUE
C                 : 2   LA MATRICE EST NON SYMETRIQUE
C                 : 3   LA MATRICE EST RECTANGULAIRE avec SPGP # SPGD
C                 : 4   LA MATRICE EST type 3 et CCt (on ne stoke que C)
C                 : 5   LA MATRICE EST diagonale
C                 : 6   LA MATRICE EST deja assemblee en morse

      SEGMENT MATRIK
      REAL*8  COEMTK(NMATRI)
      INTEGER IRIGEL(NRIGE,NMATRI)

C KSIM  =0 matrice symetrique  =2 matrice non symetrique
C KMINC , KMINCP , KMINCD : pointeur sur MINC repartition des inconnues
C totales primales et duales                            PROFKS PKINC
C KIZM  : pointeur sur les connectivites globales
C KISPGT KISPGP KISPGD ; SPG assemble pour inc totales,prim et dua
C KNTTT  KNTTP  KNTTD  ; nb d'inconnues total

      INTEGER KSYM,KMINC,KMINCP,KMINCD,KIZM
      INTEGER KISPGT,KISPGP,KISPGD
      INTEGER KNTTT,KNTTP,KNTTD

C KIDMAT: pointeur sur stokage bloc IDMAT (Cholevski)    TRIAKS
C KS2B  : pointeur sur second membre(IZA)cree ds PROFKS calcule ds KASMBR
C KMORS : pointeur sur profil Morse(PMORS)               ASSMT (KALMOR)
C KISA  : pointeur sur stokage Morse(IZA)                ASSMT (KALMOR)
C KMRST : pointeur sur profil Morse(PMORS)de AAt         PROFKS(KALMOR)
C KIST  : pointeur sur stokage Morse(IZA) de AAt         PROFKS(KALMOR)
C KCLIM : pointeur sur stokage C lim (CHPT)
C KTRING: 0 pas triangulée 1 triangulée

C  nkid=9 :  IDMATP,IDMATD,KS2B,KMORS,KISA,KMRST,KIST,KCLIM,KTRING
      INTEGER KIDMAT(NKID)
C  nkmt=7 :  KMMT,MATRIU,MATRIP,IZDU,IZDP,IZFU,IZFP
C                               (IZA)(IZA)(IZA)(IZA)
      INTEGER KKMMT(NKMT)
      ENDSEGMENT

C LIZAFM(NBSOUS,.) description par sous-objet geometrique -> IZAFM
C KSPGP , KSPGD : SPG pour les inconnues primales et duales
      SEGMENT IMATRI
      CHARACTER*8 LISPRI(NBME),LISDUA(NBME)
      INTEGER LIZAFM(NBSOUS,NBME)
      INTEGER KSPGP,KSPGD
      ENDSEGMENT

C Stokage matrices elementaires non assemblees (valeurs)
      SEGMENT IZAFM
      REAL*8  AM(NBEL,NP,MP)
      ENDSEGMENT
      POINTEUR IPM1.IZAFM,IPM2.IZAFM,IPM3.IZAFM,IPM4.IZAFM
      POINTEUR IPM5.IZAFM,IPM6.IZAFM,IPM7.IZAFM,IPM8.IZAFM
      POINTEUR IPM9.IZAFM

C Reperage des inconnues
*  NPT nb de noeud  NBI nb de composantes total  NTT nb total de DDL
*  MPOS(NPT,NBI+1) = 0 si l'inconnue j n est pas defini au noeud i
*            sinon = k rang de cette inconnue pour le noeud i
*  MPOS(i,NBI+1) nb d'inconnues au noeud i
*  NPOS(NPT)     Position de la 1ere inconnue du noeud i
*  NPOS et MPOS  sont donnes ds la numerotation optimisee

      SEGMENT MINC
      CHARACTER*8 LISINC(NBI)
      INTEGER     NPOS(NPT+1)
      INTEGER     MPOS(NPT,NBI+1)
      ENDSEGMENT
      POINTEUR MINCP.MINC,MINCD.MINC

      SEGMENT PMORS
      INTEGER IA (NTT+1)
      INTEGER JA (NJA)
      ENDSEGMENT
      POINTEUR PMS1.PMORS,PMS2.PMORS

C Segment de stokage
      SEGMENT IZA
      REAL*8  A(NBVA)
      ENDSEGMENT
      POINTEUR IZA1.IZA,IZA2.IZA,IZAU.IZA,IZAL.IZA,ISA.IZA

      SEGMENT IDMAT
*  KZA(NTT)    Longueur de chaque ligne de la matrice (diag comprise)
*  NUIA(NTT,2) 1/ numero du bloc dans lequel se trouve la ligne i de la
*                 matrice
*              2/ position du debut de la ligne dans le segment IZA - 1
      INTEGER KZA(NTT),NUIA(NTT,2)
      INTEGER NUAN(NPT),NUNA(NPT)
      INTEGER IDIAG
      INTEGER IDESCL(NBLK)
      INTEGER IDESCU(NBLK)
      INTEGER NLDBLK(NBLK+1)
      ENDSEGMENT

C*******************************************************************
