
void __thiscall FUN_004651dc(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *local_10;
  int local_c;
  int local_8;
  
  local_8 = -1;
  FUN_00464a5e(&local_8,1);
  if (local_8 < 0) {
    FUN_00465631(param_1,param_2,param_3);
  }
  else {
    FUN_0046527c();
    if (0 < local_8) {
      local_c = local_8;
      do {
        puVar1 = operator_new(0x10);
        if (puVar1 == (undefined4 *)0x0) {
          puVar1 = (undefined4 *)0x0;
        }
        else {
          *puVar1 = 0;
          puVar1[1] = 0;
          puVar1[2] = 0;
          puVar1[3] = 0;
        }
        local_10 = puVar1;
        if (0 < param_3) {
          FUN_00464a5e(puVar1 + 3,1);
        }
        FUN_0046574a(puVar1,param_2,param_3);
        FUN_00465323(&local_10);
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  return;
}

