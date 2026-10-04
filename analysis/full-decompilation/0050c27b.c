
undefined4 * FUN_0050c27b(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00635e55(extraout_ECX + 0x3d,0x34,5,FUN_0050c2e1,FUN_00416e17);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_0066b0bc;
  *(undefined1 *)(extraout_ECX + 0x37) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xde) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xdd) = 0;
  extraout_ECX[0x3c] = 0;
  return extraout_ECX;
}

