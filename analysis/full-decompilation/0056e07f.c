
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056e07f(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006714d8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0056e1b0();
  _DAT_006f6280 = _DAT_006f6280 + -1;
  if (_DAT_006f6280 == 0) {
    if (DAT_006f627c != (undefined4 *)0x0) {
      (**(code **)*DAT_006f627c)(1);
    }
    DAT_006f627c = (undefined4 *)0x0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00431242();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

