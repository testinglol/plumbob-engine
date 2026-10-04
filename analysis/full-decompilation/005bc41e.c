
void __fastcall FUN_005bc41e(int param_1)

{
  LARGE_INTEGER *lpPerformanceCount;
  
  lpPerformanceCount = (LARGE_INTEGER *)FUN_004b469d();
  QueryPerformanceCounter(lpPerformanceCount);
  *(undefined4 *)(param_1 + 0x18) = 1;
  return;
}

