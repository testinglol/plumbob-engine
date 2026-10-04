
int FUN_005a9e20(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  short *psVar8;
  short *psVar9;
  undefined2 *puVar10;
  int iVar11;
  uint uVar12;
  short *psVar13;
  undefined2 *puVar14;
  uint local_28;
  int local_24;
  int local_1c;
  
  iVar11 = 0;
  iVar2 = (&DAT_00703ea0)[param_5 & 0xf];
  if (-1 < param_2) {
    do {
      local_1c = 0;
      if (*(int *)(iVar2 + 0x38) != 0) {
        FUN_005b6820(*(int *)(iVar2 + 0x38));
      }
      iVar3 = *(int *)(iVar2 + 0x28);
      iVar4 = param_3;
      if ((param_3 == 0) && (iVar4 = iVar3, (param_5 & 0x40) != 0)) {
        iVar4 = *(int *)(iVar2 + 0x2c);
      }
      local_28 = iVar4 - 1;
      local_24 = FUN_005a9db0(param_1,param_5);
      local_24 = local_24 + param_2;
      if (local_24 < 8) {
        local_24 = 8;
      }
      iVar1 = local_24 + 0x10 + local_28;
      if ((param_5 & 0x20) == 0) {
        psVar8 = (short *)(iVar2 + 0x10);
        if ((param_5 & 0x10) == 0) {
          do {
            psVar8 = *(short **)(psVar8 + 8);
          } while (*(int *)(psVar8 + 2) < iVar1);
        }
        else {
          do {
            psVar8 = *(short **)(psVar8 + 10);
          } while (*(int *)(psVar8 + 2) < iVar1);
        }
        if (*psVar8 == 0x4253) {
          psVar8 = (short *)0x0;
        }
      }
      else {
        psVar13 = (short *)(iVar2 + 0x10);
        uVar12 = iVar1 - 1U & ((int)(iVar1 - 1U) < 0) - 1;
        psVar9 = (short *)0x0;
        if ((param_5 & 0x10) == 0) {
          do {
            do {
              psVar8 = psVar9;
              psVar13 = *(short **)(psVar13 + 8);
              psVar9 = psVar8;
            } while ((int)(*(int *)(psVar13 + 2) - 0x10U) <= (int)uVar12);
            psVar9 = psVar13;
            uVar12 = *(int *)(psVar13 + 2) - 0x10U;
          } while (*psVar13 != 0x4253);
        }
        else {
          do {
            do {
              psVar8 = psVar9;
              psVar13 = *(short **)(psVar13 + 10);
              psVar9 = psVar8;
            } while ((int)(*(int *)(psVar13 + 2) - 0x10U) <= (int)uVar12);
            psVar9 = psVar13;
            uVar12 = *(int *)(psVar13 + 2) - 0x10U;
          } while (*psVar13 != 0x4253);
        }
      }
      if (psVar8 == (short *)0x0) {
        if (DAT_006f7794 != (code *)0x0) {
          local_1c = (*DAT_006f7794)(param_1,param_2,param_5);
        }
      }
      else {
        iVar11 = *(int *)(psVar8 + 10);
        iVar5 = *(int *)(psVar8 + 8);
        iVar6 = *(int *)(psVar8 + 2);
        psVar13 = (short *)0x0;
        *(int *)(iVar11 + 0x10) = iVar5;
        *(int *)(iVar5 + 0x14) = iVar11;
        *(byte *)((int)psVar8 + 3) = *(byte *)((int)psVar8 + 3) & 0xbf;
        iVar5 = *(int *)(psVar8 + 4);
        *psVar8 = 0x424f;
        if ((param_5 & 0x10) == 0) {
          iVar11 = ((int)psVar8 + param_4 + iVar4 + 0xf & ~local_28) - param_4;
        }
        else {
          iVar11 = ((int)psVar8 + param_4 + (iVar6 - local_24) & ~local_28) - param_4;
          psVar13 = psVar8;
        }
        iVar4 = iVar11 + -0x10;
        *(undefined4 *)(iVar11 + -4) = *(undefined4 *)(psVar8 + 6);
        *(int *)(iVar11 + -8) = iVar5;
        if (iVar3 + 0x2f < iVar6 - iVar1) {
          if ((param_5 & 0x10) == 0) {
            puVar14 = (undefined2 *)(local_24 + (iVar3 - 1U) + iVar11 & ~(iVar3 - 1U));
            *(undefined2 **)(iVar5 + 0xc) = puVar14;
            *(int *)(*(int *)(iVar11 + -4) + 8) = iVar4;
            FUN_005aa2c0(puVar14,0,0,0,0,iVar4,*(undefined4 *)(iVar11 + -8));
            puVar7 = (undefined2 *)(iVar2 + 0x10);
            puVar10 = puVar7;
            if ((undefined2 *)
                (((uint)(*(int *)(iVar2 + 0x24) - *(int *)(iVar2 + 0x20)) >> 1) +
                *(int *)(iVar2 + 0x20)) < puVar14) {
              do {
                puVar7 = *(undefined2 **)(puVar7 + 10);
              } while (puVar14 < puVar7);
              puVar10 = *(undefined2 **)(puVar7 + 8);
            }
            else {
              do {
                puVar10 = *(undefined2 **)(puVar10 + 8);
              } while (puVar10 < puVar14);
              puVar7 = *(undefined2 **)(puVar10 + 10);
            }
            *(undefined2 **)(puVar14 + 8) = puVar10;
            *(undefined2 **)(puVar14 + 10) = puVar7;
            *(int *)(puVar14 + 2) = *(int *)(puVar14 + 4) - (int)puVar14;
            *(undefined2 **)(puVar7 + 8) = puVar14;
            *(undefined2 **)(puVar10 + 10) = puVar14;
            *(byte *)((int)puVar14 + 3) = *(byte *)((int)puVar14 + 3) | 0x40;
            *puVar14 = 0x4246;
            *(undefined2 **)(iVar11 + -8) = puVar14;
          }
          else {
            *(int *)(*(int *)(psVar13 + 4) + 0xc) = iVar4;
            *(undefined4 *)(iVar11 + -8) = *(undefined4 *)(psVar13 + 4);
            *(short **)(iVar11 + -4) = psVar13;
            FUN_005aa2c0(psVar13,0,0,0,0,*(undefined4 *)(psVar13 + 6),iVar4);
            psVar8 = (short *)(iVar2 + 0x10);
            psVar9 = psVar8;
            if ((short *)(((uint)(*(int *)(iVar2 + 0x24) - *(int *)(iVar2 + 0x20)) >> 1) +
                         *(int *)(iVar2 + 0x20)) < psVar13) {
              do {
                psVar8 = *(short **)(psVar8 + 10);
              } while (psVar13 < psVar8);
              psVar9 = *(short **)(psVar8 + 8);
            }
            else {
              do {
                psVar9 = *(short **)(psVar9 + 8);
              } while (psVar9 < psVar13);
              psVar8 = *(short **)(psVar9 + 10);
            }
            *(short **)(psVar13 + 8) = psVar9;
            *(short **)(psVar13 + 10) = psVar8;
            *(int *)(psVar13 + 2) = *(int *)(psVar13 + 4) - (int)psVar13;
            *(short **)(psVar8 + 8) = psVar13;
            *(short **)(psVar9 + 10) = psVar13;
            *(byte *)((int)psVar13 + 3) = *(byte *)((int)psVar13 + 3) | 0x40;
            *psVar13 = 0x4246;
          }
        }
        else {
          *(int *)(iVar5 + 0xc) = iVar4;
          *(int *)(*(int *)(iVar11 + -4) + 8) = iVar4;
        }
        param_5 = param_5 | *(uint *)(iVar2 + 0x34) & 0x700;
        if (param_1 == 0) {
          param_5 = param_5 & 0xfffffeff;
        }
        FUN_005aa2c0(iVar4,param_1,param_2,*(undefined4 *)(iVar2 + 0x30),param_5,
                     *(undefined4 *)(iVar11 + -4),*(undefined4 *)(iVar11 + -8));
      }
      if (*(int *)(iVar2 + 0x38) != 0) {
        FUN_005b6830(*(int *)(iVar2 + 0x38));
      }
    } while (local_1c == 1);
    return iVar11;
  }
  return 0;
}

