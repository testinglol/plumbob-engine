
void FUN_004b9ca0(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                 int param_7)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int local_30;
  int local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_7 >> 3 == 0) {
    cVar1 = (**(code **)(*param_1 + 0x20))(0x10);
    if (cVar1 == '\0') {
      return;
    }
    local_14 = param_2[3] - param_2[1];
    local_18 = param_2[2] - *param_2;
    local_20 = 0;
    local_1c = 0;
    FUN_004ba5ac(param_4);
    iVar6 = *param_1;
  }
  else {
    if (param_7 >> 3 != 0x1f) {
      cVar1 = (**(code **)(*param_3 + 0x20))(0x40);
      if (cVar1 == '\0') {
        return;
      }
      cVar1 = (**(code **)(*param_5 + 0x20))(0x40);
      if (cVar1 == '\0') {
        iVar6 = *param_3;
        uVar8 = 0x40;
      }
      else {
        cVar1 = (**(code **)(*param_1 + 0x20))(0x40);
        if (cVar1 == '\0') {
          (**(code **)(*param_3 + 0x24))(0x40);
          iVar6 = *param_5;
          uVar8 = 0x40;
        }
        else {
          local_30 = *param_2;
          local_2c = param_2[1];
          local_18 = *param_4;
          local_14 = param_4[1];
          local_10 = *param_6;
          local_c = param_6[1];
          if (local_30 < 0) {
            local_18 = local_18 - local_30;
            local_10 = local_10 - local_30;
            local_30 = 0;
          }
          if (local_2c < 0) {
            local_14 = local_14 - local_2c;
            local_c = local_c - local_2c;
            local_2c = 0;
          }
          iVar6 = param_2[2];
          if (param_1[7] < param_2[2]) {
            iVar6 = param_1[7];
          }
          iVar7 = param_2[3];
          if (param_1[8] < param_2[3]) {
            iVar7 = param_1[8];
          }
          uVar2 = (**(code **)(*param_3 + 0xd0))();
          uVar2 = uVar2 >> 1;
          uVar3 = (**(code **)(*param_5 + 0xd0))();
          uVar3 = uVar3 >> 1;
          uVar4 = (**(code **)(*param_1 + 0xd0))();
          local_8 = (**(code **)(*param_3 + 0xcc))();
          local_8 = local_8 + uVar2 * local_14 * 2;
          iVar5 = (**(code **)(*param_5 + 0xcc))();
          iVar5 = iVar5 + uVar3 * local_c * 2;
          (**(code **)(*param_1 + 0xcc))();
          if (((uint)param_3[10] >> 1 & 1) == 0) {
            FUN_00499327(iVar5 + local_10 * 2,(uVar4 >> 1) * 2,uVar2 * 2,uVar3 * 2,iVar6 - local_30,
                         iVar7 - local_2c,param_7);
          }
          else {
            FUN_00499848(iVar5 + local_10 * 2,(uVar4 >> 1) * 2,uVar2 * 2,uVar3 * 2,iVar6 - local_30,
                         iVar7 - local_2c,param_7,param_3[9]);
          }
          (**(code **)(*param_3 + 0x24))(0x40);
          (**(code **)(*param_5 + 0x24))(0x40);
          uVar8 = 0x40;
          iVar6 = *param_1;
        }
      }
      goto LAB_004b9f36;
    }
    cVar1 = (**(code **)(*param_1 + 0x20))(0x10);
    if (cVar1 == '\0') {
      return;
    }
    local_14 = param_2[3] - param_2[1];
    local_18 = param_2[2] - *param_2;
    local_20 = 0;
    local_1c = 0;
    FUN_004ba5ac(param_6);
    iVar6 = *param_1;
    param_3 = param_5;
  }
  (**(code **)(iVar6 + 0x9c))(param_3,&local_20,param_2,0);
  iVar6 = *param_1;
  uVar8 = 0x10;
LAB_004b9f36:
  (**(code **)(iVar6 + 0x24))(uVar8);
  return;
}

