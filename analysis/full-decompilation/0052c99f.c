
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0052c99f(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if ((cVar1 != '\0') && ((*(int *)(param_1 + 0xdc) == 0 || (param_2 != -1)))) {
      iVar2 = FUN_0040542d();
      if (iVar2 != 0) {
        local_8 = FUN_004051c1(param_2);
      }
      iVar2 = *(int *)(param_1 + 0xe0);
      uVar7 = 0;
      puVar6 = &DAT_006f3d08;
      local_c = **(int **)(param_1 + 0x5c);
      piVar5 = &local_30;
      FUN_004df599(&local_20,(int *)(param_1 + 0x1c));
      uVar3 = FUN_004df599(piVar5,puVar6);
      (**(code **)(local_c + 0x9c))(*(undefined4 *)(param_1 + 0xe0),iVar2 + 0x14,uVar3,uVar7);
      if (0 < local_8) {
        iVar2 = *(int *)(param_1 + 0xdc);
        local_30 = *(int *)(iVar2 + 0x14);
        local_2c = *(undefined4 *)(iVar2 + 0x18);
        local_28 = *(int *)(iVar2 + 0x1c);
        local_24 = *(undefined4 *)(iVar2 + 0x20);
        local_10 = *(int *)(param_1 + 0x1c) + _DAT_006f3d08;
        iVar4 = local_28 - local_30;
        local_c = *(int *)(param_1 + 0x20) + _DAT_006f3d0c;
        local_20 = local_30;
        local_1c = local_2c;
        local_18 = local_28;
        local_14 = local_24;
        FUN_004ba5ac(&local_10);
        iVar2 = local_8 * 8;
        if ((iVar2 <= iVar4) && (local_8 != 10)) {
          local_18 = local_20 + iVar2;
          local_28 = iVar2 + local_30;
        }
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                  (*(undefined4 *)(param_1 + 0xdc),&local_30,&local_20,0);
      }
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return;
}

