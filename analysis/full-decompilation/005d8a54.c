
undefined4 __thiscall FUN_005d8a54(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)**(int **)(param_1 + 0x24);
  if (piVar2 != *(int **)(param_1 + 0x24)) {
    do {
      cVar1 = FUN_004317d5(piVar2 + 3,param_2);
      if (cVar1 != '\0') {
        return 1;
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0x24));
  }
  return 0;
}

