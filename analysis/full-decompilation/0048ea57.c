
undefined4 * FUN_0048ea57(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00492ad8();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xc] = uVar1;
  extraout_ECX[0xd] = 0;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xf] = 0;
  FUN_00461e56(0,0,0,0,1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x12] = 0;
  extraout_ECX[0x15] = 0;
  *(undefined1 *)(extraout_ECX + 0x16) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x59) = 1;
  *extraout_ECX = &PTR_FUN_00667fa4;
  return extraout_ECX;
}

