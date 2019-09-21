C -INC TMCOLAC
C=======================================================================
C  ICOLAC :  KCOLA : POINTEUR SUR LA PILE ITLACC
C            MCOLA : NOMBRE D'OBJETS INSPECTES DANS LA PILE
C            ICOLA : POINTEUR SUR ISGTR ( NOM-NOM-RANG DANS ITLACC)
C            KCOLAC: CONTIENT POUR CHAQUE PILE LE NOMBRE D'OBJETS A
C                    SORTIR
C            ILISSG: pointeur vers seg ilisse qui contient la place de
C                      l'objet dans la pile itlacc ( iliseg(i)=j : le
C            ILISSP: pointeur vers seg ilisse cas des points
C            ILISSF: pointeur vers seg ilisse cas des flottants
C                      segment de numéro i est le j ieme de la pile)
C            IFFORM: entier qui vaut 1 si sauvegarde formatée sinon 0
C
C     04/04/14: Modif GF: 	-Declaration des segments en utilisant la derniere specif Esope
C				-Nouveau segment LISPIL
C======================================================================
C      SEGMENT/ICOLAC/(ICOLA(NITLAC),KCOLA(NITLAC),MCOLA(NITLAC),
C     1  KCOLAC(NITLAC),ILISSG,IFFORM)
      SEGMENT ICOLAC
         integer icola(nitlac)
         integer kcola(nitlac)
         integer mcola(nitlac)
         integer kcolac(nitlac)
         integer ilissg
         integer ilissp
         integer ilissf
         integer ifform
      ENDSEGMENT
      pointeur icola1.icolac

C      SEGMENT/ITLACC/(ITLAC(0)),ITLAC1.ITLACC,ITLAC2.ITLACC,
C     1 ITLAC3.ITLACC,ITLAC4.ITLACC,ITLAC5.ITLACC,ITLAC6.ITLACC
      SEGMENT ITLACC
         integer itlac(0)
      ENDSEGMENT
      pointeur ITLAC1.ITLACC
      pointeur ITLAC2.ITLACC
      pointeur ITLAC3.ITLACC
      pointeur ITLAC4.ITLACC
      pointeur ITLAC5.ITLACC
      pointeur ITLAC6.ITLACC

      SEGMENT ISGTR
**       character*(LONOM) isgtrc(ks)
         character*(24) isgtrc(ks)
         integer isgtri(ks)
      ENDSEGMENT

      SEGMENT ILISSE
         integer npgcd
         integer iliseg(nlisse)
      ENDSEGMENT

C	Liste de segments ICOLAC pour la communication entre collaborateurs
C		La pile iProc contient les elements echanges avec le collaborateur iProc
      SEGMENT LISPIL
        integer proc(nproc)
      ENDSEGMENT
