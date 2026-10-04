
int * __thiscall FUN_0040fb87(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if (param_2 != param_1) {
    iVar2 = param_2[1];
    puVar6 = (undefined4 *)*param_2;
    puVar8 = (undefined4 *)*param_1;
    uVar1 = (iVar2 - (int)puVar6) / 0x14;
    if ((uint)((param_1[2] - (int)puVar8) / 0x14) < uVar1) {
      iVar2 = FUN_0040fd93(uVar1,puVar6,iVar2);
      iVar3 = (param_1[2] - *param_1) / 0x14;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 * 0x14);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar1 * 0x14;
    }
    else {
      uVar4 = (param_1[1] - (int)puVar8) / 0x14;
      if (uVar4 < uVar1) {
        iVar3 = ((int)(puVar6 + uVar4 * 5) - (int)puVar6) / 0x14;
        if (0 < iVar3) {
          puVar7 = puVar6;
          for (uVar5 = iVar3 * 5 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        FUN_0046b0bd(puVar6 + uVar4 * 5,iVar2,param_1[1],uVar1);
      }
      else {
        iVar2 = (iVar2 - (int)puVar6) / 0x14;
        if (0 < iVar2) {
          puVar6 = (undefined4 *)(((int)puVar6 - (int)puVar8) + (int)puVar8);
          for (uVar4 = iVar2 * 5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar8 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar8 = puVar8 + 1;
          }
        }
      }
    }
    param_1[1] = *param_1 + uVar1 * 0x14;
  }
  return param_1;
}

