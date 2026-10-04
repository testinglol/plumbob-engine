
undefined4 FUN_005bc44e(void)

{
  LARGE_INTEGER *lpPerformanceCount;
  undefined4 uVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(extraout_ECX + 0x18) == 0) {
    FUN_005bc58e(unaff_EBP + -0x28,extraout_ECX);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_005bc5b6(unaff_EBP + -0x20,1000000);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005bc5d9(*(undefined4 *)(unaff_EBP + 8),extraout_ECX + 0x10);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
    uVar1 = *(undefined4 *)(unaff_EBP + 8);
  }
  else {
    FUN_005bc54d();
    *(undefined4 *)(unaff_EBP + -4) = 3;
    lpPerformanceCount = (LARGE_INTEGER *)FUN_004b469d();
    QueryPerformanceCounter(lpPerformanceCount);
    FUN_005bc58e(unaff_EBP + -0x38,extraout_ECX);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005bc5b6(unaff_EBP + -0x30,1000000);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_005bc5d9(*(undefined4 *)(unaff_EBP + 8),extraout_ECX + 0x10);
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0042004f();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_0042004f();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
    uVar1 = *(undefined4 *)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar1;
}

