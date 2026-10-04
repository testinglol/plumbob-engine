
void FUN_005448d7(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar2 = operator_new(0x1f8);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00542bd8();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (iVar3 != 0) {
    uVar1 = *(undefined4 *)(unaff_EBP + 8);
    *(undefined1 *)(iVar3 + 500) = *(undefined1 *)(extraout_ECX + 0xd4);
    FUN_005434d0(uVar1);
    FUN_005442f7(iVar3);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

