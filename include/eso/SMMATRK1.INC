C*************************************************************************
C
C    REPERAGE ET STOKAGE DES MATRICES ELEMENTAIRES
C     Complement 1 de l'include SMMATRIK (CHOLESKI)

      SEGMENT IZL
      INTEGER KZA(NJA)
      INTEGER NUAN(NJAN),NUNA(NJAN),IMEL(NJAN),IMJ(NJAN)
      REAL*8  B(NJAB)
      INTEGER KZA1
      ENDSEGMENT

      SEGMENT IDMAT
         INTEGER IDIAG
         INTEGER IDESCR(NBLK)
         INTEGER NLDBLK(NBLK+1)
      ENDSEGMENT
      SEGMENT IDBLK
         INTEGER IMAT
         INTEGER ILON
         INTEGER IDEBLK(NLBLK+1)
      ENDSEGMENT
      POINTEUR IBLK1.IDBLK,IBLK2.IDBLK

C*******************************************************************
