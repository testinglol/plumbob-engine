
undefined4 __thiscall
FUN_005df20c(int *param_1,undefined4 param_2,int *param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  local_8 = param_3[2] - *param_3;
  local_c = param_3[3] - param_3[1];
  param_5 = param_5 % local_8;
  param_6 = param_6 % local_c;
  if (0 < param_5) {
    param_5 = param_5 - local_8;
  }
  if (0 < param_6) {
    param_6 = param_6 - local_c;
  }
  iVar3 = *param_4 + param_5;
  local_2c = param_6 + param_4[1];
  iVar2 = local_8 + *param_4 + param_5;
  local_24 = param_4[1] + local_c + param_6;
  local_10 = param_1;
  do {
    local_3c = local_2c;
    local_20 = *param_3;
    local_1c = param_3[1];
    local_18 = param_3[2];
    local_14 = param_3[3];
    local_40 = iVar3;
    if (iVar3 < *param_4) {
      local_20 = local_20 + (*param_4 - iVar3);
      local_40 = *param_4;
    }
    local_38 = iVar2;
    if (param_4[2] < iVar2) {
      local_18 = local_18 + (param_4[2] - iVar2);
      local_38 = param_4[2];
    }
    if (local_2c < param_4[1]) {
      local_1c = local_1c + (param_4[1] - local_2c);
      local_3c = param_4[1];
    }
    iVar1 = param_4[3];
    local_34 = local_24;
    if (iVar1 < local_24) {
      local_14 = local_14 + (iVar1 - local_24);
      local_34 = iVar1;
    }
    (**(code **)(*local_10 + 0x9c))(param_2,&local_20,&local_40,0);
    iVar3 = iVar3 + local_8;
    if (param_4[2] <= iVar3) {
      local_2c = local_24;
      if (param_4[3] <= local_24) {
        return 1;
      }
      local_24 = local_24 + local_c;
      iVar3 = *param_4 + param_5;
      iVar2 = iVar3;
    }
    iVar2 = iVar2 + local_8;
  } while( true );
}

