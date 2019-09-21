C ACT3      SOURCE    PV        19/01/31    21:15:00     10091
      SUBROUTINE ACT3
C--------------------------------------------------------------------
C              ACCELERATION POUR DES CHAMPOINTS
C
C   APPELE DANS INCREME
C
C   LIT DANS L'ORDRE 3 CHAMPS PRIMAUX
C                 ET 4 CHAMPS DE DUAUX
C
C   REND UN CHAMP PRIMAL EXTRAPOLE QUI MINIMISE LE CHAMP DUAL.
C   METHODE : ON ESTIME L'APPLICATION TANGENTE ET ON L'UTILISE
C   POUR RESOUDRE LE PROBLEME
C
C--------------------------------------------------------------------
C
C   AOUT 97 : RAJOUTE L'ACCELERATION AVEC 2 OU 3 CHAMPS DE DEPLACEMENTS
C
C   CHAT 05/10/2007 : suppression de la limitation à certaines composantes
C
C   PM 19/07/2007 : cas à 2 points mettait IDCH0 à 0 au lieu de IDCH1
C
C--------------------------------------------------------------------
      IMPLICIT INTEGER(I-N)
      IMPLICIT REAL*8(A-H,O-Z)
-INC CCREEL
-INC SMCHPOI
-INC SMELEME
-INC SMLMOTS
-INC CCOPTIO
        xref=1d-6
C
C  FABRICATION DES LISTMOTS
C
      JGN=4
      JGM=100
      SEGINI MLMOTS
      JGM=0

      MLMOTF=MLMOTS
*
      CALL LIROBJ('CHPOINT',ICHD2,1,IRETOU)
      CALL LIROBJ('CHPOINT',ICHD1,1,IRETOU)
      CALL LIROBJ('CHPOINT',ICHD0,1,IRETOU)
      CALL LIROBJ('CHPOINT',IFO3 ,1,IRETOU)
      CALL LIROBJ('CHPOINT',IFO2 ,1,IRETOU)
      CALL LIROBJ('CHPOINT',IFO1 ,1,IRETOU)
      CALL LIROBJ('CHPOINT',IFO0 ,1,IRETOU)
      IF (IERR.NE.0) RETURN

*     Acceleration avec 3 points
      IF (ICHD2.EQ.ICHD1) THEN
       write(6,*) ' acceleration sur 3 points '
          ICHD2 = 0
          IFO3  = 0
       ENDIF

*     Acceleration avec 2 points
      IF (ICHD1.EQ.ICHD0) THEN
       write(6,*) ' acceleration sur 2 points '
          ICHD2 = 0
*PM          ICHD0 = 0
          ICHD1 = 0
          IFO3  = 0
          IFO2  = 0
       ENDIF

*
*     Recherche des noms de composante des forces
*
      MCHPOI=IFO3
      IPA=1
    1 CONTINUE
      IF (MCHPOI.NE.0) THEN
         SEGACT MCHPOI
         DO IA=1,IPCHP(/1)
            MSOUPO=IPCHP(IA)
            SEGACT MSOUPO
            DO IB=1,NOCOMP(/2)
               DO IC=1,JGM
                  IF (MOTS(IC).EQ.NOCOMP(IB)) GO TO 2
               ENDDO
**             write (6,*) ' act3 ncomp ',nocomp(ib)
               if (nocomp(ib).eq.'FLX ') goto 2


*         on ajoute la nouvelle composante à la liste
               JGM=JGM+1
               IF (JGM.GT.MOTS(/2)) THEN
                  SEGADJ MLMOTS
               ENDIF
               MOTS(JGM)=NOCOMP(IB)
 2             CONTINUE
            ENDDO
         ENDDO
      ENDIF
*     On fait de même pour les trois autres champs en entrée
      IF (IPA.EQ.1) THEN
          IPA=2
          MCHPOI=IFO2
          GO TO 1
      ELSEIF(IPA.EQ.2) THEN
          IPA=3
          MCHPOI=IFO1
          GO TO 1
      ELSEIF(IPA.EQ.3) THEN
          IPA=4
          MCHPOI=IFO0
          GO TO 1
      ENDIF
      SEGADJ MLMOTS
