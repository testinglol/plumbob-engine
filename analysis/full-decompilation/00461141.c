
int * __thiscall FUN_00461141(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  if (param_2 != param_1) {
    iVar1 = param_2[1];
    puVar6 = (undefined4 *)*param_1;
    puVar5 = (undefined4 *)*param_2;
    uVar7 = iVar1 - (int)puVar5 >> 4;
    if ((uint)(param_1[2] - (int)puVar6 >> 4) < uVar7) {
      iVar1 = FUN_0046121b(uVar7,puVar5,iVar1);
      iVar2 = param_1[2] - *param_1 >> 4;
      if (iVar2 != 0) {
        FUN_0040189d(*param_1,iVar2 << 4);
      }
      *param_1 = iVar1;
      param_1[2] = uVar7 * 0x10 + iVar1;
    }
    else {
      uVar3 = param_1[1] - (int)puVar6 >> 4;
      if (uVar3 < uVar7) {
        uVar4 = (int)(puVar5 + uVar3 * 4) - (int)puVar5 >> 4;
        if (0 < (int)uVar4) {
          puVar6 = puVar5;
          puVar8 = (undefined4 *)*param_1;
          for (iVar2 = (uVar4 & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar8 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        FUN_004612c6(puVar5 + uVar3 * 4,iVar1,param_1[1],uVar7);
      }
      else {
        uVar3 = iVar1 - (int)puVar5 >> 4;
        if (0 < (int)uVar3) {
          puVar5 = (undefined4 *)(((int)puVar5 - (int)puVar6) + (int)puVar6);
          for (iVar1 = (uVar3 & 0xfffffff) << 2; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar6 = puVar6 + 1;
          }
        }
      }
    }
    param_1[1] = uVar7 * 0x10 + *param_1;
  }
  return param_1;
}

