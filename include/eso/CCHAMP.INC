*    -INC CCHAMP
*
*     STOCKE TOUS LES NOMS D ELEMENTS POSSIBLES
      CHARACTER*4     NOMTP
      COMMON /CHAMP/  NOMTP(500)
      COMMON/LCHAMP/ LNOMTP
*
*     NOMIN STOCKE LA MANIERE DINTEGRER LA RIGIDITE
      CHARACTER*8     NOMIN
      COMMON /CHAMP/  NOMIN(5)
      COMMON/LCHAMP/ LNOMIN
*
*     NOMFR STOCKE TOUTES LES FORMULATIONS POSSIBLES
      CHARACTER*8     NOMFR
      COMMON /CHAMP/  NOMFR(100)
      COMMON/LCHAMP/ LNOMFR
*
*     NOMCH STOCKE TOUS LES NOMS DE CHAMPS POSSIBLES
      CHARACTER*8     NOMCH
      COMMON /CHAMP/  NOMCH(100)
      COMMON/LCHAMP/ LNOMCH
*
*     NOMAT STOCKE TOUS LES NOMS DE MATERIAU POSSIBLES
      CHARACTER*8     NOMAT
      COMMON /CHAMP/  NOMAT(100)
      COMMON/LCHAMP/ LNOMAT
*
*     NOMDD STOCKE TOUS LES NOMS D INCONNUES POSSIBLES
      CHARACTER*4     NOMDD
      COMMON /CHAMP/  NOMDD(1000)
      COMMON/LCHAMP/ LNOMDD
*
*     NOMDU STOCKE TOUS LES NOMS DE FORCES POSSIBLES
      CHARACTER*4     NOMDU
      COMMON /CHAMP/  NOMDU(1000)
      COMMON/LCHAMP/ LNOMDU
*
*     NOMVI STOCKE TOUS LES NOMS DE VITESSES POSSIBLES
      CHARACTER*4     NOMVI
      COMMON /CHAMP/  NOMVI(100)
      COMMON/LCHAMP/ LNOMVI
*
*     NOMAC STOCKE TOUS LES NOMS D ACCELERATION POSSIBLES
      CHARACTER*4     NOMAC
      COMMON /CHAMP/  NOMAC(100)
      COMMON/LCHAMP/ LNOMAC
*
*     NOMST STOCKE TOUS LES NOMS DE CONTRAINTES POSSIBLES
      CHARACTER*4     NOMST
      COMMON /CHAMP/  NOMST(100)
      COMMON/LCHAMP/ LNOMST
*
*     NOMDF STOCKE TOUS LES NOMS DE DEFORMATIONS POSSIBLES
      CHARACTER*4     NOMDF
      COMMON /CHAMP/  NOMDF(100)
      COMMON/LCHAMP/ LNOMDF
*
*     NOMYO STOCKE TOUTES LES COMPOSANTES DES MATERIAUX POSSIBLES
      CHARACTER*4     NOMYO
      COMMON /CHAMP/  NOMYO(200)
      COMMON/LCHAMP/ LNOMYO
*
*     NOMCR STOCKE TOUTES LES  CARACTERISTIQUES POSSIBLES
      CHARACTER*4     NOMCR
      COMMON /CHAMP/  NOMCR(100)
      COMMON/LCHAMP/ LNOMCR
*
*     NOMHO STOCKE TOUS LES NOMS DES COEFF DE LA MATRICE DE HOOKE
      CHARACTER*4     NOMHO
      COMMON /CHAMP/  NOMHO(100)
      COMMON/LCHAMP/ LNOMHO
*
*     NOMVRI STOCKE TOUS LES NOMS DES VARIABLES INTERNES
      CHARACTER*4     NOMVRI
      COMMON /CHAMP/  NOMVRI(100)
      COMMON/LCHAMP/ LNOVRI
*
*     STOCKE TOUS LES COUPLES U/P POSSIBLES DANS LE CAS NAVIER_STOKES
      CHARACTER*4     NNAVI
      COMMON /CHAMP/  NNAVI(20)
      COMMON/LCHAMP/ LNNAVI
*
*     COUPLE D'ELEMENT NAVIER_STOKES COURANT
      COMMON /LCHAMP/ILNAVI
*
*  -END INCLUDE
