
void FUN_00604849(void)

{
  void *pvVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar2;
  
  FUN_00634c24();
  uVar2 = extraout_ECX;
  pvVar1 = operator_new(0x4d8);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00604890(uVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

