
undefined4 __fastcall FUN_00633851(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint local_8;
  
  local_8 = *(uint *)(param_1 + 0x50);
  uVar9 = 1;
  if (1 < (int)local_8) {
    uVar9 = local_8;
  }
  uVar6 = *(uint *)(param_1 + 0x14);
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < uVar6) {
    iVar3 = uVar6 - uVar1;
  }
  else {
    iVar3 = 0;
  }
  if ((int)local_8 <= (int)(iVar3 + uVar9)) {
    if ((int)local_8 < 2) {
      local_8 = 1;
    }
    if (uVar1 < uVar6) {
      iVar3 = uVar6 - uVar1;
    }
    else {
      iVar3 = 0;
    }
    local_8 = iVar3 + local_8;
  }
  iVar3 = 0;
  if (*(code **)(param_1 + 0x5c) == (code *)0x0) {
    pvVar4 = operator_new(local_8);
  }
  else {
    pvVar4 = (void *)(**(code **)(param_1 + 0x5c))();
  }
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar9 = *(uint *)(param_1 + 0x14);
    uVar6 = *(uint *)(param_1 + 0x10);
    if (uVar6 < uVar9) {
      iVar8 = uVar9 - uVar6;
    }
    else {
      iVar8 = 0;
    }
    if (iVar8 != 0) {
      if (uVar6 < uVar9) {
        iVar3 = uVar9 - uVar6;
      }
      else {
        iVar3 = 0;
      }
      FUN_00636510(pvVar4,uVar6,iVar3);
      uVar6 = *(uint *)(param_1 + 0x10);
      iVar3 = (int)pvVar4 - uVar6;
    }
    if (*(code **)(param_1 + 0x60) == (code *)0x0) {
      FUN_006321f0(uVar6);
    }
    else {
      (**(code **)(param_1 + 0x60))();
    }
    FUN_006345ae(pvVar4,local_8 + (int)pvVar4,0);
    if ((iVar3 != 0) && (*(int *)(param_1 + 0x2c) != 0)) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + iVar3;
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + iVar3;
      *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + iVar3;
    }
    if (*(int *)(param_1 + 0x20) != 0) {
      iVar8 = *(int *)(param_1 + 0x18);
      iVar2 = *(int *)(param_1 + 0x1c);
      iVar7 = *(int *)(param_1 + 0x20) + iVar3;
      iVar3 = iVar8 + iVar3;
      *(int *)(param_1 + 0x20) = iVar7;
      *(int *)(param_1 + 0x18) = iVar3;
      *(int *)(param_1 + 0x1c) = iVar3;
      if (iVar7 != 0) {
        *(int *)(param_1 + 0x1c) = (iVar3 - iVar8) + iVar2;
      }
    }
    uVar5 = 1;
  }
  return uVar5;
}

