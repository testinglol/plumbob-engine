
int FUN_005b91e8(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005baaf8();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005bac49();
  *(undefined1 *)(extraout_ECX + 0x2c) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(extraout_ECX + 0x30));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

