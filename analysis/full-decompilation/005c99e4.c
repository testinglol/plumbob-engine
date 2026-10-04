
int FUN_005c99e4(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  uint *puVar1;
  char cVar2;
  byte bVar6;
  undefined2 uVar3;
  int iVar4;
  char cVar7;
  char *pcVar5;
  char *pcVar8;
  undefined4 *puVar9;
  undefined2 *puVar10;
  undefined1 *puVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined2 *puVar15;
  undefined1 local_950 [1024];
  undefined4 local_550;
  undefined4 local_150;
  uint local_14c;
  int local_148;
  undefined4 local_144;
  undefined4 local_108 [8];
  undefined4 local_e8;
  char local_d4;
  char local_d3;
  undefined1 local_c4 [4];
  undefined4 local_c0;
  int local_bc;
  char local_b8;
  short sStack_b6;
  undefined2 local_b4;
  undefined2 uStack_b2;
  uint local_a4;
  undefined4 local_98 [2];
  int local_90;
  undefined2 *local_8c;
  int local_88;
  undefined2 *local_74;
  byte local_4c;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint *local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  undefined2 *local_1c;
  void *local_18;
  int *local_14;
  undefined4 local_10;
  undefined2 *local_c;
  char local_5;
  
  local_5 = '\0';
  local_14 = (int *)0x0;
  local_28 = (int *)0x0;
  local_20 = (int *)0x0;
  local_18 = (void *)0x0;
  (**(code **)(*param_3 + 4))(0);
  FUN_005b903c(0x1000,0);
  cVar2 = FUN_005b904f(&local_d4,0xe);
  if (cVar2 == '\0') {
LAB_005c9a30:
    iVar12 = -0x64f4ffee;
    goto LAB_005ca496;
  }
  if ((local_d4 != 'B') || (local_d3 != 'M')) {
    iVar12 = -0x64f4ffe9;
    goto LAB_005ca496;
  }
  cVar2 = FUN_005b904f(local_c4,0x28);
  if (cVar2 == '\0') goto LAB_005c9a30;
  if (local_bc < 0) {
    local_5 = '\x01';
  }
  if ((sStack_b6 != 0x18) || (local_a4 != 0)) {
    uVar13 = local_a4;
    if (local_a4 == 0) {
      uVar13 = 1 << (local_b8 * (char)sStack_b6 & 0x1fU);
    }
    if (0x100 < (ushort)uVar13) {
LAB_005c9aaa:
      iVar12 = -0x64f4ffe7;
      goto LAB_005ca496;
    }
    _memset(&local_550,0,0x400);
    _memset(local_950,0,0x400);
    uVar13 = uVar13 & 0xffff;
    cVar2 = FUN_005b904f(local_950,uVar13 << 2);
    if (cVar2 == '\0') goto LAB_005c9a30;
    iVar12 = 0;
    if (uVar13 != 0) {
      do {
        iVar4 = iVar12 * 4;
        *(undefined1 *)(&local_550 + iVar12) = local_950[iVar4 + 2];
        *(undefined1 *)((int)&local_550 + iVar4 + 1) = local_950[iVar4 + 1];
        *(undefined1 *)((int)&local_550 + iVar4 + 2) = local_950[iVar4];
        *(undefined1 *)((int)&local_550 + iVar4 + 3) = 0xff;
        iVar12 = iVar12 + 1;
      } while (iVar12 < (int)uVar13);
    }
  }
  _memset(&local_150,0,0x7c);
  local_150 = 0x7c;
  local_14c = 1;
  local_e8 = 0x840;
  iVar12 = 8;
  if (param_2 != (undefined4 *)0x0) {
    local_14c = 0x1001;
    puVar9 = param_2;
    puVar14 = local_108;
    for (; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar14 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar14 = puVar14 + 1;
    }
  }
  local_14c = local_14c | 6;
  local_144 = local_c0;
  local_148 = local_bc;
  iVar12 = (**(code **)(**(int **)(local_24 + 0x74) + 0x18))
                     (*(int **)(local_24 + 0x74),&local_150,&local_28,0);
  if (iVar12 != 0) goto LAB_005ca496;
  if (local_14 != (int *)0x0) {
LAB_005c9c11:
    iVar12 = (**(code **)(*local_14 + 100))(local_14,0,local_98,0,0);
    if (iVar12 == 0) {
      if ((local_4c & 0x40) != 0) {
        if (sStack_b6 == 8) {
          if (local_44 == 8) {
            if (CONCAT22(uStack_b2,local_b4) == 0) {
              puVar10 = local_74;
              if (local_5 == '\0') {
                puVar10 = (undefined2 *)((local_90 + -1) * local_88 + (int)local_74);
              }
              do {
                if (local_5 == '\0') {
                  iVar12 = -local_88;
                }
                else {
                  iVar12 = local_88 * local_90;
                }
                if (puVar10 == (undefined2 *)(iVar12 + (int)local_74)) goto LAB_005c9cf3;
                cVar2 = FUN_005b904f(puVar10,local_8c);
                iVar12 = ((int)local_8c + 3U & 0xfffffffc) - (int)local_8c;
                if (iVar12 != 0) {
                  if (cVar2 == '\0') goto LAB_005c9a30;
                  FUN_005b904f((int)&param_2 + 3,iVar12);
                }
                if (cVar2 == '\0') goto LAB_005c9a30;
                iVar12 = local_88;
                if (local_5 == '\0') {
                  iVar12 = -local_88;
                }
                puVar10 = (undefined2 *)((int)puVar10 + iVar12);
              } while( true );
            }
            if (CONCAT22(uStack_b2,local_b4) == 1) {
              puVar10 = local_74;
              local_c = local_74;
              if (local_5 == '\0') {
                local_c = (undefined2 *)((local_90 + -1) * local_88 + (int)local_74);
                local_88 = -local_88;
                puVar10 = local_c;
              }
              while (cVar2 = FUN_005b904f((int)&param_2 + 2,2), cVar2 != '\0') {
                bVar6 = (byte)((uint)param_2 >> 0x18);
                if ((char)((uint)param_2 >> 0x10) == '\0') {
                  if (bVar6 == 0) {
                    local_c = (undefined2 *)((int)local_c + local_88);
                    puVar10 = local_c;
                  }
                  else {
                    if (bVar6 == 1) goto LAB_005c9cf3;
                    if (bVar6 == 2) {
                      cVar2 = FUN_005b904f((int)&local_10 + 2,2);
                      if (cVar2 == '\0') break;
                      local_c = (undefined2 *)((int)local_c + local_10._3_1_ * local_88);
                      puVar10 = (undefined2 *)((int)local_10._2_1_ + (int)local_c);
                    }
                    else {
                      cVar2 = FUN_005b904f(puVar10,bVar6);
                      if (cVar2 == '\0') break;
                      puVar10 = (undefined2 *)((int)puVar10 + ((uint)param_2 >> 0x18));
                      if (((uint)param_2 & 0x1000000) != 0) {
                        iVar4 = FUN_005b8fe4();
                        FUN_005b8f4a(iVar4 + 1);
                      }
                    }
                  }
                }
                else {
                  uVar13 = (uint)param_2 >> 0x10 & 0xff;
                  _memset(puVar10,(uint)bVar6,uVar13);
                  puVar10 = (undefined2 *)((int)puVar10 + uVar13);
                }
              }
              goto LAB_005ca496;
            }
          }
          else {
            if (local_44 != 0x10) {
LAB_005ca0ce:
              iVar12 = -0x64f4ffe8;
              goto LAB_005ca496;
            }
            if (local_40 == 0x7c00) {
              if ((local_3c != 0x3e0) || (local_38 != 0x1f)) goto LAB_005ca0ce;
              local_c = (undefined2 *)0x1;
            }
            else if (local_40 == 0xf800) {
              if (local_3c == 0x7e0) {
                if (local_38 != 0x1f) goto LAB_005ca0ce;
                local_c = (undefined2 *)0x2;
              }
              else {
                if ((local_3c != 0x7c0) || (local_38 != 0x3f)) goto LAB_005ca0ce;
                local_c = (undefined2 *)0x3;
              }
            }
            else {
              if (((local_40 != 0xfc00) || (local_3c != 0x3e0)) || (local_38 != 0x1f))
              goto LAB_005ca0ce;
              local_c = (undefined2 *)0x4;
            }
            if (CONCAT22(uStack_b2,local_b4) == 0) {
              puVar10 = local_74;
              if (local_5 == '\0') {
                puVar10 = (undefined2 *)((local_90 + -1) * local_88 + (int)local_74);
              }
              do {
                if (local_5 == '\0') {
                  iVar12 = -local_88;
                }
                else {
                  iVar12 = local_88 * local_90;
                }
                if (puVar10 == (undefined2 *)(iVar12 + (int)local_74)) goto LAB_005c9fb9;
                cVar2 = FUN_005b904f(puVar10,local_8c);
                iVar12 = ((int)local_8c + 3U & 0xfffffffc) - (int)local_8c;
                if (iVar12 != 0) {
                  if (cVar2 == '\0') goto LAB_005c9a30;
                  cVar2 = FUN_005b904f((int)&param_2 + 3,iVar12);
                }
                if (cVar2 == '\0') goto LAB_005c9a30;
                iVar12 = (int)local_8c + -1;
                if (-1 < iVar12) {
                  puVar15 = puVar10 + iVar12;
                  do {
                    uVar3 = FUN_005ca4e5(&local_550 + *(byte *)(iVar12 + (int)puVar10),local_c);
                    *puVar15 = uVar3;
                    iVar12 = iVar12 + -1;
                    puVar15 = puVar15 + -1;
                  } while (-1 < iVar12);
                }
                if (local_5 == '\0') {
                  iVar12 = local_88 / -2;
                }
                else {
                  iVar12 = local_88 / 2;
                }
                puVar10 = puVar10 + iVar12;
              } while( true );
            }
            if (CONCAT22(uStack_b2,local_b4) == 1) {
              param_2 = (undefined4 *)((uint)param_2 & 0xffffff);
              puVar10 = (undefined2 *)((local_90 + -1) * local_88 + (int)local_74);
              do {
                if (puVar10 == (undefined2 *)((int)local_74 - local_88)) break;
                iVar12 = 0;
                while( true ) {
                  while( true ) {
                    FUN_005b904f((int)&local_10 + 2,2);
                    cVar2 = (char)(local_10 >> 0x10);
                    cVar7 = (char)(local_10 >> 0x18);
                    if (cVar2 == '\0') break;
                    iVar4 = 0;
                    if (cVar2 != '\0') {
                      do {
                        *(char *)(iVar12 + (int)puVar10) = cVar7;
                        iVar12 = iVar12 + 1;
                        iVar4 = iVar4 + 1;
                      } while (iVar4 < (int)(local_10 >> 0x10 & 0xff));
                    }
                  }
                  if (cVar7 == '\0') goto LAB_005ca089;
                  if (cVar7 == '\x01') break;
                  if (cVar7 != '\x02') {
                    cVar2 = FUN_005b904f(iVar12 + (int)puVar10,cVar7);
                    iVar12 = iVar12 + (local_10 >> 0x18);
                    if (cVar2 == '\0') goto LAB_005c9a30;
                    if ((local_10 & 0x1000000) != 0) {
                      cVar2 = FUN_005b904f(&local_5,1);
                    }
                    if (cVar2 == '\0') goto LAB_005c9a30;
                  }
                }
                param_2 = (undefined4 *)CONCAT13(1,param_2._0_3_);
LAB_005ca089:
                iVar12 = (int)local_8c + -1;
                if (-1 < iVar12) {
                  puVar15 = puVar10 + iVar12;
                  do {
                    uVar3 = FUN_005ca4e5(&local_550 + *(byte *)(iVar12 + (int)puVar10),local_c);
                    *puVar15 = uVar3;
                    iVar12 = iVar12 + -1;
                    puVar15 = puVar15 + -1;
                  } while (-1 < iVar12);
                }
                puVar10 = (undefined2 *)((int)puVar10 - local_88);
              } while (param_2._3_1_ == '\0');
LAB_005c9fb9:
              iVar12 = (**(code **)(*local_14 + 0x80))(local_14,0);
              goto LAB_005c9fc7;
            }
          }
        }
        else {
          if (sStack_b6 != 0x18) goto LAB_005ca46e;
          if (CONCAT22(uStack_b2,local_b4) == 0) {
            local_18 = operator_new((int)local_8c * 3);
            if (local_18 != (void *)0x0) {
              if (local_44 == 8) {
                local_c = (undefined2 *)0x0;
                puVar10 = local_74;
                if (local_5 == '\0') {
                  puVar10 = (undefined2 *)((local_90 + -1) * local_88 + (int)local_74);
                }
                do {
                  if (local_5 == '\0') {
                    iVar12 = -local_88;
                  }
                  else {
                    iVar12 = local_88 * local_90;
                  }
                  local_1c = puVar10;
                  if (puVar10 == (undefined2 *)(iVar12 + (int)local_74)) {
                    iVar12 = (**(code **)(*local_14 + 0x80))(local_14,0);
                    if ((iVar12 != 0) ||
                       (iVar12 = (**(code **)(**(int **)(local_24 + 0x70) + 0x14))
                                           (*(int **)(local_24 + 0x70),0x44,&local_550,&local_20,0),
                       iVar12 != 0)) goto LAB_005ca496;
                    iVar12 = (**(code **)(*local_14 + 0x7c))(local_14,local_20);
                    goto LAB_005ca45f;
                  }
                  cVar2 = FUN_005b904f(local_18,(int)local_8c * 3);
                  iVar12 = ((int)local_8c + 3U & 0xfffffffc) - (int)local_8c;
                  if (iVar12 != 0) {
                    if (cVar2 == '\0') goto LAB_005c9a30;
                    cVar2 = FUN_005b904f(&param_2,iVar12);
                  }
                  if (cVar2 == '\0') goto LAB_005c9a30;
                  if ((int)local_8c * 3 != 0) {
                    local_10 = 0;
                    pcVar8 = (char *)((int)local_18 + 1);
                    local_2c = &local_550 + (int)local_c;
                    iVar12 = -1 - (int)local_18;
                    do {
                      puVar10 = local_c;
                      puVar1 = local_2c;
                      puVar15 = (undefined2 *)0x0;
                      local_10._0_3_ = CONCAT12(pcVar8[-1],CONCAT11(*pcVar8,pcVar8[1]));
                      if (0 < (int)local_c) {
                        pcVar5 = (char *)((int)&local_550 + 1);
                        do {
                          if (((pcVar5[-1] == pcVar8[1]) && (*pcVar5 == *pcVar8)) &&
                             (pcVar5[1] == pcVar8[-1])) goto LAB_005ca22c;
                          puVar15 = (undefined2 *)((int)puVar15 + 1);
                          pcVar5 = pcVar5 + 4;
                        } while ((int)puVar15 < (int)local_c);
                      }
                      if (0xff < (int)local_c) goto LAB_005c9aaa;
                      local_c = (undefined2 *)((int)local_c + 1);
                      local_2c = local_2c + 1;
                      *puVar1 = local_10;
                      puVar15 = puVar10;
LAB_005ca22c:
                      pcVar5 = pcVar8 + iVar12;
                      pcVar8 = pcVar8 + 3;
                      *(char *)((uint)pcVar5 / 3 + (int)local_1c) = (char)puVar15;
                      puVar10 = local_1c;
                    } while (pcVar8 + iVar12 < (char *)((int)local_8c * 3));
                  }
                  iVar12 = local_88;
                  if (local_5 == '\0') {
                    iVar12 = -local_88;
                  }
                  puVar10 = (undefined2 *)((int)puVar10 + iVar12);
                } while( true );
              }
              if (local_44 == 0x10) {
                if (local_40 == 0x7c00) {
                  if ((local_3c == 0x3e0) && (local_38 == 0x1f)) {
                    local_c = (undefined2 *)0x1;
                    goto LAB_005ca360;
                  }
                }
                else if (local_40 == 0xf800) {
                  if (local_3c == 0x7e0) {
                    if (local_38 == 0x1f) {
                      local_c = (undefined2 *)0x2;
LAB_005ca360:
                      puVar10 = local_74;
                      if (local_5 == '\0') {
                        puVar10 = (undefined2 *)((local_90 + -1) * local_88 + (int)local_74);
                      }
LAB_005ca384:
                      if (local_5 == '\0') {
                        iVar12 = -local_88;
                      }
                      else {
                        iVar12 = local_88 * local_90;
                      }
                      if (puVar10 == (undefined2 *)(iVar12 + (int)local_74)) {
                        iVar12 = (**(code **)(*local_14 + 0x80))(local_14,0);
LAB_005ca45f:
                        if (iVar12 == 0) {
                          FUN_006321f0(local_18);
                          goto LAB_005ca46e;
                        }
                        goto LAB_005ca496;
                      }
                      cVar2 = FUN_005b904f(local_18,(int)local_8c * 3);
                      if (((uint)local_8c & 3) != 0) {
                        if (cVar2 == '\0') goto LAB_005c9a30;
                        cVar2 = FUN_005b904f(&param_2,(uint)local_8c & 3);
                      }
                      if (cVar2 != '\0') goto code_r0x005ca3de;
                      goto LAB_005c9a30;
                    }
                  }
                  else if ((local_3c == 0x7c0) && (local_38 == 0x3f)) {
                    local_c = (undefined2 *)0x3;
                    goto LAB_005ca360;
                  }
                }
                else if (((local_40 == 0xfc00) && (local_3c == 0x3e0)) && (local_38 == 0x1f)) {
                  local_c = (undefined2 *)0x4;
                  goto LAB_005ca360;
                }
              }
              goto LAB_005ca0ce;
            }
            iVar12 = -0x64f4ffff;
            goto LAB_005ca496;
          }
        }
      }
      iVar12 = -0x64f4ffe6;
    }
    goto LAB_005ca496;
  }
  if (local_28 != (int *)0x0) {
    (**(code **)*local_28)(local_28,&DAT_00677308,&local_14);
    if (local_14 != (int *)0x0) {
      FUN_00636510(local_98,&local_150,0x6c);
      local_98[0] = 0x6c;
      goto LAB_005c9c11;
    }
    goto LAB_005ca4a5;
  }
  goto LAB_005ca4b2;
code_r0x005ca3de:
  local_1c = (undefined2 *)0x0;
  if (local_8c != (undefined2 *)0x0) {
    puVar11 = (undefined1 *)((int)local_18 + 1);
    puVar15 = puVar10;
    do {
      local_10._0_3_ = CONCAT12(puVar11[-1],CONCAT11(*puVar11,puVar11[1]));
      local_10 = (uint)(uint3)local_10;
      uVar3 = FUN_005ca4e5(&local_10,local_c);
      local_1c = (undefined2 *)((int)local_1c + 1);
      *puVar15 = uVar3;
      puVar11 = puVar11 + 3;
      puVar15 = puVar15 + 1;
    } while (local_1c < local_8c);
  }
  if (local_5 == '\0') {
    iVar12 = local_88 / -2;
  }
  else {
    iVar12 = local_88 / 2;
  }
  puVar10 = puVar10 + iVar12;
  goto LAB_005ca384;
LAB_005c9cf3:
  iVar12 = (**(code **)(*local_14 + 0x80))(local_14,0);
  if ((iVar12 != 0) ||
     (iVar12 = (**(code **)(**(int **)(local_24 + 0x70) + 0x14))
                         (*(int **)(local_24 + 0x70),0x44,&local_550,&local_20,0), iVar12 != 0))
  goto LAB_005ca496;
  iVar12 = (**(code **)(*local_14 + 0x7c))(local_14,local_20);
LAB_005c9fc7:
  if (iVar12 == 0) {
LAB_005ca46e:
    (**(code **)(*param_3 + 4))(local_14);
    (**(code **)(*local_14 + 8))(local_14);
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))(local_28);
    }
    goto LAB_005ca4d6;
  }
LAB_005ca496:
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
LAB_005ca4a5:
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
LAB_005ca4b2:
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  if (local_18 != (void *)0x0) {
    FUN_006321f0(local_18);
  }
  (**(code **)(*param_3 + 4))(0);
LAB_005ca4d6:
  *(int *)(local_24 + 4) = iVar12;
  return iVar12;
}

