
*    -INC SMMODEL
*
*     OBJET DE TYPE "MODELE"
*
      PARAMETER (LCONMO=24)
      SEGMENT,MMODEL
         INTEGER KMODEL(N1)
      ENDSEGMENT
       POINTEUR MMODE1.MMODEL,MMODE2.MMODEL
*
      SEGMENT,IMODEL
         INTEGER IMAMOD,NEFMOD
         INTEGER INFMOD(MN3)
         CHARACTER*(LCONMO) CONMOD
         CHARACTER*8 CMATEE
         CHARACTER*16 FORMOD(NFOR),MATMOD(NMAT)
         INTEGER IPDPGE,IMATEE,INATUU,IDERIV
         INTEGER LNOMID(14),INFELE(16)
         CHARACTER*8 TYMODE(NOBMOD)
         INTEGER IVAMOD(NOBMOD)
      ENDSEGMENT
       POINTEUR IMODE1.IMODEL,IMODE2.IMODEL
*
*     KMODEL : POINTEUR SUR DES OBJETS MODELES ELEMENTAIRES
*     IMAMOD : POINTEUR SUR UN OBJET MAILLAGE ELEMENTAIRE
*     NEFMOD : NUMERO DE L'ELEMENT FINI DANS NOMTP
*     INFMOD : INFORMATIONS VARIEES RELATIVES AU MODELE
*     INFMOD(1) : NOMBRE DE PTS D'INTEGRATION DANS L'EPAISSEUR
*     INFMOD(2) : utilise en meca flux pour stocker une table
*     INFMOD(3) : segment integre pour les noeuds
*     INFMOD(4) : segment integre pour un champs constant
*     INFMOD(5) : segment integre pour rigidite
*     INFMOD(6) : segment integre pour masse
*     INFMOD(7) : segment integre pour contraintes
*     CONMOD : NOM DU CONSTITUANT
*     FORMOD : SUITE DE MOTS DEFINISSANT LA FORMULATION
*              (EX: THERMIQUE , LIQUIDE + MECANIQUE, ...)
*     MATMOD : SUITE DE MOTS CARACTERISANT LE TYPE DE MATERIAU
*              (EX: ORTHOTROPE, PLASTIQUE PARFAIT, ...)
*     IPDPGE : point support de deformations planes generalisées
*     PHAMOD : nom de la phase
*       la phase est maintenant rangée dans conmod(17:24)
C     IMATEE INATUU : variables imate inatu de nomate
C     IDERIV : type de la derivee 1 Lineaire (classique HPP)
C                                 2 quadratique
C                                 3 Truesdell
C                                 4 Jaumann
C                                 5 Utilisateur
C                                 6

*     TYMODE : type de l'objet dont le pointeur est dans IVAMOD
*     LNOMID : pointeurs vers des nomid l'ordre predefini est :
*
*     1              'DEPLACEM', 'FORCES  ', 'GRADIENT', 'CONTRAIN',
*     1              'DEFORMAT', 'MATERIAU', 'CARACTER', 'TEMPERAT',
*     1              'PRINCIPA', 'VARINTER', 'GRAFLEXI', 'VINMETAL',
*     1              'DEFINELA', 'PARAMEXT',/
* segment nomid utilitaire des modeles contient la liste des noms
* des differents champs
      SEGMENT NOMID
          CHARACTER*8 LESOBL(NBROBL),LESFAC(NBRFAC)
      ENDSEGMENT
* NBROBL : Nombre de composantes obligatoires
* LESOBL : Tableau des noms de composantes obligatoires

* NBRFAC : Nombre de composantes facultatives
* LESFAC : Tableau des noms de composantes facultatives
