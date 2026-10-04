
undefined4 FUN_004ecfea(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d48d9();
  iVar1 = DAT_006f38b0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 == 1) {
    iVar1 = *(int *)(unaff_EBP + 8);
  }
  else {
    if (iVar1 != 0) {
      uVar2 = *(undefined4 *)(unaff_EBP + 8);
      goto LAB_004ed054;
    }
    iVar1 = *(int *)(unaff_EBP + 8);
  }
  uVar2 = FUN_004705f2(iVar1 + 1,0xffffffff);
  FUN_005d4bbf(uVar2);
  uVar2 = FUN_004096c2();
  uVar2 = FUN_00635f62(uVar2);
LAB_004ed054:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

