
uint __fastcall FUN_005bec0a(int param_1)

{
  uint uVar1;
  
  uVar1 = 0xffffffff;
  if (*(char *)(param_1 + 0x18) != '\0') {
    uVar1 = GetFileSize(*(HANDLE *)(param_1 + 0x1c),(LPDWORD)0x0);
    if (uVar1 == 0xffffffff) {
      FUN_005bfa81();
    }
    else if ((*(int *)(param_1 + 0x7c) != 0) && (uVar1 < *(uint *)(param_1 + 0x48))) {
      uVar1 = *(uint *)(param_1 + 0x48);
    }
  }
  return uVar1;
}

