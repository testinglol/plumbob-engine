
undefined4 __fastcall FUN_005d9133(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  return 0;
}

