
undefined4 __thiscall
FUN_0060bf16(int *param_1,int *param_2,int param_3,int param_4,int param_5,int *param_6,char param_7
            )

{
  int *piVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  int iVar10;
  undefined2 *puVar11;
  int iVar12;
  int local_2c;
  undefined2 *local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined2 *local_14;
  int local_c;
  int local_8;
  
  if (*(char *)((int)param_1 + 0x23) != '\0') {
    FUN_0060c356();
  }
  iVar4 = (**(code **)(*param_2 + 0xcc))();
  uVar5 = (**(code **)(*param_2 + 0xd0))();
  uVar5 = uVar5 >> 1;
  iVar6 = (**(code **)(*(int *)param_1[0xb] + 0xcc))();
  iVar7 = (**(code **)(*(int *)param_1[0xb] + 0xd0))();
  iVar12 = *param_6;
  iVar10 = 0;
  local_8 = param_3;
  local_c = param_4;
  local_1c = 0;
  if (param_3 < iVar12) {
    iVar10 = iVar12 - param_3;
    local_8 = iVar12;
  }
  iVar12 = param_6[1];
  if (param_4 < iVar12) {
    local_1c = iVar12 - param_4;
    local_c = iVar12;
  }
  iVar12 = param_5 * 0x1c;
  param_5 = (*(int *)(iVar12 + 0x18 + param_1[4]) - iVar10) + 1;
  local_2c = (**(code **)(*param_1 + 0x58))();
  local_2c = local_2c - local_1c;
  if (param_6[2] < local_8 + param_5) {
    param_5 = param_6[2] - local_8;
  }
  if (param_6[3] < local_2c + local_c) {
    local_2c = param_6[3] - local_c;
  }
  cVar2 = (**(code **)(*param_1 + 0x28))(4);
  iVar10 = local_c - local_1c;
  iVar8 = (**(code **)(*param_1 + 0x70))();
  local_24 = 0;
  local_20 = 0;
  piVar1 = (int *)(iVar12 + param_1[4]);
  iVar12 = *(int *)(iVar12 + 0x10 + param_1[4]) + param_3;
  local_1c = piVar1[5] + param_4;
  if (iVar12 < *param_6) {
    local_24 = *param_6 - iVar12;
    iVar12 = *param_6;
  }
  if (local_1c < param_6[1]) {
    local_20 = param_6[1] - local_1c;
    local_1c = param_6[1];
  }
  param_3 = (piVar1[2] - *piVar1) - local_24;
  param_4 = (piVar1[3] - piVar1[1]) - local_20;
  if (param_6[2] < param_3 + iVar12) {
    param_3 = param_6[2] - iVar12;
  }
  if (param_6[3] < param_4 + local_1c) {
    param_4 = param_6[3] - local_1c;
  }
  if ((0 < param_3) && (0 < param_4)) {
    local_14 = (undefined2 *)(iVar4 + (local_1c * uVar5 + iVar12) * 2);
    iVar6 = (piVar1[1] + local_20) * iVar7 + *piVar1 + local_24 + iVar6;
    if (param_7 == '\0') {
      if (param_2[2] == 7) {
        FUN_00499b54(param_1[0x10],uVar5 * 2,iVar7,param_3,param_4);
      }
      else {
        FUN_00499fc5(param_1[0x10],uVar5 * 2,iVar7,param_3,param_4);
      }
      if (cVar2 != '\0') {
        iVar12 = (**(code **)(*param_1 + 0x70))();
        iVar12 = iVar12 + iVar10;
        if ((((param_5 != 0) && (-1 < iVar12)) && (iVar12 < local_2c + local_c)) &&
           (puVar9 = (undefined2 *)(iVar4 + (iVar12 * uVar5 + local_8) * 2), 0 < param_5)) {
          do {
            *puVar9 = (short)param_1[5];
            puVar9 = puVar9 + 1;
            param_5 = param_5 + -1;
          } while (param_5 != 0);
        }
      }
    }
    else {
      local_28 = (undefined2 *)0x0;
      puVar9 = (undefined2 *)(iVar4 + (local_c * uVar5 + local_8) * 2);
      if (cVar2 != '\0') {
        local_28 = puVar9 + ((iVar8 + iVar10) - local_c) * uVar5;
      }
      param_6 = (int *)(local_1c - local_c);
      if ((int)param_6 < 1) {
        puVar9 = puVar9 + (int)param_6 * uVar5;
      }
      else {
        do {
          if (0 < param_5) {
            _param_7 = param_5;
            puVar11 = puVar9;
            do {
              *puVar11 = (short)param_1[5];
              puVar11 = puVar11 + 1;
              _param_7 = _param_7 + -1;
            } while (_param_7 != 0);
          }
          param_6 = (int *)((int)param_6 + -1);
          puVar9 = puVar9 + uVar5;
        } while (param_6 != (int *)0x0);
      }
      iVar10 = iVar12 - local_8;
      iVar4 = ((param_5 - param_3) - iVar12) + local_8;
      if ((iVar10 < 1) && (iVar4 < 1)) {
        puVar9 = puVar9 + param_4 * uVar5;
      }
      else if (0 < param_4) {
        local_24 = param_4;
        do {
          if (puVar9 != local_28) {
            puVar11 = puVar9;
            _param_7 = iVar10;
            if (0 < iVar10) {
              do {
                *puVar11 = (short)param_1[5];
                _param_7 = _param_7 + -1;
                puVar11 = puVar11 + 1;
              } while (_param_7 != 0);
            }
            if (0 < iVar4) {
              _param_7 = 0;
              param_6 = (int *)iVar4;
              do {
                param_6 = (int *)((int)param_6 + -1);
                *(short *)(_param_7 + local_8 * -2 + param_3 * 2 + iVar12 * 2 + (int)puVar9) =
                     (short)param_1[5];
                _param_7 = _param_7 + 2;
              } while (param_6 != (int *)0x0);
            }
          }
          local_24 = local_24 + -1;
          puVar9 = puVar9 + uVar5;
        } while (local_24 != 0);
      }
      _param_7 = ((local_2c - param_4) - local_1c) + local_c;
      if (0 < _param_7) {
        do {
          if ((puVar9 != local_28) && (puVar11 = puVar9, iVar12 = param_5, 0 < param_5)) {
            do {
              *puVar11 = (short)param_1[5];
              iVar12 = iVar12 + -1;
              puVar11 = puVar11 + 1;
            } while (iVar12 != 0);
          }
          _param_7 = _param_7 + -1;
          puVar9 = puVar9 + uVar5;
        } while (_param_7 != 0);
      }
      if (param_2[2] == 7) {
        if (0 < param_4) {
          param_2 = (int *)param_4;
          do {
            _param_7 = 0;
            puVar9 = local_14;
            if (0 < param_3) {
              do {
                if (*(byte *)(_param_7 + iVar6) == 0) {
                  uVar3 = (undefined2)param_1[5];
                }
                else {
                  uVar3 = FUN_0049a775(*(uint *)(param_1[0x10] +
                                                (uint)*(byte *)(_param_7 + iVar6) * 4) >> 0x13);
                }
                _param_7 = _param_7 + 1;
                *puVar9 = uVar3;
                puVar9 = puVar9 + 1;
              } while (_param_7 < param_3);
            }
            iVar6 = iVar6 + iVar7;
            param_2 = (int *)((int)param_2 + -1);
            local_14 = local_14 + uVar5;
          } while (param_2 != (int *)0x0);
        }
      }
      else if (0 < param_4) {
        param_2 = (int *)param_4;
        do {
          _param_7 = 0;
          puVar9 = local_14;
          if (0 < param_3) {
            do {
              if (*(byte *)(_param_7 + iVar6) == 0) {
                uVar3 = (undefined2)param_1[5];
              }
              else {
                uVar3 = FUN_0049a996(*(uint *)(param_1[0x10] + (uint)*(byte *)(_param_7 + iVar6) * 4
                                              ) >> 0x13);
              }
              _param_7 = _param_7 + 1;
              *puVar9 = uVar3;
              puVar9 = puVar9 + 1;
            } while (_param_7 < param_3);
          }
          iVar6 = iVar6 + iVar7;
          param_2 = (int *)((int)param_2 + -1);
          local_14 = local_14 + uVar5;
        } while (param_2 != (int *)0x0);
      }
    }
  }
  return 1;
}

