
undefined4 * FUN_0053565d(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005dbd68();
  extraout_ECX[0x35] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x36] = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR_FUN_0066eb90;
  puVar2 = (undefined4 *)FUN_00422055(0,0);
  extraout_ECX[0x35] = *puVar2;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  uVar1 = puVar2[1];
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x36] = uVar1;
  extraout_ECX[0x38] = 7;
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3f] = 0;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  *(undefined1 *)(extraout_ECX + 0x3c) = 0;
  return extraout_ECX;
}

