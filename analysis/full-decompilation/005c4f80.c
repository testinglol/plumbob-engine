
/* WARNING: Type propagation algorithm not settling */

undefined4 __thiscall FUN_005c4f80(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_8c;
  int local_88;
  int local_84 [5];
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_3c;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00661399;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_006331bc(local_84,4);
  if (*(int *)(*(int *)(*param_2 + 4) + 8 + (int)param_2) == 0) {
    if (local_84[0] == -0x4f4f4f50) {
      FUN_006331bc(&local_88,4);
      if (*(int *)(*(int *)(*param_2 + 4) + 8 + (int)param_2) == 0) {
        local_8c = 0;
        if (0 < local_88) {
          do {
            local_54 = 0;
            local_50 = 0;
            local_4c = 0;
            local_6c = 0x3f800000;
            local_68 = 0;
            local_64 = 0;
            FUN_00462be8(&local_6c);
            local_3c = 3;
            local_84[1] = 0x3f800000;
            local_84[2] = 0x3f800000;
            local_84[3] = 0x3f800000;
            uVar1 = FUN_00462bc9(local_84 + 3,local_84 + 2,local_84 + 1);
            FUN_00462be8(uVar1);
            local_2c = 0x3f800000;
            local_28 = 0;
            local_24 = 1;
            local_20 = 0x3f800000;
            local_1c = 0;
            local_18 = 0;
            local_14 = 0;
            local_10 = 0;
            local_4 = 0;
            iVar2 = FUN_005c7640(param_2);
            if (iVar2 != 0) goto LAB_005c4ffb;
            iVar2 = *(int *)(param_1 + 4);
            if (iVar2 == *(int *)(param_1 + 8)) {
              FUN_005c5200(iVar2,&local_54);
            }
            else {
              local_4 = CONCAT31(local_4._1_3_,1);
              local_84[4] = iVar2;
              local_70 = iVar2;
              if (iVar2 != 0) {
                FUN_005c5180(&local_54);
              }
              *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x48;
            }
            local_8c = local_8c + 1;
            local_4 = 0xffffffff;
          } while (local_8c < local_88);
        }
        uVar1 = 0;
      }
      else {
LAB_005c4ffb:
        uVar1 = 0x9b0d0012;
      }
    }
    else {
      uVar1 = 0x9b0d0017;
    }
  }
  else {
    uVar1 = 0x9b0d0012;
  }
  ExceptionList = local_c;
  return uVar1;
}

