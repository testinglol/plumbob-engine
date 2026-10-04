
void __thiscall FUN_004742c6(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined **local_120;
  undefined4 local_11c;
  undefined1 local_114 [256];
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = FUN_0046fbe5(0xffffffff);
  local_10 = FUN_0046fbe5(0xffffffff);
  FUN_00464a4e(&local_c,1);
  FUN_00464a4e(&local_10,1);
  FUN_0046f824(local_114,0,0x100);
  local_120 = &PTR_FUN_00666524;
  local_8 = 1;
  if (0 < local_c) {
    do {
      if (*(int *)(param_2 + 0xc) != 0) {
        uVar2 = FUN_004705f2(local_8,0xffffffff);
        FUN_0046f8cb(uVar2);
      }
      FUN_00464d2c(&local_120);
      if (*(int *)(param_2 + 0xc) == 0) {
        FUN_004704a5(local_8,local_11c,0xffffffff);
      }
      local_8 = local_8 + 1;
    } while (local_8 <= local_c);
  }
  iVar4 = 1;
  if (0 < local_10) {
    do {
      if (*(int *)(param_2 + 0xc) != 0) {
        uVar2 = FUN_004705f2(iVar4,0xffffffff);
        FUN_0046f8cb(uVar2);
      }
      FUN_00464d2c(&local_120);
      if (*(int *)(param_2 + 0xc) == 0) {
        FUN_004704a5(iVar4,local_11c,0xffffffff);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= local_10);
  }
  iVar4 = param_3;
  local_14 = (uint)(*(char *)(param_1 + 7) != '\0');
  if (0 < param_3) {
    FUN_00464a4e(&local_14,1);
  }
  *(bool *)(param_1 + 7) = local_14 != 0;
  iVar1 = *(int *)(param_1 + 500);
  iVar3 = (iVar1 - *(int *)(param_1 + 0x1f0)) - local_c;
  if (iVar3 < 1) {
    if (iVar3 < 0) {
      param_3 = CONCAT13(1,(undefined3)param_3);
      FUN_004744ca(iVar1,-iVar3,(int)&param_3 + 3);
    }
  }
  else {
    FUN_0047449a(iVar1 - iVar3,iVar1);
  }
  if (1 < iVar4) {
    FUN_00464895(*(int *)(param_1 + 0x1f0),local_c);
  }
  if (2 < iVar4) {
    param_3 = *(int *)(param_1 + 0x1fc);
    FUN_00464a4e(&param_3,1);
    *(int *)(param_1 + 0x1fc) = param_3;
  }
  if (3 < iVar4) {
    FUN_00464a5e(param_1 + 8,1);
  }
  return;
}

