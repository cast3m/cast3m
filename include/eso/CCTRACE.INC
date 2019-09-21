*
*-INC CCTRACE
*
C     ECRAN : police (OPTI 'POLI' ... -> IOPOLI)
c             couleur fond ecran (OPTI 'COSC'... -> ICOSC)
C     SORTIE PS : police (OPTI 'POTR' fonte -> IOPOTR )
c     INFOTR : info de trace
c     INFOTR(1) : angle en degre d ecriture ou de tracé
c     INFOTR(2) : alignement (0:defaut, 1:excentre, 2:centre ...)
c     INFOTR(...) : ...
      REAL*4 AMPLIT
      INTEGER INFOTR
      COMMON/CTRACE/IOPOLI,ICOSC,IOPOTR,INFOTR(8)
      COMMON/RTRACE/AMPLIT
*
*    COMMON PORTANT SUR LES COULEURS POUR LES TRACES
*
*
*   TABLEAU DU DEGRADE DE COULEURS (arc en ciel typiquement)
*   avec les couleurs nommees.
      COMMON/CTRACE/ICOTAB(15)
*
*   TABLEAU DE CHOIX DU DEGRADE DE COULEURS DANS ICOTAB LORSQU'ON
*   DEMANDE MOINS DE 16 COULEURS (ISOTAB)
*   OU MOINS DE 13 COULEURS (ISOTA0)
*   En effet, pour OPTI ISOV LIGNE, on evite les couleurs
*   gris, blanc et noir
*
      COMMON/CTRACE/ISOTAB(15,15)
      COMMON/CTRACE/ISOTA0(12,12)

