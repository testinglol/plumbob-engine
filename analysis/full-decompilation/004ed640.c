
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ed640(int param_1)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = *(int *)(param_1 + 4);
  local_8 = *(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x14);
  iVar1 = *(int *)(iVar2 + 0x20) - *(int *)(iVar2 + 0x18);
  local_10 = 100;
  local_c = 0x4b;
  if (_DAT_00669790 < (double)local_8 / (double)iVar1) {
    local_c = (iVar1 * 100) / local_8;
  }
  if ((double)local_8 / (double)iVar1 < _DAT_00669788) {
    local_10 = (local_8 * 0x4b) / iVar1;
  }
  if (*(int *)(param_1 + 8) < 0) {
    *(undefined4 *)(param_1 + 8) = 0x5a;
  }
  FUN_004b82f3(*(undefined4 *)(param_1 + 300),iVar2,0,&local_10,*(undefined4 *)(param_1 + 8),1,0);
  return;
}

