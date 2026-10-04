
undefined4 FUN_005ce996(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005c36c0(*(int *)(extraout_ECX + 0x1c0) + -0x44);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_0049b9e6(unaff_EBP + -0x94,*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x50);
  FUN_00462f2f(iVar1);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar1 + 0x40);
  FUN_005c4890();
  FUN_005cf26a(unaff_EBP + -0x50);
  FUN_005cea64(unaff_EBP + -0x50);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}

