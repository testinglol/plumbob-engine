
undefined4 __fastcall FUN_00524715(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 != '\0') {
    iVar2 = *(int *)(param_1 + 0x114);
    if (iVar2 != 0) {
      local_2c = *(int *)(iVar2 + 0x14);
      local_28 = *(undefined4 *)(iVar2 + 0x18);
      local_24 = *(int *)(iVar2 + 0x1c) / 3;
      local_20 = *(int *)(iVar2 + 0x20) / 3;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar2,&local_2c,param_1 + 0x1c,1);
    }
    cVar1 = FUN_005a5e72();
    if (cVar1 != '\0') {
      piVar3 = (int *)(param_1 + 0x104);
      if ((*(int *)(param_1 + 0x10c) - *piVar3 == 0x2d) &&
         (*(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x108) == 0x2d)) {
        iVar2 = FUN_004096c2();
        local_1c = *(int *)(iVar2 + 0x14);
        local_18 = *(int *)(iVar2 + 0x18);
        local_14 = *(int *)(iVar2 + 0x1c);
        local_10 = *(undefined4 *)(iVar2 + 0x20);
        FUN_00524f29(-local_1c,-local_18);
        piVar3 = (int *)FUN_00524b60(&local_c);
        FUN_00524f29(*(int *)(param_1 + 0x1c) + *piVar3 + 9,*(int *)(param_1 + 0x20) + piVar3[1] + 9
                    );
        iVar2 = **(int **)(param_1 + 0x5c);
        iVar4 = FUN_004096c2(&local_1c,0);
        uVar5 = FUN_004096c2(iVar4 + 0x14);
        (**(code **)(iVar2 + 0x9c))(uVar5);
        local_14 = local_1c + 0x2d;
        local_10 = local_18 + 0x2d;
        iVar2 = FUN_004096c2();
        iVar2 = *(int *)(iVar2 + 0x20);
        iVar4 = FUN_004096c2();
        iVar7 = ((iVar2 - local_10) + local_18) / 2;
        local_18 = local_18 + iVar7;
        iVar2 = ((*(int *)(iVar4 + 0x1c) - local_14) + local_1c) / 2;
        local_1c = local_1c + iVar2;
        local_14 = local_14 + iVar2;
        local_10 = local_10 + iVar7;
        iVar2 = **(int **)(param_1 + 0x5c);
        uVar5 = FUN_004096c2(param_1 + 0x104,&local_1c,0);
        (**(code **)(iVar2 + 0x9c))(uVar5);
      }
      else {
        local_2c = *piVar3;
        local_28 = *(undefined4 *)(param_1 + 0x108);
        local_24 = *(int *)(param_1 + 0x10c);
        local_20 = *(int *)(param_1 + 0x110);
        FUN_00524f41(&local_2c);
        piVar6 = (int *)FUN_00524b60(&local_14);
        local_c = *(int *)(param_1 + 0x1c) + *piVar6 + 9;
        local_8 = *(int *)(param_1 + 0x20) + piVar6[1] + 9;
        FUN_004ba5ac(&local_c);
        local_8 = **(int **)(param_1 + 0x5c);
        uVar5 = FUN_004096c2(piVar3,&local_2c,0);
        (**(code **)(local_8 + 0x9c))(uVar5);
      }
    }
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  return 1;
}

