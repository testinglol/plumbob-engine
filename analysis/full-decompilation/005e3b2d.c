
void __fastcall FUN_005e3b2d(int param_1)

{
  int iVar1;
  char cVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0xdc) != 0) {
    local_10 = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x130);
    local_8 = (*(int *)(param_1 + 0x140) - *(int *)(param_1 + 0x138)) + *(int *)(param_1 + 0x20) +
              *(int *)(param_1 + 0x130);
    local_14 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 300);
    local_c = (*(int *)(param_1 + 0x13c) - *(int *)(param_1 + 0x134)) + *(int *)(param_1 + 0x1c) +
              *(int *)(param_1 + 300);
    iVar1 = *(int *)(*(int *)(param_1 + 0xdc) + 0x60);
    if (iVar1 == 0) {
      cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
      if (cVar2 != '\0') {
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                  (*(undefined4 *)(param_1 + 0xdc),param_1 + 0x134,&local_14,0);
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
      }
    }
    else {
      FUN_004ba1dc(*(undefined4 *)(param_1 + 0x5c),&local_14,*(int *)(param_1 + 0xdc),iVar1,
                   param_1 + 0x134,0);
    }
  }
  return;
}

