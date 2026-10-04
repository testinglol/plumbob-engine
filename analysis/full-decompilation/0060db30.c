
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0060db30(int param_1,uint param_2,int param_3)

{
  double dVar1;
  double dVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  int local_28;
  int local_24;
  int local_20;
  
  if (param_1 == 0) {
    return 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
    local_28 = 0;
  }
  else {
    if (param_3 < 0x801) {
      if (param_3 < 0x401) {
        local_28 = param_3;
        goto LAB_0060db84;
      }
    }
    else {
      param_3 = 0x800;
    }
    local_28 = param_3 + -0x400;
  }
LAB_0060db84:
  uVar8 = (param_2 & 0xffff) >> 1;
  local_24 = 0;
  if (uVar8 != 0) {
    puVar6 = (undefined2 *)(param_1 + uVar8 * 2);
    dVar1 = ((double)(param_2 >> 1 & 0x7fff) - _DAT_00667280) * _DAT_00667270;
    puVar5 = puVar6;
    do {
      puVar5 = puVar5 + -1;
      dVar2 = (double)local_24 / dVar1;
      if ((param_3 < 0) || (0x400 < param_3)) {
        local_20 = 0x400;
        if (_DAT_00667280 < dVar2) {
          local_20 = 0;
        }
        iVar4 = __ftol();
      }
      else {
        FUN_0060dd40(dVar2,0xef6b5d46,0x3fd55553,0xef6b5d46,0x3fd55553);
        iVar4 = __ftol();
        local_20 = __ftol();
      }
      iVar4 = (0x400 - local_28) * iVar4 + local_28 * local_20;
      uVar3 = (undefined2)((int)(iVar4 + (iVar4 >> 0x1f & 0x3ffU)) >> 10);
      *puVar6 = uVar3;
      *puVar5 = uVar3;
      local_24 = local_24 + 1;
      puVar6 = puVar6 + 1;
    } while (local_24 < (int)uVar8);
  }
  if ((param_3 < 0) || (0x400 < param_3)) {
    iVar4 = 0x400;
    iVar7 = 0x600;
  }
  else {
    iVar4 = 0x600;
    iVar7 = 0x800;
  }
  iVar4 = (0x400 - local_28) * iVar7 + local_28 * iVar4;
  return (int)(iVar4 + (iVar4 >> 0x1f & 0x3ffU)) >> 10;
}

