
undefined4 * FUN_005bdd58(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  iVar3 = (**(code **)(*piVar1 + 0x18))();
  *(undefined4 **)(unaff_EBP + 8) = extraout_ECX + 1;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00401a3c(iVar3,iVar3 + iVar2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[4] = 0;
  *extraout_ECX = &PTR_LAB_0066933c;
  return extraout_ECX;
}

