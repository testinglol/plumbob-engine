
int __thiscall FUN_005764a8(int param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *local_c;
  int local_8;
  
  local_8 = 0;
  iVar4 = (*param_2 % (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2)) * 4;
  puVar1 = *(undefined4 **)(iVar4 + *(int *)(param_1 + 4));
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    local_c = puVar1;
    while (puVar3 = puVar2, puVar3 != (undefined4 *)0x0) {
      if (puVar3[1] == *param_2) {
        *local_c = *puVar3;
        FUN_0040189d(puVar3,0xc);
        local_8 = local_8 + 1;
        puVar2 = (undefined4 *)*local_c;
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
      }
      else {
        puVar2 = (undefined4 *)*puVar3;
        local_c = puVar3;
      }
    }
    if (puVar1[1] == *param_2) {
      *(undefined4 *)(iVar4 + *(int *)(param_1 + 4)) = *puVar1;
      FUN_0040189d(puVar1,0xc);
      local_8 = local_8 + 1;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    }
  }
  return local_8;
}

