C
C-INC CCPRECO
C
      COMMON/CPRECO/PRENUM(30)
      INTEGER PRENUM
C
C  PRENUM est un tableau de pointeurs sur des maillages stockant la numerotation
C
      COMMON/CMPREC/PREORI(30),PREPRE(30)
      COMMON/CMPCLE/PRECLE(30)
      INTEGER PREORI,PREPRE
      CHARACTER*16 PRECLE
C
C CMPREC : preconditionnement pour COMP
C associer 2 segments pour eviter de refaire certains traitements
C PREORI pointeur objet initial, PREPRE pointeur ad hoc, PRECLE etiquette
C
      parameter (nbemel=100)
      COMMON/CCRECH/premel(nbemel),hash1(nbemel),hash2(nbemel),
     >  hash3(nbemel),nbso(nbemel)
      integer premel,hash1,hash2,hash3,nbso
C
C CCRECH preconditionnement pour crechp
C premel liste des maillages, hash1 hash2 et hash3 les hash codes associes
C


C CPART6 preconditionnement pour part6 (Partitionnement des MMODEL)
C   NMOPAR : Nombre de pointeurs que l'on conserve en memoire
C   PARMOD : POINTEURS vers les MMODEL qui ont ete partitionnes
C   PESCLA : POINTEURS vers les TABLES ESCLAVES equivalentes
      PARAMETER (NMOPAR=5)
      INTEGER PARMOD,PESCLA
      COMMON/CPART6/PARMOD(NMOPAR),PESCLA(NMOPAR)


C CREDUA preconditionnement pour reduaf (Reduction de MCHAML deja fait)
C   NPREDU : Nombre de triples de pointeurs que l'on conserve en memoire par ASSISTANT
C   PRECMO : POINTEURS vers les MMODEL en entree de REDU
C   PRECM1 : POINTEURS vers les MCHELM en entree de REDU
C   PRECM2 : POINTEURS vers les MCHELM en sortie de REDU
C   NBPRRE : Nombre de preconditionnements deja sauves
      PARAMETER (NBASMA=64)
      PARAMETER (NPREDU=30)
      INTEGER PRECMO,PRECM1,PRECM2,NBPRRE
      COMMON/CREDUA/PRECMO(NPREDU,NBASMA+1),PRECM1(NPREDU,NBASMA+1),
     &              PRECM2(NPREDU,NBASMA+1),NBPRRE(NBASMA+1)


C CREDIN preconditionnement pour reduaf (intersection des MAILLAGES)
C   NTRIPL : Nombre de triples de pointeurs que l'on conserve en memoire par ASSISTANT
C   PMAMOD : POINTEURS vers les MAILLAGES des IMODEL
C   PMAMOH : HORODATAGE     des MAILLAGES des IMODEL
C   PMACHA : POINTEURS vers les MAILLAGES des MCHAML
C   PMACHH : HORODATAGE     des MAILLAGES des MCHAML
C   PMLENT : POINTEURS vers les MLENTI    des intersections
C   NINTSA : Nombre d'intersections deja sauvees
C     PARAMETER (NBASMA=64)
      PARAMETER (NTRIPL=NBASMA)
      INTEGER NINTSA,PMAMOD,PMACHA,PMLENT,PMACHH,PMAMOH
      COMMON/CREDIN/NINTSA(NBASMA+1), PMAMOD(NTRIPL,NBASMA+1),
     &              PMAMOH(NTRIPL,NBASMA+1),PMACHA(NTRIPL,NBASMA+1),
     &              PMACHH(NTRIPL,NBASMA+1),PMLENT(NTRIPL,NBASMA+1)

