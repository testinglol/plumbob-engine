
undefined4 __fastcall FUN_00502eb1(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined3 uVar8;
  size_t sVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  CHAR local_120 [256];
  int local_20;
  int local_1c;
  int local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  if (*(char *)(param_1 + 0xe4) == '\0') {
    uVar8 = (undefined3)((uint)(param_1 + 0xe4) >> 8);
  }
  else {
    *(undefined1 *)(param_1 + 0xe4) = 0;
    piVar6 = (int *)(param_1 + 0x110);
    if (*(int *)(param_1 + 0x114) == *(int *)(param_1 + 0x110)) {
      if (*(char *)(param_1 + 0x10c) == '\0') {
        local_c = *(undefined4 *)(param_1 + 0x20);
        local_20 = *(int *)(param_1 + 0x1c);
        local_10 = (int *)(local_20 + 0x1e + *(int *)(param_1 + 0xdc) * 0xc);
        local_1c = *(int *)(param_1 + 0xe8) + 0x3c + local_20;
        local_20 = *(int *)(param_1 + 0xec) + *(int *)(param_1 + 0xe8) + 0x5a + local_20;
        if ((*(int **)(param_1 + 0xe0) != (int *)0x0) &&
           (*(int *)(param_1 + 0x50) != *(int *)(param_1 + 0x4c))) {
          local_8 = *(int **)(param_1 + 0x5c);
          local_14 = **(int **)(param_1 + 0xe0);
          uVar9 = FUN_005d49d6(0,0,0);
          uVar9 = FUN_004096c2(uVar9);
          (**(code **)(local_14 + 0x78))(local_8,local_10,local_c,uVar9);
        }
        if ((*(int *)(param_1 + 0xf8) != *(int *)(param_1 + 0xf4)) &&
           (*(int **)(param_1 + 0xe0) != (int *)0x0)) {
          local_8 = (int *)(**(code **)(**(int **)(param_1 + 0xe0) + 0x1c))();
          if (*(int *)(param_1 + 0xd4) < 0) {
            (**(code **)(**(int **)(param_1 + 0xe0) + 0x20))(DAT_006f2a5c);
          }
          local_14 = *(int *)(param_1 + 0x5c);
          local_10 = (int *)**(int **)(param_1 + 0xe0);
          uVar9 = FUN_005d49d6(0,0,0);
          uVar9 = FUN_004096c2(uVar9);
          (**(code **)((int)local_10 + 0x78))(local_14,local_1c,local_c,uVar9);
          (**(code **)(**(int **)(param_1 + 0xe0) + 0x20))(local_8);
        }
        piVar6 = (int *)(param_1 + 0x100);
        if ((*(int *)(param_1 + 0x104) != *piVar6) && (*(int **)(param_1 + 0xe0) != (int *)0x0)) {
          local_10 = (int *)(**(code **)(**(int **)(param_1 + 0xe0) + 0x1c))();
          if (*(int *)(param_1 + 0xd8) < 0) {
            (**(code **)(**(int **)(param_1 + 0xe0) + 0x20))(DAT_006f2a5c);
          }
          local_1c = *(undefined4 *)(param_1 + 0x5c);
          local_14 = **(int **)(param_1 + 0xe0);
          uVar9 = FUN_005d49d6(0,0,0);
          uVar9 = FUN_004096c2(uVar9);
          (**(code **)(local_14 + 0x78))(local_1c,local_20,local_c,uVar9);
          piVar6 = (int *)(**(code **)(**(int **)(param_1 + 0xe0) + 0x20))(local_10);
        }
      }
      else {
        local_8 = *(int **)(param_1 + 0xe0);
        if (local_8 != (int *)0x0) {
          iVar1 = *local_8;
          uVar9 = FUN_004096c2(*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c));
          iVar7 = (**(code **)(iVar1 + 0x68))(uVar9);
          local_8 = *(int **)(param_1 + 0x20);
          iVar1 = *(int *)(param_1 + 0x84);
          iVar2 = *(int *)(param_1 + 0x7c);
          local_c = *(undefined4 *)(param_1 + 0x5c);
          iVar3 = *(int *)(param_1 + 0x1c);
          local_10 = *(int **)(param_1 + 0xe0);
          iVar4 = *local_10;
          uVar9 = FUN_005d49d6(0,0,0);
          uVar9 = FUN_004096c2(uVar9);
          piVar6 = (int *)(**(code **)(iVar4 + 0x78))
                                    (local_c,((iVar1 - iVar2) - iVar7) / 2 + iVar3,local_8,uVar9);
        }
      }
    }
    else {
      wsprintfA(local_120,(LPCSTR)*piVar6,*(undefined4 *)(param_1 + 0x11c));
      iVar1 = **(int **)(param_1 + 0xe0);
      sVar5 = _strlen(local_120);
      local_c = (**(code **)(iVar1 + 0x68))(local_120,sVar5);
      iVar1 = *(int *)(param_1 + 0x84);
      iVar2 = *(int *)(param_1 + 0x7c);
      uVar11 = 0;
      local_8 = (int *)**(int **)(param_1 + 0xe0);
      uVar10 = 0;
      uVar9 = 0;
      sVar5 = _strlen(local_120);
      piVar6 = (int *)(**(code **)((int)local_8 + 0x78))
                                (*(undefined4 *)(param_1 + 0x5c),
                                 ((iVar1 - iVar2) - local_c) / 2 + *(int *)(param_1 + 0x1c),
                                 *(undefined4 *)(param_1 + 0x20),local_120,sVar5,uVar9,uVar10,uVar11
                                );
    }
    uVar8 = (undefined3)((uint)piVar6 >> 8);
  }
  return CONCAT31(uVar8,1);
}

