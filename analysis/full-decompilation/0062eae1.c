
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0062eae1(int param_1,float *param_2,int param_3,float *param_4)

{
  float fVar1;
  char cVar2;
  uint uVar3;
  bool bVar4;
  float fVar5;
  undefined4 *puVar6;
  float *pfVar7;
  int iVar8;
  int extraout_ECX;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  uint uVar14;
  uint *puVar15;
  float *pfVar16;
  float local_1228 [576];
  uint local_928 [576];
  int local_28;
  float *local_24;
  undefined4 uStack_20;
  float *local_1c;
  uint local_18;
  float *local_14;
  int iVar17;
  
  puVar9 = param_2;
  FUN_00636080();
  local_28 = extraout_ECX;
  if (*(int *)(extraout_ECX + 0x4a40) == 1) {
    param_4 = (float *)0x20;
    puVar9 = (undefined4 *)(param_3 + 8);
    puVar6 = param_2;
    do {
      iVar13 = 6;
      do {
        *puVar6 = *(undefined4 *)((param_3 - (int)param_2) + (int)puVar6);
        puVar6[1] = puVar9[-1];
        puVar6[2] = *puVar9;
        puVar6 = puVar6 + 3;
        puVar9 = puVar9 + 3;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      param_4 = (float *)((int)param_4 + -1);
    } while (param_4 != (float *)0x0);
  }
  else {
    iVar13 = extraout_ECX + 0x34e4 + param_1 * 0x48;
    if ((*(char *)(extraout_ECX + 0x4a16) == '\x01') &&
       ((*(byte *)(extraout_ECX + 0x4a17) & 2) != 0)) {
      uStack_20 = CONCAT13(1,(undefined3)uStack_20);
    }
    else {
      uStack_20 = uStack_20 & 0xffffff;
    }
    if ((*(char *)(extraout_ECX + 0x4a16) == '\x01') &&
       ((*(byte *)(extraout_ECX + 0x4a17) & 1) != 0)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    local_24 = (float *)(*(uint *)(iVar13 + 0xc) & 1);
    puVar15 = local_928;
    for (iVar10 = 0x240; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar15 = 7;
      puVar15 = puVar15 + 1;
    }
    if (bVar4) {
      if ((*(int *)(iVar13 + 0x10) == 0) || (*(int *)(iVar13 + 0x14) != 2)) {
        iVar10 = 0x1f;
        iVar8 = 0x46e;
        iVar13 = 0x11;
        do {
          if (*(float *)(param_3 + (iVar8 + iVar13) * 4) != _DAT_0066657c) {
            iVar13 = iVar13 + iVar10 * 0x12;
            goto LAB_0062f099;
          }
          iVar13 = iVar13 + -1;
          if (iVar13 < 0) {
            iVar10 = iVar10 + -1;
            iVar8 = iVar8 + -0x12;
            iVar13 = 0x11;
          }
        } while (0x23f < iVar8);
        iVar13 = 0;
LAB_0062f099:
        uVar14 = (uint)*(byte *)(extraout_ECX + 0x4a0f);
        iVar10 = 0;
        if (*(short *)(&DAT_0067d778 + uVar14 * 0x4a) <= iVar13) {
          psVar12 = (short *)(&DAT_0067d778 + uVar14 * 0x4a);
          do {
            iVar10 = iVar10 + 1;
            psVar12 = psVar12 + 1;
          } while (*psVar12 <= iVar13);
        }
        iVar13 = (int)*(short *)(&DAT_0067d778 + (uVar14 * 0x25 + iVar10) * 2);
        local_18 = iVar13;
        if (iVar10 < 0x15) {
          puVar15 = (uint *)(extraout_ECX + 0x370c + iVar10 * 4);
          do {
            iVar8 = ((uint)*(byte *)(extraout_ECX + 0x4a0f) * 0x25 + iVar10) * 2;
            iVar8 = (int)*(short *)(&DAT_0067d77a + iVar8) - (int)*(short *)(&DAT_0067d778 + iVar8);
            if (0 < iVar8) {
              do {
                uVar14 = *puVar15;
                local_928[iVar13] = uVar14;
                if (uVar14 != 7) {
                  if (*(char *)(extraout_ECX + 0x4a0e) == '\0') {
                    local_1228[iVar13] = *(float *)(&DAT_00685b34 + uVar14 * 4);
                  }
                  else {
                    local_14 = param_4;
                    local_1c = local_24;
                    local_24 = (float *)0x62f132;
                    uStack_20 = uVar14;
                    local_18 = iVar13;
                    FUN_0062ea80();
                  }
                }
                iVar13 = iVar13 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
            puVar15 = puVar15 + 1;
            iVar10 = iVar10 + 1;
          } while (iVar10 < 0x15);
          local_18 = iVar13;
        }
        iVar10 = (uint)*(byte *)(extraout_ECX + 0x4a0f) * 0x4a;
        iVar8 = (int)*(short *)(&DAT_0067d7a0 + iVar10);
        iVar10 = 0x240 - *(short *)(&DAT_0067d7a2 + iVar10);
        if (0 < iVar10) {
          pfVar7 = param_4 + iVar13;
          local_14 = (float *)((int)local_1228 - (int)param_4);
          local_18 = iVar13;
          do {
            if (0x23f < (int)local_18) break;
            cVar2 = *(char *)(extraout_ECX + 0x4a0e);
            *(uint *)(((int)local_928 - (int)param_4) + (int)pfVar7) = local_928[iVar8];
            if (cVar2 == '\0') {
              *(float *)(((int)local_1228 - (int)param_4) + (int)pfVar7) = local_1228[iVar8];
            }
            else {
              *pfVar7 = param_4[iVar8];
              pfVar7[0x240] = param_4[iVar8 + 0x240];
            }
            local_18 = local_18 + 1;
            pfVar7 = pfVar7 + 1;
            iVar10 = iVar10 + -1;
          } while (0 < iVar10);
        }
      }
      else if (*(int *)(iVar13 + 0x18) == 0) {
        local_14 = (float *)0x0;
        local_18 = 0xdda;
        do {
          iVar10 = -1;
          local_1c = (float *)((int)local_14 + 1);
          iVar13 = 0xc;
          do {
            iVar8 = (iVar13 + (uint)*(byte *)(extraout_ECX + 0x4a0f) * 0x25) * 2;
            iVar11 = (int)*(short *)(&DAT_0067d7a8 + iVar8) - (int)*(short *)(&DAT_0067d7a6 + iVar8)
            ;
            iVar8 = (int)local_1c * iVar11 + -1 + *(short *)(&DAT_0067d7a6 + iVar8) * 3;
            for (; 0 < iVar11; iVar11 = iVar11 + -1) {
              iVar17 = iVar13;
              if (*(float *)(param_3 +
                            ((int)(char)(&DAT_00685db4)[iVar8] +
                            ((char)(&DAT_00685b74)[iVar8] + 0x20) * 0x12) * 4) != _DAT_0066657c) {
                local_14 = (float *)0xfffffff6;
                iVar11 = -10;
                iVar17 = -10;
                iVar10 = iVar13;
              }
              iVar8 = iVar8 + -1;
              iVar13 = iVar17;
            }
            iVar13 = iVar13 + -1;
          } while (-1 < iVar13);
          while( true ) {
            iVar10 = iVar10 + 1;
            if (0xb < iVar10) break;
            iVar8 = ((uint)*(byte *)(extraout_ECX + 0x4a0f) * 0x25 + iVar10) * 2;
            iVar13 = (int)*(short *)(&DAT_0067d7a8 + iVar8) - (int)*(short *)(&DAT_0067d7a6 + iVar8)
            ;
            uVar14 = (int)local_14 * iVar13 + *(short *)(&DAT_0067d7a6 + iVar8) * 3;
            if (0 < iVar13) {
              iVar8 = local_18 + iVar10;
              do {
                uVar3 = *(uint *)(extraout_ECX + iVar8 * 4);
                local_928[uVar14] = uVar3;
                if (uVar3 != 7) {
                  if (*(char *)(extraout_ECX + 0x4a0e) == '\0') {
                    local_1228[uVar14] = *(float *)(&DAT_00685b34 + uVar3 * 4);
                  }
                  else {
                    local_14 = param_4;
                    local_1c = local_24;
                    local_24 = (float *)0x62ef8f;
                    uStack_20 = uVar3;
                    local_18 = uVar14;
                    FUN_0062ea80();
                  }
                }
                uVar14 = uVar14 + 1;
                iVar13 = iVar13 + -1;
              } while (iVar13 != 0);
            }
          }
          iVar13 = (uint)*(byte *)(extraout_ECX + 0x4a0f) * 0x4a;
          iVar8 = (int)*(short *)(&DAT_0067d7bc + iVar13);
          iVar10 = (iVar8 - *(short *)(&DAT_0067d7ba + iVar13)) * (int)local_14 +
                   *(short *)(&DAT_0067d7ba + iVar13) * 3;
          iVar13 = *(short *)(&DAT_0067d7be + iVar13) - iVar8;
          if (0 < iVar13) {
            pfVar7 = param_4 + (int)local_14 * iVar13 + iVar8 * 3;
            do {
              cVar2 = *(char *)(extraout_ECX + 0x4a0e);
              *(uint *)(((int)local_928 - (int)param_4) + (int)pfVar7) = local_928[iVar10];
              if (cVar2 == '\0') {
                *(float *)(((int)local_1228 - (int)param_4) + (int)pfVar7) = local_1228[iVar10];
              }
              else {
                *pfVar7 = param_4[iVar10];
                pfVar7[0x240] = param_4[iVar10 + 0x240];
              }
              pfVar7 = pfVar7 + 1;
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
          }
          local_18 = local_18 + 0xd;
          local_14 = local_1c;
        } while (local_18 < 0xe01);
      }
      else {
        iVar13 = 0;
        local_14 = (float *)0x0;
        local_18 = 0xdda;
        do {
          pfVar7 = (float *)((int)local_14 + 1);
          local_1c = (float *)0x2;
          iVar10 = 0xc;
          do {
            iVar8 = (iVar10 + (uint)*(byte *)(extraout_ECX + 0x4a0f) * 0x25) * 2;
            iVar11 = (int)*(short *)(&DAT_0067d7a8 + iVar8) - (int)*(short *)(&DAT_0067d7a6 + iVar8)
            ;
            iVar8 = (int)pfVar7 * iVar11 + -1 + *(short *)(&DAT_0067d7a6 + iVar8) * 3;
            for (; 0 < iVar11; iVar11 = iVar11 + -1) {
              iVar17 = iVar10;
              if (*(float *)(param_3 +
                            ((int)(char)(&DAT_00685db4)[iVar8] +
                            ((char)(&DAT_00685b74)[iVar8] + 0x20) * 0x12) * 4) != _DAT_0066657c) {
                local_14 = (float *)0xfffffff6;
                iVar11 = -10;
                iVar17 = -10;
                local_1c = (float *)iVar10;
              }
              iVar8 = iVar8 + -1;
              iVar10 = iVar17;
            }
            iVar10 = iVar10 + -1;
          } while (2 < iVar10);
          iVar10 = (int)local_1c + 1;
          if (iVar13 < iVar10) {
            iVar13 = iVar10;
          }
          while( true ) {
            if (0xb < iVar10) break;
            iVar8 = ((uint)*(byte *)(extraout_ECX + 0x4a0f) * 0x25 + iVar10) * 2;
            local_1c = (float *)((int)*(short *)(&DAT_0067d7a8 + iVar8) -
                                (int)*(short *)(&DAT_0067d7a6 + iVar8));
            uVar14 = (int)local_14 * (int)local_1c + *(short *)(&DAT_0067d7a6 + iVar8) * 3;
            if (0 < (int)local_1c) {
              iVar8 = local_18 + iVar10;
              do {
                uVar3 = *(uint *)(extraout_ECX + iVar8 * 4);
                local_928[uVar14] = uVar3;
                if (uVar3 != 7) {
                  if (*(char *)(extraout_ECX + 0x4a0e) == '\0') {
                    local_1228[uVar14] = *(float *)(&DAT_00685b34 + uVar3 * 4);
                  }
                  else {
                    local_14 = param_4;
                    local_1c = local_24;
                    local_24 = (float *)0x62ecc6;
                    uStack_20 = uVar3;
                    local_18 = uVar14;
                    FUN_0062ea80();
                  }
                }
                uVar14 = uVar14 + 1;
                local_1c = (float *)((int)local_1c + -1);
              } while (local_1c != (float *)0x0);
            }
            iVar10 = iVar10 + 1;
          }
          iVar10 = (uint)*(byte *)(extraout_ECX + 0x4a0f) * 0x4a;
          iVar11 = (int)*(short *)(&DAT_0067d7bc + iVar10);
          iVar8 = (iVar11 - *(short *)(&DAT_0067d7ba + iVar10)) * (int)local_14 +
                  *(short *)(&DAT_0067d7ba + iVar10) * 3;
          local_1c = (float *)(*(short *)(&DAT_0067d7be + iVar10) - iVar11);
          if (0 < (int)local_1c) {
            pfVar16 = param_4 + (int)local_14 * (int)local_1c + iVar11 * 3;
            do {
              cVar2 = *(char *)(extraout_ECX + 0x4a0e);
              *(uint *)(((int)local_928 - (int)param_4) + (int)pfVar16) = local_928[iVar8];
              if (cVar2 == '\0') {
                *(float *)(((int)local_1228 - (int)param_4) + (int)pfVar16) = local_1228[iVar8];
              }
              else {
                *pfVar16 = param_4[iVar8];
                pfVar16[0x240] = param_4[iVar8 + 0x240];
              }
              pfVar16 = pfVar16 + 1;
              local_1c = (float *)((int)local_1c + -1);
            } while (local_1c != (float *)0x0);
          }
          local_18 = local_18 + 0xd;
          local_14 = pfVar7;
        } while (local_18 < 0xe01);
        if (iVar13 < 4) {
          iVar10 = 2;
          iVar8 = 0x264;
          iVar13 = 0x11;
          do {
            if (*(float *)(param_3 + (iVar8 + iVar13) * 4) != _DAT_0066657c) {
              iVar13 = iVar13 + iVar10 * 0x12;
              goto LAB_0062edd6;
            }
            iVar13 = iVar13 + -1;
            if (iVar13 < 0) {
              iVar10 = iVar10 + -1;
              iVar8 = iVar8 + -0x12;
              iVar13 = 0x11;
            }
          } while (0x23f < iVar8);
          iVar13 = -1;
LAB_0062edd6:
          uVar14 = (uint)*(byte *)(extraout_ECX + 0x4a0f);
          iVar10 = 0;
          if (*(short *)(&DAT_0067d778 + uVar14 * 0x4a) <= iVar13) {
            psVar12 = (short *)(&DAT_0067d778 + uVar14 * 0x4a);
            do {
              iVar10 = iVar10 + 1;
              psVar12 = psVar12 + 1;
            } while (*psVar12 <= iVar13);
          }
          iVar13 = (int)*(short *)(&DAT_0067d778 + (uVar14 * 0x25 + iVar10) * 2);
          if (iVar10 < 8) {
            puVar15 = (uint *)(extraout_ECX + 0x370c + iVar10 * 4);
            do {
              iVar8 = ((uint)*(byte *)(extraout_ECX + 0x4a0f) * 0x25 + iVar10) * 2;
              iVar8 = (int)*(short *)(&DAT_0067d77a + iVar8) -
                      (int)*(short *)(&DAT_0067d778 + iVar8);
              if (0 < iVar8) {
                do {
                  uVar14 = *puVar15;
                  local_928[iVar13] = uVar14;
                  if (uVar14 != 7) {
                    if (*(char *)(extraout_ECX + 0x4a0e) == '\0') {
                      local_1228[iVar13] = *(float *)(&DAT_00685b34 + uVar14 * 4);
                    }
                    else {
                      local_14 = param_4;
                      local_1c = local_24;
                      local_24 = (float *)0x62ee70;
                      uStack_20 = uVar14;
                      local_18 = iVar13;
                      FUN_0062ea80();
                    }
                  }
                  iVar13 = iVar13 + 1;
                  iVar8 = iVar8 + -1;
                } while (iVar8 != 0);
              }
              puVar15 = puVar15 + 1;
              iVar10 = iVar10 + 1;
            } while (iVar10 < 8);
          }
        }
      }
    }
    fVar5 = _DAT_00687e28;
    iVar10 = 0;
    iVar13 = extraout_ECX;
    param_2 = param_4;
    do {
      iVar8 = 0;
      pfVar7 = param_2 + 0x12;
      do {
        if (*(int *)(((int)local_928 - (int)param_4) + (int)param_2) == 7) {
          iVar11 = iVar10 + iVar8;
          if (uStack_20._3_1_ == '\0') {
            puVar9[iVar11] = *(undefined4 *)(iVar11 * 4 + param_3);
            iVar11 = (iVar10 + iVar8) * 4 + 0x900;
            fVar1 = *(float *)(iVar11 + param_3);
          }
          else {
            iVar11 = iVar11 * 4 + 0x900;
            pfVar16 = (float *)(param_3 + (iVar10 + iVar8) * 4);
            puVar9[iVar10 + iVar8] = (*(float *)(iVar11 + param_3) + *pfVar16) * fVar5;
            fVar1 = (*pfVar16 - *(float *)(iVar11 + param_3)) * fVar5;
          }
          *(float *)(iVar11 + (int)puVar9) = fVar1;
        }
        else if (bVar4) {
          iVar11 = iVar10 + iVar8;
          if (*(char *)(iVar13 + 0x4a0e) == '\0') {
            fVar1 = *(float *)(iVar11 * 4 + param_3) /
                    (*(float *)((int)param_2 + ((int)local_1228 - (int)param_4)) + _DAT_00666748);
            puVar9[iVar10 + iVar8 + 0x240] = fVar1;
            puVar9[iVar11] = fVar1 * *(float *)((int)param_2 + ((int)local_1228 - (int)param_4));
            iVar13 = local_28;
          }
          else {
            pfVar16 = (float *)(param_3 + iVar11 * 4);
            puVar9[iVar11] = *param_2 * *pfVar16;
            puVar9[iVar10 + iVar8 + 0x240] = param_2[0x240] * *pfVar16;
          }
        }
        param_2 = param_2 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0x12);
      iVar10 = iVar10 + 0x12;
      param_2 = pfVar7;
    } while (iVar10 < 0x240);
  }
  return;
}

