
undefined4 FUN_0041582b(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00666704;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_00464eab(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 0x18),
                       *(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x14));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00465055();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

