C=======================================================================
C
c     Segment type 'minte'
c     Segment definissant l'integration des champs.
C     Ce segment contient les informations nécessaires sur les points de
C     Gauss pour utiliser les formules d'intégration numérique
C
C        Tailles
C              nbpgau : nombre de points d'integration
C              nbno   : nombre de noeud
C
C		04/04/14: Modif GF: Declaration du segment en utilisant la derniere specif Esope
C
C
C=======================================================================

      SEGMENT MINTE
C        Poids des points de gauss
         real*8 poigau(nbpgau)

C        Coordonnées des points de Gauss
         real*8 qsigau(nbpgau)
         real*8 etagau(nbpgau)
         real*8 dzegau(nbpgau)

C        Valeur des fonctions de forme aux points de Gauss et de leurs dérivées
         real*8 shptot(6,nbno,nbpgau)
      ENDSEGMENT

C     Pointeurs par defaut
      pointeur minte1.MINTE
      pointeur minte2.MINTE
