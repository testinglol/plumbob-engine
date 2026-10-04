
void FUN_00485af7(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00667cd0;
  iVar1 = extraout_ECX[0xc];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_00485b4c();
    extraout_ECX[0xc] = 0;
  }
  if (DAT_006e576c != (undefined4 *)0x0) {
    (**(code **)*DAT_006e576c)(1);
  }
  DAT_006e576c = (undefined4 *)0x0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_LAB_00667bd0;
  return;
}

