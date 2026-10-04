
undefined4 * __thiscall FUN_004497ed(int *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 *local_34;
  undefined4 local_1c [3];
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_c = *param_1;
  local_8 = *(int *)(*param_1 + 4);
  while (local_8 != 0) {
    if (*(int *)(local_8 + 0x10) < *param_3) {
      local_8 = *(int *)(local_8 + 0xc);
    }
    else {
      local_c = local_8;
      local_8 = *(int *)(local_8 + 8);
    }
  }
  if ((local_c == *param_1) || (*param_3 < *(int *)(local_c + 0x10))) {
    local_34 = local_1c;
  }
  else {
    local_34 = &local_10;
  }
  *param_2 = *local_34;
  return param_2;
}

