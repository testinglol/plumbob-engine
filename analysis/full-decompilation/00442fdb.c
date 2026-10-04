
uint __fastcall FUN_00442fdb(int param_1)

{
  char cVar1;
  int *local_8;
  
  local_8 = *(int **)(param_1 + 0x84);
  while( true ) {
    if (local_8 == *(int **)(param_1 + 0x88)) {
      return (uint)local_8 & 0xffffff00;
    }
    if ((((*(short *)(*local_8 + 0x8e) == 0) && (*(short *)(*local_8 + 0x60e) < 2)) &&
        (cVar1 = FUN_0045ef31(), cVar1 == '\0')) && (*(short *)(*local_8 + 0x5cc) == 0)) break;
    local_8 = local_8 + 1;
  }
  return 1;
}

