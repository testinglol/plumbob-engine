
undefined4 * FUN_00460a05(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = *(undefined1 *)(unaff_EBP + 0xb);
  iVar1 = (*(int **)(unaff_EBP + 8))[1];
  iVar2 = **(int **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_00460a61(iVar1 - iVar2 >> 4,unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar4 = FUN_004612c6(iVar2,iVar1,*extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
  uVar3 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[1] = uVar4;
  *unaff_FS_OFFSET = uVar3;
  return extraout_ECX;
}

