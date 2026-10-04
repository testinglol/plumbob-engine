
uint FUN_00452c2d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  FUN_0046f824(local_44,0,0x40);
  local_50[0] = &PTR_FUN_0066651c;
  FUN_0046f847(param_3,0xffffffff);
  uVar1 = FUN_00402246(local_50);
  if ((short)uVar1 == 0) {
    uVar1 = uVar1 & 0xffffff00;
  }
  else {
    uVar1 = FUN_00474b22(param_1,param_2,uVar1,param_4);
  }
  return uVar1;
}

