
undefined4 FUN_0041ad47(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_006668c4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = FUN_00464dcd(unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + 0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00465055();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

