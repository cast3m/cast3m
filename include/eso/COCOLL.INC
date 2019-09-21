C      -INC COCOLL
C  structure d'echange COL
      integer piComm
      integer colltopo
      integer cointeco
      integer mpicomWo
      integer mpicomca
      integer mpiTyFlo
      integer mpiTyEnt
      integer mpiTyCha
      integer mpiTyPac
      integer mpiTyLog
      common /cocoll/ piComm
      common /cocoll/ colltopo
      common /cocoll/ cointeco
      common /cocoll/ mpicomWo, mpicomca
      common /cocoll/ mpiTyFlo, mpiTyEnt, mpiTyCha, mpiTyPac, mpiTyLog
      character*10 motext(2)
      integer idcext(2)
      data motExt/'CASTEM','DUMMY_CAST'/
      data idcext/12,24/

