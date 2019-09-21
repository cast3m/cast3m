*
* sert à reperer le passage  vecteur de matrice vers chpoint
*
      SEGMENT MVECRI
* melzon(MSOUPO) ce sont les pointeurs des segments meleme
* des msoupo zonze du chpoint
         INTEGER MELZON(NSOUPO)
* NUMNOM(I)  dit le nombre d'inconnues dans le ieme zone
         INTEGER NUMNOM(NSOUPO)
	 integer NUMNOE(NSOUPO)
* NOMINC(I,J) donne la jeme inconnu de la ieme zone
         CHARACTER*4 NAMINC(NSOUPO,MAXINC),NAMDUA(NSOUPO,MAXINC)
         INTEGER     NUMHAR(NSOUPO,MAXINC)
* NUMZON(i) dit dans quel zone va la ieme valeur du vecteur
         INTEGER NUMZON(IDIMVE)
* NUNOLO (i) donne la position du noeud dans la zone
         INTEGER NUNOLO(IDIMVE)
* NUINLO(i)  donne la position de l'inconnue dans la zone
         INTEGER NUINLO(IDIMVE)

      ENDSEGMENT

