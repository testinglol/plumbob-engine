
void __thiscall FUN_005d5544(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *local_8;
  
  iVar2 = *(int *)(param_1 + 4) - param_3 >> 4;
  local_8 = param_2;
  if (0 < iVar2) {
    do {
      iVar2 = iVar2 + -1;
      puVar1 = (undefined4 *)((param_3 - (int)param_2) + (int)local_8);
      *local_8 = *puVar1;
      local_8[1] = puVar1[1];
      local_8[2] = puVar1[2];
      local_8[3] = puVar1[3];
      local_8 = local_8 + 4;
    } while (iVar2 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - (int)param_2 >> 4) * -0x10;
  return;
}

