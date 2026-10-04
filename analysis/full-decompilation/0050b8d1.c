
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0050b8d1(int *param_1,uint param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  DWORD DVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  float local_14;
  int local_10;
  float fStack_c;
  char local_5;
  
  piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  (**(code **)(*piVar2 + 0x24))();
  iVar9 = 0;
  if ((*(int *)(*(int *)(DAT_006e486c + 0x2c) + 4) != 0) ||
     (*(int *)(*(int *)(DAT_006e486c + 0x2c) + 0x504) != 0)) {
    (**(code **)(*param_1 + 0x168))();
    return 0;
  }
  local_5 = (char)param_1[0x53];
  local_14 = (float)FUN_0050ad1f();
  if ((char)param_1[0x53] == '\0') {
    iVar9 = param_1[0x55];
    param_1[0x55] = (int)local_14;
    if ((int)local_14 - iVar9 < 200) {
      FUN_005ecd7f(param_1 + 0x46,param_1);
      FUN_005ecd7f(param_1 + 0x4a,param_1);
      iVar8 = param_1[0x21];
      fStack_c = 0.0;
      local_24 = 0;
      iVar6 = param_1[0x1f];
      local_20 = param_1[0x49];
      local_18 = param_1[0x4d];
      local_10 = (int)local_14 - param_1[0x54];
      local_34 = 0;
      local_1c = iVar8 - iVar6;
      iVar3 = __ftol();
      iVar9 = -iVar3 - param_1[0x56];
      param_1[0x56] = -iVar3;
      local_30 = local_20 + iVar9;
      local_28 = local_18 + iVar9;
      local_2c = iVar8 - iVar6;
      FUN_004a7901();
      local_20 = local_30 + -iVar9;
      local_24 = local_34;
      local_18 = -iVar9 + local_28;
      local_1c = local_2c;
      if (((local_2c <= local_34) || (local_18 <= local_20)) || (local_28 <= local_30)) {
        *(undefined1 *)(param_1 + 0x53) = 1;
        uVar10 = (**(code **)(*param_1 + 0x164))(param_2);
        return uVar10;
      }
      uVar10 = FUN_004b469d();
      uVar4 = FUN_004b469d(uVar10);
      FUN_005cab71(uVar4,uVar10);
    }
    else {
      local_5 = '\x01';
      FUN_005ecd7f(param_1 + 7,param_1);
      fStack_c = 0.0;
      local_10 = (int)local_14 - param_1[0x54];
      iVar8 = __ftol();
      iVar9 = -iVar8 - param_1[0x56];
      param_1[0x56] = -iVar8;
    }
  }
  else {
    FUN_005ecd7f(param_1 + 7,param_1);
  }
  DVar5 = timeGetTime();
  param_1[0x57] = DVar5;
  if ((int *)param_1[0x17] == (int *)0x0) goto LAB_0050bbca;
  iVar8 = *(int *)param_1[0x17];
  if (local_5 == '\0') {
    cVar1 = (**(code **)(iVar8 + 0x20))(1);
    if (cVar1 != '\0') {
      (**(code **)(*(int *)param_1[0x17] + 0x38))(DAT_006f35f8,param_1 + 0x46);
      (**(code **)(*(int *)param_1[0x17] + 0x38))(DAT_006f35f8,param_1 + 0x4a);
      uVar10 = 1;
      iVar8 = *(int *)param_1[0x17];
      goto LAB_0050bb56;
    }
  }
  else {
    cVar1 = (**(code **)(iVar8 + 0x20))(0x10);
    if (cVar1 != '\0') {
      iVar8 = param_1[0x45];
      local_24 = param_1[0x1f];
      local_34 = *(int *)(iVar8 + 0x14);
      local_30 = *(int *)(iVar8 + 0x18);
      local_20 = param_1[0x20];
      local_1c = param_1[0x21];
      local_18 = param_1[0x22];
      local_2c = *(int *)(iVar8 + 0x1c) / 3;
      local_28 = *(int *)(iVar8 + 0x20) / 3;
      (**(code **)(*(int *)param_1[0x17] + 0xc0))(iVar8,&local_34,&local_24,1);
      uVar10 = 0x10;
      iVar8 = *(int *)param_1[0x17];
LAB_0050bb56:
      (**(code **)(iVar8 + 0x24))(uVar10);
    }
  }
  if ((char)param_1[0x53] != '\0') {
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x40);
    if (cVar1 == '\0') {
      DAT_006f35f8 = 0;
    }
    else {
      iVar8 = *(int *)(param_1[0x45] + 0x1c);
      local_28 = *(int *)(param_1[0x45] + 0x20);
      iVar6 = (**(code **)(*(int *)param_1[0x17] + 0xcc))();
      uVar7 = (**(code **)(*(int *)param_1[0x17] + 0xd0))();
      DAT_006f35f8 = (uint)*(ushort *)
                            (iVar6 + ((param_1[8] + local_28) * (uVar7 >> 1) + param_1[7] + iVar8) *
                                     2);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x40);
    }
  }
LAB_0050bbca:
  piVar2 = param_1 + 0x42;
  param_2 = 0;
  if ((param_1[0x43] - *piVar2) / 0x48 != 0) {
    fStack_c = 0.0;
    do {
      if (param_2 < (param_1[0x43] - *piVar2) / 0x48 - 1U) {
        iVar8 = (int)fStack_c + 0x48 + *piVar2;
      }
      else {
        iVar8 = 0;
      }
      cVar1 = FUN_0050adab(param_1[0x17],param_1 + 0x46,iVar8,&local_34,local_14,iVar9);
      if (cVar1 == '\0') {
        FUN_0050be1b((int)fStack_c + *piVar2);
        param_2 = param_2 - 1;
        fStack_c = (float)((int)fStack_c + -0x48);
      }
      param_2 = param_2 + 1;
      fStack_c = (float)((int)fStack_c + 0x48);
    } while (param_2 < (uint)((param_1[0x43] - *piVar2) / 0x48));
  }
  iVar9 = 0;
  local_14 = _DAT_00666748 / (float)(param_1[0x47] - param_1[0x4b]);
  param_2 = 0;
  fStack_c = -((float)param_1[0x4b] * local_14);
  if ((param_1[0x43] - *piVar2) / 0x48 != 0) {
    do {
      FUN_0050ae69(param_1[0x17],(float)*(int *)(iVar9 + 0x14 + *piVar2) * local_14 + fStack_c);
      param_2 = param_2 + 1;
      iVar9 = iVar9 + 0x48;
    } while (param_2 < (uint)((param_1[0x43] - *piVar2) / 0x48));
  }
  if ((param_1[0x43] - *piVar2) / 0x48 == 0) {
    (**(code **)(*param_1 + 300))(1,0);
  }
  (**(code **)(*param_1 + 0x168))();
  *(undefined1 *)(param_1 + 0x53) = 0;
  return 1;
}

