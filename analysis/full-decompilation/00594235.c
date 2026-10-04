
void FUN_00594235(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  iVar3 = *(int *)(extraout_ECX + 8);
  piVar1 = (int *)(extraout_ECX + 4);
  iVar4 = 0;
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = iVar3 - iVar2 >> 3;
  *(int *)(unaff_EBP + -0x10) = iVar3;
  if (0 < iVar3) {
    do {
      iVar3 = *(int *)(*piVar1 + iVar4 * 8);
      if (iVar3 != 0) {
        FUN_0041d9a9(iVar3);
      }
      iVar3 = *(int *)(*piVar1 + 4 + iVar4 * 8);
      if (iVar3 != 0) {
        FUN_0041d9a9(iVar3);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_EBP + -0x10));
  }
  iVar3 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x14) = iVar3;
  FUN_00542b02();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

