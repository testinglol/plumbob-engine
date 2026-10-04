
undefined4 __fastcall FUN_005f1058(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  byte *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar3 = param_1 + 0x1c;
  local_28 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0xdc);
  local_24 = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0xe0);
  local_20 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0xdc);
  local_1c = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0xe0);
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
  if (cVar1 != '\0') {
    uVar6 = 0;
    local_10 = **(int **)(param_1 + 0x5c);
    uVar2 = FUN_005dd5e1(0,0,0);
    (**(code **)(local_10 + 0x40))(uVar2,iVar3,uVar6);
    uVar6 = 0;
    iVar3 = **(int **)(param_1 + 0x5c);
    piVar5 = &local_28;
    uVar2 = FUN_005dd5e1(0xa6,0xb4,0xb4);
    (**(code **)(iVar3 + 0x40))(uVar2,piVar5,uVar6);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
  }
  if (*(int *)(param_1 + 0xd8) != 0) {
    iVar3 = 0;
    local_8 = 0;
    if (0 < *(int *)(param_1 + 0x1910)) {
      do {
        local_14 = (byte *)(param_1 + 0x510 + iVar3);
        if (*local_14 != *(byte *)(param_1 + 0x510 + local_8)) {
          local_c = local_8 - iVar3;
          local_10 = iVar3 + 0x110 + param_1;
          local_18 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x68))(local_10,local_c);
          if (local_28 < local_20) {
            if ((*local_14 & 1) != 0) {
              local_38 = local_28;
              local_34 = local_24;
              local_2c = local_1c;
              local_30 = local_18 + local_28;
              if (local_20 < local_30) {
                local_30 = local_20;
              }
              cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
              if (cVar1 != '\0') {
                uVar6 = 0;
                local_14 = (byte *)**(undefined4 **)(param_1 + 0x5c);
                piVar5 = &local_38;
                uVar2 = FUN_005dd5e1(0xff,0xff,0xff);
                (**(code **)(local_14 + 0x40))(uVar2,piVar5,uVar6);
                (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
              }
            }
            local_14 = (byte *)(**(code **)(**(int **)(param_1 + 0xd8) + 0x1c))();
            (**(code **)(**(int **)(param_1 + 0xd8) + 0x20))(0);
            (**(code **)(**(int **)(param_1 + 0xd8) + 0x78))
                      (*(undefined4 *)(param_1 + 0x5c),local_28,local_24,local_10,local_c,
                       param_1 + 0x1c,0,0);
            (**(code **)(**(int **)(param_1 + 0xd8) + 0x20))(local_14);
          }
          local_28 = local_28 + local_18;
          iVar3 = local_8;
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)(param_1 + 0x1910));
      if (iVar3 != local_8) {
        local_c = local_8 - iVar3;
        local_10 = iVar3 + param_1 + 0x110;
        iVar4 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x68))(local_10,local_c);
        if (local_28 < local_20) {
          if ((*(byte *)(iVar3 + param_1 + 0x510) & 1) != 0) {
            local_30 = iVar4 + local_28;
            local_34 = local_24;
            local_38 = local_28;
            local_2c = local_1c;
            if (local_20 < local_30) {
              local_30 = local_20;
            }
            cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
            if (cVar1 != '\0') {
              uVar6 = 0;
              iVar3 = **(int **)(param_1 + 0x5c);
              piVar5 = &local_38;
              uVar2 = FUN_005dd5e1(0xff,0xff,0xff);
              (**(code **)(iVar3 + 0x40))(uVar2,piVar5,uVar6);
              (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
            }
          }
          uVar2 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x1c))();
          (**(code **)(**(int **)(param_1 + 0xd8) + 0x20))(0);
          (**(code **)(**(int **)(param_1 + 0xd8) + 0x78))
                    (*(undefined4 *)(param_1 + 0x5c),local_28,local_24,local_10,local_c,
                     param_1 + 0x1c,0,0);
          (**(code **)(**(int **)(param_1 + 0xd8) + 0x20))(uVar2);
        }
      }
    }
  }
  return 1;
}

