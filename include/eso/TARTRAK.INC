************************************************************************
*                INCLUDE DES VARIABLES DE TRACKING ARPACK              *
************************************************************************

*Trace output variables
      INTEGER  LOGFIL, NDIGIT, MGETV0,
     &         MSAUPD, MSAUP2, MSAITR, MSEIGT, MSAPPS, MSGETS, MSEUPD,
     &         MNAUPD, MNAUP2, MNAITR, MNEIGH, MNAPPS, MNGETS, MNEUPD,
     &         MCAUPD, MCAUP2, MCAITR, MCEIGH, MCAPPS, MCGETS, MCEUPD
      COMMON /DEBUG/
     &         LOGFIL, NDIGIT, MGETV0,
     &         MSAUPD, MSAUP2, MSAITR, MSEIGT, MSAPPS, MSGETS, MSEUPD,
     &         MNAUPD, MNAUP2, MNAITR, MNEIGH, MNAPPS, MNGETS, MNEUPD,
     &         MCAUPD, MCAUP2, MCAITR, MCEIGH, MCAPPS, MCGETS, MCEUPD


*Output variables
      INTEGER    NOPX, NBX, NRORTH, NITREF, NRSTRT

*nopx : Number of OP*X iterations
*nbx : Number of B*X iterations
*nrorth : number of reorthogonalization steps
*nitref : number of iterative refinement steps
*nrstrt : number of restart steps

*Time counting variables
      REAL*4       TSAUPD, TSAUP2, TSAITR, TSEIGT, TSGETS, TSAPPS,
     &             TSCONV,
     &           TNAUPD, TNAUP2, TNAITR, TNEIGH, TNGETS, TNAPPS, TNCONV,
     &           TCAUPD, TCAUP2, TCAITR, TCEIGH, TCGETS, TCAPPS, TCCONV,
     &           TMVOPX, TMVBX, TGETV0, TITREF, TRVEC
      COMMON /TIMING/
     &           NOPX, NBX, NRORTH, NITREF, NRSTRT,
     &           TSAUPD, TSAUP2, TSAITR, TSEIGT, TSGETS, TSAPPS, TSCONV,
     &           TNAUPD, TNAUP2, TNAITR, TNEIGH, TNGETS, TNAPPS, TNCONV,
     &           TCAUPD, TCAUP2, TCAITR, TCEIGH, TCGETS, TCAPPS, TCCONV,
     &           TMVOPX, TMVBX, TGETV0, TITREF, TRVEC


