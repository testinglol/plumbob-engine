
undefined4 __thiscall FUN_005d6516(int param_1,char *param_2,int *param_3,char param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  size_t sVar5;
  undefined **ppuVar6;
  uint uVar7;
  undefined4 uVar8;
  uint local_c;
  int local_8;
  
  if (DAT_006fe8c8 == '\0') {
LAB_005d6552:
    local_c = 0;
    if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 0) {
      local_8 = 0;
      do {
        piVar4 = (int *)(*(int *)(param_1 + 4) + local_8);
        uVar7 = 1;
        if ((1 < (uint)(piVar4[1] - *piVar4)) && (pcVar2 = (char *)*piVar4, *pcVar2 == '-')) {
          if (param_3 == (int *)0x0) {
            iVar3 = _strcmp(pcVar2 + 1,param_2);
            if (iVar3 == 0) {
              return 1;
            }
          }
          else if (1 < (uint)(piVar4[1] - (int)pcVar2)) {
            do {
              if (pcVar2[uVar7] == ':') {
                if (uVar7 != 0xffffffff) {
                  sVar5 = _strlen(param_2);
                  if ((sVar5 == uVar7 - 1) &&
                     (iVar3 = _strncmp((char *)(*(int *)(local_8 + *(int *)(param_1 + 4)) + 1),
                                       param_2,uVar7 - 1), iVar3 == 0)) {
                    piVar4 = (int *)(*(int *)(param_1 + 4) + local_c * 0xc);
                    if ((int)uVar7 < (piVar4[1] - *piVar4) + -1) {
                      pcVar2 = (char *)(*piVar4 + 1 + uVar7);
                      sVar5 = _strlen(pcVar2);
                      FUN_00431779(pcVar2,pcVar2 + sVar5);
                      if (param_4 == '\0') {
                        return 1;
                      }
                      if ((char *)param_3[1] == (char *)*param_3) {
                        return 1;
                      }
                      cVar1 = *(char *)*param_3;
                      if ((cVar1 != '\"') && (cVar1 != '\'')) {
                        return 1;
                      }
                      cVar1 = ((char *)param_3[1])[-1];
                      if ((cVar1 != '\"') && (cVar1 != '\'')) {
                        return 1;
                      }
                      FUN_00406466(0,1);
                      iVar3 = (param_3[1] - *param_3) + -1;
                      uVar8 = 1;
                    }
                    else {
                      iVar3 = 0;
                      uVar8 = DAT_00666580;
                    }
                    FUN_00406466(iVar3,uVar8);
                    return 1;
                  }
                }
                break;
              }
              uVar7 = uVar7 + 1;
            } while (uVar7 < (uint)(piVar4[1] - *piVar4));
          }
        }
        local_c = local_c + 1;
        local_8 = local_8 + 0xc;
      } while (local_c < (uint)((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc));
    }
  }
  else {
    ppuVar6 = &PTR_s_nosound_006d6f24;
    do {
      iVar3 = _strcmp(*ppuVar6,param_2);
      if (iVar3 == 0) goto LAB_005d6552;
      ppuVar6 = ppuVar6 + 1;
    } while (ppuVar6 < &DAT_006d6f9c);
  }
  return 0;
}

