
void FUN_00411c82(undefined4 param_1)

{
  int iVar1;
  undefined **local_6c [11];
  int local_40;
  undefined4 local_3c;
  undefined **local_38 [3];
  undefined1 local_2c [32];
  int local_c;
  undefined4 local_8;
  
  FUN_0046f824(local_2c,0,0x20);
  local_38[0] = &PTR_FUN_006666dc;
  FUN_00411bde(param_1,local_38);
  FUN_00411d77(&local_c,local_38);
  if (local_c == 0) {
    FUN_00411db0(local_38);
    local_40 = local_c;
    local_3c = local_8;
    local_6c[0] = &PTR_FUN_006666dc;
    iVar1 = FUN_00411e06(local_6c);
    *(undefined4 *)(iVar1 + 0x2c) = 1;
    *(undefined4 *)(iVar1 + 0x30) = param_1;
  }
  else {
    *(int *)(local_c + 0x30) = *(int *)(local_c + 0x30) + 1;
  }
  return;
}

