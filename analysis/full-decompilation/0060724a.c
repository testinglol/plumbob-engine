
undefined4 * FUN_0060724a(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00676f10;
  uVar2 = FUN_00401742(0x28);
  extraout_ECX[1] = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(undefined4 *)(extraout_ECX[1] + 4) = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[6] = 0;
  extraout_ECX[2] = 1;
  extraout_ECX[5] = 0;
  extraout_ECX[7] = 0;
  uVar2 = FUN_005fd96f();
  extraout_ECX[8] = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d8d90();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d909f();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d909f();
  iVar1 = extraout_ECX[10];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *extraout_ECX = &PTR_FUN_00676f08;
  (**(code **)(iVar1 + 0x38))(unaff_EBP + -0x14);
  *(undefined1 *)(extraout_ECX + 0x23) = 0;
  extraout_ECX[0x10] = 1;
  FUN_0060730b(1);
  FUN_005d9052(3);
  *(undefined1 *)((int)extraout_ECX + 0x8d) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

