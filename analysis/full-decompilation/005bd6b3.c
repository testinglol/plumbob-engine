
undefined4 * FUN_005bd6b3(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = **(int **)(unaff_EBP + 8);
  uVar3 = (*(int **)(unaff_EBP + 8))[1] - iVar2;
  if (uVar3 < uVar1) {
    FUN_004064df();
  }
  else {
    uVar3 = uVar3 - uVar1;
    *(uint *)(unaff_EBP + 8) = uVar3;
    piVar4 = (int *)(unaff_EBP + 8);
    if (*(uint *)(unaff_EBP + 0x10) <= uVar3) {
      piVar4 = (int *)(unaff_EBP + 0x10);
    }
    FUN_00401a3c(iVar2 + uVar1,*piVar4 + iVar2 + uVar1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

