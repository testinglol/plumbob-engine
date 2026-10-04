
int * __thiscall FUN_0047204d(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *local_c;
  undefined4 *local_8;
  
  if (param_2 != param_1) {
    iVar3 = param_2[1];
    local_8 = (undefined4 *)*param_2;
    uVar1 = (iVar3 - (int)local_8) / 0xc;
    if ((uint)((param_1[2] - *param_1) / 0xc) < uVar1) {
      iVar2 = FUN_00472198(uVar1,local_8,iVar3);
      iVar3 = param_1[1];
      for (iVar7 = *param_1; iVar7 != iVar3; iVar7 = iVar7 + 0xc) {
        FUN_0042004f();
      }
      iVar3 = (param_1[2] - *param_1) / 0xc;
      if (iVar3 != 0) {
        FUN_0040189d(*param_1,iVar3 * 0xc);
      }
      *param_1 = iVar2;
      param_1[2] = iVar2 + uVar1 * 0xc;
    }
    else {
      uVar4 = (param_1[1] - *param_1) / 0xc;
      if (uVar4 < uVar1) {
        iVar3 = (int)(uVar4 * 0xc) / 0xc;
        local_c = (undefined4 *)*param_1;
        if (0 < iVar3) {
          do {
            *local_c = *local_8;
            local_c[1] = local_8[1];
            iVar3 = iVar3 + -1;
            local_c[2] = local_8[2];
            local_c = local_c + 3;
            local_8 = local_8 + 3;
          } while (iVar3 != 0);
        }
        FUN_004722fb(*param_2 + ((param_1[1] - *param_1) / 0xc) * 0xc,param_2[1],param_1[1],uVar1);
      }
      else {
        puVar6 = (undefined4 *)*param_1;
        iVar3 = (iVar3 - (int)local_8) / 0xc;
        puVar5 = puVar6;
        if (0 < iVar3) {
          do {
            *puVar5 = *local_8;
            puVar6 = puVar5 + 3;
            puVar5[1] = local_8[1];
            iVar3 = iVar3 + -1;
            puVar5[2] = local_8[2];
            puVar5 = puVar6;
            local_8 = local_8 + 3;
          } while (iVar3 != 0);
        }
        puVar5 = (undefined4 *)param_1[1];
        for (; puVar6 != puVar5; puVar6 = puVar6 + 3) {
          FUN_0042004f();
        }
      }
    }
    param_1[1] = *param_1 + uVar1 * 0xc;
  }
  return param_1;
}

