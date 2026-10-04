
void __thiscall FUN_0041f1c7(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  uVar2 = param_2;
  local_8 = *param_1;
  FUN_00464a4e(&local_8,1);
  *param_1 = local_8;
  FUN_00464a5e(param_1 + 0xf,1);
  FUN_0043fde8(uVar2,param_1 + 1);
  FUN_0043fd68(uVar2,param_1 + 2);
  FUN_0043fd68(uVar2,param_1 + 3);
  FUN_00464a4e(param_1 + 4,1);
  FUN_00464973(param_1 + 5,4);
  FUN_00464a4e(param_1 + 7,1);
  FUN_00464973(param_1 + 8,1);
  FUN_00464b48(param_1 + 9,1);
  if (param_3 < 0x3e) {
    FUN_0046494e((int)&param_2 + 3);
    param_1[0x10] = param_1[0x10] & 0xfffffffb;
    if (param_2._3_1_ != '\0') {
      param_1[0x10] = param_1[0x10] | 4;
    }
    FUN_0046494e((int)&param_2 + 3);
    param_1[0x10] = param_1[0x10] & 0xffffffdf;
    if (param_2._3_1_ != '\0') {
      param_1[0x10] = param_1[0x10] | 0x20;
    }
    if (((uint)param_1[0x10] >> 2 & 1) != 0) {
      FUN_0046494e((int)&param_2 + 3);
      param_1[0x10] = param_1[0x10] & 0xfffffff7;
      if (param_2._3_1_ != '\0') {
        param_1[0x10] = param_1[0x10] | 8;
      }
      FUN_0046494e((int)&param_2 + 3);
      param_1[0x10] = param_1[0x10] & 0xffffffef;
      if (param_2._3_1_ != '\0') {
        param_1[0x10] = param_1[0x10] | 0x10;
      }
    }
    if (0x3b < param_3) {
      FUN_0046494e((int)&param_2 + 3);
      param_1[0x10] = param_1[0x10] & 0xfffffffd;
      if (param_2._3_1_ != '\0') {
        param_1[0x10] = param_1[0x10] | 2;
      }
    }
  }
  else {
    FUN_00464a4e(param_1 + 0x10,1);
  }
  iVar1 = param_1[0xf];
  if (DAT_006e48b4 < iVar1) {
    DAT_006e48b4 = iVar1;
  }
  return;
}

