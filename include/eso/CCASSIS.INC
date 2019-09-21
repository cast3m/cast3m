**    pour le fonctionnement des ASSISTANTs
**   """""""""""""""""""""""""""""""""""""""
**	04/04/14: Modif GF: declaration explicite des variables
**    utilisation par le MAITRE
**   """""""""""""""""""""""""""
**    NBESC  : nombre d'ASSISTANTs
**    NBESCR : nombre d'ASSISTANTs possibles
**    NBTHRS : nombre de threads possibles pour resou
**    MESCL  : liste des pointeurs sur les listes des instructions
**             pour les ASSISTANTs
**    IPCAR1 : pointeur sur la chaine contenant la ligne de commande
**             (pour les erreurs)
        common/cassis/nbesc,mescl(0:512),ipcar1,nbescr,nbthrs
        integer nbesc,mescl,ipcar1,nbescr,nbthrs
**
**    pour le decodage des objets et pour trouver l'instruction
**    LODESL : VRAI  dans l'operateur ASSIstant
**    LOTRMA : le maitre doit faire le travail d'un assistant
**    LOTESC : logique indiquant le fonctionnement en assistant
**    LODEFE : logique indiquant que opti assi est défini
      LOGICAL LODESL,LOTRMA,LOTESCPV,LODEFE,LOTESC
      common/cassi1/LODESL,LOTRMA,LOTESCPV,LODEFE
**
**    utilisation par un ASSISTANT
**   """"""""""""""""""""""""""""""
**    INASS1 : numero de l'ASSISTANT
**    IMESIN : pointeur sur le segment contenant la liste
**             des instructions pour un ASSISTANT
**    IMESCL : pointeur sur le segment contenant l'instruction
**             en cours de traitement
**    IMESTR : pointeur sur le segment MESTRA pour le gerer le MENAGE
**    IERRES : pointeur sur le segment MERRES des erreurs
      integer imesdm
      parameter (imesdm=64)
      common/cassi2/imescl(0:imesdm),imestr,ierres,imesou(0:imesdm)
      integer imescl,imestr,ierres
**
**
**
**    pour gerer le menage
**   """"""""""""""""""""""
        segment MESTRA
          integer IIIIII
        end segment
**
**    pour gerer les erreurs
**   """"""""""""""""""""""""
      segment MERRES
*   est on en situation d'erreur ?
          logical LOSIER
*   numero de l'assistant qui a gemerer l'erreur
          integer IASSER
*   nombre d'erreurs
          integer NBERR
*   liste des erreurs
          integer liserr(3,NERR)
      end segment
**
**    liste des instructions pour un ASSISTANT
**   """"""""""""""""""""""""""""""""""""""""""
        segment MESINS
*  numero de l assistant
        integer inass
*  liste des instructions chainees
          integer lismes(NINS)
*  nombre d'instructions chainees
          integer nbins
*  instruction courante (pour gerer le menage)
          integer inscou
        end segment
**
**    codage d'une instruction
**   """"""""""""""""""""""""""
      segment mescla
*  pointeur sur la chaine contenant la ligne de commande
*  (pour les erreurs)
        integer jpcar1
*  objets operandes
        integer imotlv
        logical esoplu(100)
        character*8 esopty(100)
        integer esopva(100)
        character*72 esopch(100)
        logical esoplo(100)
        real*8 esopre(100)
*  objets esclaves pour le retour
        integer esrees(100)
*  pour recuperer l'erreur eventuelle
        integer jjjerr
      endsegment
        pointeur mescl1.mescla,mescl2.mescla
**
**    codage d'un resultat (chapeau)
**   """""""""""""""""""""""""""""""
      segment mesres
* souci rencontrÃ© dans l'assistant
       INTEGER ESISOU
* pour savoir si l'objet a ete mis a jour par l'assistant
         LOGICAL LOREMP
* pointeur sur le resultat
       INTEGER IESRES
      endsegment
**
**    codage d'un resultat
**   """"""""""""""""""""""
      segment nesres
       character*8 esrety
       logical esrelo
       integer esreva
       character*72 esrech
       real*8 esrere
      endsegment
