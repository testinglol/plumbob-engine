
undefined4 * FUN_0049060c(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  float10 fVar2;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00492f28();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = &PTR__scalar_deleting_destructor__00668048;
  uVar1 = FUN_0056f3cd();
  FUN_005d4bbf(uVar1);
  fVar2 = (float10)FUN_0056f31a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0xc] = (float)fVar2;
  return extraout_ECX;
}

