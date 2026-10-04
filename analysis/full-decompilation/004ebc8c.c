
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ebc8c(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066942c;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_004ebfe6();
  _DAT_006f26ac = _DAT_006f26ac + -1;
  if (_DAT_006f26ac == 0) {
    if (DAT_006f26a8 != (undefined4 *)0x0) {
      (**(code **)*DAT_006f26a8)(1);
    }
    DAT_006f26a8 = (undefined4 *)0x0;
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635f6d(extraout_ECX + 0x70,0x6c,4,thunk_FUN_00470467);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e3892();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

