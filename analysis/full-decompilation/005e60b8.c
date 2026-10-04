
void FUN_005e60b8(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar1;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0067434c;
  iVar1 = extraout_ECX[0x13];
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (iVar1 != 0) {
    (**(code **)(*DAT_006fe8bc + 0x18))(iVar1);
    FUN_005da4c7(iVar1);
    extraout_ECX[0x13] = 0;
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005e5e16();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005e6a7d();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e6a36();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

