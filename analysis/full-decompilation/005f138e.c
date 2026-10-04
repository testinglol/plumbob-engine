
undefined4 __fastcall FUN_005f138e(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  size_t sVar5;
  uint uVar6;
  char *_Str;
  uint uVar7;
  int *piVar8;
  undefined4 uVar9;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_1c;
  int local_18;
  uint local_14;
  char *local_10;
  uint local_c;
  char local_8 [4];
  
  local_40 = *(int *)(param_1 + 0xdc) + *(int *)(param_1 + 0x1c);
  iVar4 = param_1 + 0x1c;
  iVar1 = *(int *)(param_1 + 0x110);
  local_34 = *(int *)(param_1 + 0xe0);
  local_3c = *(int *)(param_1 + 0x20) + local_34;
  local_38 = *(int *)(param_1 + 0x24) - local_34;
  local_34 = *(int *)(param_1 + 0x28) - local_34;
  cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
  if (cVar2 != '\0') {
    uVar9 = 0;
    local_10 = (char *)**(int **)(param_1 + 0x5c);
    uVar3 = FUN_005dd5e1(0x30,0x73,0xc5);
    (**(code **)((int)local_10 + 0x40))(uVar3,iVar4,uVar9);
    uVar9 = 0;
    iVar4 = **(int **)(param_1 + 0x5c);
    piVar8 = &local_40;
    uVar3 = FUN_005dd5e1(0xbc,0xbc,0xff);
    (**(code **)(iVar4 + 0x40))(uVar3,piVar8,uVar9);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
  }
  if (((*(int *)(param_1 + 0xd8) != 0) && (iVar1 != 0)) && (*(int *)(iVar1 + 4) == 1)) {
    uVar7 = *(uint *)(iVar1 + 0xc);
    if ((uVar7 < *(uint *)(iVar1 + 0x10)) ||
       (uVar6 = *(uint *)(iVar1 + 0x14), *(uint *)(iVar1 + 0x10) + uVar6 <= uVar7)) {
      uVar6 = *(uint *)(iVar1 + 0x14);
      *(uint *)(iVar1 + 0x10) = (uVar7 / uVar6) * uVar6;
    }
    local_c = 0;
    if (uVar6 != 0) {
      do {
        local_14 = local_c + *(int *)(iVar1 + 0x10);
        if (local_14 < *(uint *)(iVar1 + 8)) {
          local_30 = local_40;
          _Str = (char *)(*(int *)(iVar1 + 0x18 + local_14 * 4) + iVar1);
          local_2c = local_3c;
          local_28 = local_38;
          local_24 = local_34;
          local_10 = _Str;
          iVar4 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x58))();
          local_2c = local_2c + (iVar4 + 2) * local_c;
          iVar4 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x58))();
          local_24 = iVar4 + 2 + local_2c;
          if (local_14 == *(uint *)(iVar1 + 0xc)) {
            if (local_34 < local_24) {
              local_24 = local_34;
            }
            if (local_2c < local_34) {
              cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
              if (cVar2 != '\0') {
                uVar9 = 0;
                iVar4 = **(int **)(param_1 + 0x5c);
                piVar8 = &local_30;
                uVar3 = FUN_005dd5e1(0xff,0xff,0xff);
                (**(code **)(iVar4 + 0x40))(uVar3,piVar8,uVar9);
                (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
                _Str = local_10;
              }
            }
          }
          if (*(char *)(param_1 + 0x114) == '\0') {
            local_14 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x1c))();
            (**(code **)(**(int **)(param_1 + 0xd8) + 0x20))(0);
            uVar9 = 0;
            local_18 = **(int **)(param_1 + 0xd8);
            uVar3 = 0;
            iVar4 = param_1 + 0x1c;
            sVar5 = _strlen(_Str);
            (**(code **)(local_18 + 0x78))
                      (*(undefined4 *)(param_1 + 0x5c),local_30,local_2c + 1,local_10,sVar5,iVar4,
                       uVar3,uVar9);
            iVar4 = **(int **)(param_1 + 0xd8);
            uVar7 = local_14;
          }
          else {
            local_8[2] = 0;
            local_8[0] = (char)local_c + '1';
            local_8[1] = 0x3a;
            if ('9' < local_8[0]) {
              local_8[0] = '0';
            }
            local_18 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x1c))();
            (**(code **)(**(int **)(param_1 + 0xd8) + 0x20))(0);
            if (local_c < 10) {
              local_1c = 0;
              (**(code **)(**(int **)(param_1 + 0xd8) + 0x78))
                        (*(undefined4 *)(param_1 + 0x5c),local_30,local_2c + 1,local_8,2,
                         param_1 + 0x1c,0,0);
            }
            uVar9 = 0;
            local_14 = **(int **)(param_1 + 0xd8);
            uVar3 = 0;
            iVar4 = param_1 + 0x1c;
            sVar5 = _strlen(_Str);
            (**(code **)(local_14 + 0x78))
                      (*(undefined4 *)(param_1 + 0x5c),local_30 + 0x10,local_2c + 1,local_10,sVar5,
                       iVar4,uVar3,uVar9);
            iVar4 = **(int **)(param_1 + 0xd8);
            uVar7 = local_18;
          }
          (**(code **)(iVar4 + 0x20))(uVar7);
        }
        local_c = local_c + 1;
      } while (local_c < *(uint *)(iVar1 + 0x14));
    }
  }
  return 1;
}

