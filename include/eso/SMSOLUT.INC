*  -INC SMSOLUT
*
*     OBJET DE TYPE'SOLUTION'
*
      SEGMENT MSOLUT
       CHARACTER*8 ITYSOL
       INTEGER     MSOLIS(NIPO),MSOLIT(NIPO)
      ENDSEGMENT
       POINTEUR MSO1.MSOLUT,MSO2.MSOLUT
*
      SEGMENT MMODE
       REAL*8      FMMODD(LVALM)
       INTEGER     IMMODD(NIMOD)
      ENDSEGMENT
       POINTEUR MMOD1.MMODE
*
      SEGMENT MSOLRE
       REAL*8      SOLRE(N)
      ENDSEGMENT
       POINTEUR MSOLR1.MSOLRE,MSOLR2.MSOLRE
*
      SEGMENT MSOLEN
       INTEGER     ISOLEN(N)
      ENDSEGMENT
       POINTEUR MSOLE1.MSOLEN,MSOLE2.MSOLEN
*
*
*   ITYSOL  :  SOUS TYPE DE L'OBJET SOLUTION
*   MSOLIS(I) : POINTEUR SUR DIFFERENTS SEGMENTS (SUIVANT LA VALEUR
*               DE ITYSOL ET CELLE DE I)
*   MSOLIT(I) : DESIGNE LE TYPE DES OBJETS CONTENUS DANS LE MSOLEN
*               DE POINTEUR MSOLIS(I).
*               2 POUR LES CHPOINT , 5 POUR LES CHAMELEM ,
*              14 POUR LES MJONCT...
*               LA CORRESPONDANCE TYPE DES OBJETS--NUMERO EST CONTENUE
*               DANS LE SOUS PROGRAMME TYPFIL
*
*
*   * I=1,4 :  ZONE COMMUNE A TOUS LES ITYSOL :
*     ------------------------
*     3.  POINTEUR SUR UN MELEME                                 0
*     4.  POINTEUR SUR MSOLEN (LISTE DE MMODE )                  0
*
*   * ITYSOL = MODE
*     -------------
*     5.  POINTEUR SUR MSOLEN (DEPLACEMENTS   )         MSOLIT = 2
*     6.         ID.          (CONTRAINTES    )                  5
*     7.         ID.          (VON MISES      )                  5
*     8.         ID.          (VITESSES       )                  2
*     9.         ID           (ACCELERATIONS  )                  2
*
*   * ITYSOL = SOLUSTAT OU PSEUMODE
*     -----------------------------
*     5.  POINTEUR SUR MSOLEN (DEPLACEMENTS   )          MSOLIT = 2
*     6.         ID.          (CONTRAINTES    )                   5
*     7.         ID.          (VON MISES      )                   5
*     8.         ID.          (VITESSES       )                   2
*     9.         ID.          (ACCELERATIONS  )                   2
*     10.        ID.          (MJONCT         )                   14
*
*   * ITYSOL = DYNAMIQU
*     -----------------
*     1.  POINTEUR SUR MSOLRE (LISTE DES TEMPS)          MSOLIT = 0
*     2.  POINTEUR SUR MSOLEN (LISTE DES PAS  )                   0
*     5.         ID.          (DEPLACEMENT    )                   2
*     6.         ID.          (CONTRAINTES    )                   5
*     7.         ID.          (VONMISES       )                   5
*     8.         ID.          (VITESSES       )                   2
*     9.         ID.          (ACCELERATIONS  )                   2
*     10.        ID.          (VARIABLES DE LIAISON)              2
*     13.        ID.          (VARIABLES D'USURE)                 2
*-----------------------------------------------------------------------
