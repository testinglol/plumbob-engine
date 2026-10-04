
uint FUN_005da605(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  uint uVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = FUN_005da398(param_1);
  if ((char)uVar1 == '\0') {
    uVar1 = uVar1 & 0xffffff00;
  }
  else {
    local_14 = param_2;
    local_10 = param_3;
    local_c = param_4;
    local_8 = param_5;
    uVar1 = (**(code **)*param_1)(&local_14);
  }
  return uVar1;
}

