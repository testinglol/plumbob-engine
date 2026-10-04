
undefined4
FUN_0059f437(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4,int *param_5,
            int *param_6,int *param_7,int *param_8)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined *puVar9;
  char local_814 [1024];
  char local_414 [1028];
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar4 = param_6[1] - *param_6 >> 2;
  cVar2 = FUN_005b90ab(iVar4);
  if (cVar2 != '\0') {
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        cVar2 = FUN_00598bf6(param_2);
        if (cVar2 == '\0') goto LAB_0059f6bf;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar4);
    }
    iVar4 = param_7[1] - *param_7 >> 2;
    cVar2 = FUN_005b90ab(iVar4);
    if (cVar2 != '\0') {
      param_6 = (int *)0x0;
      if (0 < iVar4) {
        do {
          iVar3 = *(int *)(*param_7 + (int)param_6 * 4);
          FUN_0059e426(iVar3);
          local_8 = 0;
          iVar5 = *(int *)(iVar3 + 0x20) - *(int *)(iVar3 + 0x1c) >> 2;
          if (0 < iVar5) {
            do {
              iVar1 = *(int *)(*(int *)(iVar3 + 0x1c) + local_8 * 4);
              local_c = *(int *)(iVar1 + 0x1c);
              if (local_c != 0) {
                if ((param_5[1] == *param_5) || (*(char *)(param_5[1] + -1) != '\\')) {
                  uVar8 = *(undefined4 *)(iVar1 + 0x10);
                  pcVar6 = s__s__s_bmf_006d1d98;
                }
                else {
                  uVar8 = *(undefined4 *)(iVar1 + 0x10);
                  pcVar6 = s__s_s_bmf_006d1da4;
                }
                FUN_00635858(local_414,pcVar6,*param_5,uVar8);
                pcVar6 = local_414;
                FUN_005b8e25(pcVar6);
                cVar2 = FUN_005b960e(pcVar6);
                if (cVar2 != '\0') {
                  pcVar6 = local_414;
                  uVar8 = 1;
                  FUN_005b8e25(pcVar6,1);
                  local_10 = FUN_005b936f(pcVar6,uVar8);
                  FUN_0059ac03(local_10);
                  uVar8 = local_10;
                  FUN_005b8e25(local_10);
                  FUN_005b95c0(uVar8);
                }
              }
              local_8 = local_8 + 1;
            } while (local_8 < iVar5);
          }
          cVar2 = FUN_00595388(param_2);
          if (cVar2 == '\0') goto LAB_0059f6bf;
          param_6 = (int *)((int)param_6 + 1);
        } while ((int)param_6 < iVar4);
      }
      iVar4 = param_8[1] - *param_8 >> 2;
      cVar2 = FUN_005b90ab(iVar4);
      if (cVar2 != '\0') {
        param_6 = (int *)0x0;
        if (0 < iVar4) {
          do {
            iVar3 = *(int *)(*param_8 + (int)param_6 * 4);
            cVar2 = FUN_00597205(param_2);
            if (cVar2 == '\0') goto LAB_0059f6bf;
            if ((param_4[1] == *param_4) || (*(char *)(param_4[1] + -1) != '\\')) {
              uVar8 = *(undefined4 *)(iVar3 + 0x10);
              pcVar6 = s__s__s_cfp_006d1d8c;
            }
            else {
              uVar8 = *(undefined4 *)(iVar3 + 0x10);
              pcVar6 = s__s_s_cfp_006d1d80;
            }
            FUN_00635858(local_414,pcVar6,*param_4,uVar8);
            if ((param_5[1] == *param_5) || (*(char *)(param_5[1] + -1) != '\\')) {
              uVar8 = *(undefined4 *)(iVar3 + 0x10);
              pcVar6 = s__s__s_cfp_006d1d8c;
            }
            else {
              uVar8 = *(undefined4 *)(iVar3 + 0x10);
              pcVar6 = s__s_s_cfp_006d1d80;
            }
            FUN_00635858(local_814,pcVar6,*param_5,uVar8);
            iVar3 = _strcmp(local_414,local_814);
            if (iVar3 != 0) {
              pcVar6 = local_814;
              pcVar7 = local_414;
              FUN_005b8e25(pcVar7,pcVar6);
              cVar2 = FUN_005b9976(pcVar7,pcVar6);
              if (cVar2 == '\0') {
                pcVar6 = local_414;
                puVar9 = &DAT_006c08dc;
                FUN_005bc69b(s_Missing_CFP_file__006d1d6c);
                FUN_005bc69b(pcVar6);
                FUN_005bc69b(puVar9);
              }
            }
            param_6 = (int *)((int)param_6 + 1);
          } while ((int)param_6 < iVar4);
        }
        return 0;
      }
    }
  }
LAB_0059f6bf:
  FUN_004f6cef(*param_1);
  return 0xffffffff;
}

