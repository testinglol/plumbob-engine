
int * __thiscall FUN_004498b2(int *param_1,int *param_2,int *param_3)

{
  undefined4 local_c;
  undefined4 local_8;
  
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
  *param_2 = local_c;
  return param_2;
}

