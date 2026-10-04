
undefined4 __fastcall FUN_00526a9c(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar3 = FUN_005e74ca(3);
  FUN_005dde6d(uVar3);
  cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar2 != '\0') {
    iVar5 = *(int *)(param_1 + 0x114);
    if (iVar5 != 0) {
      local_3c = *(int *)(iVar5 + 0x14);
      local_38 = *(undefined4 *)(iVar5 + 0x18);
      local_34 = *(int *)(iVar5 + 0x1c) / 3;
      local_30 = *(int *)(iVar5 + 0x20) / 3;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar5,&local_3c,param_1 + 0x1c,1);
    }
    if (*(int *)(param_1 + 0x100) != 0) {
      piVar1 = (int *)(param_1 + 0x104);
      if ((*(int *)(param_1 + 0x10c) - *piVar1 == 0x2d) &&
         (*(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x108) == 0x2d)) {
        iVar5 = *(int *)(param_1 + 0x118);
        local_1c = *(int *)(iVar5 + 0x14);
        local_18 = *(int *)(iVar5 + 0x18);
        local_14 = *(int *)(iVar5 + 0x1c);
        local_10 = *(undefined4 *)(iVar5 + 0x20);
        FUN_00524f29(-local_1c,-local_18);
        piVar4 = (int *)FUN_00524b60(&local_c);
        FUN_00524f29(*piVar4 + 9 + *(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x20) + piVar4[1] + 9
                    );
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                  (*(int *)(param_1 + 0x118),*(int *)(param_1 + 0x118) + 0x14,&local_1c,0);
        local_14 = local_1c + 0x2d;
        local_10 = local_18 + 0x2d;
        iVar6 = ((*(int *)(*(int *)(param_1 + 0x118) + 0x20) - local_10) + local_18) / 2;
        local_18 = local_18 + iVar6;
        piVar4 = &local_1c;
        iVar5 = ((*(int *)(*(int *)(param_1 + 0x118) + 0x1c) - local_14) + local_1c) / 2;
        local_1c = local_1c + iVar5;
        local_14 = local_14 + iVar5;
        local_10 = local_10 + iVar6;
        iVar5 = **(int **)(param_1 + 0x5c);
      }
      else {
        local_3c = *piVar1;
        local_38 = *(undefined4 *)(param_1 + 0x108);
        local_34 = *(int *)(param_1 + 0x10c);
        local_30 = *(int *)(param_1 + 0x110);
        FUN_00524f41(&local_3c);
        piVar4 = (int *)FUN_00524b60(&local_14);
        local_c = *piVar4 + 9 + *(int *)(param_1 + 0x1c);
        local_8 = *(int *)(param_1 + 0x20) + piVar4[1] + 9;
        FUN_004ba5ac(&local_c);
        piVar4 = &local_3c;
        iVar5 = **(int **)(param_1 + 0x5c);
      }
      (**(code **)(iVar5 + 0x9c))(*(undefined4 *)(param_1 + 0x100),piVar1,piVar4,0);
    }
    local_24 = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c);
    local_8 = local_24 + -0x28;
    local_24 = local_24 + -0x14;
    local_28 = (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) + -0x23;
    local_20 = (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) + -0xf;
    local_2c = 0x14;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))(0x32,&local_2c,0);
    iVar5 = *(int *)(param_1 + 0x88);
    iVar6 = *(int *)(param_1 + 0x80);
    local_24 = __ftol();
    local_24 = local_24 + 0x14;
    local_2c = 0x14;
    local_20 = (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) + -0x10;
    local_28 = (iVar5 - iVar6) + -0x22;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))(0x98,&local_2c,0);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  return 1;
}

