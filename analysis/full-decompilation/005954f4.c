
undefined4 * __thiscall
FUN_005954f4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *local_8;
  
  local_8 = param_1;
  local_8 = operator_new(0x1c);
  if (local_8 == (undefined4 *)0x0) {
    local_8 = (undefined4 *)0x0;
  }
  else {
    *local_8 = 0;
    local_8[1] = 0;
    local_8[2] = 0;
    local_8[3] = 0;
    local_8[4] = 0;
    local_8[6] = 0;
  }
  local_8[6] = local_8[6] + 1;
  FUN_00595645(param_2,param_1,param_3,param_4,param_5);
  FUN_0059b0a3(&local_8);
  param_1[0xd] = 0;
  return local_8;
}

