
undefined4 FUN_00465e93(void)

{
  int iVar1;
  int unaff_EBP;
  undefined4 uVar2;
  
  FUN_00634c24();
  uVar2 = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_005c30e9(unaff_EBP + -0x18);
  if ((*(short *)(unaff_EBP + 8) < 1) ||
     ((uint)(*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x18) >> 2) <
      (uint)(int)*(short *)(unaff_EBP + 8))) {
    FUN_004659fc(0xffffffff);
  }
  else {
    if (iVar1 != 0) {
      if (iVar1 == 5) {
        uVar2 = 0xffffff9e;
      }
      else if (iVar1 == 6) {
        uVar2 = 0xffffff38;
      }
      else {
        uVar2 = 0xffffffff;
      }
    }
    FUN_004659fc(uVar2);
    uVar2 = FUN_004096c2();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046664c();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

