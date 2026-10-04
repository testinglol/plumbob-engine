
void FUN_0046ee09(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int iVar3;
  int *piVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  iVar5 = *(int *)(unaff_EBP + 0xc);
  iVar1 = (extraout_ECX[1] - *extraout_ECX) / 0xc;
  iVar3 = iVar5 + 1;
  if (iVar1 < iVar3) {
    iVar3 = iVar3 - iVar1;
    do {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0046ef44(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar1 = *(int *)(unaff_EBP + 8);
  iVar5 = iVar5 * 0xc;
  iVar3 = iVar1 + 1;
  piVar4 = (int *)(iVar5 + *extraout_ECX);
  iVar2 = piVar4[1] - *piVar4 >> 2;
  if (iVar2 < iVar3) {
    *(int *)(unaff_EBP + 0xc) = iVar3 - iVar2;
    do {
      *(undefined4 *)(unaff_EBP + 8) = 0;
      FUN_0046ef6c(unaff_EBP + 8);
      piVar4 = (int *)(unaff_EBP + 0xc);
      *piVar4 = *piVar4 + -1;
    } while (*piVar4 != 0);
  }
  *(undefined4 *)(*(int *)(iVar5 + *extraout_ECX) + iVar1 * 4) = *(undefined4 *)(unaff_EBP + 0x10);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

