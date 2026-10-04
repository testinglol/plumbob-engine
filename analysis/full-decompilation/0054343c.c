
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054343c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066f5b8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  _DAT_006f4f64 = _DAT_006f4f64 + -1;
  if (_DAT_006f4f64 == 0) {
    if (DAT_006f4f60 != (int *)0x0) {
      (**(code **)(*DAT_006f4f60 + 0x14))(1);
    }
    DAT_006f4f60 = (int *)0x0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e3892();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