*
*     On utilise un procédé d'orthogonalisation de Schmidt
*     pour obtenir une base de l'espace engendrée par les quatre forces
*     puis on effectue la projection (de coordonnées XL, XM et XN) du
*     champ de force nulle sur cet espace
*
      IF (IFO3.NE.0) THEN

*     CAS  A 4 POINTS :
*     -----------------
*     famille des 3 vecteurs variations du champ dual
      CALL ADCHPO(IFO1,IFO0,IFO10,1D0,-1D0)
      CALL ADCHPO(IFO2,IFO0,IFO20,1D0,-1D0)
      CALL ADCHPO(IFO3,IFO0,IFO30,1D0,-1D0)
*
      CALL XTX1(IFO10,F12)
      CALL XTX1(IFO20,F22)
      CALL XTX1(IFO30,F32)
      if(f12.LT.XPETIT*1d2) f12=XPETIT*1d2
      if(f22.LT.XPETIT*1d2) f22=XPETIT*1d2
      if(f32.LT.XPETIT*1d2) f32=XPETIT*1d2
*     write (6,*) ' dans act3 f12/f22 ',f12/f22,f12/f32
*
*     Détection de flip-flop ?
*     (1 et 3 sont trop proches, malgré 2 différent de 1)
      if (f12/f22.gt.1.2d0 .and. f12/f32.gt.0.707d0 .and.
     >       f12/f32.lt.1.414d0) then
*       act3 : plan B
        CALL ERREUR(858)
        XL = (sqrt(f12)+sqrt(f22))/(2*sqrt(f12))
        XM = 0.
        XN = 0.
        GOTO 1010
      endif
*
*     Construction d'une famille libre orthogonale
      CALL XTY1(IFO10,IFO20,MLMOTF,MLMOTF,F1F2)
      CALL XTY1(IFO10,IFO30,MLMOTF,MLMOTF,F1F3)
      CALL XTY1(IFO20,IFO30,MLMOTF,MLMOTF,F2F3)
      CALL XTY1(IFO0 ,IFO10,MLMOTF,MLMOTF,F0F1)
      CALL XTY1(IFO0 ,IFO20,MLMOTF,MLMOTF,F0F2)
      CALL XTY1(IFO0 ,IFO30,MLMOTF,MLMOTF,F0F3)
*
*  normalisation pour ameliorer la precision
*  les iteres successives pouvant diminer pas mal si on converge
*     A1  =  F12
*     B1  =  F1F2
*     C1  =  F1F3
*     XJ1 = -F0F1
*     D1  =  F1F2
*     E1  =  F22
*     F1  =  F2F3
*     XK1 = -F0F2
*     G1  =  F1F3
*     H1  =  F2F3
*     XI1 =  F32
*     XL1 = -F0F3
      A1  =  1.d0
      B1  =  F1F2/f12
      C1  =  F1F3/f12
      XJ1 = -F0F1/f12
      D1  =  F1F2/f22
      E1  =  1.D0
      F1  =  F2F3/f22
      XK1 = -F0F2/f22
      G1  =  F1F3/f32
      H1  =  F2F3/f32
      XI1 =  1.d0
      XL1 = -F0F3/f32



*     write (6,*) ' f12 f22 f32 ',f12,f22,f32

*     Calcul des coordonnées de IFO0 dans la famille libre
*     et élimination des vecteurs liés
      IF (ABS(XI1) .LT. xpetit) GOTO 2000
*
      A2  = A1  - ( G1*C1/XI1)
      B2  = B1  - ( H1*C1/XI1)
      XJ2 = XJ1 - (XL1*C1/XI1)
      D2  = D1  - ( G1*F1/XI1)
      E2  = E1  - ( H1*F1/XI1)
      XK2 = XK1 - (XL1*F1/XI1)
*
      IF (E2 .LE. e1*xref) THEN
*           write (6,*) ' act3 e2 e1 ',e2,e1
         GOTO 2000
      ENDIF
