
void __thiscall FUN_005c6c10(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  LONG LVar6;
  uint uVar7;
  int iVar8;
  undefined1 local_38 [12];
  undefined2 local_2c;
  int local_28;
  int *local_24;
  uint local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006614a2;
  local_10 = ExceptionList;
  local_14 = &stack0xffffffb4;
  local_28 = param_1[1];
  if (local_28 != param_1[2]) {
    local_8 = 0;
    ExceptionList = &local_10;
    local_24 = (int *)local_28;
    local_14 = &stack0xffffffb4;
    if (local_28 != 0) {
      ExceptionList = &local_10;
      local_14 = &stack0xffffffb4;
      FUN_005c7020(local_28 + -0x18);
    }
    local_8 = 0xffffffff;
    param_1[1] = param_1[1] + 0x18;
    uVar1 = param_3[1];
    uVar2 = *param_3;
    FUN_00462be8(param_3 + 2);
    local_2c = *(undefined2 *)(param_3 + 5);
    FUN_005c7120(param_2,param_1[1] + -0x30,param_1[1] + -0x18,param_2,0);
    param_2[1] = uVar1;
    *param_2 = uVar2;
    FUN_00462be8(local_38);
    *(undefined2 *)(param_2 + 5) = local_2c;
    ExceptionList = local_10;
    return;
  }
  local_1c = (local_28 - *param_1) / 0x18;
  if (local_1c == 0) {
    local_1c = 1;
  }
  else {
    local_1c = local_1c * 2;
    if (local_1c == 0) {
      local_18 = 0;
      ExceptionList = &local_10;
      local_14 = &stack0xffffffb4;
      goto LAB_005c6d24;
    }
  }
  ExceptionList = &local_10;
  local_18 = FUN_00401742(local_1c * 0x18);
LAB_005c6d24:
  local_8 = 1;
  local_20 = local_18;
  iVar4 = FUN_005c7200(*param_1,param_2,local_18,param_2);
  local_8._0_1_ = 2;
  local_20 = iVar4;
  if (iVar4 != 0) {
    FUN_005c7020(param_3);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  local_28 = FUN_005c7200(param_2,param_1[1],iVar4 + 0x18,iVar4);
  for (iVar4 = *param_1; iVar4 != param_1[1]; iVar4 = iVar4 + 0x18) {
  }
  piVar3 = (int *)*param_1;
  iVar4 = (param_1[2] - (int)piVar3) / 0x18;
  if (iVar4 != 0) {
    uVar5 = iVar4 * 0x18;
    if (uVar5 < 0x81) {
      local_24 = (int *)(&DAT_006de560 + (uVar5 + 7 >> 3) * 4);
      LVar6 = InterlockedExchange(&DAT_006de5a4,1);
      uVar5 = DAT_006c08e8;
      if (LVar6 != 0) {
        local_20 = DAT_006de5a8;
        uVar7 = 0;
        if (DAT_006c08e8 != 0) {
          do {
            if (((local_20 >> 1 <= uVar7) && (DAT_006de5a4 == 0)) &&
               (LVar6 = InterlockedExchange(&DAT_006de5a4,1), LVar6 == 0)) {
              DAT_006c08e8 = 1000;
              DAT_006de5a8 = uVar7;
              goto LAB_005c6ea7;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar5);
        }
        DAT_006c08e8 = 0x1e;
        iVar4 = 0;
        while( true ) {
          iVar8 = iVar4 + 6;
          if (0x1b < iVar8) {
            iVar8 = 0x1b;
          }
          LVar6 = InterlockedExchange(&DAT_006de5a4,1);
          if (LVar6 == 0) break;
          FUN_005c4760(iVar8);
          iVar4 = iVar4 + 1;
        }
      }
LAB_005c6ea7:
      *piVar3 = *local_24;
      *local_24 = (int)piVar3;
      DAT_006de5a4 = 0;
    }
    else {
      FUN_00634ecc(piVar3);
    }
  }
  *param_1 = local_18;
  param_1[1] = local_28;
  param_1[2] = local_18 + local_1c * 0x18;
  ExceptionList = local_10;
  return;
}

