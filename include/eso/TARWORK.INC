************************************************************************
*                INCLUDE DES VARIABLES DE TRAVAIL ARPACK               *
************************************************************************

      SEGMENT MAUP
        INTEGER ido
        CHARACTER*1 bmat
        CHARACTER*2 which
        REAL*8 tol
        REAL*8 resid(ndim)
        INTEGER info
        INTEGER nev
        REAL*8  v(ndim,ncv)
        INTEGER iparam(11)
        INTEGER ishift
        INTEGER ipntr(lipntr)
        REAL*8 workd(3*ndim)
        REAL*8 workl(lworkl)
        LOGICAL eigvec
        CHARACTER*1 howmny
        LOGICAL select(ncv)
        REAL*8 dr(lnev)
        REAL*8 di(lnev)
        INTEGER ldv
        REAL*8 sigmar
        REAL*8 sigmai
        REAL*8 workev(3*ncv)
      ENDSEGMENT

*  IDO     Integer.  (INPUT/OUTPUT)
*          Reverse communication flag.  IDO must be zero on the first
*          call to d-aupd . IDO will be set internally to
*          indicate the type of operation to be performed.
*
*  BMAT    Character*1.  (INPUT)
*          BMAT specifies the type of the matrix B that defines the
*          semi-inner product for the operator OP.
*          B = 'I' -> standard eigenvalue problem A*x = lambda*x
*          B = 'G' -> generalized eigenvalue problem A*x = lambda*B*x
*
*  TOL     Double precision
*          Tolerance
*
*  NDIM    Integer.  (INPUT)
*          Dimension of the eigenproblem.
*
*  WHICH   Character*2.  (INPUT)
*          Specify which of the Ritz values of OP to compute.
*
*          'LA' - compute the NEV largest (algebraic) eigenvalues.
*          'SA' - compute the NEV smallest (algebraic) eigenvalues.
*          'LM' - compute the NEV largest (in magnitude) eigenvalues.
*          'SM' - compute the NEV smallest (in magnitude) eigenvalues.
*          'BE' - compute NEV eigenvalues, half from each end of the
*                 spectrum.  When NEV is odd, compute one more from the
*                 high end than from the low end.
*          'SM' -> want the NEV eigenvalues of smallest magnitude.
*          'LR' -> want the NEV eigenvalues of largest real part.
*          'SR' -> want the NEV eigenvalues of smallest real part.
*          'LI' -> want the NEV eigenvalues of largest imaginary part.
*          'SI' -> want the NEV eigenvalues of smallest imaginary part
*
*  NEV (=lnev-1)  Integer.  (INPUT)
*                 Number of eigenvalues of OP to be computed
*
*  RESID   Double precision  array of length N.  (INPUT/OUTPUT)
*          On INPUT:
*          If INFO .EQ. 0, a random initial residual vector is used.
*          If INFO .NE. 0, RESID contains the initial residual vector,
*                          possibly from a previous run.
*          On OUTPUT:
*          RESID contains the final residual vector.
*
*  NCV     Integer.  (INPUT)
*          Number of columns of the matrix V (less than or equal to N).
*          This will indicate how many Arnoldi vectors are generated
*          at each iteration.
*
*  V       REAL*8  N by NCV array.  (OUTPUT)
*          After the factorisation building:
*          The NCV columns of V contain the Arnoldi basis vectors.
*          After the post-processing:
*          The NCV columns of V contain the eigenvectors
*
*          Note : If the eigenpairs are complex, an eigenvector is
*          containted in two colums : the first is the real part and
*          the next one is the imaginary part. The conjugated one is
*          implicit
*
*  LDV     Integer.  (INPUT)
*          Leading dimension of V exactly as declared in the calling
*          program.
*
*  IPARAM  Integer array (INPUT/OUTPUT)
*
*          Note : Only the most relevant parameters are described below
*
*          IPARAM(3) = MXITER
*          On INPUT:  maximum number of Arnoldi update
*          iterations allowed.
*          On OUTPUT: actual number of Arnoldi update iterations taken.
*
*          IPARAM(5) = NCONV: number of "converged" Ritz values.
*          This represents the number of Ritz values that satisfy
*          the convergence criterion.
*
*          IPARAM(7) = MODE
*          On INPUT determines what type of eigenproblem is being
*          solved.
*          Must be 1,2,3,4,5; See under \Description of d-aupd  for the
*          five modes available.
*
*          IPARAM(9) = NUMOP, IPARAM(10) = NUMOPB, IPARAM(11) = NUMREO,
*          OUTPUT: NUMOP  = total number of OP*x operations,
*                  NUMOPB = total number of B*x operations if BMAT='G',
*                  NUMREO = total number of steps of
*          re-orthogonalization.
*
*  IPNTR   Integer array (OUTPUT)
*          Pointer to mark the starting locations in the WORKD and WORKL
*          arrays for matrices/vectors used by the Lanczos iteration.
*
*  WORKD   Double precision  work array of length 3*N.
*          (REVERSE COMMUNICATION)
*          Distributed array to be used in the basic Arnoldi iteration
*          for reverse communication.
*
*  WORKL   Double precision  work array of length LWORKL.
*          OUTPUT/WORKSPACE)
*          Private (replicated) array on each PE or array allocated on
*          the front end.
*
*  INFO    Integer.  (INPUT/OUTPUT)
*          Information about the reason of the exit from d--pd
*
*  RVEC    LOGICAL  (INPUT)
*          Specifies whether a basis for the invariant subspace
*          corresponding to the converged Ritz value approximations for
*          the eigenproblem A*z = lambda*B*z is computed.
*
*             RVEC = .FALSE.     Compute Ritz values only.
*             RVEC = .TRUE.      Compute the Ritz vectors or
*             Schur vectors.
*
*  HOWMNY  Character*1  (INPUT)
*          Specifies the form of the basis for the invariant subspace
*          corresponding to the converged Ritz values that is to be
*          computed.
*
*          = 'A': Compute NEV Ritz vectors;
*          = 'P': Compute NEV Schur vectors;
*          = 'S': compute some of the Ritz vectors, specified
*                 by the logical array SELECT.
*
*  SELECT  Logical array of dimension NCV.  (INPUT)
*          No longer used (we always compute all eigenvectors)
*
*  DR      REAL*8  array of dimension NEV+1.  (OUTPUT)
*          Contains the real part of the eigenvalues ONLY IF the shift
*          is real. Otherwise, eigenvalues has to be computed with the
*          Rayleigh's quotients
*
*  DI      REAL*8  array of dimension NEV+1.  (OUTPUT)
*          (Used only if the problem is non-symmetric)
*          Contains the imaginary part of the eigenvalues ONLY IF
*          the shift is real. Otherwise, eigenvalues has to be computed
*          with the Rayleigh's quotients
*
*  SIGMAR  Double precision   (INPUT)
*          Real part of the shift
*
*  SIGMAI  Double precision   (INPUT)
*          Imaginary part of the shift.
*
*  WORKEV  Double precision  work array of dimension 3*NCV  WORKSPACE)


      SEGMENT MRITRA
        INTEGER RIGI(NB)
        INTEGER SYME(NB)
      ENDSEGMENT


* RIGI(NB) INTEGER array of dimension NB
*          Array for the pointers of the operators used by ARPACK
*
*
* SYME(NB) INTEGER array of dimension NB
*          Indicates if the corresponding operator (see RIGI) symmetric
*          - 0  : symmetric
*          - 1  : indefinite





