
void FUN_00594673(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar3 = *(int *)(extraout_ECX + 8);
  piVar1 = (int *)(extraout_ECX + 4);
  iVar4 = 0;
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = iVar3 - iVar2 >> 3;
  if (0 < iVar3) {
    do {
      if (*(int *)(*piVar1 + 4 + iVar4 * 8) != 0) {
        FUN_005942ab();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  iVar3 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x10) = iVar3;
  FUN_00542b02();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

