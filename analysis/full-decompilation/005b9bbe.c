
undefined1 FUN_005b9bbe(void)

{
  undefined1 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b96fe(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x18,unaff_EBP + -0x24);
  uVar1 = FUN_005b9c38(unaff_EBP + -0x18,unaff_EBP + -0x24,*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

