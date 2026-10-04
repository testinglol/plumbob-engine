
void FUN_004ac510(short *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined2 *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  undefined2 *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  iVar2 = param_4 + param_2;
  local_c = param_2;
  iVar11 = param_3 + param_5;
  local_8 = param_3;
  if (0 < param_1[1] - param_2) {
    local_c = (param_1[1] - param_2) + param_2;
  }
  if (0 < *param_1 - param_3) {
    local_8 = (*param_1 - param_3) + param_3;
  }
  iVar10 = local_8;
  param_2 = iVar2;
  if (0 < iVar2 - param_1[3]) {
    param_2 = iVar2 - (iVar2 - param_1[3]);
  }
  if (0 < iVar11 - param_1[2]) {
    iVar11 = iVar11 - (iVar11 - param_1[2]);
  }
  local_40 = param_2 - local_c;
  iVar2 = iVar11 - local_8;
  if ((0 < local_40) && (0 < iVar2)) {
    local_54 = iVar2;
    cVar1 = FUN_004b466e();
    if (cVar1 != '\0') {
      local_64 = iVar10;
      local_68 = local_c;
      local_60 = param_2;
      local_5c = iVar11;
      FUN_005cf0fa(&local_68);
    }
    cVar1 = FUN_004b465e();
    if ((cVar1 != '\0') && (cVar1 = FUN_004b4678(), cVar1 != '\0')) {
      param_4 = 4;
      iVar11 = (**(code **)(**(int **)(DAT_006e486c + 4) + 0x14))();
      if (iVar11 == 1) {
        param_4 = 2;
      }
      else if (iVar11 == 2) {
        param_4 = 4;
      }
      else if (iVar11 == 3) {
        param_4 = 8;
      }
      local_38 = FUN_004cebb0();
      param_3 = 0;
      iVar10 = DAT_006f0bd4 * local_8 + local_c * 2 + DAT_006f0bd0;
      iVar11 = DAT_006f0bbc * local_8 + local_c * 2 + DAT_006f0bcc;
      if (0 < iVar2) {
        iVar6 = -param_4;
        local_58 = iVar6;
        local_28 = iVar2;
        do {
          param_2 = local_28;
          piVar3 = &param_2;
          if (param_4 <= local_28) {
            piVar3 = &param_4;
          }
          local_20 = *piVar3;
          param_2 = 0;
          if (0 < local_40) {
            local_24 = local_40;
            iVar7 = -param_4;
            local_50 = iVar7;
            local_44 = iVar10;
            do {
              param_5 = local_24;
              piVar3 = &param_5;
              if (param_4 <= local_24) {
                piVar3 = &param_4;
              }
              local_3c = *piVar3;
              local_34 = *(int *)(DAT_006e486c + 0x34);
              local_18 = 0;
              local_c = 0;
              local_1c = 0;
              local_14 = 0;
              param_5 = 0;
              iVar2 = iVar11;
              param_1 = (short *)iVar10;
              if (0 < local_20) {
                do {
                  local_4c = FUN_0049a73d(param_6,param_5 + local_8);
                  if (0 < local_3c) {
                    local_48 = (int)param_1 - iVar2;
                    local_30 = local_3c;
                    local_2c = (undefined2 *)(iVar2 + param_2 * 2);
                    do {
                      if (local_4c < (int)(uint)*(ushort *)(local_48 + (int)local_2c)) {
                        uVar4 = CONCAT22((short)((uint)local_2c >> 0x10),*local_2c);
                        if (local_34 == 1) {
                          local_10 = FUN_00438f76(uVar4);
                        }
                        else if (local_34 == 2) {
                          local_10 = FUN_00438f9b(uVar4);
                        }
                        else if (local_34 == 3) {
                          local_10 = FUN_004a45de(uVar4);
                        }
                        else {
                          local_10 = 0xffff00;
                        }
                        local_18 = local_18 + (local_10 >> 0x10 & 0xff);
                        local_c = local_c + (local_10 >> 8 & 0xff);
                        local_1c = local_1c + (local_10 & 0xff);
                        local_14 = local_14 + 1;
                      }
                      local_2c = local_2c + 1;
                      local_30 = local_30 + -1;
                    } while (local_30 != 0);
                  }
                  iVar6 = local_14;
                  param_5 = param_5 + 1;
                  iVar2 = iVar2 + (DAT_006f0bbc >> 1) * 2;
                  param_1 = (short *)((int)param_1 + (DAT_006f0bd4 >> 1) * 2);
                } while (param_5 < local_20);
                iVar7 = local_50;
                if (local_14 != 0) {
                  uVar5 = FUN_0046f556();
                  iVar2 = ((uVar5 & 0xf) - 8) + local_18 / iVar6;
                  uVar5 = FUN_0046f556();
                  local_c = ((uVar5 & 0xf) - 8) + (int)local_c / iVar6;
                  uVar5 = FUN_0046f556();
                  uVar5 = ((uVar5 & 0xf) - 8) + local_1c / iVar6;
                  if (iVar2 < 0) {
                    iVar2 = 0;
                  }
                  else if (0xff < iVar2) {
                    iVar2 = 0xff;
                  }
                  if ((int)local_c < 0) {
                    uVar9 = 0;
                  }
                  else {
                    uVar9 = local_c;
                    if (0xff < (int)local_c) {
                      uVar9 = 0xff;
                    }
                  }
                  if ((int)uVar5 < 0) {
                    uVar5 = 0;
                  }
                  else if (0xff < (int)uVar5) {
                    uVar5 = 0xff;
                  }
                  local_10 = 0;
                  uVar5 = (iVar2 << 8 | uVar9) << 8 | uVar5;
                  if (local_34 == 1) {
                    local_10 = FUN_0049f1f4(uVar5);
                  }
                  else if (local_34 == 2) {
                    local_10 = FUN_0049f21b(uVar5);
                  }
                  else if (local_34 == 3) {
                    local_10 = FUN_004a4558(uVar5);
                  }
                  iVar10 = local_44;
                  param_5 = 0;
                  param_1 = (short *)local_44;
                  iVar2 = iVar11;
                  do {
                    local_4c = FUN_0049a73d(param_6,param_5 + local_8);
                    if (0 < local_3c) {
                      local_34 = local_3c;
                      puVar8 = (undefined2 *)(iVar2 + param_2 * 2);
                      do {
                        if (local_4c < (int)(uint)*(ushort *)((int)puVar8 + ((int)param_1 - iVar2)))
                        {
                          *puVar8 = (undefined2)local_10;
                        }
                        puVar8 = puVar8 + 1;
                        local_34 = local_34 + -1;
                      } while (local_34 != 0);
                    }
                    param_5 = param_5 + 1;
                    iVar2 = iVar2 + (DAT_006f0bbc >> 1) * 2;
                    param_1 = (short *)((int)param_1 + (DAT_006f0bd4 >> 1) * 2);
                    iVar7 = local_50;
                  } while (param_5 < local_20);
                }
              }
              param_2 = param_2 + param_4;
              local_24 = local_24 + iVar7;
              iVar6 = local_58;
              iVar2 = local_54;
            } while (param_2 < local_40);
          }
          param_3 = param_3 + param_4;
          local_28 = local_28 + iVar6;
          iVar11 = iVar11 + (DAT_006f0bbc >> 1) * param_4 * 2;
          iVar10 = iVar10 + (DAT_006f0bd4 >> 1) * param_4 * 2;
        } while (param_3 < iVar2);
      }
    }
  }
  return;
}

