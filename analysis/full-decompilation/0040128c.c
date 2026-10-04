
undefined4 __thiscall FUN_0040128c(int param_1,int *param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar5;
  byte local_8;
  int iVar4;
  
  iVar5 = 0;
  bVar1 = false;
  *(undefined4 *)(param_1 + 0xc) = 0;
  do {
    local_8 = FUN_00401144();
    if (bVar1) {
      if (((local_8 == 0x22) || (local_8 == 0xd2)) || (local_8 == 0xd3)) {
        bVar1 = false;
      }
      else if (iVar5 == 1) {
        FUN_00401406(local_8);
      }
      else if (iVar5 == 4) {
        FUN_00401436(local_8);
      }
    }
    else {
      if ((0x40 < local_8) && (local_8 < 0x5b)) {
        local_8 = local_8 + 0x20;
      }
      if (local_8 < 0x21) {
        if (local_8 == 0x20) {
LAB_00401321:
          if (iVar5 == 1) {
            iVar5 = 2;
          }
          if (iVar5 == 4) {
            iVar5 = 2;
          }
          goto LAB_004013f1;
        }
        if (local_8 == 0) goto LAB_004013f1;
        if ((8 < local_8) && ((local_8 < 0xb || (local_8 == 0xd)))) goto LAB_00401321;
LAB_00401352:
        bVar2 = false;
        if (iVar5 == 2) {
          if (*(int *)(param_1 + 0xc) <= *(int *)(param_1 + 8)) {
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          }
LAB_00401365:
          bVar2 = true;
          iVar5 = 1;
        }
        else {
          if (iVar5 == 0) goto LAB_00401365;
          if (iVar5 == 3) {
            iVar5 = 4;
          }
        }
        if (iVar5 == 1) {
          FUN_00401406(local_8);
        }
        else if (iVar5 == 4) {
          FUN_00401436(local_8);
        }
        if (!bVar2) goto LAB_004013f1;
        iVar4 = *param_2;
      }
      else {
        if (local_8 != 0x22) {
          if (local_8 == 0x3d) {
            if ((iVar5 == 2) || (iVar5 == 1)) {
              iVar5 = 3;
            }
            goto LAB_004013f1;
          }
          if ((local_8 < 0xd2) || (0xd3 < local_8)) goto LAB_00401352;
        }
        bVar2 = false;
        if (iVar5 == 2) {
          if (*(int *)(param_1 + 0xc) <= *(int *)(param_1 + 8)) {
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          }
LAB_004013c4:
          bVar2 = true;
          iVar5 = 1;
        }
        else {
          if (iVar5 == 0) goto LAB_004013c4;
          if (iVar5 == 3) {
            iVar5 = 4;
          }
        }
        bVar1 = true;
        if (!bVar2) goto LAB_004013f1;
        iVar4 = *param_2;
      }
      uVar3 = (**(code **)(iVar4 + 4))();
      FUN_00401466(uVar3);
    }
LAB_004013f1:
    if (local_8 == 0) {
      return 1;
    }
  } while( true );
}

