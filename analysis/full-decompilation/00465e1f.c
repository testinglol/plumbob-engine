
uint FUN_00465e1f(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 uVar3;
  
  FUN_00634c24();
  uVar3 = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = FUN_005c30e9(unaff_EBP + -0x18);
  if (iVar2 != 0) {
    if (iVar2 == 5) {
      uVar3 = 0xffffff9e;
    }
    else if (iVar2 == 6) {
      uVar3 = 0xffffff38;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  FUN_004659fc(uVar3);
  iVar2 = *(int *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = *(int *)(unaff_EBP + -0x18);
  FUN_0046664c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2 - iVar1 >> 2 & 0xffff;
}

