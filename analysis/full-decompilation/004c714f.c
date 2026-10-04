
undefined4 * FUN_004c714f(void)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004c94d1();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046ea4d();
  *(undefined1 *)(extraout_ECX + 6) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  pvVar2 = operator_new(0x244);
  *(void **)(unaff_EBP + -0x14) = pvVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0046f5cd();
  }
  *extraout_ECX = piVar3;
  iVar1 = *piVar3;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  (**(code **)(iVar1 + 0xc))(*(undefined4 *)(unaff_EBP + 8),0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

