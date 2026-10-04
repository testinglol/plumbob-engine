
undefined4 * FUN_005f7201(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e372a();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_00675ccc;
  extraout_ECX[0x69] = 0xc;
  FUN_005e4198(uVar1,4,1);
  *(undefined1 *)((int)extraout_ECX + 0x16b) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 2;
  *(undefined4 *)(unaff_EBP + -0x24) = 2;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_005e4104(unaff_EBP + -0x30);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

