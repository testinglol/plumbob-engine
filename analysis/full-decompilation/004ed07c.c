
int * __thiscall FUN_004ed07c(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    puVar5 = (undefined4 *)*param_2;
    puVar6 = (undefined4 *)*param_1;
    uVar7 = iVar2 - (int)puVar5 >> 2;
    if ((uint)(param_1[2] - (int)puVar6 >> 2) < uVar7) {
      iVar2 = FUN_004ed148(uVar7,puVar5,iVar2);
      iVar3 = param_1[2] - *param_1 >> 2;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 << 2);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar7 * 4;
    }
    else {
      uVar4 = param_1[1] - (int)puVar6 >> 2;
      if (uVar4 < uVar7) {
        iVar2 = (int)(uVar4 << 2) >> 2;
        if (0 < iVar2) {
          do {
            uVar1 = *puVar5;
            puVar5 = puVar5 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        FUN_00520ae5(*param_2 + (param_1[1] - *param_1 >> 2) * 4,param_2[1],param_1[1],param_2);
      }
      else {
        iVar2 = iVar2 - (int)puVar5 >> 2;
        if (0 < iVar2) {
          do {
            uVar1 = *puVar5;
            puVar5 = puVar5 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
    }
    param_1[1] = *param_1 + uVar7 * 4;
  }
  return param_1;
}

