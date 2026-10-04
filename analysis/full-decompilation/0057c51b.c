
void FUN_0057c51b(void)

{
  int *piVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar3;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  piVar1 = (int *)*extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  piVar3 = (int *)*piVar1;
  if (piVar3 != piVar1) {
    do {
      iVar2 = piVar3[2];
      if (iVar2 != 0) {
        FUN_0057c5c7();
        FUN_006321f0(iVar2);
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*extraout_ECX);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006029b3();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

