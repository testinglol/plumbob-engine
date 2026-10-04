
int FUN_00578fe9(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0xc) = 0;
  *(undefined4 *)(extraout_ECX + 0x10) = 0x400;
  *(undefined4 *)(extraout_ECX + 0x14) = 0x200;
  *(undefined4 *)(extraout_ECX + 0x18) = 0x200;
  *(undefined1 *)(extraout_ECX + 0x1c) = 0;
  *(undefined1 *)(extraout_ECX + 0x1d) = 0;
  *(undefined4 *)(extraout_ECX + 0x20) = 0;
  *(undefined4 *)(extraout_ECX + 0x24) = 0;
  *(undefined4 *)(extraout_ECX + 0x28) = 0;
  *(undefined1 *)(extraout_ECX + 0x30) = 0;
  *(undefined4 *)(extraout_ECX + 0x34) = 8;
  *(undefined4 *)(extraout_ECX + 0x38) = 0;
  *(undefined1 *)(extraout_ECX + 0x3c) = 1;
  *(undefined4 *)(extraout_ECX + 0x40) = 0;
  *(undefined4 *)(extraout_ECX + 0x44) = 0;
  *(undefined4 *)(extraout_ECX + 0x48) = 0;
  *(undefined1 *)(extraout_ECX + 0x4c) = 0;
  uVar1 = FUN_00401742(0x10);
  *(undefined4 *)(extraout_ECX + 0x50) = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(int *)(*(int *)(extraout_ECX + 0x50) + 4) = *(int *)(extraout_ECX + 0x50);
  return extraout_ECX;
}

