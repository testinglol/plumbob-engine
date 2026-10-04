
undefined4 FUN_005fd803(void)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006fed98 == 0) {
    *(undefined4 *)(unaff_EBP + -0x34) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    QueryPerformanceFrequency((LARGE_INTEGER *)(unaff_EBP + -0x14));
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005772e2();
    FUN_005771b0();
    FUN_005fd8ea();
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    FUN_005772e2();
    FUN_005771b0();
    iVar1 = FUN_005fd8ea();
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    FUN_005772e2();
    FUN_005771b0();
    iVar2 = FUN_005fd8ea();
    DAT_006fed98 = (iVar2 + iVar1) / 2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

