
void __fastcall FUN_0043e0a9(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0x20); piVar1 != *(int **)(param_1 + 0x24); piVar1 = piVar1 + 1)
  {
    if (*(int *)(*piVar1 + 0xa0) == 0) {
      FUN_0043e0d0(*piVar1);
    }
  }
  return;
}

