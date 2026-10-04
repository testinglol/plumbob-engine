
undefined4 FUN_005b92ee(void)

{
  int unaff_EBP;
  undefined1 auStack_24 [12];
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  FUN_00634c24();
  uStack_14 = *(undefined4 *)(unaff_EBP + 8);
  uStack_18 = 0x5b9309;
  FUN_005b870f();
  uStack_14 = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uStack_18 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + 8) = auStack_24;
  FUN_005b86bd(unaff_EBP + -0x18);
  FUN_005ba499();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  uStack_14 = 0x5b9337;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

