
undefined4 * FUN_0046bed4(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  int *piVar5;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = *(undefined4 *)(iVar1 + 8);
  extraout_ECX[1] = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = FUN_0043acf5(*extraout_ECX);
  if (iVar1 == 0) {
    FUN_005d4bbf(&DAT_006c4ab8);
    FUN_005d4bbf(&DAT_006c4ab0);
  }
  else {
    FUN_004573f9();
    uVar2 = thunk_FUN_00457ea7();
    FUN_005d499c(uVar2);
    iVar1 = FUN_00457e1c();
    if (iVar1 != 0) {
      piVar5 = *(int **)(iVar1 + 0x10);
      if (piVar5 != (int *)0x0) {
        iVar4 = 0;
        if (0 < *(int *)(iVar1 + 4)) {
          do {
            iVar3 = *piVar5;
            if (*(int *)(iVar3 + 0x18) == extraout_ECX[1]) goto LAB_0046bf73;
            iVar4 = iVar4 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar4 < *(int *)(iVar1 + 4));
        }
      }
      iVar3 = 0;
LAB_0046bf73:
      if (iVar3 != 0) {
        FUN_005d499c(iVar3 + 0x24);
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

