
void __fastcall FUN_005a0f1a(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x8c) - *(int *)(*(int *)(param_1 + 4) + 0x88) >> 2;
  if (0 < iVar2) {
    do {
      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x88) + local_8 * 4);
      local_4 = (*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8)) / 0xc;
      if (0 < local_4) {
        do {
          FUN_00599c09(0);
          local_4 = local_4 + -1;
        } while (local_4 != 0);
      }
      local_8 = local_8 + 1;
    } while (local_8 < iVar2);
  }
  return;
}

