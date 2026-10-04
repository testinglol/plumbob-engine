
void FUN_0060b0b4(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00677180;
  iVar1 = extraout_ECX[0xc];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_005b8770();
    FUN_006321f0(iVar1);
    extraout_ECX[0xc] = 0;
  }
  FUN_0060b129();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00677068;
  return;
}

