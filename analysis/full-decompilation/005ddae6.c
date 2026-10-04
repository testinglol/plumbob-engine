
int * __thiscall FUN_005ddae6(int *param_1,int *param_2,int param_3,char param_4)

{
  int iVar1;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined1 local_8 [4];
  
  local_1c = param_1[0x1f];
  local_18 = param_1[0x20];
  local_14 = param_1[0x21];
  local_10 = param_1[0x22];
  iVar1 = (**(code **)(*param_1 + 0x18))();
  if (iVar1 != 0) {
    FUN_00436feb(&local_1c,&local_18);
    FUN_00436feb(&local_14,&local_10);
  }
  if (param_4 == '\0') {
    local_c = (local_1c + local_14) / 2;
  }
  else {
    FUN_005d9928(&local_c,local_8);
    if (local_c < local_1c) {
      local_c = local_1c;
    }
    if (local_14 + -1 < local_c) {
      local_c = local_14 + -1;
    }
  }
  local_18 = (*(int *)(param_3 + 0x80) - *(int *)(param_3 + 0x88)) + -1 + local_18;
  if (local_18 < 3) {
    local_18 = local_10 + 2;
  }
  *param_2 = local_c;
  param_2[1] = local_18;
  return param_2;
}

