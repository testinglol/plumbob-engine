
undefined4 __thiscall FUN_005df58e(int param_1,undefined4 param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = param_3[2];
  local_18 = *param_3;
  local_14 = param_3[1];
  local_c = param_3[3];
  iVar2 = local_10 - *(int *)(param_1 + 0x1c);
  if (((((((iVar2 < 1) || (local_10 = local_10 - iVar2, local_18 < local_10)) &&
         ((-local_18 < 1 || (local_18 = 0, 0 < local_10)))) &&
        ((iVar2 = local_c - *(int *)(param_1 + 0x20), iVar2 < 1 ||
         (local_c = local_c - iVar2, local_14 < local_c)))) &&
       ((-local_14 < 1 || (local_14 = 0, 0 < local_c)))) &&
      ((param_4 == (int *)0x0 ||
       ((((local_10 - param_4[2] < 1 ||
          (local_10 = local_10 - (local_10 - param_4[2]), local_18 < local_10)) &&
         ((*param_4 - local_18 < 1 ||
          (local_18 = local_18 + (*param_4 - local_18), local_18 < local_10)))) &&
        (((local_c - param_4[3] < 1 ||
          (local_c = local_c - (local_c - param_4[3]), local_14 < local_c)) &&
         ((param_4[1] - local_14 < 1 ||
          (local_14 = local_14 + (param_4[1] - local_14), local_14 < local_c)))))))))) &&
     ((local_18 < local_10 && (local_14 < local_c)))) {
    local_8 = param_1;
    uVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x18))(param_2,&local_18);
    return uVar1;
  }
  return CONCAT31((int3)((uint)local_c >> 8),1);
}

