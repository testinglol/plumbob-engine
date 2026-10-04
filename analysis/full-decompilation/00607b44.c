
undefined4 * FUN_00607b44(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00676fac;
  extraout_ECX[1] = &PTR_LAB_00673840;
  *(undefined1 *)(extraout_ECX + 2) = 0;
  uVar1 = FUN_00401742(0xc);
  extraout_ECX[3] = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(undefined4 *)(extraout_ECX[3] + 4) = extraout_ECX[3];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0057be3a(unaff_EBP + -0xe,unaff_EBP + -0xd);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[7] = 0;
  FUN_005d48d9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *extraout_ECX = &PTR_FUN_00676f80;
  extraout_ECX[1] = &PTR_LAB_00676f68;
  *(undefined1 *)(extraout_ECX + 0xb) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x2d) = 0;
  return extraout_ECX;
}

