
undefined4 __fastcall FUN_005e3fce(int param_1)

{
  char cVar1;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0xd8) != 0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar1 == '\0') {
      return 0;
    }
    local_8 = *(int *)(param_1 + 0x118) - *(int *)(param_1 + 0x110);
    local_c = *(int *)(param_1 + 0x114) - *(int *)(param_1 + 0x10c);
    local_14 = 0;
    local_10 = 0;
    FUN_004ba5ac(param_1 + 0x1c);
    FUN_004ba5ac(param_1 + 0x144);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0xd8),(int *)(param_1 + 0x10c),&local_14,0);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  return 1;
}

