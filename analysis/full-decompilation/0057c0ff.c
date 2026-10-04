
undefined4 FUN_0057c0ff(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00575b11(unaff_EBP + -0x1c,unaff_EBP + 8);
  if (*(int *)(unaff_EBP + -0x1c) == 0) {
    pvVar1 = operator_new(0xd0);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0057c183(*(undefined4 *)(unaff_EBP + 8));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
    iVar3 = FUN_00582031(unaff_EBP + -0x14);
    *(undefined4 *)(iVar3 + 4) = uVar2;
  }
  else {
    uVar2 = *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

