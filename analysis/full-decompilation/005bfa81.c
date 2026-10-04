
void __fastcall FUN_005bfa81(int param_1)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (DVar1 == 5) {
    *(undefined4 *)(param_1 + 0x30) = 0x20000002;
    return;
  }
  if (DVar1 != 0xb7) {
    *(DWORD *)(param_1 + 0x30) = DVar1;
    return;
  }
  *(undefined4 *)(param_1 + 0x30) = 0x20000001;
  return;
}

