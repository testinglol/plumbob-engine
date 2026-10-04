
void __fastcall FUN_00446396(int param_1)

{
  int iVar1;
  int local_18;
  short local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0xdc) == *(int *)(param_1 + 0xe0)) {
    local_8 = 0;
    if ((*(ushort *)(DAT_006e486c + 0x66) & 0x40) != 0) {
      local_8 = FUN_0043acf5(0xe9337020);
    }
    if ((*(int *)(param_1 + 0xdc) == *(int *)(param_1 + 0xe0)) &&
       (*(int *)(param_1 + 0xd0) == *(int *)(param_1 + 0xd4))) {
      local_c = 4;
    }
    else {
      local_c = 2;
    }
    if (local_8 != 0) {
      for (local_10 = 0; local_10 < local_c; local_10 = local_10 + 1) {
        local_18 = 0;
        local_14 = FUN_00440b6d(local_8);
        if ((local_14 != 0) && (iVar1 = FUN_00407498((int)local_14), iVar1 != 0)) {
          *(ushort *)(iVar1 + 0x5a) = *(ushort *)(iVar1 + 0x5a) | 0x4000;
          local_18 = iVar1;
        }
        if (local_18 != 0) {
          FUN_0044845a(&local_18);
        }
      }
    }
  }
  return;
}

