
void __fastcall FUN_005eea16(int param_1)

{
  if (*(int *)(param_1 + 0x1d4) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1bc));
  }
  FUN_005de621();
  if (*(int *)(param_1 + 0x1d4) != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1bc));
  }
  return;
}