*
      A3  = A2 -( D2*B2/E2)
      XJ3 = XJ2-(XK2*B2/E2)
*
      IF (A3 .LE. a1*xref) THEN
*           write (6,*) ' act3 a3 a1 ',a3,a1
         GOTO 2000
      ENDIF
      IF (ABS(A2) .LE. A1*1d-6) THEN
*           write (6,*) ' act3 a2 a1 ',a2,a1
         GOTO 2000
      ENDIF

      XL=XJ3/A3
      if (xl .gt.1.D0) then
**         write(6,*) ' act3 xl > 0 ==> pas d acceleration'
           goto 2000
      endif
*
      B4  = B2
      XJ4 = XJ2 - (A2*XL)


*
      IF (ABS(B4) .LE. ABS(B1)*1D-6) THEN
*           write (6,*) ' act3 b4 b1 ',b4,b1
         GOTO 2000
      ENDIF
*
      XM  = XJ4/B4
*
      C5  = C1
      XJ5 = XJ1 - (A1*XL) - (B1*XM)
*
      IF (ABS(C5) .LT. xref) GOTO 2000
*
      XN=XJ5/C5
*
      ref=sqrt(a1**2+b1**2+c1**2)
*     write (6,*) ' act3 ',ref,XI1,A3,b4,c5
*     write (6,*) ' act3 a3 e2 xi1 ',a3,e2,xi1
      if (a3.lt.a1*xref.or.e2.lt.e1*xref) then
      write (6,*) ' act3 operateur secant non positif'
       goto 2000
      endif
      GOTO 1010

 2000 CONTINUE
*     le systeme est singulier on essaye avec un vecteur de moins
*
*     write (6,*) ' act3 ',xi1,e2,e1,a3,a1,b4,b1,c5
      IF (ABS(E1) .LT. xref) GOTO 2100
*
      A2  = A1  - (D1 *B1/E1)
      XJ2 = XJ1 - (XK1*B1/E1)
*
      IF (A2 .LE. A1*xref) THEN
*        write (6,*) ' act3 a2 a1 ',a2,a1
         GOTO 2100
      ENDIF
*
      XL  = XJ2/A2
      if (xl .gt.1.D0) then
**         write(6,*) ' act3 xl > 0 ==> pas d acceleration'
           goto 2100
      endif
*
      B3  = B1
      XJ3 = XJ1 - (A1*XL)
*
      IF (ABS(B3) .LT. xref) GOTO 2100
*
      XM = XJ3/B3
*
      XN = 0

      if (a2.lt.a1*xref) then
*     write (6,*) ' act3 a2 a1  ',a2,e1
       write (6,*) ' act3 operateur secant non positif'
       goto 2100
      endif
*     act3 : reduction a %i1 dimensions
      INTERR(1)=2
       CALL ERREUR(859)
      GOTO 1010

 2100 CONTINUE
*     le systeme est singulier on essaye avec un vecteur de moins
*
      IF (ABS(A1) .LT. xref ) GOTO 1000
*
      XL  = XJ1/A1
      if (xl .gt.1.D0) then
**         write(6,*) ' act3 xl > 0 ==> pas d acceleration'
           goto 1000
      endif
*
      XM  = 0
      XN  = 0

*     act3 : reduction a %i1 dimensions
*     write (6,*) ' act3 a1 ',a1
      INTERR(1)=1

      CALL ERREUR(859)
      GOTO 1010

 1000 CONTINUE
*     act3 : pas d accélération
      call erreur(860)
      XL = 0
      XM = 0
      XN = 0

 1010 CONTINUE
*
*     WRITE (6,*) ' f12*f22/(f1f2*2) ',f12*f22/(f1f2**2)
*     WRITE (6,*) ' f12*f32/(f1f3*2) ',f12*f32/(f1f3**2)
*     WRITE (6,*) ' f22*f32/(f2f3*2) ',f22*f32/(f2f3**2)
*     write (6,*) ' xi1,e2,a3,b4,c5 ',xi1,e2,a3,b4,c5
*     write (6,*) ' coefficients acc ',-xl,-xm,-xn
*     xl=sign(min(abs(xl),1d1),xl)
*     xm=sign(min(abs(xm),1d1),xm)
*     xn=sign(min(abs(xn),1d1),xn)
*     write (6,*) ' coefficients cor ',-xl,-xm,-xn

