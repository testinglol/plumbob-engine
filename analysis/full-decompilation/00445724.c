
int __fastcall FUN_00445724(int param_1)

{
  int *local_8;
  
  local_8 = *(int **)(param_1 + 0x84);
  while( true ) {
    if (local_8 == *(int **)(param_1 + 0x88)) {
      return 0;
    }
    if ((*(uint *)(*local_8 + 0x114) & 2) != 0) break;
    local_8 = local_8 + 1;
  }
  return *local_8;
}

