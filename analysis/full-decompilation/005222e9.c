
undefined4 * FUN_005222e9(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e8c4a(0);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c1719();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046fca5();
  uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
  extraout_ECX[0x50] = &PTR_FUN_0066643c;
  extraout_ECX[0x43] = uVar1;
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_0066cb60;
  extraout_ECX[0x35] = &PTR_LAB_0066cb30;
  extraout_ECX[0x49] = uVar1;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  extraout_ECX[0x47] = 0;
  extraout_ECX[0x48] = 0;
  extraout_ECX[0x4a] = 0;
  extraout_ECX[0x4b] = 0;
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4f] = 0;
  extraout_ECX[0x4e] = 0;
  uVar1 = *(undefined4 *)(DAT_006e486c + 0x24);
  *(undefined1 *)(extraout_ECX + 0x6b) = 0;
  extraout_ECX[0x42] = uVar1;
  return extraout_ECX;
}

