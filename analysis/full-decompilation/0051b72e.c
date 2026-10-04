
void __thiscall FUN_0051b72e(int param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = *param_2;
  local_c = param_2[2];
  local_8 = param_2[3];
  local_10 = param_2[1] + 0x32;
  FUN_005de0ed(&local_14,param_3);
  if (*(int *)(param_1 + 0xe4) != 0) {
    cVar1 = FUN_004cff80();
    if (cVar1 != '\0') {
      local_10 = param_2[1];
      local_c = param_2[2];
      local_8 = local_10 + 0x32;
      local_14 = *param_2 + 0x155;
      FUN_005de0ed(&local_14,param_3);
    }
  }
  return;
}

