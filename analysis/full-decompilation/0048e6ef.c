
undefined4 * FUN_0048e6ef(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = *(undefined1 *)(unaff_EBP + 0xb);
  iVar1 = (*(int **)(unaff_EBP + 8))[1];
  iVar2 = **(int **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_0048e750((iVar1 - iVar2) / 0x28,unaff_EBP + -0xd);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_0048e9da(iVar2,iVar1,*extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[1] = uVar3;
  return extraout_ECX;
}

