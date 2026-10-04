
undefined4 __fastcall FUN_005fa728(int param_1)

{
  char cVar1;
  
  *(undefined4 *)(param_1 + 0x78) = 0;
  cVar1 = (**(code **)(**(int **)(param_1 + 100) + 0x1c))();
  if (cVar1 != '\0') {
    (**(code **)(**(int **)(param_1 + 100) + 0x18))();
  }
  return 1;
}

