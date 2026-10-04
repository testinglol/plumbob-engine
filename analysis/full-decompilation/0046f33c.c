
int * __thiscall FUN_0046f33c(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    puVar7 = (undefined4 *)*param_2;
    uVar4 = iVar2 - (int)puVar7 >> 2;
    if ((uint)(param_1[2] - *param_1 >> 2) < uVar4) {
      iVar2 = FUN_0046f44b(uVar4,puVar7,iVar2);
      iVar3 = param_1[2] - *param_1 >> 2;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 << 2);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar4 * 4;
    }
    else {
      uVar5 = param_1[1] - *param_1 >> 2;
      if (uVar5 < uVar4) {
        puVar6 = (undefined4 *)*param_1;
        iVar2 = (int)(uVar5 << 2) >> 2;
        if (0 < iVar2) {
          do {
            uVar1 = *puVar7;
            puVar7 = puVar7 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        puVar6 = (undefined4 *)param_1[1];
        puVar7 = (undefined4 *)(*param_2 + ((int)puVar6 - *param_1 >> 2) * 4);
        iVar2 = param_2[1] - (int)puVar7 >> 2;
        if (0 < iVar2) {
          do {
            uVar1 = *puVar7;
            puVar7 = puVar7 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
      else {
        puVar6 = (undefined4 *)*param_1;
        iVar2 = iVar2 - (int)puVar7 >> 2;
        if (0 < iVar2) {
          do {
            uVar1 = *puVar7;
            puVar7 = puVar7 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
    }
    param_1[1] = *param_1 + uVar4 * 4;
  }
  return param_1;
}

