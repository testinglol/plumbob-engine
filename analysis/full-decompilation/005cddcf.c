
undefined4 __thiscall FUN_005cddcf(int *param_1,uint *param_2)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  puVar1 = param_2;
  if ((((int)*param_2 < (int)param_2[2]) && ((int)param_2[1] < (int)param_2[3])) &&
     (DAT_006d6184 != 0)) {
    param_2 = (uint *)0x0;
    local_18 = puVar1[1];
    local_10 = puVar1[3];
    local_1c = *puVar1 & 0xfffffffc;
    uVar5 = puVar1[2] + 3 & 0xfffffffc;
    iVar6 = param_1[1] - *param_1 >> 4;
    local_c = iVar6;
    local_14 = uVar5;
    if (iVar6 != 0) {
      local_8 = 0;
      do {
        if (iVar6 <= (int)param_2) break;
        piVar2 = (int *)(local_8 + *param_1);
        if ((int)local_1c < *piVar2) {
LAB_005cde57:
          if (((piVar2[2] <= (int)uVar5) && ((int)local_18 <= piVar2[1])) &&
             (piVar2[3] <= (int)local_10)) {
            FUN_005db3b0(piVar2);
            iVar6 = iVar6 + -1;
            param_2 = (uint *)((int)param_2 + -1);
            local_8 = local_8 + -0x10;
            local_c = iVar6;
            uVar5 = local_14;
          }
        }
        else {
          if ((((int)uVar5 <= piVar2[2]) && (piVar2[1] <= (int)local_18)) &&
             ((int)local_10 <= piVar2[3])) goto LAB_005cdec2;
          if ((int)local_1c <= *piVar2) goto LAB_005cde57;
        }
        param_2 = (uint *)((int)param_2 + 1);
        local_8 = local_8 + 0x10;
      } while (iVar6 != 0);
    }
    piVar2 = param_1 + 4;
    piVar3 = &local_c;
    if (param_1[4] <= iVar6) {
      piVar3 = piVar2;
    }
    iVar6 = *piVar3;
    *(undefined1 *)(param_1 + 3) = 0;
    *piVar2 = iVar6;
    FUN_004b3fea(&local_1c);
    *piVar2 = *piVar2 + 1;
    if (8 < *piVar2) {
      FUN_005cce97();
      *piVar2 = 0;
    }
    uVar4 = 1;
  }
  else {
LAB_005cdec2:
    uVar4 = 0;
  }
  return uVar4;
}

