
void __thiscall
FUN_005eac32(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar4 = 1;
  cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
  if (cVar2 != '\0') {
    local_24 = param_3 + 2;
    local_20 = param_4 + 2;
    local_1c = param_3 + -2 + param_5;
    uVar5 = 0;
    local_18 = param_4 + -2 + param_6;
    iVar1 = **(int **)(param_1 + 0x5c);
    uVar3 = FUN_004df599(local_34,param_1 + 0x1c);
    (**(code **)(iVar1 + 0x40))(param_2,uVar3,uVar5);
    do {
      if (iVar4 == 1) {
        param_3 = 1;
      }
      else if (iVar4 == 2) {
        param_3 = 3;
      }
      local_14 = local_24 + param_3;
      uVar5 = 0;
      local_c = local_1c - param_3;
      local_10 = local_20 - iVar4;
      local_8 = local_10 + 1;
      iVar1 = **(int **)(param_1 + 0x5c);
      uVar3 = FUN_004df599(local_34,param_1 + 0x1c);
      (**(code **)(iVar1 + 0x40))(param_2,uVar3,uVar5);
      uVar5 = 0;
      local_10 = iVar4 + -1 + local_18;
      local_8 = local_10 + 1;
      iVar1 = **(int **)(param_1 + 0x5c);
      uVar3 = FUN_004df599(local_44,param_1 + 0x1c);
      (**(code **)(iVar1 + 0x40))(param_2,uVar3,uVar5);
      local_10 = local_20 + param_3;
      uVar5 = 0;
      local_8 = local_18 - param_3;
      local_14 = local_24 - iVar4;
      local_c = local_14 + 1;
      iVar1 = **(int **)(param_1 + 0x5c);
      uVar3 = FUN_004df599(local_54,param_1 + 0x1c);
      (**(code **)(iVar1 + 0x40))(param_2,uVar3,uVar5);
      uVar5 = 0;
      local_14 = iVar4 + -1 + local_1c;
      local_c = local_14 + 1;
      iVar1 = **(int **)(param_1 + 0x5c);
      uVar3 = FUN_004df599(local_64,param_1 + 0x1c);
      (**(code **)(iVar1 + 0x40))(param_2,uVar3,uVar5);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
  }
  return;
}

