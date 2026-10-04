
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0048329c(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  float local_8;
  
  if (param_3 < 0) {
    piVar4 = (int *)0x0;
    piVar7 = (int *)((param_1[1] - *param_1 >> 3) + -3);
  }
  else if (param_3 == 0) {
    piVar4 = (int *)0x0;
    piVar7 = (int *)0x0;
  }
  else {
    piVar4 = param_2;
    if (0 < param_3) {
      piVar4 = (int *)(param_3 + -1);
    }
    piVar7 = piVar4;
    if ((int)piVar4 < 0) {
      return;
    }
  }
  iVar1 = *param_1;
  piVar6 = (int *)((param_1[1] - iVar1 >> 3) + -3);
  if (((piVar4 <= piVar6) && (-1 < (int)piVar7)) && (piVar7 <= piVar6)) {
    local_14 = param_2[1];
    local_18 = *param_2;
    local_20 = *(int *)(iVar1 + (int)piVar4 * 8);
    local_1c = *(int *)(iVar1 + 4 + (int)piVar4 * 8);
    local_8 = (float)((local_20 - local_18) * (local_20 - local_18) +
                     (local_1c - local_14) * (local_1c - local_14));
    local_c = param_1;
    for (; (int)piVar4 <= (int)piVar7; piVar4 = (int *)((int)piVar4 + 1)) {
      iVar5 = (int)piVar4 * 8;
      iVar1 = *local_c;
      local_28 = *(int *)(iVar5 + iVar1);
      local_24 = *(int *)(iVar5 + 4 + iVar1);
      local_30 = *(int *)(iVar5 + 8 + iVar1);
      local_2c = *(int *)(iVar5 + 0xc + iVar1);
      fVar3 = (float)(local_24 - local_2c);
      fVar2 = (float)(local_28 - local_30);
      local_10 = local_14 - local_2c;
      fVar2 = ((float)local_10 * fVar3 + (float)(local_18 - local_30) * fVar2) /
              (fVar3 * fVar3 + fVar2 * fVar2);
      if (_DAT_0066657c <= fVar2) {
        if (_DAT_00666748 < fVar2) {
          fVar2 = 1.0;
        }
      }
      else {
        fVar2 = 0.0;
      }
      FUN_0045eecb(&local_30,&local_28,fVar2);
      fVar2 = (float)((local_38 - local_18) * (local_38 - local_18) +
                     (local_34 - local_14) * (local_34 - local_14));
      if (fVar2 < local_8) {
        local_20 = local_38;
        local_1c = local_34;
        local_8 = fVar2;
      }
    }
    *param_2 = local_20;
    param_2[1] = local_1c;
  }
  return;
}

