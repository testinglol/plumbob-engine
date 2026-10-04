
int __fastcall FUN_00500b95(int *param_1)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  iVar1 = *param_1;
  iVar2 = param_1[1];
  local_8 = 0;
  if (param_1[8] == 0) {
    local_c = 0;
    while (((param_1[6] + iVar1 <= param_1[4] || (param_1[2] == 0)) &&
           ((param_1[7] + iVar2 <= param_1[5] || (param_1[3] == 0))))) {
      local_8 = local_8 + 1;
      iVar1 = iVar1 + param_1[2];
      if ((param_1[2] == 0) || (param_1[4] < param_1[6] + iVar1)) {
        local_c = local_c + 1;
        iVar1 = *param_1;
        iVar2 = param_1[1] + param_1[3] * local_c;
      }
    }
  }
  else {
    local_c = 0;
    while ((param_1[6] + iVar1 <= param_1[4] || (param_1[2] == 0))) {
      if ((param_1[5] < param_1[7] + iVar2) && (param_1[3] != 0)) {
        return local_8;
      }
      local_8 = local_8 + 1;
      iVar2 = iVar2 + param_1[3];
      if ((param_1[3] == 0) || (param_1[5] < param_1[7] + iVar1)) {
        local_c = local_c + 1;
        iVar2 = param_1[1];
        iVar1 = *param_1 + param_1[2] * local_c;
      }
    }
  }
  return local_8;
}

