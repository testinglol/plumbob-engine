
void __thiscall FUN_005ee2fe(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined1 local_1c [8];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*param_2 < param_2[2]) && (param_2[1] < param_2[3])) {
    cVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
    if (cVar3 != '\0') {
      uVar4 = *(undefined4 *)(param_1 + 0x20);
      uVar5 = *(undefined4 *)(param_1 + 0x1c);
      FUN_005eea5e(param_2);
      uVar4 = FUN_00524f29(uVar5,uVar4);
      FUN_005eea5e(uVar4);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x38))(0,local_1c);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
    }
    piVar1 = (int *)(param_1 + 0x1c);
    iVar2 = *(int *)(param_1 + 0xd8 + *(int *)(param_1 + 0xd4) * 4);
    local_2c = *(int *)(iVar2 + 0x14);
    local_28 = *(int *)(iVar2 + 0x18);
    local_24 = *(int *)(iVar2 + 0x1c);
    local_20 = *(int *)(iVar2 + 0x20);
    FUN_004ba5ac(piVar1);
    local_c = (((*(int *)(param_1 + 0x24) - *piVar1) - local_24) + local_2c) / 2;
    local_8 = (((*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20)) - local_20) + local_28) / 2;
    FUN_004ba5ac(&local_c);
    FUN_005de841(&local_2c,param_2);
    local_3c = local_2c;
    local_38 = local_28;
    local_34 = local_24;
    local_30 = local_20;
    local_14 = -local_c;
    local_10 = -local_8;
    FUN_004ba5ac(&local_14);
    local_14 = -*piVar1;
    local_10 = -*(int *)(param_1 + 0x20);
    FUN_004ba5ac(&local_14);
    if ((local_2c < local_24) && (local_28 < local_20)) {
      cVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
      if (cVar3 != '\0') {
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                  (*(undefined4 *)(param_1 + 0xd8 + *(int *)(param_1 + 0xd4) * 4),&local_3c,
                   &local_2c,0);
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
      }
    }
  }
  return;
}

