
undefined4 * FUN_004ec63d(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x38] = 0;
  extraout_ECX[0x39] = 0;
  extraout_ECX[0x3a] = 0;
  extraout_ECX[0x3c] = 0;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635e55(extraout_ECX + 0x48,0x6c,2,FUN_00403288,thunk_FUN_00470467);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x47] = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x37] = uVar1;
  *extraout_ECX = &PTR_FUN_006695e8;
  extraout_ECX[0x43] = 4;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x35] = 0;
  extraout_ECX[0x36] = 0;
  *(undefined1 *)(extraout_ECX + 0x3b) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xed) = 0;
  return extraout_ECX;
}

