
undefined4 __fastcall FUN_00506193(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined1 *local_8;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar2 != '\0') {
    iVar1 = *(int *)(param_1 + 0xd8);
    local_14 = *(int *)(param_1 + 0x20);
    local_1c = *(int *)(iVar1 + 0x20);
    local_20 = *(int *)(iVar1 + 0x1c);
    local_28 = 0;
    local_24 = 0;
    local_18 = *(int *)(param_1 + 0x1c);
    local_10 = local_18 + local_20;
    local_c = local_14 + local_1c;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(iVar1,&local_28,&local_18,0);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  local_8 = (undefined1 *)(param_1 + 0x478);
  if (*(char *)(param_1 + 0x478) == '\0') {
    FUN_005dde6d(0);
    FUN_005db0b7();
  }
  else {
    FUN_005dde6d(*(undefined4 *)(param_1 + 0x47c));
    *(undefined4 *)(param_1 + 0x47c) = 0;
    *local_8 = 0;
  }
  return 1;
}