*     Vérification qu'on ne retombe pas sur l'un des duals entrés
*     Sinon, on réessaye en tenant compte de moins de vecteurs
      if (abs(xl-1).lt.1e-1 .and. abs(xm).lt.1e-1
     >                      .and. abs(xn).lt.1e-1) goto 1000
      if (abs(xm-1).lt.1e-1 .and. abs(xn).lt.1e-1
     >                      .and. abs(xl).lt.1e-1) goto 2100
      if (abs(xn-1).lt.1e-1 .and. abs(xl).lt.1e-1
     >                      .and. abs(xm).lt.1e-1) goto 2000
*
      CALL ADCHPO(ICHD0,ICHD1,ITEMP4,XL+XM+XN,XM+XN)
      CALL ADCHPO(ICHD2,ITEMP4,ITEMP5,XN,1D0)
*
*     ajustement de la nature du champ
*     on prend la meme nature que ICHDO
      MCHPOI = ICHD0
      MCHPO1 = ITEMP5
      SEGACT MCHPOI,MCHPO1
      NAT    = JATTRI(/1)
      NSOUPO = MCHPO1.IPCHP(/1)
      SEGADJ MCHPO1
      DO 1020 I=1,NAT
        MCHPO1.JATTRI(I)=JATTRI(I)
 1020 CONTINUE
      SEGDES MCHPOI,MCHPO1
*
*     Affectation
*
      CALL ECROBJ('CHPOINT',ITEMP5)
*
*     Quelques destructions
*
      MLMOTS=MLMOTF
      SEGSUP MLMOTS
      CALL DTCHPO(IFO10)
      CALL DTCHPO(IFO20)
      CALL DTCHPO(IFO30)
      CALL DTCHPO(ITEMP4)
      RETURN
      ENDIF

*     CAS  A 3 POINTS :
*     -----------------
*     famille des 2 vecteurs variations du champ dual
      IF (IFO2.NE.0.AND.IFO3.EQ.0) THEN
      CALL ADCHPO(IFO1,IFO0,IFO10,1D0,-1D0)
      CALL ADCHPO(IFO2,IFO0,IFO20,1D0,-1D0)
*
      CALL XTX1(IFO10,F12)
      CALL XTX1(IFO20,F22)
*
*     Construction d'une famille libre orthogonale
      CALL XTY1(IFO10,IFO20,MLMOTF,MLMOTF,F1F2)
      CALL XTY1(IFO0 ,IFO10,MLMOTF,MLMOTF,F0F1)
      CALL XTY1(IFO0 ,IFO20,MLMOTF,MLMOTF,F0F2)
*
*      A1  =  F12
*      B1  =  F1F2
*      XJ1 = -F0F1
*      D1  =  F1F2
*      E1  =  F22
*      XK1 = -F0F2
      A1  =  1.d0
      B1  =  F1F2/F12
      XJ1 = -F0F1/F12
      D1  =  F1F2/F22
      E1  =  1.D0
      XK1 = -F0F2/F22
*
*     Calcul des coordonnées de IFO0 dans la famille libre
*     et élimination des vecteurs liés
      IF (ABS(E1) .LT. xref ) GOTO 2200
*
      A2  = A1  - (D1 *B1/E1)
      XJ2 = XJ1 - (XK1*B1/E1)
*
      IF (A2 .LE. A1*xref) THEN
*        write (6,*) ' act3 a2 a1 ',a2,a1
         GOTO 2200
      ENDIF
*
      XL  = XJ2/A2
*
      B3  = B1
      XJ3 = XJ1 - (A1*XL)
*
      IF (ABS(B3) .LT. xref) GOTO 2200
*
      XM  = XJ3/B3
*
      XN  = 0
*
*     write (6,*) ' act3 xl xm ',xl,xm
      GOTO 1210

 2200 CONTINUE
