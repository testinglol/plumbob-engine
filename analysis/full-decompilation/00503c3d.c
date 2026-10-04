
undefined4 __fastcall FUN_00503c3d(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if ((*(int **)(param_1 + 0x5c) != (int *)0x0) && (*(int *)(param_1 + 0xd8) != 0)) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar2 != '\0') {
      local_20 = *(int *)(param_1 + 0x1c);
      local_18 = *(int *)(param_1 + 0x24);
      local_1c = *(int *)(param_1 + 0x20);
      local_14 = *(int *)(param_1 + 0x28);
      local_30 = 0;
      local_28 = local_18 - local_20;
      local_24 = local_14 - local_1c;
      local_2c = 0;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(undefined4 *)(param_1 + 0xd8),&local_30,&local_20,0);
      if (*(int *)(param_1 + 0x120) != 0) {
        local_10 = 0x85;
        local_c = 6;
        uVar6 = 0;
        iVar1 = **(int **)(param_1 + 0x5c);
        puVar5 = &local_10;
        puVar4 = local_40;
        local_8 = *(int *)(param_1 + 0x120) + 0x14;
        FUN_004df599(local_50,param_1 + 0x1c);
        uVar3 = FUN_004df599(puVar4,puVar5);
        (**(code **)(iVar1 + 0x9c))(*(undefined4 *)(param_1 + 0x120),local_8,uVar3,uVar6);
      }
      iVar1 = *(int *)(param_1 + 0x124);
      if (iVar1 != 0) {
        local_10 = 0xce;
        local_c = 6;
        local_8 = **(int **)(param_1 + 0x5c);
        puVar5 = &local_10;
        uVar6 = 0;
        puVar4 = local_50;
        FUN_004df599(local_40,param_1 + 0x1c);
        uVar3 = FUN_004df599(puVar4,puVar5);
        (**(code **)(local_8 + 0x9c))(*(undefined4 *)(param_1 + 0x124),iVar1 + 0x14,uVar3,uVar6);
      }
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return 1;
}

