
int __thiscall FUN_0044097d(int param_1,int param_2)

{
  int iVar1;
  int *local_8;
  
  local_8 = *(int **)(param_1 + 0x84);
  while( true ) {
    if (local_8 == *(int **)(param_1 + 0x88)) {
      return 0;
    }
    iVar1 = FUN_0045741b(param_1,*(undefined4 *)(*local_8 + 0x11c));
    if (iVar1 == param_2) break;
    local_8 = local_8 + 1;
  }
  return *local_8;
}

