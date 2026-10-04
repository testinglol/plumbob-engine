
void __fastcall FUN_005f74a2(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  size_t sVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int local_18;
  int local_14;
  
  uVar7 = (**(code **)(*(int *)(&DAT_006f2a74)[*(int *)(param_1 + 0x1a4)] + 0x1c))();
  iVar1 = *(int *)(&DAT_006f2a74)[*(int *)(param_1 + 0x1a4)];
  uVar8 = FUN_005e416e(*(undefined4 *)(param_1 + 0xe8));
  (**(code **)(iVar1 + 0x20))(uVar8);
  iVar1 = *(int *)(param_1 + 0x17c);
  local_18 = 0;
  local_14 = 0;
  if (iVar1 != 0) {
    local_18 = *(int *)(iVar1 + *(int *)(param_1 + 0xe8) * 8);
    local_14 = *(int *)(iVar1 + 4 + *(int *)(param_1 + 0xe8) * 8);
  }
  iVar1 = *(int *)(param_1 + 0x1a8);
  if (*(int *)(param_1 + 0x124) - *(int *)(param_1 + 0x11c) < iVar1) {
    iVar1 = *(int *)(param_1 + 0x124);
    iVar2 = *(int *)(param_1 + 0x11c);
    iVar10 = *(int *)(&DAT_006f2a74)[*(int *)(param_1 + 0x1a4)];
    sVar9 = _strlen(&DAT_006c220c);
    iVar10 = (**(code **)(iVar10 + 0x68))(&DAT_006c220c,sVar9);
    uVar8 = (**(code **)(*(int *)(&DAT_006f2a74)[*(int *)(param_1 + 0x1a4)] + 0x60))
                      (*(int *)(param_1 + 0x4c),*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c),
                       (iVar1 - iVar2) - iVar10);
    iVar11 = (**(code **)(*(int *)(&DAT_006f2a74)[*(int *)(param_1 + 0x1a4)] + 0x78))
                       (*(undefined4 *)(param_1 + 0x5c),
                        *(int *)(param_1 + 0x11c) + *(int *)(param_1 + 0x1c) + local_18,
                        *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x120) + local_14,
                        *(undefined4 *)(param_1 + 0x4c),uVar8,0,0,0);
    iVar1 = *(int *)(param_1 + 0x124);
    iVar2 = *(int *)(param_1 + 0x11c);
    uVar13 = 0;
    uVar12 = 0;
    uVar8 = 0;
    iVar10 = *(int *)(&DAT_006f2a74)[*(int *)(param_1 + 0x1a4)];
    sVar9 = _strlen(&DAT_006c220c);
    (**(code **)(iVar10 + 0x78))
              (*(undefined4 *)(param_1 + 0x5c),
               ((iVar1 - iVar2) - iVar11) / 2 + *(int *)(param_1 + 0x11c) + *(int *)(param_1 + 0x1c)
               + local_18,*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x120) + local_14,
               &DAT_006c220c,sVar9,uVar8,uVar12,uVar13);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x120);
    iVar10 = *(int *)(param_1 + 0x20);
    iVar11 = *(int *)(param_1 + 0x124);
    iVar3 = *(int *)(param_1 + 0x11c);
    uVar8 = *(undefined4 *)(param_1 + 0x5c);
    iVar4 = *(int *)(param_1 + 0x1c);
    iVar5 = *(int *)(param_1 + 0x11c);
    iVar6 = *(int *)(&DAT_006f2a74)[*(int *)(param_1 + 0x1a4)];
    uVar12 = FUN_005d49d6(0,0,0);
    uVar12 = FUN_004096c2(uVar12);
    (**(code **)(iVar6 + 0x78))
              (uVar8,((iVar11 - iVar3) - iVar1) / 2 + iVar4 + iVar5 + local_18,
               iVar2 + iVar10 + local_14,uVar12);
  }
  (**(code **)(*(int *)(&DAT_006f2a74)[*(int *)(param_1 + 0x1a4)] + 0x20))(uVar7);
  return;
}

