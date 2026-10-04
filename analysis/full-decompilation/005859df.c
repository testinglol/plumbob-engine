
void FUN_005859df(void)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  (**(code **)(*extraout_ECX + 0xdc))(*(undefined4 *)(unaff_EBP + 8));
  iVar2 = (**(code **)(*extraout_ECX + 0xac))();
  uVar1 = *(undefined4 *)(iVar2 + 4);
  pvVar3 = operator_new(0x1c);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  uVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 != (void *)0x0) {
    uVar4 = FUN_0058364c();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  FUN_005873ba(unaff_EBP + -0x10);
  FUN_0058372c(DAT_006f6b64,uVar1,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

