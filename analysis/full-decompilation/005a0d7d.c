
void FUN_005a0d7d(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined1 auStack_d8 [52];
  undefined4 uStack_a4;
  int iStack_a0;
  uint uStack_9c;
  int iStack_98;
  
  FUN_00634c24();
  iStack_98 = *(undefined4 *)(unaff_EBP + 8);
  uStack_9c = 0x5a0da0;
  iVar1 = FUN_005c3650();
  uStack_9c = 0x5a0dad;
  iStack_98 = iVar1;
  FUN_00462f2f();
  *(undefined4 *)(extraout_ECX + 100) = *(undefined4 *)(iVar1 + 0x40);
  iStack_98 = 0x5a0dbe;
  FUN_005c4890();
  uStack_9c = extraout_ECX + 0x68;
  iStack_a0 = unaff_EBP + -0x50;
  uStack_a4 = 0x5a0dcc;
  iStack_98 = extraout_ECX + 0x24;
  FUN_0049b9e6();
  uStack_9c = (uint)*(byte *)(unaff_EBP + 0x10);
  iVar1 = *(int *)(extraout_ECX + 4);
  iStack_98 = 0;
  iStack_a0 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uStack_a4 = 0x5a0de7;
  FUN_005992ca();
  iStack_98 = 0;
  uStack_9c = 0x5a0def;
  FUN_005994da();
  if (iVar1 != 0) {
    iStack_98 = 0;
    uStack_9c = 0x5a0dfb;
    FUN_00599362();
    iStack_98 = 0;
    uStack_9c = 0x5a0e03;
    FUN_005a0f8b();
  }
  iStack_98 = *(int *)(extraout_ECX + 4) + 0xbc;
  uStack_9c = 0x5a0e17;
  FUN_005a0e57();
  *(undefined1 **)(unaff_EBP + 0x10) = auStack_d8;
  FUN_005c36c0(unaff_EBP + -0x50);
  FUN_005a0d34();
  iStack_98 = unaff_EBP + -0x50;
  uStack_9c = 0x5a0e3a;
  FUN_00463023();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_98 = 0x5a0e46;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

