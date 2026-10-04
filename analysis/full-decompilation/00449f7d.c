
int * __thiscall FUN_00449f7d(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int local_50;
  undefined1 local_30 [4];
  undefined1 local_2c;
  undefined1 local_24 [4];
  undefined1 local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  bool local_8;
  
  local_10 = *param_1;
  local_c = *(int *)(*param_1 + 4);
  local_8 = true;
  while (local_c != 0) {
    local_10 = local_c;
    local_8 = *param_3 < *(int *)(local_c + 0x10);
    if (local_8) {
      local_50 = *(int *)(local_c + 8);
    }
    else {
      local_50 = *(int *)(local_c + 0xc);
    }
    local_c = local_50;
  }
  local_14 = local_10;
  if (local_8 != false) {
    local_1c = *(int *)(*param_1 + 8);
    if (local_10 == local_1c) {
      local_20 = 1;
      piVar1 = (int *)FUN_00449e79(local_24,0,local_10,param_3);
      *param_2 = *piVar1;
      *(undefined1 *)(param_2 + 1) = local_20;
      return param_2;
    }
    FUN_0042a392();
  }
  if (*(int *)(local_14 + 0x10) < *param_3) {
    local_2c = 1;
    piVar1 = (int *)FUN_00449e79(local_30,local_c,local_10,param_3);
    *param_2 = *piVar1;
    *(undefined1 *)(param_2 + 1) = local_2c;
  }
  else {
    *param_2 = local_14;
    *(undefined1 *)(param_2 + 1) = 0;
  }
  return param_2;
}

