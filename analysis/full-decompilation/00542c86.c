
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00542c86(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066f3fc;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0054348f();
  _DAT_006f4f70 = _DAT_006f4f70 + -1;
  if (_DAT_006f4f70 == 0) {
    if (DAT_006f4f68 != (undefined4 *)0x0) {
      (**(code **)*DAT_006f4f68)(1);
    }
    DAT_006f4f68 = (undefined4 *)0x0;
    if (DAT_006f4f6c != (undefined4 *)0x0) {
      (**(code **)*DAT_006f4f6c)(1);
    }
    DAT_006f4f6c = (undefined4 *)0x0;
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e3892();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

