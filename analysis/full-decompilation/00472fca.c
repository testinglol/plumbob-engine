
undefined4 * __thiscall FUN_00472fca(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_90 [64];
  undefined **local_50;
  undefined1 local_44 [64];
  
  FUN_0046f824(param_1 + 3,0,0x40);
  *param_1 = &PTR_FUN_0066651c;
  FUN_0046f824(param_1 + 0x16,0,0x40);
  param_1[0x13] = &PTR_FUN_0066651c;
  FUN_0046f824(local_44,0,0x40);
  local_50 = &PTR_FUN_0066651c;
  FUN_0046f824(local_90,0,0x40);
  FUN_00455edc(param_3,param_1,param_1 + 0x13,0);
  return param_1;
}

