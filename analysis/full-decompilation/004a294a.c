
int * __thiscall FUN_004a294a(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  if (param_2 != param_1) {
    iVar1 = param_2[1];
    puVar4 = (undefined4 *)*param_2;
    puVar5 = (undefined4 *)*param_1;
    uVar6 = iVar1 - (int)puVar4 >> 3;
    if ((uint)(param_1[2] - (int)puVar5 >> 3) < uVar6) {
      iVar1 = FUN_004a2c29(uVar6,puVar4,iVar1);
      iVar2 = param_1[2] - *param_1 >> 3;
      if (iVar2 != 0) {
        FUN_0040189d(*param_1,iVar2 << 3);
      }
      *param_1 = iVar1;
      param_1[2] = iVar1 + uVar6 * 8;
    }
    else {
      uVar3 = param_1[1] - (int)puVar5 >> 3;
      if (uVar3 < uVar6) {
        iVar1 = (int)(uVar3 << 3) >> 3;
        if (0 < iVar1) {
          do {
            *puVar5 = *puVar4;
            puVar5[1] = puVar4[1];
            puVar5 = puVar5 + 2;
            iVar1 = iVar1 + -1;
            puVar4 = puVar4 + 2;
          } while (iVar1 != 0);
        }
        FUN_00424217(*param_2 + (param_1[1] - *param_1 >> 3) * 8,param_2[1],param_1[1],param_2);
      }
      else {
        iVar1 = iVar1 - (int)puVar4 >> 3;
        if (0 < iVar1) {
          do {
            *puVar5 = *puVar4;
            puVar5[1] = puVar4[1];
            puVar5 = puVar5 + 2;
            iVar1 = iVar1 + -1;
            puVar4 = puVar4 + 2;
          } while (iVar1 != 0);
        }
      }
    }
    param_1[1] = *param_1 + uVar6 * 8;
  }
  return param_1;
}

