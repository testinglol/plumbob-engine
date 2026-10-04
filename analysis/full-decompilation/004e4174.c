
void FUN_004e4174(void)

{
  int iVar1;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar2;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  piVar2 = (int *)*extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar2 != (int *)extraout_ECX[1]) {
    do {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        FUN_004e41db();
        FUN_006321f0(iVar1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != (int *)extraout_ECX[1]);
  }
  FUN_0042ed71(*extraout_ECX,extraout_ECX[1]);
  iVar1 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x10) = iVar1;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

