
undefined4 __fastcall FUN_005f730f(int param_1)

{
  char cVar1;
  int iVar2;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = (*(int *)(*(int *)(param_1 + 0xd8) + 0x1c) / 4 + -1) / 2;
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 != '\0') {
    local_10 = 0;
    local_8 = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80);
    local_c = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c);
    local_14 = 0;
    FUN_004ba5ac(param_1 + 0x1c);
    FUN_004ba5ac(param_1 + 0x144);
    local_30 = *(undefined4 *)(param_1 + 0x110);
    local_34 = *(int *)(param_1 + 0x10c);
    local_28 = *(undefined4 *)(param_1 + 0x118);
    local_20 = local_10;
    local_18 = local_8;
    local_24 = local_14;
    local_1c = local_14 + iVar2;
    local_2c = local_34 + iVar2;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0xd8),&local_34,&local_24,0);
    local_30 = *(undefined4 *)(param_1 + 0x110);
    local_34 = *(int *)(param_1 + 0x10c) + iVar2;
    local_28 = *(undefined4 *)(param_1 + 0x118);
    local_20 = local_10;
    local_18 = local_8;
    local_24 = local_14 + iVar2;
    local_2c = *(int *)(param_1 + 0x114) - iVar2;
    local_1c = local_c - iVar2;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0xbc))
              (*(undefined4 *)(param_1 + 0xd8),&local_34,&local_24,0,0);
    local_28 = *(undefined4 *)(param_1 + 0x118);
    local_30 = *(undefined4 *)(param_1 + 0x110);
    local_18 = local_8;
    local_20 = local_10;
    local_2c = *(int *)(param_1 + 0x114);
    local_1c = local_c;
    local_24 = local_c - iVar2;
    local_34 = local_2c - iVar2;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0xd8),&local_34,&local_24,0);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  return 1;
}

