
int * __thiscall FUN_00512efb(int *param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *local_c;
  
  piVar1 = param_2;
  if (param_2 != param_1) {
    iVar3 = param_2[1];
    param_2 = (int *)*param_2;
    uVar2 = (iVar3 - (int)param_2) / 0xc;
    if ((uint)((param_1[2] - *param_1) / 0xc) < uVar2) {
      iVar3 = FUN_00513022(uVar2,param_2,iVar3);
      iVar4 = (param_1[2] - *param_1) / 0xc;
      if (iVar4 != 0) {
        FUN_0040189d(*param_1,iVar4 * 0xc);
      }
      *param_1 = iVar3;
      param_1[2] = iVar3 + uVar2 * 0xc;
    }
    else {
      uVar5 = (param_1[1] - *param_1) / 0xc;
      if (uVar5 < uVar2) {
        iVar3 = (int)(uVar5 * 0xc) / 0xc;
        local_c = (undefined4 *)*param_1;
        if (0 < iVar3) {
          do {
            *local_c = *param_2;
            puVar6 = param_2 + 3;
            local_c[1] = param_2[1];
            iVar3 = iVar3 + -1;
            local_c[2] = param_2[2];
            param_2 = puVar6;
            local_c = local_c + 3;
          } while (iVar3 != 0);
        }
        FUN_005f0ae8(*piVar1 + ((param_1[1] - *param_1) / 0xc) * 0xc,piVar1[1],param_1[1],param_2);
      }
      else {
        iVar3 = (iVar3 - (int)param_2) / 0xc;
        puVar6 = param_2;
        param_2 = (undefined4 *)*param_1;
        if (0 < iVar3) {
          do {
            *param_2 = *puVar6;
            param_2[1] = puVar6[1];
            iVar3 = iVar3 + -1;
            param_2[2] = puVar6[2];
            puVar6 = puVar6 + 3;
            param_2 = param_2 + 3;
          } while (iVar3 != 0);
        }
      }
    }
    param_1[1] = *param_1 + uVar2 * 0xc;
  }
  return param_1;
}

