
void __thiscall FUN_0045e4aa(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int local_48;
  undefined1 local_34 [4];
  int local_30;
  undefined1 local_24 [16];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00438fc0(local_24,2);
  FUN_0043908c(2);
  (**(code **)(*(int *)param_1[0x2b7] + 0x78))(param_2);
  piVar1 = (int *)(**(code **)(*param_1 + 0x8c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0xa0))();
  local_14 = *piVar1;
  local_10 = piVar1[1];
  local_c = piVar1[2];
  local_8 = piVar1[3];
  if (local_14 < local_c) {
    if (local_10 < local_8) {
      FUN_004b467f(&local_14);
    }
    if ((local_14 < local_c) && (local_10 < local_8)) {
      FUN_00439016(&local_14,2);
      FUN_0043270d(param_1);
      while (local_30 != 0) {
        piVar1 = (int *)FUN_00438fc0(local_34,2);
        local_14 = *piVar1;
        local_10 = piVar1[1];
        local_c = piVar1[2];
        local_8 = piVar1[3];
        FUN_00422698();
        FUN_00439016(&local_14,2);
        FUN_0043270d(local_30);
        local_30 = local_48;
      }
    }
  }
  return;
}

