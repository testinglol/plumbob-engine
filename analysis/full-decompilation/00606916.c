
uint FUN_00606916(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  void *pvVar4;
  void *pvVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  undefined1 local_10 [4];
  undefined4 local_c;
  int local_8;
  
  piVar3 = param_2;
  *param_2 = 0;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x12);
  uVar2 = *(undefined4 *)(param_1 + 0x16);
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = uVar1;
  param_3[3] = uVar2;
  pvVar4 = *(void **)(param_1 + 0x2e);
  local_c = 0;
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)(1 << ((char)*(undefined2 *)(param_1 + 0x1c) *
                            (char)*(undefined2 *)(param_1 + 0x1a) & 0x1fU));
  }
  if (pvVar4 < (void *)0x101) {
    pvVar5 = operator_new((int)pvVar4 << 2);
    *param_2 = (int)pvVar5;
    param_1 = param_1 + 0x36;
  }
  else {
    param_1 = 0;
    pvVar5 = pvVar4;
  }
  if (*param_2 == 0) {
    uVar6 = (uint)pvVar5 & 0xffffff00;
  }
  else {
    piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    puVar8 = (undefined4 *)(**(code **)(*piVar7 + 0xc))(local_10);
    pbVar9 = (byte *)*puVar8;
    *(undefined4 *)(local_8 + 0x28) = 0xffffffff;
    if (param_1 != 0) {
      if (pbVar9 == (byte *)0x5) {
        param_2 = (void *)0x0;
        if (pvVar4 != (void *)0x0) {
          pbVar9 = (byte *)(param_1 + 1);
          do {
            *(uint *)(pbVar9 + *piVar3 + (-1 - param_1)) =
                 ((pbVar9[1] & 0xfff8) << 5 | *pbVar9 & 0xfff8) << 2 | (uint)(pbVar9[-1] >> 3);
            if (*(int *)(pbVar9 + *piVar3 + (-1 - param_1)) == 0x7c1f) {
              *(int **)(local_8 + 0x28) = param_2;
            }
            param_2 = (int *)((int)param_2 + 1);
            pbVar9 = pbVar9 + 4;
          } while (param_2 < pvVar4);
        }
      }
      else {
        param_2 = (void *)0x0;
        if (pvVar4 != (void *)0x0) {
          pbVar9 = (byte *)(param_1 + 1);
          do {
            *(uint *)(pbVar9 + *piVar3 + (-1 - param_1)) =
                 ((pbVar9[1] & 0xf8) << 5 | *pbVar9 & 0xfffc) << 3 | (uint)(pbVar9[-1] >> 3);
            if (*(int *)(pbVar9 + *piVar3 + (-1 - param_1)) == 0xf81f) {
              *(int **)(local_8 + 0x28) = param_2;
            }
            param_2 = (int *)((int)param_2 + 1);
            pbVar9 = pbVar9 + 4;
          } while (param_2 < pvVar4);
        }
      }
    }
    uVar6 = CONCAT31((int3)((uint)pbVar9 >> 8),1);
  }
  return uVar6;
}

