C=======================================================================
C
C    OBJET DE TYPE 'TEXT','E   '
      SEGMENT , MTEXTE
        CHARACTER MTEXT*72
        INTEGER   NCART
        INTEGER   MTRADC
      ENDSEGMENT
        POINTEUR MTEXT1.MTEXTE , MTEXT2.MTEXTE
      SEGMENT , MTRADU
        INTEGER  MTRAD(0)
      ENDSEGMENT
C
C=======================================================================
