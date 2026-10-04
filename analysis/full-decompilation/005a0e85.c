
void FUN_005a0e85(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined1 auStack_d8 [52];
  undefined4 uStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  
  FUN_00634c24();
  iStack_98 = *(undefined4 *)(unaff_EBP + 8);
  iStack_9c = 0x5a0ea8;
  iVar1 = FUN_005c3650();
  iStack_9c = 0x5a0eb5;
  iStack_98 = iVar1;
  FUN_00462f2f();
  *(undefined4 *)(extraout_ECX + 100) = *(undefined4 *)(iVar1 + 0x40);
  iStack_98 = 0x5a0ec6;
  FUN_005c4890();
  iStack_9c = extraout_ECX + 0x68;
  iStack_a0 = unaff_EBP + -0x50;
  uStack_a4 = 0x5a0ed4;
  iStack_98 = extraout_ECX + 0x24;
  FUN_0049b9e6();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 **)(unaff_EBP + 8) = auStack_d8;
  FUN_005c36c0(unaff_EBP + -0x50);
  FUN_005a0d34();
  iStack_98 = unaff_EBP + -0x50;
  iStack_9c = 0x5a0efd;
  FUN_00463023();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_98 = 0x5a0f09;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

