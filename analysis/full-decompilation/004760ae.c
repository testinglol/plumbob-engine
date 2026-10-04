
void __thiscall FUN_004760ae(int param_1,int param_2,undefined4 param_3)

{
  int local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_1;
  if ((short)param_3 < 6) {
    FUN_004761b4(param_2,param_3);
  }
  else {
    FUN_00464973(param_1 + 2,1);
    FUN_00464973(param_1,1);
    FUN_00464a4e(param_1 + 4,1);
    FUN_00464a4e(param_1 + 0x14,1);
    FUN_00464a4e(param_1 + 0x18,1);
    local_c = *(int *)(param_1 + 0xc);
    FUN_00464a4e(&local_c,1);
    *(int *)(param_1 + 0xc) = local_c;
    FUN_00464b48(param_1 + 0x10,1);
    FUN_00464a4e(param_1 + 0x1c,1);
    FUN_00464a4e(param_1 + 0x20,1);
    local_8 = 0;
    if (0 < *(int *)(param_1 + 4)) {
      param_2 = 0;
      do {
        FUN_00464973(*(int *)(param_1 + 8) + 2 + param_2,1);
        FUN_00464973(*(int *)(param_1 + 8) + 4 + param_2,1);
        FUN_00464973(*(int *)(param_1 + 8) + param_2,1);
        local_8 = local_8 + 1;
        param_2 = param_2 + 6;
      } while (local_8 < *(int *)(param_1 + 4));
    }
    if ((short)param_3 == 7) {
      FUN_00464c84(param_1 + 0x24);
    }
  }
  return;
}

