
void FUN_004132e8(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 local_160 [87];
  
  puVar1 = (undefined4 *)FUN_00413236(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_0041333c();
    FUN_0046f8cb(param_1);
    local_160[0] = param_2;
    FUN_004133c0(local_160);
  }
  else {
    *puVar1 = param_2;
  }
  return;
}

