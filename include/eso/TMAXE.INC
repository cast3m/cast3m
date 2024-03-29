*
*   TMAXE
*  OBJET AXE
*       XINF XSUP : BORNE SUR L'AXE X
*       YINF YSUP : BORNE SUR L'AXE Y
*       XINT YINT : GRADUATION ELEMENTAIRE DES AXES X ET Y
*       INX INY   : NOMBRE DE SEGMENTS ELEMENTAIRES
*       IPOSX IPOSY : POSITION DU TITRE DES AXES X ET Y
*       MXFMT MYFMT : FORMAT IMPOSE DES TITRES DES AXES
*       ZLOGX : AXE X EN LOG
*       ZLOGY : AXE Y EN LOG
*       ZGRILL : AFFICHAGE D'UNE GRILLE SUR LES AXES EN LOG
*       ZCARRE : FENETRE CARREE
*       BG : MARGE A GAUCHE DE L'AXE EN COORDONNEES UTILISATEUR
*       BD : MARGE A DROITE DE L'AXE EN COORDONNEES UTILISATEUR
*       BB : MARGE EN BAS   DE L'AXE EN COORDONNEES UTILISATEUR
*       BH : MARGE EN HAUT  DE L'AXE EN COORDONNEES UTILISATEUR
*
      SEGMENT AXE
           REAL*8 XINF,YINF,XSUP,YSUP,XINT,YINT
           INTEGER INX,INY,IPOSX,IPOSY
           LOGICAL ZLOGX,ZLOGY,ZGRILL,ZCARRE
           REAL*8 BG,BD,BB,BH
           CHARACTER*20 TITREX,TITREY
           CHARACTER*8 MXFMT,MYFMT
      ENDSEGMENT
