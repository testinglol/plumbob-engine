
undefined4 FUN_00602f7c(undefined4 param_1)

{
  int iVar1;
  int local_c;
  int local_8;
  
  FUN_006030b2(&local_8);
  while( true ) {
    FUN_006030c9(&local_c);
    iVar1 = local_8;
    if (local_8 == local_c) break;
    FUN_0042a392();
    (**(code **)(**(int **)(iVar1 + 0x14) + 0xc))(param_1);
    FUN_0042a392();
  }
  return 1;
}

