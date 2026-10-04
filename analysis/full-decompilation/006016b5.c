
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006016b5(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00676990;
  _DAT_006fed9c = _DAT_006fed9c + -1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d9295();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005d9122();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0060296d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

