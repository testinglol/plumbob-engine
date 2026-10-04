
int FUN_005bc36d(void)

{
  LARGE_INTEGER *lpFrequency;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005bc54d();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005bc54d();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005bc54d();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005bc557(0);
  FUN_005bc557(0);
  lpFrequency = (LARGE_INTEGER *)FUN_004b469d();
  QueryPerformanceFrequency(lpFrequency);
  *(undefined4 *)(extraout_ECX + 0x18) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

