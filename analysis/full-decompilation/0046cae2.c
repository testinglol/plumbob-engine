
int * __thiscall FUN_0046cae2(int *param_1,int *param_2)

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
    uVar1 = (iVar2 - (int)puVar6) / 0x3c;
    if ((uint)((param_1[2] - *param_1) / 0x3c) < uVar1) {
      iVar2 = FUN_0046cc43(uVar1,puVar6,iVar2);
      iVar3 = (param_1[2] - *param_1) / 0x3c;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 * 0x3c);
      }
      *param_1 = iVar2;
      param_1[2] = uVar1 * 0x3c + iVar2;
    }
    else {
      uVar4 = (param_1[1] - *param_1) / 0x3c;
      if (uVar4 < uVar1) {
        iVar3 = ((int)(puVar6 + uVar4 * 0xf) - (int)puVar6) / 0x3c;
        if (0 < iVar3) {
          puVar7 = puVar6;
          puVar8 = (undefined4 *)*param_1;
          for (uVar5 = (uint)(iVar3 * 0x3c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        }
        FUN_0046cd5f(puVar6 + uVar4 * 0xf,iVar2,param_1[1],iVar2);
      }
      else {
        iVar2 = (iVar2 - (int)puVar6) / 0x3c;
        if (0 < iVar2) {
          puVar6 = (undefined4 *)(((int)puVar6 - *param_1) + *param_1);
          puVar7 = (undefined4 *)*param_1;
          for (uVar4 = (uint)(iVar2 * 0x3c) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
        }
      }
    }
    param_1[1] = uVar1 * 0x3c + *param_1;
  }
  return param_1;
}

