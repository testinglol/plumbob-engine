
undefined4 __fastcall FUN_0050f548(int param_1)

{
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c [3];
  undefined4 local_10;
  int local_c;
  int local_8;
  
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  local_20 = *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 0x20);
  local_24 = *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 0x1c);
  local_2c = 0;
  local_28 = 0;
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[2] = local_24;
  local_10 = local_20;
  FUN_004ba5ac((int *)(param_1 + 0x1c));
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
            (*(undefined4 *)(param_1 + 0x1a0),&local_2c,local_1c,0);
  local_24 = *(int *)(DAT_006f3870 + 0x1c);
  local_20 = *(undefined4 *)(DAT_006f3870 + 0x20);
  local_2c = 0;
  local_28 = 0;
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_8 = *(int *)(param_1 + 0x20) + 5;
  local_c = *(int *)(param_1 + 0x1c) + 5 + *(int *)(*(int *)(param_1 + 0x1a0) + 0x1c);
  local_1c[2] = local_24;
  local_10 = local_20;
  FUN_004ba5ac(&local_c);
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(DAT_006f3870,&local_2c,local_1c,0);
  if (*(int *)(param_1 + 0x198) != 0) {
    local_24 = *(int *)(param_1 + 0x198) * 4;
    local_20 = *(undefined4 *)(DAT_006f3870 + 0x20);
    local_1c[2] = local_24 + local_1c[0];
    local_2c = 0;
    local_28 = 0;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(DAT_006f386c,&local_2c,local_1c,0);
  }
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  return 1;
}

