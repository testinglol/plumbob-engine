
int * __thiscall FUN_005202fc(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    puVar7 = (undefined4 *)*param_1;
    puVar5 = (undefined4 *)*param_2;
    uVar6 = iVar2 - (int)puVar5 >> 2;
    if ((uint)(param_1[2] - (int)puVar7 >> 2) < uVar6) {
      iVar2 = FUN_005207f3(uVar6,puVar5,iVar2);
      iVar3 = param_1[2] - *param_1 >> 2;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 << 2);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar6 * 4;
    }
    else {
      uVar4 = param_1[1] - (int)puVar7 >> 2;
      if (uVar4 < uVar6) {
        puVar1 = puVar5 + uVar4;
        iVar3 = (int)puVar1 - (int)puVar5 >> 2;
        if (0 < iVar3) {
          for (; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        FUN_00520ae5(puVar1,iVar2,param_1[1],uVar6);
      }
      else {
        iVar2 = iVar2 - (int)puVar5 >> 2;
        if (0 < iVar2) {
          for (; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
        }
      }
    }
    param_1[1] = *param_1 + uVar6 * 4;
  }
  return param_1;
}

