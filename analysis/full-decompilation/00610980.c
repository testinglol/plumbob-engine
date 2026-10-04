
undefined4 FUN_00610980(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  undefined4 local_3c;
  int local_34;
  int local_30;
  int local_28;
  int local_24;
  double local_10;
  
  local_3c = 0;
  local_10 = 195075.0;
  if (0 < param_5) {
    local_24 = param_4 + param_5;
    iVar5 = (param_3 - param_5) + -1;
    iVar8 = param_3 + -1 + param_5;
    local_30 = param_5;
    iVar4 = param_4 - param_5;
    do {
      local_28 = iVar4 + 1;
      local_30 = local_30 + -1;
      iVar7 = (1 - param_3) + iVar5;
      if (iVar7 <= param_5) {
        local_34 = (param_5 - iVar7) + 1;
        iVar6 = iVar5;
        do {
          if ((((-1 < iVar6) && (iVar3 = (param_4 - param_3) + iVar8, -1 < iVar3)) &&
              (iVar1 = *param_1, iVar6 < *(int *)(iVar1 + 0x10))) &&
             (iVar3 < *(int *)(iVar1 + 0x14))) {
            iVar3 = (iVar6 + 1) * *(int *)(iVar1 + 0x18);
            uVar2 = *(undefined4 *)
                     (((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) + param_1[2] * local_24 +
                     param_1[1]);
            fVar9 = (float10)FUN_00610c90(param_2,uVar2);
            if (fVar9 < (float10)local_10) {
              local_10 = (double)fVar9;
              local_3c = uVar2;
            }
          }
          iVar6 = iVar6 + 1;
          local_34 = local_34 + -1;
        } while (local_34 != 0);
        if (iVar7 <= param_5) {
          local_34 = (param_5 - iVar7) + 1;
          iVar7 = iVar5;
          do {
            if (((-1 < iVar7) && (iVar6 = (param_4 - param_3) + iVar5, -1 < iVar6)) &&
               ((iVar3 = *param_1, iVar7 < *(int *)(iVar3 + 0x10) &&
                (iVar6 < *(int *)(iVar3 + 0x14))))) {
              iVar6 = (iVar7 + 1) * *(int *)(iVar3 + 0x18);
              uVar2 = *(undefined4 *)
                       (((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3) + iVar4 * param_1[2] + param_1[1]
                       );
              fVar9 = (float10)FUN_00610c90(param_2,uVar2);
              if (fVar9 < (float10)local_10) {
                local_10 = (double)fVar9;
                local_3c = uVar2;
              }
            }
            iVar7 = iVar7 + 1;
            local_34 = local_34 + -1;
          } while (local_34 != 0);
        }
      }
      iVar4 = (2 - param_3) + iVar5;
      iVar6 = local_28;
      for (iVar7 = iVar4; iVar3 = local_28, iVar7 <= local_30; iVar7 = iVar7 + 1) {
        if (((-1 < iVar5) && (iVar3 = iVar7 + -1 + param_4, -1 < iVar3)) &&
           ((iVar1 = *param_1, iVar5 < *(int *)(iVar1 + 0x10) && (iVar3 < *(int *)(iVar1 + 0x14)))))
        {
          iVar3 = (iVar5 + 1) * *(int *)(iVar1 + 0x18);
          uVar2 = *(undefined4 *)
                   (((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3) + param_1[2] * iVar6 + param_1[1]);
          fVar9 = (float10)FUN_00610c90(param_2,uVar2);
          if (fVar9 < (float10)local_10) {
            local_10 = (double)fVar9;
            local_3c = uVar2;
          }
        }
        iVar6 = iVar6 + 1;
      }
      for (; iVar4 <= local_30; iVar4 = iVar4 + 1) {
        if ((((-1 < iVar8) && (iVar7 = iVar4 + -1 + param_4, -1 < iVar7)) &&
            (iVar6 = *param_1, iVar8 < *(int *)(iVar6 + 0x10))) && (iVar7 < *(int *)(iVar6 + 0x14)))
        {
          iVar7 = (iVar8 + 1) * *(int *)(iVar6 + 0x18);
          uVar2 = *(undefined4 *)
                   (((int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3) + param_1[2] * iVar3 + param_1[1]);
          fVar9 = (float10)FUN_00610c90(param_2,uVar2);
          if (fVar9 < (float10)local_10) {
            local_10 = (double)fVar9;
            local_3c = uVar2;
          }
        }
        iVar3 = iVar3 + 1;
      }
      param_5 = param_5 + -1;
      local_24 = local_24 + -1;
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + -1;
      iVar4 = local_28;
    } while (0 < param_5);
  }
  return local_3c;
}

