
undefined4 FUN_004906b1(void)

{
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  float10 fVar2;
  
  FUN_00634c24();
  uVar1 = FUN_0056f3cd();
  FUN_005d4956(uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  fVar2 = (float10)FUN_0056f31a();
  uVar1 = *(undefined4 *)(extraout_ECX + 0x24);
  *(float *)(unaff_EBP + -0x10) = (float)fVar2;
  FUN_0056f32e(uVar1);
  FUN_0056f23d(*(undefined4 *)(extraout_ECX + 0x30));
  FUN_005d499c(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x30) = *(undefined4 *)(unaff_EBP + -0x10);
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}

