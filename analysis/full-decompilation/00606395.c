
undefined4 __thiscall FUN_00606395(int param_1,int *param_2,int *param_3,int *param_4)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  byte *pbVar13;
  byte *pbVar14;
  int iVar15;
  int iVar16;
  undefined4 *puVar17;
  int iVar18;
  bool bVar19;
  int local_28;
  uint local_14;
  undefined4 *local_c;
  
  if (((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 8) != 0)) ||
     (cVar8 = FUN_006062d5(), cVar8 != '\0')) {
    bVar7 = false;
    iVar15 = *param_4;
    iVar4 = param_4[1];
    iVar5 = param_4[2];
    iVar6 = param_4[3];
    if (((iVar15 != 0) || (iVar4 != 0)) ||
       ((iVar5 != *(int *)(param_1 + 0x20) || (iVar6 != *(int *)(param_1 + 0x24))))) {
      bVar7 = true;
    }
    iVar18 = *(int *)(param_1 + 4);
    if (((*(short *)(iVar18 + 0x1a) == 1) && (*(short *)(iVar18 + 0x1c) == 8)) &&
       (*(int *)(iVar18 + 0x1e) == 1)) {
      iVar9 = *(int *)(iVar18 + 0x16);
      bVar19 = iVar9 < 0;
      if (bVar19) {
        iVar9 = -iVar9;
      }
      if ((iVar9 != 0) && (*(int *)(iVar18 + 0x12) != 0)) {
        pbVar13 = (byte *)(*(int *)(iVar18 + 10) + iVar18);
        cVar8 = (**(code **)(*param_2 + 0x20))(0x40);
        if (cVar8 != '\0') {
          iVar9 = (**(code **)(*param_2 + 0xcc))();
          local_14 = (**(code **)(*param_2 + 0xd0))();
          local_14 = local_14 >> 1;
          puVar11 = (undefined4 *)(iVar9 + (param_3[1] * local_14 + *param_3) * 2);
          iVar9 = param_4[1] * local_14 + *param_4;
          local_c = puVar11;
          if (!bVar19) {
            local_c = (undefined4 *)((int)puVar11 + ((param_4[3] - param_4[1]) + -1) * local_14 * 2)
            ;
            local_14 = -local_14;
          }
          if (bVar7) {
            if (*(int *)(iVar18 + 0x1e) == 1) {
              iVar18 = 0;
              param_4 = local_c;
              iVar12 = *(int *)(param_1 + 0x24) + -1;
              param_3 = (int *)iVar12;
              if (*(int *)(param_1 + 0x28) == -1) {
                while( true ) {
                  while( true ) {
                    while( true ) {
                      pbVar14 = pbVar13 + 2;
                      if (*pbVar13 == 0) break;
                      uVar10 = (uint)*pbVar13;
                      if (((iVar12 < iVar4) || (iVar6 <= iVar12)) ||
                         (((iVar18 < iVar15 || (iVar5 <= iVar18)) &&
                          ((int)(uVar10 + iVar18) < iVar15)))) {
                        iVar18 = iVar18 + uVar10;
                        pbVar13 = pbVar14;
                      }
                      else {
                        uVar3 = *(undefined2 *)(*(int *)(param_1 + 8) + (uint)pbVar13[1] * 4);
                        puVar17 = param_4;
                        for (; pbVar13 = pbVar14, param_4 = puVar17, uVar10 != 0;
                            uVar10 = uVar10 - 1) {
                          if ((iVar15 <= iVar18) && (iVar18 < iVar5)) {
                            param_4 = (int *)((int)puVar17 + 2);
                            *(undefined2 *)puVar17 = uVar3;
                          }
                          iVar18 = iVar18 + 1;
                          puVar17 = param_4;
                        }
                      }
                    }
                    uVar10 = (uint)pbVar13[1];
                    if (uVar10 != 0) break;
                    if ((iVar4 <= iVar12) && (iVar12 < iVar6)) {
                      param_4 = (int *)((int)local_c + local_14 * 2);
                      local_c = param_4;
                    }
                    iVar12 = iVar12 + -1;
                    iVar18 = 0;
                    pbVar13 = pbVar14;
                    param_3 = (int *)iVar12;
                  }
                  if (uVar10 == 1) break;
                  if (uVar10 == 2) {
                    iVar18 = iVar18 + (uint)*pbVar14;
                    iVar12 = iVar12 - (uint)pbVar13[3];
                    if ((((iVar4 <= iVar12) && (iVar12 < iVar6)) &&
                        (local_c = (undefined4 *)
                                   ((int)puVar11 + (iVar12 * local_14 + iVar15) * 2 + iVar9 * -2),
                        iVar15 <= iVar18)) && (iVar18 < iVar5)) {
                      param_4 = (int *)((int)local_c + (iVar18 - iVar15) * 2);
                    }
                    pbVar13 = pbVar13 + 4;
                    param_3 = (int *)iVar12;
                  }
                  else {
                    if ((iVar12 < iVar4) || (iVar6 <= iVar12)) {
                      iVar18 = iVar18 + uVar10;
                      pbVar14 = pbVar14 + uVar10;
                    }
                    else {
                      iVar16 = 0;
                      if (uVar10 != 0) {
                        do {
                          if ((iVar15 <= iVar18) && (iVar18 < iVar5)) {
                            *(undefined2 *)param_4 =
                                 *(undefined2 *)(*(int *)(param_1 + 8) + (uint)*pbVar14 * 4);
                            iVar12 = (int)param_3;
                            param_4 = (undefined4 *)((int)param_4 + 2);
                          }
                          iVar16 = iVar16 + 1;
                          pbVar14 = pbVar14 + 1;
                          iVar18 = iVar18 + 1;
                        } while (iVar16 < (int)(uint)pbVar13[1]);
                      }
                    }
                    pbVar13 = pbVar14 + (pbVar13[1] & 1);
                  }
                }
              }
              else {
                while( true ) {
                  while( true ) {
                    while( true ) {
                      pbVar14 = pbVar13;
                      pbVar13 = pbVar14 + 2;
                      if (*pbVar14 == 0) break;
                      uVar10 = (uint)*pbVar14;
                      if (((iVar12 < iVar4) || (iVar6 <= iVar12)) ||
                         (((iVar18 < iVar15 || (iVar5 <= iVar18)) &&
                          ((int)(uVar10 + iVar18) < iVar15)))) {
                        iVar18 = iVar18 + uVar10;
                      }
                      else {
                        uVar3 = *(undefined2 *)(*(int *)(param_1 + 8) + (uint)pbVar14[1] * 4);
                        for (; iVar12 = (int)param_3, uVar10 != 0; uVar10 = uVar10 - 1) {
                          if ((iVar15 <= iVar18) && (iVar18 < iVar5)) {
                            if ((uint)pbVar14[1] != *(uint *)(param_1 + 0x28)) {
                              *(undefined2 *)param_4 = uVar3;
                            }
                            param_4 = (int *)((int)param_4 + 2);
                          }
                          iVar18 = iVar18 + 1;
                        }
                      }
                    }
                    uVar10 = (uint)pbVar14[1];
                    if (uVar10 != 0) break;
                    if ((iVar4 <= iVar12) && (iVar12 < iVar6)) {
                      param_4 = (int *)((int)local_c + local_14 * 2);
                      local_c = param_4;
                    }
                    param_3 = (int *)(iVar12 + -1);
                    iVar18 = 0;
                    iVar12 = (int)param_3;
                  }
                  if (uVar10 == 1) break;
                  if (uVar10 == 2) {
                    iVar18 = iVar18 + (uint)*pbVar13;
                    param_3 = (int *)(iVar12 - (uint)pbVar14[3]);
                    if ((((iVar4 <= (int)param_3) && ((int)param_3 < iVar6)) &&
                        (local_c = (undefined4 *)
                                   ((int)puVar11 +
                                   ((int)param_3 * local_14 + iVar15) * 2 + iVar9 * -2),
                        iVar15 <= iVar18)) && (iVar18 < iVar5)) {
                      param_4 = (int *)((int)local_c + (iVar18 - iVar15) * 2);
                    }
                    iVar12 = (int)param_3;
                    pbVar13 = pbVar14 + 4;
                  }
                  else {
                    if ((iVar12 < iVar4) || (iVar6 <= iVar12)) {
                      iVar18 = iVar18 + uVar10;
                      pbVar13 = pbVar13 + uVar10;
                    }
                    else {
                      local_28 = 0;
                      if (uVar10 != 0) {
                        do {
                          if ((iVar15 <= iVar18) && (iVar18 < iVar5)) {
                            if ((uint)*pbVar13 != *(uint *)(param_1 + 0x28)) {
                              *(undefined2 *)param_4 =
                                   *(undefined2 *)(*(int *)(param_1 + 8) + (uint)*pbVar13 * 4);
                            }
                            param_4 = (int *)((int)param_4 + 2);
                          }
                          local_28 = local_28 + 1;
                          pbVar13 = pbVar13 + 1;
                          iVar18 = iVar18 + 1;
                          iVar12 = (int)param_3;
                        } while (local_28 < (int)(uint)pbVar14[1]);
                      }
                    }
                    pbVar13 = pbVar13 + (pbVar14[1] & 1);
                  }
                }
              }
            }
          }
          else if (*(int *)(iVar18 + 0x1e) == 1) {
            puVar11 = local_c;
            if (*(int *)(param_1 + 0x28) == -1) {
              while( true ) {
                while( true ) {
                  while( true ) {
                    pbVar14 = pbVar13 + 2;
                    bVar2 = *pbVar13;
                    if (bVar2 == 0) break;
                    uVar3 = *(undefined2 *)(*(int *)(param_1 + 8) + (uint)pbVar13[1] * 4);
                    if (bVar2 != 0) {
                      puVar17 = puVar11;
                      for (uVar10 = (uint)(bVar2 >> 1); uVar10 != 0; uVar10 = uVar10 - 1) {
                        *puVar17 = CONCAT22(uVar3,uVar3);
                        puVar17 = puVar17 + 1;
                      }
                      for (uVar10 = (uint)((bVar2 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
                        *(undefined2 *)puVar17 = uVar3;
                        puVar17 = (undefined4 *)((int)puVar17 + 2);
                      }
                    }
                    puVar11 = (undefined4 *)((int)puVar11 + (uint)bVar2 * 2);
                    pbVar13 = pbVar14;
                  }
                  bVar2 = pbVar13[1];
                  if (bVar2 != 0) break;
                  puVar11 = (undefined4 *)((int)local_c + local_14 * 2);
                  pbVar13 = pbVar14;
                  local_c = puVar11;
                }
                if (bVar2 == 1) break;
                if (bVar2 == 2) {
                  pbVar1 = pbVar13 + 3;
                  puVar11 = (undefined4 *)((int)puVar11 + ((uint)*pbVar14 + *pbVar1 * local_14) * 2)
                  ;
                  pbVar13 = pbVar13 + 4;
                  local_c = (undefined4 *)((int)local_c + *pbVar1 * local_14 * 2);
                }
                else {
                  iVar15 = 0;
                  if (bVar2 != 0) {
                    do {
                      iVar15 = iVar15 + 1;
                      *(undefined2 *)puVar11 =
                           *(undefined2 *)(*(int *)(param_1 + 8) + (uint)*pbVar14 * 4);
                      puVar11 = (undefined4 *)((int)puVar11 + 2);
                      pbVar14 = pbVar14 + 1;
                    } while (iVar15 < (int)(uint)pbVar13[1]);
                  }
                  pbVar13 = pbVar14 + (pbVar13[1] & 1);
                }
              }
            }
            else {
              while( true ) {
                while( true ) {
                  while( true ) {
                    pbVar14 = pbVar13 + 2;
                    bVar2 = *pbVar13;
                    if (bVar2 == 0) break;
                    if (((uint)pbVar13[1] != *(uint *)(param_1 + 0x28)) &&
                       (uVar3 = *(undefined2 *)(*(int *)(param_1 + 8) + (uint)pbVar13[1] * 4),
                       bVar2 != 0)) {
                      puVar17 = puVar11;
                      for (uVar10 = (uint)(bVar2 >> 1); uVar10 != 0; uVar10 = uVar10 - 1) {
                        *puVar17 = CONCAT22(uVar3,uVar3);
                        puVar17 = puVar17 + 1;
                      }
                      for (uVar10 = (uint)((bVar2 & 1) != 0); uVar10 != 0; uVar10 = uVar10 - 1) {
                        *(undefined2 *)puVar17 = uVar3;
                        puVar17 = (undefined4 *)((int)puVar17 + 2);
                      }
                    }
                    puVar11 = (undefined4 *)((int)puVar11 + (uint)bVar2 * 2);
                    pbVar13 = pbVar14;
                  }
                  bVar2 = pbVar13[1];
                  if (bVar2 != 0) break;
                  puVar11 = (undefined4 *)((int)local_c + local_14 * 2);
                  pbVar13 = pbVar14;
                  local_c = puVar11;
                }
                if (bVar2 == 1) break;
                if (bVar2 == 2) {
                  pbVar1 = pbVar13 + 3;
                  puVar11 = (undefined4 *)((int)puVar11 + ((uint)*pbVar14 + *pbVar1 * local_14) * 2)
                  ;
                  pbVar13 = pbVar13 + 4;
                  local_c = (undefined4 *)((int)local_c + *pbVar1 * local_14 * 2);
                }
                else {
                  param_4 = (int *)0x0;
                  if (bVar2 != 0) {
                    do {
                      if ((uint)*pbVar14 != *(uint *)(param_1 + 0x28)) {
                        *(undefined2 *)puVar11 =
                             *(undefined2 *)(*(int *)(param_1 + 8) + (uint)*pbVar14 * 4);
                      }
                      param_4 = (int *)((int)param_4 + 1);
                      puVar11 = (undefined4 *)((int)puVar11 + 2);
                      pbVar14 = pbVar14 + 1;
                    } while ((int)param_4 < (int)(uint)pbVar13[1]);
                  }
                  pbVar13 = pbVar14 + (pbVar13[1] & 1);
                }
              }
            }
          }
          (**(code **)(*param_2 + 0x24))(0x40);
          return 1;
        }
      }
    }
  }
  return 0;
}

