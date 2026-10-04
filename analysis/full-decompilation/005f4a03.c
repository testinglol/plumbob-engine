
undefined4 * FUN_005f4a03(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int *extraout_ECX;
  int iVar5;
  int *piVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  iVar5 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if ((uint)(iVar5 - *extraout_ECX) < uVar1) {
    FUN_004064df();
  }
  iVar5 = *extraout_ECX;
  piVar6 = (int *)(unaff_EBP + 0xc);
  uVar4 = (extraout_ECX[1] - iVar5) - uVar1;
  *(uint *)(unaff_EBP + 0xc) = uVar4;
  if (*(uint *)(unaff_EBP + 0x10) <= uVar4) {
    piVar6 = (int *)(unaff_EBP + 0x10);
  }
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  iVar5 = iVar5 + uVar1;
  iVar3 = *piVar6;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00401a3c(iVar5,iVar5 + iVar3);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar2;
}

