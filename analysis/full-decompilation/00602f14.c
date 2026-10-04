
undefined4 FUN_00602f14(void)

{
  int *piVar1;
  char cVar2;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_006030b2(&local_10);
  local_8 = local_10;
  while( true ) {
    FUN_006030c9(&local_c);
    if (local_8 == local_c) {
      return 1;
    }
    local_10 = local_8;
    FUN_0042a392();
    piVar1 = *(int **)(local_10 + 0x14);
    cVar2 = (**(code **)(*piVar1 + 8))();
    if (cVar2 == '\0') break;
    (**(code **)(*piVar1 + 4))(1);
    FUN_0042a392();
  }
  return 0;
}

