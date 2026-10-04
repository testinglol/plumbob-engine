
int FUN_00595f4e(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(float *)(unaff_EBP + -0x14) = -*(float *)(extraout_ECX + 0x60);
  *(float *)(unaff_EBP + -0x10) = -*(float *)(extraout_ECX + 0x5c);
  *(float *)(unaff_EBP + -0x18) = -*(float *)(extraout_ECX + 0x58);
  FUN_005c4840(unaff_EBP + -0x18,unaff_EBP + -0x10,unaff_EBP + -0x14,extraout_ECX + 100);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c35b0();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00596037(unaff_EBP + -0x28,unaff_EBP + -0x6c);
  uVar1 = FUN_00462f96(unaff_EBP + -0xf4,extraout_ECX + 0x4c);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  iVar2 = FUN_0049b9e6(unaff_EBP + -0xb0,unaff_EBP + -0x6c,uVar1);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00462f2f(iVar2);
  *(undefined4 *)(extraout_ECX + 0xc0) = *(undefined4 *)(iVar2 + 0x40);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX + 0x80;
}

