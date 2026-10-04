
void FUN_005a0cba(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  undefined1 auStack_94 [52];
  undefined4 uStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  iStack_58 = 0x5a0cda;
  iStack_54 = iVar1;
  FUN_00462f2f();
  *(undefined4 *)(extraout_ECX + 100) = *(undefined4 *)(iVar1 + 0x40);
  iStack_58 = extraout_ECX + 0x68;
  iStack_5c = unaff_EBP + -0x50;
  uStack_60 = 0x5a0cee;
  iStack_54 = extraout_ECX + 0x24;
  FUN_0049b9e6();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 **)(unaff_EBP + 8) = auStack_94;
  FUN_005c36c0(unaff_EBP + -0x50);
  FUN_005a0d34();
  iStack_54 = unaff_EBP + -0x50;
  iStack_58 = 0x5a0d17;
  FUN_00463023();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iStack_54 = 0x5a0d23;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

