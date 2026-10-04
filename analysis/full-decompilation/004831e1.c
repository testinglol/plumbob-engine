
uint FUN_004831e1(int *param_1,int *param_2)

{
  uint uVar1;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_14 = *param_2;
  local_c = local_14 + 1;
  local_10 = param_2[1];
  local_8 = local_10 + 1;
  if (((param_1 != (int *)0x0) &&
      (uVar1 = FUN_0046966e(&local_14,param_1), local_8 = uVar1, uVar1 != 0xffffffff)) &&
     (local_8 = uVar1 * 5, *(int *)(*param_1 + 0x10 + uVar1 * 0x14) == 0x7fffffff)) {
    return CONCAT31((int3)(local_8 >> 8),1);
  }
  return local_8 & 0xffffff00;
}

