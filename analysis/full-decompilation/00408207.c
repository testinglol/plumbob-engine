
int * __thiscall FUN_00408207(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_8;
  
  if (param_2 != param_1) {
    iVar1 = param_2[1];
    local_8 = (undefined4 *)*param_1;
    puVar4 = (undefined4 *)*param_2;
    uVar5 = iVar1 - (int)puVar4 >> 5;
    if ((uint)(param_1[2] - (int)local_8 >> 5) < uVar5) {
      iVar1 = FUN_004087bc(uVar5,puVar4,iVar1);
      iVar2 = param_1[2] - *param_1 >> 5;
      if (iVar2 != 0) {
        FUN_0040189d(*param_1,iVar2 << 5);
      }
      *param_1 = iVar1;
      param_1[2] = uVar5 * 0x20 + iVar1;
    }
    else {
      uVar3 = param_1[1] - (int)local_8 >> 5;
      if (uVar3 < uVar5) {
        iVar1 = (int)(uVar3 * 0x20) >> 5;
        if (0 < iVar1) {
          do {
            iVar1 = iVar1 + -1;
            puVar6 = puVar4;
            puVar7 = local_8;
            for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar4 = puVar4 + 8;
            local_8 = local_8 + 8;
          } while (iVar1 != 0);
        }
        FUN_005d222e((param_1[1] - *param_1 >> 5) * 0x20 + *param_2,param_2[1],param_1[1],param_2);
      }
      else {
        param_2 = (int *)(iVar1 - (int)puVar4 >> 5);
        if (0 < (int)param_2) {
          do {
            param_2 = (int *)((int)param_2 + -1);
            puVar6 = puVar4;
            puVar7 = local_8;
            for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
              *puVar7 = *puVar6;
              puVar6 = puVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar4 = puVar4 + 8;
            local_8 = local_8 + 8;
          } while (param_2 != (int *)0x0);
        }
      }
    }
    param_1[1] = uVar5 * 0x20 + *param_1;
  }
  return param_1;
}

