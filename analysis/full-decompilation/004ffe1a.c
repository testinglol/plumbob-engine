
undefined4 __fastcall FUN_004ffe1a(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar4 = *(int *)(param_1 + 0xd4);
  if ((iVar4 == 0) || (*(int *)(param_1 + 0x100) != 0)) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(8);
    if (cVar1 == '\0') {
      return 1;
    }
    local_18 = *(int *)(param_1 + 0x7c);
    local_14 = *(int *)(param_1 + 0x80);
    local_10 = *(int *)(param_1 + 0x84);
    local_c = *(int *)(param_1 + 0x88);
    uVar2 = FUN_005dfe3b(0,0,0);
    uVar3 = FUN_005dfe3b(0xff,0xff,0xff);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x50))(&local_18,uVar2,1);
    local_18 = local_18 + 1;
    local_10 = local_10 + -1;
    local_14 = local_14 + 1;
    local_c = local_c + -1;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x50))(&local_18,uVar3,1);
    local_18 = local_18 + 1;
    local_10 = local_10 + -1;
    local_14 = local_14 + 1;
    local_c = local_c + -1;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x50))(&local_18,uVar2,1);
    uVar5 = 8;
    iVar4 = **(int **)(param_1 + 0x5c);
  }
  else {
    local_8 = (*(int *)(iVar4 + 0x20) - *(int *)(iVar4 + 0x18)) / *(int *)(param_1 + 0xe8);
    local_10 = (*(int *)(iVar4 + 0x1c) - *(int *)(iVar4 + 0x14)) / *(int *)(param_1 + 0xec);
    local_18 = *(int *)(param_1 + 0xf4) * local_10;
    local_10 = (*(int *)(param_1 + 0xf4) + 1) * local_10;
    local_14 = *(int *)(param_1 + 0xf0) * local_8;
    local_c = (*(int *)(param_1 + 0xf0) + 1) * local_8;
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar1 == '\0') {
      return 1;
    }
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0xd4),&local_18,param_1 + 0x1c,0);
    uVar5 = 0x10;
    iVar4 = **(int **)(param_1 + 0x5c);
  }
  (**(code **)(iVar4 + 0x24))(uVar5);
  return 1;
}