*     le systeme est singulier on essaye avec un vecteur de moins
*
      IF (A1 .LT. xref ) GOTO 2300
*
      XL  = XJ1/A1
*
      XM  = 0
      XN  = 0
*
*     act3 : reduction a %i1 dimensions
      INTERR(1)=1
*      CALL ERREUR(859)
      GOTO 1210

 2300 CONTINUE
*     act3 : pas d accélération
      call erreur(860)
      XL  = 0
      XM  = 0
      XN  = 0

 1210 CONTINUE
*     Vérification qu'on ne retombe pas sur l'un des duals entrés
*     Sinon, on réessaye en tenant compte de moins de vecteurs
      if (abs(xl-1).lt.1e-1.and.abs(xm).lt.1e-1.and.
     >    abs(xn).lt.1e-1) goto 2300
      if (abs(xm-1).lt.1e-1.and.abs(xn).lt.1e-1.and.
     >    abs(xl).lt.1e-1) goto 2200
*      if (abs(xn-1).lt.1e-1.and.abs(xl).lt.1e-1.and.
*     >    abs(xm).lt.1e-1) goto 2300
*
      CALL ADCHPO(ICHD0,ICHD1,ITEMP5,XL+XM,XM)
*
*     ajustement de la nature du champ
*     on prend la meme nature que ICHDO
*
      MCHPOI = ICHD0
      MCHPO1 = ITEMP5
      SEGACT MCHPOI,MCHPO1
      NAT    = JATTRI(/1)
      NSOUPO = MCHPO1.IPCHP(/1)
      SEGADJ MCHPO1
      DO 1220 I=1,NAT
        MCHPO1.JATTRI(I)=JATTRI(I)
 1220 CONTINUE
      SEGDES MCHPOI,MCHPO1
*
*     Affectation
*
      CALL ECROBJ('CHPOINT',ITEMP5)
*
*     Quelques destructions
*
      MLMOTS=MLMOTF
      SEGSUP MLMOTS
      CALL DTCHPO(IFO10)
      CALL DTCHPO(IFO20)
      RETURN
      ENDIF

*     CAS  A 2 POINTS :
*     -----------------
      IF (IFO2.EQ.0) THEN
      CALL ADCHPO(IFO1,IFO0,IFO10,1D0,-1D0)
*
      CALL XTX1(IFO10,F12)
*
*     Un seul vecteur = famille libre d'emblée
      CALL XTY1(IFO0,IFO10,MLMOTF,MLMOTF,F0F1)
*
*      A1  =  F12
*      XJ1 = -F0F1
      A1  =  1.D0
      XJ1 = -F0F1/F12
*
      IF (ABS(A1) .LT. xref ) GOTO 1100
*
      XL  = XJ1/A1
*
      XM  = 0
      XN  = 0
      GOTO 1110

 1100 CONTINUE
*     act3 : pas d accélération
      call erreur(860)
      XL = 0
      XM = 0
      XN = 0

 1110 CONTINUE
      if (abs(xl-1).lt.1e-1) goto 1100
      CALL MUCHPO(ICHD0,XL,ITEMP5,1)
*     write (6,*) ' act3 xl vaut ',xl
*
*     ajustement de la nature du champ
*     on prend la meme nature que ICHDO
*
      MCHPOI = ICHD0
      MCHPO1 = ITEMP5
      SEGACT MCHPOI,MCHPO1
      NAT = JATTRI(/1)
      NSOUPO = MCHPO1.IPCHP(/1)
      SEGADJ MCHPO1
      DO 1120 I=1,NAT
        MCHPO1.JATTRI(I)=JATTRI(I)
 1120 CONTINUE
      SEGDES MCHPOI,MCHPO1
*
*     Affectation
*
      CALL ECROBJ('CHPOINT',ITEMP5)
*
*     QUELQUES DESTRUCTIONS
*
      MLMOTS=MLMOTF
      SEGSUP MLMOTS
      CALL DTCHPO(IFO10)
      RETURN
      ENDIF
      END










