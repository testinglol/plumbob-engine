
undefined4 * __thiscall FUN_004eb7af(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int local_8;
  
  *param_1 = *param_2;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 1);
  param_1[2] = param_2[2];
  puVar1 = param_2 + 3;
  puVar2 = param_1 + 4;
  local_8 = 7;
  do {
    FUN_005a5e1c(puVar1);
    puVar1 = puVar1 + 2;
    *(undefined1 *)puVar2 = *(undefined1 *)(((int)param_2 - (int)param_1) + (int)puVar2);
    puVar2 = puVar2 + 2;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return param_1;
}

