
void FUN_004ed7a2(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  uint uVar4;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066979c;
  iVar2 = extraout_ECX[2];
  piVar1 = extraout_ECX + 1;
  uVar4 = 0;
  iVar3 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar2 - iVar3 >> 2 != 0) {
    do {
      iVar2 = **(int **)(*piVar1 + uVar4 * 4);
      if ((iVar2 == 3) || (iVar2 == 4)) {
        FUN_004ed555();
      }
      iVar2 = *(int *)(*piVar1 + uVar4 * 4);
      if (iVar2 != 0) {
        FUN_004ed447();
        FUN_006321f0(iVar2);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(extraout_ECX[2] - *piVar1 >> 2));
  }
  iVar2 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(unaff_EBP + -0x10) = iVar2;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

