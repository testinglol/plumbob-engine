
undefined4 __fastcall FUN_0052ae49(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((param_1[0x35] != 0) && (param_1[0x17] != 0)) {
    iVar3 = FUN_004ed9c4();
    cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar2 != '\0') {
      local_40 = param_1[7];
      local_3c = param_1[8];
      local_38 = param_1[9];
      local_34 = param_1[10];
      iVar5 = param_1[0x35];
      local_50 = *(undefined4 *)(iVar5 + 0x14);
      local_4c = *(undefined4 *)(iVar5 + 0x18);
      local_48 = *(undefined4 *)(iVar5 + 0x1c);
      local_44 = *(undefined4 *)(iVar5 + 0x20);
      (**(code **)(*(int *)param_1[0x17] + 0x9c))(iVar5,&local_50,&local_40,0);
      if (iVar3 == 0) {
        (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
        piVar1 = DAT_006f2abc;
        iVar3 = *DAT_006f2abc;
        uVar4 = FUN_004096c2(param_1[0x47] - param_1[0x46]);
        iVar5 = (**(code **)(iVar3 + 0x68))(uVar4);
        iVar3 = (**(code **)(*piVar1 + 0x58))();
        local_8 = (param_1[0x4a] - iVar3 / 2) + param_1[8];
        iVar3 = *piVar1;
        local_c = (param_1[0x49] - iVar5 / 2) + param_1[7];
        local_10 = param_1[0x17];
        uVar4 = FUN_005d49d6(0,0,0);
        uVar4 = FUN_004096c2(uVar4);
        (**(code **)(iVar3 + 0x78))(local_10,local_c,local_8,uVar4);
      }
      else {
        local_30 = *(int *)(iVar3 + 0x14);
        local_28 = *(int *)(iVar3 + 0x1c);
        local_2c = *(int *)(iVar3 + 0x18);
        local_24 = *(int *)(iVar3 + 0x20);
        local_20 = local_30;
        local_1c = local_2c;
        local_18 = local_28;
        local_14 = local_24;
        FUN_004ba5ac(param_1 + 7);
        iVar5 = param_1[0x4a] - (local_24 - local_2c) / 2;
        local_1c = local_1c + iVar5;
        local_14 = local_14 + iVar5;
        iVar5 = param_1[0x49] - (local_28 - local_30) / 2;
        local_20 = local_20 + iVar5;
        local_18 = local_18 + iVar5;
        (**(code **)(*(int *)param_1[0x17] + 0x9c))(iVar3,&local_30,&local_20,0);
        (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
      }
    }
  }
  (**(code **)(*param_1 + 0x168))();
  return 1;
}

