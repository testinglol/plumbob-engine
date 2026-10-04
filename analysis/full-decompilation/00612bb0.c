
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00612bb0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,double *param_8)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  double *pdVar4;
  double *pdVar5;
  int iVar6;
  double *pdVar7;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  undefined8 local_28;
  
  local_40 = 0;
  if (0 < param_6) {
    local_38 = 0;
    local_3c = 0;
    do {
      local_50 = 0;
      if (0 < param_5) {
        do {
          local_48 = 0;
          pdVar7 = (double *)&local_28;
          do {
            *(undefined4 *)pdVar7 = 0;
            *(undefined4 *)((int)pdVar7 + 4) = 0;
            local_4c = 0;
            pdVar4 = param_8;
            if (0 < param_7) {
              do {
                iVar6 = 0;
                local_34 = (param_7 + -1) / 2;
                local_30 = (local_4c - local_34) + local_40;
                pdVar5 = pdVar4;
                do {
                  iVar3 = (iVar6 - local_34) + local_50;
                  if (iVar3 < 0) {
                    iVar3 = 0;
                  }
                  if (param_5 <= iVar3) {
                    iVar3 = param_5 + -1;
                  }
                  iVar2 = local_30;
                  if (local_30 < 0) {
                    iVar2 = 0;
                  }
                  if (param_6 <= iVar2) {
                    iVar2 = param_6 + -1;
                  }
                  local_2c = (uint)*(byte *)(local_48 + iVar2 * param_4 + iVar3 * 4 + param_3);
                  pdVar4 = pdVar5 + 1;
                  iVar6 = iVar6 + 1;
                  *pdVar7 = (double)local_2c * *pdVar5 + *pdVar7;
                  pdVar5 = pdVar4;
                } while (iVar6 < param_7);
                local_4c = local_4c + 1;
              } while (local_4c < param_7);
            }
            if (*pdVar7 < _DAT_006669e8) {
              *(undefined4 *)pdVar7 = 0;
              *(undefined4 *)((int)pdVar7 + 4) = 0;
            }
            if (_DAT_006683b0 < *pdVar7) {
              *(undefined4 *)pdVar7 = 0;
              *(undefined4 *)((int)pdVar7 + 4) = 0x406fe000;
            }
            uVar1 = __ftol();
            *(undefined1 *)((int)&local_44 + local_48) = uVar1;
            local_48 = local_48 + 1;
            pdVar7 = pdVar7 + 1;
          } while (local_48 < 4);
          if (local_44._3_1_ < 0xf0) {
            local_44 = *(undefined4 *)(local_3c + local_50 * 4 + param_3);
          }
          *(undefined4 *)(local_38 + local_50 * 4 + param_1) = local_44;
          local_50 = local_50 + 1;
        } while (local_50 < param_5);
      }
      local_3c = local_3c + param_4;
      local_40 = local_40 + 1;
      local_38 = local_38 + param_2;
    } while (local_40 < param_6);
  }
  return;
}

