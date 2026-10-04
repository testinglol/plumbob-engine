
undefined4 __fastcall FUN_005ec81c(int *param_1)

{
  char cVar1;
  
  if ((char)param_1[0x1d] != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x130))();
    if (cVar1 != '\0') {
      *(undefined1 *)(param_1 + 1) = 0;
      return 1;
    }
  }
  return 0;
}

