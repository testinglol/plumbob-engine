
void __thiscall FUN_0051b33b(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 local_24 [4];
  int local_20;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 != '\0') {
    FUN_004e84f4(&local_14,param_2);
    FUN_004e84f4(local_24,param_2);
    if ((*(int *)(param_1 + 0xe4) == 0) || (cVar1 = FUN_004cff80(), cVar1 == '\0')) {
      local_10 = local_10 + -0x32;
    }
    else {
      local_20 = local_20 + 0x32;
    }
    local_8 = local_8 + -0x32;
    local_14 = local_14 + -*(int *)(param_1 + 0x1c);
    local_c = local_c + -*(int *)(param_1 + 0x1c);
    local_10 = local_10 + -*(int *)(param_1 + 0x20);
    local_8 = local_8 + -*(int *)(param_1 + 0x20);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
              (*(undefined4 *)(param_1 + 0xd4),&local_14,local_24,0);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    return;
  }
  return;
}

