
void FUN_004ba37c(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int param_6)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 *puVar9;
  int local_2c;
  int local_28;
  int local_10;
  int local_8;
  
  cVar1 = (**(code **)(*param_1 + 0x20))(0x40);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*param_3 + 0x20))(0x40);
    if (cVar1 == '\0') {
      iVar8 = *param_1;
    }
    else {
      cVar1 = (**(code **)(*param_4 + 0x20))(0x40);
      if (cVar1 == '\0') {
        (**(code **)(*param_1 + 0x24))(0x40);
        iVar8 = *param_3;
      }
      else {
        local_2c = *param_2;
        local_28 = param_2[1];
        if (local_2c < 0) {
          local_2c = 0;
        }
        if (local_28 < 0) {
          local_28 = 0;
        }
        iVar8 = param_2[2];
        if (param_1[7] < param_2[2]) {
          iVar8 = param_1[7];
        }
        local_10 = param_2[3];
        if (param_1[8] < param_2[3]) {
          local_10 = param_1[8];
        }
        iVar3 = (**(code **)(*param_1 + 0xcc))();
        uVar4 = (**(code **)(*param_1 + 0xd0))();
        uVar4 = uVar4 >> 1;
        param_2 = (int *)(iVar3 + (uVar4 * local_28 + local_2c) * 2);
        local_8 = (**(code **)(*param_3 + 0xcc))();
        uVar5 = (**(code **)(*param_3 + 0xd0))();
        uVar5 = uVar5 >> 1;
        local_8 = local_8 + (param_5[1] * uVar5 + *param_5) * 2;
        iVar3 = (**(code **)(*param_4 + 0xcc))();
        iVar6 = (**(code **)(*param_4 + 0xd0))();
        iVar8 = iVar8 - local_2c;
        local_10 = local_10 - local_28;
        param_5 = (int *)(iVar3 + param_5[1] * iVar6 + *param_5);
        if (*(int *)(DAT_006e486c + 0x34) == 2) {
          if (0 < local_10) {
            do {
              iVar3 = 0;
              if (0 < iVar8) {
                puVar9 = (undefined2 *)param_2;
                do {
                  iVar7 = (uint)*(byte *)(iVar3 + (int)param_5) + param_6;
                  if (7 < iVar7) {
                    if (iVar7 < 0xf8) {
                      uVar2 = FUN_0049a775(iVar7 >> 3);
                    }
                    else {
                      uVar2 = *(undefined2 *)((local_8 - (int)param_2) + (int)puVar9);
                    }
                    *puVar9 = uVar2;
                  }
                  iVar3 = iVar3 + 1;
                  puVar9 = puVar9 + 1;
                } while (iVar3 < iVar8);
              }
              param_2 = (int *)((int)param_2 + uVar4 * 2);
              local_8 = local_8 + uVar5 * 2;
              param_5 = (int *)((int)param_5 + iVar6);
              local_10 = local_10 + -1;
            } while (local_10 != 0);
          }
        }
        else if (0 < local_10) {
          do {
            iVar3 = 0;
            if (0 < iVar8) {
              puVar9 = (undefined2 *)param_2;
              do {
                iVar7 = (uint)*(byte *)(iVar3 + (int)param_5) + param_6;
                if (7 < iVar7) {
                  if (iVar7 < 0xf8) {
                    uVar2 = FUN_0049a996(iVar7 >> 3);
                  }
                  else {
                    uVar2 = *(undefined2 *)((int)puVar9 + (local_8 - (int)param_2));
                  }
                  *puVar9 = uVar2;
                }
                iVar3 = iVar3 + 1;
                puVar9 = puVar9 + 1;
              } while (iVar3 < iVar8);
            }
            param_2 = (int *)((int)param_2 + uVar4 * 2);
            local_8 = local_8 + uVar5 * 2;
            param_5 = (int *)((int)param_5 + iVar6);
            local_10 = local_10 + -1;
          } while (local_10 != 0);
        }
        (**(code **)(*param_3 + 0x24))(0x40);
        (**(code **)(*param_4 + 0x24))(0x40);
        iVar8 = *param_1;
      }
    }
    (**(code **)(iVar8 + 0x24))(0x40);
  }
  return;
}

