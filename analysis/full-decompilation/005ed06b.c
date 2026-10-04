
undefined4 * FUN_005ed06b(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_006750dc;
  FUN_005d48d9();
  extraout_ECX[5] = 0xffffffff;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 4) = 0;
  extraout_ECX[6] = 0;
  *extraout_ECX = &PTR_FUN_00675064;
  if (iVar1 != 0) {
    FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 8));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

