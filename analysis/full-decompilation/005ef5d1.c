
undefined4 __fastcall FUN_005ef5d1(int param_1)

{
  char cVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    (**(code **)(**(int **)(param_1 + 0x24) + 0x18))();
    FUN_005da719();
    (**(code **)(**(int **)(param_1 + 0x24) + 0x18))();
    FUN_005da67b();
    if (*(char *)(param_1 + 0x2c) == '\0') {
      piVar2 = (int *)(**(code **)(*(int *)(param_1 + 0xb4) + 0xf8))();
      cVar1 = (**(code **)(*piVar2 + 0x2c))();
      if ((cVar1 != '\0') && (*(char *)(param_1 + 0x27c) == '\0')) {
        (**(code **)(**(int **)(param_1 + 0x24) + 0x18))();
        FUN_005d97a1();
      }
      (**(code **)(*(int *)(param_1 + 0xb4) + 0xf4))();
    }
    else {
      FUN_005effb4();
    }
  }
  return 1;
}

