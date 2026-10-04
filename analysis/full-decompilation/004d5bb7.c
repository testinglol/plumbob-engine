
undefined4 __thiscall FUN_004d5bb7(int param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 local_48 [16];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  if (param_2 == '\0') {
    uVar2 = 0;
  }
  else {
    local_18 = (int *)(param_1 + 0x100);
    (**(code **)(*(int *)(param_1 + 0x100) + 4))();
    iVar7 = 0;
    iVar3 = (*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4)) / 0xc;
    piVar4 = (int *)(param_1 + 0x100);
    if (0 < iVar3) {
      piVar4 = (int *)FUN_005e7743();
      piVar4 = (int *)(**(code **)(*piVar4 + 8))(1);
      local_10 = piVar4;
      local_14 = (**(code **)(*piVar4 + 0x58))();
      local_8 = 0;
      iVar6 = iVar3;
      if (0 < iVar3) {
        do {
          local_c = iVar6;
          piVar5 = (int *)(*(int *)(param_1 + 0xf4) + iVar7);
          iVar6 = *piVar5;
          iVar6 = (**(code **)(*piVar4 + 0x68))(iVar6,piVar5[1] - iVar6);
          if (local_8 < iVar6) {
            local_8 = iVar6;
          }
          iVar7 = iVar7 + 0xc;
          local_c = local_c + -1;
          iVar6 = local_c;
        } while (local_c != 0);
      }
      local_24 = *(int *)(param_1 + 0xd8);
      local_1c = *(int *)(param_1 + 0x28) - local_24;
      local_20 = (int *)(*(int *)(param_1 + 0x24) - local_24);
      iVar7 = *(int *)(param_1 + 0x5c);
      iVar8 = *(int *)(param_1 + 0x1c) + local_24;
      local_24 = *(int *)(param_1 + 0x20) + local_24;
      local_38 = *(undefined4 *)(iVar7 + 0x14);
      iVar6 = local_1c - local_14;
      local_34 = *(undefined4 *)(iVar7 + 0x18);
      local_30 = *(undefined4 *)(iVar7 + 0x1c);
      local_2c = *(undefined4 *)(iVar7 + 0x20);
      local_28 = iVar8;
      FUN_005de841(&local_38,&local_28);
      local_8 = iVar3 + -1;
      piVar4 = local_18;
      if (-1 < local_8) {
        iVar3 = local_8 * 0xc;
        do {
          piVar4 = (int *)(iVar3 + *(int *)(param_1 + 0xf4));
          (**(code **)(*local_10 + 0x78))
                    (*(undefined4 *)(param_1 + 0x5c),iVar8,iVar6,*piVar4,piVar4[1] - *piVar4,
                     local_48,0,0);
          piVar4 = local_18;
          if (iVar6 <= *(int *)(param_1 + 0x20)) break;
          iVar6 = iVar6 - local_14;
          local_8 = local_8 + -1;
          iVar3 = iVar3 + -0xc;
        } while (-1 < local_8);
      }
    }
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
    if (cVar1 != '\0') {
      local_28 = *(int *)(param_1 + 0x1c);
      iVar6 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c);
      iVar8 = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80);
      iVar3 = *(int *)(param_1 + 0x20);
      local_20 = (int *)(local_28 + iVar6);
      local_1c = *(int *)(param_1 + 0xd8) + iVar3;
      local_24 = iVar3;
      local_14 = local_28;
      local_10 = local_20;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))(*(undefined4 *)(param_1 + 100),&local_28,0);
      local_24 = (iVar8 - *(int *)(param_1 + 0xd8)) + iVar3;
      local_1c = iVar3 + iVar8;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))(*(undefined4 *)(param_1 + 100),&local_28,0);
      iVar7 = *(int *)(param_1 + 0xd8);
      local_28 = local_14;
      local_24 = iVar3 + iVar7;
      local_20 = (int *)(local_14 + iVar7);
      local_1c = (iVar8 - iVar7) + iVar3;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))(*(undefined4 *)(param_1 + 100),&local_28,0);
      local_28 = (iVar6 - *(int *)(param_1 + 0xd8)) + local_14;
      local_20 = local_10;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))(*(undefined4 *)(param_1 + 100),&local_28,0);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
      piVar4 = local_18;
    }
    (**(code **)(*piVar4 + 8))();
    uVar2 = 1;
  }
  return uVar2;
}

