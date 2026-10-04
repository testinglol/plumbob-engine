
void FUN_004ba1dc(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  cVar3 = (**(code **)(*param_1 + 0x20))(0x40);
  if (cVar3 != '\0') {
    cVar3 = (**(code **)(*param_3 + 0x20))(0x40);
    if (cVar3 == '\0') {
      iVar6 = *param_1;
    }
    else {
      cVar3 = (**(code **)(*param_4 + 0x20))(0x40);
      if (cVar3 == '\0') {
        (**(code **)(*param_1 + 0x24))(0x40);
        iVar6 = *param_3;
      }
      else {
        local_20 = *param_2;
        local_1c = param_2[1];
        if (local_20 < 0) {
          local_20 = 0;
        }
        if (local_1c < 0) {
          local_1c = 0;
        }
        local_18 = param_2[2];
        if (param_1[7] < param_2[2]) {
          local_18 = param_1[7];
        }
        local_14 = param_2[3];
        if (param_1[8] < param_2[3]) {
          local_14 = param_1[8];
        }
        (**(code **)(*param_1 + 0xcc))();
        uVar4 = (**(code **)(*param_1 + 0xd0))();
        (**(code **)(*param_3 + 0xcc))();
        uVar5 = (**(code **)(*param_3 + 0xd0))();
        iVar6 = (**(code **)(*param_4 + 0xcc))();
        iVar7 = (**(code **)(*param_4 + 0xd0))();
        iVar1 = param_5[1];
        iVar2 = *param_5;
        iVar6 = iVar6 + iVar1 * iVar7 + iVar2;
        if (*(int *)(DAT_006e486c + 0x34) == 2) {
          FUN_00498830(iVar6,(uVar4 >> 1) * 2,(uVar5 >> 1) * 2,iVar7,(local_18 - local_20) - iVar2,
                       (local_14 - local_1c) - iVar1,param_6);
        }
        else {
          FUN_00498cab(iVar6,(uVar4 >> 1) * 2,(uVar5 >> 1) * 2,iVar7,(local_18 - local_20) - iVar2,
                       (local_14 - local_1c) - iVar1,param_6);
        }
        (**(code **)(*param_3 + 0x24))(0x40);
        (**(code **)(*param_4 + 0x24))(0x40);
        iVar6 = *param_1;
      }
    }
    (**(code **)(iVar6 + 0x24))(0x40);
  }
  return;
}

