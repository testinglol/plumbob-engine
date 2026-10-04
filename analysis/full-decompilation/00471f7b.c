
undefined4 * FUN_00471f7b(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -0xd) = *(undefined1 *)(unaff_EBP + 0xb);
  iVar2 = piVar1[1];
  iVar3 = *piVar1;
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_005e6b22((iVar2 - iVar3) / 0xc,unaff_EBP + -0xd);
  uVar4 = *extraout_ECX;
  iVar2 = piVar1[1];
  iVar3 = *piVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar5 = FUN_004722fb(iVar3,iVar2,uVar4,*(undefined4 *)(unaff_EBP + 8));
  uVar4 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[1] = uVar5;
  *unaff_FS_OFFSET = uVar4;
  return extraout_ECX;
}

