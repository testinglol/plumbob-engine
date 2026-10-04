
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e8660(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00674414;
  puVar1 = (undefined4 *)extraout_ECX[0x38];
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  _DAT_006fea24 = _DAT_006fea24 + -1;
  if (_DAT_006fea24 == 0) {
    piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
    (**(code **)(*piVar2 + 0x14))(DAT_006fea20);
    DAT_006fea20 = 0;
  }
  if ((undefined4 *)extraout_ECX[0x3a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)extraout_ECX[0x3a])(1);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

