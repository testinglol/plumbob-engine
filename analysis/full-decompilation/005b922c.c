
void FUN_005b922c(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 0x30));
  *(int *)(unaff_EBP + -0x14) = extraout_ECX + 0x14;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005a5484();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005481b6();
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_005bbb04();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005481b6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

