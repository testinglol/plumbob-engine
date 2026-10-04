
undefined4 FUN_005c4e90(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00661370;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005c22bb();
  FUN_005c32ce();
  local_4 = 0;
  uVar1 = FUN_005c174f(&DAT_006d2c84);
  local_4._0_1_ = 1;
  iVar2 = FUN_005c1b28(local_2c,&DAT_006fe780,uVar1,param_1,1);
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0042004f();
  if (iVar2 != 0) {
    local_4 = 0xffffffff;
    FUN_005c3314();
    ExceptionList = local_c;
    return 0x9b0d0010;
  }
  uVar1 = FUN_00401f73();
  uVar1 = FUN_005c4f80(uVar1);
  local_4 = 0xffffffff;
  FUN_005c3314();
  ExceptionList = local_c;
  return uVar1;
}

