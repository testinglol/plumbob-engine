
undefined4 __fastcall FUN_005ec144(int *param_1)

{
  char cVar1;
  
  if ((char)param_1[0x1d] != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x118))();
    if (cVar1 != '\0') {
      *(undefined1 *)(param_1 + 1) = 1;
      return 1;
    }
  }
  return 0;
}

