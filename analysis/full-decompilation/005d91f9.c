
undefined4 __fastcall FUN_005d91f9(int param_1)

{
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return 1;
}

