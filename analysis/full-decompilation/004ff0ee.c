
undefined4 * FUN_004ff0ee(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
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
  uVar4 = FUN_004d6251(iVar3,iVar2,uVar4,*(undefined4 *)(unaff_EBP + 8));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[1] = uVar4;
  return extraout_ECX;
}

