
void __thiscall FUN_005c6670(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  LONG LVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00661442;
  local_10 = ExceptionList;
  iVar9 = param_1[1];
  if (iVar9 != param_1[2]) {
    local_8 = 0;
    ExceptionList = &local_10;
    if (iVar9 != 0) {
      ExceptionList = &local_10;
      FUN_005c6960(iVar9 + -8);
    }
    iVar9 = param_1[1];
    local_8 = 0xffffffff;
    param_1[1] = iVar9 + 8;
    uVar1 = *param_3;
    uVar2 = param_3[1];
    iVar9 = iVar9 + -8;
    iVar6 = iVar9 - (int)param_2 >> 3;
    if (0 < iVar6) {
      do {
        iVar9 = iVar9 + -8;
        FUN_005c6960(iVar9);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    *param_2 = uVar1;
    param_2[1] = uVar2;
    ExceptionList = local_10;
    return;
  }
  local_1c = iVar9 - *param_1 >> 3;
  if (local_1c == 0) {
    local_1c = 1;
  }
  else {
    local_1c = local_1c * 2;
    if (local_1c == 0) {
      local_18 = 0;
      ExceptionList = &local_10;
      goto LAB_005c6757;
    }
  }
  ExceptionList = &local_10;
  local_18 = FUN_00401742(local_1c << 3);
LAB_005c6757:
  local_8 = 1;
  iVar9 = FUN_005c7190(*param_1,param_2,local_18,param_2);
  local_8._0_1_ = 2;
  if (iVar9 != 0) {
    FUN_005c6960(param_3);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar6 = FUN_005c7190(param_2,param_1[1],iVar9 + 8,iVar9);
  iVar9 = *param_1;
  local_8 = 0xffffffff;
  for (; iVar9 != param_1[1]; iVar9 = iVar9 + 8) {
  }
  piVar3 = (int *)*param_1;
  iVar9 = param_1[2] - (int)piVar3 >> 3;
  if (iVar9 != 0) {
    uVar7 = iVar9 * 8;
    if (uVar7 < 0x81) {
      LVar8 = InterlockedExchange(&DAT_006de5a4,1);
      uVar5 = DAT_006de5a8;
      uVar4 = DAT_006c08e8;
      if (LVar8 != 0) {
        uVar10 = 0;
        if (DAT_006c08e8 != 0) {
          do {
            if (((uVar5 >> 1 <= uVar10) && (DAT_006de5a4 == 0)) &&
               (LVar8 = InterlockedExchange(&DAT_006de5a4,1), LVar8 == 0)) {
              DAT_006c08e8 = 1000;
              DAT_006de5a8 = uVar10;
              goto LAB_005c68cf;
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < uVar4);
        }
        DAT_006c08e8 = 0x1e;
        iVar9 = 0;
        while( true ) {
          iVar11 = iVar9 + 6;
          if (0x1b < iVar11) {
            iVar11 = 0x1b;
          }
          LVar8 = InterlockedExchange(&DAT_006de5a4,1);
          if (LVar8 == 0) break;
          FUN_005c4760(iVar11);
          iVar9 = iVar9 + 1;
        }
      }
LAB_005c68cf:
      *piVar3 = *(int *)(&DAT_006de560 + (uVar7 + 7 >> 3) * 4);
      *(int **)(&DAT_006de560 + (uVar7 + 7 >> 3) * 4) = piVar3;
      DAT_006de5a4 = 0;
    }
    else {
      FUN_00634ecc(piVar3);
    }
  }
  param_1[1] = iVar6;
  *param_1 = local_18;
  param_1[2] = local_18 + local_1c * 8;
  ExceptionList = local_10;
  return;
}

