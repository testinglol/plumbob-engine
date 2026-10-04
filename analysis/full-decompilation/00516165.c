
undefined1 __fastcall FUN_00516165(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  cVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  uVar4 = 0;
  if (cVar3 != '\0') {
    iVar1 = param_1 + 0x1c;
    local_18 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x1c);
    local_20 = 0;
    local_14 = *(int *)(param_1 + 0x28) + -*(int *)(param_1 + 0x20);
    local_1c = *(int *)(param_1 + 0x20) + -*(int *)(param_1 + 0x20);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0xd8),&local_20,iVar1,0);
    if (*(int *)(param_1 + 0x1ac) != 0) {
      local_10 = 0x10;
      local_c = 0x33;
      uVar8 = 0;
      iVar2 = **(int **)(param_1 + 0x5c);
      puVar7 = &local_10;
      puVar6 = local_30;
      local_8 = *(int *)(param_1 + 0x1ac) + 0x14;
      FUN_004df599(local_40,iVar1);
      uVar5 = FUN_004df599(puVar6,puVar7);
      (**(code **)(iVar2 + 0x9c))(*(undefined4 *)(param_1 + 0x1ac),local_8,uVar5,uVar8);
    }
    iVar2 = *(int *)(param_1 + 0x1b0);
    if (iVar2 != 0) {
      local_10 = 0xde;
      local_c = 6;
      local_8 = **(int **)(param_1 + 0x5c);
      puVar7 = &local_10;
      uVar8 = 0;
      puVar6 = local_40;
      FUN_004df599(local_30,iVar1);
      uVar5 = FUN_004df599(puVar6,puVar7);
      (**(code **)(local_8 + 0x9c))(*(undefined4 *)(param_1 + 0x1b0),iVar2 + 0x14,uVar5,uVar8);
    }
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    uVar4 = 1;
  }
  return uVar4;
}

