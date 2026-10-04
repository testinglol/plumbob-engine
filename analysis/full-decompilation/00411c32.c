
undefined4 FUN_00411c32(undefined4 param_1)

{
  undefined4 uVar1;
  undefined **local_38 [3];
  undefined1 local_2c [32];
  int local_c [2];
  
  FUN_0046f824(local_2c,0,0x20);
  local_38[0] = &PTR_FUN_006666dc;
  FUN_00411b8e(param_1,local_38);
  FUN_00411d77(local_c,local_38);
  if (local_c[0] == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_c[0] + 0x34);
  }
  return uVar1;
}

