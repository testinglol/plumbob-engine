
undefined4 * __thiscall FUN_004e84f4(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_004ba5ac(param_1);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  param_2[2] = puVar1[2];
  param_2[3] = puVar1[3];
  return param_2;
}

