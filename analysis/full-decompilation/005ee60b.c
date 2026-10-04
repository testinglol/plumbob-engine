
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005ee60b(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar8 = (**(code **)(*(int *)param_1[0x4a] + 0x1c))();
  (**(code **)(*(int *)param_1[0x4a] + 0x20))(0xffffff);
  if (param_1[0x14] != param_1[0x13]) {
    iVar2 = param_1[0x61];
    iVar3 = param_1[0x62];
    iVar4 = param_1[7];
    iVar5 = param_1[8];
    iVar6 = param_1[0x17];
    iVar7 = *(int *)param_1[0x4a];
    uVar9 = FUN_005d49d6(0,0,0);
    uVar9 = FUN_004096c2(uVar9);
    (**(code **)(iVar7 + 0x78))(iVar6,iVar2 + iVar4,iVar3 + iVar5,uVar9);
  }
  if (param_1[0x4c] != param_1[0x4b]) {
    iVar2 = param_1[0x5d];
    iVar3 = param_1[0x5e];
    iVar4 = param_1[7];
    iVar5 = param_1[8];
    iVar6 = param_1[0x17];
    iVar7 = *(int *)param_1[0x4a];
    uVar9 = FUN_005d49d6(0,0,0);
    uVar9 = FUN_004096c2(uVar9);
    (**(code **)(iVar7 + 0x78))(iVar6,iVar2 + iVar4,iVar3 + iVar5,uVar9);
  }
  if ((uint)param_1[0x57] <= DAT_006e5490) {
    piVar1 = param_1 + 0x69;
    if ((param_1[0x6a] - *piVar1) / 0xc != 0) {
      FUN_005d499c(param_1 + 0x13);
      (**(code **)(*param_1 + 0x9c))(*piVar1);
      FUN_0052a419(*piVar1,*piVar1 + 0xc);
      FUN_004734bd(0x3f800000,0,1000,DAT_006e5490);
      FUN_004734bd(0,_DAT_00666c18,1000,DAT_006e5490);
    }
  }
  (**(code **)(*(int *)param_1[0x4a] + 0x20))(uVar8);
  return;
}

