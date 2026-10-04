
void FUN_005879ea(void)

{
  int iVar1;
  undefined **local_334 [3];
  undefined1 local_328 [256];
  undefined **local_228 [3];
  undefined1 local_21c [256];
  undefined **local_11c;
  undefined4 local_118;
  undefined1 local_110 [260];
  int local_c;
  int local_8;
  
  FUN_0046f824(local_110,0,0x100);
  local_11c = &PTR_FUN_00666524;
  local_8 = 1;
  iVar1 = FUN_0046fbe5(0xffffffff);
  if (0 < iVar1) {
    do {
      local_c = FUN_004705f2(local_8,0xffffffff);
      FUN_0046f824(local_21c,0,0x100);
      local_228[0] = &PTR_FUN_00666524;
      FUN_0046f847(local_c,0xffffffff);
      FUN_0046f8e4(local_228);
      local_c = FUN_0046fab1(&DAT_006c145c,0);
      if (local_c != -1) {
        iVar1 = FUN_004705f2(local_8,0xffffffff);
        local_c = iVar1 + 1 + local_c;
        FUN_0046f824(local_328,0,0x100);
        local_334[0] = &PTR_FUN_00666524;
        FUN_0046f847(local_c,0xffffffff);
        FUN_0046f8e4(local_334);
        FUN_004704a5(local_8,local_118,0xffffffff);
      }
      local_8 = local_8 + 1;
      iVar1 = FUN_0046fbe5(0xffffffff);
    } while (local_8 <= iVar1);
  }
  return;
}

